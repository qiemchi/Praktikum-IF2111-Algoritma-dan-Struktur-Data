#include <stdio.h>

int main(){
    int x; int i;
    printf("");
    scanf("%d", &x);

    for (i = 1; i <= x; i++) {
        if (i % 3 == 0){
            if (i % 5 == 0){
                printf("RilNyata\n");
            }
            else {
                printf("Nyata\n");
            }
        }
        else if (i % 5 == 0){
            printf("Ril\n");
        }
        else {
            printf("%d\n", i);
        }
    }
}