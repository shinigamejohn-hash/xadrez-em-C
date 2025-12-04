#include <stdio.h>

#define TAM 8

// -------------------------------- LIMITE DO TABULEIRO -----------------------------
int dentroDoTabuleiro(int linha, int coluna) {
    return (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM);
}

// -------------------------------- MOVIMENTO DA TORRE ------------------------------
void moverTorre(int linha, int coluna) {
    int escolhaDirecao, casas;

    printf("\n--- Movimento da TORRE ---\n");
    printf("Escolha uma direção:\n");
    printf("1. Cima\n");
    printf("2. Baixo\n");
    printf("3. Direita\n");
    printf("4. Esquerda\n");

    scanf("%d", &escolhaDirecao);

    // PRINT DESCRITIVO DA DIREÇÃO
    if (escolhaDirecao == 1) printf("Direção escolhida: CIMA\n");
    if (escolhaDirecao == 2) printf("Direção escolhida: BAIXO\n");
    if (escolhaDirecao == 3) printf("Direção escolhida: DIREITA\n");
    if (escolhaDirecao == 4) printf("Direção escolhida: ESQUERDA\n");

    printf("Quantas casas deseja mover? ");
    scanf("%d", &casas);

    int novaLinha = linha;
    int novaColuna = coluna;

    for (int i = 0; i < casas; i++) {
        if (escolhaDirecao == 1) novaLinha--;
        else if (escolhaDirecao == 2) novaLinha++;
        else if (escolhaDirecao == 3) novaColuna++;
        else if (escolhaDirecao == 4) novaColuna--;

        if (!dentroDoTabuleiro(novaLinha, novaColuna)) {
            printf("Saiu do tabuleiro! Escolha outra quantidade:\n");

            int valido = 0;
            while (!valido) {
                printf("Digite novamente uma quantidade válida de casas: ");
                scanf("%d", &casas);

                novaLinha = linha;
                novaColuna = coluna;
                valido = 1;

                for (int j = 0; j < casas; j++) {
                    if (escolhaDirecao == 1) novaLinha--;
                    else if (escolhaDirecao == 2) novaLinha++;
                    else if (escolhaDirecao == 3) novaColuna++;
                    else if (escolhaDirecao == 4) novaColuna--;

                    if (!dentroDoTabuleiro(novaLinha, novaColuna)) {
                        printf("Ainda está saindo do tabuleiro!\n");
                        valido = 0;
                        break;
                    }
                }
            }
            break;
        }
    }

    printf("A TORRE se moveu para (%d, %d)\n", novaLinha, novaColuna);
}

// ------------------------------ MOVIMENTO DO BISPO -------------------------------
void moverBispo(int linha, int coluna) {
    int escolhaDirecao, casas;

    printf("\n--- Movimento do BISPO ---\n");
    printf("Escolha uma direção diagonal:\n");
    printf("1. Cima-Direita\n");
    printf("2. Cima-Esquerda\n");
    printf("3. Baixo-Direita\n");
    printf("4. Baixo-Esquerda\n");

    scanf("%d", &escolhaDirecao);

    // PRINT DESCRITIVO
    if (escolhaDirecao == 1) printf("Direção escolhida: DIAGONAL CIMA-DIREITA\n");
    if (escolhaDirecao == 2) printf("Direção escolhida: DIAGONAL CIMA-ESQUERDA\n");
    if (escolhaDirecao == 3) printf("Direção escolhida: DIAGONAL BAIXO-DIREITA\n");
    if (escolhaDirecao == 4) printf("Direção escolhida: DIAGONAL BAIXO-ESQUERDA\n");

    printf("Quantas casas deseja mover? ");
    scanf("%d", &casas);

    int novaLinha = linha;
    int novaColuna = coluna;

    for (int i = 0; i < casas; i++) {
        if (escolhaDirecao == 1) { novaLinha--; novaColuna++; }
        else if (escolhaDirecao == 2) { novaLinha--; novaColuna--; }
        else if (escolhaDirecao == 3) { novaLinha++; novaColuna++; }
        else if (escolhaDirecao == 4) { novaLinha++; novaColuna--; }

        if (!dentroDoTabuleiro(novaLinha, novaColuna)) {
            printf("Saiu do tabuleiro! Escolha outra quantidade:\n");

            int valido = 0;
            while (!valido) {
                printf("Digite novamente a quantidade: ");
                scanf("%d", &casas);

                novaLinha = linha;
                novaColuna = coluna;
                valido = 1;

                for (int j = 0; j < casas; j++) {
                    if (escolhaDirecao == 1) { novaLinha--; novaColuna++; }
                    else if (escolhaDirecao == 2) { novaLinha--; novaColuna--; }
                    else if (escolhaDirecao == 3) { novaLinha++; novaColuna++; }
                    else if (escolhaDirecao == 4) { novaLinha++; novaColuna--; }

                    if (!dentroDoTabuleiro(novaLinha, novaColuna)) {
                        printf("Ainda está saindo!\n");
                        valido = 0;
                        break;
                    }
                }
            }
            break;
        }
    }

    printf("O BISPO se moveu para (%d, %d)\n", novaLinha, novaColuna);
}

// ------------------------------ MOVIMENTO DA RAINHA ------------------------------
void moverRainha(int linha, int coluna) {
    int escolhaDirecao, casas;

    printf("\n--- Movimento da RAINHA ---\n");
    printf("Escolha uma direção:\n");
    printf("1. Cima\n");
    printf("2. Baixo\n");
    printf("3. Direita\n");
    printf("4. Esquerda\n");
    printf("5. Cima-Direita\n");
    printf("6. Cima-Esquerda\n");
    printf("7. Baixo-Direita\n");
    printf("8. Baixo-Esquerda\n");

    scanf("%d", &escolhaDirecao);

    // PRINT DESCRITIVO
    const char *direcaoTexto[] = {
        "CIMA", "BAIXO", "DIREITA", "ESQUERDA",
        "DIAGONAL CIMA-DIREITA", "DIAGONAL CIMA-ESQUERDA",
        "DIAGONAL BAIXO-DIREITA", "DIAGONAL BAIXO-ESQUERDA"
    };

    printf("Direção escolhida: %s\n", direcaoTexto[escolhaDirecao - 1]);

    printf("Quantas casas deseja mover? ");
    scanf("%d", &casas);

    int novaLinha = linha;
    int novaColuna = coluna;

    for (int i = 0; i < casas; i++) {
        if (escolhaDirecao == 1) novaLinha--;
        if (escolhaDirecao == 2) novaLinha++;
        if (escolhaDirecao == 3) novaColuna++;
        if (escolhaDirecao == 4) novaColuna--;
        if (escolhaDirecao == 5) { novaLinha--; novaColuna++; }
        if (escolhaDirecao == 6) { novaLinha--; novaColuna--; }
        if (escolhaDirecao == 7) { novaLinha++; novaColuna++; }
        if (escolhaDirecao == 8) { novaLinha++; novaColuna--; }

        if (!dentroDoTabuleiro(novaLinha, novaColuna)) {
            printf("Saiu do tabuleiro! Digite nova quantidade:\n");

            int valido = 0;
            while (!valido) {
                printf("Digite novamente a quantidade: ");
                scanf("%d", &casas);

                novaLinha = linha;
                novaColuna = coluna;
                valido = 1;

                for (int j = 0; j < casas; j++) {
                    if (escolhaDirecao == 1) novaLinha--;
                    if (escolhaDirecao == 2) novaLinha++;
                    if (escolhaDirecao == 3) novaColuna++;
                    if (escolhaDirecao == 4) novaColuna--;
                    if (escolhaDirecao == 5) { novaLinha--; novaColuna++; }
                    if (escolhaDirecao == 6) { novaLinha--; novaColuna--; }
                    if (escolhaDirecao == 7) { novaLinha++; novaColuna++; }
                    if (escolhaDirecao == 8) { novaLinha++; novaColuna--; }

                    if (!dentroDoTabuleiro(novaLinha, novaColuna)) {
                        printf("Ainda está saindo!\n");
                        valido = 0;
                        break;
                    }
                }
            }
            break;
        }
    }

    printf("A RAINHA se moveu para (%d, %d)\n", novaLinha, novaColuna);
}

// ------------------------------ MOVIMENTO DO CAVALO -----------------------------
void moverCavalo(int linha, int coluna) {

    int movLinha[8]  = {-2, -2, -1, 1,  2, 2, 1, -1};
    int movColuna[8] = { 1, -1,  2, 2, 1, -1, -2, -2};

    const char *descricaoMov[8] = {
        "duas para cima e uma para direita",
        "duas para cima e uma para esquerda",
        "uma para cima e duas para direita",
        "uma para baixo e duas para direita",
        "duas para baixo e uma para direita",
        "duas para baixo e uma para esquerda",
        "uma para baixo e duas para esquerda",
        "uma para cima e duas para esquerda"
    };

    int repetir = 1;

    while (repetir) {
        printf("\n--- Movimento do CAVALO ---\n");
        printf("Escolha um dos 8 movimentos possíveis:\n");

        for (int i = 0; i < 8; i++) {
            printf("%d. %s\n", i + 1, descricaoMov[i]);
        }

        int escolha;
        scanf("%d", &escolha);

        if (escolha < 1 || escolha > 8) {
            printf("Movimento inválido! Tente novamente.\n");
            continue;
        }

        printf("Movimento escolhido: %s\n", descricaoMov[escolha - 1]);

        int novaLinha = linha + movLinha[escolha - 1];
        int novaColuna = coluna + movColuna[escolha - 1];

        if (!dentroDoTabuleiro(novaLinha, novaColuna)) {
            printf("O cavalo sairia do tabuleiro! Escolha novamente.\n");
        } else {
            printf("O CAVALO se moveu para (%d, %d)\n", novaLinha, novaColuna);
            repetir = 0;
        }
    }
}

// ----------------------------------- MAIN ---------------------------------------
int main() {
    int jogadorAtual = 1;

    while (1) {
        printf("\n===== VEZ DO JOGADOR %d =====\n", jogadorAtual);
        printf("Escolha a peça que deseja mover:\n");
        printf("1. Torre\n");
        printf("2. Bispo\n");
        printf("3. Rainha\n");
        printf("4. Cavalo\n");

        char escolhaPeca;
        printf("Digite sua escolha: ");
        scanf(" %c", &escolhaPeca);

        if (escolhaPeca == '1') {
            printf("\nJogador %d escolheu a PEÇA: Torre.\n", jogadorAtual);
            moverTorre(4, 4);
        }
        else if (escolhaPeca == '2') {
            printf("\nJogador %d escolheu a PEÇA: Bispo.\n", jogadorAtual);
            moverBispo(4, 4);
        }
        else if (escolhaPeca == '3') {
            printf("\nJogador %d escolheu a PEÇA: Rainha.\n", jogadorAtual);
            moverRainha(4, 4);
        }
        else if (escolhaPeca == '4') {
            printf("\nJogador %d escolheu a PEÇA: Cavalo.\n", jogadorAtual);
            moverCavalo(4, 4);
        }
        else {
            printf("Opção inválida! Tente novamente.\n");
            continue;
        }

        jogadorAtual = (jogadorAtual == 1 ? 2 : 1);
    }

    return 0;
}
