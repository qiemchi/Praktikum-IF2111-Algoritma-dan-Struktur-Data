#include <stdio.h>

int main(){
    long long int x;
    long int hasil = 1;
    scanf("%lld", &x);

    while (x > 0){
        if (x % 10 != 0)
        {
            hasil *= (x % 10);
        }
        x /= 10;
    }

    long int hasilKali = hasil;
    int jumlah = 0;

    while (hasil > 0){
        if (hasil % 10 != 0)
        {
            jumlah += 1;
        }
        hasil /= 10;
    }

    printf("%ld %d\n", hasilKali, jumlah);
    return 0;
}