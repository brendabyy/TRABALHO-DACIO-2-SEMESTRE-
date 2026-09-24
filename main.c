/*
 * Integrante Responsavel: Brenda
 * Funcao: Controller principal, Menu e Otimizacao de Orcamento
 */
#include <stdio.h>
#include <stdlib.h>
#include "roupas.h"

int main() {
    Carrinho catalogo;
    catalogo.quantidade = 0;
    int opcao;
    float orcamento, total_gasto;
    int i;

    // Carrega os dados iniciais do arquivo roupas.txt se ele existir
    FILE *arquivo = fopen("roupas.txt", "r");
    if (arquivo != NULL) {
        while (fscanf(arquivo, "%f %s", &catalogo.itens[catalogo.quantidade].preco, 
                      catalogo.itens[catalogo.quantidade].nome) != EOF) {
            catalogo.quantidade++;
            if (catalogo.quantidade >= MAX_ROUPAS) break;
        }
        fclose(arquivo);
    }

    do {
        printf("\n=== SISTEMA OTIMIZADOR DE COMPRAS ===\n");
        printf("1. Cadastrar nova roupa\n");
        printf("2. Remover ultima roupa cadastrada\n");
        printf("3. Listar catalogo\n");
        printf("4. Otimizar compras (usar orcamento)\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarRoupa(&catalogo);
                break;

            case 2:
                if (catalogo.quantidade > 0) {
                    catalogo.quantidade--;
                    printf("\nUltima roupa removida com sucesso!\n");
                } else {
                    printf("\nO catalogo ja esta vazio!\n");
                }
                break;

            case 3:
                listarRoupas(&catalogo);
                break;

            case 4:
                printf("\n--- OTIMIZACAO DE COMPRAS ---\n");
                if (catalogo.quantidade == 0) {
                    printf("Cadastre pelo menos uma roupa primeiro!\n");
                } else {
                    printf("Digite seu orcamento: R$ ");
                    scanf("%f", &orcamento);

                    total_gasto = 0.0;
                    printf("\nItens selecionados dentro do orcamento:\n");
                    for (i = 0; i < catalogo.quantidade; i++) {
                        if (total_gasto + catalogo.itens[i].preco <= orcamento) {
                            total_gasto += catalogo.itens[i].preco;
                            printf("- %s: R$ %.2f\n", catalogo.itens[i].nome, catalogo.itens[i].preco);
                        }
                    }
                    printf("-----------------------------------\n");
                    printf("Total gasto : R$ %.2f\n", total_gasto);
                    printf("Troco       : R$ %.2f\n", orcamento - total_gasto);
                }
                break;

            case 0:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
