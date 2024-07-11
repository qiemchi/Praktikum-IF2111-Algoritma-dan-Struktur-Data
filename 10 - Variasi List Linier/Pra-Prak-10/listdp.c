/* File : listdp.h */
/* ADT List dengan Double Pointer */
/* Representasi berkait dengan address adalah pointer */
/* infotype adalah integer */

#include "boolean.h"
#include "listdp.h"
#include <stdio.h>
#include <stdlib.h>

/* Definisi list : */
/* List kosong : First(L) = Nil dan Last(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

/* Notasi Akses */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
{
    return (First(L) == Nil && Last(L) == Nil);
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
{
    First(*L) = Nil;
    Last(*L) = Nil;
}
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
{
    ElmtList *value = (ElmtList *) malloc(sizeof (ElmtList));

    if (value != Nil)   // Berhasil dialokasi
    {
        Info(value) = X;
        Next(value) = Nil;
        Prev(value) = Nil;
       
    } 
    return value;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
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
    while (P != Nil && Info(P) != X) 
    {
        P = Next(P);
    }
    return P;
}
/* Mencari apakah ada elemen list dengan Info(P)=X */
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
    {
    address p = Alokasi(X);

    if (p != Nil)
    {
        InsertLast(L, p);
    }
}
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
{

    address P;
    DelFirst(L, &P);
    *X = Info(P);
    Dealokasi(P);

}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X)
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
    
    Next(P) = First(*L);
    
    if (!IsEmpty(*L))
    {
        Prev(First(*L)) = P;
    } else  // List merupakan list kosong
    {
        Last(*L) = P;
    }

    First(*L) = P;

}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertLast (List *L, address P)
{
    Prev(P) = Last(*L);

    if (!IsEmpty(*L))
    {
        Next(Last(*L)) = P;
    } else  // List merupakan list kosong
    {
        First(*L) = P;
    }

    Last(*L) = P;
}

/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter (List *L, address P, address Prec)
{
    Next(P) = Next(Prec);

    if (Next(Prec) != Nil)
    {
        Prev(Next(Prec)) = P;
    } else  // Next(Prec) = Nil, artinya Prec berada di Last L
    {
        Last(*L) = P;
    }

    Next(Prec) = P;
    Prev(P) = Prec;
}

/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBefore (List *L, address P, address Succ)
{
    Prev(P) = Prev(Succ);

    if (Prev(Succ) != Nil)
    {
        Next(Prev(Succ)) = P;
    } else  // Prev(Succ) = Nil, artinya Prev berada di First L
    {
        First(*L) = P;
    }

    Prev(Succ) = P;
    Next(P) = Succ;
}

/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
{
    *P = First(*L);

    if (First(*L) == Last(*L))  // List satu elemen
    {
        Last(*L) = Nil;
    } else
    {
        Prev(Next(First(*L))) = Nil;
    }

    First(*L) = Next(First(*L));
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast (List *L, address *P)
{
    
    *P = Last(*L);

    if(First(*L) == Last(*L))
    {
        First(*L) = Nil;
        Last(*L) = Nil;
    } else
    {
        Next(Prev(*P)) = Nil;
    }

    Last(*L) = Prev(*P);
    

}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelP (List *L, infotype X)
{
    address p = Search(*L, X);

    if (p != Nil) // X ada
    {
        address q;

        if (p == First(*L))
        {
            DelFirst(L, &q);
        } else if (p == Last(*L))
        {
            DelLast(L, &q);
        } else
        {
            q = First(*L);

            while (Info(q) != X)
            {
                q = Next(q);
            }

            // Info(q) = X
            Prev(Next(q)) = Prev(q);
            Next(Prev(q)) = Next(q);

            Next(q) = Nil;
            Prev(q) = Nil;
        }

        Dealokasi(q);
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelAfter (List *L, address *Pdel, address Prec)
{
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);

    if (Next(*Pdel) != Nil)
    {
        Prev(Next(*Pdel)) = Prec;
    } else  // Next(*Pdel) = Nil, artinya *Pdel = Last(*L)
    {
        Last(*L) = Prec;
    }

    Next(*Pdel) = Nil;
    Prev(*Pdel) = Nil;
}
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBefore (List *L, address *Pdel, address Succ)
{
    *Pdel = Prev(Succ);
    Prev(Succ) = Prev(*Pdel);

    if (Prev(*Pdel) != Nil)
    {
        Next(Prev(*Pdel)) = Succ;
    } else  // Prev(*Pdel) = Nil, artinya *Pdel = First(*L)
    {
        First(*L) = Succ;
    }

    Next(*Pdel) = Nil;
    Prev(*Pdel) =  Nil;
}
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L)
{
    printf("[");

    if (!IsEmpty(L))
    {
        address q = First(L);

        while (q != Nil)
        {
            printf("%d", Info(q));

            if (Next(q) != Nil)
            {
                printf(",");
            }

            q = Next(q);

        }
    }

    printf("]\n");

}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
/* Terdapat newline di akhir setelah tutup kurung */
void PrintBackward (List L)
{

    printf("[");

    if (!IsEmpty(L))
    {
        address q = Last(L);

        while (q != Nil)
        {
            printf("%d", Info(q));

            if (Prev(q) != Nil)
            {
                printf(",");
            }

            q = Prev(q);

        }
    }

    printf("]\n");

}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
/* Terdapat newline di akhir setelah tutup kurung */