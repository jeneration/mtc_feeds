<?php
/**
 * @file
 * Adjust date format to work during import.
 */

$plugin = array(
  'form' => 'feeds_tamper_mtc_video_form',
  'callback' => 'feeds_tamper_mtc_video_callback',
  'name' => 'Create video player URL',
  'multi' => 'direct',
  'category' => 'MTC',
);

function feeds_tamper_mtc_video_form($importer, $element_key, $settings) {
  $form = array();
  $form['mtc'] = array(
    '#type' => 'checkbox',
    '#title' => t('Create a video player URL from ClipID'),
    '#default_value' => TRUE,
  );

  return $form;
}

function feeds_tamper_mtc_video_callback($result, $item_key, $element_key, &$field, $settings, $source) {
  if (!is_array($field)) {
    $field = array($field);
  }
  $out = '';
  foreach ($field as $in) {
    if (is_numeric($in)) {
      $out = url('http://mtc.granicus.com/MediaPlayer.php?view_id=1&clip_id=' . $in);
    }
  }
  $field = $out;
}
