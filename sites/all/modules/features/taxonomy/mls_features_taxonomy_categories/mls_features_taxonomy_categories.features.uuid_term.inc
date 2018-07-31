<?php
/**
 * @file
 * mls_features_taxonomy_categories.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function mls_features_taxonomy_categories_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Район',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '0c328d64-6847-4530-bb2b-146864d55267',
    'vocabulary_machine_name' => 'categories',
  );
  $terms[] = array(
    'name' => 'Здам',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '1af74376-20f2-4d90-84c1-54341c1b62e9',
    'vocabulary_machine_name' => 'categories',
  );
  $terms[] = array(
    'name' => 'будинок / частина будинку',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '25eca780-de71-437e-909d-13bce5507251',
    'vocabulary_machine_name' => 'categories',
    'parent' => array(
      0 => 'd7fed277-aafb-42c1-b083-35e19a0aff16',
    ),
  );
  $terms[] = array(
    'name' => 'будинок / частина будинку',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '40fdbb5e-fcb0-4124-a253-a0d577381d58',
    'vocabulary_machine_name' => 'categories',
    'parent' => array(
      0 => 'a3aa4897-6ee8-4f9a-bb1b-fb81e6a45759',
    ),
  );
  $terms[] = array(
    'name' => 'Зніму',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => '625a519c-b81a-452a-a5c2-ab2577f06c3e',
    'vocabulary_machine_name' => 'categories',
  );
  $terms[] = array(
    'name' => '1 кімната',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '6add5802-2d3d-4cfc-af1a-ea09d9a0e492',
    'vocabulary_machine_name' => 'categories',
    'path' => array(
      'pathauto' => 1,
    ),
    'parent' => array(
      0 => 'a3aa4897-6ee8-4f9a-bb1b-fb81e6a45759',
    ),
  );
  $terms[] = array(
    'name' => 'Різне',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 5,
    'uuid' => '9491df7b-7829-4b9d-b382-713a2fae658b',
    'vocabulary_machine_name' => 'categories',
  );
  $terms[] = array(
    'name' => 'Куплю',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a3aa4897-6ee8-4f9a-bb1b-fb81e6a45759',
    'vocabulary_machine_name' => 'categories',
  );
  $terms[] = array(
    'name' => '3-4 кімнати',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'b4647dce-6aea-4d31-9784-6d450406e8e2',
    'vocabulary_machine_name' => 'categories',
    'parent' => array(
      0 => 'a3aa4897-6ee8-4f9a-bb1b-fb81e6a45759',
    ),
  );
  $terms[] = array(
    'name' => '1 кімната',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'c21c494d-09c8-418e-a1a5-db7a54c1b2eb',
    'vocabulary_machine_name' => 'categories',
    'parent' => array(
      0 => 'd7fed277-aafb-42c1-b083-35e19a0aff16',
    ),
  );
  $terms[] = array(
    'name' => '3-4 кімнати',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'c37bba6d-3974-4032-8131-109c92e16a76',
    'vocabulary_machine_name' => 'categories',
    'parent' => array(
      0 => 'd7fed277-aafb-42c1-b083-35e19a0aff16',
    ),
  );
  $terms[] = array(
    'name' => '2 кімнати',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => 'c4da862b-e718-422c-9418-a3912b9fb24e',
    'vocabulary_machine_name' => 'categories',
    'parent' => array(
      0 => 'a3aa4897-6ee8-4f9a-bb1b-fb81e6a45759',
    ),
  );
  $terms[] = array(
    'name' => 'Продам',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => 'd7fed277-aafb-42c1-b083-35e19a0aff16',
    'vocabulary_machine_name' => 'categories',
  );
  $terms[] = array(
    'name' => '2 кімнати',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => 'd9a62a21-67e6-46df-aa57-bea3f15d2190',
    'vocabulary_machine_name' => 'categories',
    'parent' => array(
      0 => 'd7fed277-aafb-42c1-b083-35e19a0aff16',
    ),
  );
  return $terms;
}
