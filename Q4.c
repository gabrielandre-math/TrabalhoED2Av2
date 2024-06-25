#include <stdio.h>

#define MAX_LINHAS 24
#define MAX_COLUNAS 11
#define PAREDE -1
#define VISITADO -2
#define A 2
#define B -3

int labirinto[MAX_LINHAS][MAX_COLUNAS] = {
        {PAREDE, PAREDE, PAREDE, PAREDE, PAREDE, PAREDE, PAREDE, PAREDE, PAREDE, PAREDE, PAREDE},
        {PAREDE, A,      0,      0,      0,      0,      1,      PAREDE, 3,      PAREDE, PAREDE},
        {PAREDE, 6,      PAREDE, PAREDE, PAREDE, PAREDE, PAREDE, 0,      0,      PAREDE, PAREDE},
        {PAREDE, 4,      0,      0,      0,      0,      5,     PAREDE, 7,      8,      PAREDE},
        {PAREDE, 0,      PAREDE, PAREDE, PAREDE, PAREDE, 0,      PAREDE, PAREDE, 0,      PAREDE},
        {PAREDE, 9,     10,     PAREDE, 12,     13,     0,      PAREDE, 14,     0,      15,     PAREDE},
        {PAREDE, 0,      0,      PAREDE, 0,      PAREDE, 0,      PAREDE, PAREDE, 0,      PAREDE},
        {PAREDE, 0,     PAREDE, 0,      17,    PAREDE, 19,     0,      20,    PAREDE, PAREDE},
        {PAREDE, 0,      PAREDE, PAREDE, PAREDE, 0,      PAREDE, PAREDE, 0,      PAREDE, PAREDE},
        {PAREDE, 0,     PAREDE, 0,      23,    PAREDE, 25,    PAREDE, PAREDE, 28,     PAREDE},
        {PAREDE, 0,      PAREDE, PAREDE, 0,      PAREDE, 0,      0,      PAREDE, 0,      PAREDE},
        {PAREDE, 29,     30,    PAREDE, 32,    PAREDE, 34,     0,     PAREDE, 0,      PAREDE},
        {PAREDE, PAREDE, 0,      0,      PAREDE, 0,      PAREDE, 0,      0,      0,      PAREDE},
        {PAREDE, 36,     0,      0,      37,     38,     39,     40,     0,      0,      PAREDE},
        {PAREDE, 0,      0,      0,      0,      PAREDE, 0,      PAREDE, 0,      0,      PAREDE},
        {PAREDE, 0,      0,     PAREDE, 42,     PAREDE, 44,     45,     46,     0,      PAREDE},
        {PAREDE, 0,      0,      0,      PAREDE, PAREDE, PAREDE, 0,      PAREDE, PAREDE, PAREDE},
        {PAREDE, 0,      0,     PAREDE, 0,      0,      48,     49,     0,      50,     PAREDE},
        {PAREDE, 0,      0,      0,      PAREDE, PAREDE, 0,      PAREDE, PAREDE, 0,      PAREDE},
        {PAREDE, 0,      51,     52,     53,     0,      54,     55,     56,     0,      B},
        {PAREDE, 0,      0,      0,      0,      PAREDE, PAREDE, 0,      PAREDE, 0,      PAREDE},
        {PAREDE, 57,     58,    PAREDE, PAREDE, 0,      0,      61,    PAREDE, 63,     PAREDE},
        {PAREDE, PAREDE, PAREDE, PAREDE, PAREDE, PAREDE, PAREDE, PAREDE, PAREDE, PAREDE, PAREDE}
};

int dentroDosLimites(int x, int y) {
    return (x >= 0 && x < MAX_LINHAS && y >= 0 && y < MAX_COLUNAS);
}

void imprimirLabirinto(int caminho[MAX_LINHAS][MAX_COLUNAS]) {
    printf("\nLabirinto:\n\n");
    for (int i = 0; i < MAX_LINHAS; i++) {
        for (int j = 0; j < MAX_COLUNAS; j++) {
            if (labirinto[i][j] == PAREDE) {
                printf("### ");
            } else if (caminho[i][j] != 0) {
                printf(" ** ");
            } else if (labirinto[i][j] == A) {
                printf(" A  ");
            } else if (labirinto[i][j] == B) {
                printf(" B  ");
            } else {
                printf("%02d  ", labirinto[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int resolverLabirinto(int x, int y, int caminho[MAX_LINHAS][MAX_COLUNAS], int dir) {
    if (!dentroDosLimites(x, y) || labirinto[x][y] == PAREDE || labirinto[x][y] == VISITADO || caminho[x][y] != 0) {
        return 0;
    }

    caminho[x][y] = dir;

    if (labirinto[x][y] == B) {
        return 1;
    }

    labirinto[x][y] = VISITADO; // Marca a célula como visitada

    if (resolverLabirinto(x, y + 1, caminho, 2) || resolverLabirinto(x + 1, y, caminho, 3) ||
        resolverLabirinto(x, y - 1, caminho, 4) || resolverLabirinto(x - 1, y, caminho, 1)) {
        return 1;
    }

    caminho[x][y] = 0;  // Limpa o caminho se não encontrar uma solução
    labirinto[x][y] = 0; // Desmarca a célula como visitada
    return 0;
}

int Q4() {
    int startX = 1;
    int startY = 1;
    int caminho[MAX_LINHAS][MAX_COLUNAS] = {0};

    printf("Labirinto original:\n");
    imprimirLabirinto(caminho);

    if (resolverLabirinto(startX, startY, caminho, 0)) {
        printf("Caminho encontrado!\n");
    } else {
        printf("Não há caminho para a saída.\n");
    }

    printf("Labirinto após busca:\n");
    imprimirLabirinto(caminho);

    return 0;
}


