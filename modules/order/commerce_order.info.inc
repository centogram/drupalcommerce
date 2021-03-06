<?php
// $Id$

/**
 * @file
 * Provides metadata for the order entity.
 */

/**
 * Implements hook_entity_property_info().
 */
function commerce_order_entity_property_info() {
  $info = array();

  // Add meta-data about the basic commerce_order properties.
  $properties = &$info['commerce_order']['properties'];

  $properties['order-id'] = array(
    'label' => t('Order ID'),
    'description' => t('The internal numeric ID of the order.'),
    'type' => 'integer',
  );
  $properties['order-number'] = array(
    'label' => t('Order number'),
    'description' => t('The order number displayed to the customer.'),
    'type' => 'text',
    'setter callback' => 'entity_metadata_verbatim_set',
    'required' => TRUE,
    'query callback' => 'entity_metadata_table_query',
  );
  $properties['view-url'] = array(
    'label' => t('View URL'),
    'description' => t('The URL a customer can visit to view the order.'),
    'getter callback' => 'commerce_order_get_properties',
    'type' => 'uri',
  );
  $properties['admin-url'] = array(
    'label' => t('Admin URL'),
    'description' => t("The URL of the order's administrative view page."),
    'getter callback' => 'commerce_order_get_properties',
    'type' => 'uri',
  );
  $properties['edit-url'] = array(
    'label' => t('Edit URL'),
    'description' => t("The URL of the order's edit page."),
    'getter callback' => 'commerce_order_get_properties',
    'type' => 'uri',
  );
  $properties['created'] = array(
    'label' => t('Date created'),
    'description' => t('The date the order was created.'),
    'type' => 'date',
    'setter callback' => 'entity_metadata_verbatim_set',
    'query callback' => 'entity_metadata_table_query',
    'setter permission' => 'administer orders',
  );
  $properties['creator_uid'] = array(
    'label' => t("Creator ID"),
    'type' => 'integer',
    'description' => t("The unique ID of the order creator."),
    'setter callback' => 'entity_metadata_verbatim_set',
    'setter permission' => 'administer orders',
    'clear' => array('creator'),
    'query callback' => 'entity_metadata_table_query',
  );
  $properties['creator'] = array(
    'label' => t("Creator"),
    'type' => 'user',
    'description' => t("The creator of the order."),
    'getter callback' => 'commerce_order_get_properties',
    'setter callback' => 'commerce_order_set_properties',
    'setter permission' => 'administer orders',
    'required' => TRUE,
    'clear' => array('creator_uid'),
  );
  $properties['customer_uid'] = array(
    'label' => t("Customer ID"),
    'type' => 'integer',
    'description' => t("The unique ID of the order customer."),
    'setter callback' => 'entity_metadata_verbatim_set',
    'setter permission' => 'administer orders',
    'clear' => array('customer'),
    'query callback' => 'entity_metadata_table_query',
  );
  $properties['customer'] = array(
    'label' => t("Customer"),
    'type' => 'user',
    'description' => t("The customer of the order."),
    'getter callback' => 'commerce_order_get_properties',
    'setter callback' => 'commerce_order_set_properties',
    'setter permission' => 'administer orders',
    'required' => TRUE,
    'clear' => array('customer_uid'),
  );

  return $info;
}
