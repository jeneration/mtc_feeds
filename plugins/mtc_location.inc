<?php
/**
 * @file
 * Shift an element off the beginning of array.
 */

$plugin = array(
  'form' => 'feeds_tamper_mtc_location_form',
  'callback' => 'feeds_tamper_mtc_location_callback',
  'name' => 'Location cleanup',
  'multi' => 'direct',
  'category' => 'MTC',
);

function feeds_tamper_mtc_location_form($importer, $element_key, $settings) {
  $form = array();
  $form['mtc'] = array(
    '#type' => 'checkbox',
    '#title' => t('Removes NULL values and other characters from meeting location.'),
    '#default_value' => TRUE,
  );

  return $form;
}

function feeds_tamper_mtc_location_callback($result, $item_key, $element_key, &$field, $settings, $source) {
  if (strtolower($field) == 'null') {
    $field = '';
  }
  elseif(substr($field, 0, 17) == 'Meeting Location:') {
    $field = trim(str_replace('Meeting Location:', '', $field));
  }
}
