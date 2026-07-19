#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10

// essa funçao recebe o tabuleiro (10x10), a matriz de habilidade (5x5) e o centro de (origem desejado)
void aplicarhabilidade(int tabuleiro[LINHAS][COLUNAS], int habilidade[5][5], int origem_r, int origem_c) {
    //percorre a matriz de habilidade (5x5)
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++) {

            // verifica se a habilidade tem efeito na posiçao de valor 1
            if(habilidade[i][j] == 1){

                //calcula a posiçao no tabuleiro baseada na origem e no ajuste de centralizar

                int r = origem_r + (i - 2);
                int c = origem_c + (j - 2);

                //validaçao de limite do tabuleiro
                if(r >= 0 && r < LINHAS && c >= 0 && c < COLUNAS) {

                    // condiçao que aplica a habilidade (5) na casa se foragua (0)
                    // preserva os navios (3) se a habilidade atingir
                    if(tabuleiro[r][c] == 0) {
                        tabuleiro[r][c] = 5;
                    }
                }
            }
        }
    }
}

int main(){

int tabuleiro[LINHAS][COLUNAS];


    for(int i = 0; i < LINHAS; i++){
        for(int j = 0; j < COLUNAS; j++){

            tabuleiro[i][j] = 0;
        }
    }
// 2 - Posicionar os navios

    //Navio 1 Vertical

    int l_ver1 = 4, c_hor1 = 1;
        for(int k = 0; k < 3; k++){
            int r = l_ver1 + k;                // r = row(linhas)
                int c = c_hor1;                    // c = colunas
        if (r >= 0 && r < LINHAS && c >= 0 && c < COLUNAS && tabuleiro[r][c] == 0) // validando posiçoes dos navios
        {
            tabuleiro[r][c] = 3;                        
        }
    }
    // Navio 2 Horizontal

    int l_ver2 = 1, c_hor2 = 1;
        for(int k = 0; k < 3; k++){
            int r = l_ver2;                    // r = row(linhas)
                int c = c_hor2 + k;                // c = colunas
        if (r >= 0 && r < LINHAS && c >= 0 && c < COLUNAS && tabuleiro[r][c] == 0) // validando posiçoes dos navios
        {
            tabuleiro[r][c] = 3;
        }
    }
    // navio 3 Diagonal principal

    int l_diag1 = 4, c_diag1 = 4;
        for(int k = 0; k < 3; k++){
            int r = l_diag1 + k;                // r = row(linhas)
                int c = c_diag1 + k;                // c = colunas
        if (r >= 0 && r < LINHAS && c >= 0 && c < COLUNAS && tabuleiro[r][c] == 0) // validando posiçoes dos navios
        {
            tabuleiro [r][c] = 3;
        }
    }
    // navio 4 diagonal secundaria

    int l_diag2 = 1, c_diag2 = 8;
        for(int k = 0; k < 3; k++){
            int r = l_diag2 + k;                // r = row(linhas)
                int c = c_diag2 - k;                // c = colunas
        if(r >= 0 && r < LINHAS && c >= 0 && c < COLUNAS && tabuleiro[r][c] == 0) // validando posiçoes dos navios
        {  
            tabuleiro[r][c] = 3;
        }
    }
    //  DEFINIR AS HABILIDADES

    //Habilidade - Cruz
    int cruz[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };

    //Habilidade - Cone
    int cone[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0 ,0 ,0},
        {0, 0, 0, 0, 0}
    };

    //Habilidade octaedro 
    int octaedro[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // aplicar as habilidades

    aplicarhabilidade(tabuleiro, cruz, 5, 5);     // centralizada
    aplicarhabilidade(tabuleiro, cone, 2, 2);     //  cone topo esquerdo
    aplicarhabilidade(tabuleiro, octaedro, 7, 7); // octaedro na canto inferior direito

    // exibindo tabuleiro

    printf("   A B C D E F G H I J\n");

    for(int i = 0; i < LINHAS; i++){
        printf("%d  ", i);                     // linha para aparecer os numeros na lateral
            for(int j = 0; j < COLUNAS; j++){
                printf("%d ",tabuleiro[i][j]);
            }
        printf("\n");
    }
    
    return 0;
}