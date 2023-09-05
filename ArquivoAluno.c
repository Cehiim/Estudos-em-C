#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
  char turma[2];
  unsigned int matricula;
  float nota;
} Aluno;

int main(void) {
  FILE *arq;
  int n, cont;
  arq = fopen("aluno.txt", "r");
  fscanf(arq, "%i", &cont);
  Aluno ficha[cont];
  for(int x = 0; x < cont; x++){
    fscanf(arq, "%s %i %f", ficha[x].turma, &ficha[x].matricula, &ficha[x].nota);
  }
  fclose(arq);
  puts("Digite uma das opções abaixo:");
  puts("1. Ordenar por turma e matrícula.");
  puts("2. Ordenar por nota (uma classificação geral de todas as turmas).");
  puts("3. Solicitar uma turma e mostrar somente os alunos da turma em ordem de matricula.");
  puts("4. Solicitar uma turma e mostrar somente os alunos da turma em ordem de nota decrescente.");
  scanf("%i", &n);
  fflush(stdin);
  if(n == 1){
    for(int x = 0; x < cont; x++){
      for(int y = x+1; y < cont; y++){
        if(strcmp(ficha[x].turma, ficha[y].turma) > 0 ||
        (strcmp(ficha[x].turma, ficha[y].turma) == 0 && ficha[x].matricula > ficha[y].matricula)){
          Aluno aux = ficha[x];
          ficha[x] = ficha[y];
          ficha[y] = aux;
        }
      }
    }
    for(int x = 0; x < cont; x++){
      printf("%s %i %.1f\n", ficha[x].turma, ficha[x].matricula, ficha[x].nota);
    }
  }
  else if(n == 2){
    for(int x = 0; x < cont; x++){
      for(int y = x+1; y < cont; y++){
        if(ficha[x].nota < ficha[y].nota){
          Aluno aux = ficha[x];
          ficha[x] = ficha[y];
          ficha[y] = aux;
        }
      }
    }
    for(int x = 0; x < cont; x++){
      printf("%s %i %.1f\n", ficha[x].turma, ficha[x].matricula, ficha[x].nota);
    }
  }
  else if(n == 3){
    char c[2];
    puts("\nDigite uma turma (A, B, C ou D):");
    scanf("%s",&c);
    puts("");
    c[0] = toupper(c[0]);
    for(int x = 0; x < cont; x++){
      for(int y = x+1; y < cont; y++){
        if(ficha[x].matricula > ficha[y].matricula){
          Aluno aux = ficha[x];
          ficha[x] = ficha[y];
          ficha[y] = aux;
        }
      }
    }
    for(int x = 0; x < cont; x++){
      if(strcmp(ficha[x].turma, c) == 0){
        printf("%s %i %.1f\n", ficha[x].turma, ficha[x].matricula, ficha[x].nota);
      }
    }
  }
  else if(n == 4){
    char c[2];
    puts("\nDigite a turma (A, B, C ou D):");
    scanf("%s",&c);
    c[0] = toupper(c[0]);
    for(int x = 0; x < cont; x++){
      for(int y = x+1; y < cont; y++){
        if(ficha[x].nota < ficha[y].nota){
          Aluno aux = ficha[x];
          ficha[x] = ficha[y];
          ficha[y] = aux;
        }
      }
    }
    for(int x = 0; x < cont; x++){
      if(strcmp(ficha[x].turma, c) == 0){
        printf("%s %i %.1f\n", ficha[x].turma, ficha[x].matricula, ficha[x].nota);
      }
    }
  }
  else{
    puts("Opção inválida, reinicie o programa.");
  }
  return 0;
}