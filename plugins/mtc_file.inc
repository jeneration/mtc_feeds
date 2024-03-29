<?php
/**
 * @file
 * Feeds tamper plugin to fetch remote URLS.
 *
 * Used ONLY in mtc_legacy_data tamper.
 *
 * @see feeds_tamper_file_fetcher for meetings.
 */

$plugin = array(
  'form'     => 'feeds_tamper_mtc_file_form',
  'callback' => 'feeds_tamper_mtc_file_callback',
  'name'     => 'MTC File fetcher',
  'multi'    => 'skip',
  'category' => 'MTC',
);

/**
 * Settings form.
 */
function feeds_tamper_mtc_file_form($importer, $element_key, $settings) {
  $form = array();

  $form['help'] = array(
    '#type' => 'markup',
    '#markup' => t('This plugin expects to be given a full remote URL as a file to download. It will save it locally, and transform the URL into a local Drupal URI path. The value of the field being tampered will be transformed from a remote URL to a local file URI, and that local file will become valid (registered in the database) and available. Intended for use when mapping the media.module/file_entity.module URI value.'),
  );
  $form['directory_prefix'] = array(
    '#type' => 'textfield',
    '#title' => t('Directory prefix'),
    '#default_value' => isset($settings['directory_prefix']) ? $settings['directory_prefix'] : '',
  );

  return $form;
}

/**
 * Fetcher callback.
 */
function feeds_tamper_mtc_file_callback($result, $item_key, $element_key, &$field, $settings, $source) {
  // Find out if debug mode is on.
  $debug = variable_get('feeds_tamper_file_fetcher_debug', FALSE);

  if (!empty($field)) {
    $item = $result->items[$item_key];

    // Figure out where is SHOULD be saved.
    $url_parts = parse_url($field);
    $path_array = explode('/', $url_parts['path']);
    $expected_filepath = array_pop($path_array);

    // If the expected path is 'View.ashx' use a unique value from the query string instead.
    if (strstr($expected_filepath, 'View.ashx')) {
      parse_str($url_parts['query'], $query);
      $expected_filepath = strtolower($query['GUID']) . '.pdf';
    }

    $expected_uri = file_build_uri($settings['directory_prefix'] . ltrim($expected_filepath, '/'));

    $strings = array(
      '%field' => $field,
      '%expected_uri' => $expected_uri,
      '!source' => l(basename($field), $field),
    );

    // Check local filesystem.
    if (!file_exists($expected_uri)) {

      watchdog(__FUNCTION__, 'Remote File %field does not have a local copy. Need to fetch it to %expected_uri now.', $strings, WATCHDOG_NOTICE);
      $source_file = file_uri_to_object($expected_uri);

      // MAYBE can background the actual fetch into a queue job
      // just make the DB entry, and hope nobody notices until it's needed.
      $fake_it = FALSE;
      // Fake it can't work if we are using stage_file_proxy pointing at a site
      // that is not the same source.
      if (!$fake_it) {
        $dirname = dirname($expected_uri);
        file_prepare_directory($dirname, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);
        $fail = FALSE;

        // Attempt a curl.
        $file = feeds_tamper_mtc_file_curl($field);
        if ($file !== FALSE) {
          file_put_contents($expected_uri, $file);
        }
        else {
          $fail = TRUE;
          if ($debug) {
            drupal_set_message('Attempt to curl failed, trying drupal_http_request.');
          }
          watchdog(__FUNCTION__, 'Attempt to curl failed, trying drupal_http_request.', $strings, WATCHDOG_INFO);

          $file = drupal_http_request($field);
          if (!isset($file->error)) {
            $fail = FALSE;
            file_put_contents($expected_uri, $file->data);
          }
          else {
            if ($debug) {
              drupal_set_message('Attempt with drupal_http_request failed, giving up.');
            }
            watchdog(__FUNCTION__, 'Attempt with drupal_http_request failed, giving up.', $strings, WATCHDOG_INFO);
          }

          if ($fail) {
            // This is a pain, but non-fatal.
            if ($debug) {
              drupal_set_message(t("File copy from remote %field to local location (%expected_uri) failed, aborting. Maybe it's not available from the source.", $strings));
            }
            watchdog(__FUNCTION__, "File copy from remote %field to local location (%expected_uri) failed, aborting. Maybe it's not available from the source.", $strings, WATCHDOG_INFO);
            // Can I invalidate it here?
            // $entity->feeds_item->skip = TRUE;
            return NULL;
          }
        }
        if ($debug) {
          drupal_set_message(t("File copy from remote !source to %expected_uri Succeeded.", $strings));
          watchdog(__FUNCTION__, 'Remote File import from !source SUCCEEDED and is now available at %expected_uri.', $strings, WATCHDOG_INFO);
        }
      }
      else {
        // If not faking it, cannot use the temporary dl method as file_move then complains.
        // Instead, make a db entry assuming it's in its final place.
        $source_file = file_uri_to_object($expected_uri);
      }

      // Whether we fetched the file or not, if it's on the system, it needs to
      // have an entry in file_managed

      // IF we want to recycle fids, we need to insert a fake placeholder into the
      // file table, to fool the API. This allows me to define my own fid.
      if (!empty($item['file id'])) {
        $source_file->fid = $item['file id'];
        $source_file->status = FILE_STATUS_PERMANENT;
        $strings += array(
          '%fid' => $source_file->fid,
        );

        watchdog(__FUNCTION__, 'Attempting to recycle a file id fid:%fid.', $strings, WATCHDOG_INFO);
        // But look-ahead first.
        $existing_file_record = file_load($source_file->fid);
        // Now insert our placeholder.
        if (!$existing_file_record) {

          // Additional paranoia - manual replacements may now be getting
          // in the way with a new fid.
          $additional_lookahead = file_load_multiple(array(), array('uri' => $expected_uri));
          if ($existing_by_uri = reset($additional_lookahead)) {
            // Found one in the slot I was about to fill.
            $strings['%existing_fid'] = $existing_by_uri->fid;
            //drupal_set_message(t("Cannot recycle an old file fid:%fid id as fid:%existing_fid already exists for %expected_uri. That just means we don't need to add the placeholder, and it should sort itself out anyway", $strings));
            watchdog(__FUNCTION__, "Cannot recycle an old file fid:%fid id as fid:%existing_fid already exists for %expected_uri. That just means we don't need to add the placeholder, and it should sort itself out anyway", $strings, WATCHDOG_NOTICE);
            // That's ok, as the data update will look it up by uri later anyway.
            // Gah, this happens too much. It's due to media.module auto-indexing
            // the file dir.
            // BRUTALLY reset it by CHANGING THS FID in the KEY COLUMN in the DB!
            // If anyone NEW is using the new fid, they lose. We need to recover
            // it for the oldies.
            $existing_by_uri->fid = $source_file->fid;
            drupal_write_record('files', $existing_by_uri);
            if ($debug) {
              drupal_set_message(t("Brutally resetting the fid for %expected_uri back to fid:%fid from fid:%existing_fid . This means new usages of the file may get unhooked, but old expectations will work again.", $strings));
            }
          }
          else {
            if ($debug) {
              drupal_set_message(t('Recycling a file id. %field is fid:%fid and there is no pre-existing entry for %expected_uri', $strings));
            }
            watchdog(__FUNCTION__, 'Recycling a file id. %field is fid:%fid and there is no pre-existing entry for %expected_uri', $strings);
            $source_file->type = 'placeholder';
            drupal_write_record('file_managed', $source_file);
          }
        }
      }
      // It would seem that as long as the file uri I set here matches
      // the entity file uri that gets set on feeds item save,
      // then all ends up matched together!
    }
    elseif ($debug) {
      watchdog(__FUNCTION__, 'Remote File %field already has a local copy at %expected_uri.', array('%field' => $field, '%expected_uri' => $expected_uri), WATCHDOG_WARNING);
    }
    $field = $expected_uri;
  }
  elseif ($debug) {
    watchdog('feeds_tamper_file_fetcher',
      "File copy from remote %field failed, aborting. File source is empty.",
      array('%field' => $field), WATCHDOG_WARNING);
  }
}

/**
 * Helper function. Retrieves a file via curl when copy() fails.
 *
 * @param $remote
 *   URL to remote file.
 *
 * @return $result
 *   Will return the copied file on success, or FALSE on failure.
 *
 * @see feeds_tamper_mtc_file_callback in plugins/mtc_file.inc
 */
function feeds_tamper_mtc_file_curl($remote){
  $ch = curl_init();
  curl_setopt($ch, CURLOPT_URL, $remote);
  curl_setopt($ch, CURLOPT_TIMEOUT, 5);
  curl_setopt($ch, CURLOPT_USERAGENT, _USERAGENT_);
  curl_setopt($ch, CURLOPT_REFERER,_REFERER_);
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);
  $result = curl_exec($ch);

  curl_close($ch);

  return $result;
}


