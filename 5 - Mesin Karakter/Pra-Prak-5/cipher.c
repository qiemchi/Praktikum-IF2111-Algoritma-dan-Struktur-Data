// NIM 				: 18221157
// Nama 			: Cathleen Lauretta
// Tanggal 			: 3 Oktober 2022
// Topik praktikum 	: Mesin Kata
// Deskripsi 		: Program yang membuat pergeseran dari input sesuai dengan panjang kata pertamanya

#include <stdio.h>
#include "mesinkarakterv2.h"
#include "mesinkata.h"
#include "boolean.h"

int main()
{
    STARTWORD();
    int length = currentWord.Length;

    while(!isEndWord())
    {
        for (int i = 0; i < currentWord.Length; i++)
        {
            currentWord.TabWord[i] += length % 26;
            
            if (currentWord.TabWord[i] > 90)
            {
                currentWord.TabWord[i] -= 26;
            }

            printf("%c", currentWord.TabWord[i]);
        }
        ADVWORD();

        if (isEndWord())
        {
            printf(".\n");
        } else
        {
            printf(" ");
        }
    }

    return 0;
}