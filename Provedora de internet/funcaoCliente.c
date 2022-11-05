#include "funcaoCliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define TAMANHO 100

    typedef struct usuariosArq{
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
    }usuarios;


    static int quantidade = 0;
    usuarios maximo[TAMANHO];

    FILE *funUsuarios;


void loginUsuario(const char* usuario)
{
    if(usuario == "Cliente") // <----- ERRO AQUI!!!! quando tenta comparar as strings o codigo da erro e termina. não consegui resolver o problema  obs.: strcomp() tambem da erro
    {
        funUsuarios = fopen("Clientes.txt", "r"); // cadastro só de clientes
            if(funUsuarios == NULL)
            {
                printf("Desculpe arquivo não encontrado");
            }
        validarLogin();
    }
    if(usuario == "Funcionario") // <--- ERRO AQUI!!!
    {
        funUsuarios = fopen("Funcionarios.txt", "r"); // cadastro só de funcionários
            if(funUsuarios == NULL)
            {
                printf("Desculpe arquivo não encontrado");
            }
        validarLogin();
    }


fclose(funUsuarios);
}


void validarLogin()
{
    char login[100];
    char senha[100];
    int voltar=1, contador=0, p=0;

    printf("Login: ");
    gets(login);
     printf("Senha ");
    gets(senha);


    voltar = fread (&maximo[contador].login, sizeof(usuarios) ,1,funUsuarios);

    while(voltar == 1)
    {
        if(strcmp(login,maximo[p].login)==0 && strcmp(senha,maximo[p].senha)==0)
        {
             printf("\n Bem vindo...: %s",maximo[p].login);
             contador++;
        }
        p++;
        voltar = fread (&maximo[p].login, sizeof(usuarios) ,1,funUsuarios);
    }
    if(contador==0)
    {
        printf("Nenhum resultado encontrado");
    }
    getch();
    exit(1);

}


void cadastroUsuario(const char* usuario)
{
    if(usuario == "Cliente") // <-- ERRO AQUI
    {
        funUsuarios = fopen("Clientes.txt", "a");
            if(funUsuarios == NULL)
            {
                printf("Desculpe arquivo não encontrado");
            }
        adicionar();
    }
    if(usuario == "Funcionario") // <-- ERRO AQUI
    {
        funUsuarios = fopen("Funcionarios.txt", "a");
            if(funUsuarios == NULL)
            {
                printf("Desculpe arquivo não encontrado");
            }
        adicionar();
    }
}

void consultar()
{
    int voltar,contador=0,t;
    char nome[30];



        fclose(funUsuarios);
}

void adicionar()
{
    int contador=0, voltar;

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
          voltar = fwrite (&maximo[contador], sizeof(usuarios) ,1,funUsuarios);

          if(voltar == 1)
        {
            printf("\nINFO. GRAVADAS COM SUCESSO!\n");
            exit(i);

        }
        }



         exit(contador);

    }
    fclose(funUsuarios);
}
