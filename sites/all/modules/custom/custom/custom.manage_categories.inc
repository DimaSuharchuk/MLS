<?php
/**
 * @file
 * Manage categories functionality.
 */

/**
 * Manage categories page.
 */
function custom_manage_categories_page() {
  // Hide messages about taxonomy and menu updated.
  drupal_get_messages();

  $page['add'] = drupal_get_form('custom_manage_add_category_form');

  // Extends taxonomy overview terms form.
  module_load_include('inc', 'taxonomy', 'taxonomy.admin');
  drupal_add_js(drupal_get_path('module', 'taxonomy') . '/taxonomy.js');
  $vocabulary = taxonomy_vocabulary_machine_name_load('categories');
  $page['table'] = drupal_get_form('taxonomy_overview_terms', $vocabulary);

  // Change regular "secondary" (grey) button class to "success" (green).
  $page['table']['actions']['submit']['#attributes']['class'][0] = 'success';
  // Hide unnecessary button.
  $page['table']['actions']['reset_alphabetical']['#access'] = FALSE;

  return $page;
}

/**
 * Form for add new term "category".
 */
function custom_manage_add_category_form($form, &$form_state) {
  // Add term.
  $form['add_term'] = [
    '#type' => 'textfield',
    '#size' => 20,
    '#attributes' => [
      'placeholder' => t('Add category'),
    ],
  ];
  $form['submit'] = [
    '#type' => 'submit',
    '#value' => t('Add'),
    '#attributes' => [
      'class' => ['button', 'primary', 'radius'],
    ],
    '#states' => [
      'disabled' => [
        'input[name=add_term]' => ['filled' => FALSE],
      ],
    ],
  ];

  return $form;
}

/**
 * Save new term "category".
 */
function custom_manage_add_category_form_submit($form, &$form_state) {
  $term_name = $form_state['values']['add_term'];

  // Create new term.
  $vocabulary = taxonomy_vocabulary_machine_name_load('categories');
  $weight = count(taxonomy_get_tree($vocabulary->vid)) + 1;

  $term = new stdClass();
  $term->name = $term_name;
  $term->vid = $vocabulary->vid;
  $term->weight = $weight;
  // Save.
  taxonomy_term_save($term);
}
