<?php
// $Id$

/**
 * Field handler to translate an order status into its readable form.
 */
class views_handler_field_commerce_order_status extends views_handler_field_commerce_order {
  function render($values) {
    $value = commerce_order_status_get_title($values->{$this->field_alias});

    return $this->render_link((check_plain($value)), $values);
  }
}
