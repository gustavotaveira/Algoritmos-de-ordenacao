#include<locale.h>
#include "utils.h"

int main()
{  extern Desempenho *(*funcoes[6])(int *array, int comprimento, Bool (*compare)(int primeiro, int segundo));
  /*funcoes[QUICK] = quickSort;
  funcoes[MERGE] = mergeSort;*/
  funcoes[BUBBLE] = bubbleSort;
  funcoes[SELECTION] = selectionSort;
  funcoes[SHELL] = shellSort;
  funcoes[INSERTION] = insertionSort;

  setlocale(LC_ALL, "portuguese");

  Vetor *arrayExcel = carregaExcel();

  Vetor dec500;
  dec500.array = (int*)malloc(sizeof(int) * 500);
  dec500.comprimento = 500;
  for(int i = 0; i < 500; i++)
    dec500.array[i] = 500 - i;
  Vetor dec1000;
  dec1000.array = (int*)malloc(sizeof(int) * 1000);
  dec1000.comprimento = 1000;
  for(int i = 0; i < 1000; i++)
    dec1000.array[i] = 1000 - i;
  Vetor dec10_000;
  dec10_000.array = (int*)malloc(sizeof(int) * 10000);
  dec10_000.comprimento = 10000;
  for(int i = 0; i < 10000; i++)
    dec10_000.array[i] = 10000 - i;
  Vetor dec50_000;
  dec50_000.array = (int*)malloc(sizeof(int) * 50000);
  dec50_000.comprimento = 50000;
  for(int i = 0; i < 50000; i++)
    dec50_000.array[i] = 50000 - i;

  printf("\nTeste sobre o vetor decrescente de 500 itens\n");
  sortTeste(INSERTION, dec500, crescente);
  sortTeste(SHELL, dec500, crescente);
  sortTeste(BUBBLE, dec500, crescente);
  sortTeste(SELECTION, dec500, crescente);
  printf("\nTeste sobre o vetor decrescente de 1000 itens\n");
  sortTeste(INSERTION, dec1000, crescente);
  sortTeste(SHELL, dec1000, crescente);
  sortTeste(BUBBLE, dec1000, crescente);
  sortTeste(SELECTION, dec1000, crescente);
  printf("\nTeste sobre o vetor decrescente de 10.000 itens\n");
  sortTeste(INSERTION, dec10_000, crescente);
  sortTeste(SHELL, dec10_000, crescente);
  sortTeste(BUBBLE, dec10_000, crescente);
  sortTeste(SELECTION, dec10_000, crescente);
  printf("\nTeste sobre o vetor decrescente de 50.000 itens\n");
  sortTeste(INSERTION, dec50_000, crescente);
  sortTeste(SHELL, dec50_000, crescente);
  sortTeste(BUBBLE, dec50_000, crescente);
  sortTeste(SELECTION, dec50_000, crescente);
  printf("\nTeste sobre o vetor fornecido no Excel\n");
  sortTeste(INSERTION, *arrayExcel, crescente);
  sortTeste(SHELL, *arrayExcel, crescente);
  sortTeste(BUBBLE, *arrayExcel, crescente);
  sortTeste(SELECTION, *arrayExcel, crescente);

  free((*arrayExcel).array);
  free(arrayExcel);
  return 0;
}
