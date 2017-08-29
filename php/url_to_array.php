<?php

function url_to_array(){

  $sorted = array();

  $all = explode('/', $_SERVER["REQUEST_URI"]);

  unset($all[0]);  /* Removing the empty index from the beginning of array */

  foreach ($all as $param){

    if(!empty($param)){
      $sorted[] = (is_numeric($param)) ? intval($param) : $param;
    }

  }

  return (!empty($sorted)) ? $sorted : NULL ;
}

