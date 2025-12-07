#include <stdio.h>

#define TAM 8   // tabuleiro 8x8

// coordenadas da última jogada
int ultimaLinha, ultimaColuna;

// Função: converte (linha,coluna) para formato "A1", "H8", etc. Para exibir no resumo final

void converterParaCoordenada(int linha, int coluna, char *saida) { // converte (linha,coluna) para formato "A1", "H8", etc.
    char letraColuna = 'A' + coluna;  // converte número da coluna para letra (0 -> A, 1 -> B, ..., 7 -> H)
    int numeroLinha = linha + 1; // converte índice da linha para número (0 -> 1, 1 -> 2, ..., 7 -> 8)
    sprintf(saida, "%c%d", letraColuna, numeroLinha); //sprintf para formatar a string de saída
}



// Função: verifica se (linha,coluna) está no tabuleiro
int dentroDoTabuleiro(int linha, int coluna) {
    return (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM);
}



//                           TORRE

void moverTorre(int linha, int coluna) {

    //aqui definimos os arrays para as direções e seus respectivos movimentos em linhas e colunas
    //os vetores dirLinha e dirColuna representam os deslocamentos nas linhas e colunas para cada direção possível da torre
    //por exemplo, para mover para cima, a linha diminui (-1) e a coluna permanece a mesma (0)
    //para mover para baixo, a linha aumenta (+1) e a coluna permanece a mesma (0)
    //para mover para a direita, a linha permanece a mesma (0) e a coluna aumenta (+1)
    //para mover para a esquerda, a linha permanece a mesma (0) e a coluna diminui (-1)
    //(1,0) significa mover uma casa para baixo. (-1, 1) significa mover uma casa para cima e uma para a direita, etc...

//descrição das direções, uso do const char* para criar um array de strings

    const char *textoDirecao[] = {"CIMA", "BAIXO", "DIREITA", "ESQUERDA"}; 
    int dirLinha[]  = {-1, 1, 0, 0}; //movimento nas linhas, ou seja, -1 para cima e +1 para baixo
    int dirColuna[] = {0, 0, 1, -1}; //movimento nas colunas, ou seja, +1 para direita e -1 para esquerda

    int escolhaDirecao, casas;
   
    printf("\n Movimento da TORRE \n");

    // Exibe opções de direção 

    printf("1. Cima\n2. Baixo\n3. Direita\n4. Esquerda\n");
    scanf("%d", &escolhaDirecao);


    while (escolhaDirecao < 1 || escolhaDirecao > 4) { //validação da escolha
        printf("Direção inválida.\n");
        printf("Escolha uma direção válida (1-4): "); 
        scanf("%d", &escolhaDirecao);
        continue; //continua o loop, ou seja, volta para o início do while
    }

    printf("Você escolheu mover para: %s\n", textoDirecao[escolhaDirecao - 1]); //-1 para ajustar índice do array (Converter a escolha do usuário (1–4) para índice do array (0–3))
    printf("Quantas casas deseja mover? "); //solicita número de casas
    scanf("%d", &casas);

    int novaLinha  = linha  + dirLinha[escolhaDirecao - 1]  * casas;
    int novaColuna = coluna + dirColuna[escolhaDirecao - 1] * casas;

     //validação do movimento dentro do tabuleiro

//while com (!dentrodotabuleiro) roda enquanto a posição nao estiver dentro do tabuleiro, ou seja, enquanto nao estiver dentro do tabuleiro será verdadeiro, entao tera o printf de movimento invalido
//se !dentrodotabuleiro for falso, entao o movimento é válido e o loop termina

    while (!dentroDoTabuleiro(novaLinha, novaColuna)) { 
        printf("\nMovimento inválido! Fora do tabuleiro.\n");
        printf("Escolha outra quantidade de casas: ");
        scanf("%d", &casas);

        ////linha + dirLinha significa que a nova linha é calculada somando a linha atual com o valor correspondente em dirLinha multiplicado pelo número de casas

        novaLinha  = linha  + dirLinha[escolhaDirecao - 1]  * casas; //-1 para ajustar índice do array e a * casas para multiplicar o movimento pela quantidade de casas
        novaColuna = coluna + dirColuna[escolhaDirecao - 1] * casas; //-1 para ajustar índice do array e a * casas para multiplicar o movimento pela quantidade de casas
    }

    printf("Jogador moveu a TORRE: %d casas para %s\n",
           casas, textoDirecao[escolhaDirecao - 1]); //-1 para ajustar índice do array

   //variaveis para armazenar a ultima posicao da torre
    ultimaLinha = novaLinha;
    ultimaColuna = novaColuna;
   
}




//                           BISPO

void moverBispo(int linha, int coluna) {

    //descrição das direções, uso do const char* para criar um array de strings

    const char *textoDirecao[] = {
        "DIAGONAL CIMA-DIREITA", "DIAGONAL CIMA-ESQUERDA",
        "DIAGONAL BAIXO-DIREITA", "DIAGONAL BAIXO-ESQUERDA"
    };

    int dirLinha[]  = {-1, -1,  1,  1}; //movimento nas linhas, ou seja, -1 para cima e +1 para baixo
    int dirColuna[] = { 1, -1,  1, -1}; //movimento nas colunas, ou seja, +1 para direita e -1 para esquerda

    //variaveis para escolha da direcao e numero de casas

    int escolhaDirecao, casas;

    printf("\n--- Movimento do BISPO ---\n");
    printf("1. Diagonal Cima-Direita\n2. Diagonal Cima-Esquerda\n3. Diagonal Baixo-Direita\n4. Diagonal Baixo-Esquerda\n");

    scanf("%d", &escolhaDirecao);

    //validação da escolha

    while (escolhaDirecao < 1 || escolhaDirecao > 4) {
        printf("Direção inválida.\n");
        printf("Escolha uma direção válida (1-4): ");
        scanf("%d", &escolhaDirecao);
        continue;
    }

    printf("Direção escolhida: %s\n", textoDirecao[escolhaDirecao - 1]); //-1 para ajustar índice do array
    printf("Quantas casas deseja mover? ");
    scanf("%d", &casas);

    int novaLinha  = linha  + dirLinha[escolhaDirecao - 1]  * casas; //-1 para ajustar índice do array e a * casas para multiplicar o movimento pela quantidade de casas
    int novaColuna = coluna + dirColuna[escolhaDirecao - 1] * casas; //-1 para ajustar índice do array e a * casas para multiplicar o movimento pela quantidade de casas

    while (!dentroDoTabuleiro(novaLinha, novaColuna)) {
        printf("\nMovimento inválido! O bispo sairia do tabuleiro.\n");
        printf("Escolha outra quantidade de casas: ");
        scanf("%d", &casas);

        novaLinha  = linha  + dirLinha[escolhaDirecao - 1]  * casas; //-1 para ajustar índice do array e a * casas para multiplicar o movimento pela quantidade de casas
        novaColuna = coluna + dirColuna[escolhaDirecao - 1] * casas; //-1 para ajustar índice do array e a * casas para multiplicar o movimento pela quantidade de casas
    }

    printf("Jogador moveu o BISPO: %d casas na %s\n",
           casas, textoDirecao[escolhaDirecao - 1]);

 //variaveis para armazenar a ultima posicao do bispo
    ultimaLinha = novaLinha;
    ultimaColuna = novaColuna;
 
}




//                     RAINHA

void moverRainha(int linha, int coluna) {

    //descrição das direções, uso do const char* para criar um array de strings

    const char *textoDirecao[] = {
        "CIMA", "BAIXO", "DIREITA", "ESQUERDA",
        "Diagonal CIMA-DIREITA", "Diagonal CIMA-ESQUERDA",
        "Diagonal BAIXO-DIREITA", "Diagonal BAIXO-ESQUERDA"
    };

    int dirLinha[]  = {-1,  1,  0,  0, -1, -1,  1,  1}; //movimento nas linhas, ou seja, -1 para cima e +1 para baixo
    int dirColuna[] = { 0,  0,  1, -1,  1, -1,  1, -1}; //movimento nas colunas, ou seja, +1 para direita e -1 para esquerda

     //variaveis para escolha da direcao e numero de casas  

    int escolhaDirecao, casas;

    printf("\n Movimento da RAINHA \n");
    printf(
        "1. Cima\n2. Baixo\n3. Direita\n4. Esquerda\n"
        "5. Diagonal Cima-Direita\n6. Diagonal Cima-Esquerda\n7. Diagonal Baixo-Direita\n8. Diagonal Baixo-Esquerda\n"
    );

    scanf("%d", &escolhaDirecao);

    while (escolhaDirecao < 1 || escolhaDirecao > 8) {
        printf("Direção inválida.\n");
        printf("Escolha uma direção válida (1-8): "); 
        scanf("%d", &escolhaDirecao);
        continue; //continua o loop, ou seja, volta para o início do while
    }

    printf("Direção escolhida: %s\n", textoDirecao[escolhaDirecao - 1]); //-1 para ajustar índice do array
    printf("Quantas casas deseja mover? ");
    scanf("%d", &casas);

    int novaLinha  = linha  + dirLinha[escolhaDirecao - 1]  * casas; //-1 para ajustar índice do array e a * casas para multiplicar o movimento pela quantidade de casas
    int novaColuna = coluna + dirColuna[escolhaDirecao - 1] * casas; //-1 para ajustar índice do array e a * casas para multiplicar o movimento pela quantidade de casas

     //validação do movimento dentro do tabuleiro   

    while (!dentroDoTabuleiro(novaLinha, novaColuna)) {
        printf("\nMovimento inválido! Rainha sairia do tabuleiro.\n");
        printf("Escolha outra quantidade de casas: ");
        scanf("%d", &casas);

        novaLinha  = linha  + dirLinha[escolhaDirecao - 1]  * casas; //-1 para ajustar índice do array e a * casas para multiplicar o movimento pela quantidade de casas
        novaColuna = coluna + dirColuna[escolhaDirecao - 1] * casas; //-1 para ajustar índice do array e a * casas para multiplicar o movimento pela quantidade de casas
    }

    printf("Jogador moveu a RAINHA: %d casas para %s\n", casas, textoDirecao[escolhaDirecao - 1]); //-1 para ajustar índice do array

    //vairaveis para armazenar a ultima posicao da rainha
    ultimaLinha = novaLinha;
    ultimaColuna = novaColuna;
   
}




//                           CAVALO

void moverCavalo(int linha, int coluna) {

    int movL[] = {-2,-2,-1, 1, 2, 2, 1,-1}; //-1 para cima e +1 para baixo, -2 para duas casas para cima e +2 para duas casas para baixo
    int movC[] = { 1,-1, 2, 2, 1,-1,-2,-2}; //+1 para direita e -1 para esquerda, +2 para duas casas para direita e -2 para duas casas para esquerda

    //*descrição dos movimentos, uso do const char* para criar um array de strings

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

 // while (1) cria um loop infinito que só é interrompido por um break interno quando uma condição específica é atendida
 //ou seja, o loop continuará solicitando a escolha do movimento do cavalo até que uma opção válida seja selecionada e o movimento seja confirmado como válido dentro do tabuleiro

    while (1) {

        printf("\n Movimento do CAVALO \n");
        for (int i = 0; i < 8; i++) //exibe as 8 opções de movimento do cavalo, i++ incrementa i em 1 a cada iteração
            printf("%d. %s\n", i + 1, descricao[i]); //i+1 para exibir opções de 1 a 8, ja a descrição[i] exibe a descrição do movimento

        scanf("%d", &escolha);
        
        //validação da escolha

        while (escolha < 1 || escolha > 8) {
            printf("Opção inválida. Tente novamente.\n");
            printf("Escolha um movimento válido (1-8): ");
            scanf("%d", &escolha);
            continue; //continua o loop, ou seja, volta para o início do while
        }

        int novaLinha  = linha  + movL[escolha - 1]; //-1 para ajustar índice do array (linha + movL significa que a nova linha é calculada somando a linha atual com o valor correspondente em movL)
        int novaColuna = coluna + movC[escolha - 1]; //-1 para ajustar índice do array (coluna + movC significa que a nova coluna é calculada somando a coluna atual com o valor correspondente em movC)

        if (!dentroDoTabuleiro(novaLinha, novaColuna)) {
            printf("Movimento inválido! Cavalo sairia do tabuleiro.\n");
            continue;
        }

        printf("Jogador moveu o CAVALO: %s\n", descricao[escolha - 1]);

       //variaveis para armazenar a ultima posicao do cavalo
        ultimaLinha = novaLinha;
        ultimaColuna = novaColuna;
     

        break;
    }
}




//Main

int main() {

    int jogador = 1;

    //loop principal do jogo

    while (1) { //loop infinito para o jogo continuar indefinidamente, pois (1) é sempre verdadeiro, ate que um break seja chamado dentro do loop
        printf("\n VEZ DO JOGADOR %d \n", jogador);

        int escolha;
        printf("Escolha a peça:\n1. Torre\n2. Bispo\n3. Rainha\n4. Cavalo\n");
        scanf("%d", &escolha);

        if (escolha < 1 || escolha > 4) {
            printf("Peça inválida. Escolha uma opção entre 1 e 4.\n");
            continue; //continua o loop, ou seja, volta para o início do while
        }

        //confirmação da peça escolhida

        if (escolha == 1) {printf("Jogador escolheu a TORRE.\n");} 
        else if (escolha == 2) {printf("Jogador escolheu o BISPO.\n");}
        else if (escolha == 3) {printf("Jogador escolheu a RAINHA.\n");}
        else if (escolha == 4) {printf("Jogador escolheu o CAVALO.\n\n");}


        //variave para posição da peça

        int linha, coluna;
        char colunaLetra;

        printf("Informe a posição da peça:\n");

        printf("Linha (0 a 7): ");
        scanf("%d", &linha);

        while (linha < 0 || linha > 7) {
            printf("Linha inválida! Digite entre 0 e 7:\n");
            scanf("%d", &linha);
        }

        printf("Coluna (A a H): ");
        scanf(" %c", &colunaLetra);

        // convertendo para maiúsculo

//em C, os caracteres minúsculos e maiúsculos têm valores ASCII diferentes
//subtraindo 32 de um caractere minúsculo, obtemos o valor ASCII correspondente ao caractere maiúsculo
//por exemplo, 'a' tem o valor ASCII 97, e 'A' tem o valor ASCII 65. 97 - 32 = 65

        if (colunaLetra >= 'a' && colunaLetra <= 'h') { //converte minuscula para maiuscula
            colunaLetra = colunaLetra - 32; //subtrai 32 para converter para maiúsculo
        }

        while (colunaLetra < 'A' || colunaLetra > 'H') { //validação da coluna
            printf("Coluna inválida! Digite entre A e H:\n");
            scanf(" %c", &colunaLetra);

            if (colunaLetra >= 'a' && colunaLetra <= 'h') { //converte minuscula para maiuscula
                colunaLetra = colunaLetra - 32;
            }
        }

        printf("\nPosição da peça: %c%d \n", colunaLetra, linha); 


        coluna = colunaLetra - 'A'; //converte letra da coluna para número (A = 0, B = 1, C = 2, D = 3, E = 4, F = 5, G = 6, H = 7)
        
        // Chama a função correspondente à peça escolhida

        switch (escolha) { //switch para escolher a peça

            case 1: moverTorre(linha, coluna); break;
            case 2: moverBispo(linha, coluna); break;
            case 3: moverRainha(linha, coluna); break;
            case 4: moverCavalo(linha, coluna); break;
            default:
                printf("Opção inválida.\n");
                continue; //continua o loop, ou seja, volta para o início do while
        }

        // RESUMO FINAL 
        char inicial[4], final[4]; // espaço para coordenadas como "A1", "H8" do void converterParaCoordenada

        // posição final onde a peça foi movida, calculada nas funções de movimento que e armazenado nas variaveis ultimaLinha e ultimaColuna

        converterParaCoordenada(linha, coluna, inicial); // posição inicial
        converterParaCoordenada(ultimaLinha, ultimaColuna, final); // posição final

        printf("\n RESUMO DO MOVIMENTO:\n");
        printf("Jogador %d moveu a peça de %s para %s\n", jogador, inicial, final); //exibe o resumo do movimento
  

        jogador = (jogador == 1 ? 2 : 1);
    }

    return 0;
}
