#include <stdio.h>
#include <stdbool.h>

#define V 16 // Número total de vértices

// Função para verificar se é seguro colorir um vértice com uma cor específica
bool Seguro(int v, int grafo[V][V], const int cor[], int c) {
    for (int i = 0; i < V; i++)
        if (grafo[v][i] && c == cor[i])
            return false;
    return true;
}

// Função recursiva para resolver o problema de coloração do grafo
bool coloracaoGrafoUtil(int grafo[V][V], int m, int cor[], int v) {
    if (v == V)
        return true;

    for (int c = 1; c <= m; c++) {
        if (Seguro(v, grafo, cor, c)) {
            cor[v] = c;
            if (coloracaoGrafoUtil(grafo, m, cor, v + 1))
                return true;
            cor[v] = 0;
        }
    }
    return false;
}

// Função para resolver o problema de coloração do grafo usando m cores
bool coloracaoGrafo(int grafo[V][V], int m) {
    int cor[V];
    for (int i = 0; i < V; i++)
        cor[i] = 0;

    if (!coloracaoGrafoUtil(grafo, m, cor, 0)) {
        printf("Solução nao existe");
        return false;
    }

    printf("Cores atribuidas:\n");
    for (int i = 0; i < V; i++)
        printf("Vertice %d -> Cor %d\n", i, cor[i]);
    return true;
}

// Função principal
int Q2() {
    // Matriz de adjacência do grafo descrito
    int grafo[V][V] = {
        //0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15
        { 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, // 0
        { 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, // 1
        { 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0 }, // 2
        { 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 }, // 3
        { 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0 }, // 4
        { 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, // 5
        { 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 }, // 6
        { 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0 }, // 7
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 }, // 8
        { 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0 }, // 9
        { 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0 }, // 10
        { 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 }, // 11
        { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, // 12
        { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1 }, // 13
        { 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, // 14
        { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0 }  // 15
    };

    int m = 4; // Número de cores
    coloracaoGrafo(grafo, m);

    return 0;
}
