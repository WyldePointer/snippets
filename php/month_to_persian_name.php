<?php

function month_to_persian_name($number){

  switch ($number){

    case 1:  case "۱":  return "ﻑﺭﻭﺭﺩیﻥ";
    case 2:  case "۲":  return "ﺍﺭﺩیﺐﻬﺸﺗ";
    case 3:  case "۳":  return "ﺥﺭﺩﺍﺩ";
    case 4:  case "۴":  return "ﺕیﺭ";
    case 5:  case "۵":  return "ﻡﺭﺩﺍﺩ";
    case 6:  case "۶":  return "ﺶﻫﺭیﻭﺭ";
    case 7:  case "۷":  return "ﻢﻫﺭ";
    case 8:  case "۸":  return "ﺂﺑﺎﻧ";
    case 9:  case "۹":  return "ﺁﺫﺭ";
    case 10: case "۱۰": return "ﺩی";
    case 11: case "۱۱": return "ﺐﻬﻤﻧ";
    case 12: case "۱۲": return "ﺎﺴﻔﻧﺩ";

  }

  return NULL;
}
