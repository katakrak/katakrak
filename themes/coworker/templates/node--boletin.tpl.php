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
 */?>

<table class="body">
  <tr>
    <td class="center" align="center" valign="top">
      <center>
        <table class="row header">
          <tr>
            <td class="center" align="center">
              <center>
                <table class="container">
                  <tr>
                    <td class="wrapper last">

                      <table class="twelve columns">
                        <tr>
                          <td class="last">
                            <img src="<?php print 'http://www.katakrak.net/'.drupal_get_path('theme', 'coworker').'/images/boletin/buletin_header.png' ?>">
                          </td>
                          <td class="expander"></td>
                        </tr>
                      </table>

                    </td>
                  </tr>
                </table>
              </center>
            </td>
          </tr>
        </table>

        <br>

        <table class="container">
          <tr>
            <td>

              <!-- content start -->
              <table class="row">
                <tr>
                  <td class="wrapper last">
                    <table class="twelve columns">
                      <tr>
                        <td>
                          <h1><?php print $node->title ?></h1>
                          <?php if ($node->field_boletin_imagen['und'][0]['uri']): ?>
                              <?php print theme('image_style', array('style_name' => 'boletin_destacado', 'path' => $node->field_boletin_imagen['und'][0]['uri'])) ?>
                          <?php endif; ?>
                        </td>
                        <td class="expander"></td>
                      </tr>
                    </table>

                    <table class="twelve columns">
                      <tr>
                        <?php if ($node->body[LANGUAGE_NONE][0]['value']): ?>
                          <td class="panel">
                            <p><?php print $node->body[LANGUAGE_NONE][0]['value'] ?></p>
                          </td>
                        <?php endif; ?>
                        <td class="expander"></td>
                      </tr>
                    </table>
                  </td>
                </tr>
              </table>

          <br>  <!-- Break Tag for row -->

          <table class="row">
            <tr>
              <td class="wrapper">

                <table class="six columns">
                  <tr>
                    <td>
                      <h6>Próximos eventos</br> Hurrengo ekitaldiak</h6>
                      <br>
                      <?php foreach($node->field_boletin_eventos['und'] as $i => $nid): ?>
                      <?php $event = node_load($nid['nid']); 
                            $translations = translation_node_get_translations($event->nid); ?>
                      <table>
                        <tr>
                        <td>
                        <table class="two sub-columns">
                            <tr>
                              <td><strong>
                                <?php print format_date($event->field_event_date['und'][0]['value'], 'custom', 'M', NULL, 'eu') ?> 
                                 <?php print format_date($event->field_event_date['und'][0]['value'], 'custom', 'd', NULL, 'es') ?>
                                <?php print format_date($event->field_event_date['und'][0]['value'], 'custom', 'M', NULL, 'es') ?><br>
                                <?php print format_date($event->field_event_date['und'][0]['value'], 'custom', 'G:i', NULL, 'es') ?>
                                </strong>
                              </td>
                            </tr>
                          </table>
                        </td>
                        <td>
                        <table class="four sub-columns last">
                          <tr>
                            <td>
                              [EUS] <a href="http://www.katakrak.net/eus/node/<?php print $translations['eu']->nid?>""> <?php print $translations['eu']->title ?></a><br>
                              [CAS] <a href="http://www.katakrak.net/cas/node/<?php print $translations['es']->nid?>""> <?php print $translations['es']->title ?></a>
                            </td>
                          </tr>
                        </table>
                        </td>
                        </tr>
                      </table>
                      <?php endforeach; ?>

                      <table class="button">
                        <tr>
                          <td>
                            <a href="http://www.katakrak.net/agenda">Ver todos los eventos <br> Ikusi egitarau osoa</a>
                          </td>
                        </tr>
                      </table>

                    </td>
                    <td class="expander"></td>
                  </tr>
                </table>

              </td>
              <td class="wrapper last">

                <table class="six columns">
                  <tr>
                    <td class="panel">
                      <h6>Libros de la semana <br> Asteko liburuak</h6>
                      <?php foreach($node->field_boletin_libros['und'] as $i => $nid): ?>
                      <?php $libro = node_load($nid['nid']); ?>
                        <table>
                          <tr>
                            <td>
                              <?php print l($libro->title, 'node/'.$libro->nid) ?>
                            </td>
                          </tr>
                        </table>
                        <?php if (count($node->field_boletin_libros['und']) != $i + 1): ?>
                          <hr>
                        <?php endif; ?>
                      <?php endforeach; ?>
                    </td>
                    <td class="expander"></td>
                  </tr>
                </table>
                <br>
                <table class="six columns">
                  <tr>
                    <td class="panel">
                      <h6 style="margin-bottom:5px;">Sare sozialetan / En las RRSS:</h6>
                      <table class="tiny-button facebook">
                          <tr>
                            <td>
                              <a href="http://facebook.com/katakrak54">Facebook</a>
                            </td>
                          </tr>
                        </table>

                        <hr>

                        <table class="tiny-button twitter">
                          <tr>
                            <td>
                              <a href="http://twitter.com/katakrak54">Twitter</a>
                            </td>
                          </tr>
                        </table>

                        <hr>
                      <br>
                      <h6 style="margin-bottom:5px;">Kontaktua <br> Contacto:</h6>
                      <p>Teléfono / Telefonoa: <b>948225520</b></p>
                      <p>Correo / Emaila: <a href="mailto:info@katakrak.net">info@katakrak.net</a></p>
                    </td>
                    <td class="expander"></td>
                  </tr>
                </table>

              </td>
            </tr>
          </table>
          <br>
          <br>

          <!-- container end below -->
          </td>
        </tr>
      </table>

      </center>
    </td>
  </tr>
</table>