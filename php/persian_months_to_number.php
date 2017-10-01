<?php

function persian_months_to_number($month){

  switch ($month){

    case "ﻑﺭﻭﺭﺩیﻥ":  case "۱":  return 1;
    case "ﺍﺭﺩیﺐﻬﺸﺗ": case "۲":  return 2;
    case "ﺥﺭﺩﺍﺩ":    case "۳":  return 3;
    case "ﺕیﺭ":      case "۴":  return 4;
    case "ﻡﺭﺩﺍﺩ":    case "۵":  return 5;
    case "ﺶﻫﺭیﻭﺭ":   case "۶":  return 6;
    case "ﻢﻫﺭ":      case "۷":  return 7;
    case "ﺂﺑﺎﻧ":     case "۸":  return 8;
    case "ﺁﺫﺭ":      case "۹":  return 9;
    case "ﺩی":       case "۱۰": return 10;
    case "ﺐﻬﻤﻧ":     case "۱۱": return 11;
    case "ﺎﺴﻔﻧﺩ":    case "۱۲": return 12;

  }

  return NULL;
}
