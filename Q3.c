#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

// Fun��o para ler a matriz de adjac�ncias do arquivo CSV
int lerMatrizAdjacencias(char *nomeArquivo, int matriz[][MAX_VERTICES], int *numVertices) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return -1;
    }

    fscanf(arquivo, "%d", numVertices);

    for (int i = 0; i < *numVertices; i++) {
        for (int j = 0; j < *numVertices; j++) {
            fscanf(arquivo, "%d,", &matriz[i][j]);
        }
    }

    fclose(arquivo);
    return 0;
}

// Fun��o para encontrar a aresta de menor peso conectada a uma sub�rvore
int encontrarMinimo(int pesos[], int incluido[], int numVertices) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < numVertices; v++) {
        if (incluido[v] == 0 && pesos[v] < min) {
            min = pesos[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Fun��o para encontrar a �rvore geradora de custo m�nimo usando o algoritmo de Prim
void primMST(int matriz[][MAX_VERTICES], int numVertices) {
    int pais[MAX_VERTICES]; // Armazena a �rvore geradora m�nima
    int pesos[MAX_VERTICES]; // Peso da aresta m�nima para conectar um v�rtice � �rvore
    int incluido[MAX_VERTICES]; // V�rtices j� inclu�dos na �rvore geradora m�nima

    // Inicializa��o
    for (int i = 0; i < numVertices; i++) {
        pesos[i] = INT_MAX;
        incluido[i] = 0;
        pais[i] = -1;
    }

    // A raiz da �rvore ser� o primeiro v�rtice
    pesos[0] = 0;

    // Constru��o da �rvore
    for (int cont = 0; cont < numVertices - 1; cont++) {
        int u = encontrarMinimo(pesos, incluido, numVertices);
        incluido[u] = 1;

        for (int v = 0; v < numVertices; v++) {
            if (matriz[u][v] && incluido[v] == 0 && matriz[u][v] < pesos[v]) {
                pais[v] = u;
                pesos[v] = matriz[u][v];
            }
        }
    }

    // Imprime a �rvore geradora m�nima
    printf("Aresta \t Peso\n");
    for (int i = 0; i < numVertices; i++) {
        if (pais[i] != -1) {
            printf("%d - %d \t %d \n", pais[i], i, matriz[i][pais[i]]);
        }
    }
}

int Q3() {
    int matrizAdjacencias[MAX_VERTICES][MAX_VERTICES];
    int numVertices;

    char nomeArquivo[] = "grafo.csv";
    if (lerMatrizAdjacencias(nomeArquivo, matrizAdjacencias, &numVertices) != 0) {
        return -1;
    }

    // Imprime a matriz de adjac�ncias lida
    printf("Matriz de Adjac�ncias:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", matrizAdjacencias[i][j]);
        }
        printf("\n");
    }

    primMST(matrizAdjacencias, numVertices);

    return 0;
}
