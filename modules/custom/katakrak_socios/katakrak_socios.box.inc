<?php

/**
 * @file
 * katakrak_socios.box.inc
 */

/**
 * Implements hook_default_box().
 */
function katakrak_socios_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'coming_soon';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Coming soon';
  $box->options = array(
    'body' => array(
      'value' => '<h2>Webgunea garatzen ari gara. Laster izango gara zuekin</h2>
<h2>Sitio web en desarrollo. Pronto en sus pantallas</h2>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['coming_soon'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'como_hacer_crack';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Como hacer crack';
  $box->options = array(
    'body' => array(
      'value' => '<div class="panel-pane pane-views-panes pane-blog-blog-post-libreria">
                
                                    <img src="hacerkraktrans.png" /><br /><br />
                                    <div class="bloque-evento">
                                        <div class="figura fecha-evento">
                                        18<br />
                                        .05
                                        <div class="clear"></div>
                                        </div>
                                    
                                        <div class="subfigura contenido-evento">
                                        <h4>TITULO</h4>
                                        <p>Contenido <a href="#">+</a></p>
                                        <em>Pedro Perez | Maria Casanova</em>
                                        <div class="clear"></div>
                                        </div><br />
                                    <div class="clear"></div>   
                                    </div>
                                    <div class="bloque-evento">
                                        <div class="figura fecha-evento">
                                        18<br />
                                        .05
                                        <div class="clear"></div>
                                        </div>
                                    
                                        <div class="subfigura contenido-evento">
                                        <h4>TITULO</h4>
                                        <p>Contenido <a href="#">+</a></p>
                                        <em>Pedro Perez | Maria Casanova</em>
                                        <div class="clear"></div>
                                        </div><br />
                                    <div class="clear"></div>   
                                    </div>
                                    <div class="bloque-evento">
                                        <div class="figura fecha-evento">
                                        18<br />
                                        .05
                                        <div class="clear"></div>
                                        </div>
                                    
                                        <div class="subfigura contenido-evento">
                                        <h4>TITULO</h4>
                                        <p>Contenido <a href="#">+</a></p>
                                        <em>Pedro Perez | Maria Casanova</em>
                                        <div class="clear"></div>
                                        </div><br />
                                    <div class="clear"></div>   
                                    </div><div class="bloque-evento">
                                        <div class="figura fecha-evento">
                                        18<br />
                                        .05
                                        <div class="clear"></div>
                                        </div>
                                    
                                        <div class="subfigura contenido-evento">
                                        <h4>TITULO</h4>
                                        <p>Contenido <a href="#">+</a></p>
                                        <em>Pedro Perez | Maria Casanova</em>
                                        <div class="clear"></div>
                                        </div><br />
                                    <div class="clear"></div>   
                                    </div>

                                    <div class="bloque-evento">
                                        <div class="figura fecha-evento">
                                        18<br />
                                        .05
                                        <div class="clear"></div>
                                        </div>
                                    
                                        <div class="subfigura contenido-evento">
                                        <h4>TITULO</h4>
                                        <p>Contenido <a href="#">+</a></p>
                                        <em>Pedro Perez | Maria Casanova</em>
                                        <div class="clear"></div>
                                        </div><br />
                                    <div class="clear"></div>   
                                    </div>
                                    <div class="bloque-evento">
                                        <div class="figura fecha-evento">
                                        18<br />
                                        .05
                                        <div class="clear"></div>
                                        </div>
                                    
                                        <div class="subfigura contenido-evento">
                                        <h4>TITULO</h4>
                                        <p>Contenido <a href="#">+</a></p>
                                        <em>Pedro Perez | Maria Casanova</em>
                                        <div class="clear"></div>
                                        </div><br />
                                    <div class="clear"></div>   
                                    </div>
                                    <div class="bloque-evento">
                                        <div class="figura fecha-evento">
                                        18<br />
                                        .05
                                        <div class="clear"></div>
                                        </div>
                                    
                                        <div class="subfigura contenido-evento">
                                        <h4>TITULO</h4>
                                        <p>Contenido <a href="#">+</a></p>
                                        <em>Pedro Perez | Maria Casanova</em>
                                        <div class="clear"></div>
                                        </div><br />
                                    <div class="clear"></div>   
                                    </div><div class="bloque-evento">
                                        <div class="figura fecha-evento">
                                        18<br />
                                        .05
                                        <div class="clear"></div>
                                        </div>
                                    
                                        <div class="subfigura contenido-evento">
                                        <h4>TITULO</h4>
                                        <p>Contenido <a href="#">+</a></p>
                                        <em>Pedro Perez | Maria Casanova</em>
                                        <div class="clear"></div>
                                        </div><br />
                                    <div class="clear"></div>   
                                    </div>
                                    <br />
                                    <div class="clear"></div>
                                    <br />
                                    <div id="boton-aportar">APORTAR</div>
                                    <br /><br />
                                    <h3 class="katakrakendatos">KATAKRAK EN DATOS</h3>
                                    <br /><br />
                                    <div class="figura figura2">150</div>
                                    <div class="subfigura subfigura2">actos en 2020</div><br />
                                    <div class="figura figura2">1000</div>
                                    <div class="subfigura subfigura2">actos en nuestra historia</div><br />
                                    <div class="figura figura2">600</div>
                                    <div class="subfigura subfigura2">audios</div><br />
                                    <div class="figura figura2">120</div>
                                    <div class="subfigura subfigura2">colectivos/usuarixs</div><br />
                                    <div class="figura figura2">12.000</div>
                                    <div class="subsubfigura2">seguidorxs en RRSS</div><br />
                                    
                                    
                                </div>',
      'format' => 'full_html',
    ),
  );
  $export['como_hacer_crack'] = $box;

  return $export;
}
