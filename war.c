#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struct Território
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// ==== Funções ====
Territorio* criarMapa(int* qtd);
void exibirTerritorios(Territorio* mapa, int qtd);
void atacar(Territorio* atacante, Territorio* defensor);
void liberarMemoria(Territorio* mapa);
void pausar();

int main() {
    srand(time(NULL));

    int qtd = 0;
    int op, atacante, defensor;

    Territorio* mapa = criarMapa(&qtd);

    do {
        system("cls || clear");
        printf("===== MAPA DE TERRITORIOS =====\n");
        exibirTerritorios(mapa, qtd);

        printf("\n---- MENU ----\n");
        printf("1 - Realizar ataque\n");
        printf("0 - Sair\n> ");
        scanf("%d", &op);
        getchar();

        if(op == 1) {
            printf("\nEscolha o índice do territorio ATACANTE: ");
            scanf("%d", &atacante);
            printf("Escolha o índice do territorio DEFENSOR: ");
            scanf("%d", &defensor);
            getchar();

            if(atacante < 0 || atacante >= qtd || defensor < 0 || defensor >= qtd) {
                printf("\nÍndice inválido!\n");
                pausar();
                continue;
            }

            if(strcmp(mapa[atacante].cor, mapa[defensor].cor) == 0) {
                printf("\nErro: voce nao pode atacar um territorio da mesma cor!\n");
                pausar();
                continue;
            }

            if(mapa[atacante].tropas <= 0) {
                printf("\nO atacante nao possui tropas suficientes!\n");
                pausar();
                continue;
            }

            atacar(&mapa[atacante], &mapa[defensor]);
            pausar();
        }

    } while(op != 0);

    liberarMemoria(mapa);
    printf("\nPrograma encerrado!\n");
    return 0;
}

// ===============================================
// Cria o mapa automaticamente com nomes e cores
Territorio* criarMapa(int* qtd) {
    *qtd = 6;  // total de territórios pré-definidos

    Territorio* mapa = (Territorio*) calloc(*qtd, sizeof(Territorio));

    // --- Territórios preenchidos automaticamente ---
    strcpy(mapa[0].nome, "Base Norte");
    strcpy(mapa[0].cor,  "Azul");
    mapa[0].tropas = 10;

    strcpy(mapa[1].nome, "Montanha Rubra");
    strcpy(mapa[1].cor,  "Vermelho");
    mapa[1].tropas = 8;

    strcpy(mapa[2].nome, "Floresta Esmeralda");
    strcpy(mapa[2].cor,  "Verde");
    mapa[2].tropas = 12;

    strcpy(mapa[3].nome, "Castelo Sombrio");
    strcpy(mapa[3].cor,  "Preto");
    mapa[3].tropas = 9;

    strcpy(mapa[4].nome, "Deserto Solar");
    strcpy(mapa[4].cor,  "Amarelo");
    mapa[4].tropas = 7;

    strcpy(mapa[5].nome, "Vale Oeste");
    strcpy(mapa[5].cor,  "Azul");
    mapa[5].tropas = 5;

    return mapa;
}

// Exibe o mapa
void exibirTerritorios(Territorio* mapa, int qtd) {
    printf("\n--- Territorios ---\n");
    for(int i = 0; i < qtd; i++) {
        printf("[%d] %-17s | Cor: %-8s | Tropas: %d\n",
            i, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
}

// Função de ataque
void atacar(Territorio* atacante, Territorio* defensor) {
    int dadoAtq = (rand() % 6) + 1;
    int dadoDef = (rand() % 6) + 1;

    printf("\n=== BATALHA ===\n");
    printf("Atacante: %s (%s) Tropas: %d\n", atacante->nome, atacante->cor, atacante->tropas);
    printf("Defensor:  %s (%s) Tropas: %d\n", defensor->nome, defensor->cor, defensor->tropas);
    printf("Dados -> Atacante: (%d) x Defensor: (%d)\n", dadoAtq, dadoDef);

    if(dadoAtq > dadoDef) {
        printf("\n>>> VITORIA DO ATACANTE!\n");

        strcpy(defensor->cor, atacante->cor);

        defensor->tropas = atacante->tropas / 2;
        atacante->tropas -= defensor->tropas;

        printf("%s agora pertence ao exercito %s!\n", defensor->nome, defensor->cor);
    } else {
        printf("\n>>> DEFESA VENCEU!\n");
        atacante->tropas--;
        if(atacante->tropas < 0)
            atacante->tropas = 0;
    }
}

// Libera memória
void liberarMemoria(Territorio* mapa) {
    free(mapa);
}

// Pausa cross-platform
void pausar() {
    printf("\nPressione ENTER para continuar...");
    getchar();
}
