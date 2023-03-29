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

$start_year = date('Y', $start_date_timestamp);
$start_day = date('j', $start_date_timestamp);
$start_month = date('F', $start_date_timestamp);
$end_year = date('Y', $end_date_timestamp);
$end_day = date('j', $end_date_timestamp);
$end_month = date('F', $end_date_timestamp);

$year_suffix = (substr($start_year, -1) == '1'
|| substr($start_year, -1) == '5'
|| substr($start_year, -2) == '10'
|| substr($start_year, -2) == '30'
|| substr($start_year, -2) == '50'
|| substr($start_year, -2) == '70'
|| substr($start_year, -2) == '90') ? '\ek\o' : 'k\o';
$day_suffix_start = (in_array(($start_day), [1, 5, 10, 30]))? '\e' : '';
$month_suffix = '\r\e\n';

$date_format_start = "y{$year_suffix} MMMM{$month_suffix} d{$day_suffix_start}";
//$date_format_start = "Y{$year_suffix} F{$month_suffix} j";

$year_suffix = (substr($end_year, -1) == '1'
|| substr($end_year, -1) == '5'
|| substr($end_year, -2) == '10'
|| substr($end_year, -2) == '30'
|| substr($end_year, -2) == '50'
|| substr($end_year, -2) == '70'
|| substr($end_year, -2) == '90') ? '\ek\o' : 'k\o';
$day_suffix_end = (in_array($end_day, [1, 5, 10, 30]))? '\e' : '';

$date_format_end = "d{$day_suffix_end}";

if($start_month != $end_month) {
  $date_format_end = "MMMM{$month_suffix} {$date_format_end}";
}
if( $start_year != $end_year ) {
  $date_format_end = "y{$year_suffix} {$date_format_end}";
}

$date_formats = [
  'es' => 'd \'de\' MMMM \'de\' y',
  'eu_start' => $date_format_start,
  'eu_end' => $date_format_end,
];

$date_format_start = isset($date_formats[$lang_code . '_start']) ? $date_formats[$lang_code . '_start'] : 'j \d\e F \d\e Y';
$date_format_end = isset($date_formats[$lang_code . '_end']) ? $date_formats[$lang_code . '_end'] : 'j \d\e F \d\e Y';

$formatted_start_date = format_localized_date(
  $start_date_timestamp,
  $date_format_start,
  $lang_code."_ES");
$formatted_end_date = format_localized_date(
  $end_date_timestamp,
  $date_format_end,
  $lang_code."_ES");

//$formatted_start_date = date($date_format_start, $start_date_timestamp);
//$formatted_end_date = date($date_format_end, $end_date_timestamp);

/* echo "PHP Start Date: " . $php_formatted_start_date . "<br>";
echo "PHP End Date: " . $php_formatted_end_date . "<br>"; */

/* $formatted_start_date = format_date(
                          $start_date_timestamp,
                          'custom',
                          $date_format_start,
                          $lang_code);
$formatted_end_date = format_date(
                          $end_date_timestamp,
                          'custom',
                          $date_format_end,
                          $lang_code); */

$formatted_start_date_lower = strtolower($formatted_start_date);
$formatted_end_date_lower = strtolower($formatted_end_date);

if ( $lang_code == "es") {
  print "Del " . $formatted_start_date_lower . " al " . $formatted_end_date_lower;
} elseif ( $lang_code == "eu") {
  print $formatted_start_date_lower . "tik " . $formatted_end_date_lower ."ra";
}
?>