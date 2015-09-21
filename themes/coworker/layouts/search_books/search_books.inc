<?php

$plugin = array(
  'title' => t('Search Book layout'),
  'category' => t('Bootstrap'),
  'icon' => 'book-layout.png',
  'theme' => 'search-book-layout',
//  'css' => 'onerowtwocols.css',
  'regions' => array(
    'content_top' => t('Content top'),
    'title' => t('Title'),
    'book_info' => t('Book info'),
    'buttons' => t('Buttons')  
  ),
);