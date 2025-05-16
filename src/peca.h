#ifndef PECA_H
#define PECA_H

#define MAX_PECAS 100


typedef enum { ACO, ALUMINIO, BRONZE } Material;
typedef enum { ESFERA, CILINDRO, PARALELEPIPEDO } TipoForma;
typedef enum { ZE, JOAO, PAULO, CHICO, MANE, ALFA, BETA} Loja;


/* Estrutura que representa uma peça com suas propriedades físicas e comerciais */
typedef struct {
    TipoForma forma;
    Loja loja;
    Material material;
    float altura, largura, raio, profundidade ;
    float area, volume, peso, custo, tinta;
} Peca;


float calcularArea(Peca *peca);
float calcularVolume(Peca *peca);
float calcularPeso(Peca *peca);
float calcularCusto(Peca *peca);
float calcularTinta(Peca *peca);



#endif