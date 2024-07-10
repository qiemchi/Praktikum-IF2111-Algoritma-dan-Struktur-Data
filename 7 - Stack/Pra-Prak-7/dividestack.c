#include "dividestack.h"
#include "stack.h"

// void CreateEmpty(Stack *S)
// {
//   Top(*S) = Nil;
// }

// /* ************ Predikat Untuk test keadaan KOLEKSI ************ */
// boolean IsEmpty(Stack S)
// {
//   return (Top(S) == Nil);
// }
// /* Mengirim true jika Stack kosong: lihat definisi di atas */
// boolean IsFull(Stack S)
// {
//   return (Top(S) == MaxEl-1);
// }
// /* Mengirim true jika tabel penampung nilai elemen stack penuh */

// /* ************ Menambahkan sebuah elemen ke Stack ************ */
// void Push(Stack * S, infotype X)
// {
//   Top(*S)++;
//   InfoTop(*S) = X;
// }
// /* Menambahkan X sebagai elemen Stack S. */
// /* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
// /* F.S. TOP bertambah 1, X menjadi TOP yang baru, */

// /* ************ Menghapus sebuah elemen Stack ************ */
// void Pop(Stack * S, infotype* X)
// {
//   *X = InfoTop(*S);
//   Top(*S)--;
// }
// /* Menghapus X dari Stack S. */
// /* I.S. S  tidak mungkin kosong */
// /* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */



void divideStack(Stack *s, Stack *oddS, Stack *evenS)
{
  Stack tempOdd, tempEven;
  CreateEmpty(&tempEven);
  CreateEmpty(&tempOdd);
  infotype val;

  while (!IsEmpty(*s))
  {
    Pop(s, &val);
    if (val % 2 == 0) 
    {
      Push(&tempEven, val);
    }
    else 
    {
      Push(&tempOdd, val);
    }
  }

  while (!IsEmpty(tempOdd))
  {
    Pop(&tempOdd, &val);
    Push(oddS, val);
  }

  while (!IsEmpty(tempEven))
  {
    Pop(&tempEven, &val);
    Push(evenS, val);
  }
}
/*
Memisahkan nilai genap dan nilai ganjil dari Stack s.

Awal:
s: 1,2,3,4
evenS:
oddS:

Akhir:
s: 
evenS 2,4
oddS: 1,3

Perhatikan order di dalam stacknya

*/

// int main()
// {
//   Stack S, Odd, Even;
//   createstac
//   for(int i = 0; i < 10; i++)
//   {

//   }
// }