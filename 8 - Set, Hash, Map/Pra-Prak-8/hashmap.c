#include <stdio.h>
#include "boolean.h"
#include "hashmap.h"

/* *** Konstruktor/Kreator *** */
void CreateEmpty(HashMap *M)
{
  (*M).Count = Nil;
  for (int i = 0; i < MaxEl; i++)
  {
    (*M).Elements[i].Key = Undefined;
    (*M).Elements[i].Value = Undefined;
  }
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah HashMap M kosong berkapasitas MaxEl */
/* Ciri HashMap kosong : count bernilai Nil dengan seluruh isi key & value map Undefined */

/* *** Index Penyimpanan dengan modulo *** */
address Hash(keytype K)
{
  return K % MaxEl;
}
/* Menghasilkan indeks penyimpanan dengan operasi modulo ke MaxEl */

/* ********** Operator Dasar HashMap ********* */
valuetype Value(HashMap M, keytype k)
{
  address id = Hash(k);
  valuetype val = Undefined;
  boolean found = false;

  if (M.Elements[id].Key == k)
  {
    return M.Elements[id].Value;
  }
  else
  {
    int i = id + 1;
    while (M.Elements[id].Key != Undefined && !found && i != id)
    {

      if (M.Elements[i].Key == k)
      {
        found = true;
        val = M.Elements[i].Value;
      }

      i++;

      if (i == MaxEl)
      {
        i = 0;
      }
    }

    return val;
}
}
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void Insert(HashMap *M, keytype k, valuetype v)
{
  address id = Hash(k);
  boolean found = false;

  while ((*M).Elements[id].Key != Undefined && (!found))
  {
    if ((*M).Elements[id].Key == k)
    {
      found = true;
    }
    else
    {
      id++;
      if (id == MaxEl)
      {
        id = 0;
      }
    }
  }

  if (!found)
  {
    (*M).Elements[id].Key = k;
    (*M).Elements[id].Value = v;
    (*M).Count += 1;
  }
}
/* Menambahkan Elmt sebagai elemen HashMap M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan 
        index yang digunakan untuk menyimpan v adalah hash dari k
        gunakan open addressing linear probing dengan interval 1 jika index sudah terisi    */
