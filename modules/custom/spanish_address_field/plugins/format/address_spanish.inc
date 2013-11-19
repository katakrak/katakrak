<?php

/**
 * @file
 * A specific handler for ES.
 */

$plugin = array(
  'title' => t('Address form (ES add-on)'),
  'format callback' => 'addressfield_format_address_spain_generate',
  'type' => 'address',
  'weight' => -80,
);

function addressfield_format_address_spain_generate(&$format, $address, $context = array()) {
  if ($address['country'] == 'ES') {
    if (isset($format['locality_block']['administrative_area'])) {
      $state_options = array(
        ''   => t('--'),
        'C'  => t('A Coruña'),
        'VI' => t('Álava'),
        'AB' => t('Albacete'),
        'A'  => t('Alicante'),
        'AL' => t('Almería'),
        'O'  => t('Asturias'),
        'AV' => t('Ávila'),
        'BA' => t('Badajoz'),
        'PM' => t('Baleares'),
        'B'  => t('Barcelona'),
        'BU' => t('Burgos'),
        'CC' => t('Cáceres'),
        'CA' => t('Cádiz'),
        'S'  => t('Cantabria'),
        'CS' => t('Castellón'),
        'CE' => t('Ceuta'),
        'CR' => t('Ciudad Real'),
        'CO' => t('Córdoba'),
        'CU' => t('Cuenca'),
        'GI' => t('Girona'),
        'GR' => t('Granada'),
        'GU' => t('Guadalajara'),
        'SS' => t('Guipúzcoa'),
        'H'  => t('Huelva'),
        'HU' => t('Huesca'),
        'J'  => t('Jaén'),
        'LO' => t('La Rioja'),
        'GC' => t('Las Palmas'),
        'LE' => t('León'),
        'L'  => t('Lleida'),
        'LU' => t('Lugo'),
        'M'  => t('Madrid'),
        'MA' => t('Málaga'),
        'ML' => t('Melilla'),
        'MU' => t('Murcia'),
        'NA' => t('Navarra'),
        'OR' => t('Ourense'),
        'P'  => t('Palencia'),
        'PO' => t('Pontevedra'),
        'SA' => t('Salamanca'),
        'SF' => t('Santa Cruz de Tenerife'),
        'SG' => t('Segovia'),
        'SE' => t('Sevilla'),
        'SO' => t('Soria'),
        'T'  => t('Tarragona'),
        'TE' => t('Teruel'),
        'TO' => t('Toledo'),
        'V'  => t('Valencia'),
        'VA' => t('Valladolid'),
        'BI' => t('Vizcaya'),
        'ZA' => t('Zamora'),
        'Z'  => t('Zaragoza'),
      );

      if (!empty($format['locality_block']['administrative_area']['#options'])) {
        $state_options += $format['locality_block']['administrative_area']['#options'];
      }

      $format['locality_block']['administrative_area']['#title'] = t('Province');
      $format['locality_block']['administrative_area']['#options'] = $state_options;
    }
  }
}
