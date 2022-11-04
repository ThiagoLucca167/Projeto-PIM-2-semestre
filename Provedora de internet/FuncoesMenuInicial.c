#include "funcaoCliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void FuncoesMenuInicial()
{

    int validacoes,cliente,funcionario;
    printf("\n\nSelecione o que fazer...: \n\n");
    printf("1.Cliente\n");
    printf("2.Funcionario\n");
    printf("3.Sobre N�s\n");
    printf("4.Participantes\n");
    printf("5.Configura��es de tela\n");
    printf("0.Sair\n\n");
    scanf("%i",&validacoes);

    switch(validacoes)
    {
    case 1:
        system("cls || clear");
        telaUsuario("Cliente");
        break;

    case 2:
        system("cls || clear");
        telaUsuario("Funcionario");
        break;

    case 3:
        printf("Sobre N�s");
        break;
    case 4:
        printf("Participantes");
        break;
    case 5:
        system("cls || clean");
       printf("\n\tSelecionada Configura��es de tela...: \n\n");
       configuracaoTela();
        break;
    case 0:
        system("pause");
        break;

    default:
        printf("selecione uma opcao valida !!");
        system("pause>nul");
        system("cls || clean");
        FuncoesMenuInicial();
    }

}

void telaUsuario(const char* usuario)
{
    int opcao = 0;
    printf("1.Login do %s\n", usuario);
    printf("2.Cadastro do %s\n", usuario);
    printf("3. voltar\n\n");
    scanf("%i", &opcao);
    system("cls || clear");
    tipoUsuario(opcao, usuario);
}

void tipoUsuario(int opcao, const char* usuario)
{
    switch(opcao){
        case 1:
            system("cls || clear");
            loginUsuario(usuario); // vai para loginUsuario() no arquivo funcaoCliente.c
            break;

        case 2:
            system("cls || clear");
            cadastroUsuario(usuario);
            break;

        case 3:
            system("cls || clear");
            FuncoesMenuInicial();
            break;

        default:
            system("cls || clear");
            printf("op��o inv�lida!");
            system("pause>nul");
            system("cls || clear");
            telaUsuario(usuario);

    }
}

void configuracaoTela()
{
    printf("0 - Preto | 1 - Azul |2 - Verde | 3 - Verde-�gua\n");
    printf("4 - Vermelho | 5 - Roxo | 6 - Amarelo |7 - Branco\n");
    printf("8 - Cinza | 9 - Azul claro | A - Verde Claro\n");
    printf("B - Verde-�gua claro | C - Vermelho Claro\n");
    printf("D - Lil�s | E - Amarelo Claro | F - Branco Brilhante");
    int opcao;
    char buf[2];
    snprintf(buf, sizeof(buf), "color %s", opcao);
    system(buf);

}
