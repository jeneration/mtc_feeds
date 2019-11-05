<?php
/**
 * @file
 * Adjust date format to work during import.
 */

$plugin = array(
  'form' => 'feeds_tamper_mtc_address_zip_form',
  'callback' => 'feeds_tamper_mtc_address_zip_callback',
  'name' => 'MTC ZIP',
  'multi' => 'direct',
  'category' => 'MTC',
);

function feeds_tamper_mtc_address_zip_form($importer, $element_key, $settings) {
  $form = array();
  $form['mtc'] = array(
    '#type' => 'checkbox',
    '#title' => t('Pull address ZIP from Location if possible.'),
    '#default_value' => TRUE,
  );

  return $form;
}

function feeds_tamper_mtc_address_zip_callback($result, $item_key, $element_key, &$field, $settings, $source) {
  if (!is_array($field)) {
    $field = array($field);
  }
  foreach ($field as $input) {
    $array = explode(',', $input);
    $end = trim(array_pop($array));
    $pos = strpos($end, 'CA ');
    if (strpos($end, 'CA ') === 0) {
      $zip = str_replace('CA ', '', $end);
      if (is_numeric($zip) && strlen($zip) == 5) {
        $field = $zip;
      }
    }
  }
}
