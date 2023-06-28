#include "lista.h"
#include "Funcionarios.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	struct node *prox;
	struct node *anterior;
	Funcionario *funcionario;
};

struct lista
{
	struct node *topo;
};

struct lista *inicializaLista()
{
	struct lista *ll = (struct lista *)malloc(sizeof(struct lista));
	ll->topo = NULL;
	return ll;
}

void listaFuncionarios(struct lista *l) {
	if (l->topo == NULL) {
		printf("Não há funcionários cadastrados.\n");
	} else {
		struct node *aux = l->topo;
		int count = 1;
		while (aux->prox != NULL)
		{
			// printf("\nNome funcionario: %s\n", aux->funcionario->nome);
			printf("===== Funcionario Nº %d =====\n", count);
			visualizarFuncionario(aux->funcionario);
			aux = aux->prox;
			count++;
		}
		printf("===== Funcionario Nº %d =====\n", count);
		visualizarFuncionario(aux->funcionario);
	}
}

int push(struct lista *l, struct node *n)
{
	if (l->topo == NULL)
	{
		l->topo = n;
		return 1;
	}

	struct node *aux = l->topo;

	while (aux->prox != NULL)
	{
		aux = aux->prox;
	}
	n->anterior = aux;
	aux->prox = n;
	return 1;
}

void lerString(char *string, int tamanho)
{
	fgets(string, tamanho, stdin);
	size_t length = strlen(string);
	if (string[length - 1] == '\n')
	{
		string[length - 1] = '\0'; // Remove o caractere de nova linha
	}
}

struct node *criarNode(struct funcionario *f)
{
	struct node *node = (struct node *)malloc(sizeof(struct node));
	node->anterior = NULL;
	node->prox = NULL;
	node->funcionario = f;
}

void adicionaFuncionario(struct lista *l)
{
	char nome[31];
	char cpf[12];
	char data_admissao[12];
	char data_nascimento[12];
	char estado_civil[31];
	char cargo[31];
	int salario;

	printf("Informe o primeiro nome do funcionario:\n-> ");
	setbuf(stdin, nome);
	lerString(nome, sizeof(nome));

	printf("Informe a data de admissao (DD/MM/YYYY):\n-> ");
	setbuf(stdin, NULL);
	scanf("%11s", data_admissao);

	printf("Informe a data de nascimento (DD/MM/YYYY):\n-> ");
	setbuf(stdin, NULL);
	scanf("%11s", data_nascimento);

	printf("Informe o CPF (somente números):\n-> ");
	setbuf(stdin, cpf);
	scanf("%s", cpf);

	printf("Informe o estado civil:\n-> ");
	setbuf(stdin, NULL);
	scanf("%s", estado_civil);
	fflush(stdin);

	printf("Informe o cargo:\n-> ");
	setbuf(stdin, NULL);
	scanf("%30s", cargo);

	printf("Informe o salário:\n-> ");
	scanf("%d", &salario);

	Funcionario *f = novoFuncionario(
		nome,
		cpf,
		data_admissao,
		data_nascimento,
		estado_civil,
		cargo,
		salario);

	Node *node = criarNode(f);

	int resultado = push(l, node);
	if (resultado == 1)
	{
		printf("Funcionário salvo com sucesso!\n");
	}
	else
	{
		printf("Deu merda.\n");
	}
}

int pop(struct lista *l, char *cpf) {
	if (l->topo == NULL) {
		printf("Não há funcionários cadastrados.\n");
		return -1;
	}

	struct node *aux = l->topo;

	while (aux != NULL) {
		if (strcmp(aux->funcionario->cpf, cpf) == 0) {
			if (aux->anterior == NULL) { // Nó encontrado é o primeiro da lista
				l->topo = aux->prox;
			} else { // Nó encontrado está no meio da lista
				aux->anterior->prox = aux->prox;
			}
			if (aux->prox != NULL) { // Nó encontrado não é o último da lista
				aux->prox->anterior = aux->anterior;
			}
			free(aux);
			return 1;
		}
		aux = aux->prox;
	}

	printf("Funcionário com CPF %s não encontrado.\n", cpf);
	return -1;
}


struct funcionario *buscarPorCPF(struct lista *l, char *cpf)
{
	if (l->topo == NULL)
	{
		printf("Não há funcionários cadastrados.\n");
		return -1;
	}
	struct node *aux = l->topo;

	while (aux->prox != NULL)
	{
		if (strcmp(aux->funcionario->cpf, cpf) == 0)
		{
			return aux->funcionario;
		}
	}
	if (strcmp(aux->funcionario->cpf, cpf) == 0)
	{
		return aux->funcionario;
	}
	return NULL;
}
