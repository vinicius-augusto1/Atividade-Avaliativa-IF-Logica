#ifndef UTIL_H
#define UTIL_H

#include "peca.h"

const char* nomeMaterial(Material material);
const char* nomeForma(TipoForma forma);
const char* nomeLoja(Loja loja);

Material lerMaterial();
TipoForma lerForma();
Loja lerLoja();

float lerFloat(const char* mensagem);
int lerInt(const char *msg);



#endif