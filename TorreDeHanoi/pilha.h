#ifndef PILHA_H
#define PILHA_H

#include "disco.h"

typedef struct {
    int capacidade;
    int topo;
    Disco* array;
} Pilha;

Pilha* criarPilha(int capacidade);
int estaVazia(Pilha* pilha);
int estaCheia(Pilha* pilha);
void empilhar(Pilha* pilha, Disco disco);
Disco desempilhar(Pilha* pilha);

#endif


