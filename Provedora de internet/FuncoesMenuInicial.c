#include "funcaoCliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void FuncoesMenuInicial()
{

    int validacoes;
    printf("\n\nSelecione o que fazer...: \n\n");
    printf("1.Cliente\n");
    printf("2.Funcionario\n");
    printf("3.Sobre Nós\n");
    printf("4.Participantes\n");
    printf("5.Configurações de tela\n");
    printf("0.Sair\n");
    scanf("%i",&validacoes);

    switch(validacoes)
    {
    case 1:
        funcaoCliente();
        break;
    case 2:
        printf("1.login");
        break;
    case 3:
        sobreNos();
        break;
    case 4:
        participantes();
        break;
    case 5:
        system("cls || clean");
       printf("\n\tSelecionada Configurações de tela...: \n\n");
       configuracaoTela();
        break;
    case 0:
        system("pause");
        exit(1);
        break;

    default:
        printf("selecione uma opção valida !!");
        limparTela();
        FuncoesMenuInicial();
    }

}



void participantes()
{
    limparTela();
    printf("\n\n");
    printf("\tO PROJETO FOI REALIZADO PELO GRUPO DE TECNICOS DE INFORMATICA\n PARA DESENVOLVIMENTO DE UM SOFTWARE FUNCIONAL QUE ATENDA TODO TIPO DE CLIENTE.");
    printf("\n\tSENDO UM SISTEMA RAPIDO E EFICAZ ONDE VOCE PODE CONSULTAR SEU\n CADASTRO DE FORMA SIMPLES E RÁPIDO COM POUCAS REQUISIÇÕES!!!");
    printf("\n\n\tDESENVOLVEDORES DO PROJETO...: \n");
    printf("\n Gustavo Alves Quirino RA: G514GC-0");
    printf("\n José jadson rodrigues RA: G4482b2");
    printf("\n Kelson nascimento oliveira RA: G525CB-4");
    printf("\n Leonardo Luiz Silva de Paula RA: G154BE3");
    printf("\n Matheus Cavalcanti Soares RA: G433JE8");
    printf("\n Thiago Lucca Rodrigues Martins De Santana RA: N8444J-0\n");
}



void configuracaoTela()
{
    int corTela;
    printf("1.Padrão\n");
    printf("2.Fundo Azul com letra Branca\n");
    printf("3.Fundo Branco com letra Preta\n");
    printf("4.Fundo Amarelo com letra Azul\n");
    printf("0.Voltar");
    scanf("%i", & corTela);

    switch(corTela)
    {
    case 0:
        limparTela();
        FuncoesMenuInicial();
        break;
    case 1:
        system("color 0f");
        break;
    case 2:
        system("color 1f");
        break;
    case 3:
        system("color f0");
        break;
    case 4:
        system("color E1");
        break;
    default:
        printf("Opção inválida");
        limparTela();
        configuracaoTela();
    }
     limparTela();
     FuncoesMenuInicial();
}

void limparTela()
{
    system("pause>nul");
    system("cls || clean");
}

void sobreNos()
{
    printf("sobre nos");
}
