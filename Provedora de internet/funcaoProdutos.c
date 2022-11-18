#include "funcaoCliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define TAMANHO 100

int opcao=0;

typedef struct produtoServicoArq{
    char nomeProduto[20];
    int valorProduto[20];
    char descricaoProduto[150];
    int funcionario[10];
    char deletar;
    }produtos;


    produtos maximo[TAMANHO];
    FILE *funProduto;


void adicionarProduto()
{
    int contador=0, voltar;

    funProduto = fopen("Produtos.txt", "a");
    if(funProduto == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }

            gets(maximo[contador].funcionario);
            printf("\t\tCadastro de novos produtos.\n\n\n");
            printf("Nome do Produto: ");
            fprintf(funProduto,"\n");
            gets(maximo[contador].nomeProduto);
            printf("Valor do Produto: ");
            gets(maximo[contador].valorProduto);
            printf("Descrição do Produto: ");
            gets(maximo[contador].descricaoProduto);


    voltar = fwrite (&maximo[contador], sizeof(produtos) ,1,funProduto);

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
    int encontrado = 0,contador;
    char nome;
    printf ("\nDigite o nome do produto que procura: \n");
    scanf ("%s", &nome);

    while (fread(&maximo[encontrado], sizeof(produtos), 1, funProduto))
    {
        if (nome == maximo[encontrado].nomeProduto)
        {
            printf("Nome: %s --- Descricao: %-8s --- Valor R$ %4.2f\n", maximo[encontrado].nomeProduto, maximo[encontrado].descricaoProduto, maximo[encontrado].valorProduto);
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

    while (fread (&maximo[encontrado], sizeof(produtos), 1, funProduto))
    {
        if (nome == maximo[encontrado].nomeProduto)
        {
            printf("Produto: %s --- Descricao: %-8s --- Valor R$ %4.2f\n\n",maximo[encontrado].nomeProduto, maximo[encontrado].descricaoProduto, maximo[encontrado].valorProduto);
            encontrado = 1;

            printf("\nTem certeza que quer excluir este produto? s/n \n");
            fflush(stdin);
            scanf("%c", &certeza);
            if (certeza == 's')
            {
                maximo[TAMANHO].deletar = '*';
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
