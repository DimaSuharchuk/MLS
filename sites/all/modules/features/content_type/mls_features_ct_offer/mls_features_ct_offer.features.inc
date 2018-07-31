<?php
/**
 * @file
 * mls_features_ct_offer.features.inc
 */

/**
 * Implements hook_node_info().
 */
function mls_features_ct_offer_node_info() {
  $items = array(
    'offer' => array(
      'name' => t('Offer'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
