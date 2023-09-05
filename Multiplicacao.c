#include <stdio.h>

int produto(int a, int b){
  if(b == 1){
    return a;
  }
  else{
    return a + produto(a, b-1);
  }
}

int main(void) {
  int a, b, p;
  puts("Digite um número");
  scanf("%i", &a);
  puts("Digite outro número");
  scanf("%i", &b);
  p = produto(a, b);
  printf("Resultado: %i", p);
  return 0;
}