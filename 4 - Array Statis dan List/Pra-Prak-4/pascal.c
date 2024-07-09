#include <stdio.h>

void segitiga_pascal(int n, int *result){
  int new[n];
  int prev[n];

  for (int i = 0; i < n; i++){

    for (int j = 1; j < i; j++){
      new[j] = prev[j] + prev[j-1];
    }
    new[i] = 1;
    prev[i] = 1;

    for (int j = 1; j < i; j++) prev[j] = new[j];
  }

  for (int k = 0; k<n; k++){
    result[k] = new[k];
  }
}