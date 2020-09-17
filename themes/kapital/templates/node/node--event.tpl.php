<p>
  <a href="<?php print url('agenda') ?>" class="btn btn-transparent"> <i class="fas fa-arrow-left small"></i><?php print t('Listado de eventos') ?></a>
</p>

    <div class="row mt-2">
        <div class="col-sm-3">
            <img src="https://janettebeckman.com/wordpress/wp-content/uploads/2016/05/Chuck-D-851x1000.jpg" class="img-responsive img-shadow">
            <p class="mt-2">
                <a class="btn btn-secondary">
                    <i class="fas fa-search-plus"></i> Ampliar imagen
                </a>
            </p>
        </div><!-- /.col-->
        <div class="col-sm-9">
          <div class="d-flex">
          <?php print theme('agenda_date', array('time' => $node->field_event_date['und'][0]['value'])); ?>
            <div>
              <h1 class="mt-0"><?php print $node->title ?></h1>
              <p class="mb-0">Chuck D</p>
              <p class="small text-gray"><?php print render($content['field_event_type']) ?></p>
            </div>
          </div>
          <hr>
          <ul class="list-inline">
            <li>Escúchalo:</li>
            <li>
                <a class="btn btn-secondary" href="#"><i class="fab fa-soundcloud mr-1" title="Soundcloud de Katakrak"> </i>Charla parte1</a>
            </li>
            <li>
                <a class="btn btn-secondary" href="#"><i class="fab fa-soundcloud mr-1" title="Soundcloud de Katakrak"> </i>Charla parte 2</a>
            </li>
        </ul>
        <hr>
           <?php print render($content['field_event_description']) ?>
        <hr>
        <ul class="list-inline list-tags">
            <li>
                <a href="#"><span class="badge">ChuckD</span></a>
            </li>
            <li>
                <a href="#"><span class="badge">ChuckD</span></a>
            </li>
        </ul>
        </div><!-- /.col-->
        


    </div><!-- /.row -->
<hr class="hr-dark">
    <h3 class="mb-2">Libro recomendado:</h3>
    <div class="card-book-md">
        <div class="cover">
          <a href="#">
            <img src="https://katakrak.net/sites/default/files/styles/cover_home/public/portadas/978-84-9027-980-9.jpg?itok=d0S5jnJL" alt="Título del libro" class="img-responsive">
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
