#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcaoCliente.h"
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "");

    system("color f0");

    int perfil,cliente,funcionario;

    printf("\n\n");
    printf("\t*************************************************************\n");
    printf("\t*                                                           *\n");
    printf("\t*                                                           *\n");
    printf("\t*    OLA, SEJA BEM VINDO A NOSSA PROVEDORA DE INTERNET.     *\n");
    printf("\t*                       BROADTCHE                           *\n");
    printf("\t*    A INTERNET MAIS RAPIDA E SEGURA QUE DOMINARA O MUNDO   *\n");
    printf("\t*                                                           *\n");
    printf("\t*                                                           *\n");
    printf("\t*************************************************************\n\n");

    printf("Selecione o seu perfil\n\n");
    printf("1.Cliente\n");
    printf("2.Funcionario\n");
    scanf("%i",&perfil);

    switch(perfil)
    {
    case 1:
        funcaoCliente();
        break;
    case 2:
        printf("funcionario");
        printf("2.login");
        break;
    default:
        printf("selecione uma opcao valida !!");
    }


}


/*=========== Cores ================
Para implementar segue algumas cores - system(“color 1F”)
0 - Preto
1 - Azul
2 - Verde
3 - Verde-água
4 - Vermelho
5 - Roxo
6 - Amarelo
7 - Branco
8 - Cinza
9 - Azul claro
A - Verde Claro
B - Verde-água claro
C - Vermelho Claro
D - Lilás
E - Amarelo Claro
F - Branco Brilhante*/

/*=========== Tabela ASCII ================
Para implementar segue alguns caracteres
10 - Enter
27 - ESC
32 - Space
*/

