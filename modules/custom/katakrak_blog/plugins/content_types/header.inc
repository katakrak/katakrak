<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Blog header'),
  'icon' => 'icon_term.png',
  'description' => t('Blog header.'),
  'required context' => new ctools_context_required(t('Term'), array('term', 'taxonomy_term')),
  'category' => t('Blog'),
  'defaults' => array(
    'link' => TRUE,
    'markup' => 'none',
    'id' => '',
    'class' => '',
  ),
);


/**
 * Render the custom content type.
 */
function katakrak_blog_header_content_type_render($subtype, $conf, $panel_args, $context) {
  if (empty($context) || empty($context->data)) {
    return;
  }

  // Get a shortcut to the term.
  $term = i18n_taxonomy_localize_terms($context->data);

  // Load the vocabulary.
  $vocab = taxonomy_vocabulary_load($term->vid);

  // Generate the title
  
  // Build any surrounding markup if so configured
  if (isset($conf['markup']) && $conf['markup'] != 'none') {
    $markup = theme('image',  array('path' => $term->field_image['und'][0]['uri']));
    $markup .= '<' . $conf['markup'];
    if (!empty($conf['id'])) {
      $markup .= ' id="' . $conf['id'] . '"';
    }
    if (!empty($conf['class'])) {
      $markup .= ' class="' . $conf['class'] . '"';
    }
    $markup .= '>' . $term->name . '</' . $conf['markup'] . '>' . "\n";
  }
  $content = !empty($conf['link']) ? l($markup, 'taxonomy/term/' . $term->tid, array('html' => TRUE)) : check_plain($term->name);

  // Build the content type block.
  $block = new stdClass();
  $block->module  = 'katakrak_blog_header';
  $block->title   = t('Header');
  $block->content = $content;
  $block->delta   = $term->tid;

  return $block;
}

/**
 * Returns an edit form for custom type settings.
 */
function katakrak_blog_header_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['markup'] = array(
    '#title' => t('Title tag'),
    '#type' => 'select',
    '#options' => array(
      'none' => t('- No tag -'),
      'h1' => t('h1'),
      'h2' => t('h2'),
      'h3' => t('h3'),
      'h4' => t('h4'),
      'h5' => t('h5'),
      'h6' => t('h6'),
      'div' => t('div'),
    ),
    '#default_value' => $conf['markup'],
  );

  $form['id'] = array(
    '#title' => t('CSS id to use'),
    '#type' => 'textfield',
    '#default_value' => $conf['id'],
  );

  $form['class'] = array(
    '#title' => t('CSS class to use'),
    '#type' => 'textfield',
    '#default_value' => $conf['class'],
  );

  $form['link'] = array(
    '#title' => t('Link to term'),
    '#type' => 'checkbox',
    '#default_value' => $conf['link'],
    '#description' => t('Check here to make the name link to the term page.'),
  );
  return $form;
}

/**
 * Submit handler for the custom type settings form.
 */
function katakrak_blog_header_content_type_edit_form_submit($form, &$form_state) {
  // Copy everything from our defaults.
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 * Returns the administrative title for a type.
 */
function katakrak_blog_header_content_type_admin_title($subtype, $conf, $context) {
  return t('Blog header');
}
