<?php

/**
 * @file
 * katakrak_socios.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function katakrak_socios_default_rules_configuration() {
  $items = array();
  $items['rules_email_alta_socios'] = entity_import('rules_config', '{ "rules_email_alta_socios" : {
      "LABEL" : "Email alta socios",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "mimemail" ],
      "USES VARIABLES" : {
        "nombre" : { "label" : "Nombre", "type" : "text" },
        "apellidos" : { "label" : "Apellidos", "type" : "text" },
        "email" : { "label" : "Email", "type" : "text" },
        "iban" : { "label" : "Iban", "type" : "text" },
        "cantidad" : { "label" : "Cantidad", "type" : "integer" },
        "direccion" : { "label" : "Direcci\\u00f3n", "type" : "text" }
      },
      "ACTION SET" : [
        { "drupal_message" : { "message" : "Gracias por tu aportacionkdfladj\\u00f1sfkl\\u00f1a" } },
        { "mimemail" : {
            "USING" : {
              "key" : "socios_email_alta",
              "to" : "socixs@katakrak.net",
              "from_name" : "Katakrak",
              "from_mail" : "info@katakrak.net",
              "subject" : "Nuevo socixs",
              "body" : "Nombre: [nombre:value]\\r\\nApellidos: [apellidos:value]\\r\\nE-mail: [email:value]\\r\\nIban: [iban:value]\\r\\nCantidad: [cantidad:value]\\r\\nDireccion: [direccion:value]",
              "language" : [ "" ]
            },
            "PROVIDE" : { "send_status" : { "send_status" : "Send status" } }
          }
        },
        { "mimemail" : {
            "USING" : {
              "key" : "socios_email_alta_para_socio",
              "to" : "[email:value]",
              "subject" : "nlad\\u00f1fj\\u00f1l",
              "language" : [ "" ]
            },
            "PROVIDE" : { "send_status" : { "send_status1" : "Send status" } }
          }
        }
      ]
    }
  }');
  return $items;
}
