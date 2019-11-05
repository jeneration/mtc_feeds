<?php
/**
 * @file
 * Adjust date format to work during import.
 */

$plugin = array(
  'form' => 'feeds_tamper_mtc_maps_title_form',
  'callback' => 'feeds_tamper_mtc_maps_title_callback',
  'name' => 'Maps Title cleanup',
  'multi' => 'direct',
  'category' => 'MTC',
);

function feeds_tamper_mtc_maps_title_form($importer, $element_key, $settings) {
  $form = array();
  $form['mtc'] = array(
    '#type' => 'checkbox',
    '#title' => t('remove the maps Date from the maps Title'),
    '#default_value' => TRUE,
  );

  return $form;
}

function feeds_tamper_mtc_maps_title_callback($result, $item_key, $element_key, &$field, $settings, $source) {
  $old = $field;
  $array = explode(':', $old);
  $trash = array_shift($array);
  $new = implode(':', $array);

  $field = trim($new);
}
