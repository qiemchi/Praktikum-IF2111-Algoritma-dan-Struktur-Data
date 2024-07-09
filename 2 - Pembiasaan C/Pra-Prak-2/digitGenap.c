#include <stdio.h>

int totalDigit(int angka){
  int count = 0;

  while (angka > 0){
    count += 1;
    angka /= 10;
    
  }

  return count;
}

int main(){
  int N; int i; int count = 0;

  scanf("%d", &N);

  for(i = 1; i <= N; i++){
    int angka; int digit;
    scanf("%d", &angka);

    digit = totalDigit(angka);

    if (digit % 2 == 0){
      count += 1;
    }
  }

  printf("%d\n", count);
  return 0;
}