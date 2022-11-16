#include "funcaoCliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define TAMANHO 100

int opcao;

void telaFuncionario()
{
    system("cls || clean");
    opcao = 0;

    logotipo();

    printf("\t1. Setores.\n");
    printf("\t2. Dados de perfil.\n");
    printf("\t3. Logout.\n\n");
    scanf("%i", &opcao);

    switch(opcao)
    {
        case 1:
            setores();
            break;

        case 2:
            perfilFuncionario();
            break;

        case 3:
            telaInicial();
            break;

        default:
            printf("opção inválida, tente novamente.");
            system("pause>nul");
            telaFuncionario();
    }
}

char logo;
void logotipo()
{
    printf("\n\n");
    printf("\t\t  ____  _____   ____     _______ _______ ______ _____ _    _ \n");
    printf("\t\t |  _  |  __ | / __     / |  __ |__   __|  ____/ ____| |  | |\n");
    printf("\t\t | |_) | |__)|| |  | | /  | |  | | | |  | |__ | |    | |__| |\n");
    printf("\t\t |  _ <|  _ / | |  | |/ /_| |  | | | |  |  __|| |    |  __  |\n");
    printf("\t\t | |_) | |  | | |__| / ___| |__| | | |  | |___| |____| |  | |\n");
    printf("\t\t |____/|_|  |_  ____/_/   |_____/  |_|  |______ _____|_|  |_|\n\n\n");
}

void setores()
{
    system("cls || clean");
    opcao = 0;

    logotipo();
    printf("\t1. ADMIN.\n");
    printf("\t2. operação.\n");
    printf("\t3. Almoxarifado.\n");
    printf("\t4. Recepção.\n");
    printf("\t5. Voltar.\n\n");
    scanf("%i", &opcao);

    switch(opcao)
    {
        case 1:
            admin();
            break;

        case 2:
            operacao();
            break;

        case 3:
            almoxarifado();
            break;

        case 4:
            recepcao();
            break;

        case 5:
            telaFuncionario();
            break;

        default:
            printf("opção inválida, tente novamente.");
            system("pause>nul");
            setores();
    }
}

void admin()
{
    system("cls || clean");
    opcao = 0;

    logotipo();
    printf("funções para adm\n\n");
    system("pause");
    setores();
}

void operacao()
{
    system("cls || clean");
    opcao = 0;

    logotipo();
    printf("1. cadastrar produtos/serviços\n");
    printf("2. ...\n\n");
    scanf("%i", &opcao);

    switch(opcao){
        case 1:
            adicionarProduto();
            break;

    default:
            printf("opção inválida, tente novamente.");
            system("pause>nul");
            operacao();
    }
}

void recepcao()
{
    system("cls || clean");
    opcao = 0;

    logotipo();
    printf("1. suporte tecnico\n\n");
    system("pause");
    setores();
}

void almoxarifado()
{
    system("cls || clean");
    opcao = 0;

    logotipo();
}

void perfilFuncionario()
{
    system("cls || clean");
    opcao = 0;

    logotipo();
    printf("consulta de dados\n");
    printf("alteração de dados (ADMIN)\n");
    printf("excluisão de dados (ADMIN)\n");
    printf("adicionar funcionarios (ADMIN, ir direto para funcaoFuncionario)\n\n");
    system("pause");
    telaFuncionario();
}
