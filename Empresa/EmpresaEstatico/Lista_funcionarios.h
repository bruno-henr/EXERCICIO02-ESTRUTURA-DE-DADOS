// #include "Funcionarios.h"

#ifndef LISTA_FUNCIONARIOS_H
#define LISTA_FUNCIONARIOS_H

#define MAX 30

typedef struct empresa Empresa;
/// @brief 
typedef struct funcionario Funcionario;

void inicializaLista(Empresa *e);
void editarEmpresa(Empresa *e);
/// @brief 
/// @param e 
void imprimirEmpresa(Empresa *e);
void imprimeFuncionario(struct funcionario funcionario);
void imprimeLista(Empresa *lista);
void adicionaFuncionario(Empresa *l);
int buscarPorCPF(Empresa *l, char *cpf);
int removerFuncionario(Empresa *lista, char* cpf);
void limpaLista(Empresa *l);
void deletar_empresa();

#endif // LISTA_FUNCIONARIOS_H
