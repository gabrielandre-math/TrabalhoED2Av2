#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>  // Para a função getcwd

#define MAX_VERTICES 100

// Função para ler a matriz de adjacências do arquivo CSV
int lerMatrizAdjacencias(const char *nomeArquivo, int matriz[][MAX_VERTICES], int *numVertices) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo: %s\n", nomeArquivo);
        perror("Erro");
        return -1;
    }

    if (fscanf(arquivo, "%d", numVertices) != 1) {
        printf("Erro ao ler o número de vértices do arquivo.\n");
        fclose(arquivo);
        return -1;
    }

    for (int i = 0; i < *numVertices; i++) {
        for (int j = 0; j < *numVertices; j++) {
            if (fscanf(arquivo, "%d,", &matriz[i][j]) != 1) {
                printf("Erro ao ler o valor da matriz de adjacências na posição (%d, %d).\n", i, j);
                fclose(arquivo);
                return -1;
            }
        }
    }

    fclose(arquivo);
    return 0;
}

// Função para encontrar a aresta de menor peso conectada a uma subárvore
int encontrarMinimo(const int pesos[], const int incluido[], int numVertices) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < numVertices; v++) {
        if (incluido[v] == 0 && pesos[v] < min) {
            min = pesos[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Função para encontrar a árvore geradora de custo mínimo usando o algoritmo de Prim
void primMST(int matriz[][MAX_VERTICES], int numVertices) {
    int pais[MAX_VERTICES]; // Armazena a árvore geradora mínima
    int pesos[MAX_VERTICES]; // Peso da aresta mínima para conectar um vértice à árvore
    int incluido[MAX_VERTICES]; // Vértices já incluídos na árvore geradora mínima

    // Inicialização
    for (int i = 0; i < numVertices; i++) {
        pesos[i] = INT_MAX;
        incluido[i] = 0;
        pais[i] = -1;
    }

    // A raiz da árvore será o primeiro vértice
    pesos[0] = 0;

    // Construção da árvore
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

    // Imprime a árvore geradora mínima
    printf("Aresta \t Peso\n");
    for (int i = 1; i < numVertices; i++) { // Corrigi a inicialização do loop para começar de 1
        if (pais[i] != -1) {
            printf("%d - %d \t %d \n", pais[i], i, matriz[i][pais[i]]);
        }
    }
}

int Q3() {
    int matrizAdjacencias[MAX_VERTICES][MAX_VERTICES];
    int numVertices;

    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Diretório de trabalho atual: %s\n", cwd);
    } else {
        perror("getcwd() error");
        return -1;
    }

    // Assumindo que o arquivo grafo.csv está no diretório raiz do projeto
    char nomeArquivo[1024];
    snprintf(nomeArquivo, sizeof(nomeArquivo), "%s/../grafo.csv", cwd);

    if (lerMatrizAdjacencias(nomeArquivo, matrizAdjacencias, &numVertices) != 0) {
        return -1;
    }

    // Imprime a matriz de adjacências lida
    printf("Matriz de Adjacências:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", matrizAdjacencias[i][j]);
        }
        printf("\n");
    }

    primMST(matrizAdjacencias, numVertices);

    return 0;
}
