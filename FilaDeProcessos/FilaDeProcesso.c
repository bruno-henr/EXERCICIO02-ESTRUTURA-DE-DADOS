#include <stdio.h>
#include <stdlib.h>
#include "FilaDeProcessos.h"
#include "Processo.c"

struct fila {
	struct processo *inicio;
	struct processo *fim;
};

struct processo *insere_fim(struct processo *fim, int id) {
	// struct processo *f = (struct processo *)malloc(sizeof(struct processo));
	struct processo *f = criarProcesso();
	f->id = id;
	f->prox = NULL;

	if (fim != NULL)  // verifica se a lista n�o estava vazia
		fim->prox = f;
	return f;
}
// Cria Fila
Fila *criaFila() {
	Fila *f = (Fila *)malloc(sizeof(Fila));
	f->inicio = NULL;
	f->fim = NULL;
	return f;
}
// Só verifica se a fila está vazia
int vazio(Fila *f) {
	if (f->inicio == NULL)
		return 1;
	return 0;
}
// insere um novo processo na pilha
void insereProcesso(Fila *f, int id) {
	f->fim = insere_fim(f->fim, id); /* Chama a fun��o que insere no fim */

	if (f->inicio == NULL) /* fila antes vazia? */
		f->inicio = f->fim;

	printf("Processo adicionado com sucesso.\n");
}
//Remove o primeiro processo da fila
void retiraProcesso(Fila *f) {
	if (vazio(f) == 1) {
		printf("Fila vazia, n�o h� processos ativos no momento.\n");
	} else {
		struct processo *p = f->inicio;
		f->inicio = p->prox;
		free(p);
		if (f->inicio == NULL)  // Fila ficou vazia?
			f->fim = NULL;
	}
	printf("Processo retirado com sucesso.\n");
}
// Imprime todos os processos da fila
void imprimirProcessos(Fila *f) {
	if (f->inicio == NULL)
		printf("Fila vazia!\n");
	else {
		int total = 0;
		struct processo *aux = f->inicio;
		while (aux != NULL) {
			// printf("Processo ID#%d -> ", aux->id);
			imprimirId(aux);
			aux = aux->prox;
			total++;
		}
		printf("\n%d processos no total\n\n", total);
	}
}
// Limpa a fila
void liberar(Fila *f) {
	struct processo *p = f->inicio;
	while (p != NULL) {
		struct processo *t = p->prox;
		free(p);
		p = t;
	}
	free(f);
}

