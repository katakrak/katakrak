<?php
/**
 * @file views-isotope-filter-block.tpl.php
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>



<!-- Filters -->
  <div id="filters" class="filters-dropdown"><span id="filter-default-value"></span>
    <div id="isotope-options">
      <ul id="portfolio-filter" class="option-set clearfix" data-option-key="filter">
        <?php
        if (!empty($rows)):
          ?>
          <li class="selected">
            <a class="selected filterbutton" data-option-value="*" href="#filter"><?php print t('All'); ?></a>
          </li>
        <?php endif; ?>
        <?php foreach ($rows as $id => $row): ?>

          <?php
          // remove characters that cause problems with classes
          // this is also do to the isotope elements
          $dataoption = trim(strip_tags(strtolower($row)));
          $dataoption = str_replace(' ', '-', $dataoption);
          $dataoption = str_replace('/', '-', $dataoption);
          $dataoption = str_replace('&amp;', '', $dataoption);
          ?>
          <li>

            <a class="filterbutton" data-option-value=".<?php print $dataoption; ?>" href="#filter"><?php print trim($row); ?></a>
          </li>
        <?php endforeach; ?>

      </ul>  

    </div>
  </div>