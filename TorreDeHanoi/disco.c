#include <stdio.h>
#include <stdlib.h>
#include "disco.h"

Disco criarDisco(int diametro) {
    Disco disco;
    disco.diametro = diametro;
    return disco;
}

Disco* criarArrayDiscos(int capacidade) {
    Disco* arrayDiscos = (Disco*)malloc(capacidade * sizeof(Disco));
    return arrayDiscos;
}