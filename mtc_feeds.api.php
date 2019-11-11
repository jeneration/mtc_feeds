<?php
/**
 * @file
 * API definitions for mtc_feeds module.
 */

/**
 * Allow the meeting author UID to be altered per site.
 */
function hook_mtc_meeting_import_author_alter(&$meeting_import_author){
  $meeting_import_author = 331;
  return $meeting_import_author;
}
