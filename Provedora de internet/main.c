#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("color f0");

    int perfil,cliente,funcionario,admim;
    char login[50],senha[30];

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
