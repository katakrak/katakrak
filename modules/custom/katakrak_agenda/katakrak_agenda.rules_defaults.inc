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
      "USES VARIABLES" : {
        "nombre" : { "label" : "Nombre y apellidos", "type" : "text" },
        "email" : { "label" : "Email", "type" : "text" },
        "telefono" : { "label" : "Tel\\u00e9fono", "type" : "text" },
        "fecha" : { "label" : "Fecha", "type" : "text" },
        "sala" : { "label" : "Sala", "type" : "text" },
        "detalles" : { "label" : "Detalles", "type" : "text" }
      },
      "ACTION SET" : []
    }
  }');
  return $items;
}
