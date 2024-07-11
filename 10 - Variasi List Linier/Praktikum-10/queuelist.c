// NIM      : 18222105
// Nama     : Rajendra Farras Rayhan
// Tanggal  : 6 Desember 2023
// Topik    : Pasca Praktikum Variasi List Linier
// Deskripsi: Queuelist

#include <stdlib.h>
#include "queuelist.h"

/* Prototype manajemen memori */
void Alokasi(address *P, infotype X)
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
{
    (*P) = (address)malloc(sizeof(ElmtQueue));
    if (*P != Nil){
        Info(*P) = X;
        Next(*P) = Nil;
    }
}
void Dealokasi(address P)
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{
    if(P != Nil){
        free(P);
    }
}
boolean IsEmpty(Queue Q)
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
{
    return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}
int NbElmt(Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
{
    int ctr = 0;
    address P = Head(Q);
    while (P != Nil){
        ctr++;
        P = Next(P);
    }
    return ctr;
}

/*** Kreator ***/
void CreateEmpty(Queue *Q)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
{
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}
/*** Primitif Add/Delete ***/
void Enqueue(Queue *Q, infotype X)
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
{
    if(IsEmpty(*Q)){
        address P;
        Alokasi(&P, X);
        if(P != Nil){
            Head(*Q) = P;
            Tail(*Q) = P;
        }
    }
    else{
        address P;
        Alokasi(&P, X);
        if(P != Nil){
            address lastElmt = Tail(*Q);
            Next(lastElmt) = P;
            Tail(*Q) = P;
        }
    }
}
void Dequeue(Queue *Q, infotype *X)
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
{
    if(NbElmt(*Q) == 1){
        (*X) = InfoHead(*Q);
        address P = Head(*Q);
        Next(P) = Nil;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
        Dealokasi(&P);
    }
    else{
        (*X) = InfoHead(*Q);
        address P = Head(*Q);
        Head(*Q) = Next(P);
        Next(P) = Nil;
        Dealokasi(&P);
    }
}