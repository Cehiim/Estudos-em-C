//Luiz Henrique Bonilha Pasquinelli - 32224419
//Cesar Hideki Imai - 32255659
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int leituraArquivo(char nomeArquivo[]){ //função que le o arquivo retorna o número de conexões entre esquinas e o número de esquinas concatenando os dois numeros
  FILE *arquivo = fopen(nomeArquivo, "r");// ponteiro para leitura do arquivo
  int esquina_entrega, n_esquinas, i;
  fscanf(arquivo, "%d", &esquina_entrega);
  fscanf(arquivo, "%d", &n_esquinas);//numero que representa o numero de esquinas
  int aux = 0;
  while(1){
    fscanf(arquivo, "%d", &i);
    fscanf(arquivo, "%d", &i);
    fscanf(arquivo, "%d", &i);
    if(i == 0){
      break;
    } else{
      aux++;//conta linhas que possuem triplas que representam uma conexão entre esquinas
    }
  }
  fclose(arquivo);
  return aux * 10 + n_esquinas;//usando casas decimais diferentes para os dois números podemos representa-los concatenados
}
  
int guardaVetor(char nomeArquivo[], int *esquinas){//função que guarda as informações das conexões de esquinas em unico vetor e retorna a esquina em que a pizza vai ser entregue
  FILE *arquivo = fopen(nomeArquivo, "r");
  int esquina_entrega, n, i;
  fscanf(arquivo, "%d", &esquina_entrega);
  fscanf(arquivo, "%d", &n);
  i = -1;
  int aux = 0;
  while(1){
    fscanf(arquivo, "%d", &i);
    if(i == 0){
      break;
    } else{
      esquinas[aux] = i;//esquina origem
      fscanf(arquivo, "%d", &esquinas[aux+1]);//esquina destino
      fscanf(arquivo, "%d", &esquinas[aux+2]);//tempo da origem ao destino
      aux += 3;
    }
  }
  fclose(arquivo);
  return esquina_entrega;
}

int **criaMapa(int n, int n_esquinas, int *esquinas){//função que transforma as informações do vetor em uma matriz
  int **mapa = malloc(sizeof(int *) * n_esquinas);//alocação dinamica de vetor bidimensionais
  for(int i = 0; i < n_esquinas; i++){
    mapa[i] = malloc(sizeof(int) * n_esquinas);
  }
  for(int i = 0; i < n_esquinas; i++){
    for(int j = 0; j < n_esquinas; j++){
      mapa[i][j] = 0;
    }
  }
  for(int i = 0; i < (3*n); i+=3){
    mapa[esquinas[i]-1][esquinas[i+1]-1] = esquinas[i+2];//para elementos na matriz do tipo esquinas x esquinas, as esquinas que possuem conexões guardam o tempo levado entre as duas
  }
  return mapa;
}
  
void rotaMaisRapida(int n_esquinas, int **mapa, int *tempos, int *rotas){//função que implementa o pseudocódigo fornecido
  int v, i, e, tempo, min;
  int *aux = (int*) malloc(n_esquinas*sizeof(int));//"Conjunto E que armazena as esquinas do mapa M."
  for(i = 0; i < n_esquinas; i++){//"para cada esquina e em E faça"
    aux[i] = 1;
    tempos[i] = INT_MAX;//aqui a macro int_max é usada para representa o infinito
  }
  tempos[0] = 0;//"tempo gasto para ir da esquina 1 até a esquina 1"
  while(1){
    min = INT_MAX;
    for(i = 0; i < n_esquinas; i++){//faz a busca de "uma esquina em E com menor custo no vetor T[]"
      if(aux[i] && tempos[i] < min){
        min = tempos[i];
        v = i;
      }
    }
    aux[v] = 0;//"remove a esquina v de E"

  for(e = 0; e < n_esquinas; e++){//"para toda esquina interligada v → e tal que e esteja em E faça"
    if(aux[e] && mapa[v][e] > 0){
      tempo = tempos[v] + mapa[v][e];
      if(tempos[e] > tempo){//"se T[e] > T[v] + tempo par ir de v até e"
        tempos[e] = tempo;//"T[e] ← T[v] + tempo par ir de v até e"
        rotas[e] = v + 1;
      }
    }
    }
    int vazio = 1;
    for(i = 0; i < n_esquinas; i++){//verifica se E esta vazio, caso esteja o loop é quebrado
      if(aux[i]){
        vazio = 0;
        break;
      }
    }
    if(vazio){
      break;
    }
  }
}

int main(void){
  int n = leituraArquivo("pizzaria.txt");
  int n_esquinas = n % 10;
  n = n/10;
  //printf("%d\n", n);
  //printf("%d\n", n_esquinas);
  int *esquinas = (int*)malloc((3*n)*sizeof(int));
  int esquina_entrega = guardaVetor("pizzaria.txt", esquinas);
  /*
  for(int i = 0; i < 3*n; i+=3){
    printf("%d %d %d\n", esquinas[i], esquinas[i+1], esquinas[i+2]);
  }
  */
  int **mapa = criaMapa(n, n_esquinas, esquinas);
  /*
  for(int i = 0; i < n_esquinas; i++){
    for(int j = 0; j < n_esquinas; j++){
      if(mapa[i][j] == INT_MAX){
        printf("N ");
      } else{
        printf("%d ",mapa[i][j]);
      }
    }
    printf("\n");
  }
  */
  int *tempos = (int*)malloc((n_esquinas)*sizeof(int));
  int *rotas = (int*)malloc((n_esquinas)*sizeof(int));
  rotaMaisRapida(n_esquinas, mapa, tempos, rotas);
  int rota[n_esquinas];
  int count = 0;
  int esquina = esquina_entrega - 1;
  while(esquina != 0){
    rota[count] = esquina + 1;
    esquina = rotas[esquina] - 1;
    count++;
  }
  rota[count] = 1;
  printf("Melhor rota encontrada até a esquina #%d:", esquina_entrega);
  for(int i = count; i > 0; i--){
    printf("%d ", rota[i]);
  }
  printf("%d\n", rota[0]);
  printf("Tempo até a esquina %d: %d min.", esquina_entrega, tempos[esquina_entrega - 1]);
  return 0;
}
