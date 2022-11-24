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
    char nomeUsuario[50];
    float valorProduto;
    char descricaoProduto[50];
    int funcionario;
    char deletar;
    };

    FILE *funProduto;

void produtosRequisitado()
{
    funProduto = fopen("Clientes Produtos solicitados.txt", "rb");
    if(funProduto == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }
    struct Produto produtos;

    int encontrado = 0, cod;

    printf("Informe o cpf do Cliente: ");
    scanf("%i", &cod);

    while(fread(&produtos, sizeof(produtos), 1, funProduto))
    {
        if ((cod == produtos.cpf)  && (produtos.deletar != '*'))
            {
            printf("Usuário..: %s\n", produtos.nomeUsuario);
            printf("CPF..: %d \nCodigo %d \nDescricao: %-8s \nValor R$ %4.2f\n\n",produtos.cpf,produtos.codigo, produtos.descricaoProduto, produtos.valorProduto);
            encontrado = 1;
                system("pause>nul");
                system("cls || clean");
                operacao();
            }
    }
    if (!encontrado)
    {
        printf ("\nNão há pedidos no momento!!\n");
        system("pause>nul");
        operacao();
    }
    fclose(funProduto);
}
