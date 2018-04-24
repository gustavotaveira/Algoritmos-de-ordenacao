#include "algoritmos.h"

int cont1 = 0, cont2=0;

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
        for (j = 0; j < comprimento - i; j++) {
            desBubble->comparacoes++;
            if (array[j] > array[j + 1]) {
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
                desBubble->trocas = desBubble->trocas + 3;
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
   int h, i;
   Desempenho *desShell = (Desempenho*)malloc(sizeof(Desempenho));
   desShell->trocas = 0;
   desShell->comparacoes = 0;
   for( h = comprimento/2; h > 0; h = h/2)
   {
     for( i = h; i < comprimento; i++)
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

Desempenho *quickSort(int *array, int comprimento){
}

Desempenho *mergeSort(int *vetor, int comeco, int fim){
    Desempenho *desMerge = (Desempenho*)malloc(sizeof(Desempenho));
    desMerge->comparacoes=0;
    desMerge->trocas=0;
    if (comeco < fim) {
        int meio = (fim+comeco)/2;
        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
        desMerge->comparacoes = cont1;
        desMerge->trocas = cont2;
    }
    return desMerge;
    free(desMerge);
}

void merge(int *vetor, int comeco, int meio, int fim) {
    int n1 = comeco, n2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *aux;
    aux = (int*)malloc(tam * sizeof(int));
    while(n1 <= meio && n2 <= fim){
        cont1++;
        if(vetor[n1] < vetor[n2]) {
            aux[comAux] = vetor[n1];
            n1++;
            cont2++;
        } else {
            aux[comAux] = vetor[n2];
            n2++;
            cont2++;
        }
        comAux++;
    }

    while(n1 <= meio){  //Caso ainda haja elementos na primeira metade
        aux[comAux] = vetor[n1];
        comAux++;
        n1++;
        cont2++;
    }

    while(n2 <= fim) {   //Caso ainda haja elementos na segunda metade
        aux[comAux] = vetor[n2];
        comAux++;
        n2++;
        cont2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        vetor[comAux] = aux[comAux-comeco];
        cont2++;
    }
    free(aux);
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
