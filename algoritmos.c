#include "algoritmos.h"

Desempenho *insertionSort(int *array, int comprimento, Bool (*compare)(int primeiro, int segundo))
{
  Desempenho *desInsert = (Desempenho*)malloc(sizeof(Desempenho));
  desInsert->trocas = 0;
  desInsert->comparacoes = 0;
  for(int i = 1; i < comprimento; i++)
  {
    int temp = array[i];
    int j = i - 1;
    while(j >= 0 && (desInsert->comparacoes++, compare( array[j], temp) == FALSE))
    {
      array[j+1] = array[j];
      desInsert->trocas++;
      j--;
    }
    array[j+1] = temp;
    desInsert->trocas++;
  }
  return desInsert;
}

Desempenho *bubbleSort(int *array, int comprimento, Bool (*compare)(int primeiro, int segundo))
{
  Desempenho *desInsert = (Desempenho*)malloc(sizeof(Desempenho));
  desInsert->trocas = 0;
  desInsert->comparacoes = 0;
  for(int i = comprimento - 1; i > 0; i--)
  {
    for(int j = 0; j < i; j++)
    {
      if(desInsert->comparacoes++, compare(array[j+1], array[j]))
      {
        int temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
        desInsert->trocas++;
      }
    }
  }
  return desInsert;
}
Desempenho *selectionSort(int *array, int comprimento, Bool (*compare)(int primeiro, int segundo))
{
  Desempenho *desInsert = (Desempenho*)malloc(sizeof(Desempenho));
  desInsert->trocas = 0;
  desInsert->comparacoes = 0;
  for(int i = 0; i < comprimento - 1; i++)
  {
    int min = i;
    for(int j = i + 1; j < comprimento; j++)
    {
      if(desInsert->comparacoes++, compare(array[j], array[min]) == FALSE)
        min = j;
    }
    int temp = array[i];
    array[i] = array[min];
    array[min] = temp;
    desInsert->trocas++;
  }
  return desInsert;
}
Desempenho *shellSort(int *array, int comprimento, Bool (*compare)(int primeiro, int segundo))
{
  Desempenho *desInsert = (Desempenho*)malloc(sizeof(Desempenho));
  desInsert->trocas = 0;
  desInsert->comparacoes = 0;
  for(int h = comprimento/2; h > 0; h = h/2)
  {
    for(int i = h; i < comprimento; i++)
    {
      int temp = array[i];
      int j;
      for(j = i; j >= h &&(desInsert->comparacoes++, compare( array[j - h], temp) == FALSE); j = j - h)
      {
        array[j] = array[j - h];
        desInsert->trocas++;
      }
      array[j] = temp;
      desInsert->trocas++;
    }

  }
  return desInsert;
}

Desempenho *quickSort(int *array, int comprimento, Bool (*compare)(int primeiro, int segundo))
{

}
Desempenho *mergeSort(int *array, int comprimento, Bool (*compare)(int primeiro, int segundo))
{

}




//Retorna TRUE se array estiver ordenado de acordo com a comparação da função compare
Bool isSorted(int *array, int comprimento, Bool (*compare)(int primeiro, int segundo))
{
  //Repede do segundo termo até o ultimo
  for(int i = 1; i < comprimento; i++)
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
