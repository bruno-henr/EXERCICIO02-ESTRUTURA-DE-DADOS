#include <stdio.h>
#include "pilha.h"
#include "torre_hanoi.h"

void imprimirTorre(Pilha* origem, Pilha* destino, Pilha* auxiliar) {
	// Mostra o estado das hastes
        printf("Origem: ");
        int i;
        for (i = 0; i <= origem->topo; i++)
            printf("%d ", origem->array[i]);
        printf("\n");

        printf("Auxiliar: ");
        for (i = 0; i <= auxiliar->topo; i++)
            printf("%d ", auxiliar->array[i]);
        printf("\n");

        printf("Destino: ");
        for (i = 0; i <= destino->topo; i++)
            printf("%d ", destino->array[i]);
        printf("\n\n");
}

// Fun??o auxiliar para resolver a Torre de Hanoi
void torreDeHanoiUtil(int numDiscos, Pilha* origem, Pilha* destino, Pilha* auxiliar) {
    if (numDiscos == 1) {
        Disco disco = desempilhar(origem);
        empilhar(destino, disco);

        imprimirTorre(origem, destino, auxiliar);
    } else {
        torreDeHanoiUtil(numDiscos - 1, origem, auxiliar, destino);

        Disco disco = desempilhar(origem);
        empilhar(destino, disco);

        imprimirTorre(origem, destino, auxiliar);

        torreDeHanoiUtil(numDiscos - 1, auxiliar, destino, origem);
    }
}

// Fun??o principal para resolver a Torre de Hanoi
void torreDeHanoi(int numDiscos) {
    Pilha* origem = criarPilha(numDiscos);
    Pilha* destino = criarPilha(numDiscos);
    Pilha* auxiliar = criarPilha(numDiscos);
	int i;
    // Preenche a haste de origem
    for (i = numDiscos; i > 0; i--) {
        Disco disco;
        disco.diametro = i;
        empilhar(origem, disco);
    }

    printf("Estado inicial:\n");
    imprimirTorre(origem, destino, auxiliar);

    // Chama a fun??o auxiliar para resolver a Torre de Hanoi
    torreDeHanoiUtil(numDiscos, origem, destino, auxiliar);

    // Libera a mem?ria alocada pelas pilhas
    free(origem->array);
    free(origem);
    free(destino->array);
    free(destino);
    free(auxiliar->array);
    free(auxiliar);
}


