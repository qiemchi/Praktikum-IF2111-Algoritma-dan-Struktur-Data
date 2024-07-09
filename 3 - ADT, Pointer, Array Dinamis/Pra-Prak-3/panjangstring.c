// Nama : Rizqi Andhika Pratama
// NIM : 18222118
// Tanggal : 20 September 2023
// Topik praktikum  : Pra-Praktikum 3 - ADT, Pointer dan Array Dinamik
// Deskripsi        : Program yang membuat implementasi dari panjangstring.h

/* *** Definisi ABSTRACT DATA TYPE POINT *** */
#include <stdio.h>
#include "panjangstring.h"

// menerima argumen pointer kepada karakter pertama dari sebuah string yang panjangnya tidak diketahui
// dan memberikan output berupa panjang string tersebut, dengan batasan string input memiliki karakter
// '\0' pada akhir string

int panjangString(char* string){
    int i = 0;
    while (string[i] != "\0")
    {
      i ++;
    }

    return i;
}