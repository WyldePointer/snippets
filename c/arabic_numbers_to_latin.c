#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *arabic_numbers_to_latin(char *numbers){

  char *latin = NULL;
  char current_letter[3] = {0, 0, 0};
  unsigned int length = 0;
  unsigned int i = 0;
  unsigned int j = 0;

  if (strlen(numbers) < 1){
    return "0";
  }

  length = strlen(numbers) / 2;

  latin = malloc(sizeof(char) * length + 1);

  if (!latin){
    return "0";
  }

  for (i=1; i<=length*2; i++){

    if (i%2==0){
      continue;
    }

    current_letter[0] = numbers[i-1];
    current_letter[1] = numbers[i];
    current_letter[2] = '\0';

    if (strcmp(current_letter, "۰") == 0){
      latin[j] = '0';
    } else if (strcmp(current_letter, "۱") == 0){
      latin[j] = '1';
    } else if (strcmp(current_letter, "۲") == 0){
      latin[j] = '2';
    } else if (strcmp(current_letter, "۳") == 0){
      latin[j] = '3';
    } else if (strcmp(current_letter, "۴") == 0){
      latin[j] = '4';
    } else if (strcmp(current_letter, "۵") == 0){
      latin[j] = '5';
    } else if (strcmp(current_letter, "۶") == 0){
      latin[j] = '6';
    } else if (strcmp(current_letter, "۷") == 0){
      latin[j] = '7';
    } else if (strcmp(current_letter, "۸") == 0){
      latin[j] = '8';
    } else if (strcmp(current_letter, "۹") == 0){
      latin[j] = '9';
    } 

    j++;

  }

  return latin;
}

int main(int argc, char *argv[]){

  char *latin_numbers = NULL;

  if (argc < 2){
    fprintf(stderr, "usage: %s ۴۰۹۶\n", argv[0]);
    return 1;
  }

  latin_numbers = arabic_numbers_to_latin(argv[1]);

  printf("%s\n", latin_numbers);

  free(latin_numbers); 

  return 0;
}
