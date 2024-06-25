#include <stdio.h>
#include <stdbool.h>

#define V 16 // N�mero total de v�rtices

// Fun��o para verificar se � seguro colorir um v�rtice com uma cor espec�fica
bool Seguro(int v, int grafo[V][V], const int cor[], int c) {
    for (int i = 0; i < V; i++)
        if (grafo[v][i] && c == cor[i])
            return false;
    return true;
}

// Fun��o recursiva para resolver o problema de colora��o do grafo
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

// Fun��o para resolver o problema de colora��o do grafo usando m cores
bool coloracaoGrafo(int grafo[V][V], int m) {
    int cor[V];
    for (int i = 0; i < V; i++)
        cor[i] = 0;

    if (!coloracaoGrafoUtil(grafo, m, cor, 0)) {
        printf("Solu��o nao existe");
        return false;
    }

    printf("Cores atribuidas:\n");
    for (int i = 0; i < V; i++)
        printf("Vertice %d -> Cor %d\n", i, cor[i]);
    return true;
}

// Fun��o principal
int Q2() {
    // Matriz de adjac�ncia do grafo descrito
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

    int m = 4; // N�mero de cores
    coloracaoGrafo(grafo, m);

    return 0;
}
