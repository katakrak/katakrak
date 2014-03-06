<?php

/**
 * @file
 * Default theme implementation to format the simplenews newsletter body.
 *
 * Copy this file in your theme directory to create a custom themed body.
 * Rename it to override it. Available templates:
 *   simplenews-newsletter-body--[tid].tpl.php
 *   simplenews-newsletter-body--[view mode].tpl.php
 *   simplenews-newsletter-body--[tid]--[view mode].tpl.php
 * See README.txt for more details.
 *
 * Available variables:
 * - $build: Array as expected by render()
 * - $build['#node']: The $node object
 * - $title: Node title
 * - $language: Language code
 * - $view_mode: Active view mode
 * - $simplenews_theme: Contains the path to the configured mail theme.
 * - $simplenews_subscriber: The subscriber for which the newsletter is built.
 *   Note that depending on the used caching strategy, the generated body might
 *   be used for multiple subscribers. If you created personalized newsletters
 *   and can't use tokens for that, make sure to disable caching or write a
 *   custom caching strategy implemention.
 *
 * @see template_preprocess_simplenews_newsletter_body()
 */
?>
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
                    <img src="<?php print 'http://test.katakrak.net/'.drupal_get_path('theme', 'coworker').'/images/boletin/buletin_header.png' ?>">
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
                <h1><?php print $build['#node']->title ?></h1>
                
                <?php print theme('image_style', array('style_name' => 'boletin_destacado', 'path' => $build['#node']->field_boletin_imagen['und'][0]['uri'])) ?>
              </td>
              <td class="expander"></td>
            </tr>
          </table>

          <table class="twelve columns">
            <tr>
              <td class="panel">
                <p><?php print $build['#node']->body[LANGUAGE_NONE][0]['value'] ?></p>
              </td>
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
                <?php foreach($build['#node']->field_boletin_libros['und'] as $i => $nid): ?>
                <?php $event = node_load($nid['nid']); ?>
                <?php endforeach; ?>
                <p></p>

                <table class="button">
                  <tr>
                    <td>
                      <a href="#">Click Me!</a>
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
                <h6>Libros de la semana / Asteko liburuak</h6>
                <?php foreach($build['#node']->field_boletin_libros['und'] as $i => $nid): ?>
                <?php $libro = node_load($nid['nid']); ?>
                <table>
                    <tr>
                      <td>
                        <?php print l($libro->title, 'node/'.$libro->nid) ?>
                      </td>
                    </tr>
                  </table>
                <?php if (count($build['#node']->field_boletin_libros['und']) != $i + 1): ?>
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
                <h6 style="margin-bottom:5px;">Connect With Us:</h6>
                <table class="tiny-button facebook">
                    <tr>
                      <td>
                        <a href="#">Facebook</a>
                      </td>
                    </tr>
                  </table>

                  <hr>

                  <table class="tiny-button twitter">
                    <tr>
                      <td>
                        <a href="#">Twitter</a>
                      </td>
                    </tr>
                  </table>

                  <hr>

                  <table class="tiny-button google-plus">
                    <tr>
                      <td>
                        <a href="#">Google +</a>
                      </td>
                    </tr>
                  </table>
                <br>
                <h6 style="margin-bottom:5px;">Contact Info:</h6>
                <p>Phone: <b>948225520</b></p>
                <p>Email: <a href="mailto:info@katakrak.net">info@katakrak.net</a></p>
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
