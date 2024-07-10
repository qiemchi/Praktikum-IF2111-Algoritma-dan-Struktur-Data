#include "stack.h"
#include "boolean.h"
#include "string.h"
#include <stdio.h>
#include "stdlib.h"
#include "aritmatika.h"

// /* ************ Prototype ************ */
// /* *** Konstruktor/Kreator *** */
// void CreateEmpty(Stack *S)
// {
//   Top(*S) = Nil;
// }
// /* I.S. sembarang; */
// /* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
// /* jadi indeksnya antara 0..MaxEl-1 (inklusif) */
// /* Ciri stack kosong : TOP bernilai Nil */

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


boolean isOperator(char input)
{
  return (input == '+' || input == '-' || input == '*' || input == '/');
}
/* Proses: Mengecek apakah input merupakan operator */
/*         input adalah operator jika input merupakan salah
           satu dari berikut:
                - +
                - -
                - *
                - /
*/

int hitung(int angka1, int angka2, char op)
{
  int result;
  if (op == '+') result = angka1 + angka2;
  else if (op == '-') result = angka1 - angka2;
  else if (op == '*') result = angka1 * angka2;
  else if (op == '/') result = angka1 / angka2;
  return result;
}
/* Proses: Menghitung ekspresi */
/*
    Contoh input / output:
    angka1 : 2
    angka2 : 10
    op     : -

    return : -8 (penjelasan: 2 - 10 = 8)
*/

int eval(char *input, int length)
{
  Stack operand;
  CreateEmpty(&operand);
  int val, angka1, angka2, res = 0;

  for (int i = 0; i < length; i++)
  {
    if (isOperator(input[i]))
    {
      Pop(&operand, &angka2);
      Pop(&operand, &angka1);
      res = hitung(angka1, angka2, input[i]);
      Push(&operand, res);
    }
    else
    {
    val = input[i] - 48;
    Push(&operand, val);
    }
  }

  Pop(&operand, &res);
  return res;
}
/* Proses: Menghitung keseluruhan ekspresi */
/* I.S. input adalah string. setiap operand dipastikan < 10 */
/*
    Contoh input / output:
    input   : 23+
    output  : 5 (penjelasan: ekspresi ekuivalen dengan 2 + 3)

    input   : 9423+*5/-
    output  : 5 (penjelasan: ekspresi ekuivalen dengan 9-(4*(2+3))/5)

*/

// int main()
// {
//   char * input = "9423+*5/-";
//   int result = eval(input, 9);
//   printf("%d\n", result);
// }
