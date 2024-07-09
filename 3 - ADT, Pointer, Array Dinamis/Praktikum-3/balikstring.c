#include <stdio.h>

// Menerima argumen pointer yang merupakan sebuah string
// Mengembalikan panjang string
int panjangString(char* ch){
  int i = 0;
  while (*ch != '\0'){
    i++;
    ch++;

  }
  return i;
}

// Menerima argumen pointer yang merupakan sebuah string (diasumsikan tidak ada huruf kapital)
// Parameter str merupakan string yang akan dibalik
// Contoh : str adalah "slevel" maka akan terubah menjadi "levels"
void membalikString(char* str){
  int len = panjangString(str);
  char temp[len];
  int j = len - 1;
  int i = 0;

  for (j; j >= 0; j--){
    temp[j] = str[i];
    i++;
  }

  for (int k = 0; k < len; k++){
    str[k] = temp[k];
  }
}