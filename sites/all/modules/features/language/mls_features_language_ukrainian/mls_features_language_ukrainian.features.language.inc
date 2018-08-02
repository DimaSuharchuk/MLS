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
    'plurals' => 3,
    'formula' => '(((($n%10)==1)&&(($n%100)!=11))?(0):((((($n%10)>=2)&&(($n%10)<=4))&&((($n%100)<10)||(($n%100)>=20)))?(1):2))',
    'domain' => '',
    'prefix' => 'uk',
    'weight' => 0,
  );
  return $languages;
}
