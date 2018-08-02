<?php
/**
 * @file
 * mls_features_menu_main_menu.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function mls_features_menu_main_menu_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_---:taxonomy/term/3.
  $menu_links['main-menu_---:taxonomy/term/3'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/3',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'будинок / частина будинку',
    'options' => array(
      'attributes' => array(
        'title' => 'будинок / частина будинку',
      ),
      'identifier' => 'main-menu_---:taxonomy/term/3',
    ),
    'module' => 'taxonomy_menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => 3,
    'customized' => 0,
    'parent_identifier' => 'main-menu_:taxonomy/term/13',
  );
  // Exported menu link: main-menu_---:taxonomy/term/4.
  $menu_links['main-menu_---:taxonomy/term/4'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/4',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'будинок / частина будинку',
    'options' => array(
      'attributes' => array(
        'title' => 'будинок / частина будинку',
      ),
      'identifier' => 'main-menu_---:taxonomy/term/4',
    ),
    'module' => 'taxonomy_menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => 3,
    'customized' => 0,
    'parent_identifier' => 'main-menu_:taxonomy/term/8',
  );
  // Exported menu link: main-menu_1-:taxonomy/term/10.
  $menu_links['main-menu_1-:taxonomy/term/10'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/10',
    'router_path' => 'taxonomy/term/%',
    'link_title' => '1 кімната',
    'options' => array(
      'attributes' => array(
        'title' => '1 кімната',
      ),
      'identifier' => 'main-menu_1-:taxonomy/term/10',
    ),
    'module' => 'taxonomy_menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'main-menu_:taxonomy/term/13',
  );
  // Exported menu link: main-menu_1-:taxonomy/term/6.
  $menu_links['main-menu_1-:taxonomy/term/6'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/6',
    'router_path' => 'taxonomy/term/%',
    'link_title' => '1 кімната',
    'options' => array(
      'attributes' => array(
        'title' => '1 кімната',
      ),
      'identifier' => 'main-menu_1-:taxonomy/term/6',
    ),
    'module' => 'taxonomy_menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'main-menu_:taxonomy/term/8',
  );
  // Exported menu link: main-menu_2-:taxonomy/term/12.
  $menu_links['main-menu_2-:taxonomy/term/12'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/12',
    'router_path' => 'taxonomy/term/%',
    'link_title' => '2 кімнати',
    'options' => array(
      'attributes' => array(
        'title' => '2 кімнати',
      ),
      'identifier' => 'main-menu_2-:taxonomy/term/12',
    ),
    'module' => 'taxonomy_menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => 1,
    'customized' => 0,
    'parent_identifier' => 'main-menu_:taxonomy/term/8',
  );
  // Exported menu link: main-menu_2-:taxonomy/term/14.
  $menu_links['main-menu_2-:taxonomy/term/14'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/14',
    'router_path' => 'taxonomy/term/%',
    'link_title' => '2 кімнати',
    'options' => array(
      'attributes' => array(
        'title' => '2 кімнати',
      ),
      'identifier' => 'main-menu_2-:taxonomy/term/14',
    ),
    'module' => 'taxonomy_menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => 1,
    'customized' => 0,
    'parent_identifier' => 'main-menu_:taxonomy/term/13',
  );
  // Exported menu link: main-menu_3-4-:taxonomy/term/11.
  $menu_links['main-menu_3-4-:taxonomy/term/11'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/11',
    'router_path' => 'taxonomy/term/%',
    'link_title' => '3-4 кімнати',
    'options' => array(
      'attributes' => array(
        'title' => '3-4 кімнати',
      ),
      'identifier' => 'main-menu_3-4-:taxonomy/term/11',
    ),
    'module' => 'taxonomy_menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => 2,
    'customized' => 0,
    'parent_identifier' => 'main-menu_:taxonomy/term/13',
  );
  // Exported menu link: main-menu_3-4-:taxonomy/term/9.
  $menu_links['main-menu_3-4-:taxonomy/term/9'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/9',
    'router_path' => 'taxonomy/term/%',
    'link_title' => '3-4 кімнати',
    'options' => array(
      'attributes' => array(
        'title' => '3-4 кімнати',
      ),
      'identifier' => 'main-menu_3-4-:taxonomy/term/9',
    ),
    'module' => 'taxonomy_menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => 2,
    'customized' => 0,
    'parent_identifier' => 'main-menu_:taxonomy/term/8',
  );
  // Exported menu link: main-menu_:taxonomy/term/1.
  $menu_links['main-menu_:taxonomy/term/1'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/1',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Район',
    'options' => array(
      'attributes' => array(
        'title' => 'Район',
      ),
      'identifier' => 'main-menu_:taxonomy/term/1',
    ),
    'module' => 'taxonomy_menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => 4,
    'customized' => 0,
  );
  // Exported menu link: main-menu_:taxonomy/term/13.
  $menu_links['main-menu_:taxonomy/term/13'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/13',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Продам',
    'options' => array(
      'attributes' => array(
        'title' => 'Продам',
      ),
      'identifier' => 'main-menu_:taxonomy/term/13',
    ),
    'module' => 'taxonomy_menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => 1,
    'customized' => 0,
  );
  // Exported menu link: main-menu_:taxonomy/term/2.
  $menu_links['main-menu_:taxonomy/term/2'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/2',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Здам',
    'options' => array(
      'attributes' => array(
        'title' => 'Здам',
      ),
      'identifier' => 'main-menu_:taxonomy/term/2',
    ),
    'module' => 'taxonomy_menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => 3,
    'customized' => 0,
  );
  // Exported menu link: main-menu_:taxonomy/term/5.
  $menu_links['main-menu_:taxonomy/term/5'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/5',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Зніму',
    'options' => array(
      'attributes' => array(
        'title' => 'Зніму',
      ),
      'identifier' => 'main-menu_:taxonomy/term/5',
    ),
    'module' => 'taxonomy_menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => 2,
    'customized' => 0,
  );
  // Exported menu link: main-menu_:taxonomy/term/7.
  $menu_links['main-menu_:taxonomy/term/7'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/7',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Різне',
    'options' => array(
      'attributes' => array(
        'title' => 'Різне',
      ),
      'identifier' => 'main-menu_:taxonomy/term/7',
    ),
    'module' => 'taxonomy_menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => 5,
    'customized' => 0,
  );
  // Exported menu link: main-menu_:taxonomy/term/8.
  $menu_links['main-menu_:taxonomy/term/8'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/8',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Куплю',
    'options' => array(
      'attributes' => array(
        'title' => 'Куплю',
      ),
      'identifier' => 'main-menu_:taxonomy/term/8',
    ),
    'module' => 'taxonomy_menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => 0,
    'customized' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('1 кімната');
  t('2 кімнати');
  t('3-4 кімнати');
  t('Здам');
  t('Зніму');
  t('Куплю');
  t('Продам');
  t('Район');
  t('Різне');
  t('будинок / частина будинку');

  return $menu_links;
}
