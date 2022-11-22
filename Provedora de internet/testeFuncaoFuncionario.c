#include "funcaoCliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>

    struct Funcionario{
    char login[50];
    char senha[50];
    int usuario;
    char nome[20];
    char cpf[20];
    char email[50];
    char telefone[20];
    char rua[50];
    char bairro[50];
    char cep[20];
    char numero[20];
    char deletar;
    };

    FILE *funFuncionarios;

void testefuncaoFuncionarios()
{

    int funcionarios;
    char login, senha;
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
        printf("selecione uma opção valida");

    }
}

void testeloginAdm()
{
    char login;
    char senha;
    char loginAdm1="Matheus";
    char senhaAdm1="boraBill";
    char loginAdm2="Thiago";
    char senhaAdm2="boraFiDoBill";

    printf("\nOlá ADM...:\n");
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
        printf("Infelizmente não foi dessa vez meu chapas kaskdkaakkka");
    }
}
void testeloginFuncionario()
{
    char login, senha;
    struct Funcionario funcionarios;
    int encontrado=0;

    funFuncionarios =fopen("Funcionarios.txt", "r");
     if(funFuncionarios == NULL)
    {
        printf("Desculpe arquivo não encontrado");
    }


    printf("Login: ");
    scanf("%s", &login);

    printf("Senha ");
    scanf("%s", &senha);


    while(fread (&funcionarios, sizeof(funcionarios) ,1,funFuncionarios))
    {
        if(login == funcionarios.login && senha == funcionarios.senha)
        {
             limparTela();
             encontrado = 1;
             fclose(funFuncionarios);
             telaFuncionario();
        }

    }
    if(!encontrado)
    {
        printf("login ou senha inválida");
    }

fclose(funFuncionarios);
}





void testecadastroFuncionario()
{
    testeadicionarF();
}


void testeadicionarF()
{
    int contador=0, voltar;

    struct Funcionario funcionarios;

    funFuncionarios =fopen("Funcionarios.txt", "a");
    if(funFuncionarios == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }

        printf("VAMOS DAR INICIO NO CADASTRO\n");

            printf("SELECIONE UM NOME DE USUÁRIO: ");
            fflush(stdin);
            gets(funcionarios.login);
            printf("SENHA: ");
            fflush(stdin);
            gets(funcionarios.senha);
            printf("Digite seu Nome: ");
            fflush(stdin);
            gets(funcionarios.nome);
            printf("Digite seu CPF: ");
            fflush(stdin);
            gets(funcionarios.cpf);
            printf("Digite seu E-mail: ");
            fflush(stdin);
            gets(funcionarios.email);
            printf("Telefone : ");
            fflush(stdin);
            gets(funcionarios.telefone);
            printf("\n\tENDEREÇO...: \n");
            printf("RUA: ");
            fflush(stdin);
            gets(funcionarios.rua);
            printf("Numero e Complemento caso tenha: ");
            fflush(stdin);
            gets(funcionarios.numero);
            printf("Bairro: ");
            fflush(stdin);
            gets(funcionarios.bairro);
            printf("CEP: ");
            fflush(stdin);
            gets(funcionarios.cep);

          voltar = fwrite (&funcionarios, sizeof(funcionarios) ,1,funFuncionarios);

        if(voltar == 1)
        {
            printf("\nINFO. GRAVADAS COM SUCESSO!\n");
        }


    fclose(funFuncionarios);
}



void testeconsultarFuncionario()
{
    funFuncionarios = fopen("Funcionarios.txt", "rb");
    if(funFuncionarios == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }

    struct Funcionario funcionarios;

    int encontrado = 0,cod;

    printf ("\nDigite o CPF do Funcionario: \n");
    scanf ("%d", &cod);

    while (fread(&funcionarios, sizeof(funcionarios), 1, funFuncionarios))
    {

    printf("Buscando ....    \n");

        if ((cod == funcionarios.cpf)  && (funcionarios.deletar != '*'))
        {
            printf("Nome..: %s \nCPF..: %s \nEmail..: %s\n", funcionarios.nome, funcionarios.cpf, funcionarios.email);
            printf("Telefone..: %s \nRua..: %s\n", funcionarios.telefone, funcionarios.rua);
            printf("Numero..: %s \nBairro..: %s \nCep..: %s\n", funcionarios.numero, funcionarios.bairro, funcionarios.cep);
            encontrado = 1;
            system("pause>nul");
        }
    }
    if (!encontrado)
    {
        printf("\nCodigo nao cadastrado!!\n");
        system("pause");
        operacao();
    }
    fclose(funFuncionarios);
}

void testealterarFuncionario()
{
  funFuncionarios = fopen("Funcionarios.txt", "r+b");
    if(funFuncionarios == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }

    struct Funcionario funcionarios;
    int cod, encontrado = 0;
    printf ("\nDigite o cpf que deseja alterar: \n");
    scanf ("%d", &cod);

    while (fread (&funcionarios, sizeof(funcionarios), 1, funFuncionarios))
    {
        if (cod == funcionarios.cpf)
        {
            printf("Nome..: %s \nCPF..: %s \nEmail..: %s\n\n",funcionarios.nome, funcionarios.cpf, funcionarios.email);
            encontrado = 1;

            fseek(funFuncionarios,sizeof(struct Funcionario)*-1, SEEK_CUR);
            printf("\nDigite um novo nome..: \n");
            fflush(stdin);
            gets(funcionarios.nome);
            printf("\nDigite o novo CPF..: \n");
            fflush(stdin);
            gets(funcionarios.cpf);
            printf("\nDigite o novo Email..: \n");
            fflush(stdin);
            gets(funcionarios.email);

            fwrite(&funcionarios, sizeof(funcionarios), 1, funFuncionarios);
            fseek(funFuncionarios, sizeof(funcionarios)* 0, SEEK_END);

            printf("\n Dados do perfil alterados com sucesso!");
            limparTela();
            perfilFuncionario();
        }
    }
    if (!encontrado)
    {
        printf("\nCodigo nao cadastrado!!\n");
        limparTela();
        perfilFuncionario();
    }
    fclose(funFuncionarios);
}


void testeexcluirFuncionario()
{
   funFuncionarios = fopen("Funcionarios.txt", "r+b");
    if(funFuncionarios == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }

    struct Funcionario funcionarios;

    int encontrado = 0;
    char certeza, cod;
    printf ("\nDigite o CPF que deseja EXCLUIR..: \n");
    scanf ("%s", &cod);

    while (fread (&funcionarios, sizeof(funcionarios), 1, funFuncionarios))
    {


            printf("Usuario..: %s \nNome..: %s  \nCPF..: %s \n\n",funcionarios.login, funcionarios.nome, funcionarios.cpf);
            encontrado = 1;

            printf("\nTem certeza que quer excluir este perfil? s/n \n");
            fflush(stdin);
            scanf("%c", &certeza);
            if (certeza == 's')
            {
                funcionarios.deletar = '*';
                fseek(funFuncionarios,sizeof(struct Funcionario)*-1, SEEK_CUR);
                fwrite(&funcionarios, sizeof(funcionarios), 1, funFuncionarios);
                fseek(funFuncionarios, sizeof(funcionarios)* 0, SEEK_END);
                printf("\nPerfil excluido com Sucesso! \n");
                limparTela();
                perfilFuncionario();
            }
            else if (certeza == 'n')
            {
                system("cls || clear");
            }

    }
    if (!encontrado)
    {
        printf ("\nPerfil nao cadastrado!!\n");
        limparTela();
        perfilFuncionario();
    }
    fclose(funFuncionarios);
}
