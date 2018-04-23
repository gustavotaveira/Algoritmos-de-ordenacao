
#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include<stdio.h>
#include<stdlib.h>

//Define o tipo Bool
typedef enum { FALSE = 0, TRUE = 1}Bool;

typedef struct _Desempenho
{
  int comparacoes;
  int trocas;
}Desempenho;

Desempenho *insertionSort(int *array, int comprimento, Bool (*compare)(int primeiro, int segundo));
Desempenho *bubbleSort(int *array, int comprimento);
void selectionSort(int elementos);
void shellSort(int elementos);
void quickSort(int elementos);
Desempenho *mergeSort(int *array, int comeco, int fim);

//Retorna TRUE se array estiver ordenado de acordo com a comparação da função compare
Bool isSorted(int *array, int comprimento, Bool (*compare)(int primeiro, int segundo));
Bool crescente(int primeiro, int segundo);
Bool decrescente(int primeiro, int segundo);

#endif /* ALGORITMOS_H */
