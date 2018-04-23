#include<locale.h>
#include "utils.h"

int main()
{  extern Desempenho *(*funcoes[6])(int *array, int comprimento, Bool (*compare)(int primeiro, int segundo));
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

  free((*arrayExcel).array);
  free(arrayExcel);
  return 0;
}
