#include <stdio.h>
#include "boolean.h"
#include "mesinkarakter.h"
#include "mesinkata.h"

int main()
{
    int sum = 0;
    STARTWORD(); sum += currentWord.Length;
    do
    {
        ADVWORD();
        if(EOP) sum += currentWord.Length;
    } while (!EOP);
    printf("%d\n", sum);
}