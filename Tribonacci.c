#include <stdio.h>

int tribo(n){
  if(n <= 2){ // 1
    return 0;
  }
  else if(n <= 4){ // 1
    return 1;
  }
  else{
    return tribo(n-3) + tribo(n-2) + tribo(n-1); /*
    T(n-3) + T(n-2) + T(n-1)
    */
  }
}

/* Fórmula de recorrência:
Se n <= 4, T(n) = 1
Se n > 4, T(n) = T(n-3) + T(n-2) + T(n-1) = O(n)
*/


int main(void) {
  int n;
  puts("Digite um número:");
  scanf("%i",&n);
  printf("%i",tribo(n));
  return 0;
}