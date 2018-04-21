#include "algoritmos.h"

void insertionSort(int elementos){

}
void bubbleSort(int elementos){

}
void selectionSort(int elementos){
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
}
void shellSort(int elementos){

}
void quickSort(int elementos){

}
void mergeSort(int elementos){

}
