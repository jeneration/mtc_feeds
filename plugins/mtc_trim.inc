<?php
/**
 * @file
 * Adjust date format to work during import.
 */

$plugin = array(
  'form' => 'feeds_tamper_mtc_trim_form',
  'callback' => 'feeds_tamper_mtc_trim_callback',
  'name' => 'Trim text on sentence boundary.',
  'multi' => 'direct',
  'category' => 'MTC',
);

function feeds_tamper_mtc_trim_form($importer, $element_key, $settings) {
  $form = array();
  $form['length'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum length of characters.'),
    '#default_value' => 255,
  );

  return $form;
}

function feeds_tamper_mtc_trim_callback($result, $item_key, $element_key, &$field, $settings, $source) {
  if (empty($settings['length'])) {
    $settings['length'] = 255;
  }
  if (module_exists('text')) {
    module_load_include('module', 'text', 'text');
    $field = text_summary($field, 'plain_text', $settings['length']);
  }
  else {
    $field = substr($field, 0, $settings['length']);
  }
}
