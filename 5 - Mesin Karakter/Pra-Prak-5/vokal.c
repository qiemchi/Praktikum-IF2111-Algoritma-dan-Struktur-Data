#include <stdio.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;

static FILE * pita;
static int retval;


int main(){
    char vokal, str;
    char listVokal[100];
    int i = 0;

    scanf("%c\n", &vokal);
    
    
    START();

    while(IsEOP(str) == false){

      if ((GetCC() == 'a') | (GetCC() == 'i') | (GetCC() == 'u') | (GetCC() == 'e') | (GetCC() == 'o') && (GetCC() != vokal))
      {
        listVokal[i] = GetCC();
        i++;
      }

      ADV();

    }

    if (i > 0){
      for (int j = 0; j < i; j++)
      {
        printf("%c", listVokal[j]);
      }
      printf(" %d\n", i);
    }
    else
    {
      printf("%d\n", i);
    }

}