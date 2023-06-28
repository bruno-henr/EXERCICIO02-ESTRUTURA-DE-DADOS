#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista_funcionarios.h"
#include "Funcionarios.c"
#define CPF_LENGTH 12

struct empresa
{
	Funcionario lista_funcionarios[MAX];
	int qtde;
	char nome[MAX];
};

void inicializaLista(struct empresa *e)
{
	char nome[30];
	printf("Informe o nome da empresa?\n-> ");
	fgets(nome, sizeof(nome), stdin);

	strncpy(e->nome, nome, sizeof(e->nome) - 1);
	e->nome[sizeof(e->nome) - 1] = '\0';

	e->qtde = 0;
}

void editarEmpresa(Empresa *e)
{
	char nome[30];
	printf("Informe o novo nome da empresa:\n-> ");
	fgets(nome, sizeof(nome), stdin);
	getchar();
	strncpy(e->nome, nome, sizeof(e->nome) - 1);
	e->nome[sizeof(e->nome) - 1] = '\0';

	printf("Nome editado com sucesso!");
}

void imprimeFuncionario(struct funcionario funcionario)
{
	printFuncionario(funcionario);
}

void imprimeLista(struct empresa *lista)
{
	if (lista->qtde == 0)
	{
		printf("Lista vazia.");
	}
	int i;
	for (i = 0; i < lista->qtde; i++)
	{
		printf("\n==== Funcionario Nº %d =========\n", i + 1);
		imprimeFuncionario(lista->lista_funcionarios[i]);
	}
}

void imprimirEmpresa(struct empresa *e)
{
	if (strcmp(e->nome, "") == 0)
	{
		printf("\n* A empresa inexistente.\n");
	}
	else
	{
		printf("====================\n");
		printf("Empresa: %s\n", e->nome);
		printf("====================\n");

		if (e->qtde > 0)
		{
			printf("\nLista de funcionarios:\n");
			imprimeLista(e);
		}
		else
		{
			printf("\n* - Lista de funcionarios vazia no momento.\n");
		}
	}
}

void lerString(char *stringLida, int size)
{
	fgets(stringLida, size, stdin);
	stringLida[strlen(stringLida) - 1] = '\0';
}

void readString(char *buffer, int bufferSize)
{
	fgets(buffer, bufferSize, stdin);
	int length = strlen(buffer);
	if (buffer[length - 1] == '\n')
	{
		buffer[length - 1] = '\0'; // Remove o caractere de nova linha (\n)
	}
}

void lerString2(char *string, int tamanho)
{
	fgets(string, tamanho, stdin);
	size_t length = strlen(string);
	if (string[length - 1] == '\n')
	{
		string[length - 1] = '\0'; // Remove o caractere de nova linha
	}
}

void adicionaFuncionario(struct empresa *l)
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
	lerString2(nome, sizeof(nome));

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

	Funcionario *f = criarFuncionario(
		nome,
		cpf,
		data_admissao,
		data_nascimento,
		estado_civil,
		cargo,
		salario);

	l->lista_funcionarios[l->qtde] = *f;
	l->qtde++;

	printf("Funcionário salvo com sucesso!\n");
}

int buscarPorCPF(Empresa *l, char *cpf)
{
	if (l->qtde == 0)
	{
		printf("Não há funcionários cadastrados.\n");
		return -1;
	}

	int i;
	for (i = 0; i < l->qtde; i++)
	{
		if (strcmp(l->lista_funcionarios[i].cpf, cpf) == 0)
		{
			return i;
		}
	}
	return -1;
}

int removerFuncionario(Empresa *l, char *cpf)
{
	if (l->qtde == 0)
	{
		printf("Não há funcionários para remover. Lista vazia.");
		return -1;
	}
	int indice_funcionario = buscarPorCPF(l, cpf);
	int i;
	for (i = indice_funcionario; i < l->qtde; i++)
	{
		l->lista_funcionarios[i] = l->lista_funcionarios[i + 1];
	}
	l->qtde--;
	system("cls");
	printf("Funcionário removido com sucesso.");
	return 0;
}

void limpaLista(struct empresa *l)
{
	int i;
	// for (i = 0; i < l->qtde; i++)
	// {
	// 	l->lista_funcionarios[i].nome = [];
	// 	l->lista_funcionarios[i].cargo = NULL;
	// 	l->lista_funcionarios[i].cpf = NULL;
	// 	l->lista_funcionarios[i].data_admissao = NULL;
	// 	l->lista_funcionarios[i].data_nascimento = NULL;
	// 	l->lista_funcionarios[i].estado_civil = NULL;
	// 	l->lista_funcionarios[i].salario = 0;
	// }
	l->qtde = 0;
	system("cls");
	printf("Lista de funcionarios zerada.\n");
}

void deletar_empresa(Empresa *e)
{
	// memset(e->nome, 0, sizeof(e->nome));
	strncpy(e->nome, "", sizeof(e->nome) - 1);
	limpaLista(e);
}

// void imprime_empresa(Empresa *e) {

// 	printf("===================\n");
// 	printf("=== EMPRESA: %s ===\n", e->nome);
// 	printf("===================\n");

// 	for(int i = 0; i <= e->qtde; i++) {
// 		imprimeFuncionario(e->lista_funcionarios[i]);
// 	}
// }
