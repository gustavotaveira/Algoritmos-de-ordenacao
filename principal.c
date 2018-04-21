#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include "utils.h"
#define TRUE 1
#define FALSE 0


int main(void){

    setlocale(LC_ALL, "portuguese");

    int controle = -1;

    while(controle != FALSE){

        menu();
        scanf("%d", &controle);

        switch(controle){
            case 1: limparTela();
                    printf("Insertion sort\n\n");
                    inicio(&controle);
            break;
        }
    }
    return 0;
}


