#include "copyQueue.h"
#include <stdio.h>


#include "boolean.h"
#include "queue.h"
#include <stdio.h>

/* *** Kreator *** */
void CreateQueue(Queue *q)
{
  IDX_HEAD(*q) = IDX_UNDEF;
  IDX_TAIL(*q) = IDX_UNDEF;
}        
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IwDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmpty(Queue q)
{
  return (IDX_HEAD(q)== IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF);
}

/* Mengirim true jika q kosong: lihat definisi di atas */

boolean isFull(Queue q)
{
  return (length(q) == CAPACITY);
}
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int length(Queue q)
{ 
  int len;
  if (isEmpty(q)) len = 0;
  else if (IDX_TAIL(q)>= IDX_HEAD(q))
  {
    len = IDX_TAIL(q) - IDX_HEAD(q) + 1;
  }
  else
  {
    len = CAPACITY - IDX_HEAD(q) + IDX_TAIL(q) + 1;
  }

  return len;
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val)
{
  if (length(*q) == 0)
  {
    IDX_HEAD(*q) = 0;
    IDX_TAIL(*q) = 0;
    HEAD(*q) = val;
  }
  else
  {
    IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
    TAIL(*q) = val;
  }
}
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void dequeue(Queue *q, ElType *val)
{
  if (IDX_HEAD(*q) == IDX_TAIL(*q))
  {
    *val = HEAD(*q);
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
  }
  else
  {
    *val = HEAD(*q);
    IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITY;
  }
}
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display Queue *** */
void displayQueue(Queue q)
{
  if (isEmpty(q)) printf("[]");
  else
  { 
    printf("[");
    if (IDX_HEAD(q) > IDX_TAIL(q))
    { 
      for (int i = IDX_HEAD(q); i < CAPACITY; i++)
      {
        printf("%d,", q.buffer[i]);
      }

      for (int j = 0; j <= IDX_TAIL(q); j++)
      {
        if (j == IDX_TAIL(q)) printf("%d]\n", q.buffer[j]);
        else printf("%d,", q.buffer[j]);
      }
    }
    else
    {
      for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++)
      {
        if (i == IDX_TAIL(q)) printf("%d]\n", q.buffer[i]);
        else printf("%d,", q.buffer[i]);
      }
    }
  }
}
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */

// Menyalin queue.
void copyQueue(Queue *queueInput, Queue *queueOutput)
{

  if (isEmpty(*queueInput) == false)   
  {

      int i = IDX_HEAD(*queueInput);
      int tail = IDX_TAIL(*queueInput);

      ElType val;

      while (i != tail)
      {
        dequeue(queueInput, &val);
        enqueue(queueInput, val);
        enqueue(queueOutput, val);
        i = IDX_HEAD(*queueInput);
      }

      dequeue(queueInput, &val);
      enqueue(queueInput, val);
      enqueue(queueOutput, val);
  }

}
/* Proses: Menyalin isi dari queueInput ke queueOutput */
/* I.S. queueInput mungkin kosong, tabel penampung elemen queueInput TIDAK penuh */
/* F.S. queueOutput memiliki isi queue yang sama */
/*
    Contoh input:
    queueInput : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
    queueOutput: queue kosong

    Contoh output:
    queueInput:  [2,3,4,5,6]
    queueOutput: [2,3,4,5,6]
*/

/*
    Catatan
    - Hati-hati jangan sampai algoritma Anda mengubah hasil akhir dari queueInput juga.
      Elemen di queueInput harus tetap sama setelah algoritma dijalankan.
    Hint
    - Buat queue baru selain queueInput dan queueOutput untuk tempat penyimpanan
      queueInput sementara.
*/

int main()
{
	Queue que1, que2;

	CreateQueue(&que1);
	CreateQueue(&que2);

	enqueue(&que1, 3);
	enqueue(&que1, 7);
	enqueue(&que1, 8);
	enqueue(&que1, 2);

	displayQueue(que1);
	displayQueue(que2);

	copyQueue(&que1, &que2);

	displayQueue(que1);
	displayQueue(que2);	
}