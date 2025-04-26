#include <stdio.h>
#include <stdlib.h>

// função pra colocar um navio horizontal no tabuleiro
void colocar_navio_horizontal(int x, int y, int tabuleiro[10][10]) {
    // normalizando as coordenadas (se a coordenada for 1, passa pra 0 no tabuleiro)
    x = x - 1;
    y = y - 1;

    // checando a coordenada x
    if ((x + 3) > 10) {
        printf("O navio não pode ser colocado fora do tabuleiro, seguindo com a coordenada x = 7\n");
        x = 7;
    }

    // checando a coordenada y
    if (y > 10) {
        printf("O navio não pode ser colocado fora do tabuleiro, seguindo com a coordenada y = 10\n");
        y = 10;
    }

    // colococando o navio no tabuleiro, imprime um erro caso o navio esteja sobrepondo outro
    for (int i = x; i < (x + 3); i++) {
        if (tabuleiro[y][i] == 3) {
            printf("ERRO: Os navios se sobrepoem\n");
            exit(1);
        } else {
            tabuleiro[y][i] = 3;
        }
    }
}

// função pra colocar um navio vertical no tabuleiro
void colocar_navio_vertical(int x, int y, int tabuleiro[10][10]) {
    // normalizando as coordenadas (se a coordenada for 1, passa pra 0 no tabuleiro)
    x = x - 1;
    y = y - 1;

    // checando a coordenada x
    if (x > 10) {
        printf("O navio não pode ser colocado fora do tabuleiro, seguindo com a coordenada x = 10\n");
        x = 10;
    }

    // checando a coordenada y
    if ((y + 3) > 10) {
        printf("O navio não pode ser colocado fora do tabuleiro, seguindo com a coordenada y = 7\n");
        y = 7;
    }

    // colococando o navio no tabuleiro, imprime um erro caso o navio esteja sobrepondo outro
    for (int i = x; i < (x + 3); i++) {
        if (tabuleiro[i][x] == 3) {
            printf("ERRO: Os navios se sobrepoem\n");
            exit(1);
        } else {
            tabuleiro[i][x] = 3;
        }
    }
}

// função pra colocar um navio diagonal no tabuleiro
void colocar_navio_diagonal(int x, int y, int tabuleiro[10][10]) {
    // normalizando as coordenadas (se a coordenada for 1, passa pra 0 no tabuleiro)
    x = x - 1;
    y = y - 1;

    // checando a coordenada x
    if ((x + 3) > 10) {
        printf("O navio não pode ser colocado fora do tabuleiro, seguindo com a coordenada x = 7\n");
        x = 7;
    }

    // checando a coordenada y
    if ((y + 3) > 10) {
        printf("O navio não pode ser colocado fora do tabuleiro, seguindo com a coordenada y = 7\n");
        y = 7;
    }

    // colococando o navio no tabuleiro, imprime um erro caso o navio esteja sobrepondo outro
    for (int i = x; i < (x + 3); i++) {
        if (tabuleiro[y + (i - x)][i] == 3) {
            printf("ERRO: Os navios se sobrepoem\n");
            exit(1);
        } else {
            tabuleiro[y + (i - x)][i] = 3;
        }
    }
}

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

    // colocando os navios no tabuleiro
    colocar_navio_horizontal(2, 3, tabuleiro);
    colocar_navio_vertical(7, 9, tabuleiro);
    colocar_navio_diagonal(3, 5, tabuleiro);
    colocar_navio_diagonal(7, 2, tabuleiro);

    // imprimindo o tabuleiro montado
    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
            printf("%d ", tabuleiro[a][b]);
        }
        printf("\n");
    }
    
    return 0;
}