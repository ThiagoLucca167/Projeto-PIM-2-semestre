#include "funcaoCliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define TAMANHO 100



void telaCliente()
{
    int logadoCliente;


    printf("\n\n");
    printf("Ol� caro cliente, desde j� agradecemos a prefer�ncia\nE iremos te fornecer a melhor internet com banda larga ilimitada e 5G.");
    printf("\n\n");

    printf("1.Consultar Perfil\n2.Consultar Produtos\n3.Consultar Servi�os\n0.Voltar ao Menu Inicial\n");
    scanf("%i", &logadoCliente);

    switch(logadoCliente)
    {
    case 0:
        telaInicial();
        break;

    case 1:
        printf("consulta de perfil selecionado. \n\n1.Alterar Dados\n2.Consultar Perfil\n3.Incluir Dados\n4.Excluir perfil.");
        break;
    case 2:
        printf("consulta de Produtos selecionado. \n\n1.Solicitar Produtos\n2.Consultar Produtos\n3.Sugest�o de produtos\n4.Cancelar Produtos.");
        break;
    case 3:
        printf("consulta de Servi�os selecionado. \n\n1.Solicitar Servi�os\n2.Consultar Servi�os\n3.Sugest�o de servi�os.");
        break;
    default:
        printf("Selecione uma op��o val�da!!!");
    }

}
