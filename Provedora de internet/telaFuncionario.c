#include "funcaoCliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define TAMANHO 100
    typedef struct ProdutosClientes
    {
        int internet;
        int caboRede;
        char AcessPoint;
        char amplificadorSinal;
        char funcionario;
        char produtoCriado1;
        char descricaoCriado1;
        char quantidadeCriado1;
    }produtosClientes;

    static int quantidade = 0;
    produtosClientes maximoP[TAMANHO];
    FILE *arqProdutosCliente;

int opcao;
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

void setores()
{
    system("cls || clean");
    opcao = 0;

    logotipo();
    printf("\t1. almoxarifado.\n");
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
    int estoque;

    logotipo();
    printf("Bem vindo ao almoxarifado!\n");
    printf("O que deseja fazer ?!\n");

    printf("1. Adicionar Produtos\n");
    printf("2. Consultar Produtos\n");
    printf("3. Alterar produtos\n");
    printf("4. Excluir produtos");
    system("pause");
    setores();
}

void ti()
{
    system("cls || clean");
    opcao = 0;

    logotipo();
    printf("1. equipamentos\n");
    printf("2. relatorio de visitas\n\n");
    system("pause");
    setores();
}

void rh()
{
    system("cls || clean");
    opcao = 0;

    logotipo();
    printf("1. suporte tecnico\n\n");
    system("pause");
    setores();
}

void perfilFuncionario()
{
    system("cls || clean");
    opcao = 0;

    logotipo();
    printf("consulta de dados\n");
    printf("alteração de dados (ADMIN)\n");
    printf("excluisão de dados (ADMIN)\n\n");
    system("pause");
    telaFuncionario();
}







void adicionarProduto()
{
    int contador=0, voltar;



    arqProdutosCliente =fopen("Produtos da BROADTECH.txt", "a");
    if(arqProdutosCliente == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }

    while (contador < TAMANHO)
    {
        printf("VAMOS DAR INICIO NO CADASTRO\n");
        gets(maximoP[contador].funcionario);
        if(maximoP[contador].funcionario)
        {
          int i = 0;

          for(i=1;i <=1;i++)
          {
            printf("\n\tPRODUTOS...: \n");
            printf("PRODUTO: ");
            gets(maximoP[contador].produtoCriado1);
            printf("Quantidade: ");
            gets(maximoP[contador].quantidadeCriado1);
            printf("Descrição: ");
            gets(maximoP[contador].descricaoCriado1);

          }
          voltar = fwrite (&maximoP[contador],sizeof(produtosClientes),1,arqProdutosCliente);

              if(voltar == 1)
            {
                printf("\nINFO. GRAVADAS COM SUCESSO!\n");
                limparTela();
                funcaoCliente();
            }
        }



         exit(contador);

    }
    fclose(arqProdutosCliente);
}
