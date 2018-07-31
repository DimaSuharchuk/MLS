<?php
/**
 * @file
 * mls_features_taxonomy_categories.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function mls_features_taxonomy_categories_taxonomy_default_vocabularies() {
  return array(
    'categories' => array(
      'name' => 'Categories',
      'machine_name' => 'categories',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
