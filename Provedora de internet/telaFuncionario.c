#include "funcaoCliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define TAMANHO 100

int opcao;
char logo;

void telaFuncionario()
{
    system("cls || clean");
    opcao = 0;

    printf("\n\n");
    printf("\t\t  ____  _____   ____     _______ _______ ______ _____ _    _ \n");
    printf("\t\t |  _  |  __ | / __     / |  __ |__   __|  ____/ ____| |  | |\n");
    printf("\t\t | |_) | |__)|| |  | | /  | |  | | | |  | |__ | |    | |__| |\n");
    printf("\t\t |  _ <|  _ / | |  | |/ /_| |  | | | |  |  __|| |    |  __  |\n");
    printf("\t\t | |_) | |  | | |__| / ___| |__| | | |  | |___| |____| |  | |\n");
    printf("\t\t |____/|_|  |_  ____/_/   |_____/  |_|  |______ _____|_|  |_|\n\n\n");

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

void setores()
{
    system("cls || clean");
    opcao = 0;

    printf("\n\n");
    printf("\t\t  ____  _____   ____     _______ _______ ______ _____ _    _ \n");
    printf("\t\t |  _  |  __ | / __     / |  __ |__   __|  ____/ ____| |  | |\n");
    printf("\t\t | |_) | |__)|| |  | | /  | |  | | | |  | |__ | |    | |__| |\n");
    printf("\t\t |  _ <|  _ / | |  | |/ /_| |  | | | |  |  __|| |    |  __  |\n");
    printf("\t\t | |_) | |  | | |__| / ___| |__| | | |  | |___| |____| |  | |\n");
    printf("\t\t |____/|_|  |_  ____/_/   |_____/  |_|  |______ _____|_|  |_|\n\n\n");

    printf("\t1. Financeiro.\n");
    printf("\t2. TI.\n");
    printf("\t3. RH.\n");
    printf("\t4. voltar.\n\n");
    scanf("%i", &opcao);

    switch(opcao)
    {
        case 1:
            financeiro();
            break;

        case 2:
            ti();
            break;

        case 3:
            rh();
            break;

        case 4:
            telaFuncionario();
            break;

        default:
            printf("opção inválida, tente novamente.");
            system("pause>nul");
            setores();
    }
}

void financeiro()
{
    system("cls || clean");
    opcao = 0;

    printf("\n\n");
    printf("\t\t  ____  _____   ____     _______ _______ ______ _____ _    _ \n");
    printf("\t\t |  _  |  __ | / __     / |  __ |__   __|  ____/ ____| |  | |\n");
    printf("\t\t | |_) | |__)|| |  | | /  | |  | | | |  | |__ | |    | |__| |\n");
    printf("\t\t |  _ <|  _ / | |  | |/ /_| |  | | | |  |  __|| |    |  __  |\n");
    printf("\t\t | |_) | |  | | |__| / ___| |__| | | |  | |___| |____| |  | |\n");
    printf("\t\t |____/|_|  |_  ____/_/   |_____/  |_|  |______ _____|_|  |_|\n\n\n");

    printf("1. almoxarifado\n\n");
    system("pause");
    setores();
}

void ti()
{
    system("cls || clean");
    opcao = 0;

    printf("\n\n");
    printf("\t\t  ____  _____   ____     _______ _______ ______ _____ _    _ \n");
    printf("\t\t |  _  |  __ | / __     / |  __ |__   __|  ____/ ____| |  | |\n");
    printf("\t\t | |_) | |__)|| |  | | /  | |  | | | |  | |__ | |    | |__| |\n");
    printf("\t\t |  _ <|  _ / | |  | |/ /_| |  | | | |  |  __|| |    |  __  |\n");
    printf("\t\t | |_) | |  | | |__| / ___| |__| | | |  | |___| |____| |  | |\n");
    printf("\t\t |____/|_|  |_  ____/_/   |_____/  |_|  |______ _____|_|  |_|\n\n\n");

    printf("1. equipamentos\n");
    printf("2. relatorio de visitas\n\n");
    system("pause");
    setores();
}

void rh()
{
    system("cls || clean");
    opcao = 0;

    printf("\n\n");
    printf("\t\t  ____  _____   ____     _______ _______ ______ _____ _    _ \n");
    printf("\t\t |  _  |  __ | / __     / |  __ |__   __|  ____/ ____| |  | |\n");
    printf("\t\t | |_) | |__)|| |  | | /  | |  | | | |  | |__ | |    | |__| |\n");
    printf("\t\t |  _ <|  _ / | |  | |/ /_| |  | | | |  |  __|| |    |  __  |\n");
    printf("\t\t | |_) | |  | | |__| / ___| |__| | | |  | |___| |____| |  | |\n");
    printf("\t\t |____/|_|  |_  ____/_/   |_____/  |_|  |______ _____|_|  |_|\n\n\n");

    printf("1. suporte tecnico\n\n");
    system("pause");
    setores();
}

void perfilFuncionario()
{
    system("cls || clean");
    opcao = 0;

    printf("\n\n");
    printf("\t\t  ____  _____   ____     _______ _______ ______ _____ _    _ \n");
    printf("\t\t |  _  |  __ | / __     / |  __ |__   __|  ____/ ____| |  | |\n");
    printf("\t\t | |_) | |__)|| |  | | /  | |  | | | |  | |__ | |    | |__| |\n");
    printf("\t\t |  _ <|  _ / | |  | |/ /_| |  | | | |  |  __|| |    |  __  |\n");
    printf("\t\t | |_) | |  | | |__| / ___| |__| | | |  | |___| |____| |  | |\n");
    printf("\t\t |____/|_|  |_  ____/_/   |_____/  |_|  |______ _____|_|  |_|\n\n\n");

    printf("consulta de dados\n");
    printf("alteração de dados (ADMIN)\n");
    printf("excluisão de dados (ADMIN)\n\n");
    system("pause");
    telaFuncionario();
}
