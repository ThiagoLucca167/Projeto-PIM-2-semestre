#include "funcaoCliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define TAMANHO 100

    typedef struct funcionariosArq{
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
    }funcionarios;


    static int quantidade = 0;
    funcionarios maximo[TAMANHO];

    FILE *funFuncionarios;

void funcaoFuncionarios()
{

    int funcionarios;
    char login[30], senha[30];
    system("cls || clear");
    printf("\n\tSelecionado o perfil funcinario !!!\n\n");
        printf("1.Cadastro\n");
        printf("2.Login\n");
        printf("3.Login de ADMIM\n");
        printf("4.Voltar ao Menu\n");
        scanf("%i",&funcionarios);
    switch(funcionarios)
    {
    case 1:

        cadastroFuncionario();
        break;
    case 2:
        loginFuncionario();
        break;
    case 3:
        loginAdm();
        break;
    case 4:
        limparTela();
        telaInicial();
        break;

    default:
        printf("selecione uma op��o valida");

    }
}

void loginAdm()
{
    char login;
    char senha;
    char loginAdm1="Matheus";
    char senhaAdm1="boraBill";
    char loginAdm2="Thiago";
    char senhaAdm2="boraFiDoBill";

    printf("\nOl� ADM...:\n");
    printf("Login: ");
    scanf("%s",&login);
    printf("\nSenha: ");
    scanf("%s",&senha);

    if(strcmp(login,loginAdm1)==0 || strcmp(login,loginAdm2)==0 && strcmp(senha,senhaAdm1)==0 || strcmp(senha,senhaAdm2)==0)
    {
        printf("Logado meu chapas sadokoskadodkdoksa");
    }
    else
    {
        printf("Infelizmente n�o foi dessa vez meu chapas kaskdkaakkka");
    }
}
void loginFuncionario()
{
    char login[100];
    char senha[100];
    int voltar=1, contador=0, p=0;

    funFuncionarios =fopen("Funcionarios.txt", "r");
     if(funFuncionarios == NULL)
    {
        printf("Desculpe arquivo n�o encontrado");
    }


    printf("Login: ");
    gets(login);
    gets(login);
     printf("Senha ");
    gets(senha);


    voltar = fread (&maximo[contador].login, sizeof(funcionarios) ,1,funFuncionarios);

    while(voltar == 1)
    {
        if(strcmp(login,maximo[p].login)==0 && strcmp(senha,maximo[p].senha)==0)
        {
             limparTela();
             contador++;
             telaFuncionario();
        }
        p++;
        voltar = fread (&maximo[p].login, sizeof(funcionarios) ,1,funFuncionarios);
    }
    if(contador==0)
    {
        tentarNovamente();
    }

fclose(funFuncionarios);
}





void cadastroFuncionario()
{
    adicionarF();
}


void adicionarF()
{
    int contador=0, voltar;



    funFuncionarios =fopen("Funcionarios.txt", "a");
    if(funFuncionarios == NULL){
        printf("\n\tATENCAO o arquivo n�o pode ser aberto");
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
            printf("SELECIONE UM NOME DE USU�RIO: ");
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
            printf("\n\tENDERE�O...: \n");
            printf("RUA: ");
            gets(maximo[contador].rua);
            printf("Numero e Complemento caso tenha: ");
            gets(maximo[contador].numero);
            printf("Bairro: ");
            gets(maximo[contador].bairro);
            printf("CEP: ");
            gets(maximo[contador].cep);
          }
          voltar = fwrite (&maximo[contador], sizeof(funcionarios) ,1,funFuncionarios);

          if(voltar == 1)
        {
            printf("\nINFO. GRAVADAS COM SUCESSO!\n");
            exit(i);

        }
        }



         exit(contador);

    }
    fclose(funFuncionarios);
}
