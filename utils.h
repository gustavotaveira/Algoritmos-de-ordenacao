#ifndef UTILS_H
#define UTILS_H

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<time.h>
#include "algoritmos.h"

typedef struct _Vetor
{
  int *array;
  int comprimento;
}Vetor;

void imprimeVetor(int *arrayExcel, int comprimento, const int tamanhoLinha);
void sortTeste(int tipo, Vetor array, Bool (*compare)(int primeiro, int segundo));
Vetor *carregaExcel();

#endif /* UTILS_H */
