#ifndef ROUPAS_H
#define ROUPAS_H

#define MAX_ROUPAS 100

typedef struct {
    char nome[50];
    float preco;
} Roupa;

typedef struct {
    Roupa itens[MAX_ROUPAS];
    int quantidade;
} Carrinho;

// Funcoes do Gerenciador (Penelope)
void cadastrarRoupa(Carrinho *catalogo);
void listarRoupas(const Carrinho *catalogo);


#endif
