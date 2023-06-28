#include "lista.c"
// #include "Funcionarios.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void main()
{
    setlocale(LC_ALL, "Portuguese");
    Lista *lista = inicializaLista();

    int opcao;
    char cpf[12];

    do
    {
        printf("MENU\n");
        printf("1. Adicionar novo funcionario \n");
        printf("2. Ver lista de funcionarios \n");
        printf("3. Buscar por CPF \n");
        printf("4. Remover funcionario \n");
        printf("5. Limpar lista \n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        system("cls");

        switch (opcao)
        {
        case 1:
            printf("Você escolheu a opção 1\n");
            adicionaFuncionario(lista);
            break;
        case 2:
            printf("Você escolheu a opção 2\n");
            listaFuncionarios(lista);
            break;
        case 3:
            printf("Você escolheu a opção 3\n");
            printf("Informe o CPF: ");
            // Limpar o buffer de entrada
            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            fgets(cpf, 12, stdin);
            size_t length = strlen(cpf);
            if (cpf[length - 1] == '\n') {
                cpf[length - 1] = '\0';
            }
            struct funcionario* f = buscarPorCPF(lista, cpf);
            if(f == NULL) {
                printf("\nFuncionario não encontrado.\n");
            } else {
                printf("\nFuncionario encontrado com CPF: %s\n", cpf);
                visualizarFuncionario(f);
            }
            break;
        case 4:
            printf("Você escolheu a opção 4\n");
            // Limpar o buffer de entrada
            printf("Informe o CPF: ");
            scanf("%s", cpf);
            
            int resultado = pop(lista, cpf);
            if(resultado == 1) {
                printf("Funcionário removido com sucesso.\n");
            }
            break;
        case 5:
            printf("Você escolheu a opção 5\n");
            printf("Informe a matricula: ");
            scanf("%d", &cpf);
            // removerFuncionario(compania, cpf);
            break;
        case 6:
            printf("Você escolheu a opção 6\n");
            // limpaLista(compania);
            break;
        case 7:
            printf("Você escolheu a opção 7\n");
            // deletar_empresa(compania);
            break;
        case 0:
            printf("Encerrando o programa...\n");
            break;
        default:
            printf("opção inválida\n");
            break;
        }

        printf("\n");
    } while (opcao != 0);

    getch();
}
