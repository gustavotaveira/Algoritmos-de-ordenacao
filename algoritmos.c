#include "algoritmos.h"

void insertionSort(int *array, int comprimento, Bool (*compare)(int primeiro, int segundo))
{

  for(int i = 1; i < comprimento; i++)
  {
    int temp = array[i];
    int j = i - 1;
    while(j >= 0 && compare( array[j], temp) == FALSE)
    {
      array[j+1] = array[j];
      j--;
    }
    array[j+1] = temp;
  }
}

void bubbleSort(int elementos){

}
void selectionSort(int elementos){

}
void shellSort(int elementos){

}
void quickSort(int elementos){

}
void mergeSort(int elementos){

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
