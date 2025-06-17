#include <stdio.h>
#include <string.h>

// Definição da Estrutura de Dados da Carta
struct CartaPais {
    char nome[50];
    long int populacao;
    float area;
    double pib;
    int pontosTuristicos;
    float densidade;
};

// Função Utilitária para Limpeza de Buffer
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função de Inicialização do Baralho
void inicializarDeck(struct CartaPais deck[]) {
    // Inicialização dos dados para as 5 cartas
    strcpy(deck[0].nome, "Brasil");
    deck[0].populacao = 215300000;
    deck[0].area = 8510000.0f;
    deck[0].pib = 1600000000000.00;
    deck[0].pontosTuristicos = 85;

    strcpy(deck[1].nome, "Japão");
    deck[1].populacao = 125700000;
    deck[1].area = 377975.0f;
    deck[1].pib = 4230000000000.00;
    deck[1].pontosTuristicos = 70;

    strcpy(deck[2].nome, "China");
    deck[2].populacao = 1425000000;
    deck[2].area = 9597000.0f;
    deck[2].pib = 17960000000000.00;
    deck[2].pontosTuristicos = 90;

    strcpy(deck[3].nome, "Austrália");
    deck[3].populacao = 26000000;
    deck[3].area = 7692000.0f;
    deck[3].pib = 1690000000000.00;
    deck[3].pontosTuristicos = 65;

    strcpy(deck[4].nome, "Egito");
    deck[4].populacao = 109300000;
    deck[4].area = 1010000.0f;
    deck[4].pib = 476750000000.00;
    deck[4].pontosTuristicos = 95;

    // Cálculo do atributo 'densidade' para todas as cartas
    for (int i = 0; i < 5; i++) {
        // CORREÇÃO 1: Adicionada verificação para evitar divisão por zero
        if (deck[i].area > 0) {
            deck[i].densidade = (float)deck[i].populacao / deck[i].area;
        } else {
            deck[i].densidade = 0;
        }
    }
}

// Função Principal
int main() {
    struct CartaPais deck[5];
    char jogarNovamente;

    inicializarDeck(deck);

    do {
        printf("\n\n--- SUPER TRUNFO: DESAFIO DE PAÍSES (NÍVEL MESTRE) ---\n");

        // Lógica de Seleção das Cartas
        printf("Escolha duas cartas para a batalha:\n");
        for (int i = 0; i < 5; i++) {
            printf("%d. %s\n", i + 1, deck[i].nome);
        }

        int escolha1 = 0, escolha2 = 0;
        int indice1, indice2;

        do {
            printf("\nEscolha a primeira carta (1-5): ");
            if(scanf("%d", &escolha1) != 1) escolha1 = 0; // Prevenção de erro
            limparBufferEntrada();
            if (escolha1 < 1 || escolha1 > 5) printf("Opção inválida!\n");
        } while (escolha1 < 1 || escolha1 > 5);
        indice1 = escolha1 - 1;

        do {
            printf("Escolha a segunda carta (1-5): ");
             if(scanf("%d", &escolha2) != 1) escolha2 = 0; // Prevenção de erro
            limparBufferEntrada();
            if (escolha2 < 1 || escolha2 > 5) printf("Opção inválida!\n");
            else if (escolha1 == escolha2) printf("Você não pode escolher a mesma carta duas vezes!\n");
        } while (escolha2 < 1 || escolha2 > 5 || escolha1 == escolha2);
        indice2 = escolha2 - 1;

        struct CartaPais carta1 = deck[indice1];
        struct CartaPais carta2 = deck[indice2];

        printf("\nBatalha: %s vs %s\n", carta1.nome, carta2.nome);
        printf("----------------------------------------\n");

        // Lógica de Seleção do Atributo
        int opcao = 0;
        do {
            printf("\nEscolha o atributo para comparar:\n");
            printf("1. População\n2. Área (em km²)\n3. PIB (em USD)\n");
            printf("4. Número de Pontos Turísticos\n5. Densidade Demográfica (habitantes por km²)\n");
            printf("Digite o número da sua escolha: ");
            if (scanf("%d", &opcao) != 1) opcao = 0;
            limparBufferEntrada();
            if (opcao < 1 || opcao > 5) printf("\nERRO: Opção inválida! Escolha um número de 1 a 5.\n");
        } while (opcao < 1 || opcao > 5);

        // Lógica de Comparação e Exibição do Resultado
        printf("\n--- RESULTADO DA COMPARAÇÃO ---\n");
        switch (opcao) {
            // CORREÇÃO 2: Simplificação dos blocos de impressão e lógica
            case 1:
                printf("Atributo: População\n%s: %ld\n%s: %ld\n", carta1.nome, carta1.populacao, carta2.nome, carta2.populacao);
                if (carta1.populacao > carta2.populacao) printf("Vencedor: %s\n", carta1.nome);
                else if (carta2.populacao > carta1.populacao) printf("Vencedor: %s\n", carta2.nome);
                else printf("Resultado: Empate!\n");
                break;
            case 2:
                printf("Atributo: Área\n%s: %.2f km²\n%s: %.2f km²\n", carta1.nome, carta1.area, carta2.nome, carta2.area);
                if (carta1.area > carta2.area) printf("Vencedor: %s\n", carta1.nome);
                else if (carta2.area > carta1.area) printf("Vencedor: %s\n", carta2.nome);
                else printf("Resultado: Empate!\n");
                break;
            case 3:
                printf("Atributo: PIB\n%s: %.2f USD\n%s: %.2f USD\n", carta1.nome, carta1.pib, carta2.nome, carta2.pib);
                if (carta1.pib > carta2.pib) printf("Vencedor: %s\n", carta1.nome);
                else if (carta2.pib > carta1.pib) printf("Vencedor: %s\n", carta2.nome);
                else printf("Resultado: Empate!\n");
                break;
            case 4:
                printf("Atributo: Pontos Turísticos\n%s: %d\n%s: %d\n", carta1.nome, carta1.pontosTuristicos, carta2.nome, carta2.pontosTuristicos);
                if (carta1.pontosTuristicos > carta2.pontosTuristicos) printf("Vencedor: %s\n", carta1.nome);
                else if (carta2.pontosTuristicos > carta1.pontosTuristicos) printf("Vencedor: %s\n", carta2.nome);
                else printf("Resultado: Empate!\n");
                break;
            case 5:
                printf("Atributo: Densidade Demográfica (Regra: Menor vence)\n%s: %.2f hab/km²\n%s: %.2f hab/km²\n", carta1.nome, carta1.densidade, carta2.nome, carta2.densidade);
                if (carta1.densidade < carta2.densidade) printf("Vencedor: %s\n", carta1.nome);
                else if (carta2.densidade < carta1.densidade) printf("Vencedor: %s\n", carta2.nome);
                else printf("Resultado: Empate!\n");
                break;
        }

        printf("----------------------------------------\n");

        // Verificação para Reiniciar o Jogo
        printf("\nDeseja jogar novamente? (s/n): ");
        scanf(" %c", &jogarNovamente);
        limparBufferEntrada();

    } while (jogarNovamente == 's' || jogarNovamente == 'S');

    printf("\nObrigado por jogar! Até a próxima.\n");

    return 0;
}