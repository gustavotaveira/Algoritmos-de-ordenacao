#include "utils.h"

#define TRUE 1
#define FALSE 0

void menu(){
    printf("Algoritmos de ordenação\n\n");
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

void inicio(int* controle, int* isRunning){
    printf("Deseja retornar ao menu pricipal?\n1 - Sim\n0 - Não\n");
    scanf("%d", controle);
    if(*controle  == 0){
        *isRunning = FALSE;
    }
    limparTela();
}
