#include<stdio.h>
#include "controller.h"
#include "peca.h"
#include "relatorio.h"
#include "util.h"


void iniciarPrograma(){
    Peca pecas[MAX_PECAS];
    int numPecas = 0;
    char continuar = 's';

    do{ 
        if(numPecas >= MAX_PECAS) {
            printf("Limite de peças atingido.\n");
            break;
        }
        
        printf("========================================\n");
        printf("Cadastro de uma nova peça (%d):\n", numPecas + 1);
        Peca nova;

        nova.forma = lerForma();
        nova.material = lerMaterial();
        nova.loja = lerLoja();

        if(nova.forma == ESFERA){
            nova.raio = lerFloat("Raio: ");
        }else if(nova.forma == CILINDRO){
            nova.altura = lerFloat("Altura: ");
            nova.raio = lerFloat("Raio: ");
        }else{
            nova.altura = lerFloat("Altura: ");
            nova.largura = lerFloat("Largura: ");
            nova.profundidade = lerFloat("Profundidade: ");
        }

        nova.volume = calcularVolume(&nova);
        nova.area = calcularArea(&nova);
        nova.peso = calcularPeso(&nova);
        nova.tinta = calcularTinta(&nova);
        nova.custo = calcularCusto(&nova);

        pecas[numPecas++] = nova;

        printf("nDeseja inserir uma nova peça? (s | n): ");
        scanf(" %c", &continuar);
        

    } while(continuar == 's' || continuar == 'S');

    gerarRelatorio(pecas, numPecas);

}
