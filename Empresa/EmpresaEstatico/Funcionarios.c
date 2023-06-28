#include "Funcionarios.h"
#include "Lista_funcionarios.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct funcionario
{
    char nome[30];
    char cpf[12];
    char estado_civil[30];
    char cargo[30];
    char data_nascimento[12];
    char data_admissao[12];
    int salario;
};

struct funcionario *criarFuncionario(
    char nome[30],
    char cpf[12],
    char data_admissao[12],
    char data_nascimento[12],
    char estado_civil[30],
    char cargo[30],
    int salario)
{
    struct funcionario *f = (struct funcionario *)malloc(sizeof(struct funcionario));
    
    strncpy(f->nome, nome, sizeof(f->nome) - 1);
    
    strncpy(f->cpf, cpf, sizeof(f->cpf) - 1);

    strncpy(f->data_admissao, data_admissao, sizeof(f->data_admissao) - 1);

    strncpy(f->data_nascimento, data_nascimento, sizeof(f->data_nascimento) - 1);

    strncpy(f->estado_civil, estado_civil, sizeof(f->estado_civil) - 1);

    strncpy(f->cargo, cargo, sizeof(f->cargo) - 1);

    f->salario = salario;
    return f;
}
void printFuncionario(struct funcionario funcionario)
{
    printf("NOME: %s\n", funcionario.nome);
    printf("CPF: %.11s\n", funcionario.cpf);
    printf("ESTADO CIVIL: %s\n", funcionario.estado_civil);
    printf("CARGO: %s\n", funcionario.cargo);
    printf("DATA DE NASCIMENTO: %s\n", funcionario.data_nascimento);
    printf("DATA DE ADMISSÃO: %s\n", funcionario.data_admissao);
    printf("SALÁRIO: %d\n", funcionario.salario);
}
