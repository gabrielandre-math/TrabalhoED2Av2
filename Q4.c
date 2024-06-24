#include <stdio.h>
#include <stdlib.h>

#define MAX_LINHAS 22
#define MAX_COLUNAS 9
#define PAREDE -1
#define LIVRE 0
#define VISITADO 2
#define A 2
#define B -3

// Estrutura para representar uma posição no labirinto
typedef struct {
    int linha;
    int coluna;
} Posicao;

// Labirinto exemplo
int labirinto[MAX_LINHAS][MAX_COLUNAS] = {
    { A,  0,  0,  0,  0,  0,  1, -2,  3},
    { 0,  PAREDE,  PAREDE,  PAREDE,  PAREDE,  PAREDE,  0,  0,  PAREDE},
    { 4,  0,  0,  0,  0,  5, -6,  7,  8},
    { 0,  PAREDE,  PAREDE,  PAREDE,  PAREDE,  0,  PAREDE,  PAREDE,  0},
    { 9, 10, 11, 12, 13,  0, 14,  0, 15},
    { 0,  0,  PAREDE,  0,  PAREDE,  0,  PAREDE,  PAREDE,  0},
    { 0, -16,  0, 17, -18, 19,  0, 20, -21},
    { 0,  PAREDE,  PAREDE,  PAREDE,  0,  PAREDE,  PAREDE,  0,  PAREDE},
    { 0, -22,  0, 23, -24, 25, -26, 27, 28},
    { 0,  PAREDE,  PAREDE,  0,  PAREDE,  0,  0,  PAREDE,  0},
    {29, 30, -31, 32, -33, 34,  0, -35,  0},
    { PAREDE,  0,  0,  PAREDE,  0,  PAREDE,  0,  0,  0},
    {36,  0,  0, 37, 38, 39, 40,  0,  0},
    { 0,  0,  0,  0,  PAREDE,  0,  PAREDE,  0,  0},
    { 0, -0, -0, PAREDE, 42, PAREDE, 44, 45, 46},
    { 0,  0,  0, PAREDE, PAREDE, PAREDE,  0, PAREDE, PAREDE},
    { 0,  0, -47,  0,  0, 48, 49,  0, 50},
    { 0,  0,  0, PAREDE, PAREDE,  0, PAREDE, PAREDE,  0},
    { 0, 51, 52, 53,  0, 54, 55, 56, -B},
    { 0,  0,  0,  0,  PAREDE, PAREDE,  0, PAREDE,  0},
    {57, 58, -59, -60,  0,  0, 61, -62, 63}
};

// Função para imprimir o labirinto
void imprimirLabirinto() {
    for (int i = 0; i < MAX_LINHAS; i++) {
        for (int j = 0; j < MAX_COLUNAS; j++) {
            printf("%3d ", labirinto[i][j]);
        }
        printf("\n");
    }
}

// Função para imprimir o caminho encontrado
void imprimirCaminho(Posicao caminho[], int passos) {
    for (int i = 0; i < passos; i++) {
        printf("(%d, %d) ", caminho[i].linha, caminho[i].coluna);
    }
    printf("\n");
}
// Verifica se a posição é válida e livre para mover
int ehValido(int linha, int coluna) {
    if (linha >= 0 && linha < MAX_LINHAS && coluna >= 0 && coluna < MAX_COLUNAS && labirinto[linha][coluna] != PAREDE && labirinto[linha][coluna] != VISITADO) {
        return 1;
    }
    return 0;
}

// Algoritmo DFS para encontrar o caminho no labirinto
int dfs(int linha, int coluna, Posicao caminho[], int passos) {
    // Se chegou no destino (ponto B)
    if (labirinto[linha][coluna] == B) {
        imprimirCaminho(caminho, passos);
        return 1;
    }

    // Direções para mover: esquerda, direita, cima, baixo
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    // Marca a posição atual como visitada
    labirinto[linha][coluna] = VISITADO;
    caminho[passos].linha = linha;
    caminho[passos].coluna = coluna;
    passos++;

    // Tenta todas as direções possíveis
    for (int i = 0; i < 4; i++) {
        int novaLinha = linha + dx[i], novaColuna = coluna + dy[i];

        // Se a nova posição é válida e livre
        if (ehValido(novaLinha, novaColuna)) {
            if (dfs(novaLinha, novaColuna, caminho, passos)) {
                return 1;
            }
        }
    }

    // Backtracking: desmarca a posição atual e volta
    passos--;
    labirinto[linha][coluna] = LIVRE;

    return 0;
}

int main2() {
    // Posição inicial (ponto A)
    Posicao inicial = {0, 0};

    // Inicializa array para armazenar o caminho
    Posicao caminho[MAX_LINHAS * MAX_COLUNAS];

    // Imprime o labirinto para verificação
    printf("Labirinto:\n");
    imprimirLabirinto();

    // Executa a busca em profundidade (DFS) a partir do ponto A
    printf("\nCaminho encontrado:\n");
    if (!dfs(inicial.linha, inicial.coluna, caminho, 0)) {
        printf("Não há caminho possível.\n");
    }

    return 0;
}


