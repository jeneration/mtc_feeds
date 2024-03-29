<?php
/**
 * @file
 * Feeds importer: mtc
 */

$feeds_importer = new stdClass();
$feeds_importer->disabled = TRUE; /* Edit this to true to make a default feeds_importer disabled initially */
$feeds_importer->api_version = 1;
$feeds_importer->id = 'mtc_meetings_import';
$feeds_importer->config = array(
  'name' => 'MTC Meetings v2',
  'description' => 'Import meeting info from Granicus (data from both the Media Manager API and Legistar API, combined)',
  'fetcher' => array(
    'plugin_key' => 'FeedsHTTPFetcher',
    'config' => array(
      'auto_detect_feeds' => FALSE,
      'use_pubsubhubbub' => FALSE,
      'designated_hub' => '',
      'request_timeout' => NULL,
      'auto_scheme' => 'http',
      'accept_invalid_cert' => FALSE,
    ),
  ),
  'parser' => array(
    'plugin_key' => 'FeedsExXml',
    'config' => array(
      'use_tidy' => FALSE,
      'sources' => array(
        'id' => array(
          'name' => 'ID',
          'value' => 'ID',
          'raw' => 0,
          'inner' => 0,
          'debug' => 0,
          'weight' => '0',
        ),
        'uid' => array(
          'name' => 'UID',
          'value' => 'UID',
          'raw' => 0,
          'inner' => 0,
          'debug' => 0,
          'weight' => '1',
        ),
        'name' => array(
          'name' => 'Name',
          'value' => 'Name',
          'raw' => 0,
          'inner' => 0,
          'debug' => 0,
          'weight' => '2',
        ),
        'starttime' => array(
          'name' => 'StartTime',
          'value' => 'StartTime',
          'raw' => 0,
          'inner' => 0,
          'debug' => 0,
          'weight' => '3',
        ),
        'location' => array(
          'name' => 'Location',
          'value' => 'Location',
          'raw' => 0,
          'inner' => 0,
          'debug' => 0,
          'weight' => '4',
        ),
        'minutesfilegranicus' => array(
          'name' => 'MinutesFileGranicus',
          'value' => 'MinutesFileGranicus',
          'raw' => 0,
          'inner' => 0,
          'debug' => 0,
          'weight' => '6',
        ),
        'agendafile' => array(
          'name' => 'AgendaFile',
          'value' => 'AgendaFile',
          'raw' => 0,
          'inner' => 0,
          'debug' => 0,
          'weight' => '8',
        ),
        'clipid' => array(
          'name' => 'ClipID',
          'value' => 'Clips/Clip/@ID',
          'raw' => 0,
          'inner' => 0,
          'debug' => 0,
          'weight' => '9',
        ),
        'agendaposteddate' => array(
          'name' => 'AgendaPostedDate',
          'value' => 'AgendaPostedDate',
          'raw' => 0,
          'inner' => 0,
          'debug' => 0,
          'weight' => '10',
        ),
      ),
      'context' => array(
        'value' => 'Events/Event',
      ),
      'display_errors' => 0,
      'source_encoding' => array(
        0 => 'auto',
      ),
      'debug_mode' => 0,
    ),
  ),
  'processor' => array(
    'plugin_key' => 'FeedsNodeProcessor',
    'config' => array(
      'expire' => '-1',
      'author' => '431',
      'authorize' => 0,
      'mappings' => array(
        0 => array(
          'source' => 'uid',
          'target' => 'guid',
          'unique' => 1,
        ),
        1 => array(
          'source' => 'id',
          'target' => 'field_meeting_id',
          'unique' => FALSE,
        ),
        2 => array(
          'source' => 'uid',
          'target' => 'field_unique_id',
          'unique' => FALSE,
        ),
        3 => array(
          'source' => 'name',
          'target' => 'field_meeting_name',
          'unique' => FALSE,
        ),
        4 => array(
          'source' => 'starttime',
          'target' => 'Temporary target 1',
          'unique' => FALSE,
        ),
        5 => array(
          'source' => 'Blank source 1',
          'target' => 'field_meeting_date_time:start',
          'unique' => FALSE,
        ),
        6 => array(
          'source' => 'Blank source 2',
          'target' => 'field_meeting_date:start',
          'unique' => FALSE,
        ),
        7 => array(
          'source' => 'Blank source 3',
          'target' => 'field_meeting_time',
          'unique' => FALSE,
        ),
        8 => array(
          'source' => 'location',
          'target' => 'field_meeting_location',
          'unique' => FALSE,
        ),
        9 => array(
          'source' => 'agendafile',
          'target' => 'field_meeting_agenda:uri',
          'unique' => FALSE,
        ),
        10 => array(
          'source' => 'minutesfilegranicus',
          'target' => 'field_meeting_minutes:uri',
          'unique' => FALSE,
        ),
        11 => array(
          'source' => 'clipid',
          'target' => 'field_meeting_recording:url',
          'unique' => FALSE,
        ),
        12 => array(
          'source' => 'agendaposteddate',
          'target' => 'field_update_trigger',
          'unique' => FALSE,
        ),
      ),
      'update_existing' => '2',
      'update_non_existent' => 'skip',
      'input_format' => 'plain_text',
      'skip_hash_check' => 0,
      'bundle' => 'meeting',
      'insert_new' => '1',
      'language' => 'und',
    ),
  ),
  'content_type' => '',
  'update' => 0,
  'import_period' => '3600',
  'expire_period' => 3600,
  'import_on_create' => 1,
  'process_in_background' => 0,
);
