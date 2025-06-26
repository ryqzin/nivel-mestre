#include <stdio.h>
#include <stdlib.h>
#define N 10

int main(){
    char linha[N] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    char coluna[N] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    char tabuleiro[N][N];


    // Inicializa o tabuleiro com água
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tabuleiro[i][j] = '0';
        }
    }

    
    // Navio horizontal na linha 0, colunas 1 a 3
for (int j = 1; j <= 3; j++) {
    tabuleiro[0][j] = '3';
}

// Navio vertical 
for (int i = 4; i <= 6; i++) {
    tabuleiro[i][9] = '3';
}

// Navio diagonal 
for (int k = 0; k <= 3; k++) {
    tabuleiro[7 + k][k] = '3';
}

    // Exemplo: centro das áreas de efeito
    int centro_cone_i = 2, centro_cone_j = 2;
    int centro_cruz_i = 5, centro_cruz_j = 5;
    int centro_octa_i = 7, centro_octa_j = 7;

    // Área de efeito: CONE (para baixo, 3 linhas, largura aumenta)
    for (int i = 0; i < 3; i++) { // altura do cone
        for (int j = -i; j <= i; j++) { // largura do cone
            int x = centro_cone_i + i;
            int y = centro_cone_j + j;
            if (x >= 0 && x < N && y >= 0 && y < N)
                tabuleiro[x][y] = 'C';
        }
    }

    // Área de efeito: CRUZ (linha e coluna do centro, raio 2)
    for (int i = -2; i <= 2; i++) {
        int x = centro_cruz_i + i;
        int y = centro_cruz_j + i;
        if (centro_cruz_i + i >= 0 && centro_cruz_i + i < N)
            tabuleiro[centro_cruz_i + i][centro_cruz_j] = 'X';
        if (centro_cruz_j + i >= 0 && centro_cruz_j + i < N)
            tabuleiro[centro_cruz_i][centro_cruz_j + i] = 'X';
    }

    // Área de efeito: OCTAEDRO (diamante, raio 2)
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            if (abs(i) + abs(j) <= 2) {
                int x = centro_octa_i + i;
                int y = centro_octa_j + j;
                if (x >= 0 && x < N && y >= 0 && y < N)
                    tabuleiro[x][y] = 'O';
            }
        }
    }

    // Exibe o cabeçalho das colunas
    printf("   ");
    for (int j = 0; j < N; j++) {
        printf(" %c ", coluna[j]);
    }
    printf("\n");

    // Exibe as linhas com o conteúdo do tabuleiro
    for (int i = 0; i < N; i++) {
        printf("%c  ", linha[i]);
        for (int j = 0; j < N; j++) {
            printf(" %c ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}