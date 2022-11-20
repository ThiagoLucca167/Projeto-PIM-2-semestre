#include "funcaoCliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define TAMANHO 100

int opcao=0;

 struct Produto{
    int codigo[5];
    char nomeProduto[10];
    float valorProduto;
    char descricaoProduto[50];
    int funcionario;
    char deletar;
    };



    FILE *funProduto;


void adicionarProduto()
{
    struct Produto produtos;
    int voltar;

    funProduto = fopen("Produtos.txt", "a");
    if(funProduto == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }

            gets(&produtos.funcionario);
            printf("\t\tCadastro de novos produtos.\n\n\n");
            printf("Codigo do Produto: ");
            gets(&produtos.codigo);
            fprintf(funProduto,"\n");
            printf("Valor do Produto: ");
            gets(&produtos.valorProduto);
            printf("Descrição do Produto: ");
            gets(&produtos.descricaoProduto);


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
    funProduto = fopen("Produtos.txt", "r");
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
        printf("WHILE");
        if (strcmp(cod,produtos.codigo) == 0)
        {
            printf("Codigo: %d --- Descricao: %-8s --- Valor R$ %4.2f\n", produtos.codigo,produtos.descricaoProduto,produtos.valorProduto);
            encontrado = 1;
            system("pause>nul");
        }
    }
    if (!encontrado)
    {
        printf("\nCodigo nao cadastrado!!\n");
        system("pause");
    }
    fclose(funProduto);
}

void excluirProduto()
{
    struct Produto produtos;
    funProduto = fopen("Produtos.txt", "r+b");
    if (funProduto == NULL)
    {
       printf("Arquivo inexistente!");
        system("pause>nul");
        system("cls || clear");

    }

    int encontrado = 0;
    char certeza, nome;
    printf ("\nDigite o codigo que deseja EXCLUIR: \n");
    scanf ("%s", &nome);

    while (fread (&produtos, sizeof(produtos), 1, funProduto))
    {
        if (nome == &produtos.codigo)
        {
            printf("Produto: %s --- Descricao: %-8s --- Valor R$ %4.2f\n\n",produtos.nomeProduto,produtos.descricaoProduto,produtos.valorProduto);
            encontrado = 1;

            printf("\nTem certeza que quer excluir este produto? s/n \n");
            fflush(stdin);
            scanf("%c", &certeza);
            if (certeza == 's')
            {
                produtos.deletar = '*';
                fseek(funProduto,sizeof(produtos)*-1, SEEK_CUR);
                fwrite(&funProduto, sizeof(produtos), 1, funProduto);
                fseek(funProduto, sizeof(produtos)* 0, SEEK_END);
                printf("\nProduto excluido com Sucesso! \n");
                system("pause>nul");
                system("cls || clear");
                operacao();
            }
            else if (certeza == 'n')
            {
                system("cls || clear");
                operacao();
            }
        }
    }
    if (!encontrado)
    {
        printf ("\nCodigo nao cadastrado!!\n");
        system("pause>nul");
        system("cls || clear");
        operacao();
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
