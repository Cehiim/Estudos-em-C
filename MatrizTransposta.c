#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **gerarMatriz(int n){
  srand(time(NULL));
  int **matriz;
  matriz = (int**)calloc(n, sizeof(int*));
  for(int x = 0; x < n; x++){
    matriz[x] = (int*)calloc(n, sizeof(int));
  }
  for(int x = 0; x < n; x++){
    for(int y = 0; y < n; y++){
      matriz[x][y] = rand() % 10;
    }
  }
  return matriz;
}

void **mostrarMatriz(int n,**m){
  puts("");
  puts("Matriz gerada:");
  for(int x = 0; x < n; x++){
    for(int y = 0; y < n; y++){
      printf("%i ",m[x][y]);
    }
    puts("");
  }
}

void **mostrarTransposta(int n,**m){
  puts("");
  puts("Matriz transposta:");
  for(int x = 0; x < n; x++){
    for(int y = 0; y < n; y++){
      printf("%i ",m[y][x]);
    }
    puts("");
  }
}

int main(void) {
  int n;
  int **matriz;
  int erro = 1;
  while(erro == 1){
    erro = 0;
    puts("Digite o tamanho da matriz:");
    scanf("%i",&n);
    fflush(stdin);
    if(n < 1){
      erro = 1;
      puts("Valor inválido, digite novamente");
      puts("");
    }
  }
  matriz = gerarMatriz(n);
  mostrarMatriz(n, matriz);
  mostrarTransposta(n, matriz);
  free(matriz);
  return 0;
}