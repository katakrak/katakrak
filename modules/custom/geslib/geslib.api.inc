<?php

/**
 * @file
 * Define how to interact with geslib files
 * Info: http://www.unleashed-technologies.com/blog/2010/07/16/drupal-6-inserting-updating-nodes-programmatically
 */

include_once dirname(__FILE__) . '/lib/Encoding.php';
include_once dirname(__FILE__) . '/lib/GeslibReader.php';
include_once dirname(__FILE__) . '/lib/InetBookSearch.php';
include_once dirname(__FILE__) . '/lib/DilveSearch.php';

class geslib_api {

  private $geslib_files;
  private $geslib_filename;
  private $elements;

  /**
  * @param $geslib_filename
  *	Geslib export file 
  */
  function __construct($geslib_filepath, $verbose_level) {
    $this->user = user_load(array('uid' => 1));
    $this->default_nom_category = $this->utf8_encode(variable_get('geslib_category_default_name', NULL));
    $this->default_nom_collection = $this->utf8_encode(variable_get('geslib_collection_default_name', NULL));
    $this->verbose_level = $verbose_level;
    $this->geslib_files = $this->select_geslib_files($geslib_filepath);
    # Check if covers upload path is writable 
    $covers_path = file_directory_path()."/book_covers";
    if ( !file_check_directory($covers_path, FILE_CREATE_DIRECTORY) ) {
      throw new Exception('No rights to write in book covers path ('. $covers_path . ')' );
    }
    # Initialize Dilve access
    if ( variable_get('geslib_book_download_info', NULL) == "5" ) {
      DilveSearch::set_user(variable_get('geslib_dilve_user', NULL));
      DilveSearch::set_pass(variable_get('geslib_dilve_pass', NULL));
    }
  }

  /**
  * @param $path
  *   Path of geslib files or file path
  *
  * returns (array)
  *   geslib files to be readed
  */
  function select_geslib_files($path) {
    $geslib_files = array();
    if (is_dir($path)) {
      $dir_array = array();
      $handle = opendir($path);
      while (false !== ($file = readdir($handle))) {
        # Get only INTER(ddd) files
        if (preg_match('/^INTER(\d)+$/', $file)) {
            $geslib_files[] = $path."/".$file;
        }
      }
      closedir($handle);
    } else {
      $geslib_files[] = $path;
    }

    return $geslib_files;
  }

  /**
  * Get files to import
  */
  function get_pending_files() {
    $files = array();
    foreach($this->geslib_files as $file) {
      $query = 'SELECT id FROM {geslib_log} WHERE component = "geslib_file" AND imported_file = "%s" AND (status = "ok" OR status ="working")';
      $result = db_query($query, basename($file));
      if (!$result || !db_fetch_object($result)) {
        $files[] = $file;
      } else {
        $this->vprint(t("Excluded previously imported file") . " " . $file,1);
      }
    }
    sort($files);
    return $files;
  }

  /**
  * Import all elements 
  */
  function import_elements() {
    # Write action in log table
    $start_date = date('Y-m-d H:i:s');
    $log_import = array('start_date' => date('Y-m-d H:i:s'), 'component' => 'geslib_file', 'imported_file' => basename($this->geslib_filename), 'uid' => $this->user->uid, 'status' => 'working');
    drupal_write_record('geslib_log', $log_import);

    # For each element type process imported information if not null and drupal_node_type exists
    $items = array('category','publisher','music_publisher','author','collection','publisher_reference','library_reference','index');
    foreach ($items as $item) {
      $query = 'SELECT id FROM {geslib_log} WHERE component = "%s" AND imported_file = "%s" AND (status = "ok" OR status ="working")';
      $result = db_query($query, $item, basename($this->geslib_filename));
      if ( (!$result || !db_fetch_object($result)) && ($node_type = variable_get('geslib_'.$item.'_node_type', NULL)) && $this->elements[$item]) {
        $log_element = array('start_date' => date('Y-m-d H:i:s'), 'component' => $item, 'imported_file' => basename($this->geslib_filename), 'uid' => $this->user->uid, 'status' => 'ok');
        if ($item == "category") {
          $this->process_element($this->elements[$item], $item, $node_type, true);
        } else {
          $this->process_element($this->elements[$item], $item, $node_type, false);
        }
        $this->flush_cache();
        $log_element['count'] = count($this->elements[$item]);
        $log_element['end_date'] = date('Y-m-d H:i:s');
        drupal_write_record('geslib_log', $log_element);
      }
    }

    # And books
    $query = 'SELECT id FROM {geslib_log} WHERE component = "%s" AND imported_file = "%s" AND (status = "ok" OR status ="working")';
    $result = db_query($query, 'product', basename($this->geslib_filename));
    if ( (!$result || !db_fetch_object($result)) && $this->elements["product"] && (variable_get('geslib_book_node_type', NULL) || variable_get('geslib_other_node_type', NULL)) ) {
      $log_element = array('start_date' => date('Y-m-d H:i:s'), 'component' => 'product', 'imported_file' => basename($this->geslib_filename), 'uid' => $this->user->uid, 'status' => 'ok');
      $this->process_products($this->elements["product"], "product");
      $this->flush_cache();
      $log_element['count'] = count($this->elements["product"]);
      $log_element['end_date'] = date('Y-m-d H:i:s');
      drupal_write_record('geslib_log', $log_element);
      #$log_element['component'] = 'covers';
      #drupal_write_record('geslib_log', $log_element);
    }


    # Write finishing data into import table
    #$log_import = array('start_date' => $start_date, 'end_date' => date('Y-m-d H:i:s'), 'element' => 'geslib_file', 'imported_file' => basename($this->geslib_filename), 'uid' => $this->user->uid, 'status' => 'ok');
    $log_import['end_date'] = date('Y-m-d H:i:s');
    $log_import['status'] = 'ok';
    drupal_write_record('geslib_log', $log_import, 'id');
    # Delete geslib file
    if ( variable_get('geslib_delete_imported_files', NULL) ) {
      unlink($this->geslib_filename);
    }
  }

  function import_covers() {
    $query = 'SELECT id FROM {geslib_log} WHERE component = "%s" AND imported_file = "%s" AND (status = "ok" OR status ="working")';
    $result = db_query($query, 'covers', basename($this->geslib_filename));
    if ( (!$result || !db_fetch_object($result)) && $this->elements["product"] && (variable_get('geslib_book_node_type', NULL) || variable_get('geslib_other_node_type', NULL)) ) {
      $log_element = array('start_date' => date('Y-m-d H:i:s'), 'component' => 'covers', 'imported_file' => basename($this->geslib_filename), 'uid' => $this->user->uid, 'status' => 'ok');
      $log_element['count'] = $this->process_covers($this->elements["product"], "product");
      $this->flush_cache();
      $log_element['end_date'] = date('Y-m-d H:i:s');
      drupal_write_record('geslib_log', $log_element);
    }
  }

  /**
  * Flush all caches
  */
  function flush_cache() {
    $this->vprint("\n---------------------- ".t("Flush all caches")."\n",2);
    drupal_flush_all_caches();
  }

  /**
  * Output node data 
  */ 
  function output_node_data($node_id) {
    $tmp_node = node_load($node_id);
    print_r ($tmp_node);
    exit;
  }

  /**
  * Get data from internet
  *
  * @param &object
  *   reference to a book element
  */
  function preprocess_book_data() {
    $this->vprint(t("Searching external book data"),1);

    $geslib_book_type = variable_get('geslib_book_geslib_type', NULL);
    # Loop all products
    $elements = $this->elements["product"];
    foreach ($elements as $object_id => $object) {
      # Only for books that will not be deleted
      if ( $object["type"] == $geslib_book_type && $object["action"] != "B") {
        $this->get_internet_book_data($object_id);
      }
    }
    $elements = NULL;
    $this->vprint(" ",1);
  }

  /**
  * Get book data from internet
  *
  * @param $object_id
  *   book element id
  */
  function get_internet_book_data($object_id) {
    $inet_search_type = variable_get('geslib_book_download_info', NULL);
    $ean = $this->elements["product"][$object_id]["attribute"]["ean"];
    $needed_author = (variable_get('geslib_book_create_fake_author', NULL) == 2 || sizeof($this->elements["product"][$object_id]["*author"]) == 0) &&
                     sizeof($this->elements["product"][$object_id]["relation"]["author"]) == 0;
    $needed_description = variable_get('geslib_book_body_from', NULL) &&
                          sizeof($this->elements["product"][$object_id]["relation"][variable_get('geslib_book_body_from', NULL)]) == 0;

    # Only search book if no geslib data available
    if ( $ean && ( $inet_search_type || ( $inet_search_type == "2" && ( $needed_description || $needed_author ) ) ) ) {
      $inet_data = array();
      $this->vprint(t("Searching")." '".$this->elements["product"][$object_id]["title"]."' (EAN: ".$ean.")",2);

      # Search for EAN code by priority
      if ($inet_search_type == "5") {
        $inet_data = DilveSearch::search($ean);
      }
      if ($inet_search_type == "1" || $inet_search_type == "2" || $inet_data["*cover_url"] == NULL || 
           ( $inet_data["*author"] == NULL && $needed_author ) ||
           ( $inet_data["*description"] == NULL && $needed_description ) ) {
        $tmp_data = InetBookSearch::search_ttl($ean);
        if ($inet_search_type == "5" && $tmp_data["*cover_url"]) {
          unset($tmp_data["*cover_url"]);
        }
        # Mixes both downloaded data
        if (count($inet_data["*author"]) == 1 && count($tmp_data["*author"]) == 1 && !$inet_data["*author"][0]["description"] && $tmp_data["*author"][0]["description"]) {
          $inet_data["*author"][0]["description"] = $tmp_data["*author"][0]["description"];
        }
        foreach ($tmp_data as $key => $value) {
          if ( ! $inet_data[$key] ) {
            $inet_data[$key] = $value;
          }
        }
      }
      if ( ($inet_search_type != "2" && $inet_data["*cover_url"] == NULL) ||
           ( $inet_data["*description"] == NULL && $needed_description ) ) {
        $tmp_data = InetBookSearch::search_google($ean);
        foreach ($tmp_data as $key => $value) {
          if ( ! $inet_data[$key] ) {
            $inet_data[$key] = $value;
          }
        }
      }

      #print_r($inet_data);

      # Import title
      if ( $inet_data["*title"] && $this->elements["product"][$object_id]["title"] == NULL ) {
        $this->elements["product"][$object_id]["title"] = $inet_data["*title"];
        $this->vprint(t("Loaded title"));
      }
      # Import subtitle
      if ( $inet_data["*subtitle"] && $this->elements["product"][$object_id]["attribute"]["subtitle"] == NULL ) {
        $this->elements["product"][$object_id]["attribute"]["subtitle"] = $inet_data["*subtitle"];
        $this->vprint(t("Loaded subtitle"));
      }
      # Import description
      if ( $inet_data["*description"] && $needed_description ) {
        if ( variable_get('geslib_book_body_from', NULL) == "external_description" ) {
          $this->elements["product"][$object_id]["body"] = $inet_data["*description"];
        } else {
          $this->elements[variable_get('geslib_book_body_from', NULL)][$object_id . "_1"]["title"] = $inet_data["*description"];
          $this->elements[variable_get('geslib_book_body_from', NULL)][$object_id . "_1"]["body"] = $inet_data["*description"];
          $this->elements[variable_get('geslib_book_body_from', NULL)][$object_id . "_1"]["*title_from_related_book"] = $object_id;
          $this->elements["product"][$object_id]["relation"][variable_get('geslib_book_body_from', NULL)][] = array("gid" => $object_id . "_1");
        }
        $this->vprint(t("Loaded book description"));
        #print_r($this->elements[variable_get('geslib_book_body_from', NULL)][$object_id . "_1"]);
      }
      # Import measurements
      if ( $inet_data["*weight"] && $this->elements["product"][$object_id]["uc_product"]["weight"] == "" ) {
        $this->elements["product"][$object_id]["uc_product"]["weight"] = $inet_data["*weight"]["value"];
        $this->elements["product"][$object_id]["*weight_unit"] = $inet_data["*weight"]["unit"];
      }
      if ( $inet_data["*width"] && $this->elements["product"][$object_id]["uc_product"]["width"] == "" ) {
        $this->elements["product"][$object_id]["uc_product"]["width"] = $inet_data["*width"]["value"];
        $this->elements["product"][$object_id]["*width_unit"] = $inet_data["*width"]["unit"];
      }
      if ( $inet_data["*length"] && $this->elements["product"][$object_id]["uc_product"]["length"] == "" ) {
        $this->elements["product"][$object_id]["uc_product"]["length"] = $inet_data["*length"]["value"];
        $this->elements["product"][$object_id]["*length_unit"] = $inet_data["*length"]["unit"];
      }
      if ( $inet_data["*pages"] && $this->elements["product"][$object_id]["attribute"]["pages"] == "" ) {
        $this->elements["product"][$object_id]["attribute"]["pages"] = $inet_data["*pages"];
      }
      if ( $inet_data["*format"] && $this->elements["product"][$object_id]["attribute"]["format"] == "" ) {
        $this->elements["product"][$object_id]["attribute"]["format"] = $inet_data["*format"];
      }
      if ( $inet_data["*edition_date"] && $this->elements["product"][$object_id]["attribute"]["edition_date"] == "" ) {
        $this->elements["product"][$object_id]["attribute"]["edition_date"] = $inet_data["*edition_date"];
      }

      # Import cover
      if ($inet_data["*cover_url"] && $inet_search_type != "2") {
        $this->elements["product"][$object_id]["*cover_url"] = $inet_data["*cover_url"];
        $this->vprint(t("Loaded book cover URL"));
      }

      # Import preview file
      if ($inet_data["*preview_url"]) {
        $this->elements["product"][$object_id]["*preview_url"] = $inet_data["*preview_url"];
        $this->vprint(t("Loaded preview URL"));
      }

      # Import author description
      if (count($inet_data["*author"]) == 1 && count($this->elements["product"][$object_id]["*author"]) == 1 && $inet_data["*author"][0]["description"]) {
          $this->elements["product"][$object_id]["*author"][0]["description"] = $tmp_data["*author"][0]["description"];
      }
 
      # Import author name
      if ($inet_data["*author"] && (variable_get('geslib_book_create_fake_author', NULL) == 2 || sizeof($this->elements["product"][$object_id]["*author"]) == 0)) {
        $this->elements["product"][$object_id]["*author"] = $inet_data["*author"];
        $this->vprint(t("Loaded author"));
      }

    }
  }

  /**
  * Process covers 
  *
  * @param elements 
  *   products hash
  */
  function process_covers(&$elements) {
    $counter = 0;
    $total = 0;
    $geslib_book_type = variable_get('geslib_book_geslib_type', NULL);
    $geslib_book_node_type = variable_get('geslib_book_node_type', NULL);
    # Loop elements and send it to apropiate action
    $this->vprint(t("Searching book covers"),1);
    foreach ($elements as $object_id => $object) {
      # Each 1000 objects, clear cache
      if ( $counter == 1000 ) {
        # Not sure if this clear internal node cache
        #$this->flush_cache();
        $counter = 0;
      }
      if ( $object["action"] != "B" && $object["type"] == $geslib_book_type && $object["attribute"]["ean"] && $this->get_uploaded_book_image($object["attribute"]["ean"]) ) {
        $node = $this->get_node_by_gid($object_id, "product", $geslib_book_node_type);
        # If there is no cover, we define it
        if ($node->nid) {
          $this->vprint(t("Updating")." ".$node_type." '".$object["title"]."' (NID:".$node->nid."/GESLIB_ID:".$object_id."/TITLE:'".$node->title."')", 1);
          $this->set_object_image($node, $object["*cover_url"]);
        }
        $counter += 1;
        $total += 1;
      }
      $node = NULL;
    }
    return $total;
  }

  /**
  * Process products 
  *
  * @param elements
  *   products hash
  */
  function process_products(&$elements) {
    $counter = 0;
    $total_counter = 0;
    $geslib_book_type = variable_get('geslib_book_geslib_type', NULL);
    # Loop elements and send it to apropiate action
    $this->vprint(t("Importing Products"),1);
    foreach ($elements as $object_id => $object) {
      # Each 1000 objects, clear cache
      if ( $counter == 500 ) {
        # Not sure if this clear internal node cache
        #$this->flush_cache();
        $total_counter += $counter;
        $this->vprint("---------------------> " . $total_counter . "\n",1);
        $counter = 0;
      }
      # Select kind of product (book or other)
      # In relationships, stock and other actions, there is no node type in geslib file, so first, without object["type"] it should be book
      if ( !array_key_exists('type', $object) || $object["type"] == "" || $object["type"] == $geslib_book_type ) {
        $drupal_node_type = variable_get('geslib_book_node_type', NULL);
        $object_type = "book";
      } else {
        $drupal_node_type = variable_get('geslib_other_node_type', NULL);
        $object_type = "other";
      }

      if ($object["action"] != "B") {
        if ($drupal_node_type) {
          # Create or update node and use it to modify parameters (linked or defined)
          $node = $this->update_object("product", $drupal_node_type, $object_id, $object, FALSE);

          # If we couldn't find node, and there is no type defined in the object, try again with "other" type
          if ( $node == NULL && $object["action"] != "A" && (!array_key_exists('type', $object) || $object["type"] == "" ) ) {
            $drupal_node_type = variable_get('geslib_other_node_type', NULL);
            $object_type = "other";
            $node = $this->update_object("product", $drupal_node_type, $object_id, $object, FALSE);
          }

          if ( $node ) {
            # Update body
            if ( variable_get('geslib_' . $object_type . '_body_from', NULL) ) {
              $this->update_body($node, $object, variable_get('geslib_' . $object_type . '_body_from', NULL));
            }
            # Update ubercart attributes
            $this->update_uc_product($node, $object);
            # ... node attributes
            $this->update_attributes($node, "book", $object);
            # ... and relatinships
            $this->update_relationships($node, "book", $drupal_node_type, $object);

            # Update Ubercart stock data
            if ($object["uc_product_stock"]) {
              $this->update_stock($node, $object["uc_product_stock"]["stock"]);
            }

            # If there is no cover, we define it
            if ($node->nid && (!$node->field_image_cache[0] || $node->field_image_cache[0]['filepath'] == variable_get('geslib_book_default_image', NULL)) ) {
              $this->set_object_image($node, $object["*cover_url"]);
            }
            # If the node is a book but there is no author relationship and create_fake_author is selected and there is author text
            if ( variable_get('geslib_book_create_fake_author',NULL) && sizeof($object["*author"]) > 0 && !$object["relation"]["author"] ) {
              $this->set_fake_author($node, $object["*author"]);
            }
            // Remove object from memory
            $node = NULL;
          } else {
            $this->vprint(t("Product with GeslibID @gid doesn't exist", array('@gid' => $object_id)), 0);
          }
        }
      } else {
        if ($drupal_node_type) {
          if (! $this->delete_object("product", $drupal_node_type, $object_id)) {
            $this->delete_object("product", variable_get('geslib_other_node_type', NULL), $object_id);
          }
        }
      }
      $counter += 1;
    }
    $this->vprint("---------------------> " . $total_counter . "\n",1);
  }

  /**
  * Process other elements (not products)
  *
  * @param elements
  *   elements hash 
  * @param geslib_type
  *   drupal geslib type 
  * @param drupal_node_type
  *   drupal node type
  * @param use_existing_nodes
  *   If true, link existing nodes with same title to geslib. If false, create node if there is no linked yet
  */
  function process_element($elements, $geslib_type, $drupal_node_type, $use_existing_nodes = false) {
    $counter = 0;
    # Loop elements and send it to apropiate action
    $this->vprint(t("Importing")." ".$geslib_type, 1);
    foreach ($elements as $object_id => $object) {
      if ($counter == 1000) {
        # Not sure if this clear internal node cache
        #$this->flush_cache(); 
        $counter = 0;
      } 
      if ($object["action"] != "B") {
        # If there is no action defined, try with add
        if ($object["action"] == NULL) {
          $object["action"] = "M";
        }
        # Create or update node and use it to modify parameters (linked or defined)
        $node=$this->update_object($geslib_type, $drupal_node_type, $object_id, $object, $use_existing_nodes);
        if ( $node ) {
          # Update node attributes, relationships and taxonomy terms
          $this->update_attributes($node, $geslib_type, $object);
          $this->update_relationships($node, $geslib_type, $drupal_node_type, $object);
          // Remove object from memory
          $node = NULL;
        } else {
          $this->vprint(t("Node @type with GeslibID @gid doesn't exist", array('@type' => $drupal_node_type, '@gid' => $object_id)), 0);
        }
      } else {
        $this->delete_object($geslib_type, $drupal_node_type, $object_id);
      }
      $counter += 1;
    }
  }


  /**
  * Get account access to the node
  *
  * @param node 
  */
  function get_access(&$node, $op) {
    #$account = user_load($node->uid);
    if (!node_access($op, $node, $this->user)) {
      if (!db_query('UPDATE {node} SET uid=%d WHERE nid=%d', $this->user->uid, $node->nid)) {
        throw new Exception('User ' . $this->user->uid . ' not authorized to ' . $op . ' content type ' . $node->type);
      }
      watchdog('geslib-import', "$node->type: Changed ownership of '%node' to user '%user'", array('%node'=>$node->title, '%user'=>$this->user->name));
      $this->vprint(t("Changed ownership of"). " ". $node->nid . " (". $node->type ."/". $node->title .") " . t("to user")." ". $this->user->name, 2);
    }
  }

  /**
  * Update attributes
  *
  * @node
  *   drupal node
  * @type
  *   geslib node type
  * @param object
  *   object properties
  */
  function update_attributes(&$node, $type, &$object) {
    if ($node->nid && ($attributes = $object['attribute'])) {
      $updated = false;

      foreach ( $attributes as $attrib_name => $attrib_value ) {
        $field_name = variable_get('geslib_'.$type.'_attribute_'.$attrib_name, NULL); 
        if ($field_name) {
          // If is selected a taxonomy term
          if (strpos($field_name, "#vid-") === 0) {
            $vid = substr($field_name,5);
            $this->update_vocabulary_terms($node,$vid,$attrib_value);
          // For regular attributes store it
          } else {
            $values = array();
            if (is_array($attrib_value)) {
              foreach ( $attrib_value as $attrib_element ) {
                $values[] = array( 'value' => $attrib_element );
              }
            } else {
              $values[] = array( 'value' => $attrib_value );
            }
            $node->$field_name = $values;
            $values = NULL;
            $updated = true;
          }
        }
      }

      # Check that node is ready to save
      if ($updated) {
        if ($node_to_save = node_submit($node)) {
          node_save($node_to_save);

          $this->vprint(t("Attributes updated correctly"));
        } else {
          #print_r($node);
          $this->vprint(t("Node")." ".$node->title." (TYPE:".$type."/NID:".$node->nid."): ".t("not updated"), 0);
        }
      }
      $node_to_save = NULL;
    } 
  }

  /**
  * Update vocabulary terms 
  *
  * @node
  *   drupal node
  * @vid
  *   vocabulary ID 
  * @param values 
  *   object terms separated by comma 
  */
  function update_vocabulary_terms(&$node, $vid, $values) {
    if ($values && $values != "") {
      $this->vprint(t("Updating vocabulary").": ".$values);
      $terms = array();
      $terms['tags'] = array($vid => $values);
      taxonomy_node_save($node, $terms);
      # Another way to do it
      /* 
      foreach (explode(",", $values) as $term) {
        $new_term = array('name' => $term, 'parent' => 0, 'vid' => $vid);
        taxonomy_save_term($autoterm);
      }
      */
    }
  }

  
  /**
  * Update relationships 
  *
  * @node
  *   drupal node
  * @type
  *   geslib node type
  * @param drupal_node_type
  *   drupal node type
  * @param object
  *   object properties
  */
  function update_relationships(&$node, $type, $drupal_node_type, &$object) {
    if ($node->nid && ($relations = $object['relation'])) {
      $updated = false;
      # Allowed node fields for that object
      $allowed = content_types($drupal_node_type);

      # Loop all relation array
      foreach ( $relations as $rel_name => $rel_values ) {
        $field_name = variable_get('geslib_'.$type.'_link_to_'.$rel_name, NULL);
        # If there is any relation defined and it's any of the allowed fields
        if ($field_name && $allowed[fields][$field_name]) {
          $this->vprint("Actualizando relaciones con ".$rel_name,2);
          # Array used to store relation
          $linked_elements = array();
          # Loop all related values (it could be multivalued)
          foreach ( $rel_values as $rel_element ) {
            # If related element has node type, we can search it
            if ( $rel_node_type = variable_get('geslib_'.$rel_name.'_node_type', NULL) ) {
              # If relation is about authors, and link_only_authors is true, and is not an author, ignore it
              if ( $rel_name == "author" && variable_get('geslib_book_link_only_authors', NULL) && $rel_element["function"] != "A") {
                $this->vprint(t("Ignoring author relationship. The type is:") . " " . $rel_element["function"]);
              } else {
                $linked_nid = $this->get_nid_by_gid($rel_element["gid"], $rel_name, $rel_node_type);
                # If related object exists, link it
                if ($linked_nid) {
                  $this->vprint("Guardando la referencia a ".$rel_node_type." ('".$field_name."/NID:".$linked_nid."/GID:".$rel_element["gid"].")");
                  # If related node field is nodereference, we store only related object nid
                  if ( $allowed[fields][$field_name][type] == "nodereference") {
                    $linked_elements[] = array( 'nid' => $linked_nid );
                  # For text fields, store the relation title value
                  } else {
                    $linked = $this->get_node_by_gid($rel_element["gid"], $rel_name, $rel_node_type);
                    $linked_elements[] = array( 'value' => $linked->title );
                    $linked = NULL;
                  }
                } else {
                  $this->vprint("ERROR: El nodo ". $rel_node_type ." relacionado (GID:". $rel_element["gid"] .") no pudo encontrarse",0);
                }
              }
            # If related element could not be found, look it in geslib array
            } else if ($allowed[fields][$field_name][type] != "nodereference" ) {
              $referenced_value = $this->elements[$rel_name][$rel_element["gid"]]["title"];
              if ( $referenced_value ) {
                $linked_elements[] = array( 'value' => $referenced_value ); 
                $this->vprint("Guardando el valor ('".$referenced_value."'/GID:".$rel_element["gid"].") como ".$field_name);
              } else {
                $this->vprint("ERROR: No pudo encontrarse el valor de la referencia en el fichero geslib (".$rel_name."/GID:".$rel_element["gid"].")",0);
              }
            } else {
              $this->vprint("ERROR: No se que hacer con el elemento relacionado",0);
            }
          }
          # Store relationship in associated node field
          $node->$field_name = $linked_elements;
          $linked_elements = NULL;
          $updated = true;
        }
      }


      # Check that node is ready to save
      if ($updated) {
        if ($node_to_save = node_submit($node)) {
          node_save($node_to_save);
          $this->vprint(t("Node")." '".$node_to_save->title."' (NID:".$node_to_save->nid."): ".t("relationships updated correctly"),2);
        } else {
          #print_r($node);
          $this->vprint(t("Relationships for node")." '".$node->title."' (NID:".$node->nid.") ".t("not updated"), 0);
        }
      } else {
        $this->vprint(t("There is no relationships to update"));
      }
      $node_to_save = NULL;
    }
  }


  /**
  * Get Node by GeslibID
  *
  * @param geslib_id
  *    geslib object_id
  * @param geslib_type
  *    geslib type of object
  * @param node_type
  *    drupal node type
  *
  */
  function get_node_by_gid($geslib_id, $geslib_type, $node_type) {
    $nid = $this->get_nid_by_gid($geslib_id, $geslib_type, $node_type);
    # If there is a node with that gid, load it
    if ($nid) {
      $node = node_load($nid, NULL, TRUE);
    } else {
      $node = NULL;
    }
    return $node;
  }
  /**
  * Get NodeID by GeslibID
  *
  * @param geslib_id
  *    geslib object_id
  * @param geslib_type
  *    geslib type of object
  * @param node_type
  *    drupal node type
  *
  */
  function get_nid_by_gid($geslib_id, $geslib_type, $node_type) {
    $cck_field = variable_get('geslib_link_content_field', NULL);
    # Search depends if there is cck_field defined for that node type or we must use module tables
    if ( $cck_field ) {
      $query = "SELECT node.nid FROM {content_". $cck_field ."} cck LEFT JOIN {node} ON node.nid = cck.nid WHERE ". $cck_field ."_value = '%s' AND node.type = '%s'";
      $result = db_query_range($query, $geslib_id, $node_type, 0, 1);
    } else {
      $query = "SELECT nid FROM {geslib_".$geslib_type."} WHERE gid = '%s'";
      $result = db_query_range($query, $geslib_id, 0, 1);
    }
    # If there is a node with that gid, load it
    if ($result && $row = db_fetch_object($result)) {
      $nid = $row->nid;
    } else {
      $nid = NULL;
    }
    $row = NULL;
    $result = NULL;
    return $nid;
  }


  /**
  * Insert or modify simple object 
  *
  * @param geslib_type
  *   drupal table used to store geslib relationship
  * @param node_type
  *   drupal node type
  * @param object_id
  *   geslib object_id
  * @param object 
  *   object properties 
  * @param use_existing_nodes
  *   If true, link existing nodes with same title to geslib. If false, create node if there is no linked yet
  */
  function update_object($geslib_type, $node_type, $object_id, &$object, $use_existing_nodes) {
    $new_element = false;
    $cck_field = variable_get('geslib_link_content_field', NULL);

    # Get node if exists
    $node = $this->get_node_by_gid($object_id, $geslib_type, $node_type);
    # If node exists, only gets authorization for update
    if ( $node ) {
      // Only returns node if action is 'Add'
      if ( $object["action"] == "A" ) {
        $this->vprint("Already created ".$node_type." '".$object["title"]."' (NID:".$node->nid."/GESLIB_ID:".$object_id."/TITLE:'".$node->title."')", 1);
        return $node;
      } elseif ($object["action"] =! "M" ) {
        $this->vprint("Loaded ".$node_type." (NID:".$node->nid."/GESLIB_ID:".$object_id.")", 1);
        return $node;
      }
      $this->vprint(t("Updating")." ".$node_type." '".$object["title"]."' (NID:".$node->nid."/GESLIB_ID:".$object_id."/TITLE:'".$node->title."')", 1);
      $this->get_access($node, "update");
    # Return NULL if doesn't exists and there is no ADD or MODIFY action
    } elseif ( $object["action"] != "A" && $object["action"] != "M" ) {
      return NULL;
    # Si no hay nodo vinculado al gid...
    # If that node doesn't exist
    } else {
      $node = NULL;
      $new_element = true;
      # Search that node if we must link existing nodes (categories only)
      if ($use_existing_nodes) {
        $query = "SELECT node.nid FROM {node} WHERE node.type = '%s' AND node.title = '%s'";
        $result = db_query_range($query, $node_type, $object["title"], 0, 1);
        if ($result && $row = db_fetch_object($result)) {
          $node = node_load($row->nid, NULL, true);
          $this->vprint("Asociando ".$node_type." existente: '".$object["title"]."' (NID:".$node->nid."/TITLE:'".$node->title."')");
          $this->get_access($node, "update");
        }
      }
      # If there is no existing node, create it and grant access to create
      if (!$node) {
        $node = new stdClass();
        $node->type = $node_type;
        $node->created = time();
        $node->promote = 0; // Display on front page ? 1 : 0
        $node->sticky = 0;  // Display top of page ? 1 : 0
        $node->format = 1;  // 1:Filtered HTML, 2: Full HTML
        $node->comment = 2; // 0:Disabled, 1:Read, 2:Read/Write
        #node_object_prepare($node); // This sets up all the default node fields so we don't accidentally leave something off.
        $this->vprint("Creando nuevo ".$node_type." '".$object["title"]."'",1);
        $this->get_access($node, "create");
      }
    }

    # Basic node data
    $node->language = 'es';
    $node->uid = 1;
    $node->name = "admin";
    $node->status = 1;   // Published ? 1 : 0
    $node->changed = time();

    # If exists "*title_from_related_book" use it for title
    if ($object["*title_from_related_book"]) {
      # If there is book name entry in this file, use it
      if ( $this->elements["product"][$object["*title_from_related_book"]]["title"] ) {
        $node->title = $this->elements["product"][$object["*title_from_related_book"]]["title"];
      # If there is no book name entry, load from database
      } else {
        $related_node = $this->get_node_by_gid($object["*title_from_related_book"], "product", variable_get('geslib_book_node_type', NULL));
        $node->title = $related_node->title;
        $related_node = NULL;
      }
    # If not and there is title defined, update it
    } elseif ($object["title"]) {
      $node->title = $object["title"];
    }
   
    # If there is body field, for non products or products with external description update it
    if ($object["body"] && ($geslib_type != "product" || variable_get('geslib_book_body_from', NULL) == "external_description")) {
      $node->body = $object["body"];
      $this->vprint(t("Updated body product") . ": " . $object["body"]);
    } 

    #$product = uc_product_load($node);

    # Update Ubercart fields if exists
    # A eliminar cuando sepamos que se puede guardar sin esto!!!
    if (FALSE && $object["uc_product"]) {

      # Sometimes there is a book without isbn
      #$node->model = $object["uc_product"]["model"];
      if ($object["attribute"]["ean"]) {
        $node->model = $object["attribute"]["ean"];
      } else if ($object["attribute"]["isbn"]) {
        $node->model = $object["attribute"]["isbn"];
      } else {
        $node->model = "ID-".$object_id;
      }

      $node->list_price = str_replace(",", ".", $object["uc_product"]["list_price"]);
      $node->sell_price = str_replace(",", ".", $object["uc_product"]["sell_price"]);
      $node->cost = str_replace(",", ".", $object["uc_product"]["cost"]);
      # Comprobar peso, ancho y alto!!!!!
      $node->weight = $object["uc_product"]["weight"];
      $node->weight_units = "g";
      $node->width = $object["uc_product"]["width"];
      $node->length = $object["uc_product"]["length"];
      #$node->length_units = "cm";
      $node->length_units = $object["*length_unit"];
      $node->default_qty = 1;
      $node->pkg_qty = 1;
      # If product is not an ebook, make it shippable
      if (!$node->shippable && !$object["ebook"]) {
        $node->shippable = 1;
      }
    }

    # Update Ubercart stock data if exists
    if ($object["uc_product_stock"]) {
      $node->qty = $object["uc_product_stock"]["stock"];
      $node->ordering = ( $object["uc_product_stock"]["stock"] == 0 ? 0 : 1 );
    }

    # If we must use cck field to store gid, use it
    if ( $cck_field ) {
      $node->$cck_field = array( 0 => array( 'value' => $object_id) );
    }

    # Check that node is ready and save it
    if ($node = node_submit($node)) {
      node_save($node);

      # When there is no cck_field to use, store gid relationship in module tables
      if ($new_element && !$cck_field ) {
        $insert_query = "INSERT INTO {geslib_".$geslib_type."} (gid, nid) VALUES ( '%s', %d )";
        $this->vprint("Vinculando ".$node_type." '".$object["title"]."' (GESLIB_ID:".$object_id."/NID:".$node->nid.")");
        $result = db_query($insert_query, $object_id, $node->nid);
      }
       
      $this->vprint(t("Node")." '".$node->title."' (NID:".$node->nid."/GID:".$object_id.") ".t("updated correctly"), 2);

      return $node;
    } else {
      $this->vprint(t("Node")." '".$node->title."' (NID:".$node->nid."/GID:".$object_id.") ".t("processed incorrectly"), 0);
      return NULL;
    }
  }

  /**
  * Updates body for books
  *
  * @param node
  *   node to be updated
  * @param object 
  *   object element 
  */
  function update_body(&$node, $object, $body_from) {
    if ( $object["relation"][$body_from] ) {
      $body_gid = $object["relation"][$body_from][0]["gid"];
      $tmp_body = $this->elements[$body_from][$body_gid]["title"];
      if ($tmp_body) {
        $node->body = $tmp_body;

        # Check that node is ready and save it
        if ($node = node_submit($node)) {
          node_save($node);

          $this->vprint(t("Updated body product"));
        } else {
          $this->vprint(t("Body for node")." '".$node->title."' (NID:".$node->nid."/GID:".$object_id.") ".t("processed incorrectly"), 0);
        }
      }
    }
  }

  /**
  * Update ubercart attributes for books
  *
  * @param node
  *   node to be updated
  * @param object
  *   object element
  */
  function update_uc_product(&$node, $object) {
    if ($object["uc_product"]) {
      # Sometimes there is a book without isbn
      #$node->model = $object["uc_product"]["model"];
      if ($object["attribute"]["ean"]) {
        $node->model = $object["attribute"]["ean"];
      } else if ($object["attribute"]["isbn"]) {
        $node->model = $object["attribute"]["isbn"];
      } else {
        $node->model = "ID-".$object_id;
      }

      $node->list_price = (float) str_replace(",", ".", $object["uc_product"]["list_price"]);
      $node->sell_price = (float) str_replace(",", ".", $object["uc_product"]["sell_price"]);
      $node->cost = (float) str_replace(",", ".", $object["uc_product"]["cost"]);
      # Comprobar peso, ancho y alto!!!!!
      $node->weight = $object["uc_product"]["weight"];
      $node->weight_units = "g";
      $node->width = $object["uc_product"]["width"];
      $node->length = $object["uc_product"]["length"];
      #$node->length_units = "cm";
      $node->length_units = $object["*length_unit"];
      $node->default_qty = 1;
      $node->pkg_qty = 1;
      # If product is not an ebook, make it shippable
      if (!$node->shippable && !$object["ebook"]) {
        $node->shippable = 1;
      }

      # Check that node is ready and save it
      if ($node = node_submit($node)) {
        node_save($node);
  
        $this->vprint(t("Updated ubercart product attributes"));
      } else {
        $this->vprint(t("Ubercart attributes for node")." '".$node->title."' (NID:".$node->nid."/GID:".$object_id.") ".t("processed incorrectly"), 0);
      }
    }
  }

  /**
  * Updates stock and threshold level 
  *
  * @param node
  *   node to be updated
  * @param stock
  *   new stock value
  */
  function update_stock(&$node, $stock) {
    $query = "SELECT sku FROM {uc_product_stock} WHERE sku = '%s'";
    $result = db_query_range($query, $node->model, $node_type, 0, 1);

    // If there is a registered sku un uc_product_stock table, update it
    if ($result && $row = db_fetch_object($result)) {
      db_query("UPDATE {uc_product_stock} SET stock = %d WHERE sku = '%s'", $stock, $node->model );
    } else {
      db_query("INSERT INTO {uc_product_stock} (sku, nid, active, stock, threshold) VALUES ('%s', %d, %d, %d, %d)", $node->model, $node->nid, 1, $stock, 1);
    }

    $new_stock = uc_stock_level($node->model);
    if ($new_stock == $stock) {
      $this->vprint(t("Updated stock") . " (" . $new_stock .")");
    } else {
      $this->vprint(t("Error updating stock"),0);
    }
    $result = NULL;
  }
  
  /**
  * Delete object if exists
  *
  * @param geslib_type 
  *   drupal table used to store geslib relationship 
  * @param node_type
  *   drupal node type
  * @param object_id
  *   geslib object_id
  * 
  * @return object could be found and deleted
  */
  function delete_object($geslib_type, $node_type, $object_id) {
    $ret = false;

    # Get related node
    $node = $this->get_node_by_gid($object_id, $geslib_type, $node_type);

    # and delete if exists
    if ( $node ) {
      $this->get_access($node, "delete");
      node_delete($node->nid);
      $this->vprint(t("Node")." '".$node->title."' (NID:".$node->nid."/GID:".$object_id.") ".t("removed"), 2);
      # If there is no CCK field for that node type, delete relation from geslib tables
      if (!variable_get('geslib_link_content_field', NULL)) {
        $delete_query = "DELETE FROM {geslib_".$geslib_type."} WHERE gid = '%s'";
        $result = db_query($delete_query, $object_id);
      }
      $ret = true;
    }
    $result = NULL;
    $node = NULL;
    return $ret;
  }

  /**
  * Set fake author if product has no defined author relation
  *
  * @param $node
  *     Drupal Node
  */
  function set_fake_author(&$node, &$authors) {
    $author_fieldname = variable_get('geslib_book_link_to_author', NULL);
    if ($author_fieldname && ($author_field = $node->$author_fieldname) && ($author_type = variable_get('geslib_author_node_type', NULL)) ) {
      # Do it only if there is no author linked yet
      if ( !$author_field[0] || !$author_field[0][nid] ) {
        $author_links = array();
        # param $author_string could be various names. Split it and iterate
        #print "-------------------> Probando con ".$author_string."\n";
        foreach($authors as $author_data) {
          # Search for a author with that title
          $query = "SELECT node.nid FROM {node} WHERE title = '%s' AND type = '%s'";
          $result = db_query_range($query, $author_data['name'], $author_type, 0, 1);

          # Si encontramos un autor con ese nombre, lo usamos 
          # If there is an author with that name, use it
          if ($result && $row = db_fetch_object($result)) {
            $author_nid = $row->nid;
            $result = NULL;
            $row = NULL;
          # Si no lo encontramos tratamos de crearlo
          # If author could't be found, we try to create it
          } else {
            $author = new stdClass();
            $author->type = $author_type;
            $author->created = time();
            $author->promote = 0; // Display on front page ? 1 : 0
            $author->sticky = 0;  // Display top of page ? 1 : 0
            $author->language = 'es';
            $author->uid = 1;
            $author->name = "admin";
            $author->status = 1;   // Published ? 1 : 0
            $author->changed = time();
            $author->title = $author_data['name'];
            if ($author_data['description']) {
              $author->body = $author_data['description'];
            }
            $this->get_access($author, "create");
            if ($author = node_submit($author)) {
              node_save($author);
              $author_nid = $author->nid;
              $this->vprint(t("Author")." ".$author->title." (NID:".$author->nid.") ".t("created correctly"),2);
            } else {
              $this->vprint("ERROR: ".t("Author")." (".$author_data['name'].") ".t("could not be created"), 0);
            }
            $author = NULL;
          }
          # Now, we should have an author, so link it with the book
          if ($author_nid) {
            $author_links[] = array("nid" => $author_nid);
          }
        }
        if (count($author_links) > 0) {
          #$node->$author_fieldname = array( 0 => array("nid" => $author_nid));
          $node->$author_fieldname = $author_links;
          $this->get_access($node, "update");
          if ($node = node_submit($node)) {
            node_save($node);
            $this->vprint(t("Node")." ".$node->title." (NID:".$node->nid."). ".t("Authors")." ".t("updated correctly"),2);
          } else {
            $this->vprint(t("Node")." ".$node->title." (NID:".$node->nid."/GID:".$object_id.") ".t("Authors")." ".t("processed incorrectly"), 0);
          }
        }
        $author_links = NULL;
      }
    }
  }

  /**
  * Save associated image of the node 
  *
  * @param $node
  *     Drupal Node 
  * @param $image_url
  *     URL of remote image
  */
  function set_object_image(&$node,$image_url) {
    # Get uploaded image 
    $filename = $this->get_book_image($node,$image_url); 
    # If there is no cover loaded in database, do it
    if ( !($image = field_file_load($filename, TRUE)) ) {
      // Create file object and update files table
      $file = new stdClass();
      $file->filename  = basename($filename);
      $file->filepath  = $filename;
      $file->filemime  = mime_content_type($filename);
      $file->filesize  = filesize($filename);
      $file->uid       = 1;
      $file->timestamp = time();
      drupal_write_record('files', $file);
      $image = field_file_load($filename, TRUE);
    }
    if ( $image[fid] ) {
      $image['data']['alt'] = t("Cover Image") . ": " . $node->title;
      $image['data']['title'] = t("Cover Image") . ": " . $node->title; 
      $node->field_image_cache[0] = $image; 
      # Check that node is ready to save
      if ($node = node_submit($node)) {
        node_save($node);
        $this->vprint(t("Cover image stored"),2);
      } else {
        $this->vprint(t("Error storing cover image"),0);
      }
    }
    $file = NULL;
    $image = NULL;
  }

  /**
  * Save associated image of the node  
  *
  * @param $node
  *     Node 
  * @param $image_url
  *     URL of remote image
  */
  function get_book_image(&$node, $image_url) {
    # If there is uploaded cover, copy it
    $image_file = $this->get_uploaded_book_image($node->model);

    # If not book cover exists try to download it
    if (!$image_file && $image_url) {
      $this->vprint(t("Downloading remote book cover"));
      $image_file = InetBookSearch::download_file($image_url, file_directory_path()."/book_covers", $node->model);
      # If content type is not an image, delete it
      $ext = pathinfo($image_file, PATHINFO_EXTENSION);
      if ($ext != "jpeg" && $ext != "png" && $ext != "jpg" && $ext != "gif" && $ext != "tiff") {
        $this->vprint(t("Remote book cover not valid").": ".$image_file);
        $image_file=NULL;
        unlink($image_file);
      }
    }

    # Or use default one
    if (!$image_file) {
      $this->vprint(t("Using default cover"));
      if ( $node->type == variable_get('geslib_book_node_type', NULL)) {
        $image_file = variable_get('geslib_book_default_image', NULL);
      } else {
        $image_file = variable_get('geslib_other_default_image', NULL);
      }
    }

    # And return cover path 
    return $image_file;
  }

  /**
  * Save associated image of the node  
  *
  * @param $ean
  *     EAN 
  */
  function get_uploaded_book_image($ean) {
    $image_file = NULL;
    $found = FALSE;
    # Try with known image extensions
    if (variable_get('geslib_upload_cover_path', NULL)) {
      $covers_path = variable_get('geslib_upload_cover_path', NULL);
    } else {
      $covers_path = dirname($this->geslib_filename);
    }
    $short_ean = substr($ean, 0, 12);
    foreach ( array("gif", "GIF", "jpg", "JPG", "jpeg", "JPEG", "png", "PNG")  as $extension ) {
      # First try in basepath
      $filename = $covers_path."/".$ean.".".$extension;
      $alt_filename = $covers_path."/".substr($ean, 0 , 12).".".$extension;
      if ( !$found && $ean && realpath( $filename ) ) {
        if ( copy( $filename, file_directory_path()."/book_covers/".$ean.".".$extension ) ) {
          $this->vprint(t("Using uploaded book cover"));
          $image_file = file_directory_path()."/book_covers/".$ean.".".$extension;
          $found = TRUE;
          # Delete original cover
          if ( variable_get('geslib_delete_original_covers', NULL) ) {
            unlink($filename);
          }
          break;
        }
      # Try with the ean without control digit
      } elseif ( !$found && $ean && realpath( $alt_filename ) ) {
        if ( copy( $alt_filename, file_directory_path()."/book_covers/".$ean.".".$extension ) ) {
          $this->vprint(t("Using uploaded book cover"));
          $image_file = file_directory_path()."/book_covers/".$ean.".".$extension;
          $found = TRUE;
          # Delete original cover
          if ( variable_get('geslib_delete_original_covers', NULL) ) {       
            unlink($alt_filename);
          }
          break;
        }
      }
      # If not exists image, try in subdir
      $subdir = substr($ean, 0, 6);
      $filename = $covers_path."/".$subdir."/".$ean.".".$extension;
      $alt_filename = $covers_path."/".$subdir."/".substr($ean, 0 , 12).".".$extension;
      if ( !$found && $ean && realpath( $filename ) ) {
        if ( copy( $filename, file_directory_path()."/book_covers/".$ean.".".$extension ) ) {
          $this->vprint(t("Using uploaded book cover"));
          $image_file = file_directory_path()."/book_covers/".$ean.".".$extension;
          $found = TRUE;
          # Delete original cover
          if ( variable_get('geslib_delete_original_covers', NULL) ) {       
            unlink($filename);
          }
          break;
        }
      # Try with the ean without control digit
      } elseif ( !$found && $ean && realpath( $alt_filename ) ) {
        if ( copy( $alt_filename, file_directory_path()."/book_covers/".$ean.".".$extension ) ) { 
          $this->vprint(t("Using uploaded book cover"));
          $image_file = file_directory_path()."/book_covers/".$ean.".".$extension;
          $found = TRUE;
          # Delete original cover
          if ( variable_get('geslib_delete_original_covers', NULL) ) {       
            unlink($alt_filename);
          }
          break;
        }
      }
    }
    return $image_file;
  }

  /**
  * Read geslib_filename line by line
  *
  * @param filename
  *   file to be imported
  */
  function read_file($filename) {
    if (empty($filename) || !file_exists ($filename)) {
      throw new Exception(t('Geslib file not valid.'));
    } else {
      $this->geslib_filename = $filename;
      $this->elements = array();

      # Check if there is a previously serialized version of file
      if ( file_exists($filename . ".json") ) {
        $this->vprint(t("Reading previously serialized file"),1);
        #$this->elements = unserialize(file_get_contents($filename . '.serialized'));
        $this->elements = json_decode(file_get_contents($filename . '.json'), true);
      } else {
        $reader = new GeslibReader($filename, $this->default_nom_collection, $this->default_nom_category);
        $this->elements = &$reader->getElements();
        # else, read file line by line
        #$handle = fopen($filename, "r");
        #while (($data = fgetcsv($handle, 0, "|")) !== FALSE) {
        #  $this->process_line($data);
        #}

        # If user wants to search book data
        if (variable_get('geslib_book_download_info', NULL)) {
          $this->preprocess_book_data();
        }

        # Write data to disk
        $this->vprint(t("Saving serialized file"),1);
        #file_put_contents($filename . ".serialized",serialize($this->elements));
        file_put_contents($filename . ".json",json_encode($this->elements)); 
      }
    }
  }

  function utf8_encode($string) {
    if ($string) {
      return Encoding::fixUTF8(utf8_encode($string));
    } else {
      return NULL;
    }
  }

  /**
  * Print output messages
  *
  * @param $string
  *	Output message
  * @param $verbose=3
  *	Verbose level for message
  */
  function vprint($string, $level = 3, $type = NULL) {
    # For errors, write it in logs
    if ($level == 0) {
      watchdog('geslib-import', $string, NULL, WATCHDOG_ERROR);
    }
    # Output message if verbose level is greater
    if ($level < $this->verbose_level) {
      # Output formating
      $pre = array("\n*** ", "   * ", "       ", "          ");
      drush_print($pre[$level].$string);
    }
  }
}

