<?php
/**
 * @file
 * mls_features_language_ukrainian.features.language.inc
 */

/**
 * Implements hook_locale_default_languages().
 */
function mls_features_language_ukrainian_locale_default_languages() {
  $languages = array();

  // Exported language: uk.
  $languages['uk'] = array(
    'language' => 'uk',
    'name' => 'Ukrainian',
    'native' => 'Українська',
    'direction' => 0,
    'enabled' => 1,
    'plurals' => 0,
    'formula' => '',
    'domain' => '',
    'prefix' => 'uk',
    'weight' => 0,
  );
  return $languages;
}
