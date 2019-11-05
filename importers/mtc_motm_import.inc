<?php
/**
 * @file
 * Feeds importer: mtc_motm
 */

$feeds_importer = new stdClass();
$feeds_importer->disabled = TRUE; /* Edit this to true to make a default feeds_importer disabled initially */
$feeds_importer->api_version = 1;
$feeds_importer->id = 'mtc_motm_import';
$feeds_importer->config = array(
  'name' => 'MTC Map of the Month v3',
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
        'value' => '$.*',
      ),
      'sources' => array(
        'id' => array(
          'name' => 'id',
          'value' => 'id',
          'debug' => 0,
          'weight' => '0',
        ),
        'title' => array(
          'name' => 'title',
          'value' => 'title',
          'debug' => 0,
          'weight' => '1',
        ),
        'owner' => array(
          'name' => 'author',
          'value' => 'author',
          'debug' => 0,
          'weight' => '2',
        ),
        'description' => array(
          'name' => 'description',
          'value' => 'description',
          'debug' => 0,
          'weight' => '3',
        ),
        'name' => array(
          'name' => 'link_pdf',
          'value' => 'link_pdf',
          'debug' => 0,
          'weight' => '4',
        ),
        'link_png' => array(
          'name' => 'link_png',
          'value' => 'link_png',
          'debug' => 0,
          'weight' => '5',
        ),
        'month' => array(
          'name' => 'month',
          'value' => 'month',
          'debug' => 0,
          'weight' => '6',
        ),
        'monthid' => array(
          'name' => 'monthid',
          'value' => 'monthid',
          'debug' => 0,
          'weight' => '7',
        ),
        'year' => array(
          'name' => 'year',
          'value' => 'year',
          'debug' => 0,
          'weight' => '8',
        ),
        'post_date' => array(
          'name' => 'post_date',
          'value' => 'post_date',
          'debug' => 0,
          'weight' => '9',
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
          'source' => 'title',
          'target' => 'title',
          'unique' => FALSE,
          'language' => 'und',
        ),
        3 => array(
          'source' => 'owner',
          'target' => 'field_admin_name',
          'unique' => FALSE,
          'language' => 'und',
        ),
        4 => array(
          'source' => 'description',
          'target' => 'body',
          'format' => 'filtered_html',
          'language' => 'und',
        ),
        5 => array(
          'source' => 'name',
          'target' => 'field_map_document:uri',
          'unique' => FALSE,
          'language' => 'und',
        ),
        6 => array(
          'source' => 'link_png',
          'target' => 'field_image:uri',
          'unique' => FALSE,
          'language' => 'und',
        ),
        7 => array(
          'source' => 'month',
          'target' => 'field_map_month',
          'unique' => FALSE,
          'language' => 'und',
        ),
        8 => array(
          'source' => 'monthid',
          'target' => 'field_map_month_id',
          'unique' => FALSE,
          'language' => 'und',
        ),
        9 => array(
          'source' => 'year',
          'target' => 'field_map_year',
          'unique' => FALSE,
          'language' => 'und',
        ),
        10 => array(
          'source' => 'Blank source 2',
          'target' => 'field_date_appointed:start',
          'unique' => FALSE,
          'language' => 'und',
        ),
        11 => array(
          'source' => 'post_date',
          'target' => 'created',
          'unique' => FALSE,
          'language' => 'und',
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
