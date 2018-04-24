#include "utils.h"

Desempenho *(*funcoes[6])(int *array, int comprimento, Bool (*compare)(int primeiro, int segundo));


void imprimeVetor(int *arrayExcel, int comprimento, const int tamanhoLinha)
{
  int s = 0;
  for(int i = 0; i < comprimento; i++)
  {
    if(s < tamanhoLinha)
    {
      printf("[%d] ", arrayExcel[i]);
      s++;
    }
    else
    {
      printf("\n[%d] ", arrayExcel[i]);
      s = 1;
    }
  }
  printf("\n");
}

Vetor *carregaExcel()
{
  FILE *excel = fopen("vetor de entrada.csv", "r");
  if(excel == NULL)
  {
    printf("ERRO: Falha ao abrir arquivo csv\n");
    return NULL;
  }

  char buffer[8];
  //Estrutura que guarda o endereço do array e o seu comprimento
  Vetor *arrayExcel = (Vetor*)malloc(sizeof(Vetor));
  //Contador da quantidade de numeros contidos no arquivo de texto
  (*arrayExcel).comprimento = 0;
  //Conta a quantidade de numeros no arquivo
  while(fgets(buffer, 8, excel) != NULL)
  {
    (*arrayExcel).comprimento++;
  }
  //Retorna o ponteiro do arquivo de texto para o inicio
  fseek(excel, 0, SEEK_SET);
  //Reserva o espaço de memoria para o array do arquivo
  (*arrayExcel).array = (int*)malloc(sizeof(int) * (*arrayExcel).comprimento);
  //Preenche o arquivo
  for(int i = 0; i < (*arrayExcel).comprimento; i++)
  {
    fgets(buffer, 8, excel);
    ((*arrayExcel).array)[i] = atoi(buffer);
  }
  //Fecha o arquivo
  fclose(excel);
  return arrayExcel;
}

void sortTeste(int tipo, Vetor array, Bool (*compare)(int primeiro, int segundo))
{
  //Preparando os campos constantes na tabela
  char *nome;
  char *complexidade = "O(n²)";;
  char *otimo = "N";;
  char *estavel;
  char *inplace;
  switch (tipo)
  {
    case QUICK:
      nome = "Quick Sort";
      estavel = "N";
      inplace = "N";
      break;
    case MERGE:
      nome = "Merge Sort";
      complexidade = "O(n*log(n))";
      otimo = "S";
      estavel = "S";
      inplace = "N";
      break;
    case BUBBLE:
      nome = "Bublle Sort   ";
      estavel = "S";
      inplace = "S";
      break;
    case SELECTION:
      nome = "Selection Sort";
      estavel = "N";
      inplace = "S";
      break;
    case SHELL:
      nome = "Shell Sort    ";
      estavel = "N";
      inplace = "S";
      break;
    case INSERTION:
      nome = "Insertion Sort";
      estavel = "S";
      inplace = "S";
      break;
  }
  //Duplicando o vetor a ser ordenado
  int *duplicado = (int*)malloc(sizeof(int) * array.comprimento);
  memcpy(duplicado, array.array, sizeof(int) * array.comprimento);
  //Ponteiro que vai apontar para a estrutura que armazenara o desempenho
  Desempenho *d = NULL;
  //Ordena o Vetor por Insertion Sort
  clock_t t = clock();
  d = funcoes[tipo](duplicado, array.comprimento, compare);
  t = clock() - t;
  //Imprime o vetor
  //imprimeVetor(arrayExcel, comprimento, 20);
  //Verifica se a ordenação funcionou corretamente
  if(isSorted(duplicado, array.comprimento, compare) == TRUE)
    printf("%s [%d ciclos do processador] [%f segundos] [%d comparações] [%d trocas]\n",nome,
             t, ((float)t)/CLOCKS_PER_SEC, d->comparacoes, d->trocas);
  else
    printf("Falha ao ordenar por %s\n", nome);


  //Desalocando memoria dinamica
  free(duplicado);
  free(d);
}
