#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **gerarMatriz_1(int n, int m){
  srand(time(NULL));
  int **matriz;
  matriz = (int**)calloc(n, sizeof(int*));
  for(int x = 0; x < n; x++){
    matriz[x] = (int*)calloc(m, sizeof(int));
  }
  for(int x = 0; x < n; x++){
    for(int y = 0; y < m; y++){
      matriz[x][y] = rand() % 5;
    }
  }
  return matriz;
}

void **mostrarMatriz(int n, int m, **matriz){
  puts("");
  puts("Matriz gerada:");
  for(int x = 0; x < n; x++){
    for(int y = 0; y < m; y++){
      printf("%i ",matriz[x][y]);
    }
    puts("");
  }
}

int **gerarMatriz_2(int n, int m){
  srand(time(NULL));
  int **matriz;
  matriz = (int**)calloc(n, sizeof(int*));
  for(int x = 0; x < n; x++){
    matriz[x] = (int*)calloc(m, sizeof(int));
  }
  for(int x = 0; x < n; x++){
    for(int y = 0; y < m; y++){
      matriz[x][y] = rand() % 5+5;
    }
  }
  return matriz;
}

int **somarMatriz(int n, int m, **m1, **m2){
  for(int x = 0; x < n; x++){
    for(int y = 0; y < m; y++){
      m1[x][y] = m1[x][y] + m2[x][y];
    }
  }
  return m1;
}

int main(void) {
  int **matriz_1;
  int **matriz_2;
  int **soma_m;
  int n = 2, m = 4;
  matriz_1 = gerarMatriz_1(n, m);
  mostrarMatriz(n, m, matriz_1);
  matriz_2 = gerarMatriz_2(n, m);
  mostrarMatriz(n, m, matriz_2);
  soma_m = somarMatriz(n, m, matriz_1, matriz_2);
  mostrarMatriz(n, m, soma_m);
  free(matriz_2);
  free(soma_m);
  return 0;
}