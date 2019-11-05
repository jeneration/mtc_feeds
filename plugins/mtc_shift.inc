<?php
/**
 * @file
 * Shift an element off the beginning of array.
 */

$plugin = array(
  'form' => 'feeds_tamper_mtc_shift_form',
  'callback' => 'feeds_tamper_mtc_shift_callback',
  'name' => 'Remove date from meeting name.',
  'multi' => 'direct',
  'category' => 'MTC',
);

function feeds_tamper_mtc_shift_form($importer, $element_key, $settings) {
  $form = array();
  $form['mtc'] = array(
    '#type' => 'checkbox',
    '#title' => t('Remove date from meeting name'),
    '#default_value' => TRUE,
  );

  return $form;
}

function feeds_tamper_mtc_shift_callback($result, $item_key, $element_key, &$field, $settings, $source) {
  if (!is_array($field)) {
    $field = array($field);
  }
  $out = array();
  foreach ($field as $in) {
    $array = explode(' on ', $in);
    // If there are no occurances of ' on ' then return.
    if (count($array) == 1) {
      $out = $in;
    }
    // Only one ' on '. Remove the first element and return.
    elseif (count($array) == 2) {
      $out = array_shift($array);
    }
    // More than one ' on '. Remove the last element, and implode.
    else {
      $count = count($array);
      unset($array[$count]);
      $out = implode(' on ', $array);
    }
  }
  $field = $out;
}
