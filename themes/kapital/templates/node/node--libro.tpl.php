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
?>
<?php if ($page): ?>
<div class="book">
  <div class="cover">
     <?php print render($content['field_libro_portada']) ?>
  </div><!-- /cover -->
  <div class="visible-xs-block">
    <h1><?php print $node->title ?></h1>
    <p>
      <?php print $content['autores'] ?>
    </p>
  </div>  
  <div class="buy">
    <p class="price"><?php print $content['product:commerce_price'][0]['#markup'] ?></p>
    <p class="small text-color-light"><?php print t('IVA incluido') ?></p>
    
    <?php if ($node->disponibilidad == DISPONIBLE_LIBRERIA): ?>
      <p class="success"><?php print t('Disponible') ?></p>
    <?php elseif( $node->disponibilidad == DISPONIBLE_DISTRIBUIDOR): ?>
      <p class="text-warning"><?php print t('Disponible en @count días', array('@count' => distribuidores_plazo($node->plazo))) ?></p>
    <?php elseif($node->disponibilidad == NO_DISPONIBLE): ?>
      <p class="text-danger"><?php print t('No disponible') ?></p>
    <?php endif; ?>
    <?php if ($node->disponibilidad == DISPONIBLE_LIBRERIA || $node->disponibilidad == DISPONIBLE_DISTRIBUIDOR): ?>
      <div class="mt-2">
        <?php print render($content['field_libro_producto']) ?>
        <?php print libro_generar_boton_product($node->nid, TRUE) ?>
      </div>
    <?php endif; ?>
      
      
  </div><!-- /buy -->
  <div class="description">
    <h1 class="hidden-xs"><?php print $node->title ?></h1>
    <?php if ($content['autores']): ?>
      <p class="hidden-xs">
          <?php print $content['autores'] ?>
      </p>
    <?php endif; ?>
    <div class="mt-2">
      <table class="table table-condensed table-book">
        <tbody>
          <tr>
            <th>ISBN</th>
            <td><?php print $content['field_libro_isbn'][0]['#markup'] ?></td>
          </tr>
          <tr>
            <th><?php print t('Páginas') ?></th>
            <td><?php print $content['field_libro_paginas'][0]['#markup'] ?></td>
          </tr>
          <tr>
            <th><?php print t('Año') ?></th>
            <td><?php print $content['field_libro_year'][0]['#markup'] ?></td>
          </tr>
          <tr>
            <th><?php print t('Editorial') ?></th>
            <td><?php print $content['field_libro_editorial'][0]['#markup'] ?></td>
          </tr>
          <tr>
            <th><?php print t('Sección') ?></th>
            <td><?php $node->ubicacion ? print $node->ubicacion . ' / ': ''?><?php print l($content['field_libro_categoria']['#items'][0]['taxonomy_term']->name, 'taxonomy/term/'.$content['field_libro_categoria']['#items'][0]['tid']); ?></td>
          </tr>
        </tbody>
      </table>
    </div>
    <p>
         <?php print $node->sinopsis ?>
    </p>
    <?php if ($node->leer_mas): ?>
    <p>
      <a data-toggle="collapse" href="#collapse-sinopsis">Leer más</a>
    </p>
    <div class="collapse" id="collapse-sinopsis">
      <p>
        <?php print $node->leer_mas ?>
      </p>
    </div><!-- /posible collapse-->
    <?php endif; ?>
  </div><!-- /description -->
</div>
<?php print render($content['links']); ?>
<hr class="hr-dark">
<h2 class="text-center"><?php print t('Te puede interesar') ?></h2>
<?php print views_embed_view('libros', 'libros_rel_cat', $node->field_libro_categoria['und'][0]['tid']) ?>
<?php endif; ?>

<?php if ($view_mode == 'card_book'): ?>
<div class="card-book-sm">
  <div class="<?php print $content['cover_class'] ?>">
      <?php print render($content['field_libro_portada']) ?>

  </div><!-- /cover -->
  <div class="description">
    <h3 class="book-title-sm">
      <?php print l($node->title, 'node/'.$node->nid) ?>
    </h3>
      <p><?php print render($content['field_libro_autores']) ?></p>
      <p class="price"><?php print $content['product:commerce_price'][0]['#markup'] ?></p>
      <?php if ($node->disponibilidad == DISPONIBLE_LIBRERIA): ?>
      <p class="success"><?php print t('Disponible') ?></p>
    <?php elseif( $node->disponibilidad == DISPONIBLE_DISTRIBUIDOR): ?>
      <p class="text-warning"><?php print t('Disponible en @count días', array('@count' => distribuidores_plazo($node->plazo))) ?></p>
    <?php elseif($node->disponibilidad == NO_DISPONIBLE): ?>
      <p class="text-danger"><?php print t('No disponible') ?></p>
    <?php endif; ?>
  </div><!-- /description -->
</div><!-- /.card-book-sm-->
<?php elseif($view_mode == 'card_book_md'): ?>
<div class="card-book-md">
    <div class="cover">
     <?php print render($content['field_libro_portada']) ?>
      </div><!-- /cover -->
    <div class="description">
        <h3 class="mt-0">
            <?php print l($node->title, 'node/'.$node->nid) ?>
        </h3>
        <p><?php print render($content['field_libro_autores']) ?></p>
        <p class="small text-gray mb-0"><?php print $content['field_libro_year'][0]['#markup'] ?>, <?php print l($content['field_libro_editorial'][0]['#title'], $content['field_libro_editorial'][0]['#href']) ?></p>
        <p class="small"><?php $node->ubicacion ? print $node->ubicacion . ' / ': ''?><?php print l($content['field_libro_categoria']['#items'][0]['taxonomy_term']->name, 'taxonomy/term/'.$content['field_libro_categoria']['#items'][0]['tid']); ?></p>
        <p class="price"><?php print $content['product:commerce_price'][0]['#markup'] ?></p>
        <?php if ($node->disponibilidad == DISPONIBLE_LIBRERIA): ?>
          <p class="small success"><?php print t('Disponible') ?></p>
        <?php elseif( $node->disponibilidad == DISPONIBLE_DISTRIBUIDOR): ?>
          <p class="small text-warning"><?php print t('Disponible en @count días', array('@count' => distribuidores_plazo($node->plazo))) ?></p>
        <?php elseif($node->disponibilidad == NO_DISPONIBLE): ?>
          <p class="small text-danger"><?php print t('No disponible') ?></p>
        <?php endif; ?>
    </div><!-- /description -->
    </div><!-- /.card-book-md-->
<?php endif; ?>
