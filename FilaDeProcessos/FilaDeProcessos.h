

// #include "Processo.h"

typedef struct fila Fila;

Fila *criaFila();
int vazio(Fila *f);
void insereProcesso(Fila *f, int id);
void retiraProcesso(Fila *f);
void imprimirProcessos(Fila *f);
void liberar(Fila *f);


