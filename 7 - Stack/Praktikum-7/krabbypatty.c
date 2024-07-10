// NIM              : 18222105
// NAMA             : Rajendra Farras Rayhan
// Tanggal          : 29 November 2023
// Topik Praktikum  : Pasca-Praktikum Stack
// Deskripsi        : Krabby Patty

#include <stdio.h>
#include "krabbypatty.h"

void krabbyPatty(Stack *ingredients, Stack *burger)
/*
Membuat satu Krabby Patty dari tumpukan bahan
0 - roti bawah
1 - patty
2 - keju
3 - selada
4 - bawang
5 - acar
6 - tomat
7 - saus
8 - mustard
9 - roti atas

PENJELASAN:
1.  Sebuah Krabby Patty di anggapan SpinBob adalah susunan bahan-bahan yang ditumpuk sedemikian rupa sehingga 
    roti atas selalu berada di paling atas tumpukan dan roti bawah ada di paling bawah tumpukan dengan bahan-bahan lain berada di antara kedua roti,
    namun menurutnya itu sifatnya opsional. Artinya, Ia juga beranggapan bahwa hanya satu buah roti atas dan satu buah roti bawah bisa disebut sebagai 
    Krabby Patty.
2.  Jika di dalam tumpukan bahan SpinBob tidak menemukan setidaknya satu buah roti atas dan satu buah roti bawah, maka Krabby Patty tidak dapat dibuat.
3.  Karena SpinBob teledor, jika di tumpukan bahan Ia tidak menemukan setidaknya satu buah roti atas dan satu buah roti bawah sehingga
    Krabby Patty tidak dapat Ia buat, bahan-bahan yang mungkin sudah Ia keluarkan dari tumpukan bahan tidak Ia kembalikan lagi.
4.  Karena SpinBob tidak memiliki passion yang sama dengan saudaranya, Ia hanya ingin membuat satu buah Krabby Patty saja,
    sehingga jika Ia sudah menemukan semua yang Ia butuhkan untuk membuat satu buah Krabby Patty, Ia tidak akan membuatnya lagi tanpa peduli jika
    di tumpukan bahan masih tersisa bahan-bahan lain.
5.  Karena SpinBob mudah marah, jika Ia sudah mendapatkan satu jenis roti (atas/bawah) namun belum mendapatkan jenis yang satunya lagi (bawah/atas)
    di tumpukan bahan dan Ia kemudian menemukan lagi roti dengan jenis yang sama seperti yang sudah Ia dapatkan (atas/bawah), 
    Ia akan membuang roti yang baru ditemukannya itu.


~ CONTOH 1 ~
Awal:
ingredients -> [7, 1, 9, 2, 3, 4, 3, 0, 1, 2]
burger -> []

Akhir:
ingredients -> [7, 1]
burger -> [0, 2, 3, 4, 3, 1, 2, 9]

Terjemahan:
Krabby Patty dapat dibuat dengan susunan:
- roti atas
- keju
- patty
- selada
- bawang
- selada
- keju
- roti bawah

Sisa bahan di tumpukan bahan:
- patty
- saus

~ CONTOH 2 ~
Awal:
ingredients -> [0, 2, 9, 3, 4, 3, 7, 0, 9, 9]
burger -> []

Akhir:
ingredients -> [0, 2, 9, 3, 4, 3, 7]
burger -> [0, 9]

Terjemahan:
Krabby Patty dapat dibuat dengan susunan:
- roti atas
- roti bawah

Sisa bahan di tumpukan bahan:
- saus
- selada
- bawang
- selada
- roti atas
- keju
- roti bawah

~ CONTOH 3 ~
Awal:
ingredients -> [1, 3, 8, 5, 7, 9]
burger -> []

Akhir:
ingredients -> []
burger -> []

Terjemahan:
Krabby Patty tidak dapat dibuat

Tidak ada bahan tersisa di tumpukan bahan
*/
{
    boolean terbuat = false; /* Boolean bahwa krabby patty berhasil terbuat */
    boolean find_atas = false; /* Boolean bahwa ditemukannya roti atas */
    boolean find_bawah = false; /* Boolean bahwa ditemukannya roti bawah */
    Stack before_find, after_find; 
    CreateEmpty(&before_find); /* Stack ketika belum ditemukannya roti atas atau roti bawah */
    CreateEmpty(&after_find); /* Stack ketika sudah ditemukannya roti atas atau roti bawah */
    while((!IsEmpty(*ingredients)) && (!terbuat)){
        int bahanNow;
        Pop(ingredients, &bahanNow);
        if((!find_bawah) && (bahanNow == 0)){ /* Jika belum ditemukannya roti bawah, buat boolean find_bawah menjadi true */
            find_bawah = true;
        }
        else if((!find_atas) && (bahanNow == 9)){ /* Jika belum ditemukannya roti atas, buat boolean find_atas menjadi true */
            find_atas = true;
        }
        if((find_atas) && (find_bawah)){ /* Jika sudah ditemukan roti atas dan roti bawah, krabby patty dapat dibuat */
            terbuat = true;
        }
        else if((!find_atas) && (!find_bawah)){ /* Melakukan pengisian stack before_find jika belum ditemukannya roti bawah dan roti atas */
            Push(&before_find, bahanNow);
        }
        else if(((!find_atas) || (!find_bawah)) && ((bahanNow != 0) && (bahanNow != 9))){ /* Melakukan pengisian stack after_find jika sudah ditemukannya roti bawah atau roti atas, serta bahan yang ditinjau sekarang bukanlah roti atas dan bukanlah roti bawah */
            Push(&after_find, bahanNow);
        }
        /* Jika sudah mendapatkan satu jenis roti (atas/bawah) namun kemudian menemukan lagi roti dengan jenis yang sama seperti yang sudah didapatkan (atas/bawah), tidak akan melakukan apapun*/
    }
    if(terbuat){ /* Penyusunan burger jika krabby patty dapat dibuat */
        Push(burger, 0);
        while (!IsEmpty(after_find)){
            int X;
            Pop(&after_find, &X);
            Push(burger, X);
        }
        while(!IsEmpty(before_find)){
            int X;
            Pop(&before_find, &X);
            Push(burger, X);
        }
        Push(burger, 9);
    }
}


/*** DRIVER NYA***/
// int main(){
//     Stack ingredients, burger;
//     CreateEmpty(&ingredients);
//     CreateEmpty(&burger); /* [0, 2, 9, 3, 4, 3, 7, 0, 9, 9] */
//     Push(&ingredients, 0);
//     Push(&ingredients, 2);
//     Push(&ingredients, 9);
//     Push(&ingredients, 3);
//     Push(&ingredients, 4);
//     Push(&ingredients, 3);
//     Push(&ingredients, 7);
//     Push(&ingredients, 0);
//     Push(&ingredients, 9);
//     Push(&ingredients, 9);
//     krabbyPatty(&ingredients, &burger);
//     Stack displayburger, displaybahan;
//     CreateEmpty(&displaybahan);
//     printf("INGREDIENTS: \n");
//     printf("[");
//     while(!IsEmpty(ingredients)){
//         int Elmt;
//         Pop(&ingredients, &Elmt);
//         Push(&displaybahan, Elmt);
//     }
//     while(!IsEmpty(displaybahan)){
//         int Elmt;
//         Pop(&displaybahan, &Elmt);
//         Push(&ingredients, Elmt);
//         printf("%d", Elmt);
//         if(!IsEmpty(displaybahan)){
//             printf(", ");
//         }
//     }
//     printf("]\n");
//     CreateEmpty(&displayburger);
//     printf("BURGER: \n");
//     printf("[");
//     while(!IsEmpty(burger)){
//         int Elmt;
//         Pop(&burger, &Elmt);
//         Push(&displayburger, Elmt);
        
//     }
//     while(!IsEmpty(displayburger)){
//         int Elmt;
//         Pop(&displayburger, &Elmt);
//         Push(&burger, Elmt);
//         printf("%d", Elmt);
//         if(!IsEmpty(displayburger)){
//             printf(", ");
//         }
//     }
//     printf("]\n");
//     if(IsEmpty(burger)){
//         printf("Krabby patty tidak dapat dibuat\n");
//     }
//     return 0;
// }