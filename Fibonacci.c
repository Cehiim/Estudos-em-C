#include <stdio.h>

int fibo(int n, int *cont){
  //printf("fibo(%d)\n", n);
  (*cont)++;
  if(n <= 1){
    return n;
  }
  else{
    return fibo(n-1, cont) + fibo(n-2, cont);
  }
}

int main(void) {
  int n, f, cont = 0;
  puts("Digite um número");
  scanf("%i",&n);
  f = fibo(n, &cont);
  printf("Fibonacci(%i): %i\n", n, f);
  printf("Profundidade da recursão: %i", cont);
  return 0;
}