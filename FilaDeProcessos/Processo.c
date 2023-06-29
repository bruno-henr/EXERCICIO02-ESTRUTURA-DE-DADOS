#include <stdio.h>
#include <stdlib.h>
#include "Processo.h"


struct processo* criarProcesso() {
	struct processo *f = (struct processo *)malloc(sizeof(struct processo));
	return f;
}

/// @brief 
/// @param  
void imprimirId(struct processo* p) {
    // printf("%d", p->id);
    printf("Processo ID#%d -> ", p->id);
}