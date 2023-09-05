#include <stdio.h>
#include <string.h>

char filtrarString(char v[], char c){
    for(int x = 0; x < strlen(v);x++){
    if(v[x] == c){
      int cont = x+1;
      int ok = 0;
      int y = x;
      while(ok == 0){
        if(v[cont] != c){
          while(y < strlen(v)){
            v[y] = v[cont];
            y++;
            cont++;
          }
          ok = 1;
        }
        else{
          if(cont == strlen(v)){
            ok = 1;
          }
          else{
            cont++;
          }
        }
      }
    }
  }
  return v;
}

int main(void) {
  char v[30];
  char c;
  puts("ELIMINAR UM TIPO DE CARACTER NUMA STRING\n");
  puts("Digite uma string: ");
  scanf("%s",&v);
  fflush(stdin);
  puts("Digite um caracter: ");
  scanf(" %c",&c);
  fflush(stdin);
  filtrarString(v, c);
  printf("Vetor filtrado: %s",v);
  return 0;
}