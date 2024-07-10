// NIM              : 18222105
// NAMA             : Rajendra Farras Rayhan
// Tanggal          : 29 November 2023
// Topik Praktikum  : Pasca-Praktikum Stack
// Deskripsi        : Aplikasi Pemutar Lagu

#include <stdio.h>
#include "stack.h"

int main(){
    int jumlahlagu;
    char listlagu[10][20];
    Stack History;
    CreateEmpty(&History);
    scanf("%d", &jumlahlagu);
    for(int i = 0; i < jumlahlagu; i++){
        scanf("%s", listlagu[i]);
    }
    int jumlah_ops;
    scanf("%d", &jumlah_ops);
    for(int i = 0; i < jumlah_ops; i++){
        int ops;
        scanf("%d", &ops);
        if(ops == 1){
            int idx;
            scanf("%d", &idx);
            Push(&History, idx);
            printf("Playing: %s\n", listlagu[idx]);
        }
        else if(ops == 2){
            if(IsEmpty(History)){
                printf("No music is played\n");
            }
            else{
                int playedsong;
                Pop(&History, &playedsong);
                if(!IsEmpty(History)){
                    printf("Playing: %s\n", listlagu[InfoTop(History)]);
                }
                else{
                    printf("No music is played\n");
                }
            }
        }
        else{
            printf("Operasi tidak diketahui\n");
        }
    }
    return 0;
}