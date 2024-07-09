#include <stdio.h>

int main(){
  int baris, i, k = 0;
  int j = 0;

  scanf("%d", &baris);

  for(i = 1; i <= baris; ++i, k = 0){

    for(j = 1; j <= baris - i; ++j ){
      printf(" ");
    }
    
    while (k < ((2*i) - 1)){
      printf("*");
      ++k;
    }

    printf("\n");
  }

  for(i = baris; i > 0; i--, k = 0){

    for(j = 1; j <= baris - i; ++j ){
      printf(" ");
    }
    
    while (k < ((2*i) - 1)){
      printf("*");
      ++k;
    }

    printf("\n");
  }

  return 0;
}