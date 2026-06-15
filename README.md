# Analizador-Rotas-Redes

## Descrição

Este projeto utiliza grafos direcionados para representar rotas de rede obtidas a partir de dados de traceroute. Cada endereço IP é modelado como um vértice e cada conexão entre roteadores como uma aresta direcionada.

O sistema permite visualizar a topologia da rede com Graphviz, encontrar o menor caminho entre dois roteadores, calcular o diâmetro do grafo e identificar os cinco roteadores com maior grau de entrada (indegree).

## Estruturas e Algoritmos Utilizados

* Grafo direcionado com lista de adjacência.
* unordered_map para armazenamento dos vértices.
* Ordenação para identificação dos roteadores mais conectados.
* Exportação para Graphviz nos formatos DOT, PNG e PDF.

## Justificativa

As soluções implementadas seguem os conceitos trabalhados na disciplina, aplicando estruturas de grafos, busca em largura e análise de propriedades da rede de forma eficiente e adequada ao problema proposto.
