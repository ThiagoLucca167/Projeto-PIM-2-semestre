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
<<<<<<< HEAD

void telaFuncionario()
{
    system("cls || clean");
    opcao = 0;

    logotipo();
=======
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
>>>>>>> 73ae061a377a77c8a2bfda6a6e7add7d5c9a6119

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
            printf("op��o inv�lida, tente novamente.");
            system("pause>nul");
            telaFuncionario();
    }
}

char logo;
void logotipo()
{
<<<<<<< HEAD
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
=======
>>>>>>> 73ae061a377a77c8a2bfda6a6e7add7d5c9a6119
    system("cls || clean");
    opcao = 0;

    logotipo();
<<<<<<< HEAD
    printf("\t1. ADMIN.\n");
    printf("\t2. opera��o.\n");
    printf("\t3. Almoxarifado.\n");
    printf("\t4. Recep��o.\n");
    printf("\t5. Voltar.\n\n");
=======
    printf("\t1. almoxarifado.\n");
    printf("\t2. TI.\n");
    printf("\t3. RH.\n");
    printf("\t4. voltar.\n\n");
>>>>>>> 73ae061a377a77c8a2bfda6a6e7add7d5c9a6119
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
            printf("op��o inv�lida, tente novamente.");
            system("pause>nul");
            setores();
    }
}

void admin()
{
    system("cls || clean");
    opcao = 0;
    int estoque;

    logotipo();
<<<<<<< HEAD
    printf("fun��es para adm\n\n");
=======
    printf("Bem vindo ao almoxarifado!\n");
    printf("O que deseja fazer ?!\n");

    printf("1. Adicionar Produtos\n");
    printf("2. Consultar Produtos\n");
    printf("3. Alterar produtos\n");
    printf("4. Excluir produtos");
>>>>>>> 73ae061a377a77c8a2bfda6a6e7add7d5c9a6119
    system("pause");
    setores();
}

void operacao()
{
    system("cls || clean");
    opcao = 0;

    logotipo();
<<<<<<< HEAD
    printf("1. cadastrar produtos/servi�os\n");
    printf("2. ...\n\n");
    scanf("%i", &opcao);

    switch(opcao){
        case 1:
            adicionarProduto();
            break;

    default:
            printf("op��o inv�lida, tente novamente.");
            system("pause>nul");
            operacao();
    }
=======
    printf("1. equipamentos\n");
    printf("2. relatorio de visitas\n\n");
    system("pause");
    setores();
>>>>>>> 73ae061a377a77c8a2bfda6a6e7add7d5c9a6119
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
    printf("altera��o de dados (ADMIN)\n");
    printf("excluis�o de dados (ADMIN)\n");
    printf("adicionar funcionarios (ADMIN, ir direto para funcaoFuncionario)\n\n");
    system("pause");
    telaFuncionario();
}







void adicionarProduto()
{
    int contador=0, voltar;



    arqProdutosCliente =fopen("Produtos da BROADTECH.txt", "a");
    if(arqProdutosCliente == NULL){
        printf("\n\tATENCAO o arquivo n�o pode ser aberto");
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
            printf("Descri��o: ");
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
