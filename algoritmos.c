#include "algoritmos.h"


Desempenho *insertionSort(int *array, int comprimento, Bool (*compare)(int primeiro, int segundo))
{
  int i, j;
  Desempenho *desInsert = (Desempenho*)malloc(sizeof(Desempenho));
  desInsert->trocas = 0;
  desInsert->comparacoes = 0;
  for(i = 1; i < comprimento; i++)
  {
    int temp = array[i];
    j = i - 1;
    while(j >= 0 && (compare( array[j], temp) == FALSE))
    {
      desInsert->trocas++;
      desInsert->comparacoes++;
      array[j+1] = array[j];
      j--;
    }
    array[j+1] = temp;
  }
  return desInsert;
}

Desempenho *bubbleSort(int *array, int comprimento)
{
    int i, j, aux;
    Desempenho *desBubble = (Desempenho*)malloc(sizeof(Desempenho));
    desBubble->trocas = 0;
    desBubble->comparacoes = 0;

    for (i = 1; i < comprimento; i++) {
        for (j = 0; j < comprimento - 1; j++) {
            desBubble->comparacoes++;
            if (array[j] > array[j + 1]) {
                desBubble->trocas++;
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
        }
    }
    return desBubble;
}
 Desempenho* selectionSort(int* array, int comprimento){
    Desempenho *desempenho =(Desempenho*) malloc(sizeof(Desempenho));
    int i =0, j = 0, menor;
    int comparacoes = 0;
    int trocas = 0;
    int aux;
    desempenho->comparacoes = 0;
    desempenho->trocas = 0;

   for(i=0; i<comprimento; i++){

        menor = i;

        for(j=i+1; j<comprimento; j++){

            if(array[j] < array[menor]){
               menor = j;
            }

            desempenho->comparacoes++;
        }

       if(array[i] != array[menor]){
            aux = array[i];
            array[i] = array[menor];
            array[menor] = aux;
            desempenho->trocas++;
        }
    }
    return desempenho;
 }
 Desempenho *shellSort(int *array, int comprimento, Bool (*compare)(int primeiro, int segundo))
 {
   Desempenho *desShell = (Desempenho*)malloc(sizeof(Desempenho));
   desShell->trocas = 0;
   desShell->comparacoes = 0;
   int i, h;
   for(h = comprimento/2; h > 0; h = h/2)
   {
     for(i = h; i < comprimento; i++)
     {
       int temp = array[i];
       int j;
       for(j = i; j >= h &&(desShell->comparacoes++, compare( array[j - h], temp) == FALSE); j = j - h)
       {
         array[j] = array[j - h];
         desShell->trocas++;
       }
       array[j] = temp;
       desShell->trocas++;
     }

   }
   return desShell;
 }
Desempenho* quickSort(int *array, int comprimento){
    Desempenho *desempenho = (Desempenho*)malloc(sizeof(Desempenho));
    desempenho->comparacoes = 0;
    desempenho->trocas = 0;
    quick(array, 0, comprimento - 1, desempenho);
    return desempenho;
}

void quick(int *array, int esq, int dir, Desempenho* desempenho ){

    if(esq < dir){
        int pivo = separar(array, esq, dir, desempenho);
        quick(array, esq, pivo-1, desempenho);
        quick(array, pivo+1, dir, desempenho);
    }
}

int separar(int *array, int esq, int dir, Desempenho* desempenho){
    int i = esq, j =  dir;
    int aux;
    int pivo = array[esq];

    while(i < j){
        desempenho->comparacoes++;
        while(i < dir && array[i] <= pivo) {
            i++;
            desempenho->comparacoes++;
        }
        desempenho->comparacoes++;
        while(j > esq && array[j] >= pivo) {
            j--;
            desempenho->comparacoes++;
        }

        if(i < j){
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
            i++;
            j--;
            desempenho->trocas++;
        }
        aux = array[esq];
        array[esq] = array[j];
        array[j] = aux;
        desempenho->trocas++;
        return j;
    }
}


Desempenho *mergeSort(int *array, int comeco, int fim){
    Desempenho *desMerge = (Desempenho*)malloc(sizeof(Desempenho));
    desMerge->trocas = 0;
    desMerge->comparacoes = 0;
    if (comeco < fim) {
        int meio = (comeco+fim)/2;
        mergeSort(array, comeco, meio);
        mergeSort(array, meio+1, fim);
        int n1 = comeco, n2 = meio+1,comecoAux = 0, tam = (fim-comeco+1);
        int *aux;
        aux = (int*)malloc(sizeof(int) * tam);

        while(n1 <= meio && n2 <= fim){
            desMerge->comparacoes++;
            if(array[n1] < array[n2]) {
                aux[comecoAux] = array[n2];
                n1++;
                desMerge->trocas++;
            } else {
                aux[comecoAux] = array[n2];
                n2++;
                desMerge->trocas++;
            }
            comecoAux++;
        }

        while(n1 <= meio){  //Caso ainda haja elementos na primeira metade
            aux[comecoAux] = array[n1];
            comecoAux++;
            n1++;
        }

        while(n2 <= fim) {   //Caso ainda haja elementos na segunda metade
            aux[comecoAux] = array[n2];
            comecoAux++;
            n2++;
        }

        for(comecoAux = comeco; comecoAux <= fim; comecoAux++){    //Move os elementos de volta para o vetor original
            array[comecoAux] = aux[comecoAux-comeco];
        }
        free(aux);

        }
        return desMerge;
        free(desMerge);
}




//Retorna TRUE se array estiver ordenado de acordo com a comparação da função compare
Bool isSorted(int *array, int comprimento, Bool (*compare)(int primeiro, int segundo))
{
   int i;
  //Repede do segundo termo até o ultimo
  for(i = 1; i < comprimento; i++)
  {
    //Realiza a comparação entre o termo anterior e o atual
    //Caso a comparação falhe termina a função
    if(compare(array[i-1],array[i]) == FALSE)
      return FALSE;
  }
  return TRUE;
}
//Retorna FALSE caso a ordem esteja errada
Bool crescente(int primeiro, int segundo)
{
  if(primeiro <= segundo)
    return TRUE;
  return FALSE;
}
//Retorna FALSE caso a ordem esteja errada
Bool decrescente(int primeiro, int segundo)
{
  if(primeiro >= segundo)
    return TRUE;
  return FALSE;
}
