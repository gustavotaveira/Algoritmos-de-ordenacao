#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
#include "utils.h"
#include "algoritmos.h"

int main()
{
    setlocale(LC_ALL, "portuguese-brazilian");

    //Ponteiro que vai apontar para a estrutura que armazenara o desempenho
    Desempenho *d = NULL;

    int *array;
    int comprimento;
    int algoritmo = -1;
    int entrada = -1;
    int isRunning = TRUE;
    while(isRunning == TRUE){

        menu();
        scanf("%d", &algoritmo);

        limparTela();

        inserirEntrada();
        scanf("%d", &entrada);

        switch(entrada){
            case 1:
                array = (int*)malloc(sizeof(int)*500);
                popular(array, 500);
                comprimento = 500;
                break;
            case 2:
                array = (int*)malloc(sizeof(int)*1000);
                popular(array, 1000);
                comprimento = 1000;
                break;
            case 3:
                array = (int*)malloc(sizeof(int)*10000);
                popular(array, 10000);
                comprimento = 10000;
                break;
            case 4:
                array = (int*)malloc(sizeof(int)*50000);
                popular(array, 50000);
                comprimento = 50000;
                break;
            case 5:
                array = gerarArrayExcel(&comprimento);
                break;
            case 0:
                isRunning = FALSE;
                break;
        }
        limparTela();
        printf("Processando...\n");
        //inicia tempo de execução
        clock_t t = clock();
        switch(algoritmo){
            case 1:
                d= quickSort(array, comprimento);
                break;
            case 2:
                //Chamada da ordenação
                d = mergeSort(array, 0, comprimento-1);
                break;
            case 3 :
                d = bubbleSort(array, comprimento);
                break;
            case 4 :
                d = selectionSort(array, comprimento);
                break;
            case 5 :
                d = shellSort(array, comprimento, crescente);
                break;
            case 6 :
                d = insertionSort(array, comprimento, crescente);
                break;
            case 0 :
                system("cls");
                break;
        }
        //Finaliza o tempo de execução
        t = clock() - t;
        limparTela();
        if(algoritmo!=0){
            //Imprime o vetor
            imprimeVetor(array, comprimento, 20);
            //Verifica se a ordenação funcionou corretamente
            if(isSorted(array, comprimento, crescente) == TRUE){
                printf("\nFoi levado %d ciclos do processador\
                      (%.5f milisegundos)\nRealizou %d comparações e %d trocas\n",
                       t, ((float)t)*1000/CLOCKS_PER_SEC, d->comparacoes, d->trocas);
                //Imprime as informações
                informacoes(algoritmo);
                //printf("ARRAY %d",array[3]);
            }else{
              printf("Vetor não ordenado\n");
            }
        }
        inicio(&algoritmo, &isRunning);
    }
    free(d);
    return 0;
}
