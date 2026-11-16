#include <stdio.h>
#include "roupas.h"

void salvarRoupas(Roupa roupas[], int quantidade) {
    int i;
    FILE *arquivo = fopen("roupas.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir roupas.txt para escrita!\n");
        return;
    }
    for (i = 0; i < quantidade; i++) {
        fprintf(arquivo, "%.2f %s\n", roupas[i].preco, roupas[i].nome);
    }
    fclose(arquivo);
}

void carregarRoupas(Roupa roupas[], int *quantidade) {
    FILE *arquivo = fopen("roupas.txt", "r");

    *quantidade = 0;
    if (arquivo == NULL) {
        printf("Aviso: roupas.txt nao encontrado. Catalogo iniciado vazio.\n");
        return;
    }
    while (*quantidade < MAX_ROUPAS &&
           fscanf(arquivo, "%f %49s", &roupas[*quantidade].preco,
                  roupas[*quantidade].nome) == 2) {
        (*quantidade)++;
    }
    fclose(arquivo);
}
