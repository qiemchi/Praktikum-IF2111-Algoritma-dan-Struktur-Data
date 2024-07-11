// NIM      : 18222105
// Nama     : Rajendra Farras Rayhan
// Tanggal  : 6 Desember 2023
// Topik    : Pasca Praktikum Variasi List Linier
// Deskripsi: Setlist

#include <stdlib.h>
#include "setlist.h"

/* MODUL Set
Deklarasi set yang diimplementasikan menggunakan list dengan struktur berkait
*/

/* ********* Prototype ********* */

address Alokasi (infotype Elmt)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=Elmt, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    address P = (address)malloc(sizeof(ElmtSet));
    if(P != Nil){
        Info(P) = Elmt;
        Next(P) = Nil;
    }
    return P;
}

void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong */
{
    First(*S) = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S)
/* Mengirim true jika Set S kosong*/
{
    return (First(S) == Nil);
}

/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt)
/* Menambahkan Elmt sebagai elemen terakhir Set S. */
/* I.S. S mungkin kosong
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota terakhir dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
{
    if(IsEmpty(*S)){
        address newElmt = Alokasi(Elmt);
        if(newElmt != Nil){
            First(*S) = newElmt;
        }
    }
    else if(!IsMember(*S, Elmt)){
        address P = First(*S);
        while (Next(P) != Nil){
            P = Next(P);
        } /* P adalah elemen terakhir */
        address newElmt = Alokasi(Elmt);
        if(newElmt != Nil){
            Next(P) = newElmt;
        }
    }
}

void Delete(Set *S, infotype Elmt)
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */
{
    if(Count(*S) == 1){
        address P = First(*S);
        First(*S) = Nil;
        Dealokasi(&P);
    }
    else if(IsMember(*S, Elmt)){
        address P = First(*S);
        address Prec = Nil;
        while (Info(P) != Elmt){
            Prec = P;
            P = Next(P);
        } /* Info(P) == Elmt */
        if (Prec == Nil){ /* Ditemukan di elemen pertama */
            First(*S) = Next(P);
        }
        else{ /* Ditemukan di elemen lainnya */
            Next(Prec) = Next(P);
        }
        Dealokasi(&P);
    }
}

boolean IsMember(Set S, infotype Elmt)
/* Mengembalikan true jika Elmt adalah member dari S */
{
    boolean found = false;
    address P = First(S);
    while ((P != Nil) && (!found)){
        if(Info(P) == Elmt){
            found = true;
        }
        else{
            P = Next(P);
        }
    }

    return found;
}

int Count(Set S)
/* Mengembalikan jumlah elemen/anggota di dalam S */
{
    int ctr = 0;
    address P = First(S);
    while (P != Nil){
        ctr++;
        P = Next(P);
    }
    return ctr;
}