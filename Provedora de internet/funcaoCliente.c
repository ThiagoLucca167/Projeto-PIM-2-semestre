#include "funcaoCliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define TAMANHO 100

    typedef struct clientesArq{
    char nome[50];
    char telefone[20];
    char email[80];
    char usuario[0];
    }clientes;


    static int quantidade = 0;
    clientes maximo[TAMANHO];

    FILE *funCliente;

void funcaoCliente()
{

    int cliente;
    char login[30], senha[30];

    printf("\n\tSelecionado o perfil cliente !!!\n\n");
        printf("1.cadastro\n");
        printf("2.login\n");
        scanf("%i",&cliente);
    switch(cliente)
    {
    case 1:

        cadastroCliente();
        break;
    case 2:
        loginCliente();
        break;
    default:
        printf("selecione uma opção valida");

    }
}

void loginCliente()
{

}

void cadastroCliente()
{
    adicionar();
}

void adicionar()
{
    int contador=0, voltar;
    char opcoes = 's';

    funCliente =fopen("Clientes.txt", "a");
    if(funCliente == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }
    while ((contador < TAMANHO))
    {
        printf("VAMOS DAR INICIO NO CADASTRO\n");
        gets(maximo[contador].usuario);
        printf("Digite seu nome: ");
        gets(maximo[contador].nome);
        printf("Digite seu email: ");
        gets(maximo[contador].email);
        printf("Digite seu numero: ");
        gets(maximo[contador].telefone);

        voltar = fwrite (&maximo[contador], sizeof(clientes) ,1,funCliente);

        if(voltar == 1)
        {
            printf("\nINFO. GRAVADAS COM SUCESSO!");
        }
         exit(opcoes);

    }
    fclose(funCliente);
}
