#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produtos.h"

void mostra_produtos()
{
    FILE *fp;
    char nomearq[100] = "C:\\Users\\izabe\\Desktop\\Cria_arq_prod\\Produtos.dat";
    Produto produto;

    fp = fopen(nomearq, "rb");

    if (!fp) {
        printf("FILE ERROR!!! Arquivo %s nao encontrado\n", nomearq);
        return;
    }

    printf("\nCodigo\t\tNome\t\tPreco\n");

    while (fread(&produto, sizeof(Produto), 1, fp)) {
        printf("%d\t\t%s\t\t%.2f\n", produto.codigo_produto, produto.nome_produto, produto.preco_produto);
    }

    printf("\n");

    fclose(fp);
}
