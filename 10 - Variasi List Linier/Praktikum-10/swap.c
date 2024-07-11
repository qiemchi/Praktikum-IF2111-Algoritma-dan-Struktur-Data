// NIM      : 18222105
// Nama     : Rajendra Farras Rayhan
// Tanggal  : 6 Desember 2023
// Topik    : Pasca Praktikum Variasi List Linier
// Deskripsi: Swap List Double Pointer

#include <stdlib.h>
#include "swap.h"

address AddressAtIndex(List L, infotype x)
/* 
Mencari address suatu node pada element ke- X
*/
{
    int idx = 1;
    address P = First(L);
    while((idx < x) && (P != Nil)){
        idx++;
        P = Next(P);
    } /* idx == x, P adalah address dari node element ke-x */
    return P;
}
void Swap(List *L1)
/*
Kondisi awal: L1 sudah terisi dengan beberapa node.
Lakukan swap node pada node yang ada di tengah dari suatu List
*/
{
    int angka_pertama, angka_kedua, selisih;
    address Pawal, Pakhir;
    int nbelmt = 0;
    address temp = First(*L1);
    while (temp != Nil)
    {
        nbelmt++;
        temp = Next(temp);
    }
    scanf("%d %d", &angka_pertama, &angka_kedua);
    if((angka_pertama > 1) && (angka_kedua > 1) && (angka_pertama < nbelmt) && (angka_kedua < nbelmt) && (angka_pertama != angka_kedua)){
        if(angka_pertama < angka_kedua){
            Pawal = AddressAtIndex(*L1, angka_pertama);
            Pakhir = AddressAtIndex(*L1, angka_kedua);
            selisih = angka_kedua - angka_pertama; /* selisih indeks elemen swap */
        }
        else{ /* angka_pertama > angka_kedua */
            Pawal = AddressAtIndex(*L1, angka_kedua);
            Pakhir = AddressAtIndex(*L1, angka_pertama);
            selisih = angka_pertama - angka_kedua; /* selisih indeks elemen swap */
        }
        Next(Prev(Pawal)) = Pakhir; /* ujung-ujungnya ditukar dulu */
        Prev(Next(Pakhir)) = Pawal; 
        if(selisih > 1){
            Prev(Next(Pawal)) = Pakhir; /* benerin sisi sebelah dalam dari yang mau di-swap */
            Next(Prev(Pakhir)) = Pawal;
            address penjaga = Prev(Pawal); /* address penjaga agar tidak salah swap */
            address penjaga2 = Prev(Pakhir);
            address penjaga3 = Next(Pawal);
            address penjaga4 = Next(Pakhir);
            Next(Pawal) = penjaga4; /* swap sisi luar elemen yang mau di-swap */
            Next(Pakhir) = penjaga3;
            Prev(Pawal) = penjaga2;
            Prev(Pakhir) = penjaga;
        }
        else{ /* selisih == 1 */
            address penjaga = Prev(Pawal); /* address penjaga agar tidak salah swap */
            address penjaga2 = Next(Pakhir);
            Prev(Pakhir) = penjaga;
            Next(Pawal) = penjaga2;
            Prev(Pawal) = Pakhir;
            Next(Pakhir) = Pawal;
        }
        // printf("Print Forward: ");
        // PrintForward(*L1);
        // printf("\n\nPrint Backward: ");
        // PrintBackward(*L1);
        // printf("\n");
    }
}

// int main(){
//     printf("MILESTONE1\n");
//     List L;
//     CreateEmpty(&L);
//     InsVLast(&L, 2);
//     InsVLast(&L, 3);
//     InsVLast(&L, 5);
//     InsVLast(&L, 8);
//     InsVLast(&L, 6);
//     InsVLast(&L, 11);
//     InsVLast(&L, 10);
//     PrintForward(L);
//     printf("\n");
//     Swap(&L);
//     printf("MILESTONE2\n");
//     return 0;
// }