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
    char descricaoProduto[300];
    int funcionario[10];
    }produtos;


    produtos maximo[TAMANHO];
    FILE *funProduto;


void adicionarProduto()
{
    int contador=0, voltar;

    funProduto = fopen("Produtos e Serviços.txt", "a");
    if(funProduto == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }

    while (contador < TAMANHO)
    {
            gets(maximo[contador].funcionario);
            printf("\t\tCadastro de novos produtos.\n\n\n");
            printf("Nome do Produto: ");
            gets(maximo[contador].nomeProduto);
            printf("Valor do Produto: ");
            gets(maximo[contador].valorProduto);
            printf("Descrição do Produto: ");
            gets(maximo[contador].descricaoProduto);

    voltar = fwrite (&maximo[contador], sizeof(produtos) ,1,funProduto);

    if(voltar == 1)
        {
            printf("\nINFO. GRAVADAS COM SUCESSO!\n");
        }

    exit(contador);
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


}


    fclose(funProduto);
}
