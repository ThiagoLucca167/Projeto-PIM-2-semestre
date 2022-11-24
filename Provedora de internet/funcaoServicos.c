#include "funcaoCliente.h"
#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>


// este arquivo foi criado com a finalidade de realizar funções em relação ao serviços que a empresa presta ao cliente e cadastramento do mesmo


    struct Servico{
    int cpf;
    int codigo;
    char nomeServico;
    float valorServico;
    char descricaoServico[50];
    int funcionario;
    char deletar;
    };


    FILE *funServico;


void adicionarServico() // cadastra um tipo de serviço e suas informaçoes
{

    int voltar;

    funServico = fopen("Serviços.txt", "ab");
    if(funServico == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }
            struct Servico servicos;

            printf("Digite o codigo do Serviço: \n");
            scanf("%d", &servicos.codigo);
            printf("Digite a descricao do Serviço: \n");
            fflush(stdin);
            gets(servicos.descricaoServico);
            printf("Digite o valor do Serviço: \n");
            scanf("%f", &servicos.valorServico);

    voltar = fwrite (&servicos, sizeof(servicos) ,1,funServico);

    if(voltar == 1)
        {
            printf("\nINFO. GRAVADAS COM SUCESSO!\n");
            system("pause");
        }
    fclose(funServico);
}

void consultarServico() // consulta um tipo de serviço cadastrado no sistema
{
    funServico = fopen("Serviços.txt", "rb");
    if(funServico == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }

    struct Servico servicos;

    int encontrado = 0,cod;

    printf ("\nDigite o Codigo do Servico que procura: \n");
    scanf ("%d", &cod);

    while (fread(&servicos, sizeof(servicos), 1, funServico))
    {

    printf("Buscando ....    \n");

        if ((cod == servicos.codigo)  && (servicos.deletar != '*'))
        {
            printf("Codigo..: %d \nDescricao..: %-8s \nValor..: R$ %4.2f\n", servicos.codigo,servicos.descricaoServico,servicos.valorServico);
            encontrado = 1;
            system("pause>nul");
        }
    }
    if (!encontrado)
    {
        printf("\nCodigo nao cadastrado!!\n");
        system("pause");
    }
    fclose(funServico);
}

void excluirServico() // apaga dados de um serviço do sistema
{
   funServico = fopen("Serviços.txt", "r+b");
    if(funServico == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }

    struct Servico servicos;

    int cod, encontrado = 0;
    char certeza;
    printf ("\nDigite o codigo que deseja EXCLUIR: \n");
    scanf ("%d", &cod);

    while (fread (&servicos, sizeof(servicos), 1, funServico))
    {
        if (cod == servicos.codigo)
        {
            printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n\n",servicos.codigo, servicos.descricaoServico, servicos.valorServico);
            encontrado = 1;

            printf("\nTem certeza que quer excluir este Serviço? s/n \n");
            fflush(stdin);
            scanf("%c", &certeza);
            if (certeza == 's')
            {
                servicos.deletar = '*';
                fseek(funServico,sizeof(struct Servico)*-1, SEEK_CUR);
                fwrite(&servicos, sizeof(servicos), 1, funServico);
                fseek(funServico, sizeof(servicos)* 0, SEEK_END);
                printf("\nServiço excluido com Sucesso! \n");
                system("pause>nul");
            }
            else if (certeza == 'n')
            {
                system("cls || clear");
            }
        }
    }
    if (!encontrado)
    {
        printf ("\nCodigo nao cadastrado!!\n");
        system("pause>nul");
    }
    fclose(funServico);
}




void alterarServico() // altera dados de um serviço cadastrado no sistema
{
  funServico = fopen("Serviços.txt", "r+b");
    if(funServico == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }

    struct Servico servicos;
    int cod, encontrado = 0;
    printf ("\nDigite o codigo que deseja alterar: \n");
    scanf ("%d", &cod);

    while (fread (&servicos, sizeof(servicos), 1, funServico))
    {
        if (cod == servicos.codigo)
        {
            printf("Cod %d --- Descricao: %-8s --- Valor R$ %4.2f\n\n",servicos.codigo, servicos.descricaoServico, servicos.valorServico);
            encontrado = 1;

            fseek(funServico,sizeof(struct Servico)*-1, SEEK_CUR);
            printf("\nDigite a nova descricao: \n");
            fflush(stdin);
            gets(servicos.descricaoServico);
            printf("\nDigite o novo preco....: \n");
            scanf("%f", &servicos.valorServico);

            fwrite(&servicos, sizeof(servicos), 1, funServico);
            fseek(funServico, sizeof(servicos)* 0, SEEK_END);

            printf("\n Dados do Serviço alterados com sucesso!");
            system("pause>nul");
        }
    }
    if (!encontrado)
    {
        printf("\nCodigo nao cadastrado!!\n");
    }
    fclose(funServico);
}


void consultarServicoClientes() // abre uma lista de serviços disponíveis para o cliente
{
     funServico = fopen("Serviços.txt", "rb");
    if(funServico == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }

    struct Servico servicos;

    int encontrado = 0;
    char i;

    printf("Ver serviços ? S ou N");
    scanf("%s",&i);

    if(i =='S' || i=='s')
    {
        int encontrado = 0;
        printf ("\nEsses são os serviços que estão disponiveis..: \n");

    while (fread(&servicos, sizeof(servicos), 1, funServico))
    {
           if(encontrado==0)
           {
            printf("Procurando ....    \n");
            printf("Codigo..: %d \nDescricao..: %-8s \nValor..: R$ %4.2f\n", servicos.codigo,servicos.descricaoServico,servicos.valorServico);

           }
    }

    if (!encontrado)
    {
        printf("Serviços não encontrados !!!");
        system("pause");
        system("cls || clean");
        consultarServicoCli();
    }
    fclose(funServico);
    }
    else if(i=='n' || i=='N')
    {
        printf("\nSaindo...\n");
        system("pause");
        system("cls || clean");
        consultarProdutosCli();
    }
    else
    {
        printf("Opção invalida !!!");
        limparTela();
        consultarServicoClientes();
    }
}












void adicionarServicoSolicitados() // função para o cliente requisitar um pedido de serviço no sistema
{
    funServico = fopen("Serviços.txt", "rb");
    if(funServico == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }
    struct Servico servicos;
    int encontrado=0;
    while (fread(&servicos, sizeof(servicos), 1, funServico))
    {
           if(encontrado==0)
           {
            printf("Procurando ....    \n");
            printf("Codigo..: %d \nDescricao..: %-8s \nValor..: R$ %4.2f\n", servicos.codigo,servicos.descricaoServico,servicos.valorServico);
           }
    }
    fclose(funServico);
    int voltar;

    funServico = fopen("Clientes Serviços solicitados.txt", "ab");
    if(funServico == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }
            printf("Confirme seu CPF..:\n");
            scanf("%d", &servicos.cpf);
            printf("Confirme o codigo do Serviço..:\n");
            scanf("%d", &servicos.codigo);


    voltar = fwrite (&servicos, sizeof(servicos) ,1,funServico);

    if(voltar == 1)
        {
            printf("\nINFO. GRAVADAS COM SUCESSO!\n");
            system("pause");
            system("cls || clean");
        }
    fclose(funServico);
    consultarServicoCli();
}







void cancelarServico()  // cancela um pedido de serviço pendente feito pelo cliente
{
   funServico = fopen("Clientes Serviços solicitados.txt", "r+b");
    if(funServico == NULL){
        printf("\n\tATENCAO o arquivo não pode ser aberto");
        getch();
        exit(1);
    }

    struct Servico servicos;

    int cod, encontrado = 0;
    char certeza;
    printf ("\nDigite o cpf para verificar cancelamento dos Serviços..: \n");
    scanf ("%d", &cod);

    while (fread (&servicos, sizeof(servicos), 1, funServico))
    {
        if (cod == servicos.cpf)
        {
            printf("Usuário..: %d \nCodigo %d \nDescricao: %-8s \nValor R$ %4.2f\n\n",servicos.cpf,servicos.codigo, servicos.descricaoServico, servicos.valorServico);
            encontrado = 1;

            printf("\nTem certeza que quer cancelar este Serviço? s/n \n");
            fflush(stdin);
            scanf("%c", &certeza);
            if (certeza == 's')
            {
                servicos.deletar = '*';
                fseek(funServico,sizeof(struct Servico)*-1, SEEK_CUR);
                fwrite(&servicos, sizeof(servicos), 1, funServico);
                fseek(funServico, sizeof(servicos)* 0, SEEK_END);
                printf("\nServiço excluido com Sucesso! \n");
                system("pause>nul");
                system("cls || clean");
                consultarServicoCli();
            }
            else if (certeza == 'n')
            {
                system("cls || clear");
                consultarServicoCli();
            }
        }
    }
    if (!encontrado)
    {
        printf ("\nCodigo nao cadastrado!!\n");
        system("pause>nul");
        consultarServicoCli();
    }
    fclose(funServico);
}
