#include <stdio.h>

void converterMin(int mnts, int *h, int *m){
  *h = mnts/60;
  *m = mnts - *h * 60;
}

int main(void) {
  int mnts, h, m;
  puts("Digite a quantia de minutos");
  scanf("%i",&mnts);
  converterMin(mnts, &h, &m);
  printf("%ih%i", h, m);
  return 0;
}