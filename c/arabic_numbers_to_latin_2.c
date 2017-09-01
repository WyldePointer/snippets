#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *arabic_numbers_to_latin(char *numbers){

  char *latin = NULL;
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

    if (numbers[i] == 0xffffffb0){
      latin[j] = '0';
    } else if (numbers[i] == 0xffffffb1){
      latin[j] = '1';
    } else if (numbers[i] == 0xffffffb2){
      latin[j] = '2';
    } else if (numbers[i] == 0xffffffb3){
      latin[j] = '3';
    } else if (numbers[i] == 0xffffffb4){
      latin[j] = '4';
    } else if (numbers[i] == 0xffffffb5){
      latin[j] = '5';
    } else if (numbers[i] == 0xffffffb6){
      latin[j] = '6';
    } else if (numbers[i] == 0xffffffb7){
      latin[j] = '7';
    } else if (numbers[i] == 0xffffffb8){
      latin[j] = '8';
    } else if (numbers[i] == 0xffffffb9){
      latin[j] = '9';
    } 

    j++;
    i++;

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
