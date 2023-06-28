#include <stdio.h>
#include "torre_hanoi.h"

int main() {
    int numDiscos;
    int escolha;
    printf("Torre de hanoi:\n1- Dinamico\n2- Estatica\nEscolha: ");
    scanf("%d", &escolha);
    
    if(escolha == 1) {
    	printf("Digite o numero de discos: ");
    	scanf("%d", &numDiscos);

	    printf("\nResolvendo a Torre de Hanoi para %d discos:\n\n", numDiscos);
	    torreDeHanoi(numDiscos);
	} else if (escolha == 2) {
		printf("\nResolvendo a Torre de Hanoi para %d discos:\n\n", 3);
	    torreDeHanoi(3);
	} else {
		printf("Escolha invalida.");
	}

    

    return 0;
}


