<?php
/**
 * @file
 * Adjust date format to work during import.
 */

$plugin = array(
  'form' => 'feeds_tamper_mtc_maps_guid_form',
  'callback' => 'feeds_tamper_mtc_maps_guid_callback',
  'name' => 'Maps GUID',
  'multi' => 'direct',
  'category' => 'MTC',
);

function feeds_tamper_mtc_maps_guid_form($importer, $element_key, $settings) {
  $form = array();
  $form['mtc'] = array(
    '#type' => 'checkbox',
    '#title' => t('Pull the Maps GUID from two separate fields'),
    '#default_value' => TRUE,
  );

  return $form;
}

function feeds_tamper_mtc_maps_guid_callback($result, $item_key, $element_key, &$field, $settings, $source) {
  $year = $result->items[$item_key]['year'];
  $numeric_mo = $result->items[$item_key]['monthid'];

  $field = $year . '-' .  $numeric_mo;
}
