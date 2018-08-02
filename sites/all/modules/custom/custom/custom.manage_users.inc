<?php
/**
 * @file
 * Manage accounts functionality.
 */

/**
 * Manage users page.
 *
 * @throws \Exception
 */
function custom_manage_users_page() {
  $page = [];

  $page['add_wrapper'] = [
    '#type' => 'container',
    '#attributes' => [
      'class' => ['create-account'],
    ],
  ];
  $page['add_wrapper']['add'] = [
    '#type' => 'link',
    '#title' => t('Create account'),
    '#href' => 'admin-menu/manage-users/add',
  ];

  // Define table header with sorts.
  $header = [
    'username' => ['data' => t('Login'), 'field' => 'u.name'],
    'status' => ['data' => t('Status'), 'field' => 'u.status'],
    'role' => ['data' => t('Role')],
    'member_for' => [
      'data' => t('Member for'),
      'field' => 'u.created',
      'sort' => 'desc',
    ],
    'access' => ['data' => t('Last access'), 'field' => 'u.access'],
    'operations' => ['data' => t('Operations')],
  ];

  // Get all users except anonymous and admin (uid 1). Prepare table's header sorts.
  $query = db_select('users', 'u');
  $query->condition('u.uid', [0, 1], 'not in');
  user_build_filter_query($query);

  $count_query = clone $query;
  $count_query->addExpression('COUNT(u.uid)');

  $query = $query->extend('PagerDefault')->extend('TableSort');
  $query
    ->fields('u', ['uid', 'name', 'status', 'created', 'access'])
    ->orderByHeader($header)
    ->setCountQuery($count_query);
  $result = $query->execute();

  // Statuses names.
  $status = [t('blocked'), t('active')];
  // Get all roles.
  $roles = array_map('check_plain', user_roles(TRUE));
  // Build table rows.
  $rows = [];
  foreach ($result as $account) {
    // Get current account role id.
    $user_rid = db_select('users_roles', 'r')
      ->fields('r', ['rid'])
      ->condition('uid', $account->uid)
      ->execute()
      ->fetchField();

    $rows[$account->uid] = [
      'username' => theme('username', ['account' => $account]),
      'status' => $status[$account->status],
      'role' => $roles[$user_rid],
      'member_for' => format_interval(REQUEST_TIME - $account->created),
      'access' => $account->access ? t('@time ago', ['@time' => format_interval(REQUEST_TIME - $account->access)]) : t('never'),
      'operations' => [
        'data' => [
          '#type' => 'link',
          '#title' => t('Actions'),
          '#href' => "admin-menu/manage-users/$account->uid",
        ],
      ],
    ];

    // Set field labels to "table td" for mobile.
    foreach ($rows[$account->uid] as $field => $row) {
      if ($field !== 'operations') {
        $rows[$account->uid][$field] = '<span class="mobile-label">' . $header[$field]['data'] . ': </span>' . $row;
      }
    }
  }

  $page['table'] = [
    '#markup' => theme('table', [
      'caption' => t('Users'),
      'header' => $header,
      'rows' => $rows,
      'attributes' => [
        'class' => ['manage-accounts-table'],
      ],
    ]),
  ];

  return $page;
}

/**
 * Create account form.
 */
function custom_add_user_form($form, &$form_state) {
  $form['name'] = [
    '#type' => 'textfield',
    '#title' => t('Login'),
    '#required' => TRUE,
    '#attributes' => [
      'autocomplete' => 'off',
    ],
  ];
  $form['password'] = [
    '#type' => 'textfield',
    '#title' => t('Password'),
    '#required' => TRUE,
    '#attributes' => [
      'autocomplete' => 'off',
    ],
  ];

  $roles = user_roles(TRUE);
  // Remove unnecessary role.
  unset($roles[array_search(t('authenticated user'), $roles)]);

  $form['role'] = [
    '#type' => 'radios',
    '#title' => t('Role'),
    '#options' => $roles,
    '#default_value' => array_search(USER_ROLE_MODERATOR, $roles),
  ];

  $form['submit'] = [
    '#type' => 'submit',
    '#value' => t('Create account'),
  ];
  $form['cancel'] = [
    '#type' => 'link',
    '#title' => t('Back'),
    '#href' => 'admin-menu/manage-users',
    '#attributes' => [
      'class' => ['button', 'secondary', 'radius'],
    ],
  ];

  return $form;
}

/**
 * Create account validation.
 */
function custom_add_user_form_validate($form, &$form_state) {
  if ($error = user_validate_name($form_state['values']['name'])) {
    form_set_error('name', $error);
  }
  elseif ((bool) db_select('users')
    ->fields('users', ['uid'])
    ->condition('name', db_like($form_state['values']['name']), 'LIKE')
    ->range(0, 1)
    ->execute()
    ->fetchField()) {
    form_set_error('name', t('The name %name is already taken.', ['%name' => $form_state['values']['name']]));
  }
}

/**
 * Create account.
 *
 * @throws \Exception
 */
function custom_add_user_form_submit($form, &$form_state) {
  $name = $form_state['values']['name'];
  $pass = trim($form_state['values']['password']);

  $account = new stdClass;
  $account->is_new = TRUE;
  $account->name = $name;
  // Hash password before saving.
  require_once DRUPAL_ROOT . '/' . variable_get('password_inc', 'includes/password.inc');
  $account->pass = user_hash_password($pass);
  // Generate dummy emails until mail sending not used.
  $account->mail = user_password() . '@user.com';
  $account->status = TRUE;
  $account->roles = [
    DRUPAL_AUTHENTICATED_RID => TRUE,
    $form_state['values']['role'] => TRUE,
  ];

  user_save($account);

  drupal_set_message(t('Account with login "@name" and password "@pass" successfully created.', [
    '@name' => $name,
    '@pass' => $pass,
  ]));
}

/**
 * Page for edit, block-unblock and delete account.
 *
 * @param $account
 *  Already loaded user entity.
 *
 * @return mixed
 */
function custom_manage_user_form($form, &$form_state, $account) {
  global $user;

  // Check if MLS Administrator (not uid 1) editing himself now.
  $edit_himself = $account->uid === $user->uid;

  $form['account'] = [
    '#type' => 'value',
    '#value' => $account,
  ];
  $form['name'] = [
    '#type' => 'textfield',
    '#title' => t('New login'),
    '#attributes' => [
      'autocomplete' => 'off',
    ],
    '#default_value' => $account->name,
  ];
  $form['password'] = [
    '#type' => 'textfield',
    '#title' => t('New password'),
  ];

  $roles = user_roles(TRUE);
  // Remove unnecessary role.
  unset($roles[array_search(t('authenticated user'), $roles)]);
  // Get account role id except "authenticated user" role id.
  $account_rid = array_keys($account->roles)[1];

  $form['role'] = [
    '#type' => 'radios',
    '#title' => t('Role'),
    '#options' => $roles,
    '#default_value' => $account_rid,
    '#disabled' => $edit_himself,
  ];

  $form['actions'] = [
    '#type' => 'actions',
    '#attributes' => [
      'class' => ['manage-user-actions'],
    ],
  ];
  $form['actions']['save'] = [
    '#type' => 'submit',
    '#value' => t('Save'),
    '#name' => 'save',
    '#attributes' => [
      'class' => ['button', 'success', 'radius'],
    ],
  ];
  if ($account->status) {
    $form['actions']['block'] = [
      '#type' => 'submit',
      '#value' => t('Block'),
      '#name' => 'block',
      '#attributes' => [
        'class' => ['button', 'warning', 'radius'],
      ],
      '#disabled' => $edit_himself,
    ];
  }
  else {
    $form['actions']['unblock'] = [
      '#type' => 'submit',
      '#value' => t('Unblock'),
      '#name' => 'unblock',
      '#attributes' => [
        'class' => ['button', 'primary', 'radius'],
      ],
    ];
  }
  $form['actions']['delete'] = [
    '#type' => 'submit',
    '#value' => t('Delete'),
    '#name' => 'delete',
    '#attributes' => [
      'class' => ['button', 'alert', 'radius'],
    ],
    '#disabled' => $edit_himself,
  ];
  $form['actions']['cancel'] = [
    '#type' => 'link',
    '#title' => t('Back'),
    '#href' => 'admin-menu/manage-users',
    '#attributes' => [
      'class' => ['button', 'secondary', 'radius'],
    ],
  ];

  return $form;
}

/**
 * Update account validation.
 */
function custom_manage_user_form_validate($form, &$form_state) {
  // Check for available new user name before saving.
  if ($form_state['triggering_element']['#name'] === 'save') {
    $new_name = $form_state['values']['name'];
    if ($form_state['values']['account']->name !== $new_name) {
      if ((bool) db_select('users')
        ->fields('users', ['uid'])
        ->condition('name', db_like($new_name), 'LIKE')
        ->range(0, 1)
        ->execute()
        ->fetchField()) {
        form_set_error('name', t('The name %name is already taken.', ['%name' => $new_name]));
      }
    }
  }
}

/**
 * Actions for manage user form.
 *
 * @throws \Exception
 */
function custom_manage_user_form_submit($form, &$form_state) {
  $account = $form_state['values']['account'];
  $edit = [];

  switch ($form_state['triggering_element']['#name']) {
    case 'save':
      // Set account login.
      $edit['name'] = $form_state['values']['name'];
      // Change password if filled.
      if (!empty($form_state['values']['password'])) {
        $edit['pass'] = $form_state['values']['password'];
        drupal_set_message(t('Password successfully changed. Enter new password for next authorization.'), 'status');
      }
      // Set role.
      $account->roles = [
        DRUPAL_AUTHENTICATED_RID => TRUE,
        $form_state['values']['role'] => TRUE,
      ];
      drupal_set_message(t('Account "@name" successfully updated.', [
        '@name' => $form_state['values']['name'],
      ]));
      break;

    case 'block':
      $edit['status'] = FALSE;
      break;

    case 'unblock':
      $edit['status'] = TRUE;
      break;

    case 'delete':
      user_delete($account->uid);
      drupal_goto('admin-menu/manage-users');
      break;
  }

  user_save($account, $edit);
}
