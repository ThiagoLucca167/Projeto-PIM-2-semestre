#include "funcaoCliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>

// este arquivo foi criado com a finalidade de fazer funcionalidades em relação com funcionários como, cadastro de funcionario e login

    struct Funcionario{
    int cpf;
    int codigo;
    char nome[60];
    int funcionario;
    float salario;
    char deletar;
    };

    FILE *funFuncionarios;

void funcaoFuncionarios()  // tela de login ou cadastro de funcionarios
{

    int funcionarios=0;
    char login, senha;
    system("cls || clear");
    printf("\n\tSelecionado o perfil funcinario !!!\n");
    printf("Após feito o login tera acesso as informações de funcionario\n\n");
        printf("1.Login\n");
        printf("0.Voltar ao Menu\n");
        scanf("%i",&funcionarios);
    switch(funcionarios)
    {
    case 1:
        loginFuncionario();
        break;

    case 0:
        limparTela();
        telaInicial();
        break;

    default:
        printf("selecione uma opção valida");
        limparTela();
        funcaoFuncionarios();

    }
}

void loginFuncionario()  // funcao para login de usuário como funcionário
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
       funcaoFuncionarios();
    }
    fclose(funFuncionarios);
}


void loginADM()  // funcao para login de usuário como ADMINISTRADOR
{
    char loginAdm1[15] = "root1";
    char loginAdm2[15] = "root2";
    char login[15];
    char senhaAdm1[15] = "root1";
    char senhaAdm2[15] = "root2";
    char senha[15];

    printf("Digite o Login: ");
    scanf("%s", login);

    printf("Digite a Senha: ");
    scanf("%s", senha);

    if (strcmp(login,loginAdm1) == 0 && strcmp(senha,senhaAdm1) == 0 || strcmp(login,loginAdm2)==0 &&  strcmp(senha,senhaAdm2)==0)
    {
        printf("\n\nBem vindo Admin!\n\n");
        system("pause");
        funcaoAdm();
    }

    else
    {
            printf("\n\nDADOS INVALIDOS!\n\n");
            printf("TENTAR NOVAMENTE ? S OU N\n");
            char tenta;
            scanf("%s", &tenta);
            if(tenta == 's' || tenta=='S')
            {
                loginADM();
            }
            else if(tenta=='n' || tenta=='N')
            {
                limparTela();
                FuncoesMenuInicial();
            }

}
}


void cadastroFuncionario()
{
    adicionarF();
}


void adicionarF() // funcao criada para o cadastro de funcionários
{
    int contador=0, voltar;

    funFuncionarios =fopen("Funcionarios.txt", "ab");
    if(funFuncionarios == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }

    struct Funcionario funcionarios;

            printf("Digite os numeros do seu cpf sem pontuação..: \n");
            scanf("%d", &funcionarios.cpf);
            printf("Informe seu nome completo..: \n");
            fflush(stdin);
            gets(funcionarios.nome);
            printf("informe seu salario..: \n");
            scanf("%f", &funcionarios.salario);

          voltar = fwrite (&funcionarios, sizeof(funcionarios) ,1,funFuncionarios);

        if(voltar == 1)
        {
            printf("\nINFO. GRAVADAS COM SUCESSO!\n");
             fclose(funFuncionarios);
            limparTela();

        }
    perfilFuncionarioADM();
}



void consultarFuncionario()  // função criada para consultar dados de funcionarios
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
            printf("CPF..: %d \nNome..: %-8s \nSalario..: R$ %4.2f\n", funcionarios.cpf,funcionarios.nome,funcionarios.salario);
            encontrado = 1;
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

void alterarFuncionario()
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
            printf("CPF..: %d \nNome..: %-8s \nSalario..: R$ %4.2f\n", funcionarios.cpf,funcionarios.nome,funcionarios.salario);
            encontrado = 1;

            fseek(funFuncionarios,sizeof(struct Funcionario)*-1, SEEK_CUR);
            printf("\nDigite um novo nome..: \n");
            fflush(stdin);
            gets(funcionarios.nome);
            printf("\nDigite o novo CPF..: \n");
            scanf("%d", &funcionarios.cpf);
            printf("\nDigite o novo Salario..: \n");
            scanf("%f", &funcionarios.salario);


            fwrite(&funcionarios, sizeof(funcionarios), 1, funFuncionarios);
            fseek(funFuncionarios, sizeof(funcionarios)* 0, SEEK_END);

            printf("\n Dados do perfil alterados com sucesso!");
            fclose(funFuncionarios);
            limparTela();
            perfilFuncionarioADM();
        }
    }
    if (!encontrado)
    {
        printf("\nCodigo nao cadastrado!!\n");
        limparTela();
        perfilFuncionarioADM();
    }
}


void excluirFuncionario() // exclui um cadastro de funcionário
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
            printf("CPF..: %d \nNome..: %-8s \nSalario..: R$ %4.2f\n", funcionarios.cpf,funcionarios.nome,funcionarios.salario);
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
                perfilFuncionarioADM();
            }
            else if (certeza == 'n')
            {
                system("cls || clear");
                perfilFuncionarioADM();
            }

    }
    if (!encontrado)
    {
        printf ("\nPerfil nao cadastrado!!\n");
        limparTela();
        perfilFuncionarioADM();
    }
    fclose(funFuncionarios);
}



void consultarFuncionarioADM()  // função criada para consultar dados de funcionarios
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
            printf("CPF..: %d \nNome..: %-8s \nSalario..: R$ %4.2f\n", funcionarios.cpf,funcionarios.nome,funcionarios.salario);
            encontrado = 1;
            limparTela();
            perfilFuncionarioADM();
        }
    }
    if (!encontrado)
    {
        printf("\nCodigo nao cadastrado!!\n");
         limparTela();
        perfilFuncionarioADM();
    }
    fclose(funFuncionarios);
}

