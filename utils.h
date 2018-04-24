#ifndef UTILS_H
#define UTILS_H

#include<stdio.h>
#include<stdlib.h>

/*typedef struct _Infomacoes
{
  char *tipo, *pior;
  char *otimo, *estavel, *in;
}Info;

Info *infoMerge();*/

void imprimeVetor(int *arrayExcel, int comprimento, const int tamanhoLinha);
void menu();
void inserirEntrada();
void limparTela();
void inicio(int *controle, int* isRunning);
void informacoes(int valor);
int *entradas(int qtd, const int tam);


#endif /* UTILS_H */
