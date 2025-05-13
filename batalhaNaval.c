#include <stdio.h>
#define TAMANHO_TABELA 10
#define TAMANHO_PODER 5
void cone(int tabuleiro[TAMANHO_TABELA][TAMANHO_TABELA], int colunaBase, int alturadoCone){
    for (int i = 0; i < alturadoCone; i++) {
        int linha = i;
        int inicio = colunaBase - i;
        int fim = colunaBase + i;

        // Verifica se a linha está dentro do tabuleiro
        if (linha >= TAMANHO_TABELA) break;

        for (int j = inicio; j <= fim; j++) {
            // Verifica se a coluna está dentro do tabuleiro
            if (j >= 0 && j < TAMANHO_TABELA) {
                tabuleiro[linha][j] = 5;
            }
        }
    }

}

void cruz(int tabuleiro[TAMANHO_TABELA][TAMANHO_TABELA], int centroX, int centroY) {
    // Verifica se o centro está dentro do tabuleiro
    if (centroX < 0 || centroX >= TAMANHO_TABELA || centroY < 0 || centroY >= TAMANHO_TABELA) return;

    // Desenha a linha central (horizontal)
    for (int i = -1; i <= 1; i++) {
        if (centroY + i >= 0 && centroY + i < TAMANHO_TABELA) {
            tabuleiro[centroY + i][centroX] = 9;  // Linha vertical
        }
        if (centroX + i >= 0 && centroX + i < TAMANHO_TABELA) {
            tabuleiro[centroY][centroX + i] = 9;  // Linha horizontal
        }
    }
}

void losango(int tabuleiro[TAMANHO_TABELA][TAMANHO_TABELA], int centroX, int centroY) {
    // Verifica se o centro está dentro do tabuleiro
    if (centroX < 0 || centroX >= TAMANHO_TABELA || centroY < 0 || centroY >= TAMANHO_TABELA) return;

    // Desenha a forma de losango (máximo 3x3)
    for (int i = -1; i <= 1; i++) {
        int linha = centroY + i;
        if (linha < 0 || linha >= TAMANHO_TABELA) continue;

        int colInicio = centroX - (1 - abs(i)); // Para o efeito de losango
        int colFim = centroX + (1 - abs(i));

        if (colInicio >= 0 && colInicio < TAMANHO_TABELA) {
            tabuleiro[linha][colInicio] = 5;
        }
        if (colFim >= 0 && colFim < TAMANHO_TABELA) {
            tabuleiro[linha][colFim] = 5;
        }
    }
}

void imprimirTabela(int tabuleiro [TAMANHO_TABELA][TAMANHO_TABELA]){
    char letras[10] = {'A','B','C','D','E','F','G','H','I','J'};
    printf("   ");
    for (int l = 0; l<10;l++){
        printf("%c ", letras[l]);
    }
    printf("\n");

    for (int i=0; i<10; i++){
        
        printf("%2d ", i+1);
        for(int j=0; j<10; j++){
        printf("%d ", tabuleiro[i][j]);    
        }
        printf("\n");
    }

}

void navioReto(int tabuleiro [TAMANHO_TABELA][TAMANHO_TABELA], int coordenadaUm, int coordenadaDois){
    int navio [3]={3,3,3};
    //inicia o navio

    if (coordenadaUm + 2 >= TAMANHO_TABELA) {
        printf("Erro: navio reto ultrapassa o limite do tabuleiro!\n");
        return;
    }
    //verifica se o navio não passou do limite da tabela

    for (int i=0; i<3;i++){
        tabuleiro[coordenadaUm][coordenadaDois] = navio [i];
        coordenadaUm++;
    }//aplica o navio
}
void navioDiagonal(int tabuleiro [TAMANHO_TABELA][TAMANHO_TABELA], int coordenadaUm, int coordenadaDois){
    int navio [3]={3,3,3};
    
    if (coordenadaUm + 2 >= TAMANHO_TABELA || coordenadaDois + 2 >= TAMANHO_TABELA) {
        printf("Erro: navio diagonal ultrapassa o limite do tabuleiro!\n");
        return;
    }//verifica se o navio não passou do limite da tabela

    for (int i=0; i<3;i++){
        tabuleiro[coordenadaUm][coordenadaDois] = navio [i];
        coordenadaUm++,coordenadaDois++;
    }//aplica o navio
}


int main() {

//Iniciando as matrizes e arrays que serão usados para a exibição e funcionamento do jogo
    int tabuleiro [TAMANHO_TABELA][TAMANHO_TABELA];

    for (int i=0; i<TAMANHO_TABELA; i++){
        for (int j=0; j<TAMANHO_TABELA; j++){
            tabuleiro [i][j]=0;
        }
    }


    
    printf("BEM VINDO AO BATALHA NAVAL!\n");
imprimirTabela(tabuleiro);
navioReto(tabuleiro,4,4);
//iniciando o navio e imprimindo a primeira função
    printf("\nVamos adicionar um návio reto\n");
imprimirTabela(tabuleiro);
//imprimindo segunda função
    printf("\nVamos adicionar um navio diagonal\n");
navioDiagonal(tabuleiro,3,6);
imprimirTabela(tabuleiro);
//finalizando com os poderes especiais
printf("\nVamos adicionar um cone, uma cruz e um losango!\n");
cone(tabuleiro,5,3);
cruz(tabuleiro,3,7);
losango(tabuleiro,7,7);
imprimirTabela(tabuleiro);


    return 0;
}
