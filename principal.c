#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
//#include "utils.h"
//#include "algoritmos.h"

int main(void){

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
    int s = 0;
    int LINHA = 20;
    for(int i = 0; i < comprimento; i++)
    {
      if(s < LINHA)
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


    return 0;
}
