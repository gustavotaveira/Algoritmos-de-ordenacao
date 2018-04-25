#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>

#include "utils.h"
#define TRUE 1
#define FALSE 0

void imprimeVetor(int *arrayExcel, int comprimento, const int tamanhoLinha)
{
  int s = 0, i;
  for( i = 0; i < comprimento; i++)
  {
    if(s < tamanhoLinha)
    {
      printf("[%d] ", arrayExcel[i]);
      s++;
    }
    else
    {
      printf("\n[%d] ", arrayExcel[i]);
      s = 1;
    }
  }
  printf("\n");
}

int* gerarArrayExcel(int *comprimento){
    int i;
    FILE *excel = fopen("vetor de entrada.csv", "r");
    if(excel == NULL)
    {
      printf("ERRO: Falha ao abrir arquivo csv\n");
      exit(1);
    }

    char buffer[8];
    //Contador da quantidade de numeros contidos no arquivo de texto
    comprimento = 0;

    //Conta a quantidade de numeros no arquivo
    while(fgets(buffer, 8, excel) != NULL)
    {
      comprimento++;
    }
    //Retorna o ponteiro do arquivo de texto para o inicio
    fseek(excel, 0, SEEK_SET);
    //Reserva o espaco de memoria para o array do arquivo

    int *arrayExcel = (int*)malloc(sizeof(int) * (*comprimento));
    //Preenche o arquivo
    int i;
    for(i = 0; i < *comprimento; i++)
    {
      fgets(buffer, 8, excel);
      arrayExcel[i] = atoi(buffer);
    }
    //Fecha o arquivo
    fclose(excel);
    return arrayExcel;
}

void menu(){
    printf("Digite qual a forma de ordenação desejada:\n");
    printf("\t1- Quick Sort\n");
    printf("\t2- Merge Sort\n");
    printf("\t3- Bubble Sort\n");
    printf("\t4- Selection Sort\n");
    printf("\t5- Shell Sort\n");
    printf("\t6- Insertion Sort\n");
    printf("\t0 - Sair\n");
}

void inserirEntrada(){
    printf("Digite qual a entrada desejada:\n");
    printf("\t1- Vetor decrescente de 500\n");
    printf("\t2- Vetor decrescente de 1000\n");
    printf("\t3- Vetor decrescente de 10000\n");
    printf("\t4- Vetor decrescente de 50000\n");
    printf("\t5- Entrada do excel\n");
    printf("\t0 - Sair\n");
}

void limparTela(){
    system("cls");
}

void inicio(int* controle, int* isRunning){
    printf("\nDeseja retornar ao menu pricipal?\n 1 - Sim\n0 - Não\n");
    scanf("%d", controle);
    if(*controle  == 0){
        *isRunning = FALSE;
    }
    limparTela();
}

void informacoes(int valor){
    switch(valor){
        case 1:
            printf(" O método Quick sort é do tipo Divisão e conquista\n O pior caso é O(n²)\n Não é estável\n Não é in-place\n E não é ótimo\n");
            break;
        case 2:
            printf(" O método Merge sort é do tipo Divisão e conquista\n O pior caso é Teta(n logo n)\n É estável\n Não é in-place\n E é ótimo\n");
            break;
        case 3:
            printf(" O método Bubble sort é do tipo Flutuação\n O pior caso é O(n²)\n É estável\n É in-place\n E não é ótimo\n");
            break;
        case 4:
            printf(" O método Selection sort é do tipo Seleção\n O pior caso é O(n²)\n Não é estável\n É in-place\n E não é ótimo\n");
            break;
        case 5:
            printf(" O método Shell sort é do tipo Ordenação por inserção\n O pior caso é O(n²)\n Não é est�vel\n É in-place\n E não é ótimo\n");
            break;
        case 6:
            printf(" O método Insertion sort é do tipo Ordenação por inserção\n O pior caso é O(n²)\n É estável\n É in-place\n E não é ótimo\n");
            break;
    }
}

popular(int* array, int tam){
    int i, j = 0;
    for(i=tam; i>0; i--){
        *(array+j) = i;
        j++;
    }
}

int size(int* array){

}
