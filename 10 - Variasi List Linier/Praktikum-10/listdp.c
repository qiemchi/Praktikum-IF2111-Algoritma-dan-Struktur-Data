#include <stdio.h>
#include <stdlib.h>
#include "listdp.h"

boolean IsEmpty (List L){
    /* List kosong : First(L) = Nil dan Last(L) = Nil */
    return First(L) == Nil && Last(L) == Nil;
}

void CreateEmpty (List *L){
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
    First(*L) = Nil;
    Last(*L) = Nil;
}

address Alokasi (infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
    address P;

    P = (address) malloc (sizeof(ElmtList));
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
        Prev(P) = Nil;
    }
    return P;
}

void Dealokasi (address P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
    free(P);
}

address Search (List L, infotype X){
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
    address P;
    P = First(L);
    if (IsEmpty(L)) return Nil;
    while (P != Nil && Info(P) != X){
        P = Next(P);
    }
    return P;
}

void InsVFirst (List *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    address P;
    P = Alokasi(X);
    if (P != Nil){
        if (First(*L) == Nil){
            Last(*L) = P;
        } 
        else {
            Prev(First(*L)) = P;
        }
        Next(P) = First(*L);
        First(*L) = P;
    }
}

void InsVLast (List *L, infotype X){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */\
    address P;
    P = Alokasi(X);
    if (P != Nil){
        if (Last(*L) == Nil){
            First(*L) = P;
        } 
        else {
            Next(Last(*L)) = P;
        }
        Prev(P) = Last(*L);
        Last(*L) = P;
    }
}

void DelVFirst (List *L, infotype *X){
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */\
    address del;
    del = First(*L);
    *X = Info(First(*L));
    if (First(*L) == Last(*L)){
        First(*L) = Nil;
        Last(*L) = Nil;
    }
    else{
        Prev(Next(del)) = Nil;
        First(*L) = Next(del);
    }
    Dealokasi(del);
}

void DelVLast (List *L, infotype *X){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
    address del;
    del = Last(*L);
    *X = Info(Last(*L));
    if (First(*L) == Last(*L)) {
        First(*L) = Nil;
        Last(*L) = Nil;
    }
    else{
        Next(Prev(del)) = Nil;
        Last(*L) = Prev(del);
    }
    Dealokasi(del);
}

void InsertFirst (List *L, address P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
    if (First(*L) == Nil){
        Last(*L) = P;
    } else {
        Prev(First(*L)) = P;
    }
    Next(P) = First(*L);
    First(*L) = P;
}
void InsertLast (List *L, address P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    if (P != Nil){
        if (IsEmpty(*L)) InsertFirst(L, P);
        else{
            Next(Last(*L)) = P;
            Prev(P) = Last(*L);
            Last(*L) = P;
        }
    }
}

void InsertAfter (List *L, address P, address Prec){
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    if (Prec == Last(*L)){
        InsertLast(L, P);
    } else {
        Next(P) = Next(Prec);
        Prev(Next(Prec)) = P;
        Prev(P) = Prec;
        Next(Prec) = P;
    }
}

void InsertBefore (List *L, address P, address Succ){
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
    if (Succ == First(*L)){
        InsertFirst(L, P);
    } else {
        Prev(P) = Prev(Succ);
        Next(Prev(Succ)) = P;
        Next(P) = Succ;
        Prev(Succ) = P;
    }
}

void DelFirst (List *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
    *P = First(*L);
    if (First(*L) == Last(*L)){
        First(*L) = Nil;
        Last(*L) = Nil;
    }else{
        First(*L) = Next(First(*L));
        Prev(First(*L)) = Nil;
    }
}

void DelLast (List *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
    if (First(*L) == Last(*L)) DelFirst(L, P);
    else{
        *P = Last(*L);
        Last(*L) = Prev(Last(*L));
        Next(Last(*L)) = Nil;
    } 
}
void DelP (List *L, infotype X){
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
    address loc;
    loc = Search(*L, X);
    if (loc != Nil){
        if (loc == First(*L)){
            DelFirst(L, &loc);
        } else if (loc  == Last(*L)){
            DelLast(L, &loc);
        } else {
            address del;
            DelAfter(L, &del, Prev(loc));
        }
    }
}

void DelAfter (List *L, address *Pdel, address Prec){
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    *Pdel = Next(Prec);
    if ((*Pdel) == First(*L)){
        DelFirst(L, Pdel);
    } else if ((*Pdel) == Last(*L)){
        DelLast(L, Pdel);
    } else {
        Prev(Next(*Pdel)) = Prec;
        Next(Prec) = Next(*Pdel);
    }
}

void DelBefore (List *L, address *Pdel, address Succ){
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    *Pdel = Prev(Succ);
    if(*Pdel == First(*L)){
        DelFirst(L, Pdel);
    }else{
        DelAfter(L, Pdel, Prev(*Pdel));
    }
}

void PrintForward (List L){
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    address P;
    printf("[");
    if (!IsEmpty(L)){
        P = First(L);
        while (P != Nil) {
            printf("%d", Info(P));
            P = Next(P);

            if (P != Nil)
                printf(",");
        }
    }
    printf("]\n");
}

void PrintBackward (List L){
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    address P;
    printf("[");
    if (!IsEmpty(L)){
        P = Last(L);
        while (P != Nil) {
            printf("%d", Info(P));
            P = Prev(P);

            if (P != Nil)
                printf(",");
        }
    }
    printf("]\n");

}