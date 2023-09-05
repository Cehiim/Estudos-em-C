#include <stdio.h>
# include <string.h>

int main(void) {
  char v[16];
  int ok = 0;
  puts("VERIFICAR SE UMA STRING É UM PALÍNDROMO");
  puts("Digite uma string: ");
  scanf("%s",&v);
  fflush(stdin);
  for(int x = 0, cont = strlen(v)-1; x < strlen(v)/2; x++, cont--){
    if(v[x] != v[cont]){
      ok++;
    }
  }
  if(ok == 0){
    puts("A string é um palíndromo");
  }
  else{
    puts("A string não é um palíndromo");
  }
  return 0;
}