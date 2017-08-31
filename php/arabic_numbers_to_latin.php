<?php

function arabic_numbers_to_latin($string){

  $latin = NULL;

  $numbers = array(
    '۰', '۱', '۲', '۳', '۴', '۵', '۶', '۷', '۸', '۹'
  );

  for($i=0; $i < mb_strlen($string, "UTF-8"); $i++){
    $latin .= array_search(mb_substr($string, $i, 1, "UTF-8"), $numbers);
  } 

  return intval($latin);
}


