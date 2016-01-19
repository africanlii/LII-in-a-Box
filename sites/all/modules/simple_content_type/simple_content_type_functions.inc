<?php

/**
 * @file simple_content_type_functions.inc
 * Supporting functions for the Simple Content Type module
 */
/**
 * Associative array of fields to add to our content type
 */
function _simple_content_type_installed_fields()  {
  $fields['simple_content_type_select'] = array(
    'field_name' => 'simple_content_type_select',
    'label' => t('Select an option from the list'),
    'type' => 'list_integer',
    'cardinality' => '1', // change this to -1 to enable ctrl+select
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'module' => 'list',
    'settings' => array(
      'allowed_values_function' => '_simple_content_type_options_list',
    ),
  );
  
  
  return $fields;
}
/**
 * Associative array of instance settings for our fields
 */
function _simple_content_type_installed_instances()  {
  // select widget
  $instances['simple_content_type_select'] = array(
    'field_name' => 'simple_content_type_select',
    'label' => t('You Selected'),
    'description' => t('Select an option from the list.'),
    'default_value' => NULL,	// add a default value here that matches your key => index values
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => -1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -1,
      ),
    ),
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => '-1',
    ),
  );
  
  return $instances;
}
/**
 * Options callback for simple_content_type_checkboxes field
 * @return - returns an indexed array as integer => string
 */
function _simple_content_type_options_list()  {
  $options = array(
    1 => 'Option A',
    2 => 'Option 2',
    3 => 'Option C',
    4 => 'Option 4',
    5 => 'Option E',
    6 => 'Option 6',
  );
  return $options;
}
