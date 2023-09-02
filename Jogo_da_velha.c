#include <stdio.h>

char tabuleiro[3][3]; // Tabuleiro 3x3

void inicializarTabuleiro() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

void imprimirTabuleiro() {
    printf("  1 2 3\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("%c", tabuleiro[i][j]);
            if (j < 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2) {
            printf("  -+-+-\n");
        }
    }
}

int verificarVitoria(char jogador) {
    // Verificar linhas, colunas e diagonais
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) {
            return 1; // Vitória na linha
        }
        if (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador) {
            return 1; // Vitória na coluna
        }
    }
    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) {
        return 1; // Vitória na diagonal principal
    }
    if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador) {
        return 1; // Vitória na diagonal secundária
    }
    return 0; // Nenhuma vitória
}

int verificarEmpate() {
    // Verificar se o jogo terminou em empate
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ') {
                return 0; // Ainda há espaços vazios
            }
        }
    }
    return 1; // Não há espaços vazios, é um empate
}

int fazerJogada(int linha, int coluna, char jogador) {
    // Verificar se a posição é válida e se está vazia
    if (linha >= 1 && linha <= 3 && coluna >= 1 && coluna <= 3 && tabuleiro[linha - 1][coluna - 1] == ' ') {
        tabuleiro[linha - 1][coluna - 1] = jogador;
        return 1; // Jogada válida
    }
    return 0; // Jogada inválida
}

int main() {
    int vez = 0; // 0 para jogador 1 e 1 para jogador 2
    int linha, coluna;
    char jogadorAtual = 'X';
    int jogoTerminado = 0;

    inicializarTabuleiro();

    while (!jogoTerminado) {
        imprimirTabuleiro();

        printf("Jogador %c, digite a linha e a coluna (ex: 1 2): ", jogadorAtual);
        scanf("%d %d", &linha, &coluna);

        if (fazerJogada(linha, coluna, jogadorAtual)) {
            if (verificarVitoria(jogadorAtual)) {
                imprimirTabuleiro();
                printf("Jogador %c venceu!\n", jogadorAtual);
                jogoTerminado = 1;
            } else if (verificarEmpate()) {
                imprimirTabuleiro();
                printf("O jogo terminou em empate!\n");
                jogoTerminado = 1;
            } else {
                vez = 1 - vez;
                jogadorAtual = (vez == 0) ? 'X' : 'O';
            }
        } else {
            printf("Jogada inválida. Tente novamente.\n");
        }
    }

    return 0;
}
