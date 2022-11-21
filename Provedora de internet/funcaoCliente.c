#include "funcaoCliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define TAMANHO 100

    struct Cliente{
    int  usuario;
    char login[20];
    char senha[20];
    char nome[30];
    char cpf[14];
    char email[80];
    char telefone[20];
    char rua[50];
    char bairro[50];
    char cep[9];
    char numero[20];
    };

    FILE *funCliente;

void funcaoCliente()
{

    int cliente;
    char login[30], senha[30];

    printf("\n\tSelecionado o perfil cliente !!!\n\n");
        printf("1. Login\n");
        printf("2. Cadastro\n");
        printf("3. Esqueceu Senha ?\n");
        printf("0.Voltar ao Menu\n");
        scanf("%i",&cliente);
    switch(cliente)
    {
    case 1:
         loginCliente();
        break;
    case 2:
        cadastroCliente();
        break;
    case 3:
        alterarClienteDados();
        break;
    case 0:
        limparTela();
        FuncoesMenuInicial();
        break;

    default:
        printf("selecione uma opção valida");

    }
}




void loginCliente()
{
    char login[20];
    char senha[20];
    int contador;

    funCliente =fopen("Clientes.txt", "rb");
     if(funCliente == NULL)
    {
        printf("Desculpe arquivo não encontrado");
        funcaoCliente();
    }

    printf("\nLogin: ");
    scanf("%s",&login);
    printf("Senha: ");
    scanf("%s",&senha);

    struct Cliente clientes;

    while(fread (&clientes, sizeof(clientes) ,1,funCliente))
    {
        printf("\nValidando Acesso...   \n");
        if((login == clientes.login) && (senha == clientes.senha))
        {
             printf("\nSucesso!");
             limparTela();
             printf("\nBem vindo...: %s",clientes.nome);
             telaCliente();
        }
    }
    if(contador==0)
    {
        tentarNovamente();
    }

fclose(funCliente);
}





void tentarNovamente()
{
    char tentativas;
        int i;
        printf("\nNenhum resultado encontrado\nTentar novamente S/N...: ");
        scanf("%s",&tentativas);
                if(tentativas == 's' || tentativas == 'S' && tentativas!= 'n' && tentativas!= 'N')
                {
                  loginCliente();

                }
                else if(tentativas == 'n' || tentativas == 'N')
                  {
                      printf("\nSaindo da tela de login.....\n");
                      limparTela();
                      funcaoCliente();
                  }
                else if (tentativas != 's' && tentativas != 'S' && tentativas!= 'n' && tentativas!= 'N'){
                    printf("Opção invalída !!!\n");
                    tentarNovamente();
                }
}

void cadastroCliente()
{
    int contador=0, voltar;

    struct Cliente clientes;

    funCliente =fopen("Clientes.txt", "ab");
    if(funCliente == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }
            limparTela();
            printf("\tCADASTRO DE USUÁRIO\n\n");
            printf("Digite um nome para login..: \n");
            fflush(stdin);
            gets(clientes.login);
            printf("Digite uma senha..: \n");
            fflush(stdin);
            gets(clientes.senha);
            printf("Digite seu nome completo..: \n");
            fflush(stdin);
            gets(clientes.nome);
            printf("Digite seu cpf..: \n");
            fflush(stdin);
            gets(clientes.cpf);
            printf("Digite seu e-mail..: \n");
            fflush(stdin);
            gets(clientes.email);
            printf("Digite seu telefone..: \n");
            fflush(stdin);
            gets(clientes.telefone);
            printf("Digite o nome da sua rua..: \n");
            fflush(stdin);
            gets(clientes.rua);
            printf("Digite o numero..: \n");
            fflush(stdin);
            gets(clientes.numero);
            printf("Digite o bairro..: \n");
            fflush(stdin);
            gets(clientes.bairro);
            printf("Digite o cep..: \n");
            fflush(stdin);
            gets(clientes.cep);


    voltar = fwrite (&clientes, sizeof(clientes) ,1,funCliente);

    if(voltar == 1)
        {
            printf("\nINFO. GRAVADAS COM SUCESSO!\n");
            limparTela();
            funcaoCliente();
        }
    fclose(funCliente);
}



void alterarClienteDados()
{
   funCliente =fopen("Clientes.txt", "r+b");
    if(funCliente == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }

     struct Cliente clientes;

    int encontrado = 0;
    char log[20];

    printf ("\nDigite o Cpf..: \n");
    scanf ("%s", &log);

    while (fread (&clientes, sizeof(clientes), 1, funCliente))
    {
        if (log == clientes.cpf)
        {
            printf("login..: %s \n",clientes.nome);
            encontrado = 1;

            fseek(funCliente,sizeof(struct Cliente)*-1, SEEK_CUR);
            printf("\nDigite uma nova senha..:\n");
            fflush(stdin);
            gets(clientes.senha);
            fwrite(&clientes, sizeof(clientes), 1, funCliente);
            fseek(funCliente, sizeof(clientes)* 0, SEEK_END);

            printf("\n Dados alterados com sucesso!");
            limparTela();
            funcaoCliente();
        }
    }
    if (!encontrado)
    {
        printf("\nCodigo nao cadastrado!!\n");
        funcaoCliente();
    }
    fclose(funCliente);
}
