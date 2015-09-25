<?php

/**
 * @file
 * Default theme implementation for displaying a single search result.
 *
 * This template renders a single search result and is collected into
 * search-results.tpl.php. This and the parent template are
 * dependent to one another sharing the markup for definition lists.
 *
 * Available variables:
 * - $url: URL of the result.
 * - $title: Title of the result.
 * - $snippet: A small preview of the result. Does not apply to user searches.
 * - $info: String of all the meta information ready for print. Does not apply
 *   to user searches.
 * - $info_split: Contains same data as $info, split into a keyed array.
 * - $module: The machine-readable name of the module (tab) being searched, such
 *   as "node" or "user".
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Default keys within $info_split:
 * - $info_split['type']: Node type (or item type string supplied by module).
 * - $info_split['user']: Author of the node linked to users profile. Depends
 *   on permission.
 * - $info_split['date']: Last update of the node. Short formatted.
 * - $info_split['comment']: Number of comments output as "% comments", %
 *   being the count. Depends on comment.module.
 *
 * Other variables:
 * - $classes_array: Array of HTML class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $title_attributes_array: Array of HTML attributes for the title. It is
 *   flattened into a string within the variable $title_attributes.
 * - $content_attributes_array: Array of HTML attributes for the content. It is
 *   flattened into a string within the variable $content_attributes.
 *
 * Since $info_split is keyed, a direct print of the item is possible.
 * This array does not apply to user searches so it is recommended to check
 * for its existence before printing. The default keys of 'type', 'user' and
 * 'date' always exist for node searches. Modules may provide other data.
 * @code
 *   <?php if (isset($info_split['comment'])): ?>
 *     <span class="info-comment">
 *       <?php print $info_split['comment']; ?>
 *     </span>
 *   <?php endif; ?>
 * @endcode
 *
 * To check for all available data within $info_split, use the code below.
 * @code
 *   <?php print '<pre>'. check_plain(print_r($info_split, 1)) .'</pre>'; ?>
 * @endcode
 *
 * @see template_preprocess()
 * @see template_preprocess_search_result()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>

<div class="row <?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="row">
    <div class="col-lg-3 col-md-3 col-sm-3 col-xs-8 col-xs-offset-2 col-sm-offset-0">
      <?php print $image ?>
    </div>
    <div class="col-lg-7 col-md-7 col-sm-7 col-xs-8">
      <div class="search-snippet-info">
        <h2 class="title"<?php print $title_attributes; ?>>
          <a href="<?php print $url; ?>?utm_source=search&utm_medium=web&utm_content=titulo&utm_campaign=libros"><?php print $title; ?></a>
        </h2>
        <p>
          <?php print t("Autores"); ?>: 
          <?php foreach($node->autores as $i => $autor): ?>
            <?php print $autor; print $i+1 == count($node->autores) ? '' : ','; ?>
          <?php endforeach; ?>
            
        </p>
        <?php if ($snippet): ?>
          <p class="search-snippet"<?php print $content_attributes; ?>><?php print $snippet; ?></p>
        <?php endif; ?>

      </div>
    </div>  
    <div class="col-lg-2 col-md-2 col-sm-2 col-xs-4 col_book_buy">
      <div class="book-buy">
        <div class="book-price"><?php print $price ?></div>
        <?php print $add_to_cart ?>
      </div>
    </div>
  </div>
</div>
<div class="dotted-divider"></div>
