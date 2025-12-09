
#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define AFETADO 5
#define AGUA 0
#define TAM_H 5

void criarCone(int h[TAM_H][TAM_H]) {
    int centro = TAM_H / 2;
    for (int r = 0; r < TAM_H; r++) {
        for (int c = 0; c< TAM_H; c++) {
            if (c >= centro - r && c <= centro + r) h[r][c] = 1;
            else h[r][c] = 0;
        }
    }
}
void criarCruz(int h[TAM_H][TAM_H]){
    int centro = TAM_H / 2;
    for (int r = 0; r < TAM_H; r++) {
        for (int c = 0; c < TAM_H; c++) {
            if (r == centro || c == centro) h[r][c] = 0;
        }
    }
}
void criarOctaedro(int h[TAM_H][TAM_H]) {
    int centro = TAM_H / 2;
    for (int r = 0; r < TAM_H; r++) {
        for (int c = 0; c < TAM_H; c++) {
            int dist = (r > centro ? r - centro : centro - r) + (c > centro ? c - centro : centro - c);
            if (dist <= centro) h[r][c] = 1;
            else h[r][c] = 0;
        }
    }
}
void aplicarHabilidade(int tab[TAM][TAM], int ability[TAM_H][TAM_H], int origRow, int origCol) {
    int meio = TAM_H / 2;
    for (int ar = 0; ar < TAM_H; ar++) {
        for (int ac = 0; ac < TAM_H; ac++) {
            if (ability[ar][ac] == 1) {
                int tr = origRow + (ar - meio);
                int tc = origCol + (ac - meio);
                if (tr >= 0 && tr < TAM && tc >= 0 && tc < TAM) {
                    tab[tr][tc] = AFETADO; 
                }
            }
        }
    }
}


void imprimirTabuleiro(int tab[TAM][TAM]) {
    printf("** Tabuleiro Batalha Naval - Nível Mestre **\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int tabuleiro[TAM][TAM];
    int i, j;

    
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    int linha_vertical = 5;
    int coluna_vertical = 1;

    
    for (j = 0; j < 3; j++) {
        tabuleiro[linha_horizontal][coluna_horizontal + j] = NAVIO;
    }

    
    for (i = 0; i < 3; i++) {
        if (tabuleiro[linha_vertical + i][coluna_vertical] == 0) {
            tabuleiro[linha_vertical + i][coluna_vertical] = NAVIO;
        }
    }

    
    int cone[TAM_H][TAM_H];
    int cruz[TAM_H][TAM_H];
    int octa[TAM_H][TAM_H];

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octa);

    
    int origemConeLinha = 1, origemConeColuna = 3;   
    int origemCruzLinha = 6, origemCruzColuna = 4;   
    int origemOctaLinha = 4, origemOctaColuna = 8;   
    
    aplicarHabilidade(tabuleiro, cone, origemConeLinha, origemConeColuna);
    aplicarHabilidade(tabuleiro, cruz, origemCruzLinha, origemCruzColuna);
    aplicarHabilidade(tabuleiro, octa, origemOctaLinha, origemOctaColuna);

    
    imprimirTabuleiro(tabuleiro);

    return 0;
}
