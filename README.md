 Sistema Otimizador de Compras de Roupas

## 1 Descrição do Sistema
O projeto consiste em um sistema desenvolvido em linguagem C com o objetivo de auxiliar o usuário a escolher peças de roupas dentro de um orçamento fixo (por exemplo, R$ 300,00). 

O programa recebe os preços das peças disponíveis e o valor disponível do usuário. Em seguida, utiliza estruturas condicionais para verificar as peças que cabem no orçamento e calcular o total a ser gasto e o troco resultante.

## 2 Fluxo de Utilização Esperado para O Sistema
1. O usuário executa o programa e visualiza as peças de roupas disponíveis com seus respectivos preços.
2. O programa solicita que o usuário digite o valor do seu orçamento (ex: 300.00).
3. O sistema calcula e exibe na tela se o valor é suficiente, quais itens podem ser comprados dentro desse valor, o total gasto e o troco.
4. Caso o orçamento seja insuficiente para os itens selecionados, o sistema exibe uma mensagem de aviso.

## 3 Fluxograma da Lógica do Sistema
O fluxograma representa o funcionamento geral do
Sistema Otimizador de Compras de Roupas.
Inicialmente, o sistema carrega o catálogo de roupas
armazenado em arquivo e apresenta um menu interativo
ao usuário.
Por meio do menu, o usuário pode cadastrar novas peças,
consultar as roupas disponíveis, realizar a otimização
das compras com base em um orçamento informado ou
encerrar o programa.
No cadastro, o sistema valida os dados informados e
armazena as roupas no catálogo. Na consulta, apresenta
as peças cadastradas em formato de tabela.
Na opção de otimização, o sistema verifica quais peças
podem ser compradas sem ultrapassar o orçamento,
apresentando o total gasto e o saldo restante.

## 4. Estrutura de Dados
4. Estrutura de Dados

O sistema utiliza estruturas (struct) para organizar as informações das roupas cadastradas.

Struct Roupa

A estrutura Roupa é utilizada para armazenar os dados de cada peça cadastrada no sistema.

Ela possui os seguintes campos:

* nome: armazena o nome da peça de roupa, utilizando um vetor de caracteres (char).
* preco: armazena o preço da peça, utilizando o tipo float, permitindo trabalhar com valores decimais.

Exemplo:

typedef struct {
    char nome[50];
    float preco;
} Roupa;

As roupas são armazenadas em um vetor, permitindo que o sistema tenha várias peças cadastradas ao mesmo tempo.

Struct Carrinho

A estrutura Carrinho é utilizada para representar as peças selecionadas pelo usuário.

Ela possui:

* itens: vetor que armazena as roupas do carrinho.
* quantidade: indica a quantidade de roupas armazenadas no carrinho.

Exemplo:

typedef struct {
    Roupa itens[MAX_ROUPAS];
    int quantidade;
} Carrinho;

Persistência dos dados

Para que as roupas cadastradas não sejam perdidas quando o programa for encerrado, o sistema utiliza o arquivo roupas.txt.

A função salvarRoupas() grava os dados das roupas no arquivo, enquanto a função carregarRoupas() realiza a leitura do arquivo quando o sistema é iniciado.

Dessa forma, as informações cadastradas podem ser utilizadas novamente em uma próxima execução do programa.

Tratamento de erros

Durante a manipulação do arquivo, o sistema verifica se o arquivo pode ser aberto corretamente. Caso ocorra uma falha, uma mensagem de erro é exibida ao usuário.

Também é tratado o caso em que o arquivo não existe ou está vazio, permitindo que o sistema seja iniciado sem roupas cadastradas.


##  Divisão de Responsabilidades e Contribuições

Este projeto foi desenvolvido de forma modular e colaborativa pela equipe:

* **Brenda (Líder do Projeto)**:
  * Criação do arquivo principal (`main.c`) e fluxo do menu interativo.
  * Implementação da lógica de otimização de orçamento e troco.
  * Lógica para remoção do último item do carrinho e controle de versão no GitHub.

* **Penélope**:
  * Criação do módulo de interface e gerenciamento (`gerenciador.c`).
  * Desenvolvimento da função de cadastro de peças (`cadastrarRoupa`).
  * Desenvolvimento da função de listagem do catálogo (`listarRoupas`).

* **Luna**:
  * Definição da estrutura de dados e protótipos de funções no cabeçalho (`roupas.h`).
  * Estruturação e criação do arquivo base de dados (`roupas.txt`).
  * Documentação das estruturas (`struct Roupa` e `struct Carrinho`) no README.md.
