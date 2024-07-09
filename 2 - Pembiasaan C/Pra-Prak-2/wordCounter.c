#include <stdio.h>
#include <string.h>

int main(){

  int i = 0; int count = 1;
  char str[200]; 

  fgets(str, 200, stdin);

  for (i = 0; str[i] != '\0'; i++){

    if(str[i] == ' '){
      count = count + 1;
    }
  }

  printf("%d\n", count);

  return 0;
}