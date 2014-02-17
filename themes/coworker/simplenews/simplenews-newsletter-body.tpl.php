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
                  <table class="container">
                    <tr>
                      <td class="wrapper last">

                        <table class="twelve columns">
                          <tr>
                            <td class="six sub-columns">
                              <img src="http://placehold.it/200x50">
                            </td>
                            <td class="six sub-columns last" style="text-align:right; vertical-align:middle;">
                              <span class="template-label">SIDEBAR</span>
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
                    <td class="wrapper">

                      <table class="six columns">
                        <tr>
                          <td>
                            <h2>Hello,<br> Han Fastolfe</h2>
                            <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et.</p>
                            <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et. Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et. Lorem ipsum dolor sit amet.</p>
                          </td>
                          <td class="expander"></td>
                        </tr>
                      </table>

                      <table class="six columns">
                        <tr>
                          <td class="panel">
                            <p>Phasellus dictum sapien a neque luctus cursus. Pellentesque sem dolor, fringilla et pharetra vitae. <a href="#">Click it! »</a></p>
                          </td>

                          <td class="expander"></td>
                        </tr>
                      </table>

                      <table class="six columns">
                        <tr>
                          <td>
                            <br>
                            <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et.</p>

                            <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et. Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et. Lorem ipsum dolor sit amet.</p>

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
                            <h6>Header Thing</h6>
                            <p>Sub-head or something</p>
                            <table>
                              <tr>
                                <td>
                                  <a href="#">Just a Plain Link &raquo;</a>
                                </td>
                              </tr>
                            </table>
                            <hr>
                            <table>
                              <tr>
                                <td>
                                  <a href="#">Just a Plain Link &raquo;</a>
                                </td>
                              </tr>
                            </table>
                            <hr>
                            <table>
                              <tr>
                                <td>
                                  <a href="#">Just a Plain Link &raquo;</a>
                                </td>
                              </tr>
                            </table>
                            <hr>
                            <table>
                              <tr>
                                <td>
                                  <a href="#">Just a Plain Link &raquo;</a>
                                </td>
                              </tr>
                            </table>
                            <hr>
                            <table>
                              <tr>
                                <td>
                                  <a href="#">Just a Plain Link &raquo;</a>
                                </td>
                              </tr>
                            </table>
                            <hr>
                            <table>
                              <tr>
                                <td>
                                  <a href="#">Just a Plain Link &raquo;</a>
                                </td>
                              </tr>
                            </table>
                            <hr>
                            <table>
                              <tr>
                                <td>
                                  <a href="#">Just a Plain Link &raquo;</a>
                                </td>
                              </tr>
                            </table>
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
                            <p>Phone: <b>408.341.0600</b></p>
                            <p>Email: <a href="mailto:hseldon@trantor.com">hseldon@trantor.com</a></p>
                          </td>
                          <td class="expander"></td>
                        </tr>
                      </table>

                    </td>
                  </tr>
                </table>
                <br>
                <br>
                <!-- Legal + Unsubscribe -->
                <table class="row">
                  <tr>
                    <td class="wrapper last">

                      <table class="twelve columns">
                        <tr>
                          <td align="center">
                            <center>
                              <p style="text-align:center;"><a href="#">Terms</a> | <a href="#">Privacy</a> | <a href="#">Unsubscribe</a></p>
                            </center>
                          </td>
                          <td class="expander"></td>
                        </tr>
                      </table>

                    </td>
                  </tr>
                </table>

              <!-- container end below -->
              </td>
            </tr>
          </table>
