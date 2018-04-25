#ifndef UTILS_H
#define UTILS_H

#include<stdio.h>
#include<stdlib.h>

void imprimeVetor(int *arrayExcel, int comprimento, const int tamanhoLinha);
void menu();
void inserirEntrada();
void limparTela();
void inicio(int *controle, int* isRunning);
void informacoes(int valor);
void popular(int* array, int tam);
int* gerarArrayExcel(comprimento);
int size(int* array);


#endif /* UTILS_H */
