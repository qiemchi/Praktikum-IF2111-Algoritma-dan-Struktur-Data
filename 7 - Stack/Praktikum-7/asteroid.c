// NIM              : 18222105
// NAMA             : Rajendra Farras Rayhan
// Tanggal          : 29 November 2023
// Topik Praktikum  : Pasca-Praktikum Stack
// Deskripsi        : Game Asteroid Tabrak Tabrak Masuk

#include <stdio.h>
#include <stdlib.h>
#include "asteroid.h"

boolean isCollision(infotype a, infotype b)
/* Mengirim true jika terjadi tabrakan */
/* yaitu ketika a > 0 dan b < 0 */
{
    return((a > 0) && (b < 0));
}

void collision(int n, infotype *asteroids, Stack *remaining)
/* Proses: Mengisi stack dengan asteroid yang tersisa setelah tabrakan. 
    Asteroid dengan ukuran lebih besar tidak akan hancur, dan apabila kedua asteroid ukurannya sama maka 
    akan sama-sama hancur.  */
/* I.S Array asteroids pasti terisi dengan elemen positif atau negatif, Stack remaining telah terbentuk */
/* F.S Stack remaining terisi oleh sisa asteroid yang tidak hancur */
/*
   Contoh simulasi:
   - Input: [5,10,-5]
     Output: [5,10]
     Penjelasan: 5(->) 10(->) -5(<-) Asteroid 5 dan 10 bergerak ke kanan, -5 ke kiri. Asteroid 10 lebih besar dari -5, sehingga -5 hancur.

   - Input: [-10,10]
     Output: [-10,10]
     Penjelasan: -10(<-) 10(->) Kedua asteroid bergerak ke arah berbeda dan tidak bertemu, jadi tidak ada yang hancur.

   - Input: [1,-2,10,5]
     Output: [-2,10,5]
     Penjelasan: 1(->) -2(<-) akan bertabrakan, namun asteroid -2 lebih besar sehingga asteroid 1 hancur. Lalu, -2(<-) 10(->) tidak akan bertabrakan. 5 tetap melaju karena bergerak ke arah yang sama.
*/
{
    Stack tempStack;
    CreateEmpty(&tempStack);
    for(int i = 0; i < n; i++){
        boolean kiri = false;
        boolean sama = false;
        boolean kanan = false;
        if(IsEmpty(tempStack)){ /* Stack kosong */
            Push(&tempStack, asteroids[i]);
        }
        else if(!isCollision(InfoTop(tempStack),asteroids[i])){ /* Gak ada tabrakan yang terjadi */
            Push(&tempStack, asteroids[i]);
        }
        else{ /* Terjadi tabrakan */
            while((!IsEmpty(tempStack)) && (isCollision(InfoTop(tempStack), asteroids[i])) && (!kiri) && (!sama)){
                int X;
                Pop(&tempStack, &X);
                kiri = false;
                sama = false;
                kanan = false;
                if((abs(X)) > (abs(asteroids[i]))){ /* Yang di sebelah kiri lebih besar */
                    Push(&tempStack, X);
                    kiri = true;
                }
                else if ((abs(X)) == (abs(asteroids[i]))) {/* Kalau kanan dan kiri sama besar */
                    sama = true;
                }
                else{ /* Yang di sebelah kanan lebih besar */
                    kanan = true;
                }
            }
            if(kanan){
                Push(&tempStack, asteroids[i]);
            }
        }
    }
    CreateEmpty(remaining);
    while(!IsEmpty(tempStack)){
        int Elmt;
        Pop(&tempStack, &Elmt);
        Push(remaining, Elmt);
    }
}

void displayAsteroids(Stack S)
/* Proses : mereverse isi stack dari parameter kemudian mencetak elemen-elemen stack tersebut ke layar. */
/* I.S. S boleh kosong */
/* F.S. Jika S tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen asteroid bernilai 4, 5, -2 akan dicetak: [-2,4,5] */
/* Jika Stack kosong : menulis [] */
/* Terdapat new line setelah kurung tutup */
/* Hint: Buatlah stack baru untuk meng-copy isi dari stack parameter */
{
    printf("[");
    if(!IsEmpty(S)){
        Stack RevStack;
        CreateEmpty(&RevStack);
        while(!IsEmpty(S)){
            int X;
            Pop(&S, &X);
            Push(&RevStack, X);
            printf("%d", X);
            if(!IsEmpty(S)){
                printf(",");
            }
        }
        while(!IsEmpty(RevStack)){
            int X;
            Pop(&RevStack, &X);
            Push(&S, X);
        }
    }
    printf("]\n");
}