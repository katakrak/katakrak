<?php

$plugin = array(
  'title' => t('Blog layout'),
  'category' => t('Bootstrap'),
  'icon' => 'blog-layout.png',
  'theme' => 'blog-layout',
//  'css' => 'onerowtwocols.css',
  'regions' => array(
    'header' => t("Header"),
    'right' => t('Right side'),
    'left' => t('Left side')
  ),
);