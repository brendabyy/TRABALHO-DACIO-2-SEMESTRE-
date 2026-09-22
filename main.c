#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo;
    float preco = 0.0;
    char nome_peca[50];
    
    float orcamento = 0.0;
    float total_gasto = 0.0;

    printf("=== SISTEMA OTIMIZADOR DE COMPRAS VIA ARQUIVO ===\n\n");

    // 1. O usuário digita o dinheiro disponível
    printf("Digite o valor do seu orcamento (ex: 300.00): R$ ");
    scanf("%f", &orcamento);

    if (orcamento <= 0) {
        printf("Erro: Informe um valor de orcamento valido!\n");
        return 1;
    }

    // 2. O programa abre o documento com a lista de preços das roupas
    arquivo = fopen("roupas.txt", "r");

    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo 'roupas.txt'! Verifique se o arquivo existe.\n");
        return 1;
    }

    printf("\n--- COMPRAS SELECIONADAS DO ARQUIVO ---\n");

    // 3. O programa lê peça por peça do documento e faz os testes condicionais
    while (fscanf(arquivo, "%f %[^\n]", &preco, nome_peca) != EOF) {
        if (total_gasto + preco <= orcamento) {
            total_gasto = total_gasto + preco;
            printf("- Item selecionado: %s (R$ %.2f)\n", nome_peca, preco);
        }
    }

    // 4. Fecha o arquivo aberto
    fclose(arquivo);

    // 5. Exibição do resumo final
    printf("----------------------------------------\n");
    if (total_gasto == 0) {
        printf("Aviso: Seu orcamento e insuficiente para comprar qualquer item do arquivo.\n");
    } else {
        printf("Total Gasto:  R$ %.2f\n", total_gasto);
        printf("Sobra/Troco:  R$ %.2f\n", orcamento - total_gasto);
    }

    return 0;
}

    return 0;
}
