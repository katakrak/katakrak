<ol class="breadcrumb">
  <?php foreach ($links as $link): ?>
    <li <?php $link['active'] ? 'class="active"': ''?>><?php print $link['link'] ?></li>
  <?php endforeach; ?>
</ol>