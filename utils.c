#include "utils.h"


void menu(){
    printf("Algoritmos de ordena��o\n\n");
    printf("1 - Insertion Sort\n");
    printf("2 - Bubble Sort\n");
    printf("3 - Selection Sort\n");
    printf("4 - Shell Sort\n");
    printf("5 - Quick Sort\n");
    printf("6 - Merge Sort\n");
    printf("0 - Sair\n");
}

void limparTela(){
    system("cls");
}

void inicio(int* controle, Bool* isRunning){
    printf("Deseja retornar ao menu pricipal?\n 1 - Sim\n0 - N�o\n");
    scanf("%d", controle);
    if(*controle  == 0){
        *isRunning = FALSE;
    }
    limparTela();
}
