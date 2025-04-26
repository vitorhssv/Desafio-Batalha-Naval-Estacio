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

// função pra colocar a habilidade de cone no tabuleiro
void habilidade_cone(int x, int y, int tabuleiro[10][10]) {
    int habilidade_cone[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1}
    };

    // normalizando as coordenadas (se a coordenada for 1, passa pra 0 no tabuleiro)
    x = x - 1;
    y = y - 1;

    // checando a coordenada x
    if ((x + 5) > 10) {
        printf("A habilidade não pode ser colocada fora do tabuleiro, seguindo com a coordenada x = 4\n");
        x = 4;
    }

    // checando a coordenada y
    if ((y + 5) > 10) {
        printf("A habilidade não pode ser colocada fora do tabuleiro, seguindo com a coordenada y = 4\n");
        y = 4;
    }

    // colocando a habilidade no tabuleiro
    for (int a = y; a < (y + 5); a++) {
        int habilidade_y = a - y;
        for (int b = x; b < (x + 5); b++) {
            int habilidade_x = b - x;
            if (habilidade_cone[habilidade_y][habilidade_x] == 1) {
                tabuleiro[a][b] = 5;
            }
        }
    }
}

// função colocar a habilidade de cruz no tabuleiro
void habilidade_cruz(int x, int y, int tabuleiro[10][10]) {
    int habilidade_cruz[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };

    // normalizando as coordenadas (se a coordenada for 1, passa pra 0 no tabuleiro)
    x = x - 1;
    y = y - 1;

    // checando a coordenada x
    if ((x + 5) > 10) {
        printf("A habilidade não pode ser colocada fora do tabuleiro, seguindo com a coordenada x = 4\n");
        x = 4;
    }

    // checando a coordenada y
    if ((y + 5) > 10) {
        printf("A habilidade não pode ser colocada fora do tabuleiro, seguindo com a coordenada y = 4\n");
        y = 4;
    }

    // colocando a habilidade no tabuleiro
    for (int a = y; a < (y + 5); a++) {
        int habilidade_y = a - y;
        for (int b = x; b < (x + 5); b++) {
            int habilidade_x = b - x;
            if (habilidade_cruz[habilidade_y][habilidade_x] == 1) {
                tabuleiro[a][b] = 5;
            }
        }
    }
}

// função colocar a habilidade de octaedro no tabuleiro
void habilidade_octaedro(int x, int y, int tabuleiro[10][10]) {
    int habilidade_octaedro[3][3] = {
        {0, 1, 0},
        {1, 1, 1},
        {0, 1, 0}
    };

    // normalizando as coordenadas (se a coordenada for 1, passa pra 0 no tabuleiro)
    x = x - 1;
    y = y - 1;

    // checando a coordenada x
    if ((x + 3) > 10) {
        printf("A habilidade não pode ser colocada fora do tabuleiro, seguindo com a coordenada x = 6\n");
        x = 6;
    }

    // checando a coordenada y
    if ((y + 3) > 10) {
        printf("A habilidade não pode ser colocada fora do tabuleiro, seguindo com a coordenada y = 6\n");
        y = 6;
    }

    // colocando a habilidade no tabuleiro
    for (int a = y; a < (y + 3); a++) {
        int habilidade_y = a - y;
        for (int b = x; b < (x + 3); b++) {
            int habilidade_x = b - x;
            if (habilidade_octaedro[habilidade_y][habilidade_x] == 1) {
                tabuleiro[a][b] = 5;
            }
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

    // colocar as habilidades
    habilidade_cone(3, 1, tabuleiro);
    habilidade_cruz(6, 6, tabuleiro);
    habilidade_octaedro(2, 7, tabuleiro);

    // imprimindo o tabuleiro montado
    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
            printf("%d ", tabuleiro[a][b]);
        }
        printf("\n");
    }
    
    return 0;
}