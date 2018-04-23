#include<locale.h>
#include<time.h>
#include "utils.h"
#include "algoritmos.h"

int main()
{
  Desempenho *(*funcoes[6])(int *array, int comprimento, Bool (*compare)(int primeiro, int segundo));
  enum Sorts{ QUICK = 0, MERGE = 1, BUBLLE = 2, SELECTION = 3, SHELL = 4, INSERTION = 5};
  /*funcoes[QUICK] = ;
  funcoes[MERGE] = ;
  funcoes[BUBLLE] = ;
  funcoes[SELECTION] = ;*/
  funcoes[SHELL] = shellSort;
  funcoes[INSERTION] = insertionSort;

  setlocale(LC_ALL, "portuguese");

  Vetor *arrayExcel = carregaExcel();

  sortTeste(INSERTION, *arrayExcel, crescente);
  sortTeste(SHELL, *arrayExcel, crescente);

  free((*arrayExcel)->array);
  free(arrayExcel);
  return 0;
}
