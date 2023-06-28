
// #ifndef lista_h
// #define lista_h
// #define MAX 30
#include "Funcionarios.h"

typedef struct node Node;
typedef struct lista Lista;

struct lista* inicializaLista();
struct node* criarNode(Funcionario *f);
int push(struct lista* l, struct node *n);
struct funcionario* buscarPorCPF(struct lista* l, char *cpf);
void lerString(char *string, int tamanho);
void listaFuncionarios(struct lista *l);
struct node *criarNode(struct funcionario *f);
void adicionaFuncionario(struct lista *l);