#include "funcaoCliente.h"
#include<stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>
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


void adicionarServico()
{

    int voltar;

    funServico = fopen("Servi�os.txt", "ab");
    if(funServico == NULL){
        printf("\n\tATENCAO o arquivo n�o pode ser aberto");
        getch();
        exit(1);
    }
            struct Servico servicos;

            printf("Digite o codigo do Servi�o: \n");
            scanf("%d", &servicos.codigo);
            printf("Digite a descricao do Servi�o: \n");
            fflush(stdin);
            gets(servicos.descricaoServico);
            printf("Digite o valor do Servi�o: \n");
            scanf("%f", &servicos.valorServico);

    voltar = fwrite (&servicos, sizeof(servicos) ,1,funServico);

    if(voltar == 1)
        {
            printf("\nINFO. GRAVADAS COM SUCESSO!\n");
            system("pause");
        }
    fclose(funServico);
}

void consultarServico()
{
    funServico = fopen("Servi�os.txt", "rb");
    if(funServico == NULL){
        printf("\n\tATENCAO o arquivo n�o pode ser aberto");
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
        operacao();
    }
    fclose(funServico);
}

void excluirServico()
{
   funServico = fopen("Servi�os.txt", "r+b");
    if(funServico == NULL){
        printf("\n\tATENCAO o arquivo n�o pode ser aberto");
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

            printf("\nTem certeza que quer excluir este Servi�o? s/n \n");
            fflush(stdin);
            scanf("%c", &certeza);
            if (certeza == 's')
            {
                servicos.deletar = '*';
                fseek(funServico,sizeof(struct Servico)*-1, SEEK_CUR);
                fwrite(&servicos, sizeof(servicos), 1, funServico);
                fseek(funServico, sizeof(servicos)* 0, SEEK_END);
                printf("\nServi�o excluido com Sucesso! \n");
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




void alterarServico()
{
  funServico = fopen("Servi�os.txt", "r+b");
    if(funServico == NULL){
        printf("\n\tATENCAO o arquivo n�o pode ser aberto");
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

            printf("\n Dados do Servi�o alterados com sucesso!");
            system("pause>nul");
        }
    }
    if (!encontrado)
    {
        printf("\nCodigo nao cadastrado!!\n");
    }
    fclose(funServico);
}
