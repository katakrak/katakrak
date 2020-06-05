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
global $language;
?>
  <div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

    <div class="entry_content content <?php print $content_attributes; ?>">
      <?php
      // We hide the comments and links now so that we can render them later.
      
      hide($content['comments']);
      hide($content['links']);
      //print render($content);
      ?>
      <div class="row">
        <div class="col-xs-12">
          <div class="visible-xs">
            <h1>
              <?php if ($page): ?>
                <?php print $node->title ?>
              <?php else: ?>
                <?php print l($node->title, 'node/'.$node->nid) ?>
              <?php endif; ?>
            </h1>
            <?php print render($content['field_libro_subtitulo']) ?>
            <h4><?php print render($content['field_libro_autores'])  ?></h4>
          </div>
          
          <div class="row">
            <div class="col-sm-4 col-md-4">
              <?php print render($content['field_libro_portada']) ?>
            </div>
            <div class="col-sm-8 col-md-8">
              <div class="hidden-xs">
                <div class="row">
                  <div class="col-xs-12">
                    <h1>
                      <?php if ($page): ?>
                        <?php print $node->title ?>
                      <?php else: ?>
                        <?php print l($node->title, 'node/'.$node->nid) ?>
                      <?php endif; ?>
                    </h1>
                    <?php print render($content['field_libro_subtitulo']) ?>
                  </div>
                </div>
                <div class="row">
                  <div class="col-sm-8">
                    <h3><?php print render($content['field_libro_autores']) ?></h3>
                  </div>
                  <div class="col-sm-4">
                    <?php print render($content['sharethis']) ?>
                  </div>
                </div>
                
              </div>
               
              <div class="book-metadata row">
                <div class="col-sm-6 col-md-6">
              <div class="book-info-entry">
                <span class="col-2 book-info-label">
                  <?php print t('ISBN') ?>
                </span>
                <span class="col-2 book-info-data">
                    <?php print $content['field_libro_isbn'][0]['#markup'] ?>
                </span>
              </div>
              <div class="book-info-entry">
                <span class="col-2 book-info-label">
                  <?php print t('Páginas') ?>
                </span>
                <span class="col-2 book-info-data">
                    <?php print $content['field_libro_paginas'][0]['#markup'] ?>
                </span>
              </div>
              <div class="book-info-entry">
                <span class="col-2 book-info-label">
                  <?php print t('Año') ?>
                </span>
                <span class="col-2 book-info-data">
                  <?php print $content['field_libro_year'][0]['#markup'] ?>
                </span>
              </div>
              <div class="book-info-entry">
                <span class="col-2 book-info-label">
                  <?php print t('Editorial') ?>
                </span>
                <span class="col-2 book-info-data">
                  <?php print $content['field_libro_editorial'][0]['#markup'] ?>
                </span>
              </div>
              <div class="book-info-entry">
                <span class="col-2 book-info-label">
                  <?php print t('Estado') ?>
                </span>
                <span class="col-2 book-info-data">
                  <?php print t($content['field_libro_estado'][0]['#markup']) ?>
                </span>
              </div>
              <div class="book-info-entry">
                <span class="col-2 book-info-label">
                  <?php print t('Sección') ?>
                </span>
                <span class="col-2 book-info-data">
                    <?php $node->ubicacion ? print $node->ubicacion . ' / ': ''?><?php print l($content['field_libro_categoria']['#items'][0]['taxonomy_term']->name, 'taxonomy/term/'.$content['field_libro_categoria']['#items'][0]['tid']); ?>
                </span>
              </div>
            </div>

              <div class="col-sm-3">
                <?php if ($node->itinerarios): ?>
                <div class="itinerarios">
                  <?php foreach($node->itinerarios[$language->language] as $itinerario): ?>
                    <a title="<?php print t('Este libro pertenece a un itinerario de lectura')?>" href="<?php print url('node/'.$itinerario['nid'])?>">
                      <div class="linea-<?php print $itinerario['linea'] ?>">
                        <div class="circle">
                          <div class="circle-<?php print $itinerario['linea'] ?>">
                          </div>
                        </div>
                      </div>
                    </a>
                  <?php endforeach; ?>
                  </div>
                <?php endif; ?>
              </div>
              <div class="col-sm-3">
                <?php if ($content['mostrar_carrito']): ?>
                
                <div class="book-buy">
                  <div class="book-price"><?php print $content['product:commerce_price'][0]['#markup'] ?></div>
                  <?php print render($content['field_libro_producto']) ?>
                  <?php if ($content['disponible_bajo_pedido']): ?>
                  <div class="alert alert-block alert-warning fade in"><strong><?php print t('Sin stock en tienda. Se puede adquirir igualmente pero tardará entre 3 y 4 días más el envío.') ?></strong></div>
                  <?php endif; ?>
                </div>
                  <?php endif; ?>
              </div>
              <div class="row">
                <div class="col-sm-12 col-md-12">
                  <?php print render($content['field_libro_sinopsis']) ?>
                </div>
              </div>
              <?php if(!$page && $content['field_libro_sinopsis']): ?>
                <?php print l(t("Leer más [+]"), 'node/'.$node->nid) ?>
              <?php endif; ?>
            </div>
          </div>
        </div>
        </div>
      </div>
      
      <?php if ($page): ?>
        <div class="row">
          <div class="col-xs-12">
            <?php $view = views_get_view_result('blog', 'resenas_libro', $node->nid)?>
            <?php if ($view): ?>
              <h2 class="block"><?php print t('Reseñas:')?></h2>
              <?php print views_embed_view('blog', 'resenas_libro', $node->nid) ?>
            <?php endif; ?>
            
            
            <h2 class="block"><?php print t('Otros libros en %term', array('%term' => $content['field_libro_categoria']['#items'][0]['taxonomy_term']->name))?></h2>
            <?php print views_embed_view('libros', 'libros_rel_cat', $node->field_libro_categoria['und'][0]['tid']) ?>
            <?php $view = views_get_view_result('libros', 'libros_rel_autor', $node->field_libro_autores['und'][0]['tid'])?>
            <?php if ($view): ?>
              <h2 class="block"><?php print t('Otros libros del autor')?></h2>
              <?php print views_embed_view('libros', 'libros_rel_autor', $node->field_libro_autores['und'][0]['tid']) ?>
            <?php endif; ?>
          </div>
        </div>
      <?php endif; ?>
      

      <?php if ($page): print render($content['links']);
      endif;
      ?>
    </div>

  </div>