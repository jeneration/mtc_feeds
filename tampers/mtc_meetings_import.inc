<?php
/**
 * Tampers for the mtc_meetings_import feed.
 */

$feeds_tampers = array();

$feeds_tamper = new stdClass();
$feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
$feeds_tamper->api_version = 2;
$feeds_tamper->id = 'mtc_meetings_import-agendafile-file_fetcher';
$feeds_tamper->importer = 'mtc_meetings_import';
$feeds_tamper->source = 'agendafile';
$feeds_tamper->plugin_id = 'file_fetcher';
$feeds_tamper->settings = array(
  'directory_prefix' => 'meetings/agendas/',
  'directory_strip' => '',
);
$feeds_tamper->weight = 0;
$feeds_tamper->description = 'File fetcher';
$feeds_tampers['mtc_meetings_import-agendafile-file_fetcher'] = $feeds_tamper;

$feeds_tamper = new stdClass();
$feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
$feeds_tamper->api_version = 2;
$feeds_tamper->id = 'mtc_meetings_import-blank_source_1-copy';
$feeds_tamper->importer = 'mtc_meetings_import';
$feeds_tamper->source = 'Blank source 1';
$feeds_tamper->plugin_id = 'copy';
$feeds_tamper->settings = array(
  'to_from' => 'from',
  'source' => 'starttime',
);
$feeds_tamper->weight = 0;
$feeds_tamper->description = 'Copy source value';
$feeds_tampers['mtc_meetings_import-blank_source_1-copy'] = $feeds_tamper;

$feeds_tamper = new stdClass();
$feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
$feeds_tamper->api_version = 2;
$feeds_tamper->id = 'mtc_meetings_import-blank_source_1-strtotime';
$feeds_tamper->importer = 'mtc_meetings_import';
$feeds_tamper->source = 'Blank source 1';
$feeds_tamper->plugin_id = 'strtotime';
$feeds_tamper->settings = array();
$feeds_tamper->weight = 1;
$feeds_tamper->description = 'String to Unix timestamp';
$feeds_tampers['mtc_meetings_import-blank_source_1-strtotime'] = $feeds_tamper;

$feeds_tamper = new stdClass();
$feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
$feeds_tamper->api_version = 2;
$feeds_tamper->id = 'mtc_meetings_import-blank_source_2-copy';
$feeds_tamper->importer = 'mtc_meetings_import';
$feeds_tamper->source = 'Blank source 2';
$feeds_tamper->plugin_id = 'copy';
$feeds_tamper->settings = array(
  'to_from' => 'from',
  'source' => 'starttime',
);
$feeds_tamper->weight = 0;
$feeds_tamper->description = 'Copy source value';
$feeds_tampers['mtc_meetings_import-blank_source_2-copy'] = $feeds_tamper;

$feeds_tamper = new stdClass();
$feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
$feeds_tamper->api_version = 2;
$feeds_tamper->id = 'mtc_meetings_import-blank_source_2-strtotime';
$feeds_tamper->importer = 'mtc_meetings_import';
$feeds_tamper->source = 'Blank source 2';
$feeds_tamper->plugin_id = 'strtotime';
$feeds_tamper->settings = array();
$feeds_tamper->weight = 1;
$feeds_tamper->description = 'String to Unix timestamp';
$feeds_tampers['mtc_meetings_import-blank_source_2-strtotime'] = $feeds_tamper;

$feeds_tamper = new stdClass();
$feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
$feeds_tamper->api_version = 2;
$feeds_tamper->id = 'mtc_meetings_import-blank_source_3-copy2';
$feeds_tamper->importer = 'mtc_meetings_import';
$feeds_tamper->source = 'Blank source 3';
$feeds_tamper->plugin_id = 'copy';
$feeds_tamper->settings = array(
  'to_from' => 'from',
  'source' => 'Blank source 2',
);
$feeds_tamper->weight = 2;
$feeds_tamper->description = 'Copy source value';
$feeds_tampers['mtc_meetings_import-blank_source_3-copy2'] = $feeds_tamper;

$feeds_tamper = new stdClass();
$feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
$feeds_tamper->api_version = 2;
$feeds_tamper->id = 'mtc_meetings_import-blank_source_3-mtc_time';
$feeds_tamper->importer = 'mtc_meetings_import';
$feeds_tamper->source = 'Blank source 3';
$feeds_tamper->plugin_id = 'mtc_time';
$feeds_tamper->settings = array(
  'mtc' => 1,
);
$feeds_tamper->weight = 3;
$feeds_tamper->description = 'Pull time from date';
$feeds_tampers['mtc_meetings_import-blank_source_3-mtc_time'] = $feeds_tamper;

$feeds_tamper = new stdClass();
$feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
$feeds_tamper->api_version = 2;
$feeds_tamper->id = 'mtc_meetings_import-clipid-mtc_video';
$feeds_tamper->importer = 'mtc_meetings_import';
$feeds_tamper->source = 'clipid';
$feeds_tamper->plugin_id = 'mtc_video';
$feeds_tamper->settings = array(
  'mtc' => 1,
);
$feeds_tamper->weight = 0;
$feeds_tamper->description = 'Create video player URL';
$feeds_tampers['mtc_meetings_import-clipid-mtc_video'] = $feeds_tamper;

$feeds_tamper = new stdClass();
$feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
$feeds_tamper->api_version = 2;
$feeds_tamper->id = 'mtc_meetings_import-location-mtc_location';
$feeds_tamper->importer = 'mtc_meetings_import';
$feeds_tamper->source = 'location';
$feeds_tamper->plugin_id = 'mtc_location';
$feeds_tamper->settings = array(
  'mtc' => 1,
);
$feeds_tamper->weight = 0;
$feeds_tamper->description = 'Remove NULL from location.';
$feeds_tampers['mtc_meetings_import-location-mtc_location'] = $feeds_tamper;

$feeds_tamper = new stdClass();
$feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
$feeds_tamper->api_version = 2;
$feeds_tamper->id = 'mtc_meetings_import-minutesfilegranicus-file_fetcher';
$feeds_tamper->importer = 'mtc_meetings_import';
$feeds_tamper->source = 'minutesfilegranicus';
$feeds_tamper->plugin_id = 'file_fetcher';
$feeds_tamper->settings = array(
  'directory_prefix' => 'meetings/minutes/',
  'directory_strip' => '',
);
$feeds_tamper->weight = 0;
$feeds_tamper->description = 'File fetcher';
$feeds_tampers['mtc_meetings_import-minutesfilegranicus-file_fetcher'] = $feeds_tamper;

$feeds_tamper = new stdClass();
$feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
$feeds_tamper->api_version = 2;
$feeds_tamper->id = 'mtc_meetings_import-name-mtc_shift';
$feeds_tamper->importer = 'mtc_meetings_import';
$feeds_tamper->source = 'name';
$feeds_tamper->plugin_id = 'mtc_shift';
$feeds_tamper->settings = array(
  'mtc' => 1,
);
$feeds_tamper->weight = 0;
$feeds_tamper->description = 'Remove date from meeting name.';
$feeds_tampers['mtc_meetings_import-name-mtc_shift'] = $feeds_tamper;

