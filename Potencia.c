#include <stdio.h>

int potencia(int a, int n){
  if(n == 0){
    return 1;
  }
  else{
    return a * potencia(a, n-1);
  }
}

int main(void) {
  int a, n, p;
  puts("Digite um número para base");
  scanf("%i", &a);
  puts("Digite um número para potência");
  scanf("%i", &n);
  p = potencia(a, n);
  printf("Resultado: %i", p);
  return 0;
}