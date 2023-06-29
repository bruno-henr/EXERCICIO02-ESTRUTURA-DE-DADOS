#include <stdio.h>
#include <stdlib.h>
#include "FilaDeProcesso.c"

int main() {
	int escolha;
	Fila *fila = NULL;

	do {
		printf("========== MENU ==========\n");
		printf("1 - Fila de processos dinamica\n");
		printf("2 - Fila de processos estatica\n");
		printf("0 - Sair\n");
		printf("==========================\n");
		printf("Escolha uma opção: ");
		scanf("%d", &escolha);

		switch (escolha) {
			case 1: {
				int opcao;

				if (fila == NULL) {
					fila = criaFila();
					printf("Fila de processos dinamica criada.\n");
				}

				do {
					printf("=========== MENU FILA DE PROCESSOS DINAMICA ===========\n");
					printf("1 - Inserir processo\n");
					printf("2 - Imprimir processos\n");
					printf("3 - Retirar processo\n");
					printf("4 - Liberar fila\n");
					printf("0 - Voltar\n");
					printf("======================================================\n");
					printf("Escolha uma opçao: ");
					scanf("%d", &opcao);

					switch (opcao) {
						case 1: {
							int id;
							printf("Informe o ID do processo a ser inserido: ");
							scanf("%d", &id);
							insereProcesso(fila, id);
							break;
						}
						case 2:
							imprimirProcessos(fila);
							break;
						case 3:
							retiraProcesso(fila);
							break;
						case 4:
							liberar(fila);
							fila = NULL;
							printf("Fila de processos dinamica liberada.\n");
							break;
						case 0:
							printf("Voltando para o menu principal...\n");
							break;
						default:
							printf("Opçao invalida. Tente novamente.\n");
							break;
					}
				} while (opcao != 0);

				break;
			}
			case 2: {
				printf("=========== FILA DE PROCESSOS ESTATICA ===========\n");
				Fila *fila = criaFila();

				insereProcesso(fila, 1);
				insereProcesso(fila, 2);
				insereProcesso(fila, 3);
			
				imprimirProcessos(fila);
			
				retiraProcesso(fila);
			
				imprimirProcessos(fila);
			
				liberar(fila);
				break;
			}
			case 0:
				printf("Encerrando o programa...\n");
				break;
			default:
				printf("Opçao invalida. Tente novamente.\n");
				break;
		}
	} while (escolha != 0);

	return 0;
}


