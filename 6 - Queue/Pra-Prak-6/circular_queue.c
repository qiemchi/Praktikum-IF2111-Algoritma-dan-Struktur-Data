/* MODUL CIRCULAR QUEUE */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */
/* Implementasi Queue menggunakan circular buffer (Alternatif III) */
#include "boolean.h"
#include "circular_queue.h"
#include <stdio.h>


/* ********* Prototype ********* */
boolean IsEmpty (Queue Q)
{
  return (IDX_HEAD(Q)== IDX_UNDEF && IDX_TAIL(Q) == IDX_UNDEF);
}

/* Mengirim true jika Q kosong */
/* yaitu ketika idxHead=IDX_UNDEF dan idxTail=IDX_UNDEF */
boolean IsFull (Queue Q)
{
  return (Length(Q) == IDX_MAX+1);
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu ketika idxHead=0 dan idxTail=IDX_MAX atau idxHead=idxTail+1 ketika idxHead > idxTail */
int Length (Queue Q)
{
  int len;
  if (IsEmpty(Q)) len = 0;
  else if (IDX_TAIL(Q) >= IDX_HEAD(Q))
  {
    len = IDX_TAIL(Q) - IDX_HEAD(Q) + 1;
  }
  else
  {
    len = IDX_MAX - IDX_HEAD(Q) + IDX_TAIL(Q);
  }

  return len;
}
/* Mengirimkan banyaknya elemen Q, 0 jika kosong */

/* *** Kreator *** */
void CreateQueue (Queue * Q)
{
  IDX_HEAD(* Q) = IDX_UNDEF;
  IDX_TAIL(* Q) = IDX_UNDEF;
}        
/* I.S. sembarang */
/* F.S. mengembalikan Q kosong dengan kondisi sbb: */
/* - idxHead=IDX_UNDEF; */
/* - idxTail=IDX_UNDEF. */

/* *** Primitif Add/Delete *** */
void enqueue (Queue * Q, ElType X)
{
  if (Length(*Q) == 0)
  {
    IDX_HEAD(*Q) = 0;
    IDX_TAIL(*Q) = 0;
    HEAD(*Q) = X;
  }
  else
  {
    IDX_TAIL(*Q) = (IDX_TAIL(*Q) + 1) % (IDX_MAX+1);
    TAIL(*Q) = X;
  }
}
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. Tail "maju" dengan mekanisme circular buffer,
        X menjadi idxTail yang baru
        Jika Q kosong, idxHead dimulai dari 0 */
ElType dequeue (Queue * Q)
{
  ElType val;
  if (IDX_HEAD(*Q) == IDX_TAIL(*Q))
  {
    val = HEAD(*Q);
    IDX_HEAD(*Q) = IDX_UNDEF;
    IDX_TAIL(*Q) = IDX_UNDEF;
  }
  else
  {
    val = HEAD(*Q);
    IDX_HEAD(*Q) = (IDX_HEAD(*Q) + 1) % (IDX_MAX+1);
  }
  return val;
}
/* Proses: Menghapus idxHead pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada idxHead;
        Head "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* *** Display Queue *** */
void displayQueue(Queue q)
{
  if (IsEmpty(q)) printf("[]");
  else
  { 
    printf("[");
    if (IDX_HEAD(q) > IDX_TAIL(q))
    { 
      for (int i = IDX_HEAD(q); i <= IDX_MAX; i++)
      {
        printf("%d,", q.Tab[i]);
      }

      for (int j = 0; j <= IDX_TAIL(q); j++)
      {
        if (j == IDX_TAIL(q)) printf("%d]\n", q.Tab[j]);
        else printf("%d,", q.Tab[j]);
      }
    }
    else
    {
      for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++)
      {
        if (i == IDX_TAIL(q)) printf("%d]\n", q.Tab[i]);
        else printf("%d,", q.Tab[i]);
      }
    }
  }
}
/* Proses : Menuliskan isi Queue dengan traversal dan mekanisme circular buffer;
/* Queue ditulis di antara kurung siku; antara dua elemen dipisahkan dengan separator "koma" */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
/* Note: Output mengandung newline */