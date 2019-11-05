<?php
/**
 * @file
 * Adjust date format to work during import.
 */

$plugin = array(
  'form' => 'feeds_tamper_mtc_address_state_form',
  'callback' => 'feeds_tamper_mtc_address_state_callback',
  'name' => 'MTC State',
  'multi' => 'direct',
  'category' => 'MTC',
);

function feeds_tamper_mtc_address_state_form($importer, $element_key, $settings) {
  $form = array();
  $form['mtc'] = array(
    '#type' => 'checkbox',
    '#title' => t('Pull address State from Location (if possible).'),
    '#default_value' => TRUE,
  );

  return $form;
}

function feeds_tamper_mtc_address_state_callback($result, $item_key, $element_key, &$field, $settings, $source) {
  if (!is_array($field)) {
    $field = array($field);
  }
  foreach ($field as $input) {
    $array = explode(',', $input);
    $end = trim(array_pop($array));
    $pos = strpos($end, 'CA ');
    if (strpos($end, 'CA ') === 0) {
      $state = 'CA';
    }
  }
}
