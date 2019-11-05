<?php
/**
 * Tampers for the mtc_legacy_data feed.
 */

$export = array();

$feeds_tamper = new stdClass();
$feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
$feeds_tamper->api_version = 2;
$feeds_tamper->id = 'mtc_motm_import-blank_source_1-mtc_maps_guid';
$feeds_tamper->importer = 'mtc_motm_import';
$feeds_tamper->source = 'Blank source 1';
$feeds_tamper->plugin_id = 'mtc_maps_guid';
$feeds_tamper->settings = array(
  'mtc' => 1,
);
$feeds_tamper->weight = 0;
$feeds_tamper->description = 'Maps GUID';

$export[$feeds_tamper->id] = $feeds_tamper;

$feeds_tamper = new stdClass();
$feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
$feeds_tamper->api_version = 2;
$feeds_tamper->id = 'mtc_motm_import-blank_source_2-mtc_maps_date';
$feeds_tamper->importer = 'mtc_motm_import';
$feeds_tamper->source = 'Blank source 2';
$feeds_tamper->plugin_id = 'mtc_maps_date';
$feeds_tamper->settings = array(
  'mtc' => 1,
);
$feeds_tamper->weight = 0;
$feeds_tamper->description = 'Pull the Maps month from two separate fields';

$export[$feeds_tamper->id] = $feeds_tamper;

$feeds_tamper = new stdClass();
$feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
$feeds_tamper->api_version = 2;
$feeds_tamper->id = 'mtc_motm_import-link_png-mtc_file';
$feeds_tamper->importer = 'mtc_motm_import';
$feeds_tamper->source = 'link_png';
$feeds_tamper->plugin_id = 'mtc_file';
$feeds_tamper->settings = array(
  'directory_prefix' => '',
);
$feeds_tamper->weight = 0;
$feeds_tamper->description = 'MTC File fetcher';

$export[$feeds_tamper->id] = $feeds_tamper;

$feeds_tamper = new stdClass();
$feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
$feeds_tamper->api_version = 2;
$feeds_tamper->id = 'mtc_motm_import-name-mtc_file';
$feeds_tamper->importer = 'mtc_motm_import';
$feeds_tamper->source = 'name';
$feeds_tamper->plugin_id = 'mtc_file';
$feeds_tamper->settings = array(
  'directory_prefix' => '',
);
$feeds_tamper->weight = 0;
$feeds_tamper->description = 'MTC File fetcher';

$export[$feeds_tamper->id] = $feeds_tamper;

$feeds_tamper = new stdClass();
$feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
$feeds_tamper->api_version = 2;
$feeds_tamper->id = 'mtc_motm_import-post_date-strtotime';
$feeds_tamper->importer = 'mtc_motm_import';
$feeds_tamper->source = 'post_date';
$feeds_tamper->plugin_id = 'strtotime';
$feeds_tamper->settings = array();
$feeds_tamper->weight = 0;
$feeds_tamper->description = 'String to Unix timestamp';

$export[$feeds_tamper->id] = $feeds_tamper;

$feeds_tamper = new stdClass();
$feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
$feeds_tamper->api_version = 2;
$feeds_tamper->id = 'mtc_motm_import-title-mtc_maps_title';
$feeds_tamper->importer = 'mtc_motm_import';
$feeds_tamper->source = 'title';
$feeds_tamper->plugin_id = 'mtc_maps_title';
$feeds_tamper->settings = array(
  'mtc' => 1,
);
$feeds_tamper->weight = 0;
$feeds_tamper->description = 'Maps Title cleanup';

$export[$feeds_tamper->id] = $feeds_tamper;
