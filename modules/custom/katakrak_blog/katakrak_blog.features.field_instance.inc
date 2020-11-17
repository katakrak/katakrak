<?php

/**
 * @file
 * katakrak_blog.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function katakrak_blog_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-blog-field_blog_adjunto'.
  $field_instances['node-blog-field_blog_adjunto'] = array(
    'bundle' => 'blog',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'card_book' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'card_book_md' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_table',
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
    'field_name' => 'field_blog_adjunto',
    'label' => 'Adjunto',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => '',
      'file_extensions' => 'txt jpg pdf doc odt docx',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'imce_filefield_on' => 0,
        'insert' => 0,
        'insert_absolute' => FALSE,
        'insert_class' => '',
        'insert_default' => array(
          0 => 'auto',
        ),
        'insert_styles' => array(
          0 => 'auto',
        ),
        'insert_width' => '',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-blog-field_blog_cuerpo'.
  $field_instances['node-blog-field_blog_cuerpo'] = array(
    'bundle' => 'blog',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'card_book' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'card_book_md' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
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
    'field_name' => 'field_blog_cuerpo',
    'label' => 'Cuerpo',
    'required' => 0,
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
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-blog-field_blog_eventos'.
  $field_instances['node-blog-field_blog_eventos'] = array(
    'bundle' => 'blog',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'card_book' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'card_book_md' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
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
    'entityconnect' => array(
      'button' => array(
        'unload_add_button' => NULL,
        'unload_edit_button' => NULL,
      ),
      'icon' => array(
        'show_add_icon' => NULL,
        'show_edit_icon' => NULL,
      ),
    ),
    'field_name' => 'field_blog_eventos',
    'label' => 'Eventos',
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
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-blog-field_blog_libro'.
  $field_instances['node-blog-field_blog_libro'] = array(
    'bundle' => 'blog',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'card_book' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'card_book_md' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(
          'node_reference_view_mode' => 'card_book_md',
        ),
        'type' => 'node_reference_node',
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
    'entityconnect' => array(
      'button' => array(
        'unload_add_button' => 0,
        'unload_edit_button' => 0,
      ),
      'icon' => array(
        'show_add_icon' => NULL,
        'show_edit_icon' => NULL,
      ),
    ),
    'entityconnect_unload_add' => 0,
    'entityconnect_unload_edit' => 0,
    'field_name' => 'field_blog_libro',
    'label' => 'Libro(s)',
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
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-blog-field_blog_type'.
  $field_instances['node-blog-field_blog_type'] = array(
    'bundle' => 'blog',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'card_book' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'card_book_md' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_blog_type',
    'label' => 'Blog_type',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-blog-field_cita'.
  $field_instances['node-blog-field_cita'] = array(
    'bundle' => 'blog',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Para que aparezca en la ficha del libro de la editorial. Usar siempre comillas latinas, si no Dios mata un gatito « »',
    'display' => array(
      'card_book' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'card_book_md' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cita',
    'label' => 'Cita',
    'required' => 0,
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
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'node-blog-field_fuente_cita'.
  $field_instances['node-blog-field_fuente_cita'] = array(
    'bundle' => 'blog',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Por ejemplo: Aritz Gorostiaga, Berria',
    'display' => array(
      'card_book' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'card_book_md' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_fuente_cita',
    'label' => 'Fuente cita',
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
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'node-blog-field_image'.
  $field_instances['node-blog-field_image'] = array(
    'bundle' => 'blog',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'card_book' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'card_book_md' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'colorbox',
        'settings' => array(
          'colorbox_caption' => 'auto',
          'colorbox_caption_custom' => '',
          'colorbox_gallery' => 'post',
          'colorbox_gallery_custom' => '',
          'colorbox_image_style' => 'extra_large',
          'colorbox_multivalue_index' => NULL,
          'colorbox_node_style' => 'blog_post_page',
          'colorbox_node_style_first' => '',
        ),
        'type' => 'colorbox',
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
    'field_name' => 'field_image',
    'label' => 'Imagen',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '1 MB',
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
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-blog-field_media'.
  $field_instances['node-blog-field_media'] = array(
    'bundle' => 'blog',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'card_book' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'card_book_md' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'file_entity',
        'settings' => array(
          'file_view_mode' => 'default',
        ),
        'type' => 'file_rendered',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_media',
    'label' => 'Media',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => '',
      'file_extensions' => 'txt',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'emfield',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'enfield_widget',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-blog-field_tags'.
  $field_instances['node-blog-field_tags'] = array(
    'bundle' => 'blog',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'card_book' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'card_book_md' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tags',
    'label' => 'Etiqueta',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'taxonomy_term-blog_type-field_image'.
  $field_instances['taxonomy_term-blog_type-field_image'] = array(
    'bundle' => 'blog_type',
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
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_image',
    'label' => 'Cabecera blog',
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
      'weight' => 42,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Adjunto');
  t('Blog_type');
  t('Cabecera blog');
  t('Cita');
  t('Cuerpo');
  t('Etiqueta');
  t('Eventos');
  t('Fuente cita');
  t('Imagen');
  t('Libro(s)');
  t('Media');
  t('Para que aparezca en la ficha del libro de la editorial. Usar siempre comillas latinas, si no Dios mata un gatito « »');
  t('Por ejemplo: Aritz Gorostiaga, Berria');

  return $field_instances;
}
