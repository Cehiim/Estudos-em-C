#include <stdio.h>
#include <string.h>

void contarString(char v[]){
  for(int x=0; x<strlen(v); x++){
    int cont = 0;
    for(int y=0; y<strlen(v); y++){
      if(v[x] == v[y]){
        cont++;
      }
    }
    if(x>0){
      int num_repetido = 0;
      for(int y=0; y<x; y++){
        if(v[y] == v[x]){
          num_repetido = 1;
        }
      }
      if(num_repetido == 0){
        printf("%c: %i\n",v[x], cont);
      }
    }
    else{
    printf("%c: %i\n",v[x], cont);
    }
  }
}

int main(void) {
  char v[30];
  puts("CONTAR CARACTERES DE UMA STRING");
  puts("Digite uma string: ");
  scanf("%s",&v);
  fflush(stdin);
  contarString(v);
  return 0;
}