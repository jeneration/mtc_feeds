<?php
/**
 * Tampers for the mtc_legacy_data feed.
 */

$feeds_tampers = array();

$feeds_tamper = new stdClass();
$feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
$feeds_tamper->api_version = 2;
$feeds_tamper->id = 'mtc_legacy_data-agenda_url-mtc_file';
$feeds_tamper->importer = 'mtc_legacy_data';
$feeds_tamper->source = 'AGENDA URL';
$feeds_tamper->plugin_id = 'mtc_file';
$feeds_tamper->settings = array(
  'directory_prefix' => 'meetings/',
);
$feeds_tamper->weight = 0;
$feeds_tamper->description = 'MTC File fetcher';
$feeds_tampers['mtc_legacy_data-agenda_url-mtc_file'] = $feeds_tamper;

$feeds_tamper = new stdClass();
$feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
$feeds_tamper->api_version = 2;
$feeds_tamper->id = 'mtc_legacy_data-datetime-strtotime';
$feeds_tamper->importer = 'mtc_legacy_data';
$feeds_tamper->source = 'DATETIME';
$feeds_tamper->plugin_id = 'strtotime';
$feeds_tamper->settings = array();
$feeds_tamper->weight = 0;
$feeds_tamper->description = 'String to Unix timestamp';
$feeds_tampers['mtc_legacy_data-datetime-strtotime'] = $feeds_tamper;

$feeds_tamper = new stdClass();
$feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
$feeds_tamper->api_version = 2;
$feeds_tamper->id = 'mtc_legacy_data-__agenda_url-mtc_file';
$feeds_tamper->importer = 'mtc_legacy_data';
$feeds_tamper->source = '  AGENDA URL';
$feeds_tamper->plugin_id = 'mtc_file';
$feeds_tamper->settings = array(
  'directory_prefix' => 'meetings/',
);
$feeds_tamper->weight = 0;
$feeds_tamper->description = 'MTC File fetcher';
$feeds_tampers['mtc_legacy_data-__agenda_url-mtc_file'] = $feeds_tamper;