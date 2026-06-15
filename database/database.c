#include "database.h"

Empresa *empresas;
unsigned int num_empresas;
size_t capacidade_empresas;
unsigned int proximo_id_empresa;

short db_init(void) {
    capacidade_empresas = 5;
    empresas = malloc(sizeof(Empresa) * capacidade_empresas);

    if (empresas == NULL) {
        fprintf(stderr, "Erro ao alocar memória para empresas.\n");
        return 0;
    }

    num_empresas = 0;
    proximo_id_empresa = 1;
    return 1;
}

void db_clear(void){
    free(empresas);
}