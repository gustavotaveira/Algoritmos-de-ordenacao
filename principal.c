#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
#include "utils.h"
#include "algoritmos.h"

int main()
{
    setlocale(LC_ALL, "portuguese");

    //Ponteiro que vai apontar para a estrutura que armazenara o desempenho
    Desempenho *d = NULL;

    int *array;
    int comprimento;
    int controle = -1;
    while(isRunning == TRUE){

        menu();
        scanf("%d", &controle);

        inserirEntrada();
        scanf("%d", &entrada);

        switch(entrada){
            case 1:
                array = (int*)malloc(sizeof(int)*500);
                popular(int *array, 500);
            break;
            case 2:
                array = (int*)malloc(sizeof(int)*1000);
                popular(int *array, 1000);
                break;
            case 3:
                array = (int*)malloc(sizeof(int)*10000);
                popular(int *array, 10000);
                break;
            case 4:
                array = (int*)malloc(sizeof(int)*50000);
                popular(int *array, 50000);
                break;
            case 5:
                array = gerarArrayExcel();
                break;
            case 0:
                isRunning = FALSE;
                break;
        }
        limparTela();
        comprimento = sizeof(array)/sizeof(int);
        //inicia tempo de execução
        clock_t t = clock();
        switch(controle){
            case 1:
                //Quick
                break;

            case 2:
                //Chamada da ordenação
                d = mergeSort(array, 0, comprimento-1);
                break;

            case 3 :
                d = bubbleSort(array, comprimento);
                break;

            case 4 :
                d = selectionSort(array, comprimento)
                break;

            case 5 :
                //Shell\n
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

        if(valor!=0){
            //Imprime o vetor
            imprimeVetor(arrayExcel, comprimento, 20);
            //Verifica se a ordenação funcionou corretamente
            if(isSorted(arrayExcel, comprimento, crescente) == TRUE){
                printf("\nFoi levado %d ciclos do processador\
                      (%f segundos)\nRealizou %d comparações e %d trocas\n",
                       t, ((float)t)/CLOCKS_PER_SEC, d->comparacoes, d->trocas);
                //Imprime as informações
                informacoes(valor);
                //printf("ARRAY %d",array[3]);
            }else{
              printf("Vetor não ordenado\n");
            }
        }
        inicio(&valor, &isRunning);
    }
    free(d);
    return 0;
}




    /*menu();
    scanf("%d", &valor);

    //inicia tempo
    clock_t t = clock();
    switch ( valor )
    {
     case 1:
       //Quick

     break;

     case 2:
        //Chamada da ordenação
        d = mergeSort(arrayExcel, 0, comprimento-1);
     break;

     case 3 :
        d = bubbleSort(arrayExcel, comprimento);
     break;

     case 4 :
        //Selection
     break;

     case 5 :
        //Shell\n
     break;

     case 6 :
        d = insertionSort(arrayExcel, comprimento, crescente);
     break;

     default :
       printf ("Valor invalido!\n");
    //getch();
    return 0;
    }
    //Finaliza o tempo
    t = clock() - t;

    //Imprime o vetor
    imprimeVetor(arrayExcel, comprimento, 20);
    //Verifica se a ordenação funcionou corretamente
    if(isSorted(arrayExcel, comprimento, crescente) == TRUE)
      printf("\nFoi levado %d ciclos do processador\
              (%f segundos)\nRealizou %d comparações e %d trocas\n",
               t, ((float)t)/CLOCKS_PER_SEC, d->comparacoes, d->trocas);
    else
      printf("Vetor não ordenado\n");

    free(d);
    return 0;
}*/
