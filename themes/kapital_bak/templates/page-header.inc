<nav class="navbar-secondary">
  <ul class="list-inline mb-0">
    <li class="list-inline-item">
      <a href="mailto:info@katakrak.net" target="_blank"> <i class="far fa-envelope " aria-hidden="true"></i> <span class="d-none d-sm-inline-block">info@katakrak.net</span></a>
    </li>
    <li class="list-inline-item">
      <a href="tel:+34948225520" target="_blank"><i class="fas fa-phone" aria-hidden="true"></i> <span class="d-none d-sm-inline-block">948 225 520</span></a> 
    </li>
    <li class="list-inline-item">
      <a href="https://xabiangos.com/katakrak-bs/index.html#" target="_blank"><i class="fas fa-location-arrow" aria-hidden="true"></i> <span class="d-none d-sm-inline-block">¿Dónde estamos?</span></a> 
    </li>
    <li class="list-inline-item d-none d-sm-inline-block">
      <div class="dropdown ">
        <a class="dropdown-toggle" href="" role="button" id="dropdownIdioma" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
          <i class="fas fa-globe-africa small d-none d-sm-inline-block" aria-hidden="true"></i> <?php print $active_lang; dpm($language) ?>
        </a>
        <div class="dropdown-menu dropdown-menu-right" aria-labelledby="dropdownIdioma">
          <a class="dropdown-item active" href="https://xabiangos.com/katakrak-bs/index.html#">Cas</a>
          <a class="dropdown-item" href="https://xabiangos.com/katakrak-bs/index.html#">Eus</a>
        </div>
      </div>
    </li>
  </ul>
</nav>


<nav class="navbar navbar-expand-lg navbar-light navbar-custom">
  <a class="navbar-brand" href="poner-enlace-home">
    <img src="<?php print $logo ?>" alt="Katakrak Liburuak" class="logo-main d-inline-block d-sm-none" loading="lazy">
    <img src="<?php print $logo ?>" alt="Katakrak Liburuak" class="logo-main d-none d-sm-inline-block" loading="lazy">
  </a>
  <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#NavbarMain" aria-controls="NavbarMain" aria-expanded="false" aria-label="Toggle navigation">
    <!-- <span class="navbar-toggler-icon"></span> -->
    <i class="fas fa-bars" aria-hidden="true"></i>
  </button>



  <div class="collapse navbar-collapse" id="NavbarMain">

    <ul class="navbar-nav navbar-centered">
      <li class="nav-item">
        <a class="nav-link" href="https://xabiangos.com/katakrak-bs/tienda.html">Tienda online</a>
      </li>
      <li class="nav-item">
        <a class="nav-link" href="https://xabiangos.com/katakrak-bs/el-espacio.html">El espacio</a> 
      </li> 
      <li class="nav-item">
        <a class="nav-link" href="https://xabiangos.com/katakrak-bs/la-editorial.html">La editorial</a> 
      </li>
      <li class="nav-item">
        <a class="nav-link" href="https://xabiangos.com/katakrak-bs/agenda.html">Agenda</a> 
      </li>
      <li class="nav-item">
        <a class="nav-link" href="https://xabiangos.com/katakrak-bs/agenda.html">Blog</a> 
      </li>
      <li class="nav-item d-inline-block d-sm-none">
        <div class="dropdown ">
          <a class="dropdown-toggle" href="https://xabiangos.com/katakrak-bs/index.html#" role="button" id="dropdownIdioma" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
            <i class="fas fa-globe-africa small d-none d-sm-inline-block" aria-hidden="true"></i> Cas
          </a>
          <div class="dropdown-menu dropdown-menu-right" aria-labelledby="dropdownIdioma">
            <a class="dropdown-item active" href="https://xabiangos.com/katakrak-bs/index.html#">Cas</a>
            <a class="dropdown-item" href="https://xabiangos.com/katakrak-bs/index.html#">Eus</a>
          </div>
        </div>
      </li>
    </ul>
  </div> <!-- /navbar-collapse-->

  <!-- Visible items xs -->
  <div class="navbar-xs-items d-flex">
    <button class="btn btn-transparent">
      <i class="fas fa-user-circle" aria-hidden="true"></i> <span class="d-none d-sm-inline-block">Mi cuenta</span>
    </button>


    <div class="dropdown">
      <button class="btn btn-transparent" type="button" id="dropdownMenu2" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
        <i class="fas fa-shopping-cart" aria-hidden="true"></i> <span class="badge badge-pill badge-custom">1</span> <span class="sr-only">Items en tu cesta</span>
      </button>
      <div class="dropdown-menu dropdown-menu-right" aria-labelledby="dropdownMenu2">
        <div class="dropdown-item">
          bla bla bla
        </div>
      </div>
    </div> 
  </div>
</nav>