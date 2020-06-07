<?php 
/**
 * @author   Xabier maeztu <trisketonni@gmail.com>
 * @package  Cegal 
 * @version  0.1
  */

class CegalSearch {
  public $url_host = "www.cegalenred.com/";
  public $url_path = "peticiones";
  public $url_user;
  public $url_pass;
  
  /**
   * 
   * @param type $username
   * @param type $password
   */
  public function __construct($username, $password) {
    $this->url_user = $username;
    $this->url_pass = $password;
  }
  
  /**
   * A partir de un isbn devuelve un array de ids de sinli que tienen disponible un libro
   * Si nadie lo tiene devuelve un array vacio
   * @param type $isbn
   * @return type
   */
  public function disponibilidad($isbn) {
    $query  = 'http://'.$this->url_host.$this->url_path.'/disponibilidad.xml.php?USUARIO='.$this->url_user.'&CLAVE='.$this->url_pass.'&ISBN='.$isbn;
    
     $request = drupal_http_request($query);
    if ($request->code == 200) {
      $xml = simplexml_load_string($request->data);
    }
    else 
      return array();
    
    $distribuidores = array();
    foreach ($xml as $key => $value) {     
      if ($value->TIPO_ASOCIADO->__toString() == 'D') {
        $distribuidores[] = $value->ID_SINLI_ASOCIADO->__toString();
      }
    }
    return $distribuidores;
  }
}