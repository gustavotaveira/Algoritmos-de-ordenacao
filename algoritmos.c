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
 Desempenho* selectionSort(int elementos){
    clock_t tempoExecucao;
    int i =0, j = 0, menor;
    int comparacoes = 0;
    int trocas = 0;
    char complexidade[] = "n^2";
    int otimo = TRUE;
    int estavel = FALSE;
    int inPlace = TRUE;
    char tipoOrdenacao[] = "Seleção";
    int vetor[elementos];
    int aux;
    printf("Criando vetor: ");
    for(i = elementos;i > 0; i--){
        vetor[j] = i;
        printf("%d ", vetor[j]);
        j++;
    }
    tempoExecucao = clock();

   for(i=0; i<elementos; i++){
           menor = i;
         for(j=i+1; j<elementos; j++){
           if(vetor[j] < vetor[menor]){
               menor = j;
            }
            comparacoes++;
        }
       if(vetor[i] != vetor[menor]){
            aux = vetor[i];
           vetor[i] = vetor[menor];
            vetor[menor] = aux;
            trocas++;
        }
    }
    tempoExecucao = clock() - tempoExecucao;
    printf("\n\n");
  printf("Saída: ");
    for(i = 0; i < elementos; i++){
        printf("%d ", vetor[i]);
    }
   printf("\n\nTempo de execução: %f ms\n", ((float)tempoExecucao)/CLOCKS_PER_SEC);
   printf("Comparações: %d\n", comparacoes);
   printf("Trocas: %d\n", trocas);
   printf("Complexidade: %s\n", complexidade);
    printf("Ótimo: %s\n", otimo == TRUE? "SIM" : "NAO");
    printf("Estável: %s\n", estavel == TRUE? "SIM" : "NAO");
    printf("In-place: %s\n", inPlace == TRUE? "SIM" : "NAO");
    printf("Tipo de ordenação: %s\n\n", tipoOrdenacao);
    return 0;
 }
void shellSort(int elementos){

}
void quickSort(int elementos){

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




//Retorna TRUE se array estiver ordenado de acordo com a comparaÃ§Ã£o da funÃ§Ã£o compare
Bool isSorted(int *array, int comprimento, Bool (*compare)(int primeiro, int segundo))
{
   int i;
  //Repede do segundo termo atÃ© o ultimo
  for(i = 1; i < comprimento; i++)
  {
    //Realiza a comparaÃ§Ã£o entre o termo anterior e o atual
    //Caso a comparaÃ§Ã£o falhe termina a funÃ§Ã£o
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
