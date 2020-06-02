<?php include 'page-header.inc' ?>
<main class="main">
  
<!-- Banner -->
<div class="wrapper-banner">
  <div class="container text-center">
    <div class="row justify-content-md-center">
      <div class="col-sm-6 col-lg-8">
        <img src="/sites/all/themes/kapital/images/bansocix.gif" class="img-fluid" alt="Házte socix">
      </div>
    </div>
  </div>
</div><!--/.banner -->

<?php if ($messages): ?>
  <?php print $messages; ?>
<?php endif; ?>


  <div class="row no-gutters">
    <div class="col-sm-12 col-md-6">
      <div class="box">
        <img src="/sites/all/themes/kapital/images/tienda.jpg" class="img-fluid" alt="">
      </div>
    </div><!--/.col -->
    <div class="col-sm-12 col-md-6">
      <div class="box">
        <img src="/sites/all/themes/kapital/images/espacio.jpg" class="img-fluid" alt="">
      </div>
    </div><!--/.col -->
    <div class="col-sm-4">
      <div class="box">
        <img src="/sites/all/themes/kapital/images/cantina.jpg" class="img-fluid" alt="">
      </div>
    </div><!--/.col -->
    <div class="col-sm-4">
      <div class="box">
          <img src="/sites/all/themes/kapital/images/editorial.jpg" class="img-fluid" alt="">
      </div>
    </div><!--/.col -->
    <div class="col-sm-4">
      <div class="box">
        <img src="/sites/all/themes/kapital/images/agenda.jpg" class="img-fluid" alt="">
      </div>
    </div><!--/.col -->
  </div><!--/.row -->

 

</main><!-- /.main -->

<div class="wrapper-posts">
  <div class="container">
    <h1 class="h1-lg text-center">Ponte al día</h1>
    <p class="text-center">Si quieres recibir estas noticias en tu email, <a href="https://xabiangos.com/katakrak-bs/index.html#">suscríbete aquí</a></p>
      <div class="row mt-4">
        <div class="col-md-4 col-sm-6">
          <div class="post">
           <div class="post-image">
            <a href="https://xabiangos.com/katakrak-bs/index.html#"><img src="/sites/all/themes/kapital/images/tarkovski.jpg" class="img-fluid" alt=""></a>
           </div>
            <h3 class="post-title">
              <a href="https://xabiangos.com/katakrak-bs/index.html#">¡Ya son más de 100! ¡Faltas tú!</a>
            </h3>
            <p class="small">Jueves 28 de mayo</p>
          </div><!--/.post -->
        </div><!--/.col -->
        <div class="col-md-4 col-sm-6">
          <div class="post">
           <div class="post-image">
            <a href="https://xabiangos.com/katakrak-bs/index.html#"><img src="/sites/all/themes/kapital/images/bici.jpg" class="img-fluid" alt=""></a>
           </div>
            <h3 class="post-title">
              <a href="https://xabiangos.com/katakrak-bs/index.html#">Reparto en bici</a>
            </h3>
            <p class="small">Miércoles 27 de mayo</p>
          </div><!--/.post -->
        </div><!--/.col -->
        <div class="col-md-4 col-sm-6">
          <div class="post">
           <div class="post-image">
            <a href="https://xabiangos.com/katakrak-bs/index.html#"><img src="/sites/all/themes/kapital/images/diario.jpg" class="img-fluid" alt=""></a>
           </div>
            <h3 class="post-title">
              <a href="https://xabiangos.com/katakrak-bs/index.html#">«Kapitalismoa eta emakumeen aurkako indarkeria» DIARIO VASCOn</a>
            </h3>
            <p class="small">Domingo 24 de mayo</p>
          </div><!--/.post -->
        </div><!--/.col -->
      </div><!--/.row -->
     <div class="text-center mt-3">
      <button class="btn btn-secondary">Ver más posts</button>
     </div>
  </div><!--/.container -->
</div><!--/.wrapper-posts -->
<?php print render($page['content']); ?>
<?php include 'page-footer.inc' ?>
