#include "funcaoCliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// O arquivo FuncoesMenuInicial foi desenvolvido como tela inicial para o usu�rio ter acesso a v�rias telas



void FuncoesMenuInicial() // primeira tela de acesso do usu�rio
{
    int validacoes;
    printf("\nMENU INICIAL*\n\nSelecione o que fazer...: \n\n");
    printf("1. Cliente\n");
    printf("2. Funcionario\n");
    printf("3. Administrador\n");
    printf("4. Sobre N�s\n");
    printf("5. Participantes\n");
    printf("6. Configura��es de tela\n");
    printf("0. Sair\n");
    scanf("%i",&validacoes);

    switch(validacoes)
    {
    case 1:
        funcaoCliente();  // op��o para o usu�rio acessar como cliente (funcaoCliente.c)
        break;
    case 2:
        funcaoFuncionarios(); // op��o para acessar como funcionario (funcaoFuncionario.c)
        break;
    case 3:
        loginADM(); // op��o para o usu�rio acessar como administrador(telaCliente.c)
        break;
    case 4:
        sobreNos();
        break;
    case 5:
        participantes();
        break;
    case 6:
        system("cls || clean");
       printf("\n\tSelecionada Configura��es de tela...: \n\n");
       configuracaoTela();
        break;

    case 0:
        system("pause");
        exit(1);
        break;

    default:
        printf("selecione uma op��o valida !!");
        system("cls || clean");
        FuncoesMenuInicial();
    }

}



void participantes()  // integrantes do projeto
{
    limparTela();
    printf("\n\n");
    printf("\tO PROJETO FOI REALIZADO PELO GRUPO DE TECNICOS DE INFORMATICA\n PARA DESENVOLVIMENTO DE UM SOFTWARE FUNCIONAL QUE ATENDA TODO TIPO DE CLIENTE.");
    printf("\n\tSENDO UM SISTEMA RAPIDO E EFICAZ ONDE VOCE PODE CONSULTAR SEU\n CADASTRO DE FORMA SIMPLES E R�PIDO COM POUCAS REQUISI��ES!!!");
    printf("\n\n\tDESENVOLVEDORES DO PROJETO...: \n");
    printf("\n Gustavo Alves Quirino RA: G514GC-0");
    printf("\n Jos� jadson rodrigues RA: G4482b2");
    printf("\n Kelson nascimento oliveira RA: G525CB-4");
    printf("\n Leonardo Luiz Silva de Paula RA: G154BE3");
    printf("\n Matheus Cavalcanti Soares RA: G433JE8");
    printf("\n Thiago Lucca Rodrigues Martins De Santana RA: N8444J-0\n\n");
    limparTela();
    FuncoesMenuInicial();
}



void configuracaoTela() //configura��o da formata��o de tela
{
    int corTela;
    printf("1.Padr�o\n");
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
        printf("Op��o inv�lida");
        limparTela();
        configuracaoTela();
    }
     limparTela();
     FuncoesMenuInicial();
}

void limparTela()  //fun��o b�sica para pausar e limpar a tela
{
    system("pause>nul");
    system("cls || clean");
}

void sobreNos() // informa��es sobre a empresa
{
    printf("sobre nos\n\n");
    limparTela();
    FuncoesMenuInicial();
}
