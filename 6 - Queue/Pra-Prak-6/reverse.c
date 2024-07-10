#include <stdio.h>
#include "reverse.h"

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
