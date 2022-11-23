<ul class="steps">
  <?php foreach ($steps as $i => $step): ?>
  <li class="steps-item <?php print $step['class'] ?>">
    <span class="number"><?php print $i+1 ?></span> <?php print $step['title'] ?>
  </li>
  <?php if (count($steps) -1 > $i): ?>
  <li class="steps-item item-arrow hidden-xs">
    <i class="fas fa-chevron-right"></i>
  </li>
  <?php endif; ?>
 <?php endforeach; ?>
</ul>