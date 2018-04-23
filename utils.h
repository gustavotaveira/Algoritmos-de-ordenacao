#ifndef UTILS_H
#define UTILS_H

#include<stdio.h>
#include<stdlib.h>

typedef struct _Vetor
{
  int *array;
  int comprimento;
}Vetor;

void imprimeVetor(int *arrayExcel, int comprimento, const int tamanhoLinha);
void sortTeste(enum Sorts tipo, Vetor array, Bool (*compare)(int primeiro, int segundo));
Vetor *carregaExcel();

#endif /* UTILS_H */
