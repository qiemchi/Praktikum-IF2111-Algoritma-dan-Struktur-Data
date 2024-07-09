#include <stdio.h>

int main(){
    int n; int i;
    printf("");
    scanf("%d", &n);

    for (i = 1; i <= n; i++){
        if (i % 3 ==0 ){
            if ( i % 5 == 0){
                printf("RilNyata\n");
            }
            else {
                printf("Nyata\n");
            }
        } 
        else if ( i % 5 ==0){
            printf("Ril");
        } 
        else {
            printf ("%d\n", i);
        }
    }
}