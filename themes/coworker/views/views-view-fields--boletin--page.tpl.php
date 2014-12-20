<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
global $language;
if ($language->language == 'es') {
  $date_format = 'd/m/Y';
}
else {
  $date_format = 'Y/m/d';
}
$body = field_collection_item_load($row->field_field_boletin_body[0]['raw']['value']);
if (strlen($body->field_boletin_body_texto['und'][0]['value']) >= 500) {
  $pos=strpos($body->field_boletin_body_texto['und'][0]['value'], ' ', 500);
  $body_text = substr($body->field_boletin_body_texto['und'][0]['value'],0,$pos ).'...'; 
}
else {
  $body_text = $body->field_boletin_body_texto['und'][0]['value'] ; 
}
?>
<div class="row-fluid">
  <div class="span6">
    <?php print $fields['field_boletin_imagen']->content ?>
  </div>
  <div class="span6">
    <?php print $fields['title']->content ?>
    <?php print t("Posted on !date", array('!date' => format_date($fields['created']->raw, 'custom', $date_format))) ?>
    <?php print check_markup($body_text, $body->field_boletin_body_texto['und'][0]['format']) ?>
    <?php print $fields['view_node']->content ?>
  </div>
</div>
