#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10

int main(){

int tabuleiro[LINHAS][COLUNAS];
int linha_vertical = 2;
int coluna_horizontal = 3;


    for(int i = 0; i < LINHAS; i++){
        for(int j = 0; j < COLUNAS; j++){

            tabuleiro[i][j] = 0;
        }
    }
// 2 - Posicionar os navios

    //Navio 1 Vertical

    int l_ver1 = 4, c_hor1 = 1;
        for(int k = 0; k < 3; k++){
            tabuleiro[l_ver1 + k][c_hor1] = 3;
        }
    // Navio 2 Horizontal

    int l_ver2 = 1, c_hor2 = 1;
        for(int k = 0; k < 3; k++){
            tabuleiro[l_ver2][c_hor2 + k] = 3;
        }
    // navio 3 Diagonal principal

    int l_diag1 = 4, c_diag1 = 4;
        for(int k = 0; k < 3; k++){
            tabuleiro[l_diag1 + k][c_diag1 + k] = 3;
        }
    // navio 4 diagonal secundaria

    int l_diag2 = 1, c_diag2 = 8;
        for(int k = 0; k < 3; k++){
            tabuleiro[l_diag2 + k][c_diag2 - k] = 3;
        }
    // exibindo tabuleiro

    printf("   A B C D E F G H I J\n");

    for(int i = 0; i < LINHAS; i++){
        printf("%d  ", i);
            for(int j = 0; j < COLUNAS; j++){
                printf("%d ",tabuleiro[i][j]);
            }
        printf("\n");
    }
    
    return 0;
}