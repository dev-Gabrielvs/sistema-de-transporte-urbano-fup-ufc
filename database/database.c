#include "database.h"

Empresa *empresas;
unsigned int num_empresas;
size_t capacidade_empresas;
unsigned int proximo_id_empresa;

Motorista *motoristas;
unsigned int num_motoristas;
size_t capacidade_motoristas;
unsigned int proximo_id_motorista;

Linha *linhas;
unsigned int num_linhas;
size_t capacidade_linhas;
unsigned int proximo_id_linha;

Onibus *onibus;
unsigned int num_onibus;
size_t capacidade_onibus;
unsigned int proximo_id_onibus;

unsigned int proximo_id_parada;
unsigned int proximo_id_horario;

short db_init(void) {
    capacidade_empresas = 5;
    empresas = malloc(sizeof(Empresa) * capacidade_empresas);

    if (empresas == NULL) {
        fprintf(stderr, "Erro ao alocar memória para empresas.\n");
        return 0;
    }

    num_empresas = 0;
    proximo_id_empresa = 1;

    capacidade_motoristas = 5;
    motoristas = malloc(sizeof(Motorista) * capacidade_motoristas);

    if (motoristas == NULL) {
        fprintf(stderr, "Erro ao alocar memória para motoristas.\n");
        return 0;
    }

    num_motoristas = 0;
    proximo_id_motorista = 1;

    capacidade_linhas = 5;
    linhas = malloc(sizeof(Linha) * capacidade_linhas);

    if (linhas == NULL) {
        fprintf(stderr, "Erro ao alocar memória para linhas.\n");
        return 0;
    }

    num_linhas = 0;
    proximo_id_linha = 1;

    capacidade_onibus = 5;
    onibus = malloc(sizeof(Onibus) * capacidade_onibus);

    if (onibus == NULL) {
        fprintf(stderr, "Erro ao alocar memória para ônibus.\n");
        return 0;
    }

    num_onibus = 0;
    proximo_id_onibus = 1;

    proximo_id_parada = 1;
    proximo_id_horario = 1;

    return 1;
}

void db_clear(void){
    free(empresas);
    free(motoristas);
    
    while (num_linhas > 0) {
        Linha *linha = &linhas[--num_linhas];
        
        while (linha->paradas != NULL) {
            Parada *temp_parada = linha->paradas;
            linha->paradas = linha->paradas->proxima;
            free(temp_parada);
        }

        while (linha->horarios != NULL) {
            Horario_Linha *temp_horario = linha->horarios;
            linha->horarios = linha->horarios->proximo;
            free(temp_horario);
        }
    }
    free(linhas);

    free(onibus);
}