#include <stdio.h>

#define TAM 8   // tabuleiro 8x8


// Função: verifica se (linha,coluna) está no tabuleiro

int dentroDoTabuleiro(int linha, int coluna) {
    return (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM);}



//                           TORRE

void moverTorre(int linha, int coluna) {

    const char *textoDirecao[] = {"CIMA", "BAIXO", "DIREITA", "ESQUERDA"};
    int dirLinha[]  = {-1, 1, 0, 0};
    int dirColuna[] = {0, 0, 1, -1};

    int escolhaDirecao, casas;

    printf("\n--- Movimento da TORRE ---\n");

    printf("1. Cima\n2. Baixo\n3. Direita\n4. Esquerda\n");
    scanf("%d", &escolhaDirecao);

    if (escolhaDirecao < 1 || escolhaDirecao > 4) {
        printf("Direção inválida.\n");
        return;
    }

    printf("Você escolheu mover para: %s\n", textoDirecao[escolhaDirecao - 1]);
    printf("Quantas casas deseja mover? ");
    scanf("%d", &casas);

    int novaLinha  = linha  + dirLinha[escolhaDirecao - 1]  * casas;
    int novaColuna = coluna + dirColuna[escolhaDirecao - 1] * casas;

    while (!dentroDoTabuleiro(novaLinha, novaColuna)) {
        printf("\nMovimento inválido! Fora do tabuleiro.\n");
        printf("Escolha outra quantidade de casas: ");
        scanf("%d", &casas);

        novaLinha  = linha  + dirLinha[escolhaDirecao - 1]  * casas;
        novaColuna = coluna + dirColuna[escolhaDirecao - 1] * casas;
    }

    printf("Jogador moveu a TORRE: %d casas para %s\n",
           casas, textoDirecao[escolhaDirecao - 1]);
}




//                           BISPO

void moverBispo(int linha, int coluna) {

    const char *textoDirecao[] = {
        "DIAGONAL CIMA-DIREITA", "DIAGONAL CIMA-ESQUERDA",
        "DIAGONAL BAIXO-DIREITA", "DIAGONAL BAIXO-ESQUERDA"
    };

    int dirLinha[]  = {-1, -1,  1,  1};
    int dirColuna[] = { 1, -1,  1, -1};

    int escolhaDirecao, casas;

    printf("\n--- Movimento do BISPO ---\n");
    printf("1. Cima-Direita\n2. Cima-Esquerda\n3. Baixo-Direita\n4. Baixo-Esquerda\n");

    scanf("%d", &escolhaDirecao);

    if (escolhaDirecao < 1 || escolhaDirecao > 4) {
        printf("Direção inválida.\n");
        return;
    }

    printf("Direção escolhida: %s\n", textoDirecao[escolhaDirecao - 1]);
    printf("Quantas casas deseja mover? ");
    scanf("%d", &casas);

    int novaLinha  = linha  + dirLinha[escolhaDirecao - 1]  * casas;
    int novaColuna = coluna + dirColuna[escolhaDirecao - 1] * casas;

    while (!dentroDoTabuleiro(novaLinha, novaColuna)) {
        printf("\nMovimento inválido! O bispo sairia do tabuleiro.\n");
        printf("Escolha outra quantidade de casas: ");
        scanf("%d", &casas);

        novaLinha  = linha  + dirLinha[escolhaDirecao - 1]  * casas;
        novaColuna = coluna + dirColuna[escolhaDirecao - 1] * casas;
    }

    printf("Jogador moveu o BISPO: %d casas na %s\n",
           casas, textoDirecao[escolhaDirecao - 1]);
}




//                           RAINHA

void moverRainha(int linha, int coluna) {

    const char *textoDirecao[] = {
        "CIMA", "BAIXO", "DIREITA", "ESQUERDA",
        "CIMA-DIREITA", "CIMA-ESQUERDA",
        "BAIXO-DIREITA", "BAIXO-ESQUERDA"
    };

    int dirLinha[]  = {-1,  1,  0,  0, -1, -1,  1,  1};
    int dirColuna[] = { 0,  0,  1, -1,  1, -1,  1, -1};

    int escolhaDirecao, casas;

    printf("\n--- Movimento da RAINHA ---\n");
    printf(
        "1. Cima\n2. Baixo\n3. Direita\n4. Esquerda\n"
        "5. Cima-Direita\n6. Cima-Esquerda\n7. Baixo-Direita\n8. Baixo-Esquerda\n"
    );

    scanf("%d", &escolhaDirecao);

    if (escolhaDirecao < 1 || escolhaDirecao > 8) {
        printf("Direção inválida.\n");
        return;
    }

    printf("Direção escolhida: %s\n", textoDirecao[escolhaDirecao - 1]);
    printf("Quantas casas deseja mover? ");
    scanf("%d", &casas);

    int novaLinha  = linha  + dirLinha[escolhaDirecao - 1]  * casas;
    int novaColuna = coluna + dirColuna[escolhaDirecao - 1] * casas;

    while (!dentroDoTabuleiro(novaLinha, novaColuna)) {
        printf("\nMovimento inválido! Rainha sairia do tabuleiro.\n");
        printf("Escolha outra quantidade de casas: ");
        scanf("%d", &casas);

        novaLinha  = linha  + dirLinha[escolhaDirecao - 1]  * casas;
        novaColuna = coluna + dirColuna[escolhaDirecao - 1] * casas;
    }

    printf("Jogador moveu a RAINHA: %d casas para %s\n",
           casas, textoDirecao[escolhaDirecao - 1]);
}




//                           CAVALO

void moverCavalo(int linha, int coluna) {

    int movL[] = {-2,-2,-1, 1, 2, 2, 1,-1};
    int movC[] = { 1,-1, 2, 2, 1,-1,-2,-2};

    const char *descricao[] = {
        "2 para cima e 1 para a direita",
        "2 para cima e 1 para a esquerda",
        "1 para cima e 2 para a direita",
        "1 para baixo e 2 para a direita",
        "2 para baixo e 1 para a direita",
        "2 para baixo e 1 para a esquerda",
        "1 para baixo e 2 para a esquerda",
        "1 para cima e 2 para a esquerda"
    };

    int escolha;

    while (1) {

        printf("\n--- Movimento do CAVALO ---\n");
        for (int i = 0; i < 8; i++)
            printf("%d. %s\n", i + 1, descricao[i]);

        scanf("%d", &escolha);

        if (escolha < 1 || escolha > 8) {
            printf("Opção inválida. Tente novamente.\n");
            continue;
        }

        int novaLinha  = linha  + movL[escolha - 1];
        int novaColuna = coluna + movC[escolha - 1];

        if (!dentroDoTabuleiro(novaLinha, novaColuna)) {
            printf("Movimento inválido! Cavalo sairia do tabuleiro.\n");
            continue;
        }

        printf("Jogador moveu o CAVALO: %s\n", descricao[escolha - 1]);
        break;
    }
}




//                              MAIN

int main() {

    int jogador = 1;

    while (1) {
        printf("\n===== VEZ DO JOGADOR %d =====\n", jogador);

        int escolha;
        printf("Escolha a peça:\n1. Torre\n2. Bispo\n3. Rainha\n4. Cavalo\n");
        scanf("%d", &escolha);

        int linha = 4, coluna = 4; // posição fictícia

        switch (escolha) {
            case 1: moverTorre(linha, coluna); break;
            case 2: moverBispo(linha, coluna); break;
            case 3: moverRainha(linha, coluna); break;
            case 4: moverCavalo(linha, coluna); break;
            default:
                printf("Opção inválida.\n");
                continue;
        }

        jogador = (jogador == 1 ? 2 : 1); // troca jogador
    }

    return 0;
}
