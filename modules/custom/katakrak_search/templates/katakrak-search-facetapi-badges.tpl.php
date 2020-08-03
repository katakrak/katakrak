<ul class="list-inline mb-0">
    <li><?php print t("<strong>!count</strong> resultados", array('!count' => $num_results)) ?></li>
    <?php foreach ($badges as $badge): ?>
    <li>
      <span class="badge"><?php print $badge['term']->name ?> <?php print $badge['link']?></span>
    </li>
    <?php endforeach; ?>
    
</ul>