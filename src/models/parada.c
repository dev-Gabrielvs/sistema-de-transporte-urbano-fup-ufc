#include "application_base.h"

Parada* ListarParadasDaLinha(unsigned int linha_id){
    for (unsigned int i = 0; i < num_linhas; i++) {
        if (linhas[i].id == linha_id) {
            return linhas[i].paradas;
        }
    }
    return NULL;
}

Parada AdicionarParadaALinha(unsigned int linha_id, const char* nome_parada, float distancia_km) {
    Parada nova_parada;
    nova_parada.id = proximo_id_parada;
    strcpy(nova_parada.nome, nome_parada);
    nova_parada.distancia_km = distancia_km;
    nova_parada.proxima = NULL;

    proximo_id_parada++;

    for (unsigned int i = 0; i < num_linhas; i++) {
        if (linhas[i].id == linha_id) {
            if (linhas[i].paradas == NULL) {
                linhas[i].paradas = malloc(sizeof(Parada));
                
                if (linhas[i].paradas == NULL) {
                    fprintf(stderr, "Erro ao alocar memória para a nova parada.\n");
                    return (Parada){0, "", 0, NULL};
                }
                
                *linhas[i].paradas = nova_parada;
                return nova_parada;
            } else {
                Parada* anterior = NULL;
                Parada* atual = linhas[i].paradas;

                while (atual != NULL && atual->distancia_km < nova_parada.distancia_km) {
                    anterior = atual;
                    atual = atual->proxima;
                }

                Parada *nova_parada_ptr = malloc(sizeof(Parada));

                if (nova_parada_ptr == NULL) {
                    fprintf(stderr, "Erro ao alocar memória para a nova parada.\n");
                    return (Parada){0, "", 0, NULL};
                }

                *nova_parada_ptr = nova_parada;
                nova_parada_ptr->proxima = atual;

                if (anterior == NULL) {
                    linhas[i].paradas = nova_parada_ptr;
                } else {
                    anterior->proxima = nova_parada_ptr;
                }
                return nova_parada;


            }
        }
    }

    return (Parada){0, "", 0, NULL};
}

short RemoverParadaDaLinha(unsigned int linha_id, unsigned int parada_id) {
    for (unsigned int i = 0; i < num_linhas; i++) {
        if (linhas[i].id == linha_id) {
            Parada* anterior = NULL;
            Parada* atual = linhas[i].paradas;

            while (atual != NULL) {
                if (atual->id == parada_id) {
                    if (anterior == NULL) {
                        linhas[i].paradas = atual->proxima;
                    } else {
                        anterior->proxima = atual->proxima;
                    }

                    free(atual);
                    return 1;
                }
                anterior = atual;
                atual = atual->proxima;
            }
        }
    }
    return 0;
}

Parada EditarParadaDaLinha(unsigned int linha_id, unsigned int parada_id, const char* novo_nome) {
    for (unsigned int i = 0; i < num_linhas; i++) {
        if (linhas[i].id == linha_id) {
            Parada* atual = linhas[i].paradas;

            while (atual != NULL) {
                if (atual->id == parada_id) {
                    strcpy(atual->nome, novo_nome);
                    return *atual;
                }
                atual = atual->proxima;
            }
        }
    }
    return (Parada){0, "", 0, NULL};
}