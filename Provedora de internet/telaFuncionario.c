#include "funcaoCliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define TAMANHO 100


int opcao;

void telaFuncionario() // tela inicial de usu?rio como funcionario ap?s de login
{
    limparTela();
    opcao = 0;

    logoTipo();
    printf("\t1. Setores.\n");
    printf("\t2. Dados de perfil.\n");
    printf("\t0. Sair para menu inicial.\n\n");
    scanf("%i", &opcao);

    switch(opcao)
    {
        case 1:
            setores();
            break;

        case 2:
            perfilFuncionario();
            break;

        case 0:
            telaInicial();
            break;

        default:
            printf("op??o inv?lida, tente novamente.");
            system("pause");
            telaFuncionario();
    }
}



void setores() // tela onde o funcionario ir? gerenciar o estoque, relatorios, cadastros
{
    system("cls || clean");
    opcao = 0;

    logoTipo();
    printf("\t1. opera??o.\n");
    printf("\t2. Recep??o.\n");
    printf("\t3. almoxarifado.\n");
    printf("\t0. Voltar.\n\n");
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
            almoxarifado();
            break;

        case 0:
            telaFuncionario();
            break;

        default:
            printf("op??o inv?lida, tente novamente.");
            system("pause");
            setores();
    }
}

void operacao() // tela de gerenciamento de produtos e servi?os
{
    system("cls || clean");
    opcao = 0;

    logoTipo();
    printf("Selecione..:\n");
    printf("1. Alterar Produtos\n");
    printf("2. Consultar Produtos\n");
    printf("3. Alterar Servi?os\n");
    printf("4. Consultar Servi?os\n");
    printf("5. Pedidos de Produtos\n");
    printf("0. Voltar\n");
    scanf("%i", &opcao);

    switch(opcao){
        case 1:
            system("cls || clean");
            logoTipo();
            alterarProduto();
            break;
        case 2:
            system("cls || clean");
            logoTipo();
            consultarProduto();
            break;

        case 3:
            system("cls || clean");
            logoTipo();
            alterarServico();
            break;

        case 4:
            system("cls || clean");
            logoTipo();
            consultarServico();
            break;

        case 5:
            system("cls || clean");
            logoTipo();
            produtosRequisitado();
            break;

        case 0:
            setores();
            break;
    default:
            printf("op??o inv?lida, tente novamente.");
            system("pause");
            operacao();
    }
    setores();
}

void recepcao() // tela de gerenciamento de clientes e produtos
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
            system("cls || clean");
            logoTipo();
            consultarClienteFuncionarioRecepcao();
            break;
        case 2:
            system("cls || clean");
            logoTipo();
            alterarClienteFuncionariosRecepcao();
            break;
        case 3:
            system("cls || clean");
            excluirClienteFuncionarioRecepcao();
            break;
        case 4:
            system("cls || clean");
            logoTipo();
            consultarProdutoFuncionarioRecepcao();
            break;
        case 5:
            system("cls || clean");
            logoTipo();
            alterarProdutoFuncionarioRecepcao();
            break;
        case 0:
            setores();
            break;
    default:
            printf("op??o inv?lida, tente novamente.");
            system("pause");
            operacao();
    }
    setores();
}

void almoxarifado() // tela para cadastro de produtos e servi?os
{
    system("cls || clean");
    opcao = 0;

    logoTipo();
    printf("Bem vindo ao almoxarifado!\n");
    printf("O que deseja fazer ?!\n");
    printf("1. Adicionar Produtos\n");
    printf("2. Consultar Produtos\n");
    printf("3. Alterar produtos\n");
    printf("4. Adicionar Servi?os\n");
    printf("5. Consultar Servi?os\n");
    printf("6. Alterar Servi?os\n");
    printf("7. Excluir Servi?os\n");
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
            adicionarServicoAlmoxarifado();
            break;

        case 5:
            system("cls || clean");
            logoTipo();
            consultarServicoAlmoxarifado();
            break;

        case 6:
            system("cls || clean");
            logoTipo();
            alterarServicoAlmoxarifado();
            break;
        case 7:
            excluirServicoAlmoxarifado();
            break;

        case 0:
            setores();
            break;

        default:
            printf("op??o inv?lida, tente novamente.");
            system("pause");
            almoxarifado();


    }
}

void perfilFuncionario() // tela para consulta de perfil de funcion?rios
{
    system("cls || clean");
    opcao = 0;

    logoTipo();
    printf("1.consulta de dados\n");
    printf("0.voltar\n");
    scanf("%i", &opcao);

    switch(opcao)
    {
        case 1:
            system("cls || clean");
            consultarFuncionario();
            break;

        case 0:
            telaFuncionario();
            break;

        default:
            printf("op??o inv?lida, tente novamente.");
            system("pause");
            perfilFuncionario();

    }
}

void funcaoAdm() // tela exclusiva de administrador onde ele tem acesso total a todas as fun??es
{
    system("cls || clean");
    opcao = 0;

    logoTipo();
    printf("1.dados de funcionarios\n");
    printf("2.almoxarifado\n");
    printf("3.dados de clientes\n");
    printf("0.Voltar\n");
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

        case 0:
            system("cls || clean");
            FuncoesMenuInicial();
            break;

        default:
            printf("op??o inv?lida, tente novamente.");
            system("pause");
            funcaoAdm();
    }
}

void perfilFuncionarioADM() // tela de administrador onde tem acesso total ao CRUD de funcion?rios
{
    system("cls || clean");
    opcao = 0;

    logoTipo();
    printf("1. cadastrar funcionario\n");
    printf("2. consultar funcionario\n");
    printf("3. alterar funcionario\n");
    printf("4. excluir funcionario\n");
    printf("0. voltar\n\n");
    scanf("%i", &opcao);

    switch(opcao)
    {
        case 1:
            cadastroFuncionario();
            break;

        case 2:
            consultarFuncionarioADM();
            break;

        case 3:
            alterarFuncionario();
            break;

        case 4:
            excluirFuncionario();
            break;

        case 0:
            funcaoAdm();
            break;

        default:
            printf("op??o inv?lida, tente novamente.");
            system("pause");
            perfilFuncionarioADM();
    }
}

void almoxarifadoADM() // tela de administrador onde tem acesso total ao CRUD de produtos e servi?os
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
    printf("5. Adicionar Servi?os\n");
    printf("6. Consultar Servi?os\n");
    printf("7. Alterar Servi?os\n");
    printf("8. Excluir Servi?os\n");
    printf("0. Voltar\n");
    scanf("%i", &opcao);

    switch(opcao)
    {
        case 1:
            system("cls || clean");
            logoTipo();
            adicionarClientesProdutos();
            break;

        case 2:
            system("cls || clean");
            logoTipo();
            consultarClientesProdutos();
            break;

        case 3:
            system("cls || clean");
            logoTipo();
            alterarClientesProdutos();
            break;

        case 4:
            system("cls || clean");
            logoTipo();
            excluirClientesProdutos();
            break;

        case 5:
            system("cls || clean");
            logoTipo();
            adicionarServicoAMD();
            break;

        case 6:
            system("cls || clean");
            logoTipo();
            consultarServicoADM();
            break;

        case 7:
            system("cls || clean");
            logoTipo();
            alterarServicoADM();
            break;

        case 8:
            system("cls || clean");
            logoTipo();
            excluirServicoADM();
            break;

        case 0:
            funcaoAdm();
            break;

        default:
            printf("op??o inv?lida, tente novamente.");
            system("pause");
            almoxarifadoADM();

    }
}

void perfilClienteADM() // tela de administrador onde tem acesso total ao CRUD de clientes
{
    system("cls || clean");
    opcao = 0;

    logoTipo();
    printf("1. Cadastrar Cliente\n");
    printf("2. Alterar Cliente\n");
    printf("3. Consultar Cliente\n");
    printf("4. Excluir Cliente\n");
    printf("0. Voltar\n");
    scanf("%i", &opcao);

    switch(opcao)
    {
        case 1:
            adicionarClienteADM();
            break;

        case 2:
            alterarClienteADM();
            break;

        case 3:
            consultarClienteADM();
            break;

        case 4:
            excluirClienteADM();
            break;

        case 0:
            funcaoAdm();
            break;

        default:
            printf("op??o inv?lida, tente novamente.");
            limparTela();
            perfilClienteADM();
    }
}

void logoTipo() // logotipo da empresa que estar? em v?rias telas do sistema
{
    printf("\n\n");
    printf("\t\t  ____  _____   ____     _______ _______ ______ _____ _    _ \n");
    printf("\t\t |  _  |  __ | / __     / |  __ |__   __|  ____/ ____| |  | |\n");
    printf("\t\t | |_) | |__)|| |  | | /  | |  | | | |  | |__ | |    | |__| |\n");
    printf("\t\t |  _ <|  _ / | |  | |/ /_| |  | | | |  |  __|| |    |  __  |\n");
    printf("\t\t | |_) | |  | | |__| / ___| |__| | | |  | |___| |____| |  | |\n");
    printf("\t\t |____/|_|  |_  ____/_/   |_____/  |_|  |______ _____|_|  |_|\n\n\n");
}
