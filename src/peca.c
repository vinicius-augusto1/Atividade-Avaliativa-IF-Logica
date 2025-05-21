#include <math.h>
#include "peca.h"
#define PI 3.14159265358979323846


float calcularVolume(Peca *peca) {
    switch (peca->forma) {
        case ESFERA:
            return (4.0 / 3.0) * PI * pow(peca->raio, 3);
        case CILINDRO:
            return PI * pow(peca->raio, 2) * peca->altura;
        case PARALELEPIPEDO:
            return peca->altura * peca->largura * peca->profundidade;
        default:
            return 0.0f;
    }
}


float calcularArea(Peca *peca){
    switch(peca -> forma){
        case ESFERA:
            return 4 * PI * pow(peca -> raio, 2);
            break;
        case CILINDRO:
            return 2 * PI * peca -> raio * (peca -> altura + peca -> raio);
            break;
        case PARALELEPIPEDO:
            return 2 * (peca -> altura * peca -> largura + peca -> altura * peca -> profundidade + peca -> largura * peca -> profundidade);
            break;
        default:
            return 0.0f;
    }
}


float calcularPeso(Peca *peca){
    float volume = calcularVolume(peca);
    switch(peca->material){
        case ACO:
            return (7.8f * volume) / 1000.0f;
        case ALUMINIO:
            return (2.6f * volume) / 1000.0f;
        case BRONZE:
            return (8.8f * volume) / 1000.0f;
        default:
            return 0.0f;
    }
}

float calcularTinta(Peca *peca){
    switch(peca -> material){
        case ACO:
            return 0.02f * calcularArea(peca);
            break;
        case ALUMINIO:
            return 0.01f * calcularArea(peca);
            break;
        case BRONZE:
            return 0.015f * calcularArea(peca);
            break;
        default:
            return 0.0f;
    }
}


/* Calcula o preço total da peça com base na loja, material e peso.
Usa uma matriz de preços fixos por loja e tipo de material. */

float calcularCusto(Peca *peca){
    float preco = 0.0f;

    float precos[7][3] = {
        {100, 80, 130}, // casa zé
        {150, 90, 115}, // casa joão
        {110, 75, 120}, // casa paulo
        {110, 100, 160}, // casa chico
        {110, 50, 160}, // casa mane
        {90, 50, 110}, // casa alfa
        {140, 100, 180}  // casa beta
    };

    preco = precos[peca->loja][peca->material];
    return preco * peca->peso;

}

