#include <stdio.h>
#include <stdlib.h>


void funcaoCliente()
{
    int cliente;
    char login[30], senha[30];

    printf("\n\tSelecionado o perfil cliente !!!\n\n");
        printf("1.cadastro\n");
        printf("2.login");
        scanf("%i",&cliente);
    switch(cliente)
    {
    case 1:
        printf("cadastro\n");
        break;
    case 2:
        printf("login");
        break;
    default:
        printf("selecione uma opcao valida");

    }
}

//Login cliente
void loginCliente()
{
    for
}
