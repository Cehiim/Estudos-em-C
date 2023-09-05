#include <stdio.h>

void acharExtremos(int v[], int n, int *maior, int *menor){
  for(int x=0; x<n; x++){
    if(v[x]>*maior){
      *maior=v[x];
    }
    if(v[x]<*menor){
      *menor=v[x];
    }
  }
}

int main(void) {
  int v[30];
  int n, maior=0, menor=100000;
  puts("Digite o tamanho do vetor");
  scanf("%i",&n);
  fflush(stdin);
  for(int x=0; x<n; x++){
    printf("Digite o valor da posição %i: ", x);
    scanf("%i", &v[x]);
    fflush(stdin);
  }
  acharExtremos(v,n, &maior, &menor);
  printf("O maior valor é %i\n", maior);
  printf("O menor valor é %i", menor);
  return 0;
}