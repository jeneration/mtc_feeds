<?php
/**
 * @file
 * Adjust date format to work during import.
 */

$plugin = array(
  'form' => 'feeds_tamper_mtc_video_baha_title_form',
  'callback' => 'feeds_tamper_mtc_video_baha_title_callback',
  'name' => 'Create meeting recording title',
  'multi' => 'direct',
  'category' => 'MTC',
);

function feeds_tamper_mtc_video_baha_title_form($importer, $element_key, $settings) {
  $form = array();
  $form['default_value'] = array(
    '#type' => 'textfield',
    '#title' => t('Meeting recording title'),
    '#default_value' => isset($settings['default_value']) ? $settings['default_value'] : '',
  );
  return $form;
}

function feeds_tamper_mtc_video_baha_title_callback($result, $item_key, $element_key, &$field, $settings, $source) {
  $item = $result->items[$item_key];

  $field = NULL;
  // Setting a default title if there will be a URL.
  if (!empty($item['clipid']) && !empty($settings['default_value'])) {
    $field = $settings['default_value'];
  }
}
