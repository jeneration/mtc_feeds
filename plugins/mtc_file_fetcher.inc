<?php

/**
 * @file
 * Feeds tamper plugin to fetch remote URLS.
 *
 * If the source data is a remote URL,
 * and the local equivalent does not exist in the system
 * fetch it,
 * copy it into an equivalent local filepath
 * update the files_managed to index it
 * return the local file wrapper URI.
 *
 * @see file_feeds_set_target()
 */

$plugin = array(
  'form'     => 'feeds_tamper_mtc_file_fetcher_form',
  'callback' => 'feeds_tamper_mtc_file_fetcher_callback',
  'name'     => 'MTC File fetcher',
  'multi'    => 'skip',
  'category' => 'Other',
);

/**
 * Settings form.
 */
function feeds_tamper_mtc_file_fetcher_form($importer, $element_key, $settings) {
  $form = array();

  $form['help'] = array(
    '#type' => 'markup',
    '#markup' => t('This plugin expects to be given a full remote URL as a file to download. It will save it locally, and transform the URL into a local Drupal URI path. That local file will become valid (registered in the database) and available.'),
  );
  $filepath = variable_get('file_public_path', 'sites/default/files/');
  $form['directory_prefix'] = array(
    '#type' => 'textfield',
    '#title' => t('Directory structure for saving files'),
    '#description' => t('Please include a trailing slash'),
    '#field_prefix' => $filepath . '/',
    '#default_value' => isset($settings['directory_prefix']) ? $settings['directory_prefix'] : '',
  );

  return $form;
}

/**
 * Fetcher callback.
 */
function feeds_tamper_mtc_file_fetcher_callback($result, $item_key, $element_key, &$field, $settings, $source) {
  // Find out if debug mode is on.
  $debug = variable_get('feeds_tamper_file_fetcher_debug', FALSE);

  if (!empty($field)) {

    // Don't attempt to retrieve a file if the source is not a valid URL.
      // This should also catch invalid characters like Â or ®️
    if (filter_var($field, FILTER_VALIDATE_URL) === FALSE) {
      // Log a failure message when the file does not copy.
      if ($debug) {
        $strings = array('%field' => $field);
        $message = "FAILURE: File copy from remote %field failed, invalid URL provided.";
        watchdog('feeds_tamper_mtc_file_fetcher', $message, $strings, WATCHDOG_WARNING);
        drupal_set_message(t($message, $strings), 'warning');
      }

      // Return NULL to prevent the file from being saved.
      $field = NULL;
    }

    $item = $result->items[$item_key];

    // Figure out the local filepath.
    $url_parts = parse_url(trim($field));
    $expected_filepath = $url_parts['path'];

    // Remove all directories from source.
    $path_array = explode('/', $url_parts['path']);
    $expected_filepath = array_pop($path_array);

    // Get the URI we expect to have after file is copied.
    $expected_uri = file_build_uri($settings['directory_prefix'] . ltrim($expected_filepath, '/'));

    if (isset($expected_uri)) {
      $redownload = FALSE;

      // Get the headers of the external file to make sure it does not 404.
      $headers = feeds_tamper_mtc_file_fetcher_get_headers($field);

      $status_code = FALSE;
      if ($headers && strstr($headers[0], '200')) {
        $status_code = 200;
      }
      elseif ($headers && strstr($headers[0], '404')) {
        $status_code = 404;
      }

      // Check to see if the file is already in the local filesystem.
      if (file_exists($expected_uri)) {
        if ($status_code == 200) {
          // Compare file sizes to see if they are different.
          $local_size = @filesize($expected_uri);
          $remote_size = 0;
          if ($headers) {
            $remote_size = $headers['Content-Length'];
          }
          if ($local_size != $remote_size) {
            $redownload = TRUE;
          }

          if (!$redownload) {
            // Check to see if the file has been updated recently.
            $local_time = filemtime($expected_uri);
            $remote_time = 0;
            if ($headers) {
              $remote_time = $headers['Last-Modified'];
            }
            if ($local_time <= $remote_time) {
              $redownload = TRUE;
            }
          }
        }
        elseif ($status_code == 404) {
          // Log if remote file URL is 404.
          watchdog('feeds_tamper_mtc_file_fetcher',
            'FAILURE: Remote File URL %field returned a 404.',
            array('%field' => $field), WATCHDOG_WARNING);
        }
      }

      // Check to see if the file needs to be downloaded.
      if (!file_exists($expected_uri) || $redownload) {

        // Set strings for all logging below.
        $strings = array(
          '%field' => $field,
          '%expected_uri' => $expected_uri,
          '!source' => l(basename($field), $field),
        );
        if ($debug) {
          drupal_set_message(t('Remote File %field needs to be downloaded to %expected_uri.', $strings));
        }

        // Only download the document if the URL does not 404.
        if ($status_code == 404) {
          watchdog('feeds_tamper_mtc_file_fetcher',
            'FAILURE: Remote File URL %field returned a 404.',
            array('%field' => $field), WATCHDOG_WARNING);
        }
        else {
          // Create a file object.
          $source_file = file_uri_to_object($expected_uri);
          // Create the file path if necessary.
          $dirname = dirname($expected_uri);
          file_prepare_directory($dirname, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);

          // Check to see if the file copied properly.
          if (!@copy($field, $expected_uri)) {

            // Log a failure message when the file does not copy.
            if ($debug) {
              $message = "FAILURE: File copy from remote %field to location (%expected_uri) failed, aborting.";
              watchdog('feeds_tamper_mtc_file_fetcher', $message . ' ' .
                "Maybe it's not available from the source? Maybe the destination is not writable?",
                $strings, WATCHDOG_WARNING);
              drupal_set_message(t($message, $strings), 'warning');
            }

            // Return NULL to prevent the file from being saved.
            $field = NULL;
          }

          // Log a success message if it copied correctly.
          if ($debug) {
            $message = 'SUCCESS: Remote File import from !source is now available at %expected_uri.';
            drupal_set_message(t($message, $strings));
            watchdog('feeds_tamper_mtc_file_fetcher', $message, $strings, WATCHDOG_INFO);
          }
        }
      }
      elseif ($debug) {
        $strings = array('%field' => $field, '%expected_uri' => $expected_uri);
        $message = 'NO ACTION: Remote file %field already has an identical local copy at %expected_uri. Refusing to update.';
        drupal_set_message(t($message, $strings));
        watchdog('feeds_tamper_mtc_file_fetcher', $message, $strings, WATCHDOG_INFO);
      }

      // Replace external PDF info with internal now that the file has copied.
      $field = $expected_uri;

      // The function file_save() is in feeds/plugins/FeedsFileFetcher.inc which
      // is called from feeds/mappers/file.inc
    }
  }
}

/**
 * Helper function. Gets the remote file size for comparison.
 *
 * @param $url
 *   URL of file to read size.
 *
 * @return Timestamp when file was last created or modified.
 */
function feeds_tamper_mtc_file_fetcher_get_headers($url) {
  $headers = get_headers($url, 1);

  if (is_array($headers) && array_key_exists('Location', $headers)) {
    // Get the redirect url.
    $redirect_url = $headers['Location'];
    // Get the new headers.
    $headers = get_headers($redirect_url, 1);
  }

  return $headers;
}
