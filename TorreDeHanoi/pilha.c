#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "disco.c"

Pilha* criarPilha(int capacidade) {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->capacidade = capacidade;
    pilha->topo = -1;
    // pilha->array = (Disco*)malloc(capacidade * sizeof(Disco));
    pilha->array = criarArrayDiscos(capacidade);
    return pilha;
}

int estaVazia(Pilha* pilha) {
    return pilha->topo == -1;
}

int estaCheia(Pilha* pilha) {
    return pilha->topo == pilha->capacidade - 1;
}

void empilhar(Pilha* pilha, Disco disco) {
    if (estaCheia(pilha)) {
        printf("Erro: Pilha cheia.\n");
        return;
    }
    pilha->array[++pilha->topo] = disco;
}

Disco desempilhar(Pilha* pilha) {
    Disco discoVazio = {0};

    if (estaVazia(pilha)) {
        printf("Erro: Pilha vazia.\n");
        return discoVazio;
    }
    return pilha->array[pilha->topo--];
}


