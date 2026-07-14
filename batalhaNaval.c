#include <stdio.h>

int main() {
    // 1. Definição do tabuleiro e variáveis

    int tabuleiro[10][10];
    int i, j;

    // 2. Inicialização
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 3. Posicionamento dos Navios
    
    // Navio 1 
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3;

    // Navio 2: 
    tabuleiro[5][7] = 3;
    tabuleiro[6][7] = 3;
    tabuleiro[7][7] = 3;

    printf("   A B C D E F G H I J\n");

    for (i = 0; i < 10; i++) {
        // Lateral (Números 1-10)
        printf("%2d ", i + 1);

        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        
        // Pula linha para a próxima fila do tabuleiro
        printf("\n");
    }

    return 0;
}