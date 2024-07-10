#include <stdio.h>
#include "reverse.h"

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


// void transferReverse(Queue* q1, Queue* q2)
// { 
//   Queue temp;
//   CreateQueue(&temp);
  
//   if (IDX_HEAD(*q1) > IDX_TAIL(*q1))
//   {
//     for (int i = IDX_TAIL(*q1); i >= 0; i--)
//     {
//       enqueue(&temp, q1->Tab[i]);
//     }

//     for (int j = IDX_MAX; j >= IDX_HEAD(*q1); j--)
//     {
//       enqueue(&temp, q1->Tab[j]);
//     }
//   }
  
//   else
//   {
//     for (int i = IDX_HEAD(*q1); i <= IDX_TAIL(*q1); i++)
//     {
//       enqueue(&temp, dequeue(q1));
//     }
//   }

//   for (int j = IDX_TAIL(temp); j >= IDX_HEAD(temp); j--)
//   {
//     enqueue(q2, temp.Tab[j]);
//   }
// }

void transferReverse(Queue* q1, Queue* q2)
// Proses: Memindahkan tiap elemen q1 ke q2 dengan urutan yang terbalik
// I.S.: q1 tidak kosong, q2 kosong. q1 dan q2 memiliki panjang yang sama
// F.S.: q1 kosong, q2 berisi elemen-elemen yang tadinya milik q1 dengan urutan yang terbalik
{
    Queue temp;
    CreateQueue(&temp);

    while (IsEmpty(*q1) == false) {
        if (IsEmpty(temp)) {
            enqueue(&temp, dequeue(q1));
        } else {
            ElType val = dequeue(q1);
            IDX_HEAD(temp) = (IDX_HEAD(temp) - 1 + (IDX_MAX+1)) % (IDX_MAX+1);
            HEAD(temp) = val;
        }
    }

    while (IsEmpty(temp) ==  false) {
        enqueue(q2, dequeue(&temp));
    }
}

int main(){
    Queue q1,q2;
    CreateQueue(&q1);
    CreateQueue(&q2);
    for(int i = 1; i <= 100; i++){
        enqueue(&q1, i);
    }

    IDX_HEAD(q1) = 5;
    IDX_TAIL(q1) = 4;

    displayQueue(q1);
    printf("ID Head : %d\n", IDX_HEAD(q1));
    printf("ID Tail : %d\n", IDX_TAIL(q1));
    printf("Head : %d\n", HEAD(q1));
    printf("Tail : %d\n", TAIL(q1));
    transferReverse(&q1, &q2);
    printf("-------------\n");
    displayQueue(q2);
    printf("ID Head : %d\n", IDX_HEAD(q2));
    printf("ID Tail : %d\n", IDX_TAIL(q2));
    printf("Head : %d\n", HEAD(q2));
    printf("Tail : %d\n", TAIL(q2));
    printf("-------------\n");
    displayQueue(q1);
}