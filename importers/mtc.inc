<?php
/**
 * @file
 * Feeds importer: mtc
 */

$feeds_importer = new stdClass();
$feeds_importer->disabled = TRUE; /* Edit this to true to make a default feeds_importer disabled initially */
$feeds_importer->api_version = 1;
$feeds_importer->id = 'mtc';
$feeds_importer->config = array(
  'name' => 'MTC Meetings v1',
  'description' => 'Import meeting info from Granicus Legistar JSON feed.',
  'fetcher' => array(
    'plugin_key' => 'FeedsHTTPFetcherAppendHeaders',
    'config' => array(
      'append_headers' => 'Accept|application/json',
      'request_timeout' => '',
    ),
  ),
  'parser' => array(
    'plugin_key' => 'FeedsExJsonPath',
    'config' => array(
      'sources' => array(
        'eventguid' => array(
          'name' => 'EventGuid',
          'value' => 'EventGuid',
          'debug' => 0,
          'weight' => '0',
        ),
        'eventbodyname' => array(
          'name' => 'EventBodyName',
          'value' => 'EventBodyName',
          'debug' => 0,
          'weight' => '1',
        ),
        'eventlocation' => array(
          'name' => 'EventLocation',
          'value' => 'EventLocation',
          'debug' => 0,
          'weight' => '2',
        ),
        'eventdate' => array(
          'name' => 'EventDate',
          'value' => 'EventDate',
          'debug' => 0,
          'weight' => '3',
        ),
        'eventtime' => array(
          'name' => 'EventTime',
          'value' => 'EventTime',
          'debug' => 0,
          'weight' => '4',
        ),
      ),
      'context' => array(
        'value' => '$.*',
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
      'bundle' => 'meeting',
      'update_existing' => '2',
      'expire' => '-1',
      'mappings' => array(
        0 => array(
          'source' => 'eventguid',
          'target' => 'guid',
          'unique' => 1,
        ),
        1 => array(
          'source' => 'eventbodyname',
          'target' => 'title',
          'unique' => FALSE,
        ),
        2 => array(
          'source' => 'eventlocation',
          'target' => 'field_meeting_location',
          'unique' => FALSE,
        ),
        3 => array(
          'source' => 'eventdate',
          'target' => 'field_meeting_date:start',
          'unique' => FALSE,
        ),
        4 => array(
          'source' => 'eventtime',
          'target' => 'field_meeting_time',
          'unique' => FALSE,
        ),
      ),
      'input_format' => 'plain_text',
      'author' => '431',
      'authorize' => 0,
      'update_non_existent' => 'skip',
      'skip_hash_check' => 0,
    ),
  ),
  'content_type' => '',
  'update' => 0,
  'import_period' => '-1',
  'expire_period' => 3600,
  'import_on_create' => 1,
  'process_in_background' => 0,
);
