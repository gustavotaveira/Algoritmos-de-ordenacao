#include "utils.h"


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
