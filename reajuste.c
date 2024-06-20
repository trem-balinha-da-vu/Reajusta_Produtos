#include<stdio.h>
#include "reajuste.h"
#include "C:\\Users\\izabe\\Desktop\\Cria_arq_prod\\produtos.h"
#include "C:\\Users\\izabe\\Desktop\\Cria_arq_prod\\interface.h"


void reajusta_produtos(int codigo_produto, int reajuste)
{
    float porcentagem = porcentagem_de_reajuste(reajuste);

    FILE *fp;
    FILE *temp_fp;
    char nomearq[100] = "C:\\Users\\izabe\\Desktop\\Cria_arq_prod\\Produtos.dat";
    char temp_nomearq[100] = "C:\\Users\\izabe\\Desktop\\Cria_arq_prod\\Temp_Produtos.dat";

    Produto produto;

    fp = fopen(nomearq, "rb");
    if (!fp) {
        printf("FILE ERROR!!! Arquivo %s nao encontrado\n", nomearq);
        return;
    }

    temp_fp = fopen(temp_nomearq, "wb");
    if (!temp_fp) {
        printf("FILE ERROR!!! Arquivo temporario nao pode ser criado\n");
        fclose(fp);
        return;
    }

    printf("\nCodigo\t\tNome\t\tPreco Reajustado\n");

    while (fread(&produto, sizeof(Produto), 1, fp))
    {
        if (codigo_produto == -1 || produto.codigo_produto == codigo_produto)
        {
            produto.preco_produto *= porcentagem;
        }
        printf("%d\t\t%s\t\t%.2f\n", produto.codigo_produto, produto.nome_produto, produto.preco_produto);
        fwrite(&produto, sizeof(Produto), 1, temp_fp);
    }

    fclose(fp);
    fclose(temp_fp);

    remove(nomearq);
    rename(temp_nomearq, nomearq);

}

float porcentagem_de_reajuste (int reajuste)
{
    float porcentagem;

    porcentagem = 1.0 + ((float)reajuste)/100.0;

    return porcentagem;
}
