#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int geraVetor(int n){
  srand (time(NULL));
  int *v;
  v = (int*)calloc(n, sizeof(int));
  puts("Vetor gerado:");
  for(int x = 0; x < n; x++){
    v[x] = rand() % 1001;
    printf("%i ",v[x]);
  }
  free(v);
}

int main(void) {
  int v, n;
  puts("Digite o tamanho do vetor:");
  scanf("%i",&n);
  fflush(stdin);
  geraVetor(n);
  return 0;
}