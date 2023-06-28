#include <stdio.h>
#include <stdlib.h>
#include "FilaDeProcessos.h"

struct fila {
	Processo *inicio;
	Processo *fim;
};

struct processo *insere_fim(struct processo *fim, int id) {
	struct processo *f = (struct processo *)malloc(sizeof(struct processo));
	f->id = id;
	f->prox = NULL;

	if (fim != NULL)  // verifica se a lista não estava vazia
		fim->prox = f;
	return f;
}

Fila *criaFila() {
	Fila *f = (Fila *)malloc(sizeof(Fila));
	f->inicio = NULL;
	f->fim = NULL;
	return f;
}

int vazio(Fila *f) {
	if (f->inicio == NULL)
		return 1;
	return 0;
}

void insereProcesso(Fila *f, int id) {
	f->fim = insere_fim(f->fim, id); /* Chama a função que insere no fim */

	if (f->inicio == NULL) /* fila antes vazia? */
		f->inicio = f->fim;

	printf("Processo adicionado com sucesso.\n");
}

void retiraProcesso(Fila *f) {
	if (vazio(f) == 1) {
		printf("Fila vazia, não há processos ativos no momento.\n");
	} else {
		struct processo *p = f->inicio;
		f->inicio = p->prox;
		free(p);
		if (f->inicio == NULL)  // Fila ficou vazia?
			f->fim = NULL;
	}
	printf("Processo retirado com sucesso.\n");
}

void imprimirProcessos(Fila *f) {
	if (f->inicio == NULL)
		printf("Fila vazia!\n");
	else {
		int total = 0;
		struct processo *aux = f->inicio;
		while (aux != NULL) {
			printf("Processo ID#%d -> ", aux->id);
			aux = aux->prox;
			total++;
		}
		printf("\n%d processos no total\n\n", total);
	}
}

void liberar(Fila *f) {
	struct processo *p = f->inicio;
	while (p != NULL) {
		struct processo *t = p->prox;
		free(p);
		p = t;
	}
	free(f);
}

