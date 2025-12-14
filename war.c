#include <stdio.h>
#include <string.h>

// Definição da struct Territorio
// Esta estrutura armazena o nome do território,
// a cor do exército e a quantidade de tropas
typedef struct {
    char nome[30];   // Nome do território
    char cor[10];    // Cor do exército
    int tropas;      // Quantidade de tropas
} Territorio;

int main() {
    // Declaração e preenchimento direto do vetor de territórios
    // Os dados abaixo são exemplos já cadastrados no sistema
    Territorio territorios[5] = {
        {"Norte", "Azul", 150},
        {"Sul", "Vermelho", 120},
        {"Leste", "Verde", 200},
        {"Oeste", "Amarelo", 180},
        {"Central", "Preto", 250}
    };

    // Exibição dos dados cadastrados
    printf("===== TERRITÓRIOS CADASTRADOS =====\n");

    for (int i = 0; i < 5; i++) {
        printf("\nTerritório %d\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do Exército: %s\n", territorios[i].cor);
        printf("Quantidade de Tropas: %d\n", territorios[i].tropas);
    }

    return 0;
}
