#include <stdio.h>
#include <stdlib.h>
#include "circular_queue.h"

int main()
{
    // Deklarasi variabel n dan m
    int n, m; scanf("%d %d", &n, &m);

    // Deklarasi matriks playlist
    int lagu[m][3];
    // Input matriks playlist dengan handling error (IDlagu < 0 || IDlagu > n-1)
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            scanf("%d", &lagu[i][j]);
            if(lagu[i][j] < 0 || lagu[i][j] > n-1)
            {
                printf("Playlist tidak valid\n");
                exit(0);
            }
        }
    }
    // Deklarasi dan inisiasi switch loop
    int loop = 0;

    // Deklarasi dan input perintah
    int input; scanf("%d", &input);

    // Deklarasi dan inisiasi antrian
    Queue antrian; CreateQueue(&antrian);
    
    // While input != 0
    while(input)
    {
        if(input == 1)
        {
            if(IsEmpty(antrian))
            {
                printf("Tidak ada lagu\n");
            }
            else
            {
                int cur = dequeue(&antrian);
                if(loop)
                {
                    
                    printf("Play lagu %d\n", cur);
                    enqueue(&antrian, cur);
                }
                else
                {
                    printf("Play lagu %d\n", cur);
                }
            }
        }
        else if(input == 2)
        {
            if(loop)
            {
                printf("Tidak looping lagu\n");
                loop = 0;
            }
            else
            {
                printf("Looping lagu\n");
                loop = 1;
            }
        }
        else if(input == 3)
        {
            int IDlagu; scanf("%d", &IDlagu);
            if(IsFull(antrian))
            {
                printf("Queue penuh\n");
            }
            else
            {
                enqueue(&antrian, IDlagu);
            }
        }
        else if(input == 4)
        {
            int IDplaylist; scanf("%d", &IDplaylist);
            for(int i = 0; i < 3; i++)
            {
                if(IsFull(antrian))
                {
                    printf("Queue penuh\n");
                    break;
                }
                enqueue(&antrian, lagu[IDplaylist][i]);
            }
        }
        else break;
        scanf("%d", &input);
    }
}