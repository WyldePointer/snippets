<?php

function arabic_numbers_to_latin($string){

  $latin = NULL;

  $length = mb_strlen($string, "UTF-8");

  $numbers = array(
    '۰', '۱', '۲', '۳', '۴', '۵', '۶', '۷', '۸', '۹'
  );

  for($i=0; $i < $length; $i++){
    $latin .= array_search(mb_substr($string, $i, 1, "UTF-8"), $numbers);
  } 

  return intval($latin);
}


