#include "Lista_funcionarios.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void mainEstatico()
{
    setlocale(LC_ALL, "Portuguese");
    Empresa *compania = (Empresa *)malloc(sizeof(Empresa));
    inicializaLista(compania);
    // imprimirEmpresa(compania);

    int opcao;
    char cpf[12];

    do
    {

        printf("MENU\n");
        printf("1. Adicionar funcionarios \n");
        printf("2. Ver lista de funcionarios \n");
        printf("3. Visão geral da empresa \n");
        printf("4. Buscar pela matricula \n");
        printf("5. Remover funcionario \n");
        printf("6. Limpar lista \n");
        printf("7. Excluir empresa \n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        system("cls");

        switch (opcao)
        {
        case 1:
            printf("Você escolheu a opção 1\n");
            adicionaFuncionario(compania);
            break;
        case 2:
            printf("Você escolheu a opção 2\n");
            imprimeLista(compania);
            break;
        case 3:
            printf("Você escolheu a opção 3\n");
            imprimirEmpresa(compania);
            break;
        case 4:
            printf("Você escolheu a opção 4\n");
            printf("Informe o CPF: ");
            // Limpar o buffer de entrada
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;

            fgets(cpf, 12, stdin);
            size_t length = strlen(cpf);
            if (cpf[length - 1] == '\n')
            {
                cpf[length - 1] = '\0';
            }
            int indice = buscarPorCPF(compania, cpf);
            printf("indice do funcionario %d", indice);
            if (indice != -1) {
                printf("\nFuncionario encontrado com CPF: %s\n", cpf);
                imprimeFuncionario(compania->lista_funcionarios[indice]);
            }
            break;
        case 5:
            printf("Você escolheu a opção 5\n");
            printf("Informe a matricula: ");
            scanf("%d", &cpf);
            removerFuncionario(compania, cpf);
            break;
        case 6:
            printf("Você escolheu a opção 6\n");
            limpaLista(compania);
            break;
        case 7:
            printf("Você escolheu a opção 7\n");
            deletar_empresa(compania);
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
