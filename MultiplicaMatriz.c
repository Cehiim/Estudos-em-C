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

int **multMatriz(int n, int m, **mat1, **mat2, int p){
  int **mult;
  mult = (int**)calloc(n, sizeof(int*));
  for(int x = 0; x < n; x++){
    mult[x] = (int*)calloc(m, sizeof(int));
  }
  for(int x = 0; x < n; x++){
    for(int y = 0; y < m; y++){
      for(int w = 0; w < p; w++){
        mult[x][y] += mat1[x][w] * mat2[w][y];
      }
    }
  }
  return mult;
}



int main(void) {
  int **matriz_1;
  int **matriz_2;
  int **mult_m;
  int n = 2, m = 4, p = 6;
  matriz_1 = gerarMatriz_1(m, n);
  mostrarMatriz(m, n, matriz_1);
  matriz_2 = gerarMatriz_2(n, p);
  mostrarMatriz(n, p, matriz_2);
  mult_m = multMatriz(m, p, matriz_1, matriz_2, n);
  mostrarMatriz(m, p, mult_m);
  free(matriz_1);
  free(matriz_2);
  free(mult_m);
  return 0;
}