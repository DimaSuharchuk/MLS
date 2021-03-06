<?php
/**
 * @file
 * Offer content type custom functionality.
 */

/**
 * Offer view.
 */
function custom_offer_view($node = NULL) {
  $page = [];

  // Just show the node.
  $page['content'] = node_view($node);

  return $page;
}

/**
 * Add/edit Offer custom page.
 */
function custom_offer_form($form, &$form_state, $node = NULL) {
  // Taxonomy term id used as destination for redirect.
  $tid = isset($_GET['tid']) ? $_GET['tid'] : FALSE;
  if ($tid) {
    ctools_include('object-cache');
    ctools_object_cache_set('tid', 'offer_redirect', $tid);
  }

  // Create node object if not node loaded.
  if (!$node) {
    $node = entity_create('node', ['type' => 'offer']);
  }
  // Attach fields from node "Offer".
  field_attach_form('node', $node, $form, $form_state);

  // I don't want load properties from node and just create custom offer title
  // field.
  $form['title'] = [
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#required' => TRUE,
    '#default_value' => isset($node->title) ? $node->title : '',
  ];
  // To simplify the work of the content moderator we set category from path.
  $form['field_category'][LANGUAGE_NONE]['#default_value'] = $tid;
  // Hide unnecessary text format selector.
  $form['body'][LANGUAGE_NONE][0]['#after_build'][] = 'custom_hide_text_format_selector';

  // Translate fields title.
  $form['body'][LANGUAGE_NONE][0]['#title'] = t($form['body'][LANGUAGE_NONE][0]['#title']);
  $form['field_pictures'][LANGUAGE_NONE]['#title'] = t($form['field_pictures'][LANGUAGE_NONE]['#title']);
  $form['field_category'][LANGUAGE_NONE]['#title'] = t($form['field_category'][LANGUAGE_NONE]['#title']);

  $form['actions'] = [
    '#type' => 'actions',
  ];
  $form['actions']['submit'] = [
    '#type' => 'submit',
    '#value' => t('Save'),
    '#attributes' => [
      'class' => ['button', 'success', 'radius'],
    ],
  ];
  $form['actions']['cancel'] = [
    '#type' => 'link',
    '#title' => t('Cancel'),
    '#href' => $tid ? "taxonomy/term/$tid" : '<front>',
    '#attributes' => [
      'class' => ['button', 'secondary', 'radius'],
    ],
  ];

  $form['node'] = [
    '#type' => 'value',
    '#value' => $node,
  ];

  $form['#attributes'] = [
    'class' => ['custom-offer-form'],
  ];

  return $form;
}

/**
 * Form validate.
 */
function custom_offer_form_validate($form, &$form_state) {
  field_attach_form_validate('node', $form_state['values']['node'], $form, $form_state);
}

/**
 * Save node.
 */
function custom_offer_form_submit($form, &$form_state) {
  $node = &$form_state['values']['node'];
  $node->title = $form_state['values']['title'];
  field_attach_submit('node', $node, $form, $form_state);
  // Set author to node.
  if (!isset($node->uid)) {
    global $user;
    $node->uid = $user->uid;
  }

  try {
    node_save($node);
  } catch (Exception $e) {
    watchdog('save offer', $e->getMessage());
    drupal_set_message(t('Offer saving failed.'), 'error');
  }

  // Redirect back to taxonomy term page.
  ctools_include('object-cache');
  $tid = ctools_object_cache_get('tid', 'offer_redirect');
  ctools_object_cache_clear('tid', 'offer_redirect');
  $form_state['redirect'] = $tid ? "taxonomy/term/$tid" : '<front>';
}

/**
 * Offer delete confirmation form.
 */
function custom_offer_delete_form($form, &$form_state, $node) {
  $tid = isset($_GET['tid']) ? $_GET['tid'] : FALSE;

  $form['node'] = [
    '#type' => 'value',
    '#value' => $node,
  ];
  $form['tid'] = [
    '#type' => 'value',
    '#value' => $tid,
  ];

  return confirm_form(
    $form,
    t('Are you sure you want to delete %title?', ['%title' => $node->title]),
    "taxonomy/term/$tid",
    '<h4 class="description">' . t('This action cannot be undone.') . '</h4>',
    t('Delete'),
    t('Back')
  );
}

/**
 * Finally remove the offer.
 */
function custom_offer_delete_form_submit($form, &$form_state) {
  node_delete($form_state['values']['node']->nid);

  $form_state['redirect'] = 'taxonomy/term/' . $form_state['values']['tid'];
}
