#include "funcaoCliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define TAMANHO 100

    typedef struct clientesArq{
    char login[20];
    char senha[20];
    int usuario[100];
    char nome[30];
    char cpf[14];
    char email[80];
    char telefone[20];
    char rua[50];
    char bairro[50];
    char cep[9];
    char numero[20];
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
    char login[100];
    char senha[100];
    char str1[100];
    char str2[100];
    int contador=0;

    printf("Login: ");
    scanf("%s",&login);
    printf("senha: ");
    scanf("%s",&senha);

    funCliente =fopen("Clientes.txt", "r");
     if(funCliente == NULL)
    {
        printf("Desculpe arquivo não encontrado");
    }

    while(fgets(login,100,funCliente) != NULL)
    {
        if(strcmp(login,maximo[TAMANHO].login) && strcmp(senha,maximo[TAMANHO].login) != 0){

            printf("logado");
        }else
        {
            printf("nao logado");
        }
    }

printf("NAO LOGADO");



fclose(funCliente);
}





void cadastroCliente()
{
    adicionar();
}

void consultar()
{
    int voltar,contador=0,t;
    char nome[30];



        fclose(funCliente);
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
            printf("\n\tCADASTRO...: \n");
            printf("SELECIONE UM NOME DE USUÁRIO: ");
            gets(maximo[contador].login);
            printf("SENHA: ");
            gets(maximo[contador].senha);
            printf("Digite seu Nome: ");
            gets(maximo[contador].nome);
            printf("Digite seu CPF: ");
            gets(maximo[contador].cpf);
            printf("Digite seu E-mail: ");
            gets(maximo[contador].email);
            printf("Telefone : ");
            gets(maximo[contador].telefone);
            printf("\n\tENDEREÇO...: \n");
            printf("RUA: ");
            gets(maximo[contador].rua);

            printf("Numero e Complemento caso tenha: ");
            gets(maximo[contador].numero);

            printf("Bairro: ");
            gets(maximo[contador].bairro);

            printf("CEP: ");
            gets(maximo[contador].cep);


          }
          voltar = fwrite (&maximo[contador], sizeof(clientes) ,1,funCliente);

          if(voltar == 1)
        {
            printf("\nINFO. GRAVADAS COM SUCESSO!\n");
            exit(i);

        }
        }



         exit(contador);

    }
    fclose(funCliente);
}
