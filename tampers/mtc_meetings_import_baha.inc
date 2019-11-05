<?php
/**
 * Tampers for the mtc_meetings_import_baha feed.
 */

$feeds_tampers = array();

$feeds_tamper = new stdClass();
$feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
$feeds_tamper->api_version = 2;
$feeds_tamper->id = 'mtc_meetings_import_baha-agendafile-mtc_file_fetcher';
$feeds_tamper->importer = 'mtc_meetings_import_baha';
$feeds_tamper->source = 'agendafile';
$feeds_tamper->plugin_id = 'mtc_file_fetcher';
$feeds_tamper->settings = array(
  'directory_prefix' => 'meetings/agendas/',
);
$feeds_tamper->weight = 0;
$feeds_tamper->description = 'MTC File fetcher';

$feeds_tampers[$feeds_tamper->id] = $feeds_tamper;

$feeds_tamper = new stdClass();
$feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
$feeds_tamper->api_version = 2;
$feeds_tamper->id = 'mtc_meetings_import_baha-blank_source_1-copy';
$feeds_tamper->importer = 'mtc_meetings_import_baha';
$feeds_tamper->source = 'Blank source 1';
$feeds_tamper->plugin_id = 'copy';
$feeds_tamper->settings = array(
  'to_from' => 'from',
  'source' => 'starttime',
);
$feeds_tamper->weight = 0;
$feeds_tamper->description = 'Copy source value';

$feeds_tampers[$feeds_tamper->id] = $feeds_tamper;

$feeds_tamper = new stdClass();
$feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
$feeds_tamper->api_version = 2;
$feeds_tamper->id = 'mtc_meetings_import_baha-blank_source_1-strtotime';
$feeds_tamper->importer = 'mtc_meetings_import_baha';
$feeds_tamper->source = 'Blank source 1';
$feeds_tamper->plugin_id = 'strtotime';
$feeds_tamper->settings = array();
$feeds_tamper->weight = 1;
$feeds_tamper->description = 'String to Unix timestamp';

$feeds_tampers[$feeds_tamper->id] = $feeds_tamper;

$feeds_tamper = new stdClass();
$feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
$feeds_tamper->api_version = 2;
$feeds_tamper->id = 'mtc_meetings_import_baha-blank_source_2-mtc_video_baha_title';
$feeds_tamper->importer = 'mtc_meetings_import_baha';
$feeds_tamper->source = 'Blank source 2';
$feeds_tamper->plugin_id = 'mtc_video_baha_title';
$feeds_tamper->settings = array(
  'default_value' => 'Video Recording',
);
$feeds_tamper->weight = 3;
$feeds_tamper->description = 'Create a video title';

$feeds_tampers[$feeds_tamper->id] = $feeds_tamper;

$feeds_tamper = new stdClass();
$feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
$feeds_tamper->api_version = 2;
$feeds_tamper->id = 'mtc_meetings_import_baha-clipid-mtc_video_baha';
$feeds_tamper->importer = 'mtc_meetings_import_baha';
$feeds_tamper->source = 'clipid';
$feeds_tamper->plugin_id = 'mtc_video_baha';
$feeds_tamper->settings = array(
  'mtc' => 1,
);
$feeds_tamper->weight = 0;
$feeds_tamper->description = 'Create video player URL';

$feeds_tampers[$feeds_tamper->id] = $feeds_tamper;

$feeds_tamper = new stdClass();
$feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
$feeds_tamper->api_version = 2;
$feeds_tamper->id = 'mtc_meetings_import_baha-contactemail-find_replace';
$feeds_tamper->importer = 'mtc_meetings_import_baha';
$feeds_tamper->source = 'contactemail';
$feeds_tamper->plugin_id = 'find_replace';
$feeds_tamper->settings = array(
  'find' => 'null',
  'replace' => '',
  'case_sensitive' => 0,
  'word_boundaries' => 0,
  'whole' => 0,
  'regex' => FALSE,
  'func' => 'str_ireplace',
);
$feeds_tamper->weight = 0;
$feeds_tamper->description = 'Find replace';

$feeds_tampers[$feeds_tamper->id] = $feeds_tamper;

$feeds_tamper = new stdClass();
$feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
$feeds_tamper->api_version = 2;
$feeds_tamper->id = 'mtc_meetings_import_baha-contactname-find_replace';
$feeds_tamper->importer = 'mtc_meetings_import_baha';
$feeds_tamper->source = 'contactname';
$feeds_tamper->plugin_id = 'find_replace';
$feeds_tamper->settings = array(
  'find' => 'null',
  'replace' => '',
  'case_sensitive' => 0,
  'word_boundaries' => 0,
  'whole' => 0,
  'regex' => FALSE,
  'func' => 'str_ireplace',
);
$feeds_tamper->weight = 0;
$feeds_tamper->description = 'Find replace';

$feeds_tampers[$feeds_tamper->id] = $feeds_tamper;

$feeds_tamper = new stdClass();
$feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
$feeds_tamper->api_version = 2;
$feeds_tamper->id = 'mtc_meetings_import_baha-location-mtc_location';
$feeds_tamper->importer = 'mtc_meetings_import_baha';
$feeds_tamper->source = 'location';
$feeds_tamper->plugin_id = 'mtc_location';
$feeds_tamper->settings = array(
  'mtc' => 1,
);
$feeds_tamper->weight = 0;
$feeds_tamper->description = 'Remove NULL from location.';

$feeds_tampers[$feeds_tamper->id] = $feeds_tamper;

$feeds_tamper = new stdClass();
$feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
$feeds_tamper->api_version = 2;
$feeds_tamper->id = 'mtc_meetings_import_baha-name-mtc_shift';
$feeds_tamper->importer = 'mtc_meetings_import_baha';
$feeds_tamper->source = 'name';
$feeds_tamper->plugin_id = 'mtc_shift';
$feeds_tamper->settings = array(
  'mtc' => 1,
);
$feeds_tamper->weight = 0;
$feeds_tamper->description = 'Remove date from meeting name.';

$feeds_tampers[$feeds_tamper->id] = $feeds_tamper;

$feeds_tamper = new stdClass();
$feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
$feeds_tamper->api_version = 2;
$feeds_tamper->id = 'mtc_meetings_import_baha-blank_source_3-copy2';
$feeds_tamper->importer = 'mtc_meetings_import_baha';
$feeds_tamper->source = 'Blank source 3';
$feeds_tamper->plugin_id = 'copy';
$feeds_tamper->settings = array(
  'to_from' => 'from',
  'source' => 'Blank source 2',
);
$feeds_tamper->weight = 2;
$feeds_tamper->description = 'Copy source value';

$feeds_tampers[$feeds_tamper->id] = $feeds_tamper;

$feeds_tamper = new stdClass();
$feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
$feeds_tamper->api_version = 2;
$feeds_tamper->id = 'mtc_meetings_import_baha-blank_source_3-mtc_time';
$feeds_tamper->importer = 'mtc_meetings_import_baha';
$feeds_tamper->source = 'Blank source 3';
$feeds_tamper->plugin_id = 'mtc_time';
$feeds_tamper->settings = array(
  'mtc' => 1,
);
$feeds_tamper->weight = 3;
$feeds_tamper->description = 'Pull time from date';

$feeds_tampers[$feeds_tamper->id] = $feeds_tamper;

$feeds_tamper = new stdClass();
$feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
$feeds_tamper->api_version = 2;
$feeds_tamper->id = 'mtc_meetings_import_baha-minutesfilegranicus-mtc_file_fetcher';
$feeds_tamper->importer = 'mtc_meetings_import_baha';
$feeds_tamper->source = 'minutesfilegranicus';
$feeds_tamper->plugin_id = 'mtc_file_fetcher';
$feeds_tamper->settings = array(
  'directory_prefix' => 'meetings/minutes/',
);
$feeds_tamper->weight = 0;
$feeds_tamper->description = 'MTC File fetcher';

$feeds_tampers[$feeds_tamper->id] = $feeds_tamper;
