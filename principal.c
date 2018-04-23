#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
#include "utils.h"
#include "algoritmos.h"



int main()
{

    setlocale(LC_ALL, "portuguese");
    FILE *excel = fopen("vetor de entrada.csv", "r");
    if(excel == NULL)
    {
      printf("ERRO: Falha ao abrir arquivo csv\n");
      return 1;
    }

    char buffer[8];
    //Contador da quantidade de numeros contidos no arquivo de texto
    int comprimento = 0, isRunning = TRUE;
    int i, valor = -1, qtd = 0;
    int *array;
    //Conta a quantidade de numeros no arquivo
    while(fgets(buffer, 8, excel) != NULL)
    {
      comprimento++;
    }
    //Retorna o ponteiro do arquivo de texto para o inicio
    fseek(excel, 0, SEEK_SET);
    //Reserva o espaço de memoria para o array do arquivo
    int *arrayExcel = (int*)malloc(sizeof(int) * comprimento);
    //Preenche o arquivo
    for( i = 0; i < comprimento; i++)
    {
      fgets(buffer, 8, excel);
      arrayExcel[i] = atoi(buffer);
    }
    //Fecha o arquivo
    fclose(excel);

    //Ponteiro que vai apontar para a estrutura que armazenara o desempenho
    Desempenho *d = NULL;
    while(isRunning == TRUE){

        menu();
        scanf("%d", &valor);
        inserirEntrada();
        scanf("%d", &qtd);
        array = (int*)malloc(sizeof(int)*qtd);
        for( i = 0; i < comprimento; i++){

            array[i] = atoi(buffer);
        }
        *array = entradas(qtd, 20);
        limparTela();
        //inicia tempo de execução
        clock_t t = clock();
        switch(valor){
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
