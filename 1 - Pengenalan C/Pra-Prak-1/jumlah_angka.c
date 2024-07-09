#include <stdio.h>
#include <string.h>
#include <math.h>
 
int main()
{
    int x;
    printf("");
    scanf("%d", &x);

    int hasil = 0;

    if (floor(x / 10) == 0){
        hasil = x % 10;
    }
    else {
        while (floor(x / 10) != 0)
        { 
            hasil += (x % 10);
            x = floor(x/10);
        }
        hasil += (x % 10);
    }

    printf("Jumlah angka = %d", hasil);
}