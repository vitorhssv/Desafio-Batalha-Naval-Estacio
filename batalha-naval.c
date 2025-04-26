#include <stdio.h>
#include <stdlib.h>

int main() {
    // definindo o tabuleiro
    int tabuleiro[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // definindo dois navios
    int navio_horizontal[3] = {3, 3, 3};
    int navio_vertical[3] = {3, 3, 3};

    // colocando os navios e checando se eles cabem no tabuleiro ou se estão se sobrepondo
    // variáveis das coordenadas dos navios em (x, y)
    int coordenadas_navio_horizontal[2] = {8, 8};
    int coordenadas_navio_vertical[2] = {3, 2};

    // checando as coordenadas horizontais do navio horizontal
    if ((coordenadas_navio_horizontal[0] + 3) > 10) {
        printf("O navio não pode ser colocado fora do tabuleiro, seguindo com a coordenada x = 7\n");
        coordenadas_navio_horizontal[0] = 7;
    }

    // checando as coordenadas verticais do navio horizontal
    if (coordenadas_navio_horizontal[1] > 10) {
        printf("O navio não pode ser colocado fora do tabuleiro, seguindo com a coordenada y = 10\n");
        coordenadas_navio_horizontal[1] = 10;
    }

    // colococando o navio horizontal no tabuleiro
    for (int i = coordenadas_navio_horizontal[0]; i < (coordenadas_navio_horizontal[0] + 3); i++) {
        tabuleiro[coordenadas_navio_horizontal[1]][i] = 3;
    }

    // checando as coordenadas horizontais do navio vertical
    if (coordenadas_navio_vertical[0] > 10) {
        printf("O navio não pode ser colocado fora do tabuleiro, seguindo com a coordenada x = 10\n");
        coordenadas_navio_vertical[0] = 10;
    }

    // checando as coordenadas verticais do navio vertical
    if ((coordenadas_navio_vertical[1] + 3) > 10) {
        printf("O navio não pode ser colocado fora do tabuleiro, seguindo com a coordenada y = 7\n");
        coordenadas_navio_vertical[1] = 7;
    }

    // checando se os navios se sobrepoem
    for (int i = coordenadas_navio_vertical[1]; i < (coordenadas_navio_vertical[1] + 3); i++) {
        if (tabuleiro[i][coordenadas_navio_vertical[0]] == 3) {
            printf("ERRO: Os navios se sobrepoem\n");
            exit(1);
        }
    }

    // colococando o navio vertical no tabuleiro
    for (int i = coordenadas_navio_vertical[1]; i < (coordenadas_navio_vertical[1] + 3); i++) {
        tabuleiro[i][coordenadas_navio_vertical[0]] = 3;
    }

    // imprimindo o tabuleiro montado
    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
            printf("%d ", tabuleiro[a][b]);
        }
        printf("\n");
    }
    
    return 0;
}