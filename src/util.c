#include <stdio.h>
#include "util.h"

const char* nomeMaterial(Material material) {
    switch (material) {
        case ACO: return "Aço";
        case ALUMINIO: return "Alumínio";
        case BRONZE: return "Bronze";
        default: return "Desconhecido";
    }
}

const char* nomeForma(TipoForma forma) {
    switch (forma) {
        case ESFERA: return "Esfera";
        case CILINDRO: return "Cilindro";
        case PARALELEPIPEDO: return "Paralelepípedo";
        default: return "Desconhecido";
    }
}

const char* nomeLoja(Loja loja) {
    switch (loja) {
        case ZE: return "Zé";
        case JOAO: return "João";
        case PAULO: return "Paulo";
        case CHICO: return "Chico";
        case MANE: return "Mané";
        case ALFA: return "Alfa";
        case BETA: return "Beta";
        default: return "Desconhecido";
    }
}


Material lerMaterial() {
    int opcao;
    do {
        printf("========================================\n");
        opcao = lerInt("Selecão de Materiais:\n0-Aço\n1-Alumínio\n2-Bronze\nEscolha uma opção:");
        if(opcao < 0 || opcao > 2) {
            printf("\nOpção inválida. Tente novamente.\n");
        }
    } while (opcao < 0 || opcao > 2);
    return (Material)opcao;

}

Loja lerLoja() {
    int opcao;
    do {
        printf("========================================\n");
        opcao = lerInt("Selecão de Lojas:\n0-Zé\n1-João\n2-Paulo\n3-Chico\n4-Mané\n5-Alfa\n6-Beta\nEscolha uma opção:");
        if(opcao < 0 || opcao > 6) {
            printf("\nOpção inválida. Tente novamente.\n");
        }
    } while (opcao < 0 || opcao > 6);
    return (Loja)opcao;

}

TipoForma lerForma(){
    int opcao;
    do {
        printf("========================================\n");
        opcao = lerInt("Seleção de Formas:\n0-Esfera\n1-Cilindro\n2-Paralelepípedo\nEscolha uma opção:");
        if(opcao < 0 || opcao > 2) {
            printf("\nOpção inválida. Tente novamente.\n");
        }
    } while (opcao < 0 || opcao > 2);

    return (TipoForma)opcao;
}


float lerFloat(const char* mensagem) {
    float valor;
 
    printf("%s", mensagem);
    scanf("%f", &valor);
 
    return valor;
}

int lerInt(const char *msg) {
    int valor;
    char c;

    while (1) {
        printf("%s", msg);
        if (scanf("%d", &valor) == 1) {
            // Limpa qualquer lixo após o número
            while ((c = getchar()) != '\n' && c != EOF);
            return valor;
        } else {
            printf("Entrada inválida. Digite um número inteiro.\n");
            // Limpa o buffer de entrada
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }
}