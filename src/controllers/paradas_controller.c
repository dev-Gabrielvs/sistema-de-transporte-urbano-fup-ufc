#include "application_base.h"

void show_paradas_by_linha_id(void) {
    unsigned int linha_id;
    printf("Digite o ID da linha para listar suas paradas: ");
    scanf("%u", &linha_id);

    Parada* paradas = ListarParadasDaLinha(linha_id);
    if (paradas == NULL) {
        printf("Nenhuma parada encontrada para a linha com ID %u.\n", linha_id);
        return;
    }

    printf("Paradas da linha com ID %u:\n", linha_id);
    Parada* atual = paradas;
    while (atual != NULL) {
        printf("ID: %u, Nome: %s, Distância: %.2f km\n", atual->id, atual->nome, atual->distancia_km);
        atual = atual->proxima;
    }
}

void create_parada_for_linha(void) {
    unsigned int linha_id;
    char nome_parada[50];
    float distancia_km;

    printf("Digite o ID da linha para adicionar uma parada: ");
    scanf("%u", &linha_id);
    printf("Digite o nome da parada: ");
    scanf(" %[^\n]", nome_parada); // Lê uma linha inteira, incluindo
    printf("Digite a distância da parada em km: ");
    scanf("%f", &distancia_km);

    Parada nova_parada = AdicionarParadaALinha(linha_id, nome_parada, distancia_km);
    if (nova_parada.id == 0) {
        printf("Erro ao adicionar a parada à linha com ID %u.\n", linha_id);
    } else {
        printf("Parada '%s' adicionada com sucesso à linha com ID %u.\n", nome_parada, linha_id);
    }
}

void update_parada_from_linha(void) {
    unsigned int linha_id;
    unsigned int parada_id;
    char nome_parada[50];

    printf("Digite o ID da linha para editar uma parada: ");
    scanf("%u", &linha_id);
    printf("Digite o ID da parada para editar: ");
    scanf("%u", &parada_id);
    printf("Digite o novo nome da parada: ");
    fgets(nome_parada, sizeof(nome_parada), stdin);
    nome_parada[strcspn(nome_parada, "\n")] = 0;
    
    Parada parada_editada = EditarParadaDaLinha(linha_id, parada_id, nome_parada);
    if (parada_editada.id == 0) {
        printf("Erro ao editar a parada com ID %u na linha com ID %u.\n", parada_id, linha_id);
    } else {
        printf("Parada com ID %u editada com sucesso na linha com ID %u.\n", parada_id, linha_id);
    }
}

void delete_parada_from_linha(void) {
    unsigned int linha_id;
    unsigned int parada_id;

    printf("Digite o ID da linha para remover uma parada: ");
    scanf("%u", &linha_id);
    printf("Digite o ID da parada para remover: ");
    scanf("%u", &parada_id);

    if (!RemoverParadaDaLinha(linha_id, parada_id)) {
        printf("Erro ao remover a parada da linha com ID %u.\n", linha_id);
    } else {
        printf("Parada removida com sucesso da linha com ID %u.\n", linha_id);
    }
}