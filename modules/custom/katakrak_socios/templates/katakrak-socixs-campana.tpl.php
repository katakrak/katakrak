<div class="d-flex-fullwidth">
  <div class=" col-sm-6 bg-image bg-primary col-flex" style="background-color: #E9297E;">
    <p>
        <img src="/sites/all/themes/kapital/images/socix-claim.jpg" class="img-responsive" title="Hazte socix: O es contigo, o no será">
    </p>
    <div class="embed-responsive embed-responsive-16by9 mt-2 mb-2">
      <iframe class="embed-responsive-item" src="https://www.youtube.com/embed/7RgdIzp-jus"></iframe>
    </div>
    <h1><?php print t("Campaña captación de socixs") ?></h1>
    <h2><?php print t("¿Qué ofrecemos?") ?></h2>
    <p class="lead mt-1"<?php print t(">Sin importar la cuota") ?></p>
    <ul>
      <li><?php print t("Participación en una asamblea anual") ?></li>
      <li><?php print t("Acceso preferente a eventos (filas reservadas a socixs)") ?></li>
      <li><?php print t("Descuentos en cursos de organizados por Katakrak") ?></li>
      <li><?php print t("Un libro de la editorial") ?></li>
      <li><?php print t("Fiestaca mítica de agradecimiento, sea cuando sea.") ?></li>
    </ul>
    <p class="mt-3">
      <a class="btn btn-light-line btn-xs-block" href="#mas-info"><?php print t("Conócenos") ?></a>
    </p>
  </div>
    
  <div class="col-sm-6  col-flex bg-pink-p">
    <ul class="nav nav-secondary mt-2 hidden-xs">
      <li class="active">
        <a href="#socix" aria-controls="home" role="tab" data-toggle="tab"><?php print t("Quiero hacerme socix") ?></a>
      </li>
      <li>
        <a href="#aportacion" aria-controls="home" role="tab" data-toggle="tab"><?php print t("Quiero hacer una aportación puntual") ?></a>
      </li>
    </ul>
      
    <ul class="nav nav-tabs nav-secondary mt-2 visible-xs">  
      <li role="presentation" class="drowpdown">
        <a class="dropdown-toggle" data-toggle="dropdown" href="#" role="button" aria-haspopup="true" aria-expanded="false">
          <span class="caret"></span>
        </a>
          <ul class="dropdown-menu">
            <li>
              <a href="#socix" aria-controls="home" role="tab" data-toggle="tab"><?php print t("hacerme socix") ?></a>
            </li>
            <li>
              <a href="#aportacion" aria-controls="home" role="tab" data-toggle="tab"><?php print t("hacer una aportación puntual") ?></a>
            </li>
          </ul>
      </li>  
    </ul>

    <div class="tab-content">
      <div role="tabpanel" class="tab-pane active" id="socix">
        <!-- <h2>Quiero hacerme socix</h2> -->
        <?php print  $form_signup ?>
      </div><!-- /.tab-pane-->
      <div role="tabpanel" class="tab-pane" id="aportacion">
        <!-- <h2>Quiero hacerme socix</h2> -->
        <?php print  $form_aportacion ?>
      </div><!-- /.tab-pane-->
    </div><!-- /.tab-content -->

    </div>


</div>