#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include "utils.h"
#include "algoritmos.h"

int main(void){

    setlocale(LC_ALL, "portuguese");

    int controle = -1;
    Bool isRunning = TRUE;
    while(isRunning == TRUE){

        menu();
        scanf("%d", &controle);
        limparTela();
        switch(controle){

            case 1: printf("Insertion sort\n\n");
            break;

            case 2: printf("Bubble sort\n\n");
            break;

            case 3: printf("Selection sort\n\n");
                    int n;
                    printf("Insira a quantidade de elementos a ordenar: ");
                    scanf("%d", &n);
                    printf("Iniciando a ordenacao de %d elementos\n", n);
                    selectionSort(n);
            break;

            case 4: printf("Shell sort\n\n");
            break;

            case 5: printf("Quick sort\n\n");
            break;

            case 6: printf("Merge sort\n\n");
            break;
        }
        inicio(&controle, &isRunning);
    }
    return 0;
}
