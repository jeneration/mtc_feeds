<?php
/**
 * Tampers for the mtc_legacy_data feed.
 */
  $feeds_tampers = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'mtc_maps_import-blank_source_1-copy';
  $feeds_tamper->importer = 'mtc_maps_import';
  $feeds_tamper->source = 'Blank source 1';
  $feeds_tamper->plugin_id = 'copy';
  $feeds_tamper->settings = array(
    'to_from' => 'from',
    'source' => 'id',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Copy source value';
  $feeds_tampers['mtc_maps_import-blank_source_1-copy'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'mtc_maps_import-blank_source_1-mtc_maps_file_img';
  $feeds_tamper->importer = 'mtc_maps_import';
  $feeds_tamper->source = 'Blank source 1';
  $feeds_tamper->plugin_id = 'mtc_maps_file_img';
  $feeds_tamper->settings = array(
    'directory_prefix' => '',
  );
  $feeds_tamper->weight = 4;
  $feeds_tamper->description = 'MTC Map of the Month IMG fetcher';
  $feeds_tampers['mtc_maps_import-blank_source_1-mtc_maps_file_img'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'mtc_maps_import-blank_source_1-mtc_maps_img';
  $feeds_tamper->importer = 'mtc_maps_import';
  $feeds_tamper->source = 'Blank source 1';
  $feeds_tamper->plugin_id = 'mtc_maps_img';
  $feeds_tamper->settings = array(
    'mtc' => 1,
  );
  $feeds_tamper->weight = 3;
  $feeds_tamper->description = 'Create Map of the Month Image thumbnail URL';
  $feeds_tampers['mtc_maps_import-blank_source_1-mtc_maps_img'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'mtc_maps_import-blank_source_2-copy';
  $feeds_tamper->importer = 'mtc_maps_import';
  $feeds_tamper->source = 'Blank source 2';
  $feeds_tamper->plugin_id = 'copy';
  $feeds_tamper->settings = array(
    'to_from' => 'from',
    'source' => 'title',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Copy source value';
  $feeds_tampers['mtc_maps_import-blank_source_2-copy'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'mtc_maps_import-blank_source_2-mtc_maps_date';
  $feeds_tamper->importer = 'mtc_maps_import';
  $feeds_tamper->source = 'Blank source 2';
  $feeds_tamper->plugin_id = 'mtc_maps_date';
  $feeds_tamper->settings = array(
    'mtc' => 1,
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Pull the Maps month from the title';
  $feeds_tampers['mtc_maps_import-blank_source_2-mtc_maps_date'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'mtc_maps_import-name-mtc_maps_file';
  $feeds_tamper->importer = 'mtc_maps_import';
  $feeds_tamper->source = 'name';
  $feeds_tamper->plugin_id = 'mtc_maps_file';
  $feeds_tamper->settings = array(
    'directory_prefix' => '',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'MTC Map of the Month PDF fetcher';
  $feeds_tampers['mtc_maps_import-name-mtc_maps_file'] = $feeds_tamper;

  return $feeds_tampers;
