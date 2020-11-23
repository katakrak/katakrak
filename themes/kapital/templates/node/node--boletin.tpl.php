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
?>

<p>
            <a href="#" class="btn btn-transparent"> <i class="fas fa-arrow-left small"></i> Listado de artículos</a>
        </p>

       <!-- <p></p>
    <h1 class="text-center">Gerda Lerner en GARA</h1>
    <p class="text-gray text-center">18/08/2020</p> -->

    <div class="row mt-2">
        <div class="col-sm-3">
            <?php print render($content['field_image']) ?>
        </div><!-- /.col-->
        <div class="col-sm-9">
          <h1 class="mt-0">¡Ya son más de 100! ¡Faltas tú!</h1>
          <p class="mb-0">Autor/a</p>
          <p class="text-gray">28/05/2020</p>
          <p>En una semana <strong>ya se han hecho socixs 100 personas</strong>. Amantes de narrativa anglosajona, asiduos a charlas, feministas, fans de sagas de c&oacute;mics fant&aacute;sticos, deboradorxs de libros sobre ecolog&iacute;a, sindicalistas, pensionistas, ni&ntilde;xs exconfinadxs. Ya hay socixs de mil lugares, de Bara&ntilde;ain a Ordizia, Casco Viejo y Segundo Ensanche, Hondarribia y Gandia, Vitoria-Gasteiz y Madrid, Atarrabia y Berriozar, Burlata y Leitza, Zumaia y Bera, Mendillorri y Sarriguren, Bilbao y Hernani, Artika y Zizur Mayor, Donostia e Iturrama, Txantrea y Zirauki, Logro&ntilde;o, Erripagaina, San Jorge y San Juan.<br /><br />Distintos medios nos han ayudado a difundir el mensaje:&nbsp;<a href="https://soundcloud.com/katakrak54/sobre-la-campana-de-socixs-en-eguzki-irratia">EGUZKI IRRATIA</a>,&nbsp;<a href="https://soundcloud.com/katakrak54/iflandia-como-hacer-krak">RADIO EUSKADI</a>, <a href="https://soundcloud.com/katakrak54/euskalerria-irratian-bazkide-kanpainaz">EUSKALERRIA IRRATIA</a>, <a href="https://www.argia.eus/albistea/iruneko-katakrak-liburu-dendak-bazkide-berriak-lortzeko-kanpaina-abiatu-du">ARGIA</a>&nbsp;.<br /><br />Est&aacute; siendo un duro golpe, as&iacute; que s&iacute;, necesitaremos&nbsp;<a href="https://katakrak.net/cas/hazte-socix/alta">a tu prima, a tu amigo que va a los Martes al sol, a tu compa&ntilde;era del instituto que tantas veces te has cruzado en la&nbsp;<em>sala de arriba</em></a>.</p>
       <hr>
          <div class="post-item">
          <h2>¡Otros 4 libros online!</h2>
          <p>Ya puedes descargar estos cuatro libros:&nbsp;<a href="https://katakrak.net/cas/editorial/libro/subversi-n">&iexcl;SUBVERSI&Oacute;N!</a>,&nbsp;<a href="https://katakrak.net/cas/editorial/libro/el-discurso-del-terrorismo">EL DISCURSO DEL TERRORISMO</a>,&nbsp;<a href="https://katakrak.net/eus/argitaletxea/liburua/michael-kohlhaas">MICHAEL KOHLHAAS</a>&nbsp;y&nbsp;<a href="https://katakrak.net/eus/argitaletxea/liburua/sofia-petrovna">SOFIA PETROVNA</a>.</p>
        </div><!-- /.post-item-->
        <div class="post-item">
          <h2>«Sorginak, emaginak eta erizainak» en BIZKAIA IRRATIA</h2>
          <p>Maria Colera visitó BIZKAIA IRRATIA para charlar con Garazi Albizua sobre el libro de Barbara Ehrenreich y Deirdre English.</p>
        </div><!-- /.post-item-->
        <div class="post-item">
          <h2>Más recortes del Día del libro...</h2>
          <p>Allá queda el día del libro... pero hubo piezas que no pasaron por aquí, esta de DIARIO DE NOTICIAS y esta otra
            de BERRIA.</p>
        </div><!-- /.post-item-->
        <div class="post-item">
          <h2>Vídeo: «Las batallas de la bici»</h2>
          <p>La semana pasada tuvimos la suerte de escuchar a James Longhurst y a Laura Carasusán, dentro vídeo.</p>
        </div><!-- /.post-item-->
        <hr>
        <ul class="list-inline list-tags">
            <li>
                <a href="#"><span class="badge">ChuckD</span></a>
            </li>
            <li>
                <a href="#"><span class="badge">ChuckD</span></a>
            </li>
        </ul>
        <hr>
    <h4>Compártelo:</h4>
           <p>RRSS</p>
        </div><!-- /.col-->
        
    </div><!-- /.row -->

    <hr class="hr-dark">
    <h3 class="mb-2">Eventos relacionados</h3>
    <div class="row row-posts mt-3">
      <div class="col-md-4 col-sm-6 mb-2 col-post">
        <div class="post">
         <div class="post-image">
          <a href="#">
              <div class="date">
                  <p class="day">3</p>
                  <p class="small">Septiembre</p>
                  <p class="week-day small">Domingo</p>
                  <p class="time">17:00</p>
              </div>
              <img src="https://ep01.epimg.net/cultura/imagenes/2019/01/22/actualidad/1548183093_439733_1548183392_noticia_normal.jpg" alt=""></a>
         </div>
          <h3 class="post-title">
            <a href="#">Penitencia</a>
          </h3>
          <p class="mb-0">Tonino Carotone</p>
          <p class="small text-gray">Proyección</p>
        </div><!--/.post -->
      </div><!--/.col -->
      <div class="col-md-4 col-sm-6 mb-2 col-post">
          <div class="post">
              <div class="post-image">
               <a href="#">
                   <div class="date">
                       <p class="day">23</p>
                       <p class="small">Noviembre</p>
                       <p class="week-day small">Domingo</p>
                       <p class="time">12:00</p>
                   </div>
                   <img src="https://theundefeated.com/wp-content/uploads/2019/01/GettyImages-461596877-e1547738151756.jpg" alt=""></a>
              </div>
               <h3 class="post-title">
                 <a href="#">Do the right thing</a>
               </h3>
               <p class="mb-0">Chuck D</p>
               <p class="small text-gray">Proyección, Charla</p>
             </div><!--/.post -->
      </div><!--/.col -->
      <div class="col-md-4 col-sm-6 mb-2 col-post">
          <div class="post">
              <div class="post-image">
               <a href="#">
                   <div class="date">
                       <p class="day">9</p>
                       <p class="small">Diciembre</p>
                       <p class="week-day small">Domingo</p>
                       <p class="time">18:00</p>
                   </div>
                   <div class="event-type">
                      <i class="fab fa-soundcloud" title="Será grabado y subido a Soundcloud"></i>
                  </div>
                   <img src="https://media.pitchfork.com/photos/5e5d984ce721440008a6cfeb/2:1/w_3000,h_1500,c_limit/Chuck%20D,%20Flavor%20Flav-GettyImages-175948162.jpg" alt=""></a>
              </div>
               <h3 class="post-title">
                 <a href="#">Do the right thing</a>
               </h3>
               <p class="mb-0">Chuck D</p>
               <p class="small text-gray">Presentación</p>
             </div><!--/.post -->
      </div><!--/.col -->
 
    </div><!--/.row -->

    
<hr class="hr-dark">
    <h3 class="mb-2">Libro recomendado:</h3>
    <div class="card-book-md one-item">
        <div class="cover">
          <a href="#">
            <img src="images/book-lg.jpg" alt="Título del libro" class="img-responsive">
            </a>
          </div><!-- /cover -->
        <div class="description">
            <h3 class="mt-0">
                <a href="#">
                    Después de la utopía. El declive de la fe política
                </a>
            </h3>
            <p>Judith Shklar</p>
            <p class="small text-gray mb-0">2020, <a href="#">Txalaparta</a></p>
            <p class="small"><a href="#">Cómic</a></p>
            <p class="price">22,00€</p>
            <p class="small success">Disponible</p>
        </div><!-- /description -->
        </div>


<div class="row">
  <div class="col-lg-5 col-md-5">
    <?php print render($content['field_image']) ?>
    <p><?php print $node->event_table; ?></p>
    <h4><?php print t("Selección") ?></h4>
    <p><?php print views_embed_view('libros', 'books_related_boletin', $node->nid); ?></p>
  </div>
  <div class="col-lg-7 col-md-7">
    <h1><?php print $node->title ?></h1>
    <p><?php print t("Posted on !date", array('!date' => format_date($node->created, 'custom', 'd/m/Y'))) ?></p>
    <div class="clear"></div>
    <?php print render($content['sharethis']) ?>
    <div class="clear"></div>
    <?php foreach($node->field_boletin_body['und'] as $body): ?>
      <?php $body = field_collection_item_load($body['value']) ?>
       <?php if ($body->field_boletin_body_subtitulo['und'][0]['value']): ?>
    <p><i class="fa fa-2x fa-<?php print $body->field_boletin_body_seccion['und'][0]['value'] ?>"></i> <strong><?php print $body->field_boletin_body_subtitulo['und'][0]['value'] ?></strong></p>
       <?php endif; ?>
    <p><?php print check_markup($body->field_boletin_body_texto['und'][0]['value'], $body->field_boletin_body_texto['und'][0]['format']) ?></p>
    <?php endforeach; ?>
    
    <p><?php print render($content['field_blog_adjunto']) ?></p>
  </div>
</div>