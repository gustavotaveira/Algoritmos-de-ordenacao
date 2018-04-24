#include "utils.h"
#define TRUE 1
#define FALSE 0


/*Info *infoMerge(){
    Info *infoMerge = (Info*)malloc(sizeof(Info));
    infoMerge->pior = "Teta(n log n)";      infoMerge->tipo = "Divisão e conquista";
    infoMerge->estavel = "Sim";     infoMerge->in = "Não";      infoMerge->otimo = "Sim";
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

int inserirEntrada(){
    int valor;
    do{
        printf("Digite qual a entrada desejada:\n");
        printf("\t1- Vetor decrescente de 500\n");
        printf("\t2- Vetor decrescente de 1000\n");
        printf("\t3- Vetor decrescente de 10000\n");
        printf("\t4- Vetor decrescente de 50000\n");
        printf("\t5- Entrada do exel\n");
        printf("\t0 - Sair\n");
        scanf("%d", &valor);
        switch(valor){
            case 1:
                return 500;
                break;
             case 2:
                return 1000;
                break;
             case 3:
                return 10000;
                break;
             case 4:
                return 50000;
                break;
             case 5:
                return 5;
                break;
             case 0:
                exit(0);
                break;
             default:
                valor = -1;
                break;
        }
    }while(valor<0 || valor>5);
}

void limparTela(){
    system("cls");
}

void inicio(int* valor, int* isRunning){
    printf("\nDeseja retornar ao menu pricipal?\n 1 - Sim\n0 - Não\n");
    scanf("%d", valor);
    if(*valor  == 0){
        *isRunning = FALSE;
    }
    limparTela();
}

void informacoes(int valor){
    switch(valor){
        case 1:
            printf(" O metodo Quick sort é do tipo Divisão e conquista\n O pior caso é O(n²)\n Não é estável\n Não é in-place\n E não é ótimo\n");
            break;
        case 2:
            printf(" O metodo Merge sort é do tipo Divisão e conquista\n O pior caso é Teta(n logo n)\n É estável\n Não é in-place\n É ótimo\n");
            break;
        case 3:
            printf(" O metodo Bubble sort é do tipo Flutuação\n O pior caso é O(n²)\n É estável\n É in-place\n E não é ótimo\n");
            break;
        case 4:
            printf(" O metodo Selection sort é do tipo Seleção\n O pior caso é O(n²)\n Não é estável\n É in-place\n E não é ótimo\n");
            break;
        case 5:
            printf(" O metodo Shell sort é do tipo Ordenação por inserção\n O pior caso é O(n²)\n Não é estável\n É in-place\n E não é ótimo\n");
            break;
        case 6:
            printf(" O metodo Insertion sort é do tipo Ordenação por inserção\n O pior caso é O(n²)\n É estável\n É in-place\n E não é ótimo\n");
            break;
    }
}

int entradas(int qtd, const int tam){
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


