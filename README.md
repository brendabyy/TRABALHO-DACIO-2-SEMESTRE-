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
*(A ser detalhado por Luna)*


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
