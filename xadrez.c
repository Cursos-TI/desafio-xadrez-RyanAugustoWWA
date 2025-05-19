#include <stdio.h>

#define BISHOP_STEPS 5
#define ROOK_STEPS   5
#define QUEEN_STEPS  8

// --------------------------------------------------
// Funções auxiliares para movimentação de peças
// --------------------------------------------------

// NÍVEL NOVATO: loops simples
void moveBishopNovato() {
    printf("[Novato] Bispo: %d casas na diagonal cima-direita\n", BISHOP_STEPS);
    for (int i = 0; i < BISHOP_STEPS; i++) {
        printf("  Cima\n");
        printf("  Direita\n");
    }
}

void moveRookNovato() {
    printf("\n[Novato] Torre: %d casas para a direita\n", ROOK_STEPS);
    for (int i = 0; i < ROOK_STEPS; i++) {
        printf("  Direita\n");
    }
}

void moveQueenNovato() {
    printf("\n[Novato] Rainha: %d casas para a esquerda\n", QUEEN_STEPS);
    for (int i = 0; i < QUEEN_STEPS; i++) {
        printf("  Esquerda\n");
    }
}

// NÍVEL AVENTUREIRO: loops aninhados para o cavalo em L (2 para baixo, 1 para a esquerda)
void moveKnightAventureiro() {
    printf("\n[Aventureiro] Cavalo: L (2 para baixo, 1 para esquerda)\n");
    // loop externo para repetir uma vez o L
    for (int rep = 0; rep < 1; rep++) {
        int cnt = 0;
        // duas casas para baixo
        while (cnt < 2) {
            printf("  Baixo\n");
            cnt++;
        }
        // uma casa para a esquerda
        printf("  Esquerda\n");
    }
}

// NÍVEL MESTRE: funções recursivas e loops avançados

// Bispo recursivo
void moveBishopMestre(int steps) {
    if (steps <= 0) return;
    printf("  Cima\n");
    printf("  Direita\n");
    moveBishopMestre(steps - 1);
}

// Torre recursiva
void moveRookMestre(int steps) {
    if (steps <= 0) return;
    printf("  Direita\n");
    moveRookMestre(steps - 1);
}

// Rainha recursiva
void moveQueenMestre(int steps) {
    if (steps <= 0) return;
    printf("  Esquerda\n");
    moveQueenMestre(steps - 1);
}

// Cavalo com múltiplas variáveis, continue e break (1 em L para cima-direita)
void moveKnightMestre() {
    int up = 2, right = 1;
    printf("\n[Mestre] Cavalo: L (2 para cima, 1 para direita) com continue/break\n");
    // loop único com duas variáveis de controle
    for (; up > 0 || right > 0; ) {
        if (up > 0) {
            printf("  Cima\n");
            up--;
            continue;  // volta para checar novamente
        }
        if (right > 0) {
            printf("  Direita\n");
            right--;
            break;     // sai após a etapa horizontal
        }
    }
}

int main() {
    printf("=== Desafio de Xadrez ===\n\n");

    // Executa todos os movimentos em sequência, incorporando os três níveis:
    // Novato (loops simples), Aventureiro (loops aninhados) e Mestre (recursão + loops avançados).

    // 1. Novato
    moveBishopNovato();
    moveRookNovato();
    moveQueenNovato();

    // 2. Aventureiro
    moveKnightAventureiro();

    // 3. Mestre
    printf("\n[Mestre] Bispo (recursivo):\n");
    moveBishopMestre(BISHOP_STEPS);

    printf("\n[Mestre] Torre (recursivo):\n");
    moveRookMestre(ROOK_STEPS);

    printf("\n[Mestre] Rainha (recursivo):\n");
    moveQueenMestre(QUEEN_STEPS);

    moveKnightMestre();

    return 0;
}
