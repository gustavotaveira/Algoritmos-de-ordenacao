#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>

#include "utils.h"
#define TRUE 1
#define FALSE 0


/*Info *infoMerge(){
    Info *infoMerge = (Info*)malloc(sizeof(Info));
    infoMerge->pior = "Teta(n log n)";      infoMerge->tipo = "Divis�o e conquista";
    infoMerge->estavel = "Sim";     infoMerge->in = "N�o";      infoMerge->otimo = "Sim";
}*/

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
    FILE *excel = fopen("vetor de entrada.csv", "r");
    if(excel == NULL)
    {
      printf("ERRO: Falha ao abrir arquivo csv\n");
      exit(1);
    }

    char buffer[8];
    //Contador da quantidade de numeros contidos no arquivo de texto
    *comprimento = 0;

    //Conta a quantidade de numeros no arquivo
    while(fgets(buffer, 8, excel) != NULL)
    {
      (*comprimento)++;
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
    printf("Digite qual a forma de ordena��o desejada:\n");
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
    printf("\nDeseja retornar ao menu pricipal?\n 1 - Sim\n0 - N�o\n");
    scanf("%d", controle);
    if(*controle  == 0){
        *isRunning = FALSE;
    }
    limparTela();
}

void informacoes(int valor){
    switch(valor){
        case 1:
            printf(" O metodo Quick sort � do tipo Divis�o e conquista\n O pior caso � O(n�)\n N�o � est�vel\n N�o � in-place\n E n�o � �timo\n");
            break;
        case 2:
            printf(" O metodo Merge sort � do tipo Divis�o e conquista\n O pior caso � Teta(n logo n)\n � est�vel\n N�o � in-place\n � �timo\n");
            break;
        case 3:
            printf(" O metodo Bubble sort � do tipo Flutua��o\n O pior caso � O(n�)\n � est�vel\n � in-place\n E n�o � �timo\n");
            break;
        case 4:
            printf(" O metodo Selection sort � do tipo Sele��o\n O pior caso � O(n�)\n N�o � est�vel\n � in-place\n E n�o � �timo\n");
            break;
        case 5:
            printf(" O metodo Shell sort � do tipo Ordena��o por inser��o\n O pior caso � O(n�)\n N�o � est�vel\n � in-place\n E n�o � �timo\n");
            break;
        case 6:
            printf(" O metodo Insertion sort � do tipo Ordena��o por inser��o\n O pior caso � O(n�)\n � est�vel\n � in-place\n E n�o � �timo\n");
            break;
    }
}

int *entradas(int qtd, const int tam){
  int s = qtd, i, *val, j=0;
  val = (int*)malloc(sizeof(int)*qtd);

  for(i=qtd; i>0; i--)
  {
    val[j]=i;
    /* PARA IMPRIMIR VETOR DE ENTRADAS DECRESCENTES
    if(s > tam){
      printf("[%d] ", val[j]);
      s--;
    }
    else
    {
      printf("\n[%d] ", val[j]);
      s = qtd-1;
    }*/
    j++;
  }
    printf("\n");
    return val;
    free(val);
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
