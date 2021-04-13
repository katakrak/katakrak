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
?>
<ul class="nav nav-secondary hidden-xs">
  <?php foreach($node->field_menu_tipo_menu['und'] as $tab): ?>
  
    <li>
      <a href="#<?php print slugify($tab['field_collection']->field_menu_tipo_titulo['und'][0]['value']) ?>" aria-controls="home" role="tab" data-toggle="tab"><?php print t($tab['field_collection']->field_menu_tipo_titulo['und'][0]['value']) ?></a>
      </li>
  <?php endforeach; ?>
</ul>




<select class="form-control visible-xs-block">
  <?php foreach($node->field_menu_tipo_menu['und'] as $tab): ?>
    <option><?php print t($tab['field_collection']->field_menu_tipo_titulo['und'][0]['value'])?></option>
<?php endforeach; ?>
</select>

<div class="row">
  <div class="col-sm-12">
    <div class="tab-content mb-2">
    <?php foreach($node->field_menu_tipo_menu['und'] as $i => $tab): ?>
      <?php //dpm($tab) ?>
      <div role="tabpanel" class="tab-pane <?php print $i == 0 ? 'active' : '' ?>" id="<?php print slugify($tab['field_collection']->field_menu_tipo_titulo['und'][0]['value']) ?>">
        <!-- <h3 class="text-center">Menú del día</h3>
        <p class="text-center">Menús variados con productos de temporada y equilibrados</p> -->
        
        <?php foreach ($tab['field_collection']->field_menu_categoria['und'] as $categoria): ?>
        <?php //dpm($categoria) ?>
        
        <div class="row mt-4">
          <div class="col-sm-5 mb-1">
            <div id="carousel-entrantes" class="carousel slide" data-ride="carousel">
              <!-- Indicators -->
              <ol class="carousel-indicators">
                <?php foreach ($categoria['field_collection']->field_menu_platos['und'] as $i => $plato): ?>
                <?php $plato = $plato['node']?>
                <?php if ($plato->field_image['und'][0]):?>
                  <li data-target="#<?php print $plato->field_image['und'][0]['filename'] ?>" data-slide-to="<?php print $i ?>" class="active"></li>
                <?php endif; ?>
                <?php endforeach; ?>
              </ol>
                

              <!-- Wrapper for slides -->
              <div class="carousel-inner" role="listbox">
                <?php foreach ($categoria['field_collection']->field_menu_platos['und'] as $i => $plato): ?>
                <?php $plato = $plato['node']; ?>
                <?php if ($plato->field_image['und'][0]):?>
                  <div class="item <?php print $i == 0 ? 'active' : '' ?>" id="<?php print $plato->field_image['und'][0]['filename'] ?>">
                  <?php print theme('image_style', array('style_name' => 'receta_page', 'path' => $plato->field_image['und'][0]['uri'])) ?>
                  <div class="carousel-caption">
                    <?php if ($idioma == 'es'): ?>
                    <h3><?php print $plato->title ?></h3>
                    <?php else: ?>
                    <h3><?php print $plato->field_errezeta_nombre_carta_eus['und'][0]['value'] ?></h3>
                    <?php endif; ?>
                    <p></p>
                  </div>
                </div><!-- item-active -->
                <?php endif; ?>
                <?php endforeach; ?>
              </div><!-- carousel-inner -->

              <!-- Controls -->
              <a class="left carousel-control" href="#carousel-entrantes" role="button" data-slide="prev">
                <img src="/sites/all/themes/kapital/images/angle-left.svg" width="30" height="30" alt="Anterior">
              </a>
              <a class="right carousel-control" href="#carousel-entrantes" role="button" data-slide="next">
                <img src="/sites/all/themes/kapital/images/angle-right.svg" width="30" height="30" alt="Siguiente">
              </a>
            </div>

          </div><!-- /.col-->
          <div class="col-sm-7">
                <h1 class="mt-0"><?php print t($categoria['field_collection']->field_menu_nombre_categoria['und'][0]['value'])?></h1>
                
                <div class="table-responsive">
                  <table class="table">
                    <thead>
                      <tr>
                        <th><?php print t('Plato') ?></th>
                        <th><?php print t('Alérgenos') ?>*</th>
                        <?php if ($tab['field_collection']->field_menu_tipo_titulo['und'][0]['value'] != 'Menú del día'): ?>
                        <th><?php print t('Precio') ?></th>
                        <?php endif; ?>
                      </tr>
                    </thead>
                    <tbody>
                      <?php foreach ($categoria['field_collection']->field_menu_platos['und'] as $i => $plato): ?>
                      <?php $plato = $plato['node'];?>
                        <tr>
                          <?php if ($idioma == 'es'): ?>
                          <td><?php print $plato->title ?></td>
                          <?php else: ?>
                          <td><?php print $plato->field_errezeta_nombre_carta_eus['und'][0]['value'] ?></td>
                          <?php endif; ?>
                          <td>
                            <?php foreach($plato->field_alergenos['und'] as $alergeno): ?>
                              <?php print $alergeno['value'] ?>
                            <?php endforeach; ?>
                          </td>
                          <?php if ($tab['field_collection']->field_menu_tipo_titulo['und'][0]['value'] != 'Menú del día'): ?>
                          <td><?php print $plato->field_produktua_prezioa['und'][0]['value'] ?>€</td>
                          <?php endif; ?>
                        </tr>
                      <?php endforeach; ?>
                    </tbody>
                  </table>
                </div>

            </div><!-- /.col-->
          </div><!-- /.row-->
          
        <?php endforeach; ?>
          <div class="row">
            <div class="col-sm-5"></div>
            <div class="col-sm-7"><p class=""><?php print t($tab['field_collection']->field_menu_tipo_descripcion['und'][0]['value'])?></p></div>
          </div>
      </div><!-- /.tab-pane-->

    <?php    endforeach; ?>
         </div><!-- /.tab-content-->
  </div><!-- /.col-->
  
  <p><?php print t('*Información sobre alérgenos') ?>
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
  </ul>













  </p>
</div><!-- /.row-->