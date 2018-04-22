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
    int comprimento = 0;
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
    for(int i = 0; i < comprimento; i++)
    {
      fgets(buffer, 8, excel);
      arrayExcel[i] = atoi(buffer);
    }
    //Fecha o arquivo
    fclose(excel);

    //Imprime o vetor
    imprimeVetor(arrayExcel, comprimento, 20);

    //Ponteiro que vai apontar para a estrutura que armazenara o desempenho
    Desempenho *d = NULL;
    //Ordena o Vetor por Insertion Sort
    clock_t t = clock();
    d = insertionSort(arrayExcel, comprimento, crescente);
    t = clock() - t;
    //Imprime o vetor
    imprimeVetor(arrayExcel, comprimento, 20);
    //Verifica se a ordenação funcionou corretamente
    if(isSorted(arrayExcel, comprimento, crescente) == TRUE)
      printf("Array ordenado por InsertionSort\nFoi levado %d ciclos do processador\
              (%f segundos)\nRealizou %d comparações e %d trocas\n",
               t, ((float)t)/CLOCKS_PER_SEC, d->comparacoes, d->trocas);
    else
      printf("Array não ordenado\n");

    free(d);
    return 0;
}
