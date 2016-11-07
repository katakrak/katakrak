<?php
/**
 * @file
 * katakrak_editorial.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function katakrak_editorial_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-autor_ed-body'.
  $field_instances['node-autor_ed-body'] = array(
    'bundle' => 'autor_ed',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Biografía',
    'required' => 1,
    'settings' => array(
      'display_summary' => 1,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-autor_ed-field_autor_nacimiento'.
  $field_instances['node-autor_ed-field_autor_nacimiento'] = array(
    'bundle' => 'autor_ed',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_autor_nacimiento',
    'label' => 'Fecha y lugar nacimiento',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-autor_ed-field_imagen'.
  $field_instances['node-autor_ed-field_imagen'] = array(
    'bundle' => 'autor_ed',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_imagen',
    'label' => 'Foto',
    'required' => 1,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'autores',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'imce_filefield_on' => 0,
        'insert' => 0,
        'insert_absolute' => 0,
        'insert_class' => '',
        'insert_default' => 'auto',
        'insert_styles' => array(
          'auto' => 'auto',
          'colorbox__app_book_thumbnail' => 0,
          'colorbox__app_evento' => 0,
          'colorbox__app_evento_thumbnail' => 0,
          'colorbox__blog_home' => 0,
          'colorbox__blog_post_page' => 0,
          'colorbox__boletin_destacado' => 0,
          'colorbox__book_cover' => 0,
          'colorbox__book_irakurle_taldea' => 0,
          'colorbox__book_medium' => 0,
          'colorbox__book_thumbnail' => 0,
          'colorbox__cover_home' => 0,
          'colorbox__event_ciclos' => 0,
          'colorbox__event_highlight' => 0,
          'colorbox__event_home' => 0,
          'colorbox__event_node_view' => 0,
          'colorbox__event_teaser' => 0,
          'colorbox__event_thumbnail' => 0,
          'colorbox__extra_large' => 0,
          'colorbox__flexslider_full' => 0,
          'colorbox__flexslider_thumbnail' => 0,
          'colorbox__home_agenda' => 0,
          'colorbox__home_agenda_main' => 0,
          'colorbox__home_agenda_main_secondary' => 0,
          'colorbox__home_promo' => 0,
          'colorbox__kantina_large' => 0,
          'colorbox__kantina_medium' => 0,
          'colorbox__kantina_thumbnail' => 0,
          'colorbox__large' => 0,
          'colorbox__media_thumbnail' => 0,
          'colorbox__medium' => 0,
          'colorbox__portfolio' => 0,
          'colorbox__portfolio_item' => 0,
          'colorbox__receta_page' => 0,
          'colorbox__search_result_cover' => 0,
          'colorbox__seccion' => 0,
          'colorbox__thumbnail' => 0,
          'icon_link' => 0,
          'image' => 0,
          'image_app_book_thumbnail' => 0,
          'image_app_evento' => 0,
          'image_app_evento_thumbnail' => 0,
          'image_blog_home' => 0,
          'image_blog_post_page' => 0,
          'image_boletin_destacado' => 0,
          'image_book_cover' => 0,
          'image_book_irakurle_taldea' => 0,
          'image_book_medium' => 0,
          'image_book_thumbnail' => 0,
          'image_cover_home' => 0,
          'image_event_ciclos' => 0,
          'image_event_highlight' => 0,
          'image_event_home' => 0,
          'image_event_node_view' => 0,
          'image_event_teaser' => 0,
          'image_event_thumbnail' => 0,
          'image_extra_large' => 0,
          'image_flexslider_full' => 0,
          'image_flexslider_thumbnail' => 0,
          'image_home_agenda' => 0,
          'image_home_agenda_main' => 0,
          'image_home_agenda_main_secondary' => 0,
          'image_home_promo' => 0,
          'image_kantina_large' => 0,
          'image_kantina_medium' => 0,
          'image_kantina_thumbnail' => 0,
          'image_large' => 0,
          'image_media_thumbnail' => 0,
          'image_medium' => 0,
          'image_portfolio' => 0,
          'image_portfolio_item' => 0,
          'image_receta_page' => 0,
          'image_search_result_cover' => 0,
          'image_seccion' => 0,
          'image_thumbnail' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-libro_ed-field_editorial_libro'.
  $field_instances['node-libro_ed-field_editorial_libro'] = array(
    'bundle' => 'libro_ed',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Esto es para linkar la ficha de la editorial a la ficha que viene de geslib, sobre todo bueno para la venta on-line',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'entityconnect_show_add_icon' => 0,
    'entityconnect_show_edit_icon' => 0,
    'entityconnect_unload_add' => 1,
    'entityconnect_unload_edit' => 1,
    'field_name' => 'field_editorial_libro',
    'label' => 'Libro',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'node_reference',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'autocomplete_path' => 'node_reference/autocomplete',
        'size' => 60,
      ),
      'type' => 'node_reference_autocomplete',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-libro_ed-field_libro_ed_autor'.
  $field_instances['node-libro_ed-field_libro_ed_autor'] = array(
    'bundle' => 'libro_ed',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'entityconnect_show_add_icon' => 1,
    'entityconnect_show_edit_icon' => 0,
    'entityconnect_unload_add' => 0,
    'entityconnect_unload_edit' => 0,
    'field_name' => 'field_libro_ed_autor',
    'label' => 'Autor',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'node_reference',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'autocomplete_path' => 'node_reference/autocomplete',
        'size' => 60,
      ),
      'type' => 'node_reference_autocomplete',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-libro_ed-field_libro_idioma'.
  $field_instances['node-libro_ed-field_libro_idioma'] = array(
    'bundle' => 'libro_ed',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_libro_idioma',
    'label' => 'Idioma',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-libro_ed-field_libro_isbn'.
  $field_instances['node-libro_ed-field_libro_isbn'] = array(
    'bundle' => 'libro_ed',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_libro_isbn',
    'label' => 'Isbn',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-libro_ed-field_libro_paginas'.
  $field_instances['node-libro_ed-field_libro_paginas'] = array(
    'bundle' => 'libro_ed',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_libro_paginas',
    'label' => 'Páginas',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-libro_ed-field_libro_portada'.
  $field_instances['node-libro_ed-field_libro_portada'] = array(
    'bundle' => 'libro_ed',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'colorbox',
        'settings' => array(
          'colorbox_caption' => 'auto',
          'colorbox_caption_custom' => '',
          'colorbox_gallery' => 'post',
          'colorbox_gallery_custom' => '',
          'colorbox_image_style' => '',
          'colorbox_multivalue_index' => NULL,
          'colorbox_node_style' => 'book_cover',
          'colorbox_node_style_first' => '',
        ),
        'type' => 'colorbox',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_libro_portada',
    'label' => 'Portada',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'imce_filefield_on' => 0,
        'insert' => 0,
        'insert_absolute' => 0,
        'insert_class' => '',
        'insert_default' => 'auto',
        'insert_styles' => array(
          'auto' => 'auto',
          'colorbox__app_book_thumbnail' => 0,
          'colorbox__app_evento' => 0,
          'colorbox__app_evento_thumbnail' => 0,
          'colorbox__blog_home' => 0,
          'colorbox__blog_post_page' => 0,
          'colorbox__boletin_destacado' => 0,
          'colorbox__book_cover' => 0,
          'colorbox__book_irakurle_taldea' => 0,
          'colorbox__book_medium' => 0,
          'colorbox__book_thumbnail' => 0,
          'colorbox__cover_home' => 0,
          'colorbox__event_ciclos' => 0,
          'colorbox__event_highlight' => 0,
          'colorbox__event_home' => 0,
          'colorbox__event_node_view' => 0,
          'colorbox__event_teaser' => 0,
          'colorbox__event_thumbnail' => 0,
          'colorbox__extra_large' => 0,
          'colorbox__flexslider_full' => 0,
          'colorbox__flexslider_thumbnail' => 0,
          'colorbox__home_agenda' => 0,
          'colorbox__home_agenda_main' => 0,
          'colorbox__home_agenda_main_secondary' => 0,
          'colorbox__home_promo' => 0,
          'colorbox__kantina_large' => 0,
          'colorbox__kantina_medium' => 0,
          'colorbox__kantina_thumbnail' => 0,
          'colorbox__large' => 0,
          'colorbox__media_thumbnail' => 0,
          'colorbox__medium' => 0,
          'colorbox__portfolio' => 0,
          'colorbox__portfolio_item' => 0,
          'colorbox__receta_page' => 0,
          'colorbox__search_result_cover' => 0,
          'colorbox__seccion' => 0,
          'colorbox__thumbnail' => 0,
          'icon_link' => 0,
          'image' => 0,
          'image_app_book_thumbnail' => 0,
          'image_app_evento' => 0,
          'image_app_evento_thumbnail' => 0,
          'image_blog_home' => 0,
          'image_blog_post_page' => 0,
          'image_boletin_destacado' => 0,
          'image_book_cover' => 0,
          'image_book_irakurle_taldea' => 0,
          'image_book_medium' => 0,
          'image_book_thumbnail' => 0,
          'image_cover_home' => 0,
          'image_event_ciclos' => 0,
          'image_event_highlight' => 0,
          'image_event_home' => 0,
          'image_event_node_view' => 0,
          'image_event_teaser' => 0,
          'image_event_thumbnail' => 0,
          'image_extra_large' => 0,
          'image_flexslider_full' => 0,
          'image_flexslider_thumbnail' => 0,
          'image_home_agenda' => 0,
          'image_home_agenda_main' => 0,
          'image_home_agenda_main_secondary' => 0,
          'image_home_promo' => 0,
          'image_kantina_large' => 0,
          'image_kantina_medium' => 0,
          'image_kantina_thumbnail' => 0,
          'image_large' => 0,
          'image_media_thumbnail' => 0,
          'image_medium' => 0,
          'image_portfolio' => 0,
          'image_portfolio_item' => 0,
          'image_receta_page' => 0,
          'image_search_result_cover' => 0,
          'image_seccion' => 0,
          'image_thumbnail' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-libro_ed-field_libro_sinopsis'.
  $field_instances['node-libro_ed-field_libro_sinopsis'] = array(
    'bundle' => 'libro_ed',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_libro_sinopsis',
    'label' => 'Sinopsis',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-libro_ed-field_libro_subtitulo'.
  $field_instances['node-libro_ed-field_libro_subtitulo'] = array(
    'bundle' => 'libro_ed',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_libro_subtitulo',
    'label' => 'Subtitulo',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Autor');
  t('Biografía');
  t('Esto es para linkar la ficha de la editorial a la ficha que viene de geslib, sobre todo bueno para la venta on-line');
  t('Fecha y lugar nacimiento');
  t('Foto');
  t('Idioma');
  t('Isbn');
  t('Libro');
  t('Portada');
  t('Páginas');
  t('Sinopsis');
  t('Subtitulo');

  return $field_instances;
}
