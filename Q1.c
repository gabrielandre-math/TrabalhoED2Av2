#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <locale.h>


#define NODES 15

typedef struct {
    int NO;
    int distancia;
} Aresta;

typedef struct {
    Aresta arestas[NODES];
    int quantidadeArestas;
} NodoGrafo;

NodoGrafo grafo[NODES + 1];

void adicionarAresta(int de, int para, int distancia) {
    grafo[de].arestas[grafo[de].quantidadeArestas].NO = para;
    grafo[de].arestas[grafo[de].quantidadeArestas].distancia = distancia;
    grafo[de].quantidadeArestas++;
}

int menorDistancia(int dist[], int sptSet[]) {
    int min = INT_MAX, minIndex;
    for (int v = 1; v <= NODES; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void imprimirCaminho2(int pais[], int j, int dist[]) {
    if (pais[j] == -1)
        return;
    imprimirCaminho2(pais, pais[j], dist);
    printf("No %d para %d: Distancia %d. Total percorrido: %d.\n", pais[j], j, dist[j] - dist[pais[j]], dist[j]);
}

void dijkstra(int inicio, int destino) {
    int dist[NODES + 1];
    int sptSet[NODES + 1];
    int pais[NODES + 1];

    for (int i = 1; i <= NODES; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
        pais[i] = -1;
    }

    dist[inicio] = 0;

    for (int count = 1; count <= NODES - 1; count++) {
        int u = menorDistancia(dist, sptSet);
        sptSet[u] = 1;

        for (int i = 0; i < grafo[u].quantidadeArestas; i++) {
            int v = grafo[u].arestas[i].NO;
            int peso = grafo[u].arestas[i].distancia;

            if (!sptSet[v] && dist[u] != INT_MAX && dist[u] + peso < dist[v]) {
                dist[v] = dist[u] + peso;
                pais[v] = u;
            }
        }
    }

    imprimirCaminho2(pais, destino, dist);
    printf("\nMenor distancia possivel percorrida: %d unidades.\n", dist[destino]);
}

int Q1() {
    setlocale(LC_ALL, "Portuguese");
    for (int i = 1; i <= NODES; i++) {
        grafo[i].quantidadeArestas = 0;
    }

    adicionarAresta(1, 2, 8);
    adicionarAresta(1, 13, 10);
    adicionarAresta(2, 1, 8);
    adicionarAresta(2, 3, 10);
    adicionarAresta(2, 14, 7);
    adicionarAresta(3, 2, 10);
    adicionarAresta(3, 4, 12);
    adicionarAresta(3, 5, 9);
    adicionarAresta(4, 3, 12);
    adicionarAresta(4, 8, 14);
    adicionarAresta(5, 3, 9);
    adicionarAresta(5, 6, 4);
    adicionarAresta(5, 7, 3);
    adicionarAresta(6, 5, 4);
    adicionarAresta(6, 14, 8);
    adicionarAresta(6, 7, 5);
    adicionarAresta(7, 5, 3);
    adicionarAresta(7, 6, 5);
    adicionarAresta(7, 8, 9);
    adicionarAresta(8, 4, 14);
    adicionarAresta(8, 7, 9);
    adicionarAresta(8, 15, 10);
    adicionarAresta(9, 10, 4);
    adicionarAresta(9, 11, 16);
    adicionarAresta(9, 15, 9);
    adicionarAresta(10, 9, 4);
    adicionarAresta(10, 11, 11);
    adicionarAresta(11, 10, 11);
    adicionarAresta(11, 9, 16);
    adicionarAresta(11, 12, 8);
    adicionarAresta(12, 11, 8);
    adicionarAresta(12, 13, 13);
    adicionarAresta(13, 1, 10);
    adicionarAresta(13, 12, 13);
    adicionarAresta(13, 14, 6);
    adicionarAresta(14, 13, 6);
    adicionarAresta(14, 2, 7);
    adicionarAresta(14, 6, 8);

    dijkstra(1, 15);

    return 0;
}
