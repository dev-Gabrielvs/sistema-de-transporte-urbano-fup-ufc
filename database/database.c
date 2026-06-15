#include "database.h"

Empresa *empresas;
unsigned int num_empresas;
size_t capacidade_empresas;
unsigned int proximo_id_empresa;

Motorista *motoristas;
unsigned int num_motoristas;
size_t capacidade_motoristas;
unsigned int proximo_id_motorista;

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

    return 1;
}

void db_clear(void){
    free(empresas);
    free(motoristas);
}