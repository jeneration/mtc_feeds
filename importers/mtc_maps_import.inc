<?php
/**
 * @file
 * Feeds importer: mtc_maps
 */

$feeds_importer = new stdClass();
$feeds_importer->disabled = TRUE; /* Edit this to true to make a default feeds_importer disabled initially */
$feeds_importer->api_version = 1;
$feeds_importer->id = 'mtc_maps_import';
$feeds_importer->config = array(
  'name' => 'Map of the Month - v2',
  'description' => 'Import JSON data for map of the month',
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
      'context' => array(
        'value' => '$.results.*',
      ),
      'sources' => array(
        'id' => array(
          'name' => 'id',
          'value' => 'id',
          'debug' => 0,
          'weight' => '0',
        ),
        'owner' => array(
          'name' => 'owner',
          'value' => 'owner',
          'debug' => 0,
          'weight' => '1',
        ),
        'created' => array(
          'name' => 'created',
          'value' => 'created',
          'debug' => 0,
          'weight' => '2',
        ),
        'updated' => array(
          'name' => 'updated',
          'value' => 'modified',
          'debug' => 0,
          'weight' => '3',
        ),
        'name' => array(
          'name' => 'filename',
          'value' => 'name',
          'debug' => 0,
          'weight' => '4',
        ),
        'title' => array(
          'name' => 'title',
          'value' => 'title',
          'debug' => 0,
          'weight' => '5',
        ),
        'type' => array(
          'name' => 'type',
          'value' => 'type',
          'debug' => 0,
          'weight' => '6',
        ),
        'description' => array(
          'name' => 'description',
          'value' => 'description',
          'debug' => 0,
          'weight' => '7',
        ),
        'tags' => array(
          'name' => 'tags',
          'value' => 'tags',
          'debug' => 0,
          'weight' => '9',
        ),
        'culture' => array(
          'name' => 'culture',
          'value' => 'culture',
          'debug' => 0,
          'weight' => '11',
        ),
      ),
      'display_errors' => 0,
      'debug_mode' => 0,
      'source_encoding' => array(
        0 => 'auto',
      ),
    ),
  ),
  'processor' => array(
    'plugin_key' => 'FeedsNodeProcessor',
    'config' => array(
      'bundle' => 'map',
      'update_existing' => '2',
      'expire' => '-1',
      'mappings' => array(
        0 => array(
          'source' => 'id',
          'target' => 'guid',
          'unique' => 1,
          'language' => 'und',
        ),
        1 => array(
          'source' => 'id',
          'target' => 'field_map_unique_id',
          'unique' => FALSE,
          'language' => 'und',
        ),
        2 => array(
          'source' => 'owner',
          'target' => 'field_admin_name',
          'unique' => FALSE,
          'language' => 'und',
        ),
        3 => array(
          'source' => 'name',
          'target' => 'field_map_document:uri',
          'unique' => FALSE,
          'language' => 'und',
        ),
        4 => array(
          'source' => 'title',
          'target' => 'title',
          'unique' => FALSE,
          'language' => 'und',
        ),
        5 => array(
          'source' => 'type',
          'target' => 'field_map_type',
          'unique' => FALSE,
          'language' => 'und',
        ),
        6 => array(
          'source' => 'description',
          'target' => 'body',
          'format' => 'filtered_html',
          'language' => 'und',
        ),
        7 => array(
          'source' => 'tags',
          'target' => 'field_map_tags',
          'unique' => FALSE,
          'language' => 'und',
        ),
        8 => array(
          'source' => 'culture',
          'target' => 'field_map_culture',
          'unique' => FALSE,
          'language' => 'und',
        ),
        9 => array(
          'source' => 'Blank source 1',
          'target' => 'field_image:uri',
          'unique' => FALSE,
          'language' => 'und',
        ),
        10 => array(
          'source' => 'Blank source 2',
          'target' => 'field_date_appointed:start',
          'unique' => FALSE,
        ),
      ),
      'input_format' => 'plain_text',
      'author' => '3596',
      'authorize' => 0,
      'update_non_existent' => 'skip',
      'skip_hash_check' => 0,
      'insert_new' => '1',
      'language' => 'und',
    ),
  ),
  'content_type' => '',
  'update' => 0,
  'import_period' => '86400',
  'expire_period' => 3600,
  'import_on_create' => 1,
  'process_in_background' => 0,
);
