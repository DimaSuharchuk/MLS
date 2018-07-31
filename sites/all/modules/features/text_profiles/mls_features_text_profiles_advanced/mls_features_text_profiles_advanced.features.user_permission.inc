<?php
/**
 * @file
 * mls_features_text_profiles_advanced.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function mls_features_text_profiles_advanced_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'use text format advanced'.
  $permissions['use text format advanced'] = array(
    'name' => 'use text format advanced',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  return $permissions;
}
