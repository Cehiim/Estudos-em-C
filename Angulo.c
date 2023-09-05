#include <stdio.h>
#include <math.h>

void calcAng(int ang, double *seno, double *cosseno){
  double ang_rad = (double) ang/180 * 3.14;
  *seno = sin(ang_rad);
  *cosseno = cos(ang_rad);
}

int main(void) {
  double seno, cosseno;
  float ang;
  printf("Digite o ângulo em graus: ");
  scanf("%f",&ang);
  fflush(stdin);
  calcAng(ang, &seno, &cosseno);
  printf("O seno é %lf\n", seno);
  printf("O cosseno é %lf", cosseno);
  return 0;
}