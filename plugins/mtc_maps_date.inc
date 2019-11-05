<?php
/**
 * @file
 * Adjust date format to work during import.
 */

$plugin = array(
  'form' => 'feeds_tamper_mtc_maps_date_form',
  'callback' => 'feeds_tamper_mtc_maps_date_callback',
  'name' => 'Maps date',
  'multi' => 'direct',
  'category' => 'MTC',
);

function feeds_tamper_mtc_maps_date_form($importer, $element_key, $settings) {
  $form = array();
  $form['mtc'] = array(
    '#type' => 'checkbox',
    '#title' => t('Pull the Maps date from two separate fields'),
    '#default_value' => TRUE,
  );

  return $form;
}

function feeds_tamper_mtc_maps_date_callback($result, $item_key, $element_key, &$field, $settings, $source) {
  $year = $result->items[$item_key]['year'];
  $numeric_mo = $result->items[$item_key]['monthid'];

  $out = array(
    'value' => $year . '-' .  $numeric_mo . '-10 00:00:00',
    'timezone' => 'America/Los_Angeles',
    'timezone_db' => 'America/Los_Angeles',
    'date_type' => 'datetime',
  );

  $field = $out['value'];
}
