#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *geraVetor(int n){
  srand (time(NULL));
  int *v;
  v = (int*)calloc(n, sizeof(int));
  for(int x = 0; x < n; x++){
    v[x] = rand() % 10;
  }
  return v;
}

void *mostraVetor(int *v, int n){
  for(int x = 0; x < n; x++){
    printf("%i ",v[x]);
  }
  puts("\n");
}

void *okVetor(int *v, int n){
  int ok = 1;
  for(int x = 0; x < n-1; x++){
    if(v[x] > v[x+1]){
      ok = 0;
      x = n;
    }
  }
  if(ok == 1){
    puts("O vetor está ordenado\n");
  }
  else{
    puts("O vetor não está ordenado\n");
  }
}

void *bubbleSort(int *v, int n){
  for(int x = 0; x < n-1; x++){
    for(int y = 0; y < n-1; y++){
      if(v[y] > v[y+1]){
        int aux = v[y+1];
        v[y+1] = v[y];
        v[y] = aux;
      }
    }
  }
  mostraVetor(v, n);
  okVetor(v, n);
}

void *insertionSort(int *v, int n){
  for(int x = 1; x < n; x++){
    int chave = x-1;
    while(v[chave] > v[x]){
        int aux = v[x];
        v[x] = v[chave];
        v[chave] = aux;
        x--, chave--;
    }
  }
  mostraVetor(v, n);
  okVetor(v, n);
}

void *selectionSort(int *v, int n){
  for(int x = 0; x < n-1; x++){
    int min = x, aux;
    for(int y = x+1; y < n; y++){
      if(v[min] > v[y]){
        min = y;
      }
    }
    aux = v[x];
    v[x] = v[min];
    v[min] = aux;
  }
  mostraVetor(v, n);
  okVetor(v, n);
}

void *shellSort(int *v, int n){
  int h = n/2;
  while(h > 0){
    for(int x = h; x < n; x++){
      int aux = v[x];
      int y = x;
      while(y >= h){
        if(v[y-h] > aux){
          v[y] = v[y-h];
          y -= h;
        }
        else{
          break;
        }
      }
      v[y] = aux;
    }
    h/= 2;
  }
  mostraVetor(v, n);
  okVetor(v, n);
}

int main(void) {
  int *v, n;
  puts("Digite o tamanho do vetor:");
  scanf("%i",&n);
  fflush(stdin);
  v = geraVetor(n);
  puts("\nVetor gerado:");
  mostraVetor(v, n);
  okVetor(v, n);
  puts("Bubble sort:");
  bubbleSort(v, n);
  puts("Insertion sort:");
  insertionSort(v, n);
  puts("Selection sort:");
  selectionSort(v, n);
  puts("Shell sort:");
  shellSort(v, n);
  return 0;
}