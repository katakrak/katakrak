<?php if (!empty($title)): ?>
  <h3><?php print $title ?></h3>
<?php endif ?>

<div id="carousel-agenda" class="carousel slide data-ride="carousel" <?php print $classes ?>" <?php print $attributes ?>>
  <?php if ($indicators): ?>
    <!-- Carousel indicators -->
    <ol class="carousel-indicators">
      <?php foreach ($rows as $key => $value): ?>
        <li data-target="#views-bootstrap-carousel-<?php print $id ?>" data-slide-to="<?php print $key ?>" class="<?php if ($key == $first_key) print 'active' ?>"></li>
      <?php endforeach ?>
    </ol>
  <?php endif ?>

  <!-- Carousel items -->
  <div class="carousel-inner">
    <?php foreach ($rows as $key => $row): ?>
      <div class="item <?php if ($key == $first_key) print 'active' ?>">
        <?php print $row ?>
      </div>
    <?php endforeach ?>
  </div>

  <?php if ($navigation): ?>
    <!-- Controls -->
    <a class="left carousel-control" href="#carousel-agenda" role="button" data-slide="prev">
      <img src="/sites/all/themes/kapital/images/angle-left.svg" width="30" height="30" alt="Anterior">
    </a>
    <a class="right carousel-control" href="#carousel-agenda" role="button" data-slide="next">
      <img src="/sites/all/themes/kapital/images/angle-right.svg" width="30" height="30" alt="Siguiente">
    </a>
  <?php endif ?>
</div>
