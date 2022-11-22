#include "funcaoCliente.h"
#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>



    struct Cliente
    {
    int codigo;
    char nomeProduto;
    float valorProduto;
    char descricaoProduto[50];
    int funcionario;
    char deletar;
    };



    FILE *funCliente;



void funcaoCliente()
{
    int opcao =0;
    limparTela();
    printf("Oque voce deseja fazer ?\n\n");
    printf("1. Adicionar cadastro\n");
    printf("2. Alterar cadastro\n");
    printf("3. Login\n");
    printf("0. Voltar\n");
    scanf("%d",&opcao);

    switch(opcao)
    {
    case 1:
        adicionarCliente();
        break;
    case 2:
        alterarCliente();
        break;
    case 3:
        login();
        break;
    case 0:
        limparTela();
        FuncoesMenuInicial();
        break;
    default:
        printf("SELECIONE UMA OPÇÃO VALIDA!!!");
        funcaoCliente();
    }
}

void adicionarCliente()
{

    int voltar;

    funCliente = fopen("Clientes.txt", "ab");
    if(funCliente == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }
            struct Cliente clientes;

            printf("Digite os numeros do seu cpf sem pontuação..: \n");
            scanf("%d", &clientes.codigo);
            printf("Informe seu nome completo..: \n");
            fflush(stdin);
            gets(clientes.descricaoProduto);
            printf("informe seu salario..: \n");
            scanf("%f", &clientes.valorProduto);

    voltar = fwrite (&clientes, sizeof(clientes) ,1,funCliente);

    if(voltar == 1)
        {
            printf("\nINFO. GRAVADAS COM SUCESSO!\n");
            fclose(funCliente);
            system("pause");
            funcaoCliente();
        }

}

void consultarCliente()
{
    funCliente = fopen("Clientes.txt", "rb");
    if(funCliente == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }

    struct Cliente clientes;

    int encontrado = 0,cod;

    printf ("\nDigite o numero do seu CPF* sem pontuação..: \n");
    scanf ("%d", &cod);

    while (fread(&clientes, sizeof(clientes), 1, funCliente))
    {

    printf("Buscando .... \n\n");

        if ((cod == clientes.codigo)  && (clientes.deletar != '*'))
        {
            printf("Usuario..: %d \nNome..: %-8s \nSalario..: R$ %4.2f\n", clientes.codigo,clientes.descricaoProduto,clientes.valorProduto);
            encontrado = 1;
            system("pause>nul");
            funcaoCliente();

        }
    }
    if (!encontrado)
    {
        printf("\nPerfil nao cadastrado!!\n");
        system("pause");
       funcaoCliente();
    }
    fclose(funCliente);
}

void excluirCliente()
{
   funCliente = fopen("Clientes.txt", "r+b");
    if(funCliente == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }

    struct Cliente clientes;

    int cod, encontrado = 0;
    char certeza;
    printf ("\nDigite o CPF que deseja EXCLUIR..: \n");
    scanf ("%d", &cod);

    while (fread (&clientes, sizeof(clientes), 1, funCliente))
    {
        if (cod == clientes.codigo)
        {
            printf("Usuario..: %d \nNome..: %-8s  \nSalario..: R$ %4.2f\n\n",clientes.codigo, clientes.descricaoProduto, clientes.valorProduto);
            encontrado = 1;

            printf("\nTem certeza que quer excluir este perfil? s/n \n");
            fflush(stdin);
            scanf("%c", &certeza);
            if (certeza == 's')
            {
                clientes.deletar = '*';
                fseek(funCliente,sizeof(struct Cliente)*-1, SEEK_CUR);
                fwrite(&clientes, sizeof(clientes), 1, funCliente);
                fseek(funCliente, sizeof(clientes)* 0, SEEK_END);
                printf("\nPerfil excluido com Sucesso! \n");
                limparTela();
                funcaoCliente();
            }
            else if (certeza == 'n')
            {
                system("cls || clear");
            }
        }
    }
    if (!encontrado)
    {
        printf ("\nPerfil nao cadastrado!!\n");
        limparTela();
        funcaoCliente();
    }
    fclose(funCliente);
}




void alterarCliente()
{
  funCliente = fopen("Clientes.txt", "r+b");
    if(funCliente == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }

    struct Cliente clientes;
    int cod, encontrado = 0;
    printf ("\nDigite o cpf que deseja alterar: \n");
    scanf ("%d", &cod);

    while (fread (&clientes, sizeof(clientes), 1, funCliente))
    {
        if (cod == clientes.codigo)
        {
            printf("Usuario..: %d \nnome..: %-8s \nSalario R$ %4.2f\n\n",clientes.codigo, clientes.descricaoProduto, clientes.valorProduto);
            encontrado = 1;

            fseek(funCliente,sizeof(struct Cliente)*-1, SEEK_CUR);
            printf("\nDigite um novo nome..: \n");
            fflush(stdin);
            gets(clientes.descricaoProduto);
            printf("\nDigite o novo Salario..: \n");
            scanf("%f", &clientes.valorProduto);

            fwrite(&clientes, sizeof(clientes), 1, funCliente);
            fseek(funCliente, sizeof(clientes)* 0, SEEK_END);

            printf("\n Dados do perfil alterados com sucesso!");
            limparTela();
            funcaoCliente();
        }
    }
    if (!encontrado)
    {
        printf("\nCodigo nao cadastrado!!\n");
        limparTela();
        funcaoCliente();
    }
    fclose(funCliente);
}


void login()
{
    funCliente = fopen("Clientes.txt", "rb");
    if(funCliente == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }

    struct Cliente clientes;

    int encontrado = 0,cod;

    printf ("\nLogin utilize seu CPF para entrar..: \n");
    scanf ("%d", &cod);

    while (fread(&clientes, sizeof(clientes), 1, funCliente))
    {

    printf("\nVerifincando .... \n\n");

        if ((cod == clientes.codigo)  && (clientes.deletar != '*'))
        {
            printf("Bem Vindo..: %-8s \n",clientes.descricaoProduto);
            encontrado = 1;
           telaCliente();

        }
    }
    if (!encontrado)
    {
        printf("\nCodigo nao cadastrado!!\n");
        system("pause");
       funcaoCliente();
    }
    fclose(funCliente);

}






void adicionarClientesProdutos()
{

    int voltar;

    funCliente = fopen("Clientes.txt", "ab");
    if(funCliente == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }
            struct Cliente clientes;

            printf("Digite os numeros do seu cpf sem pontuação..: \n");
            scanf("%d", &clientes.codigo);
            printf("Informe seu nome completo..: \n");
            fflush(stdin);
            gets(clientes.descricaoProduto);
            printf("informe seu salario..: \n");
            scanf("%f", &clientes.valorProduto);

    voltar = fwrite (&clientes, sizeof(clientes) ,1,funCliente);

    if(voltar == 1)
        {
            printf("\nINFO. GRAVADAS COM SUCESSO!\n");
            fclose(funCliente);
            system("pause");
            consultaPerfil();
        }

}

void consultarClientesProdutos()
{
    funCliente = fopen("Clientes.txt", "rb");
    if(funCliente == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }

    struct Cliente clientes;

    int encontrado = 0,cod;

    printf ("\nDigite o numero do seu CPF* sem pontuação..: \n");
    scanf ("%d", &cod);

    while (fread(&clientes, sizeof(clientes), 1, funCliente))
    {

    printf("Buscando .... \n\n");

        if ((cod == clientes.codigo)  && (clientes.deletar != '*'))
        {
            printf("Usuario..: %d \nNome..: %-8s \nSalario..: R$ %4.2f\n", clientes.codigo,clientes.descricaoProduto,clientes.valorProduto);
            encontrado = 1;
            system("pause>nul");
            consultaPerfil();
        }
    }
    if (!encontrado)
    {
        printf("\nPerfil nao cadastrado!!\n");
        system("pause");
       consultaPerfil();
    }
    fclose(funCliente);
}

void excluirClientesProdutos()
{
   funCliente = fopen("Clientes.txt", "r+b");
    if(funCliente == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }

    struct Cliente clientes;

    int cod, encontrado = 0;
    char certeza;
    printf ("\nDigite o CPF que deseja EXCLUIR..: \n");
    scanf ("%d", &cod);

    while (fread (&clientes, sizeof(clientes), 1, funCliente))
    {
        if (cod == clientes.codigo)
        {
            printf("Usuario..: %d \nNome..: %-8s  \nSalario..: R$ %4.2f\n\n",clientes.codigo, clientes.descricaoProduto, clientes.valorProduto);
            encontrado = 1;

            printf("\nTem certeza que quer excluir este perfil? s/n \n");
            fflush(stdin);
            scanf("%c", &certeza);
            if (certeza == 's')
            {
                clientes.deletar = '*';
                fseek(funCliente,sizeof(struct Cliente)*-1, SEEK_CUR);
                fwrite(&clientes, sizeof(clientes), 1, funCliente);
                fseek(funCliente, sizeof(clientes)* 0, SEEK_END);
                printf("\nPerfil excluido com Sucesso! \n");
                limparTela();
                consultaPerfil();
            }
            else if (certeza == 'n')
            {
                system("cls || clear");
            }
        }
    }
    if (!encontrado)
    {
        printf ("\nPerfil nao cadastrado!!\n");
        limparTela();
        consultaPerfil();
    }
    fclose(funCliente);
}




void alterarClientesProdutos()
{
  funCliente = fopen("Clientes.txt", "r+b");
    if(funCliente == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }

    struct Cliente clientes;
    int cod, encontrado = 0;
    printf ("\nDigite o cpf que deseja alterar: \n");
    scanf ("%d", &cod);

    while (fread (&clientes, sizeof(clientes), 1, funCliente))
    {
        if (cod == clientes.codigo)
        {
            printf("Usuario..: %d \nnome..: %-8s \nSalario R$ %4.2f\n\n",clientes.codigo, clientes.descricaoProduto, clientes.valorProduto);
            encontrado = 1;

            fseek(funCliente,sizeof(struct Cliente)*-1, SEEK_CUR);
            printf("\nDigite um novo nome..: \n");
            fflush(stdin);
            gets(clientes.descricaoProduto);
            printf("\nDigite o novo Salario..: \n");
            scanf("%f", &clientes.valorProduto);

            fwrite(&clientes, sizeof(clientes), 1, funCliente);
            fseek(funCliente, sizeof(clientes)* 0, SEEK_END);

            printf("\n Dados do perfil alterados com sucesso!");
            limparTela();
            consultaPerfil();
        }
    }
    if (!encontrado)
    {
        printf("\nCodigo nao cadastrado!!\n");
        limparTela();
        consultaPerfil();
    }
    fclose(funCliente);
}
