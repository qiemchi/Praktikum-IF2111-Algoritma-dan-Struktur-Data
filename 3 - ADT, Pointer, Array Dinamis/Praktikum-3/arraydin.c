#include <stdio.h>
#include "arraydin.h"
#include <stdlib.h>

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin(){
  ArrayDin Array;
  Array.A = (ElType *) malloc (InitialSize * sizeof(ElType));
  Array.Capacity = InitialSize;
  Array.Neff = 0;
  return Array;
}

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin(ArrayDin *array){
  free((*array).A);
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(ArrayDin array){
  return (array.Neff == 0);
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDin array){
  return (array.Neff);
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType Get(ArrayDin array, IdxType i){
  return array.A[i];
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDin array){
  return array.Capacity;
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(ArrayDin *array, ElType el, IdxType i){
    if (GetCapacity(*array) == Length(*array))
    {
        int newCap = GetCapacity(*array) * 2;
        ElType *newArray = (ElType *) malloc (newCap * sizeof(ElType));

        for (int j = 0; j < Length(*array); j++)
        {
            newArray[j] = Get(*array, j);
        }
        
        free((*array).A);
        (*array).A = newArray;
        (*array).Capacity = newCap;
    }
    
    for (int j = Length(*array); i <= j; j--)
    {
        (*array).A[j] = (*array).A[j-1]; 
    }
    (*array).A[i] = el;
    (*array).Neff += 1;
}

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLast(ArrayDin *array, ElType el){
  InsertAt((array), el, (*array).Neff);
}

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirst(ArrayDin *array, ElType el){
  InsertAt((array),el,0);
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDin *array, IdxType i)
{
    for (int j = i; j < Length(*array) - 1; j++)
    {
        (*array).A[j] = (*array).A[j+1];    
    }
    (*array).Neff -= 1;
}


/**
 * Fungsi untuk menghapus elemen terakhir ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteLast(ArrayDin *array)
{
	int j = Length(*array);
	(*array).A[j] = '\0';
	(*array).Neff -= 1;
}


/**
 * Fungsi untuk menghapus elemen pertama ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteFirst(ArrayDin *array){
	for (int i = 0; i < Length(*array); i++)
	{
		(*array).A[i] = (*array).A[i+1];
	}
	(*array).Neff -= 1;
}

/**
 * Fungsi untuk melakukan print suatu ArrayDin.
 * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * dan diakhiri newline.
 * Prekondisi: array terdefinisi
 */
void PrintArrayDin(ArrayDin array){
    int j;
    printf("[");
    for (j=0;j<(array).Neff;j++){
        printf("%d",(array).A[j]);
        if (j!= (array).Neff-1){
            printf(", ");
        }
    }
    printf("]\n");
}

/**
 * Fungsi untuk melakukan reverse suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
void ReverseArrayDin(ArrayDin *array){
    ArrayDin newArray = MakeArrayDin();
    for (int i = Length(*array) - 1; i >= 0; i--)
    {
        InsertLast(&newArray, Get(*array, i));
    }

    free((*array).A);
    (*array).A = newArray.A;
    (*array).Capacity = newArray.Capacity;;
}

/**
 * Fungsi untuk melakukan copy suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
ArrayDin CopyArrayDin(ArrayDin array){
	ArrayDin copyArr = MakeArrayDin();
    copyArr.Capacity = array.Capacity;
    
    for (int i = 0; i < Length(array); i++)
    {
        InsertLast(&copyArr, Get(array, i));
    }
    return copyArr;
}

/**
 * Fungsi untuk melakukan search suatu ArrayDin.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */
IdxType SearchArrayDin(ArrayDin array, ElType el){
	
    if (IsEmpty(array))
    {
        return -1;
    } else
    {
        for (int i = 0; i < Length(array); i++)
        {
            if (Get(array, i) == el)
            {
                return i;
            }
        }
        return -1;
    }
}
