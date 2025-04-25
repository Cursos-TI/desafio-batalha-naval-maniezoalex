#include <stdio.h>
#define TAMANHO_TABELA 10
#define TAMANHO_PODER 5

void cone(int tabela[TAMANHO_TABELA][TAMANHO_TABELA], int comeco, int tamanho){
    int matriz [TAMANHO_PODER][TAMANHO_PODER];
    int centro = TAMANHO_PODER/2, altura = tamanho;

    // Inicializa a matriz com zeros
    for (int i = 0; i < TAMANHO_PODER; i++) {
        for (int j = 0; j < TAMANHO_PODER; j++) {
            matriz[i][j] = 0;
            }
        }
    //Adiciona o cone
    for (int i=0; i<altura; i++){
        int inicio = centro - i;
        int fim = centro + i;
        
        for(int j=inicio; j<=fim; j++){
            matriz[i][j] = 5;
        }
    }

    for (int i=0; i<altura; i++){
        int inicio = centro - i;
        int fim = centro + i;
        
        for(int j=inicio; j<=fim; j++){
            tabela[i][j] = 5;
        }
    }
}
// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
//Iniciando as matrizes e arrays que serão usados para a exibição e funcionamento do jogo
    int tabuleiro [10][10], agua=0;
    char tabela[10] = {'A','B','C','D','E','F','G','H','I','J'};
    printf("BEM VINDO AO BATALHA NAVAL!\n");
//PRINTF para deixar a tabela certa quando imprimir para o usuário
    printf("   ");

//Imprimindo novamente as letras da tabela
    for (int l = 0; l<10;l++){
        printf("%c ", tabela[l]);
    }
    printf("\n");


    for (int i=0; i<10; i++){
        
        printf("%2d ", i+1);
        for(int j=0; j<10; j++){
        tabuleiro [i][j]= agua;
        printf("%d ", tabuleiro[i][j]);    
        }
        printf("\n");

        
        
    };
//Introduzir os navios
    printf("\n\n");
    printf("Agora vamos adicionar os navios...\n");

    int navio [3]={3,3,3};
//Loops para os návios na vertical e horizontal.
//Para faciliar, preferi usar um loop complexo ao invés do aninhado, uma vez que o resultado é o mesmo para o que quero fazer.
    for (int i=0, coordenadaUm = 4, coordenadaDois= 6; i<3;i++){
        tabuleiro[coordenadaUm][coordenadaDois] = navio [i];
        coordenadaUm++;
    }

    for (int i=0, coordenadaUm = 3, coordenadaDois= 9; i<3;i++){
        tabuleiro[coordenadaUm][coordenadaDois] = navio [i];
        coordenadaDois--;
    }
//Loops para os Navios em diagonal
    for (int i=0, coordenadaUm = 7, coordenadaDois= 0; i<3;i++){
        tabuleiro[coordenadaUm][coordenadaDois] = navio [i];
        coordenadaDois++, coordenadaUm++;
    }
        for (int i=0, coordenadaUm = 5, coordenadaDois= 5; i<3;i++){
            tabuleiro[coordenadaUm][coordenadaDois] = navio [i];
            coordenadaDois--, coordenadaUm--;
    }
cone(tabuleiro, 6, 3);    
//PRINTF para deixar a tabela certa quando imprimir para o usuário
    printf("   ");
    
//Imprimindo novamente as letras da tabela
    for (int l = 0; l<10;l++){
        printf("%c ", tabela[l]);
    }
    printf("\n");


    for (int i=0; i<10; i++){
        
        printf("%2d ", i+1);
        for(int j=0; j<10; j++){
        printf("%d ", tabuleiro[i][j]);    
        }
        printf("\n");}

    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
