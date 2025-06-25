<?php

/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct URL of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type; for example, "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type; for example, story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode; for example, "full", "teaser".
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined; for example, $node->body becomes $body. When needing to
 * access a field's raw values, developers/themers are strongly encouraged to
 * use these variables. Otherwise they will have to explicitly specify the
 * desired field language; for example, $node->body['en'], thus overriding any
 * language negotiation rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 *
 * @ingroup templates
 */

global $language;
$idioma = $language->language;
$idioma_index = $idioma == 'es'? 0 : 1;
$alergenos = variable_get('alergenos');
?>
<ul class="nav nav-secondary hidden-xs">
  <?php foreach($node->field_menu_tipo_menu['und'] as $i => $tab): ?>
  <?php if ($tab['field_collection']->field_menu_pest_activo['und'][0]['value']): ?>
    <li class="<?php print $i == 0 ? 'active': '' ?>">
      <a href="#<?php print slugify($tab['field_collection']->field_menu_tipo_titulo['und'][$idioma_index]['value']) ?>" aria-controls="home" role="tab" data-toggle="tab"><?php print $tab['field_collection']->field_menu_tipo_titulo['und'][$idioma_index]['value'] ?></a>
      </li>
      <?php endif; ?>
  <?php endforeach; ?>
</ul>


 
<select class="form-control tabs visible-xs-block">
  <?php foreach($node->field_menu_tipo_menu['und'] as $tab): ?>
  
  <option value="<?php print slugify($tab['field_collection']->field_menu_tipo_titulo['und'][$idioma_index]['value'])?>"><?php print $tab['field_collection']->field_menu_tipo_titulo['und'][$idioma_index]['value'] ?></option>
<?php endforeach; ?>
</select>

<div class="row">
  <div class="col-sm-12">
      
    
    <div class="tab-content mb-2">
    <?php foreach($node->field_menu_tipo_menu['und'] as $i => $tab): ?>
      
      <?php if ($tab['field_collection']->field_menu_pest_activo['und'][0]['value']): ?>
      <div role="tabpanel" class="tab-pane <?php print $i == 0 ? 'active' : '' ?>" id="<?php print slugify($tab['field_collection']->field_menu_tipo_titulo['und'][$idioma_index]['value']) ?>">
        
        <?php if ($tab['field_collection']->field_menu_tipo_descripcion['und'][0]['value']): ?>
        <div class="alert alert-primary mt-2 text-center" role="alert">
          
          
          <?php print $tab['field_collection']->field_menu_tipo_descripcion['und'][$idioma_index]['value'] ?>
        </div>
        <?php endif; ?>
       <?php print theme_image(array('path' => $tab['field_collection']->field_imagen['und'][0]['uri'], 'attributes' => array('class' => 'img-responsive'))); ?>	   
      </div>
      <?php endif; ?>
    <?php  endforeach; ?>
         </div>
  </div>
  
  <!--<p><?php print t('*Información sobre alérgenos') ?>
  <ul>
    <li>L = <?php print t('Lacteos') ?></li>
    <li>G = <?php print t('Cereales con gluten') ?></li>
    <li>H = <?php print t('Huevos') ?>Huevos</li>
    <li>P = <?php print t('Pescado') ?></li>
    <li>M = <?php print t('Molúscos') ?></li>
    <li>CR = <?php print t('Crustáceos') ?></li>
    <li>C = <?php print t('Cacahuetes') ?></li>
    <li>F = <?php print t('Frutos secos') ?></li>
    <li>S = <?php print t('Soja') ?></li>
    <li>A = <?php print t('Apio') ?></li>
    <li>M = <?php print t('Mostaza') ?></li>
    <li>S = <?php print t('Sésamo') ?></li>
    <li>A = <?php print t('Altramuz') ?></li>
    <li>SU = <?php print t('Sulfitos') ?></li>
  </ul>-->

                        













  </p>
</div><!-- /.row-->
