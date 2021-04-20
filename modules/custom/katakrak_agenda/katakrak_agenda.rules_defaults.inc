<?php

/**
 * @file
 * katakrak_agenda.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function katakrak_agenda_default_rules_configuration() {
  $items = array();
  $items['rules_envio_del_formulario_organizar_acto'] = entity_import('rules_config', '{ "rules_envio_del_formulario_organizar_acto" : {
      "LABEL" : "Envio del formulario organizar acto",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "mimemail" ],
      "USES VARIABLES" : {
        "nombre" : { "label" : "Nombre y apellidos", "type" : "text" },
        "email" : { "label" : "Email", "type" : "text" },
        "telefono" : { "label" : "Tel\\u00e9fono", "type" : "text" },
        "fecha" : { "label" : "Fecha", "type" : "text" },
        "sala" : { "label" : "Sala", "type" : "text" },
        "detalles" : { "label" : "Detalles", "type" : "text" }
      },
      "ACTION SET" : [
        { "mimemail" : {
            "USING" : {
              "key" : "email_organiza_acto_agenda",
              "to" : "agenda@katakrak.net",
              "from_name" : "Katakrak WEB",
              "from_mail" : "info@katakrak.net",
              "subject" : "Una nueva solicitud de uso de la sala",
              "body" : "Han enviado una solicitud de uso de la sala, he aqu\\u00ed los datos\\r\\n\\r\\nNombre: [nombre:value]\\r\\n\\r\\nEmail: [email:value]\\r\\n\\r\\nTel\\u00e9fono: [telefono:value]\\r\\n\\r\\nFecha: [fecha:value]\\r\\n\\r\\nSala: [sala:value]\\r\\n\\r\\nDetalles adicionales: [detalles:value]",
              "language" : [ "" ]
            },
            "PROVIDE" : { "send_status" : { "send_status" : "Send status" } }
          }
        }
      ]
    }
  }');
  return $items;
}
