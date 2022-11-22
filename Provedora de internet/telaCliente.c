#include "funcaoCliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define TAMANHO 100



void telaCliente()
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
        printf("consulta de Serviços selecionado. \n\n1.Solicitar Serviços\n2.Consultar Serviços\n3.Sugestão de serviços.");
        break;
    default:
        printf("Opção invalída!!!");
        telaCliente();
    }

}
void consultaPerfil()
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

void consultarProdutosCli()
{
    int opcao = 0;
    printf("Consulta de Produtos selecionado. \n\n1. Consultar Produtos\n2. Solicitar Produtos\n3. Cancelar Produtos.\n0. Voltar\n");
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
