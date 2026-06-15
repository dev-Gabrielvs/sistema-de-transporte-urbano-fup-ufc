#include "application_base.h"

Horario_Linha* ListarHorariosDaLinha(unsigned int linha_id) {
    for (unsigned int i = 0; i < num_linhas; i++) {
        if (linhas[i].id == linha_id) {
            return linhas[i].horarios;
        }
    }
    return NULL;
}

Horario_Linha AdicionarHorarioALinha(unsigned int linha_id, unsigned short hora, unsigned short minuto) {
    Horario_Linha novo_horario;
    novo_horario.id = proximo_id_horario;
    novo_horario.hora = hora;
    novo_horario.minuto = minuto;
    novo_horario.proximo = NULL;

    proximo_id_horario++;

    for (unsigned int i = 0; i < num_linhas; i++) {
        if (linhas[i].id == linha_id) {
            if (linhas[i].horarios == NULL) {
                linhas[i].horarios = malloc(sizeof(Horario_Linha));
                
                if (linhas[i].horarios == NULL) {
                    fprintf(stderr, "Erro ao alocar memória para o novo horário.\n");
                    return (Horario_Linha){0, 0, 0, NULL};
                }
                
                *linhas[i].horarios = novo_horario;
                return novo_horario;
            } else {
                Horario_Linha* anterior = NULL;
                Horario_Linha* atual = linhas[i].horarios;

                while (atual != NULL && (atual->hora < novo_horario.hora || 
                        (atual->hora == novo_horario.hora && atual->minuto < novo_horario.minuto))) {
                    anterior = atual;
                    atual = atual->proximo;
                }

                Horario_Linha *novo_horario_ptr = malloc(sizeof(Horario_Linha));

                if (novo_horario_ptr == NULL) {
                    fprintf(stderr, "Erro ao alocar memória para o novo horário.\n");
                    return (Horario_Linha){0, 0, 0, NULL};
                }

                *novo_horario_ptr = novo_horario;
                novo_horario_ptr->proximo = atual;

                if (anterior == NULL) {
                    linhas[i].horarios = novo_horario_ptr;
                } else {
                    anterior->proximo = novo_horario_ptr;
                }
                return novo_horario;
            }
        }
    }
    return (Horario_Linha){0, 0, 0, NULL};
}

short RemoverHorarioDaLinha(unsigned int linha_id, unsigned int horario_id) {
    for (unsigned int i = 0; i < num_linhas; i++) {
        if (linhas[i].id == linha_id) {
            Horario_Linha* anterior = NULL;
            Horario_Linha* atual = linhas[i].horarios;

            while (atual != NULL) {
                if (atual->id == horario_id) {
                    if (anterior == NULL) {
                        linhas[i].horarios = atual->proximo;
                    } else {
                        anterior->proximo = atual->proximo;
                    }
                    free(atual);
                    return 1;
                }
                anterior = atual;
                atual = atual->proximo;
            }
        }
    }
    return 0;
}
