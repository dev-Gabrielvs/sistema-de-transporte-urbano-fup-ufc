#include "application_base.h"
#include "math.h"

#define TAXA_TARIFA 1.4f

void get_all_route_tax(void) { 
    unsigned int linha_id;
    fprintf(stderr, "Digite o ID da linha para calcular a tarifa: ");
    scanf("%u", &linha_id);

    float km_total = 0.0;

    for (unsigned int i = 0; i < num_linhas; i++) {
        if (linhas[i].id == linha_id) {
            Parada *atual = linhas[i].paradas;

            if (atual == NULL) {
                fprintf(stderr, "A linha %u não possui paradas cadastradas.\n", linha_id);
                return;
            }

            while (atual->proxima != NULL) {
                atual = atual->proxima;
            }
            km_total = atual->distancia_km;
        }
    }

    if (km_total <= 0) {
        fprintf(stderr, "Linha %u não encontrada ou sem paradas cadastradas.\n", linha_id);
        return;
    }

    fprintf(stderr, "A tarifa para a linha %u é: R$ %.2f\n", linha_id, km_total * TAXA_TARIFA);
}

void get_route_tax(void) {
    unsigned int linha_id;
    char parada_origem[50], parada_destino[50];
    fprintf(stderr, "Digite o ID da linha para calcular a tarifa: ");
    scanf("%u", &linha_id);
    getchar();

    fprintf(stderr, "Digite o nome da parada de origem: ");
    fgets(parada_origem, sizeof(parada_origem), stdin);
    parada_origem[strcspn(parada_origem, "\n")] = '\0';

    fprintf(stderr, "Digite o nome da parada de destino: ");
    fgets(parada_destino, sizeof(parada_destino), stdin);
    parada_destino[strcspn(parada_destino, "\n")] = '\0';

    float km_origem = -1.0f, km_destino = -1.0f;

    for (unsigned int i = 0; i < num_linhas; i++) {
        if (linhas[i].id == linha_id) {
            Parada *atual = linhas[i].paradas;

            if (atual == NULL) {
                fprintf(stderr, "A linha %u não possui paradas cadastradas.\n", linha_id);
                return;
            }

            while (atual != NULL) {
                if (strcmp(atual->nome, parada_origem) == 0) {
                    km_origem = atual->distancia_km;
                }
                if (strcmp(atual->nome, parada_destino) == 0) {
                    km_destino = atual->distancia_km;
                }
                atual = atual->proxima;
            }
        }
    }

    if (km_origem < 0 || km_destino < 0) {
        fprintf(stderr, "Parada de origem ou destino não encontrada na linha %u.\n", linha_id);
        return;
    }

    float distancia = fabsf(km_destino - km_origem);
    fprintf(stderr, "A tarifa para a linha %u entre %s e %s é: R$ %.2f\n", linha_id, parada_origem, parada_destino, distancia * TAXA_TARIFA);
    
}