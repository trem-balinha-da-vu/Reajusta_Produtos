#include <stdio.h>
#include <stdlib.h>
#include "reajuste.h"
#include "produtos.h"
#include "interface.h"

/*
"Reajusta_Produtos" � um programa que aplica um indice de reajuste ao pre�o de todos os produtos,
 ou a um �nico produto, cuja codigo seja fornencido pelo usu�rio.
**/

int main()
{
    int porcentagem, codigo_produto;
    titulo("REAJUSTE DE PRODUTOS");
    printf("Informe o codigo do produto que voce deseja reajustar o preco.\nCaso queira alterar todos, digite -1."); scanf("%d", &codigo_produto);
    printf("Informe o indice de reajuste: "); scanf("%d", &porcentagem);

    reajusta_produtos(codigo_produto, porcentagem);
    limpaTela();

    titulo("LISTA COMPLETA DE PRODUTOS");
    mostra_produtos();

    return 0;
}
