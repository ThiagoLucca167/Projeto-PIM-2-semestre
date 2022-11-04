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
        printf("2.login");
        break;
    case 3:
        printf("Sobre Nós");
        break;
    case 4:
        printf("Participantes");
        break;
    case 5:
        system("cls || clean");
       printf("\n\tSelecionada Configurações de tela...: \n\n");
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



void configuracaoTela()
{
    printf("0 - Preto | 1 - Azul |2 - Verde | 3 - Verde-água\n");
    printf("4 - Vermelho | 5 - Roxo | 6 - Amarelo |7 - Branco\n");
    printf("8 - Cinza | 9 - Azul claro | A - Verde Claro\n");
    printf("B - Verde-água claro | C - Vermelho Claro\n");
    printf("D - Lilás | E - Amarelo Claro | F - Branco Brilhante");
    int opcao;
    char buf[2];
    snprintf(buf, sizeof(buf), "color %s", opcao);
    system(buf);

}
