#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declaracao das variaveis
    FILE *arquivo;
    float preco;
    char nome_peca[50];
    float orcamento;
    float total_gasto = 0.0;

    printf("=== OTIMIZADOR DE COMPRAS ===\n\n");

    // Pedir o orcamento ao usuario
    printf("Digite quanto dinheiro voce tem: R$ ");
    scanf("%f", &orcamento);

    // Abrir o arquivo de roupas para leitura
    arquivo = fopen("roupas.txt", "r");

    // Verificar se o arquivo existe
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo roupas.txt!\n");
        system("pause");
        return 1;
    }

    printf("\n--- ITENS COMPRADOS ---\n");

    // Ler o arquivo linha por linha ate o final
    while (fscanf(arquivo, "%f %s", &preco, nome_peca) != EOF) {
        // Se o preco da roupa couber no orcamento
        if (total_gasto + preco <= orcamento) {
            total_gasto = total_gasto + preco;
            printf("- %s: R$ %.2f\n", nome_peca, preco);
        }
    }

    // Fechar o arquivo
    fclose(arquivo);

    // Mostrar o total e o troco
    printf("\n-------------------------\n");
    printf("Total gasto: R$ %.2f\n", total_gasto);
    printf("Troco: R$ %.2f\n", orcamento - total_gasto);

    system("pause");
    return 0;
}
