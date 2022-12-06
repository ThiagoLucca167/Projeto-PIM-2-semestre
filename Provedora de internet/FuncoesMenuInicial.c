#include "funcaoCliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// O arquivo FuncoesMenuInicial foi desenvolvido como tela inicial para o usu�rio ter acesso a v�rias telas



void FuncoesMenuInicial() // primeira tela de acesso do usu�rio
{
    int validacoes;
    printf("\nMENU INICIAL\nSelecione seu perfil ou Selecione alguma fun��o...:\n\n");
    printf("1. Perfil Cliente\n");
    printf("2. Perfil Funcionario\n");
    printf("3. Perfil de Administrador\n");
    printf("4. Sobre N�s\n");
    printf("5. Configura��es de tela\n");
    printf("6. Participantes do projeto\n");
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
    case 6:
        participantes();
        break;
    case 5:
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
    system("cls || clean");
    logoTipo();

    printf("\n\n");
    printf("\t*****************************************************************************************************\n");
    printf("\t*                                                                                                   *\n");
    printf("\t*   O nosso objetivo � auxiliar e gerenciar o provedor de internet de pequenas e m�dias empresas.   *\n");
    printf("\t*   N�s temos em mente que muitas empresas de tecnologia surgiram com essa grande expans�o,e hoje   *\n");
    printf("\t*   visamos a quest�o de entregar um produto de qualidade, confiabilidade e com total               *\n");
    printf("\t*   profissionalismo que a empresa Broatech utiliza.                                                *\n");
    printf("\t*   Hoje a Broatech, quer desmistificar essa quest�o e padroniza��o dos servi�os de                 *\n");
    printf("\t*   hospedagem/provedores de internet, querendo sempre entregar um servi�os de qualidade,           *\n");
    printf("\t*   confiabilidade e seguran�a aos seus clientes, e visando tamb�m o suporte, pois muitas           *\n");
    printf("\t*   CIA hoje em dia s� querer criar billing e n�o relacionamento com o cliente.                     *\n");
    printf("\t*   Optamos por um servi�o que seja mais atrativo ao cliente pois n�o � simples e f�cil             *\n");
    printf("\t*   escolher um provedor de web e seguir em frente, � bom sempre pesquisar antes de fechar          *\n");
    printf("\t*   a compra de um servi�o, seja ele de servi�os  fornecidos ou de produtos para�contrata��o.       *\n");
    printf("\t*                                                                                                   *\n");
    printf("\t*****************************************************************************************************\n\n");

    limparTela();
    FuncoesMenuInicial();
}
