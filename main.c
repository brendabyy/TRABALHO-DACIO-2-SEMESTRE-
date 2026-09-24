#include <stdio.h>
#include <stdlib.h>
#include "roupas.h"

int main() {
    Carrinho catalogo;
    catalogo.quantidade = 0;
    int opcao;
    float orcamento, total_gasto;
    int i;

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
                // Chama a funcao original da Penelope sem alterar o codigo dela
                cadastrarRoupa(&catalogo);
                break;

            case 2:
                // Apaga a ultima roupa inserida
                if (catalogo.quantidade > 0) {
                    catalogo.quantidade--;
                    printf("\nUltima roupa removida com sucesso!\n");
                } else {
                    printf("\nO catalogo ja esta vazio!\n");
                }
                break;

            case 3:
                // Chama a funcao original da Penelope
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
                    printf("\nItens selecionados:\n");
                    for (i = 0; i < catalogo.quantidade; i++) {
                        if (total_gasto + catalogo.itens[i].preco <= orcamento) {
                            total_gasto += catalogo.itens[i].preco;
                            printf("- %s: R$ %.2f\n", catalogo.itens[i].nome, catalogo.itens[i].preco);
                        }
                    }
                    printf("Total gasto: R$ %.2f | Troco: R$ %.2f\n", total_gasto, orcamento - total_gasto);
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
