#include <stdio.h>
#include "relatorio.h"
#include "util.h"

void gerarRelatorio(Peca pecas[], int numPecas){

    float pesoTotal = 0.0f, volumeTotal = 0.0f, custoTotal = 0.0f, tintaTotal = 0.0f;
    float pesoEsferas[3] = {0.0f, 0.0f, 0.0f}; // inicializa tudo com zero
    float quantidadeEsferas[3] = {0.0f, 0.0f, 0.0f};
    float custoPorLoja[7] = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};


    for(int i = 0; i < numPecas; i++){
        pesoTotal += pecas[i].peso;
        volumeTotal += pecas[i].volume;
        tintaTotal += pecas[i].tinta;
        custoTotal += pecas[i].custo;
        custoPorLoja[pecas[i].loja] += pecas[i].custo;

        if(pecas[i].forma == ESFERA){
            pesoEsferas[pecas[i].material] += pecas[i].peso;
            quantidadeEsferas[pecas[i].material] += 1.0f;
        }
    }



    printf("=========================\n");
    printf("Relatório de Peças\n");
    printf("=========================\n");

    printf("\n1 - Peso total da estátuata %.2f kg", pesoTotal);

    for(int i=0; i < 3; i++){
        if(quantidadeEsferas[i] > 0.0f){
            printf("\n8  - Peso médio das esferas de %d: %.2f kg", i, pesoEsferas[i] / quantidadeEsferas[i]);

        }
    }

    printf("\n10 - Valor total gasto: R$ %.2f", custoTotal);


    int lojaMaisCara = 0;

    for(int i = 1; i < 7; i++){
        if(custoPorLoja[i] > custoPorLoja[lojaMaisCara]){
            lojaMaisCara = i;
        }
    }

    printf("\n11 - Loja que mais faturou: %s com R$ %.2f\n", nomeLoja(lojaMaisCara), custoPorLoja[lojaMaisCara]);







}