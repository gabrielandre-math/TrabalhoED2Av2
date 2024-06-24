# Projeto de Estrutura de Dados II

## Alunos Envolvidos
- Gabriel Pinheiro
- Gabriel André
- Jonas Alves

## Professor
- Dr. Denis Gonçalves Cople

## Descrição do Projeto

Este projeto, desenvolvido para a disciplina de Estrutura de Dados II, sob orientação do professor Dr. Denis Gonçalves Cople, tem como objetivo a implementação e análise de algoritmos fundamentais em C. O foco principal é o entendimento da complexidade de tempo dos algoritmos através de exemplos práticos e gráficos gerados por código Python.

## Conteúdo

### Questão 1: Algoritmo de Dijkstra

#### Introdução
Implementação do algoritmo de Dijkstra para encontrar o caminho mais curto em um grafo.

#### Estruturas de Dados
- **Aresta**: Representa uma aresta no grafo.
- **NodoGrafo**: Representa um nó no grafo com suas arestas.
- **Grafo**: Representação do grafo como um array de `NodoGrafo`.

#### Funções Principais
- **adicionarAresta**: Adiciona uma aresta ao grafo.
- **menorDistancia**: Encontra o nó com a menor distância não processado.
- **imprimirCaminho2**: Imprime o caminho do nó inicial ao nó destino.
- **dijkstra**: Implementa o algoritmo de Dijkstra.
- **Q1**: Inicializa o grafo, adiciona arestas e executa o algoritmo de Dijkstra.

### Questão 2: Coloração de Grafos

#### Introdução
Solução para o problema de coloração de grafos utilizando backtracking.

#### Estruturas e Funções
- **Seguro**: Verifica se é seguro colorir um vértice com uma cor específica.
- **coloracaoGrafoUtil**: Função recursiva que tenta resolver o problema de coloração.
- **coloracaoGrafo**: Inicializa e tenta colorir o grafo.
- **Q2**: Inicializa a matriz de adjacência e executa a coloração do grafo.

### Questão 3: Algoritmo de Prim

#### Introdução
Implementação do algoritmo de Prim para encontrar a árvore geradora mínima (MST) de um grafo.

#### Funções Principais
- **lerMatrizAdjacencias**: Lê a matriz de adjacências de um arquivo CSV.
- **encontrarMinimo**: Encontra a aresta de menor peso que conecta um vértice não incluído na MST a um vértice incluído.
- **primMST**: Implementa o algoritmo de Prim.
- **Q3**: Lê a matriz de adjacências, imprime a matriz e encontra a MST.

### Questão 4: Busca em Profundidade (DFS) no Labirinto

#### Introdução
Algoritmo de busca em profundidade para encontrar um caminho em um labirinto.

#### Funções Principais
- **imprimirLabirinto**: Imprime o labirinto.
- **imprimirCaminho**: Imprime o caminho encontrado.
- **ehValido**: Verifica se uma posição no labirinto é válida.
- **dfs**: Implementa o algoritmo DFS.
- **main2**: Inicializa a posição inicial, imprime o labirinto e executa o DFS.

## Contribuições

Contribuições para a melhoria e ampliação deste projeto são bem-vindas. Sinta-se à vontade para abrir issues e pull requests.

---

Este projeto é uma atividade acadêmica desenvolvida no contexto da disciplina de Estrutura de Dados II, com o objetivo de aprofundar o conhecimento teórico e prático dos algoritmos estudados.
