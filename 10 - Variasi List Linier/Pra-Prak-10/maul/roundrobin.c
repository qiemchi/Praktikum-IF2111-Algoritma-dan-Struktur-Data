#include "listsirkuler.h"
#include <stdio.h>

void deleteRR (List *l, infotype tQ) {
    if (!IsEmpty(*l)) {
        address last = First(*l);
        while (Next(last) != First(*l)) {
            last = Next(last);
        }

        if (Info(last) > tQ) {
            printf("%d\n", tQ);
            Info(last) -= tQ;
            First(*l) = last;
        } else {
            infotype x;
            DelVLast(l, &x);
            printf("%d\n", x);
        }
    } else {
        printf("List kosong\n");
    }
}

float average (List l) {
    if (IsEmpty(l)) return 0;

    float sum = 0;
    int count = 0;
    address P = First(l);

    do {
        sum += Info(P);
        count++;
        P = Next(P);
    } while (P != First(l));

    return sum / count;
}

int main() {
    List l;
    CreateEmpty(&l);
    infotype tQ, X;
    char kode;

    do {
        // printf("Masukkan TQ (>0): ");
        scanf("%d", &tQ);
    } while (tQ <= 0);

    do {
        // printf("Masukkan kode operasi (A/D/F): ");
        scanf(" %c", &kode);

        switch (kode) {
            case 'A':
                // printf("Masukkan waktu proses (>0): ");
                scanf("%d", &X);
                if (X > 0) {
                    InsVFirst(&l, X);
                }
                break;
            case 'D':
                deleteRR(&l, tQ);
                break;
            case 'F':
                break;
            default:
                printf("Kode salah\n");
        }
    } while (kode != 'F');

    if (!IsEmpty(l)) {
        printf("%.2f\n", average(l));
    } else {
        printf("Proses selesai\n");
    }
    return 0;
}
