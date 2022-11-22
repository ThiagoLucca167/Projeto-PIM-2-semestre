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

    logoTipo();
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

    logoTipo();
    printf("\t1. operação.\n");
    printf("\t2. Recepção.\n");
    printf("\t3. Voltar.\n\n");
    scanf("%i", &opcao);

    switch(opcao)
    {
        case 1:
            operacao();
            break;

        case 2:
            recepcao();
            break;

        case 3:
            telaFuncionario();
            break;

        default:
            printf("opção inválida, tente novamente.");
            system("pause>nul");
            setores();
    }
}

void operacao()
{
    system("cls || clean");
    opcao = 0;

    logoTipo();
    printf("Selecione..:\n");
    printf("1. Adicionar Produtos\n");
    printf("2. Consultar Produtos\n");
    printf("3. Adicionar Serviços\n");
    printf("4. Consultar Serviços\n");
    printf("0. Voltar\n");
    scanf("%i", &opcao);

    switch(opcao){
        case 1:
            system("cls || clean");
            logoTipo();
            adicionarProduto();
            break;
        case 2:
            system("cls || clean");
            logoTipo();
            consultarProduto();
            break;

        case 3:
            system("cls || clean");
            logoTipo();
            adicionarServico();
            break;

        case 4:
            system("cls || clean");
            logoTipo();
            consultarServico();
            break;

        case 0:
            setores();
            break;
    default:
            printf("opção inválida, tente novamente.");
            system("pause>nul");
            operacao();
    }
    setores();
}

void recepcao()
{
    system("cls || clean");
    opcao = 0;

    logoTipo();
     printf("Selecione..:\n");
    printf("1. Consultar Clientes\n");
    printf("2. Alterar Clientes\n");
    printf("3. Excluir Clientes\n");
    printf("4. Consultar Produtos\n");
    printf("5. Alterar Produtos\n");
    printf("0. Voltar\n");
    scanf("%i", &opcao);

    switch(opcao){
        case 1:
            logoTipo();
            consultarCliente();
            break;
        case 2:
            logoTipo();
            alterarCliente();
            break;
        case 3:
            excluirCliente();
            break;
        case 4:
            logoTipo();
            consultarProduto();
            break;
        case 5:
            logoTipo();
            alterarProduto();
            break;
        case 0:
            setores();
            break;
    default:
            printf("opção inválida, tente novamente.");
            system("pause>nul");
            operacao();
    }
    setores();
}



void perfilFuncionario()
{
    system("cls || clean");
    opcao = 0;

    logoTipo();
    printf("1.consulta de dados\n");
    scanf("%i", &opcao);

    switch(opcao)
    {
        case 1:
            system("cls || clean");
            testeconsultarFuncionario();

    }
}

void funcaoAdm()
{
    system("cls || clean");
    opcao = 0;

    logoTipo();
    printf("1.dados de funcionarios\n");
    printf("2.almoxarifado\n");
    printf("3.dados de clientes\n\n");
    scanf("%i", &opcao);

    switch(opcao)
    {
        case 1:
            perfilFuncionarioADM();
            break;

        case 2:
            almoxarifadoADM();
            break;

        case 3:
            perfilClienteADM();
            break;

        default:
            printf("opcao invalida");
            funcaoAdm();
    }
}

void perfilFuncionarioADM()
{
    system("cls || clean");
    opcao = 0;

    logoTipo();
    printf("1. cadastrar funcionario\n");
    printf("2. consultar funcionario\n");
    printf("3. alterar funcionario\n");
    printf("4. excluir funcionario\n");
    printf("5. voltar\n\n");
    scanf("%i", opcao);

    switch(opcao)
    {
        case 1:
            testecadastroFuncionario();
            break;

        case 2:
            testeconsultarFuncionario();
            break;

        case 3:
            testealterarFuncionario();
            break;

        case 4:
            testeexcluirFuncionario();
            break;

        case 5:
            funcaoAdm();
            break;

        default:
            printf("opcao invalida");
            perfilFuncionarioADM();
    }
}

void almoxarifadoADM()
{
    system("cls || clean");
    opcao = 0;

    logoTipo();
    printf("Bem vindo ao almoxarifado!\n");
    printf("O que deseja fazer ?!\n");
    printf("1. Adicionar Produtos\n");
    printf("2. Consultar Produtos\n");
    printf("3. Alterar produtos\n");
    printf("4. Excluir produtos\n");
    printf("5. Adicionar Serviços\n");
    printf("6. Consultar Servilços\n");
    printf("7. Alterar Serviços\n");
    printf("8. Excluir Serviços\n");
    printf("0. Voltar\n");
    scanf("%i", &opcao);

    switch(opcao)
    {
        case 1:
            system("cls || clean");
            logoTipo();
            adicionarProduto();
            break;

        case 2:
            system("cls || clean");
            logoTipo();
            consultarProduto();
            break;

        case 3:
            system("cls || clean");
            logoTipo();
            alterarProduto();
            break;

        case 4:
            system("cls || clean");
            logoTipo();
            excluirProduto();
            break;

        case 5:
            system("cls || clean");
            logoTipo();
            adicionarServico();
            break;

        case 6:
            system("cls || clean");
            logoTipo();
            alterarServico();
            break;

        case 7:
            system("cls || clean");
            logoTipo();
            consultarServico();
            break;

        case 8:
            system("cls || clean");
            logoTipo();
            excluirServico();
            break;

        case 0:
            funcaoAdm();
            break;

    }
}

void perfilClienteADM()
{
    system("cls || clean");
    opcao = 0;

    logoTipo();
    printf("1. Cadastrar Cliente\n");
    printf("2. Alterar Cliente\n");
    printf("3. Consultar Cliente\n");
    printf("4. Excluir Cliente\n");
    scanf("%i", &opcao);

    switch(opcao)
    {
        case 1:
            adicionarCliente();
            break;

        case 2:
            alterarCliente();
            break;

        case 3:
            consultarCliente();
            break;

        case 4:
            excluirCliente();
            break;

        case 5:
            funcaoAdm();
            break;

        default:
            printf("opcao invalida");
            perfilClienteADM();
    }
}

void logoTipo()
{
    printf("\n\n");
    printf("\t\t  ____  _____   ____     _______ _______ ______ _____ _    _ \n");
    printf("\t\t |  _  |  __ | / __     / |  __ |__   __|  ____/ ____| |  | |\n");
    printf("\t\t | |_) | |__)|| |  | | /  | |  | | | |  | |__ | |    | |__| |\n");
    printf("\t\t |  _ <|  _ / | |  | |/ /_| |  | | | |  |  __|| |    |  __  |\n");
    printf("\t\t | |_) | |  | | |__| / ___| |__| | | |  | |___| |____| |  | |\n");
    printf("\t\t |____/|_|  |_  ____/_/   |_____/  |_|  |______ _____|_|  |_|\n\n\n");
}
