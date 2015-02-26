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
 * @ingroup themeable
 */
if (!$page) {
  include 'node_teaser.tpl.php';
} else {
  ?>
  <div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

    <?php print $user_picture; ?>

    <?php print render($title_prefix); ?>
    <?php if (!$page): ?>
      <div class="entry_title">
        <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
      </div>
    <?php endif; ?>
    <?php
    if ($page && $node->type == 'blog'):
      ?>
      <div class="entry_title">
        <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
      </div>
    <?php endif; ?>

    <?php print render($title_suffix); ?>



    <div class="entry_content content fichalinea"<?php print $content_attributes; ?>>
      <?php
      // We hide the comments and links now so that we can render them later.
      
      hide($content['comments']);
      hide($content['links']);
      
      
      ?>
      <div class="itinerario-header row-fluid">
        <div class="span10 offset1">
          <h1><?php print $node->title ?></h1>
        </div>
      </div>
      <div class="clear"></div>
      <div class="row itinerario-desc">
        <div class="span1 offset1">
          <div class="circle">
            <div class="circle-<?php print $node->field_itinerario_linea['und'][0]['value'] ?>">
            </div>
          </div>
        </div>
        <div class="span5">
          <div class="bubble"><?php print check_markup($node->field_itinerario_descripcion['und'][0]['value'], $node->field_itinerario_descripcion['und'][0]['format']) ?>
          </div>
        </div>
        <div class="span6">
          <?php print render($content['field_itinerario_imagen']) ?>
        </div>
      </div>
      <div class="row-fluid">
        <div class="span6">
          <?php foreach($node->portadas as $row): ?>
            <div class="row-fluid">
              <?php foreach($row as $portada): ?>
                <div class="span3">
                  <?php print l($portada['image'], 'node/'.$portada['nid'], array('html' => true)); ?>
                </div>
              <?php endforeach; ?>
            </div>
          <?php endforeach; ?>
        </div>
        <div class="span6">
          <div class="ficharight">
            <ul class="listaparadastrayecto" id="listaparadastrayecto">
              <?php foreach($node->paradas as $parada): ?>
                <li>
                  <div class="iconlistaparadatrayectos">&nbsp;</div>
                  <div class="namelistaparadatrayectos" id="namelistaparadatrayectos">
                    <?php foreach($parada->libros as $libros): ?>
                    <?php //print_r($libros) ?>
                      <h3><?php foreach($libros['parada_libros'] as $k => $libro): ?>
                        <?php print l($libro->title, 'node/'.$libro->nid) ?>
                          <?php if (count($libros['parada_libros']) > $k+1):?>
                          / 
                          <?php endif;?>
                      <?php endforeach; ?><span class="autor"><?php print $libros['parada_libros'][0]->autores[0] ?></span></h3> <span class="itinerario-libro-tipo <?php print $libros['tipos'][0]['value'] ?>"><?php print substr($libros['tipos'][0]['value'], 0, 1) ?></span> 
                      <?php foreach ($libro->itinerarios as $itinerario): ?>
                      
                      <a href="/node/<?php print $itinerario['nid'] ?>"><span class="circle-small" style="background-color: <?php print $itinerario['color'] ?>"><?php print $itinerario['linea'] ?></span></a>
                      <?php endforeach;?>
                          <br>
                      <?php endforeach;?>
                    <?php endforeach; ?>
                  </div>
                </li>
            </ul>
            <div class="itinerario-leyenda">
              <span class="itinerario-libro-tipo komikia">K</span> <?php print t("Cómic") ?>
              <span class="itinerario-libro-tipo poesia">P</span> <?php print t("Poesia") ?>
              <span class="itinerario-libro-tipo narratiba">N</span> <?php print t("Narrativa") ?>
              <span class="itinerario-libro-tipo saiakera">S</span> <?php print t("Ensayo") ?>
              <span class="itinerario-libro-tipo antzerkia">T</span> <?php print t("Teatro") ?>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
  <?php
}
?>