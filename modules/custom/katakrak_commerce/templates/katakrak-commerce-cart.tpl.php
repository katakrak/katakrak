
<div class="dropdown">
  <button class="btn btn-transparent" type="button" id="dropdownMenu2" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
    <i class="fas fa-shopping-cart" aria-hidden="true"></i> <span class="badge badge-pill badge-custom"><?php print $count ?></span> <span class="sr-only">Items en tu cesta</span>
  </button>
  <div class="dropdown-menu dropdown-menu-right" aria-labelledby="dropdownMenu2">
    <div class="dropdown-item">
      <?php print $order; ?>
    </div>
  </div>
</div> 