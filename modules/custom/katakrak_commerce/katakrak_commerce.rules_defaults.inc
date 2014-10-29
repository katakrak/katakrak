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
      "REQUIRES" : [ "rules", "mimemail", "entity" ],
      "ON" : { "commerce_order_update" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "commerce-order-unchanged:status" ], "value" : "pending" } },
        { "data_is" : { "data" : [ "commerce-order:status" ], "value" : "processing" } }
      ],
      "DO" : [
        { "mimemail" : {
            "key" : "order_pending_to_processing",
            "to" : "[commerce-order:mail]",
            "from_mail" : "info@katakrak.net",
            "subject" : "Su pedido se est\\u00e1 procesando",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
