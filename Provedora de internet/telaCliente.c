#include "funcaoCliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define TAMANHO 100



void telaCliente() // tela inicial do usuário como cliente após o login
{
    int logadoCliente;


    printf("\n\n");
    printf("Olá caro cliente, desde já agradecemos a preferência\nE iremos te fornecer a melhor internet com banda larga ilimitada e 5G.");
    printf("\n\n");

    printf("1.Consultar Perfil\n2.Consultar Produtos\n3.Consultar Serviços\n0.Voltar ao Menu Inicial\n");
    scanf("%i", &logadoCliente);

    switch(logadoCliente)
    {
    case 0:
        telaInicial();
        break;

    case 1:
        limparTela();
        consultaPerfil();
        break;
    case 2:
        limparTela();
        consultarProdutosCli();
        break;
    case 3:
        limparTela();
        consultarServicoCli();
        break;
    default:
        printf("Opção invalída!!!");
        telaCliente();
    }

}
void consultaPerfil() // tela de perfil do cliente
{
    int opcao = 0;
     printf("Consulta de perfil selecionado. \n\n1. Incluir Dados\n2. Consultar Perfil\n3. Alterar Dados\n4. Excluir perfil.\n0. Voltar\n");
     scanf("%d", &opcao);

     switch(opcao)
     {
     case 1:
        limparTela();
        adicionarClientesProdutos();
        break;
     case 2:
        limparTela();
        consultarClientesProdutos();
        break;
     case 3:
        limparTela();
        alterarClientesProdutos();
        break;
     case 4:
        limparTela();
        excluirClientesProdutos();
        break;
     case 0:
        limparTela();
        telaCliente();
        break;
     default:
        printf("Selecione uma opção válida !!!");
        limparTela();
        consultaPerfil();
     }
}

void consultarProdutosCli() // tela para o cliente pedir ou consultar produtos
{
    int opcao = 0;
    printf("Consulta de Produtos selecionado. \n\n1. Consultar Produtos\n2. Solicitar Produtos\n3. Cancelar Produtos.\n4. Consultar produtos solicitados\n0. Voltar\n");
    scanf("%d", &opcao);

     switch(opcao)
     {
     case 1:
        consultarProdutoClientes();
        break;
     case 2:
       adicionarProdutoSolicitados();
        break;
     case 3:
        limparTela();
        cancelarProduto();
        break;
     case 4:
        limparTela();
        consultarProdutoSolicitado();
        break;
     case 0:
         limparTela();
         telaCliente();
        break;
     default:
        printf("Selecione uma opção válida !!!");
        limparTela();
        consultarProdutosCli();
     }
}

void consultarServicoCli() // tela para o cliente pedir ou consultar serviços
{
    int opcao = 0;
    printf("consulta de Serviços selecionado. \n\n1.Solicitar Serviços\n2.Consultar Serviços\n3.Cancelar serviço solicitado.\n4.Voltar.");
    scanf("%i", &opcao);

    switch(opcao)
    {
        case 1:
            adicionarServicoSolicitados();
            limparTela();
            break;

        case 2:
            limparTela();
            consultarServicoClientes();
            break;

        case 3:
            limparTela();
            cancelarServico();
            break;

        case 4:
            telaCliente();
            limparTela();
            break;

        default:
            printf("opção inválida, tente novamente");
            system("pause");
            consultarServicoCli();
    }
}
