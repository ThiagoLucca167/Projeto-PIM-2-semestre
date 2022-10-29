#include "funcaoCliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define TAMANHO 100

    typedef struct clientesArq{
    int usuario[100];
    char nome[30];
    char cpf[14];
    char email[80];
    char telefone[20];
    char rua[50];
    char bairro[50];
    char cep[9];
    char numero[20];
    char login[20];
    char senha[20];
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
    char login[15];
    char senha[15];

    printf("Digite o Login: ");
    scanf("%s", &login);

    printf("Digite a Senha: ");
    scanf("%s", &senha);

    if (strcmp(login, maximo[TAMANHO].login) == 0 && strcmp(senha,  maximo[TAMANHO].senha) == 0)

        printf("\n\nLOGADO!\n\n");

    else

        printf("\n\nDADOS INVALIDOS!\n\n");



}

void cadastroCliente()
{
    adicionar();
}

void adicionar()
{
    int contador=0, voltar;

    funCliente =fopen("Clientes.txt", "a");
    if(funCliente == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }
    while (contador < TAMANHO)
    {
        printf("VAMOS DAR INICIO NO CADASTRO\n");
        gets(maximo[contador].usuario);
        if(maximo[contador].usuario)
        {
          int i = 0;

          for(i=1;i <=1;i++)
          {
            fprintf(funCliente,"\n\nUsuario de numero: %d \n",rand() % 1000); // gerar um numero aleatorio para o usuario
            printf("\n\tCADASTRO...: \n");
            printf("SELECIONE UM NOME DE USUÁRIO: ");
            gets(maximo[contador].login);
            fprintf(funCliente,"Usuário: %s\n",maximo[contador].login);
            printf("SENHA: ");
            gets(maximo[contador].senha);
            fprintf(funCliente,"Senha: %s\n",maximo[contador].senha);
            printf("Digite seu Nome: ");
            gets(maximo[contador].nome);
            fprintf(funCliente,"Nome: %s\n",maximo[contador].nome);
            printf("Digite seu CPF: ");
            gets(maximo[contador].cpf);
            fprintf(funCliente,"CPF: %s\n",maximo[contador].cpf);
            printf("Digite seu E-mail: ");
            gets(maximo[contador].email);
            fprintf(funCliente,"E-mail: %s\n",maximo[contador].email);
            printf("Telefone : ");
            gets(maximo[contador].telefone);
            fprintf(funCliente,"Telefone: %s\n",maximo[contador].telefone);
            printf("\n\tENDEREÇO...: \n");
            printf("RUA: ");
            gets(maximo[contador].rua);
            fprintf(funCliente,"Rua: %s\n",maximo[contador].rua);
            printf("Numero e Complemento caso tenha: ");
            gets(maximo[contador].numero);
            fprintf(funCliente,"Numero: %s\n",maximo[contador].numero);
            printf("Bairro: ");
            gets(maximo[contador].bairro);
            fprintf(funCliente,"Bairro: %s\n",maximo[contador].bairro);
            printf("CEP: ");
            gets(maximo[contador].cep);
            fprintf(funCliente,"Cep: %s\n",maximo[contador].cep);

          }
          if(i != NULL)
        {
            printf("\nINFO. GRAVADAS COM SUCESSO!\n");
            exit(i);

        }
        }



         exit(contador);

    }
    fclose(funCliente);
}
