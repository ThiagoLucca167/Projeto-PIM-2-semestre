#include "funcaoCliente.h"
#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>
    struct Produto{
    int cpf;
    int codigo;
    char nomeProduto;
    float valorProduto;
    char descricaoProduto[50];
    int funcionario;
    char deletar;
    };


    FILE *funProduto;


void adicionarProduto()
{

    int voltar;

    funProduto = fopen("Produtos.txt", "ab");
    if(funProduto == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }
            struct Produto produtos;

            printf("Digite o codigo do produto: \n");
            scanf("%d", &produtos.codigo);
            printf("Digite a descricao do produto: \n");
            fflush(stdin);
            gets(produtos.descricaoProduto);
            printf("Digite o valor do produto: \n");
            scanf("%f", &produtos.valorProduto);

    voltar = fwrite (&produtos, sizeof(produtos) ,1,funProduto);

    if(voltar == 1)
        {
            printf("\nINFO. GRAVADAS COM SUCESSO!\n");
            system("pause");
        }
    fclose(funProduto);
}

void consultarProduto()
{
    funProduto = fopen("Produtos.txt", "rb");
    if(funProduto == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }

    struct Produto produtos;

    int encontrado = 0,cod;

    printf ("\nDigite o Codigo do produto que procura: \n");
    scanf ("%d", &cod);

    while (fread(&produtos, sizeof(produtos), 1, funProduto))
    {

    printf("Buscando ....    \n");

        if ((cod == produtos.codigo)  && (produtos.deletar != '*'))
        {
            printf("Codigo..: %d \nDescricao..: %-8s \nValor..: R$ %4.2f\n", produtos.codigo,produtos.descricaoProduto,produtos.valorProduto);
            encontrado = 1;
            system("pause>nul");
        }
    }
    if (!encontrado)
    {
        printf("\nCodigo nao cadastrado!!\n");
        system("pause");
        operacao();
    }
    fclose(funProduto);
}

void excluirProduto()
{
   funProduto = fopen("Produtos.txt", "r+b");
    if(funProduto == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }

    struct Produto produtos;

    int cod, encontrado = 0;
    char certeza;
    printf ("\nDigite o codigo que deseja EXCLUIR: \n");
    scanf ("%d", &cod);

    while (fread (&produtos, sizeof(produtos), 1, funProduto))
    {
        if (cod == produtos.codigo)
        {
            printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n\n",produtos.codigo, produtos.descricaoProduto, produtos.valorProduto);
            encontrado = 1;

            printf("\nTem certeza que quer excluir este produto? s/n \n");
            fflush(stdin);
            scanf("%c", &certeza);
            if (certeza == 's')
            {
                produtos.deletar = '*';
                fseek(funProduto,sizeof(struct Produto)*-1, SEEK_CUR);
                fwrite(&produtos, sizeof(produtos), 1, funProduto);
                fseek(funProduto, sizeof(produtos)* 0, SEEK_END);
                printf("\nProduto excluido com Sucesso! \n");
                system("pause>nul");
            }
            else if (certeza == 'n')
            {
                system("cls || clear");
            }
        }
    }
    if (!encontrado)
    {
        printf ("\nCodigo nao cadastrado!!\n");
        system("pause>nul");
    }
    fclose(funProduto);
}




void alterarProduto()
{
  funProduto = fopen("Produtos.txt", "r+b");
    if(funProduto == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }

    struct Produto produtos;
    int cod, encontrado = 0;
    printf ("\nDigite o codigo que deseja alterar: \n");
    scanf ("%d", &cod);

    while (fread (&produtos, sizeof(produtos), 1, funProduto))
    {
        if (cod == produtos.codigo)
        {
            printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n\n",produtos.codigo, produtos.descricaoProduto, produtos.valorProduto);
            encontrado = 1;

            fseek(funProduto,sizeof(struct Produto)*-1, SEEK_CUR);
            printf("\nDigite a nova descricao: \n");
            fflush(stdin);
            gets(produtos.descricaoProduto);
            printf("\nDigite o novo preco....: \n");
            scanf("%f", &produtos.valorProduto);

            fwrite(&produtos, sizeof(produtos), 1, funProduto);
            fseek(funProduto, sizeof(produtos)* 0, SEEK_END);

            printf("\n Dados do produto alterados com sucesso!");
            system("pause>nul");
        }
    }
    if (!encontrado)
    {
        printf("\nCodigo nao cadastrado!!\n");
    }
    fclose(funProduto);
}







void consultarProdutoClientes()
{
     funProduto = fopen("Produtos.txt", "rb");
    if(funProduto == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }

    struct Produto produtos;

    int encontrado = 0;
    char i;

    printf("Ver produtos ? S ou N");
    scanf("%s",&i);

    if(i =='S' || i=='s')
    {
        int encontrado = 0;
        printf ("\nEsses são os produtos que estão disponiveis..: \n");

    while (fread(&produtos, sizeof(produtos), 1, funProduto))
    {
           if(encontrado==0)
           {
            printf("Procurando ....    \n");
            printf("Codigo..: %d \nDescricao..: %-8s \nValor..: R$ %4.2f\n", produtos.codigo,produtos.descricaoProduto,produtos.valorProduto);
           }
    }

    if (!encontrado)
    {
        printf("Produtos nao encontrados !!!");
        system("pause");
        consultarProdutosCli();
    }
    fclose(funProduto);
    }
    else if(i=='n' || i=='N')
    {
        printf("\nSaindo...\n");
        system("pause");
        consultarProdutosCli();
    }
    else
    {
        printf("Opção invalida !!!");
        limparTela();
        consultarProdutoClientes();
    }
}












void adicionarProdutoSolicitados()
{
    funProduto = fopen("Produtos.txt", "rb");
    if(funProduto == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }
    struct Produto produtos;
    int encontrado=0;
    while (fread(&produtos, sizeof(produtos), 1, funProduto))
    {
           if(encontrado==0)
           {
            printf("Procurando ....    \n");
            printf("Codigo..: %d \nDescricao..: %-8s \nValor..: R$ %4.2f\n", produtos.codigo,produtos.descricaoProduto,produtos.valorProduto);
           }
    }
    fclose(funProduto);
    int voltar;

    funProduto = fopen("Clientes Produtos solicitados.txt", "ab");
    if(funProduto == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }
            printf("Confirme seu CPF..:\n");
            scanf("%d", &produtos.cpf);
            printf("Confirme o codigo do produto..:\n");
            scanf("%d", &produtos.codigo);


    voltar = fwrite (&produtos, sizeof(produtos) ,1,funProduto);

    if(voltar == 1)
        {
            printf("\nINFO. GRAVADAS COM SUCESSO!\n");
            system("pause");
        }
    fclose(funProduto);
    consultarProdutosCli();
}







void cancelarProduto()
{
   funProduto = fopen("Clientes Produtos solicitados.txt", "r+b");
    if(funProduto == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }

    struct Produto produtos;

    int cod, encontrado = 0;
    char certeza;
    printf ("\nDigite o cpf para verificar cancelar os produtos..: \n");
    scanf ("%d", &cod);

    while (fread (&produtos, sizeof(produtos), 1, funProduto))
    {
        if (cod == produtos.cpf)
        {
            printf("Usuário..: %d \nCodigo %d \nDescricao: %-8s \nValor R$ %4.2f\n\n",produtos.cpf,produtos.codigo, produtos.descricaoProduto, produtos.valorProduto);
            encontrado = 1;

            printf("\nTem certeza que quer cancelar este produto? s/n \n");
            fflush(stdin);
            scanf("%c", &certeza);
            if (certeza == 's')
            {
                produtos.deletar = '*';
                fseek(funProduto,sizeof(struct Produto)*-1, SEEK_CUR);
                fwrite(&produtos, sizeof(produtos), 1, funProduto);
                fseek(funProduto, sizeof(produtos)* 0, SEEK_END);
                printf("\nProduto excluido com Sucesso! \n");
                system("pause>nul");
                consultarProdutosCli();
            }
            else if (certeza == 'n')
            {
                system("cls || clear");
                consultarProdutosCli();
            }
        }
    }
    if (!encontrado)
    {
        printf ("\nCodigo nao cadastrado!!\n");
        system("pause>nul");
        consultarProdutosCli();
    }
    fclose(funProduto);
}
