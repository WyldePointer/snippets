<?php

function latin_digits_to_arabic($string){

  $digit = 0;

  $result = "";

  /* int compatibility for function parameter. */
  $string = "$string";

  $length = strlen($string);

  for ($i=0; $i<$length; $i++){

    $digit = intval($string[$i]);

    if ($string[$i] !== '0' && $digit === 0){
      continue;
    }

    switch ($digit){

      case 0: $result .= "۰"; break;
      case 1: $result .= "۱"; break;
      case 2: $result .= "۲"; break;
      case 3: $result .= "۳"; break;
      case 4: $result .= "۴"; break;
      case 5: $result .= "۵"; break;
      case 6: $result .= "۶"; break;
      case 7: $result .= "۷"; break;
      case 8: $result .= "۸"; break;
      case 9: $result .= "۹"; break;

    }

  }

  return $result;
}
