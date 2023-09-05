#include <stdio.h>

void somarTempo(int *h, int *m, int soma_m){
  int soma_h = soma_m/60, soma_h2;
  *m += soma_m - soma_h * 60;
  soma_h2 = *m/60;
  *m = *m - soma_h2 *60;
  *h = *h + soma_h + soma_h2;
}

int main(void) {
  int h, m, soma_m;
  printf("Digite as horas: ");
  scanf("%i", &h);
  fflush(stdin);
  printf("Digite os minutos: ");
  scanf("%i", &m);
  fflush(stdin);
  printf("Tempo inicial: %ih%i\n",h, m);
  printf("Digite os minutos para somar: ");
  scanf("%i", &soma_m);
  fflush(stdin);
  somarTempo(&h, &m, soma_m);
  printf("Tempo final: %2.ih%2.i\n",h, m);
  return 0;
}