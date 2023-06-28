// #include "Lista_funcionarios.h"

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

typedef struct funcionario Funcionario;

struct funcionario *criarFuncionario(
	char *nome,
    char *cpf,
    char *data_admissao,
    char *data_nascimento,
    char *estado_civil,
    char *cargo,
    int salario
);
void printFuncionario(struct funcionario funcionario);

#endif  // FUNCIONARIO_H
