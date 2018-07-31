<?php
/**
 * @file
 * mls_features_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function mls_features_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create offer content'.
  $permissions['create offer content'] = array(
    'name' => 'create offer content',
    'roles' => array(
      'MLS Administrator' => 'MLS Administrator',
      'Moderator' => 'Moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any offer content'.
  $permissions['delete any offer content'] = array(
    'name' => 'delete any offer content',
    'roles' => array(
      'MLS Administrator' => 'MLS Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own offer content'.
  $permissions['delete own offer content'] = array(
    'name' => 'delete own offer content',
    'roles' => array(
      'MLS Administrator' => 'MLS Administrator',
      'Moderator' => 'Moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in categories'.
  $permissions['delete terms in categories'] = array(
    'name' => 'delete terms in categories',
    'roles' => array(
      'MLS Administrator' => 'MLS Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit advertisement'.
  $permissions['edit advertisement'] = array(
    'name' => 'edit advertisement',
    'roles' => array(
      'MLS Administrator' => 'MLS Administrator',
    ),
    'module' => 'custom',
  );

  // Exported permission: 'edit any offer content'.
  $permissions['edit any offer content'] = array(
    'name' => 'edit any offer content',
    'roles' => array(
      'MLS Administrator' => 'MLS Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own offer content'.
  $permissions['edit own offer content'] = array(
    'name' => 'edit own offer content',
    'roles' => array(
      'MLS Administrator' => 'MLS Administrator',
      'Moderator' => 'Moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in categories'.
  $permissions['edit terms in categories'] = array(
    'name' => 'edit terms in categories',
    'roles' => array(
      'MLS Administrator' => 'MLS Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'manage categories'.
  $permissions['manage categories'] = array(
    'name' => 'manage categories',
    'roles' => array(
      'MLS Administrator' => 'MLS Administrator',
    ),
    'module' => 'custom',
  );

  // Exported permission: 'manage users'.
  $permissions['manage users'] = array(
    'name' => 'manage users',
    'roles' => array(
      'MLS Administrator' => 'MLS Administrator',
    ),
    'module' => 'custom',
  );

  return $permissions;
}
