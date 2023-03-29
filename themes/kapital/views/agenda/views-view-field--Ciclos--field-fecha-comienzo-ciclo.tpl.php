<?php
/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
?>
<?php

global $language;
$lang_code = $language->language;


$start_date_timestamp = strtotime($row->field_field_fecha_comienzo_ciclo[0]['raw']['value']);
$end_date_timestamp = strtotime($row->field_field_fecha_comienzo_ciclo[0]['raw']['value2']);

$date_formats = [
  'es' => 'j \d\e F \d\e Y',
  'eu' => 'Yk\o F(\r)\e\n j(\a)',
];
$date_format = isset($date_formats[$lang_code]) ? $date_formats[$lang_code] : 'j \d\e F \d\e Y';
$formatted_start_date = format_date($start_date_timestamp, 'custom', $date_format, $lang_code);
$formatted_end_date = format_date($end_date_timestamp, 'custom', $date_format, $lang_code);

$formatted_start_date_lower = strtolower($formatted_start_date);
$formatted_end_date_lower = strtolower($formatted_end_date);

?>
<?php
if ( $lang_code == "es") {
  print "Del " . $formatted_start_date_lower . " al " . $formatted_end_date_lower;
} elseif ( $lang_code == "eu") {
  print $formatted_start_date_lower . "(e)tik" . $formatted_end_date_lower ."(e)ra";
}
?>