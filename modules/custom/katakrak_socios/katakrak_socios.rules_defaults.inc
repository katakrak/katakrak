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
        "direccion" : { "label" : "Direcci\\u00f3n", "type" : "text" },
        "fraccionado" : { "label" : "Fraccionado", "type" : "text" }
      },
      "ACTION SET" : [
        { "drupal_message" : { "message" : "Mila esker zure ekarpenagatik. Laster jasoko duzu email bat.\\r\\nMuchas gracias por tu aportaci\\u00f3n. Recibir\\u00e1s un email con m\\u00e1s informaci\\u00f3n." } },
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
              "subject" : "Mila esker | Muchas gracias",
              "body" : "\\r\\n[EUS]\\r\\nEsker mila Katakrakeko bazkide egiteagatik. Mezu honek ez du transakzio bat bukatutzat eman nahi. Ez da \\u201cEskerrik asko etortzeagatik\\u201d ezpainzapia. Alderantziz, gonbidapen-txartela da.\\r\\nBeharraren eta desioaren bultzada bikoitzarekin jarri genuen martxan kanpaina hau. Laguntza ekonomikoa behar genuen, eta, aldi berean, lehen egunetik ezinbestekoa izan den proiektuan laguntzeko eta parte hartzeko sarea indartu nahi genuen. Komunitatea deritzogun hori.\\r\\n\\r\\nNormaltasun berri bat nahi dugu, non zainketak oinarrizko lan gisa onartuko diren, alkatea ez den UPNkoa izanen, Arga beti garbi etorriko den, alokairuak merkeak izanen diren, nobelak irakurtzeko denbora izanen dugun, osasun publikoak behar adina baliabide izanen dituen, bizikleta  nagusi izanen den eta, azken finean, non bizitzeak mereziko duen. Katakrak-ek zentzua du hiria harantz bultzatzen ahalbidetzen digun bitartean. Zurekin bai.\\r\\n\\r\\n\\u0022Eta hau bukaera ez bada,\\r\\namaiera bat ez bada hau, orduan\\r\\nlehertuko den bonba da.\\r\\nBonba bat da eta lehertuko da.\\u0022\\r\\nFundaci\\u00f3n Robo,\\r\\n\\u201cC\\u00f3mo hacer crac\\u201d (2011)\\r\\n\\r\\n[CAS]\\r\\nGracias por hacerte socix de Katakrak. Este mensaje no pretende dar por\\r\\nconcluida una transacci\\u00f3n. No es una servilleta de \\u201cGracias por su\\r\\nvisita\\u201d. Todo lo contrario, es m\\u00e1s bien una tarjeta de invitaci\\u00f3n.\\r\\nPusimos en marcha esta campa\\u00f1a con el doble impulso de la necesidad y el\\r\\ndeseo. Nos hac\\u00eda falta el apoyo econ\\u00f3mico y a la vez quer\\u00edamos\\r\\nfortalecer una red de soporte y participaci\\u00f3n en el proyecto que ha sido\\r\\nimprescindible desde el primer d\\u00eda. Eso que llamamos comunidad.\\r\\n\\r\\nDeseamos una nueva normalidad en la que los cuidados se reconozcan como\\r\\ntrabajos esenciales, el alcalde no sea de UPN, el Arga baje siempre\\r\\nlimpio, los alquileres est\\u00e9n baratos, tengamos tiempo para leer novelas,\\r\\nla sanidad p\\u00fablica cuente con recursos suficientes, la bici impere y, en\\r\\ndefinitiva, vivir valga la pena. Katakrak tiene sentido mientras nos\\r\\npermita empujar la ciudad hacia ah\\u00ed. Contigo s\\u00ed se puede.\\r\\n\\r\\n\\u201cY si esto no es el fin,\\r\\nsi esto no es un final, entonces\\r\\nes la bomba que va a estallar.\\r\\nEs una bomba y va a estallar.\\u201d\\r\\nFundaci\\u00f3n Robo,\\r\\n\\u201cC\\u00f3mo hacer crac\\u201d (2011)",
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
