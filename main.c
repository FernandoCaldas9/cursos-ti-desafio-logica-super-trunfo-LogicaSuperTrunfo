#include <stdio.h>

// Definição da estrutura para armazenar os dados de uma carta
typedef struct {
    char estado;
    char codigo[5];
    char nome_cidade[50];
    int populacao;
    float area; // em km²
    float pib; // em bilhões
    int pontos_turisticos;
} Carta;


// Função para calcular a densidade populacional
float calcular_densidade_populacional(int populacao, float area) {
    return (float) populacao / area;
}

// Função para calcular o PIB per capita
float calcular_pib_per_capita(float pib, int populacao) {
    return pib / populacao;
}

// Função para comparar dois atributos e determinar a vencedora
void comparar_cartas(Carta carta1, Carta carta2) {
    // ATRIBUTO FIXO ESCOLHIDO: vamos comparar **PIB**
    int atributo = 3;

    // Calculando atributos derivados
    float dens1 = calcular_densidade_populacional(carta1.populacao, carta1.area);
    float dens2 = calcular_densidade_populacional(carta2.populacao, carta2.area);
    float pib_per_capita1 = calcular_pib_per_capita(carta1.pib, carta1.populacao);
    float pib_per_capita2 = calcular_pib_per_capita(carta2.pib, carta2.populacao);

    // Comparação
    if (atributo == 1) { // População
        printf("Comparação de cartas (Atributo: População):\n");
        printf("Carta 1 - %s (%c): %d\n", carta1.nome_cidade, carta1.estado, carta1.populacao);
        printf("Carta 2 - %s (%c): %d\n", carta2.nome_cidade, carta2.estado, carta2.populacao);
        if (carta1.populacao > carta2.populacao)
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
        else if (carta2.populacao > carta1.populacao)
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
        else
            printf("Resultado: Empate!\n");
    }
    else if (atributo == 2) { // Área
        printf("Comparação de cartas (Atributo: Área):\n");
        printf("Carta 1 - %s (%c): %.2f km²\n", carta1.nome_cidade, carta1.estado, carta1.area);
        printf("Carta 2 - %s (%c): %.2f km²\n", carta2.nome_cidade, carta2.estado, carta2.area);
        if (carta1.area > carta2.area)
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
        else if (carta2.area > carta1.area)
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
        else
            printf("Resultado: Empate!\n");
    }
    else if (atributo == 3) { // PIB
        printf("Comparação de cartas (Atributo: PIB):\n");
        printf("Carta 1 - %s (%c): R$ %.2f bilhões\n", carta1.nome_cidade, carta1.estado, carta1.pib);
        printf("Carta 2 - %s (%c): R$ %.2f bilhões\n", carta2.nome_cidade, carta2.estado, carta2.pib);
        if (carta1.pib > carta2.pib)
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
        else if (carta2.pib > carta1.pib)
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
        else
            printf("Resultado: Empate!\n");
    }
    else if (atributo == 4) { // Densidade Populacional (MENOR valor vence)
        printf("Comparação de cartas (Atributo: Densidade Populacional):\n");
        printf("Carta 1 - %s (%c): %.2f hab/km²\n", carta1.nome_cidade, carta1.estado, dens1);
        printf("Carta 2 - %s (%c): %.2f hab/km²\n", carta2.nome_cidade, carta2.estado, dens2);
        if (dens1 < dens2)
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
        else if (dens2 < dens1)
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
        else
            printf("Resultado: Empate!\n");
    }
    else if (atributo == 5) { // PIB per capita
        printf("Comparação de cartas (Atributo: PIB per capita):\n");
        printf("Carta 1 - %s (%c): R$ %.2f\n", carta1.nome_cidade, carta1.estado, pib_per_capita1);
        printf("Carta 2 - %s (%c): R$ %.2f\n", carta2.nome_cidade, carta2.estado, pib_per_capita2);
        if (pib_per_capita1 > pib_per_capita2)
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
        else if (pib_per_capita2 > pib_per_capita1)
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
        else
            printf("Resultado: Empate!\n");
    }
}

int main() {
    // Cadastro das cartas
    Carta carta1 = {
        'S', "C001", "São Paulo",
        12300000, // população
        1521.11,  // área
        830.00,   // PIB (em bilhões)
        10        // pontos turísticos
    };

    Carta carta2 = {
        'R', "C002", "Rio de Janeiro",
        6718903,  // população
        1182.30,  // área
        400.00,   // PIB (em bilhões)
        8         // pontos turísticos
    };

    // Comparar as duas cartas
    comparar_cartas(carta1, carta2);

    return 0;
}
