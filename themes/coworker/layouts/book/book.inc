<?php

$plugin = array(
  'title' => t('Book layout'),
  'category' => t('Bootstrap'),
  'icon' => 'book-layout.png',
  'theme' => 'book-layout',
//  'css' => 'onerowtwocols.css',
  'regions' => array(
    'cover' => t('Cover'),
    'title' => t('Title'),
    'book_info' => t('Book info'),
    'buttons' => t('Buttons')  
  ),
);