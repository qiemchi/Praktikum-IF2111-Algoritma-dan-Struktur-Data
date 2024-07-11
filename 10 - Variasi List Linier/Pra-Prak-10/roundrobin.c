#include "listsirkuler.h"
#include <stdio.h>

void deleteRR (List *l, infotype tQ)
{
    if (!IsEmpty(*l))
    {
        address Last = First(*l);
        infotype X;

        while (Next(Last) != First(*l))
        {
            Last = Next(Last);
        }

        if (Info(Last) > tQ)
        {
            printf("%d\n", tQ);
            Info(Last) -= tQ;
            First(*l) = Last;
        }
        else
        {
            DelVLast(l, &X);
            printf("%d\n", X);
        }
    }
    else
    {
        printf("List kosong\n");
    }

}
/* Jika l tidak kosong, "menghapus" elemen terakhir list l, misal last, sesuai aturan round robin, yaitu:
- jika Info(last)>tQ, maka last "diantrikan" kembali sebagai first elemen dengan Info(last)=Info(last)-tQ
- jika Info(last)<=tQ, maka DelVLast(l,x) dan menampilkan x ke layar */
/* Jika l kosong, cetak "List kosong" */
/* I.S. tQ terdefinisi sebagai nilai time slice pemrosesan.
L terdefinisi, mungkin kosong. */
/* F.S. Elemen terakhir l diproses sesuai aturan round-robin.
l mungkin menjadi kosong. */

float average (List l)
{
    float avg = 0;
    int count = 0;

    if (!IsEmpty(l))
    {
        address P = First(l);

        do {
        avg += Info(P);
        count++;
        P = Next(P);
        } while (P != First(l));

        avg = avg / count;
    }

    return avg;
}
/* Menghasilkan nilai rata-rata elemen l. l tidak kosong. */

/* Pengerjaan Soal */
int main()
{
    List Robin;
    CreateEmpty(&Robin);

    infotype TQ;
    scanf("%d", &TQ);

    while (TQ <= 0)
    {
        scanf("%d", &TQ);
    }

    char command;
    scanf(" %c", &command);

    while (command != 'F')
    {
        if (command == 'A')
        {
            infotype val;
            scanf("%d", &val);
            
            if (val > 0)
            {
                InsVFirst(&Robin, val);
            }
            
        }
        else if (command == 'D')
        {
            deleteRR(&Robin, TQ);
        }
        else
        {
            printf("Kode salah\n");
        }

        scanf(" %c", &command);
    }

    if (!IsEmpty(Robin)) {
        printf("%.2f\n", average(Robin));
    } else {
        printf("Proses selesai\n");
    }

    return 0;
}

