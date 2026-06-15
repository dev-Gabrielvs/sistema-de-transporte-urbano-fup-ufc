#include "application_base.h"

void show_horarios_by_linha_id(void){
    unsigned int linha_id;
    printf("Digite o ID da linha para listar seus horários: ");
    scanf("%u", &linha_id);

    Horario_Linha* horarios = ListarHorariosDaLinha(linha_id);
    if (horarios == NULL) {
        printf("Nenhum horário encontrado para a linha com ID %u.\n", linha_id);
        return;
    }

    printf("Horários da linha com ID %u:\n", linha_id);
    Horario_Linha* atual = horarios;
    while (atual != NULL) {
        printf("ID: %u, Hora: %02u:%02u\n", atual->id, atual->hora, atual->minuto);
        atual = atual->proximo;
    }
}

void create_horario_for_linha(void) {
    unsigned int linha_id;
    unsigned short hora, minuto;

    printf("Digite o ID da linha para adicionar um horário: ");
    scanf("%u", &linha_id);
    printf("Digite a hora (0-23): ");
    scanf("%hu", &hora);
    printf("Digite os minutos (0-59): ");
    scanf("%hu", &minuto);

    Horario_Linha novo_horario = AdicionarHorarioALinha(linha_id, hora, minuto);
    if (novo_horario.id == 0) {
        printf("Erro ao adicionar o horário à linha com ID %u.\n", linha_id);
    } else {
        printf("Horário %02u:%02u adicionado com sucesso à linha com ID %u.\n", hora, minuto, linha_id);
    }
}

void delete_horario_from_linha(void) {
    unsigned int linha_id;
    unsigned int horario_id;

    printf("Digite o ID da linha para deletar um horário: ");
    scanf("%u", &linha_id);
    printf("Digite o ID do horário para deletar: ");
    scanf("%u", &horario_id);

    int resultado = RemoverHorarioDaLinha(linha_id, horario_id);
    if (resultado == 0) {
        printf("Erro ao deletar o horário com ID %u da linha com ID %u.\n", horario_id, linha_id);
    } else {
        printf("Horário com ID %u deletado com sucesso da linha com ID %u.\n", horario_id, linha_id);
    }
}