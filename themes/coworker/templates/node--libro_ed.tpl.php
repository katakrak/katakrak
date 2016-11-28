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
		<?php // We hide the comments and links now so that we can render them later.hide($content['comments']);hide($content['links']);?>
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
						<?php if ($node->field_libro_ed_proxima['und'][0]['value']):?>
							<div class="proxima-aparicion">
                <div class="proxima">
                  <?php print t("Próxima aparición") ?>
                </div>
              </div>
						<?php endif; ?>
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
									<?php if ($node->field_libro_subtitulo['und'][0]['value']): ?>
										<h3><?php print render($content['field_libro_subtitulo']) ?></h3>
									<?php endif; ?>
								</div>
							</div>
							<div class="row">
								<div class="col-sm-8">
									<h3><?php print render($content['field_libro_ed_autor']) ?></h3>
									<?php if ($node->field_libro_ed_prologo['und'][0]['value']): ?>
										<p><?php print t('Prólogo de ')?><strong><?php print $content['field_libro_ed_prologo'][0]['#markup']?></strong></p>
									<?php endif; ?>
									<?php if ($node->traductores): ?>	
										<p><?php print t('Traducción de ') ?><strong><?php print $node->traductores ?></strong></p>
									<?php endif; ?>
								</div>
								<div class="col-sm-4">
									<?php print render($content['sharethis']) ?>
                  <?php if ($node->field_libro_producto['und'][0]['product_id']): ?>
                    <?php print libro_generar_boton_compra($node->field_libro_producto['und'][0]['product_id']) ?>
                  <?php endif; ?>
								</div>
							</div>
							<div class="row">
								<div class="col-sm-12 col-md-12">
									<?php print render($content['field_libro_sinopsis']) ?>
								</div>
							</div>
						</div>
					</div>
				</div>
			</div>
		</div>
		<?php if ($page): ?>
			<?php print render($content['links']); ?>
		<?php endif; ?>
      
		<div class="row ficha-editorial-info container">
			<div class="col-md-4 ficha-tecnica">
				<h3><?php print t("Ficha Técnica")?> </h3>
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
						<?php print t('Idioma') ?>
					</span>
					<span class="col-2 book-info-data">
						<?php print $content['field_libro_idioma'][0]['#markup'] ?>
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
						<?php print t('Tamaño') ?>
					</span>
					<span class="col-2 book-info-data">
						<?php print $content['field_libro_ed_tamano'][0]['#markup'] ?>
					</span>
				</div>
				<div class="book-info-entry">
					<span class="col-2 book-info-label">
						<?php print t('Encuadernación') ?>
					</span>
					<span class="col-2 book-info-data">
						<?php print $content['field_libro_ed_encuadernacion'][0]['#markup'] ?>
					</span>
				</div>
				<div class="book-info-entry">
					<span class="col-2 book-info-label">
						<?php print t('Precio') ?>
					</span>
					<span class="col-2 book-info-data">
						<?php print $content['field_libro_ed_precio'][0]['#markup'] ?>€
					</span>
				</div>
			</div>
			<div class="col-md-8 ficha-autor <?php print count($node->autores) > 1 ? 'varios-autores': ''?>">
				<?php foreach($node->autores as $autor): ?>
				<div class="row">
					<div class="col-md-7">
						<h2><?php print l($autor->title, 'node/'.$autor->nid) ?></h2>
						<p><?php print $autor->field_autor_nacimiento['und'][0]['value'] ?></p>
						<p><?php print truncate_utf8($autor->body['und'][0]['value'], 640, TRUE, TRUE) ?></p>
						<p><?php print l(t('Leer más [+]'), 'node/'.$autor->nid) ?></p>
					</div>
					<div class="col-md-5 imagen">
							<?php print theme('image_style', array('style_name' => 'autor_editorial_ficha_libro', 'path' => $autor->field_imagen['und'][0]['uri'])) ?>
					</div>

				</div>
				<?php	endforeach; ?>
			</div>
		</div>
	</div>
</div>

