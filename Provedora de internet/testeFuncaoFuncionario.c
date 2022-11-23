#include "funcaoCliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>

    struct Funcionario{
    int cpf;
    int codigo;
    char nome[60];
    int funcionario;
    float salario;
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
        printf("4.Voltar ao Menu\n");
        scanf("%i",&funcionarios);
    switch(funcionarios)
    {
    case 1:
        testecadastroFuncionario();
        break;

    case 2:
        testeloginFuncionario();
        break;

    case 4:
        limparTela();
        telaInicial();
        break;

    default:
        printf("selecione uma opção valida");

    }
}

void testeloginFuncionario()
{
    funFuncionarios = fopen("Funcionarios.txt", "rb");
    if(funFuncionarios == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }

    struct Funcionario funcionarios;

    int encontrado = 0,cod;

    printf ("\nLogin utilize seu CPF para entrar..: \n");
    scanf ("%d", &cod);

    while (fread(&funcionarios, sizeof(funcionarios), 1, funFuncionarios))
    {
    system("cls || clean");
    printf("\nVerifincando .... \n\n");

        if ((cod == funcionarios.cpf)  && (funcionarios.deletar != '*'))
        {
            printf("Bem Vindo..: %-8s \n",funcionarios.nome);
            encontrado = 1;
           telaFuncionario();

        }
    }
    if (!encontrado)
    {
        printf("\nCodigo nao cadastrado!!\n");
        system("pause");
       testefuncaoFuncionarios();
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

            printf("Digite os numeros do seu cpf sem pontuação..: \n");
            scanf("%d", &funcionarios.codigo);
            printf("Informe seu nome completo..: \n");
            fflush(stdin);
            gets(funcionarios.nome);
            printf("informe seu salario..: \n");
            scanf("%f", &funcionarios.salario);

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

            encontrado = 1;

            fseek(funFuncionarios,sizeof(struct Funcionario)*-1, SEEK_CUR);
            printf("\nDigite um novo nome..: \n");
            fflush(stdin);
            gets(funcionarios.nome);
            printf("\nDigite o novo CPF..: \n");
            fflush(stdin);
            gets(funcionarios.cpf);
            printf("\nDigite o novo Email..: \n");


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
