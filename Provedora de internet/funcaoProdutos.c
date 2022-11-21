#include "funcaoCliente.h"
#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>


int opcao=0;

 typedef struct Produto{
    int codigo;
    char nomeProduto;
    float valorProduto;
    char descricaoProduto[50];
    int funcionario;
    char deletar;
    }produtos;



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










void requisitarProduto()
{
    int opcao=0;

    funProduto = fopen("Produtos e Serviços.txt", "r");
    if(funProduto == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }

    printf("\t\tPacotes e Serviços\n\n\n");
    printf("1. produto1\n");
    printf("2. produto2\n");
    printf("3. produto3\n");

    fclose(funProduto);
}
