#define FUNCIONARIO_H

typedef struct funcionario Funcionario;

Funcionario *novoFuncionario(
	char *nome,
    char *cpf,
    char *data_admissao,
    char *data_nascimento,
    char *estado_civil,
    char *cargo,
    int salario
);
void visualizarFuncionario(struct funcionario *funcionario);