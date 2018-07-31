<?php
/**
 * @file
 * mls_features_text_profiles_advanced.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function mls_features_text_profiles_advanced_filter_default_formats() {
  $formats = array();

  // Exported format: Advanced.
  $formats['advanced'] = array(
    'format' => 'advanced',
    'name' => 'Advanced',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(),
  );

  return $formats;
}
