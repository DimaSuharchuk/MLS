<?php

/**
 * Implements template_preprocess_html().
 */
function mls_preprocess_html(&$variables) {
}

/**
 * Implements template_preprocess_page.
 */
function mls_preprocess_page(&$variables) {
}

/**
 * Implements template_preprocess_node.
 *
 * @throws \Exception
 */
function mls_preprocess_node(&$variables) {
  if ($variables['type'] === 'offer') {
    // Remove linked node title.
    $variables['page'] = TRUE;
    // Add custom title to Offer content type.
    $variables['content']['title'] = [
      '#markup' => theme('html_tag', [
        'element' => [
          '#tag' => 'h3',
          '#value' => $variables['title'],
          '#attributes' => [
            'class' => ['page-title'],
          ],
        ],
      ]),
      '#weight' => -1,
    ];
  }
}

/**
 * Implements template_preprocess_views_view.
 *
 * @throws \Exception
 */
function mls_preprocess_views_view(&$variables) {
  if ($variables['name'] === 'taxonomy_category' && $variables['display_id'] === 'page') {
    $tid = arg()[2];
    // Add link "add Offer" for "most" child taxonomy Category page overview.
    if (!taxonomy_get_children($tid)) {
      $variables['header'] = theme('html_tag', [
        'element' => [
          '#tag' => 'div',
          '#attributes' => [
            'class' => 'add-offer-wrapper',
          ],
          '#value' => l(t('Add offer'), "offer/add", ['query' => ['tid' => $tid]]),
        ],
      ]);
    }
  }
}
