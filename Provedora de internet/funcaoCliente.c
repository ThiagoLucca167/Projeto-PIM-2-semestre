#include "funcaoCliente.h"
#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>

// esta parte do codigo foi desenvolvida exclusivamente para fun��es que tem rela��es com cliente como cadastro, consulta de informa��es etc.sssssss

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



void funcaoCliente()  // tela para o usu�rio fazer o login ou cadastrar como cliente
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
        printf("SELECIONE UMA OP��O VALIDA!!!");
        funcaoCliente();
    }
}

void adicionarCliente() // faz o cadastro do usu�rio como cliente
{

    int voltar;

    funCliente = fopen("Clientes.txt", "ab");
    if(funCliente == NULL){
        printf("\n\tATENCAO o arquivo n�o pode ser aberto");
        getch();
        exit(1);
    }
            struct Cliente clientes;

            printf("Digite os numeros do seu cpf sem pontua��o..: \n");
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
            limparTela();
            funcaoCliente();
        }

}

void consultarCliente() // consulta informa��es sobre clientes cadastrados
{
    funCliente = fopen("Clientes.txt", "rb");
    if(funCliente == NULL){
        printf("\n\tATENCAO o arquivo n�o pode ser aberto");
        getch();
        exit(1);
    }

    struct Cliente clientes;

    int encontrado = 0,cod;

    printf ("\nDigite o numero do seu CPF* sem pontua��o..: \n");
    scanf ("%d", &cod);

    while (fread(&clientes, sizeof(clientes), 1, funCliente))
    {

    printf("Buscando .... \n\n");

        if ((cod == clientes.codigo)  && (clientes.deletar != '*'))
        {
            printf("Usuario..: %d \nNome..: %-8s \nSalario..: R$ %4.2f\n", clientes.codigo,clientes.descricaoProduto,clientes.valorProduto);
            encontrado = 1;
            limparTela();
            funcaoCliente();
        }
    }
    if (!encontrado)
    {
        printf("\nPerfil nao cadastrado!!\n");
        limparTela();
        funcaoCliente();
    }
    fclose(funCliente);
}

void excluirCliente() // exclui o cadastro de um usu�rio como cliente
{
   funCliente = fopen("Clientes.txt", "r+b");
    if(funCliente == NULL){
        printf("\n\tATENCAO o arquivo n�o pode ser aberto");
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
                funcaoCliente();
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




void alterarCliente() // faz a altera��o de dados de um cliente cadastrado
{
  funCliente = fopen("Clientes.txt", "r+b");
    if(funCliente == NULL){
        printf("\n\tATENCAO o arquivo n�o pode ser aberto");
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


void login() // Valida��o de login de um cliente usu�rio
{
    funCliente = fopen("Clientes.txt", "rb");
    if(funCliente == NULL){
        printf("\n\tATENCAO o arquivo n�o pode ser aberto");
        getch();
        exit(1);
    }

    struct Cliente clientes;

    int encontrado = 0,cod;

    printf ("\nLogin utilize seu CPF para entrar..: \n");
    scanf ("%d", &cod);

    while (fread(&clientes, sizeof(clientes), 1, funCliente))
    {
    system("cls || clean");
    printf("\nVerifincando .... \n\n");

        if ((cod == clientes.codigo)  && (clientes.deletar != '*'))
        {
            printf("Bem Vindo..: %-8s \n",clientes.descricaoProduto);
            gets(clientes.descricaoProduto);
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






void adicionarClientesProdutos() // fun��o para acrescentar informa��o ao cadastro do cliente
{

    int voltar;

    funCliente = fopen("Clientes.txt", "ab");
    if(funCliente == NULL){
        printf("\n\tATENCAO o arquivo n�o pode ser aberto");
        getch();
        exit(1);
    }
            struct Cliente clientes;

            printf("Digite os numeros do seu cpf sem pontua��o..: \n");
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
            system("cls || clean");
            consultaPerfil();
        }

}

void consultarClientesProdutos() // consulta os dados cadastrados do cliente
{
    funCliente = fopen("Clientes.txt", "rb");
    if(funCliente == NULL){
        printf("\n\tATENCAO o arquivo n�o pode ser aberto");
        getch();
        exit(1);
    }

    struct Cliente clientes;

    int encontrado = 0,cod;

    printf ("\nDigite o numero do seu CPF* sem pontua��o..: \n");
    scanf ("%d", &cod);

    while (fread(&clientes, sizeof(clientes), 1, funCliente))
    {

    printf("Buscando .... \n\n");

        if ((cod == clientes.codigo)  && (clientes.deletar != '*'))
        {
            printf("Usuario..: %d \nNome..: %-8s \nSalario..: R$ %4.2f\n", clientes.codigo,clientes.descricaoProduto,clientes.valorProduto);
            encontrado = 1;
            system("pause>nul");
            system("cls || clean");
            consultaPerfil();
        }
    }
    if (!encontrado)
    {
        printf("\nPerfil nao cadastrado!!\n");
        system("pause");
        system("cls || clean");
       consultaPerfil();
    }
    fclose(funCliente);
}

void excluirClientesProdutos() // apaga os dados do cliente cadastrado
{
   funCliente = fopen("Clientes.txt", "r+b");
    if(funCliente == NULL){
        printf("\n\tATENCAO o arquivo n�o pode ser aberto");
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




void alterarClientesProdutos() // altera os dados do cliente cadastrado
{
  funCliente = fopen("Clientes.txt", "r+b");
    if(funCliente == NULL){
        printf("\n\tATENCAO o arquivo n�o pode ser aberto");
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


// fun��es abaixo criadas para CRUD DOS FUNCIONARIOS

void consultarClienteFuncionarioRecepcao() // consulta informa��es sobre clientes cadastrados
{
    funCliente = fopen("Clientes.txt", "rb");
    if(funCliente == NULL){
        printf("\n\tATENCAO o arquivo n�o pode ser aberto");
        getch();
        exit(1);
    }

    struct Cliente clientes;

    int encontrado = 0,cod;

    printf ("\nDigite o numero do seu CPF* sem pontua��o..: \n");
    scanf ("%d", &cod);

    while (fread(&clientes, sizeof(clientes), 1, funCliente))
    {

    printf("Buscando .... \n\n");

        if ((cod == clientes.codigo)  && (clientes.deletar != '*'))
        {
            printf("Usuario..: %d \nNome..: %-8s \nSalario..: R$ %4.2f\n", clientes.codigo,clientes.descricaoProduto,clientes.valorProduto);
            encontrado = 1;
            limparTela();
            recepcao();
        }
    }
    if (!encontrado)
    {
        printf("\nPerfil nao cadastrado!!\n");
        limparTela();
        recepcao();
    }
    fclose(funCliente);
}

void excluirClienteFuncionarioRecepcao() // exclui o cadastro de um usu�rio como cliente
{
   funCliente = fopen("Clientes.txt", "r+b");
    if(funCliente == NULL){
        printf("\n\tATENCAO o arquivo n�o pode ser aberto");
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
                recepcao();
            }
        }
    }
    if (!encontrado)
    {
        printf ("\nPerfil nao cadastrado!!\n");
        limparTela();
        recepcao();
    }
    fclose(funCliente);
}

void alterarClienteFuncionariosRecepcao() // faz a altera��o de dados de um cliente cadastrado
{
  funCliente = fopen("Clientes.txt", "r+b");
    if(funCliente == NULL){
        printf("\n\tATENCAO o arquivo n�o pode ser aberto");
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
            recepcao();
        }
    }
    if (!encontrado)
    {
        printf("\nCodigo nao cadastrado!!\n");
        limparTela();
        recepcao();
    }
    fclose(funCliente);
}


// fun��es ACIMA criadas para CRUD DOS FUNCIONARIOS


// fun��es abaixo criadas para CRUD DO ADM

void adicionarClienteADM() // faz o cadastro do usu�rio como cliente
{

    int voltar;

    funCliente = fopen("Clientes.txt", "ab");
    if(funCliente == NULL){
        printf("\n\tATENCAO o arquivo n�o pode ser aberto");
        getch();
        exit(1);
    }
            struct Cliente clientes;

            printf("Digite os numeros do seu cpf sem pontua��o..: \n");
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
            limparTela();
            perfilClienteADM();
        }

}

void consultarClienteADM() // consulta informa��es sobre clientes cadastrados
{
    funCliente = fopen("Clientes.txt", "rb");
    if(funCliente == NULL){
        printf("\n\tATENCAO o arquivo n�o pode ser aberto");
        getch();
        exit(1);
    }

    struct Cliente clientes;

    int encontrado = 0,cod;

    printf ("\nDigite o numero do seu CPF* sem pontua��o..: \n");
    scanf ("%d", &cod);

    while (fread(&clientes, sizeof(clientes), 1, funCliente))
    {

    printf("Buscando .... \n\n");

        if ((cod == clientes.codigo)  && (clientes.deletar != '*'))
        {
            printf("Usuario..: %d \nNome..: %-8s \nSalario..: R$ %4.2f\n", clientes.codigo,clientes.descricaoProduto,clientes.valorProduto);
            encontrado = 1;
            limparTela();
           perfilClienteADM();

        }
    }
    if (!encontrado)
    {
        printf("\nPerfil nao cadastrado!!\n");
        limparTela();
        perfilClienteADM();
    }
    fclose(funCliente);
}

void excluirClienteADM() // exclui o cadastro de um usu�rio como cliente
{
   funCliente = fopen("Clientes.txt", "r+b");
    if(funCliente == NULL){
        printf("\n\tATENCAO o arquivo n�o pode ser aberto");
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
                system("pause");
                perfilClienteADM();
            }
            else if (certeza == 'n')
            {
                system("cls || clear");
                perfilClienteADM();
            }
        }
    }
    if (!encontrado)
    {
        printf ("\nPerfil nao cadastrado!!\n");
        limparTela();
        perfilClienteADM();
    }
    fclose(funCliente);
}

void alterarClienteADM() // faz a altera��o de dados de um cliente cadastrado
{
  funCliente = fopen("Clientes.txt", "r+b");
    if(funCliente == NULL){
        printf("\n\tATENCAO o arquivo n�o pode ser aberto");
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
            perfilClienteADM();
        }
    }
    if (!encontrado)
    {
        printf("\nCodigo nao cadastrado!!\n");
        limparTela();
       perfilClienteADM();
    }
    fclose(funCliente);
}
