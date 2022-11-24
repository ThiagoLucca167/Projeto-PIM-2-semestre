#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcaoCliente.h"
#include <locale.h>


// o programa se iniciar� aqui e ir� direto para outra parte do c�digo FuncoesMenuInicial.c

int main()
{
    system("color 0f");
    setlocale(LC_ALL, "");
    telaInicial();
}

// telaInicial imprimir� uma mensagem de boas vindas ao usu�rio

int telaInicial()
{
    system("cls || clean");
    printf("\n\n");
    printf("\t\t*************************************************************\n");
    printf("\t\t*      OLA, SEJA BEM VINDO A NOSSA PROVEDORA DE INTERNET.   *\n");
    printf("\t\t*                                                           *\n");
    printf("\t\t*                                                           *\n");
    printf("\t\t*                       BRODTECH                            *\n");
    printf("\t\t*                                                           *\n");
    printf("\t\t*                                                           *\n");
    printf("\t\t*      A INTERNET MAIS RAPIDA E SEGURA QUE DOMINARA O MUNDO *\n");
    printf("\t\t*                                                           *\n");
    printf("\t\t*************************************************************\n\n");

    system("pause>nul");

    FuncoesMenuInicial();
}
/*=========== Cores ================
Para implementar segue algumas cores - system(�color 1F�)
0 - Preto
1 - Azul
2 - Verde
3 - Verde-�gua
4 - Vermelho
5 - Roxo
6 - Amarelo
7 - Branco
8 - Cinza
9 - Azul claro
A - Verde Claro
B - Verde-�gua claro
C - Vermelho Claro
D - Lil�s
E - Amarelo Claro
F - Branco Brilhante*/

/*=========== Tabela ASCII ================
Para implementar segue alguns caracteres
10 - Enter
27 - ESC
32 - Space
*/

