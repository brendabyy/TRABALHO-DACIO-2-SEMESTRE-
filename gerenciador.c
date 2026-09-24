#include <stdio.h>
#include <stdlib.h>
#include "roupas.h"

// 1. Módulo de Cadastro
void cadastrarRoupa(Carrinho *catalogo) {
    float preco;

    printf("\n--- CADASTRO DE ROUPA ---\n");

    if (catalogo->quantidade >= MAX_ROUPAS) {
        printf("Erro: Catalogo cheio!\n");
    } 
    else {
        
        printf("Digite o nome da roupa (sem espacos): ");
        scanf("%s", catalogo->itens[catalogo->quantidade].nome);

        printf("Digite o preco da roupa: R$ ");
        scanf("%f", &preco);

        if (preco <= 0) {
            printf("Erro: O preco deve ser maior que zero!\n");
        } 
        else {
            // Guarda o preço e aumenta a quantidade de roupas
            catalogo->itens[catalogo->quantidade].preco = preco;
            catalogo->quantidade = catalogo->quantidade + 1;

            printf("Roupa cadastrada com sucesso!\n");
        }
    }
}

// 2. Módulo de Consulta
void listarRoupas(const Carrinho *catalogo) {
    int i;

    printf("\n--- CATALOGO DE ROUPAS ---\n");

    // Verifica se existem roupas cadastradas
    if (catalogo->quantidade == 0) {
        printf("Nenhuma roupa cadastrada no momento.\n");
    } 
    else {
        for (i = 0; i < catalogo->quantidade; i = i + 1) {
            printf("%d. %s - R$ %.2f\n", 
                   i + 1, 
                   catalogo->itens[i].nome, 
                   catalogo->itens[i].preco);
        }
    }
    printf("--------------------------\n");
}
