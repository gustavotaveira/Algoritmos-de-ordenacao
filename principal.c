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
    int i, valor = -1, qtd = 0, *array;
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
        qtd = inserirEntrada();

        if(qtd!=5){
            //Vetor para entrada decrescente
            array =  (int*)malloc(sizeof(int)*qtd);
            array = entradas(qtd, 20);
        }
        limparTela();

        //inicia tempo de execução
        clock_t t = clock();
        switch(valor){
            case 1:
                //Quick
                break;

            case 2:
                //Chamada da ordenação
                if(qtd==5){
                    d = mergeSort(arrayExcel, 0, comprimento-1);
                }else{
                    d = mergeSort(array, 0, qtd-1);
                }
                break;

            case 3 :
                if(qtd==5){
                    d = bubbleSort(arrayExcel, comprimento);
                }else{
                    d = bubbleSort(array, qtd);
                }
                break;

            case 4 :
                //Selection
                break;

            case 5 :
                //Shell\n
                break;

            case 6 :
                if(qtd==5){
                    d = insertionSort(arrayExcel, comprimento, crescente);
                }else{
                    d = insertionSort(array, qtd, crescente);
                }
                break;

            case 0 :
                system("cls");
                break;

        }
        //Finaliza o tempo de execução
        t = clock() - t;

        if(valor!=0){
            if(qtd==5){
                    //Imprime o vetor
                    imprimeVetor(arrayExcel, comprimento, 20);
                    //Verifica se a ordenação funcionou corretamente
                    if(isSorted(arrayExcel, comprimento, crescente) == TRUE){
                            printf("\n O tempo de execuçao foi de (%f segundos)\t ",((float)t)/CLOCKS_PER_SEC);
                            printf("\n Realizou %d comparações e %d trocas\n",d->comparacoes, d->trocas);
                    }
                    //Imprime as informações
                    informacoes(valor);
            }else{
                //Imprime o vetor
                    imprimeVetor(array, qtd, 20);
                    //Verifica se a ordenação funcionou corretamente
                    if(isSorted(array, qtd, crescente) == TRUE){
                            printf("\n O tempo de execuçao foi de (%f segundos)\t ",((float)t)/CLOCKS_PER_SEC);
                            printf("\n Realizou %d comparações e %d trocas\n",d->comparacoes, d->trocas);
                    }
                    informacoes(valor);
            }
        }else{
            printf("Vetor não ordenado\n");
        }
        inicio(&valor, &isRunning);
    }
    free(d);
    free(array);
    return 0;
}
