
#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include<stdio.h>
#include<stdlib.h>

//Define o tipo Bool
typedef enum { FALSE = 0, TRUE = 1}Bool;

enum Sorts{ QUICK = 0, MERGE = 1, BUBBLE = 2, SELECTION = 3, SHELL = 4, INSERTION = 5};

typedef struct _Desempenho
{
  int comparacoes;
  int trocas;
}Desempenho;


Desempenho *insertionSort(int *array, int comprimento, Bool (*compare)(int primeiro, int segundo));
Desempenho *bubbleSort(int *array, int comprimento, Bool (*compare)(int primeiro, int segundo));
Desempenho *selectionSort(int *array, int comprimento, Bool (*compare)(int primeiro, int segundo));
Desempenho *shellSort(int *array, int comprimento, Bool (*compare)(int primeiro, int segundo));
Desempenho *quickSort(int *array, int comprimento, Bool (*compare)(int primeiro, int segundo));
Desempenho *mergeSort(int *array, int comprimento, Bool (*compare)(int primeiro, int segundo));

//Retorna TRUE se array estiver ordenado de acordo com a comparação da função compare
Bool isSorted(int *array, int comprimento, Bool (*compare)(int primeiro, int segundo));
Bool crescente(int primeiro, int segundo);
Bool decrescente(int primeiro, int segundo);

#endif /* ALGORITMOS_H */
