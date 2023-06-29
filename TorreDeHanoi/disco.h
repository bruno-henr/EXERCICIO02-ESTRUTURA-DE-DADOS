#ifndef DISCO_H
#define DISCO_H

typedef struct {
    int diametro;
} Disco;

Disco criarDisco(int diametro);
Disco* criarArrayDiscos(int capacidade);

#endif


