/* File : listsirkuler.h */
/* ADT List Sirkuler dengan elemen terakhir menunjuk pada elemen pertama */
/* Representasi berkait dengan address adalah pointer */
/* infotype adalah integer */

#include "boolean.h"
#include "listsirkuler.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
{
    return (First(L) == Nil);
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
{
    First(*L) = Nil;
}
/* I.S. L sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
{
    address P = (address) malloc (sizeof(ElmtList));
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;

}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address P)
{
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
{
    address P = First(L);
    if (P != Nil) {
        do {
            if (Info(P) == X) {
                return P;
            }
            P = Next(P);
        } while (P != First(L));
    }
    return Nil;
}
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
{

    address p = Alokasi(X);

    if (p != Nil)
    {
        InsertFirst(L, p);
    }

}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X)
{
    address p = Alokasi(X);

    if (p != Nil)
    {
        InsertLast(L, p);
    }

}

/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype * X)
{
    address p;
    DelFirst(L, &p);
    *X = Info(p);
    Dealokasi(p);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype * X)
{
    address p;
    DelLast(L, &p);
    *X = Info(p);
    Dealokasi(p);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
{
    if (IsEmpty(*L))
    {
        First(*L) = P;
        Next(P) = P;
    } 

    else
    {
        address last = First(*L);

        while (Next(last) != First(*L))
        {
            last = Next(last);
        }

        // Next(last) = First(*L), artinya pointer sudah berada di elemen terakhir
        Next(P) = First(*L);
        Next(last) = P;
        First(*L) = P;
    }

}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */

void InsertLast (List *L, address P)
{
    if (IsEmpty(*L))
    {
        InsertFirst(L, P);
    } 

    else
    {
        address last = First(*L);

        while (Next(last) != First(*L))
        {
            last = Next(last);
        }

        // Next(last) = First(*L), artinya pointer sudah berada di elemen terakhir
        Next(last) = P;
        Next(P) = First(*L);
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter (List *L, address P, address Prec)
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
{
    *P = First(*L);

    if (Next(First(*L)) == First(*L))   // List dengan satu elemen
    {
        First(*L) = Nil;
    } 
    
    else
    {
        address last = First(*L);

        while (Next(last) != First(*L))
        {
            last = Next(last);
        }

        First(*L) = Next(First(*L));
        Next(last) = First(*L);
    }

}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast (List *L, address *P)
{
    address Last = First(*L);

    while (Next(Last) != First(*L)) {
        Last = Next(Last);
    }

    (*P) = Last;

    if (Last == First(*L))    // kasus satu elemen
    {
        First(*L) = Nil;
    } 
    else
    {
        address Prec = First(*L);
        while (Next(Prec) != Last) 
        {
            Prec = Next(Prec);
        }
        Next(Prec) = First(*L);
    }
}

/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec)
{
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
    Next(*Pdel) = Nil;
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelP (List *L, infotype X)
{
    address p = Search(*L, X);

    if (p != Nil)   
    {
        if (p == First(*L))
        {
            DelFirst(L, &p);
        } else
        {
            address prev = First(*L);

            while (Next(prev) != p)
            {
                prev = Next(prev);
            }

            DelAfter(L, &p, prev);
            Dealokasi(p);
        }
    }
}

/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
{
    printf("[");

    if (!IsEmpty(L))
    {
        address p = First(L);

        do
        {
            printf("%d", Info(p));
            if (Next(p) != First(L))
            {
                printf(",");
            }
            p = Next(p);
        } while (p != First(L));
    }

    printf("]");
}
// {
//     printf("[");

//     if (!IsEmpty(L))
//     {
//         address p = First(L);

//         while (Next(p) != First(L))
//         {
//             printf("%d,", Info(p));
//             p = Next(p);
//         }

//         printf("%d", Info(p));

//     }

//     printf("]\n");
    
// }
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */