<?php

/**
 * @file
 * katakrak.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function katakrak_default_rules_configuration() {
  $items = array();
  $items['rules_apply_bibliotecas_discount'] = entity_import('rules_config', '{ "rules_apply_bibliotecas_discount" : {
      "LABEL" : "apply bibliotecas discount",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_discount", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "IF" : [
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "8" : "8" } }
          }
        }
      ],
      "DO" : [
        { "commerce_discount_percentage" : {
            "entity" : [ "commerce-line-item" ],
            "commerce_discount" : "discount_descuento_biblioteca"
          }
        }
      ]
    }
  }');
  return $items;
}
