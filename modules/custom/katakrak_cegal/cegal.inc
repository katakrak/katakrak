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
  
  public function query($service, $isbn) {
    return 'http://'.$this->url_host.$this->url_path.'/'.$service.'?USUARIO='.$this->url_user.'&CLAVE='.$this->url_pass.'&ISBN='.$isbn;
  }
  
  /**
   * A partir de un isbn devuelve un array de ids de sinli que tienen disponible un libro
   * Si nadie lo tiene devuelve un array vacio
   * @param type $isbn
   * @return type
   */
  public function disponibilidad($isbn) {
    $query  = $this->query('disponibilidad.xml.php', $isbn);
    
    $request = drupal_http_request($query, array('timeout' => 1));
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
  
  /**
   * 
   * @param type $isbn
   */
  public function cover($isbn) {
    $query  = $this->query('fichalibro.xml.php', $isbn).'&TIPOFICHA=C';
    
    //set_time_limit(1);
    $request = drupal_http_request($query, array('timeout' => 2));     if ($request->code == 200) {
      $xml = simplexml_load_string($request->data);
    }
    else 
      return array();
    
    foreach ($xml as $key => $value) {
      if ($value->PORTADA) {
        return array(
          'data' => base64_decode($value->PORTADA->IMAGEN_PORTADA->__toString()),
          'image' => $value->PORTADA->IMAGEN_PORTADA->__toString(),
          'format' => $value->PORTADA->FORMATO_PORTADA->__toString()
        );
      }
      else 
        return array();
    }
  }
  
  public function ficha($isbn) {
    $query  = $this->query('fichalibro.xml.php', $isbn).'&formato=XML';
    $request = drupal_http_request($query, array('timeout' => 2));
     if ($request->code == 200) {
      $xml = simplexml_load_string($request->data);
    }
    else 
      return array();
    
    foreach ($xml as $key => $value) {
      //dpm();
      $book = array();
      $book['isbn'] = $value->ISBN->__toString();
      $book['title'] = $value->TITULO->__toString();
      $book['ean'] = $value->EAN->__toString();
      $book['price'] = $value->PRECIO_CON_IVA->__toString();
      $book['year'] = substr($value->FECHA_PUBLICACION->__toString(), 2);
      $book["pages"] = $value->NUMERO_PAGINAS->__toString();
      $book['description'] = $this->sinopsis($isbn);
      $book['portada'] = $this->cover($isbn);   
    }
    return $book;
  }
  
  
  public function sinopsis($isbn) {
    $query  = $this->query('fichalibro.xml.php', $isbn).'&TIPOFICHA=C';
    $request = drupal_http_request($query, array('timeout' => 2));
     if ($request->code == 200) {
      $xml = simplexml_load_string($request->data);
    }
    else 
      return array();
    
    foreach ($xml as $key => $value) {
      $sinopsis = $value->RESUMEN->__toString();
    }
    return $sinopsis;
  }
}