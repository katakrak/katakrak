<?php
/**
 * @file
 * katakrak_commerce.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function katakrak_commerce_default_rules_configuration() {
  $items = array();
  $items['rules_pedido_procesado'] = entity_import('rules_config', '{ "rules_pedido_procesado" : {
      "LABEL" : "El pedido ha sido procesado",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "entity" ],
      "ON" : { "commerce_order_update" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "commerce-order-unchanged:status" ], "value" : "pending" } },
        { "data_is" : { "data" : [ "commerce-order:status" ], "value" : "processing" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "commerce-order:mail" ],
            "subject" : "Su pedido ha sido procesado",
            "message" : "Su pedido ha sido procesado",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
