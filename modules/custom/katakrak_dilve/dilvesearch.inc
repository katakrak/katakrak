<?php 
/**
 * @author   Santiago Ramos <sramos@semillasl.com>
 * @package  DilveSearch 
 * @version  0.1
  */

class DilveSearch {

  public $url_host = "www.dilve.es";
  public $url_path = "/dilve/dilve";
  public $url_user;
  public $url_pass;
  
  public function __construct($username, $password) {
    $this->url_user = $username;
    $this->url_pass = $password;
  }

  /**
  * Function DilveSearch::search
  *
  * @param string $isbn
  *   ISBN code to search
  * @return hash
  *   hash data of book
  */ 
  public function search($isbn) {
    $query  = 'http://'.$this->url_host.$this->url_path.'/getRecordsX.do?user='.$this->url_user.'&password='.$this->url_pass.'&identifier='.$isbn;
    # Get xml in ONIX version 2.1
    $query .= '&metadataformat=ONIX&version=2.1';
    # Get xml in CEGAL version 3
    #$query .= '&metadataformat=CEGAL&version=3&formatdetail=C';
    # By default responses are UTF-8 encoded, but force it
    $query .= '&encoding=UTF-8';
    $request = drupal_http_request($query);
    if ($request->code == 200) {
      $xml = simplexml_load_string($request->data);
    }
    else 
      return;
    
    
    $xml_book = $xml->ONIXMessage->Product[0];
    
    if ($xml_book) {
      $book = array();
    //drupal_set_message(dprint_r($xml_book, 1));
    
      $book['isbn'] = $isbn;//(string)$xml_book->RecordReference;
      $book['ean'] = (string)$xml_book->RecordReference;
      $book['date'] = (int)$xml_book->PublicationDate;
      $book['year'] = substr($book['date'],0, 4);
      
      #Get Price
      foreach($xml_book->SupplyDetail->Price as $price) {
        $book['price'] = (float)$price->PriceAmount;
        $book['price'] = str_replace('.', '', number_format($book['price'], 2));
      }
      # Get title
      foreach($xml_book->Title as $title) {
        if ($title->TitleType == "01") {
          $book["title"] = (string)$title->TitleText;
          if ($title->Subtitle) {
            $book["subtitle"] = (string)$title->Subtitle;
          }
        }
      }
      
      //Get Publisher
      foreach ($xml_book->Publisher as $publisher) {
        if ($publisher->NameCodeType == 02) {
          $book['publisher'] = (string)$xml_book->Publisher->PublisherName;
        }
      }
      
      # Get author
      foreach($xml_book->Contributor as $contributor) {
        if ($contributor->ContributorRole == "A01") {
          $author_name = (string) $contributor->PersonNameInverted;
          $author_description = (string) $contributor->BiographicalNote;
          if ($author_description) {
            $book["author"][] = array('name' => $author_name, 'description' => $author_description);
          } else {
            $book["author"][] = array('name' => $author_name);
          }
        }
      }
      # Get measurements
      foreach($xml_book->Measure as $measure) {
        switch ($measure->MeasureTypeCode) {
          case "01":
            $book["length"] = array('unit' => (string)$measure->MeasureUnitCode, 'value' => (string)$measure->Measurement);
            break;
          case "02":
            $book["width"] = array('unit' => (string)$measure->MeasureUnitCode, 'value' => (string)$measure->Measurement);
            break;
          case "08":
            $book["weight"] = array('unit' => (string)$measure->MeasureUnitCode, 'value' => (string)$measure->Measurement);
            break;
        }
      }
      # Get number of pages
      if($xml_book->NumberOfPages) {
        $book["pages"] = (string)$xml_book->NumberOfPages;
      }
      # Get descriptions
      foreach($xml_book->OtherText as $description) {
        switch ($description->TextTypeCode) {
          case "01":
          case "03":
          case "05":
          case "07":
          case "31":
            //Descripción general
            $book["description"] = nl2br( (string) $description->Text );
            break;
          case "09":
            $book["promoting_description"] = nl2br( (string) $description->Text );
            break;
          case "12":
            $book["short_description"] = nl2br( (string) $description->Text );
            break;
          case "13":
            if ( count($book['author']) == 1 ) {
              $book["author"][0]["description"] = nl2br( (string) $description->Text );
            }
            break;
          case "23":
            $book["preview_url"] = $this->get_file_url((string) $description->TextLink, $isbn);
            #print "\n---> Recogido fichero de preview: " . $book["*preview_url"] ." --- ";
            #print_r($description);
            break;
          default:
            #print "\n-----------------------> Tipo de texto no definido (".$description->TextTypeCode.") para el libro con ISBN ".$isbn."\n\n";
        }
      }
      # Get cover URL
      foreach ($xml_book->MediaFile as $media) {
        switch ($media->MediaFileTypeCode) {
          # Covers
          case "03":
          case "04":
          case "05":
          case "06":
            # Its better dilve uris
            if (!isset($book["cover_url"]) || $media->MediaFileLinkTypeCode == "06") {
              $book["cover_url"] = $this->get_file_url((string) $media->MediaFileLink, $isbn);
            }
            break;
          # Cover miniature
          case "07":
            break;
          # Author image
          case "08":
            $book["image_author_url"] = $this->get_file_url((string) $media->MediaFileLink, $isbn);
            #print "\n---> Recogido imagen del autor: " . $book["*image_author_url"];
            #print "\n---> Formato: " . $media->MediaFileFormatCode;
            #print "\n---> Tipo de Enlace: " . $media->MediaFileLinkTypeCode;
            break;
          # Publisher logo
          case "17":
            $book["image_publisher_url"] = $this->get_file_url((string) $media->MediaFileLink, $isbn);
            #print "\n---> Recogido logo de editorial: " . $book["*image_publisher_url"];
            #print "\n---> Formato: " . $media->MediaFileFormatCode;
            #print "\n---> Tipo de Enlace: " . $media->MediaFileLinkTypeCode;
            break;
          # Preview book
          case "51";
            #$book["*preview_media_url"] = $this->::get_file_url((string) $media->MediaFileLink, $isbn);
            #print "\n---> Recogido fichero de preview: " . $book["*preview_media_url"];
            #print "\n---> Formato: " . $media->MediaFileFormatCode;
            #print "\n---> Tipo de Enlace: " . $media->MediaFileLinkTypeCode;
            #break;e
          default:
            #print_r ($media);
            #print "\n-----------------------> Tipo de medio no definido (".$media->MediaFileTypeCode.") para el libro con ISBN ".$isbn."\n\n";
        }
      }
    }
    else {
      $book = (string)$xml->error->text;
    }

    return $book;
  }

  /**
  * Function DilveSearch::get_file_url
  *
  * @param string $filename
  *   local or remote filename
  * @param string $isbn
  *   ISBN code to search
  * @return string
  *   Full URL of requested resource 
  */
  private function get_file_url($filename, $isbn) {
    # If URL is a DILVE reference, complete full request
    if (!strncmp($filename, 'http://', 7) || !strncmp($filename, 'https://', 8)) {
      $url = $filename;
    } else {
      $url  = 'http://'.$this->url_host.'/'.$this->url_path.'/getResourceX.do?user='.$this->url_user.'&password='.$this->url_pass;
      $url .= '&identifier='.$isbn.'&resource='.urlencode($filename);
    }
    return $url;
  }
}
