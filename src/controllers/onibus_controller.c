#include "application_base.h"

void index_onibus(void){
    Onibus *onibus_listados = ListarOnibus();

    for (unsigned int i = 0; i < num_onibus; i++) {
        printf("ID: %u, Placa: %s, Modelo: %s\n", onibus_listados[i].id, onibus_listados[i].placa, onibus_listados[i].modelo);
    }
}

void show_onibus_by_licence_plate(void){
    char placa[10];
    fprintf(stdout, "Digite a placa do ônibus que deseja buscar: ");
    fgets(placa, sizeof(placa), stdin);
    placa[strcspn(placa, "\n")] = 0;

    Onibus onibus_buscado = BuscarOnibusPorPlaca(placa);
    if (onibus_buscado.id != 0) {
        printf("ID: %u, Placa: %s, Modelo: %s\n", onibus_buscado.id, onibus_buscado.placa, onibus_buscado.modelo);
    } else {
        fprintf(stderr, "Ônibus não encontrado.\n");
    }
}

void show_onibus_by_driver(void){
    char nome[50];
    fprintf(stdout, "Digite o nome do motorista que deseja buscar: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    Onibus onibus_buscado = BuscarOnibusPorMotorista(nome);
    if (onibus_buscado.id != 0) {
        printf("ID: %u, Placa: %s, Modelo: %s\n", onibus_buscado.id, onibus_buscado.placa, onibus_buscado.modelo);
    } else {
        fprintf(stderr, "Ônibus não encontrado para o motorista '%s'.\n", nome);
    }
}

void create_onibus (void) {
    char placa[10], modelo[20];
    unsigned short ano_fabricacao, capacidade_passageiros;
    unsigned int id_linha, id_motorista;

    fprintf(stdout, "Digite a placa do ônibus: ");
    fgets(placa, sizeof(placa), stdin);
    placa[strcspn(placa, "\n")] = 0;

    fprintf(stdout, "Digite o modelo do ônibus: ");
    fgets(modelo, sizeof(modelo), stdin);
    modelo[strcspn(modelo, "\n")] = 0;

    fprintf(stdout, "Digite o ano de fabricação do ônibus: ");
    scanf("%hu", &ano_fabricacao);
    getchar();

    fprintf(stdout, "Digite a capacidade de passageiros do ônibus: ");
    scanf("%hu", &capacidade_passageiros);
    getchar();

    fprintf(stdout, "Digite o ID da linha associada ao ônibus: ");
    scanf("%u", &id_linha);
    getchar();

    fprintf(stdout, "Digite o ID do motorista associado ao ônibus: ");
    scanf("%u", &id_motorista);
    getchar();

    Onibus novo_onibus = AdicionarOnibus(placa, modelo, ano_fabricacao, capacidade_passageiros, id_linha, id_motorista);
    if (novo_onibus.id != 0) {
        printf("Ônibus '%s' adicionado com ID %u.\n", novo_onibus.placa, novo_onibus.id);
    } else {
        fprintf(stderr, "Erro ao adicionar ônibus.\n");
    }
}

void update_onibus(void) {
    unsigned int id;
    char nova_placa[10], novo_modelo[20];
    unsigned short novo_ano_fabricacao, nova_capacidade_passageiros;
    unsigned int nova_id_linha, nova_id_motorista;

    fprintf(stdout, "Digite o ID do ônibus que deseja editar: ");
    scanf("%u", &id);
    getchar();

    fprintf(stdout, "Digite a nova placa do ônibus: ");
    fgets(nova_placa, sizeof(nova_placa), stdin);
    nova_placa[strcspn(nova_placa, "\n")] = 0;

    fprintf(stdout, "Digite o novo modelo do ônibus: ");
    fgets(novo_modelo, sizeof(novo_modelo), stdin);
    novo_modelo[strcspn(novo_modelo, "\n")] = 0;

    fprintf(stdout, "Digite o novo ano de fabricação do ônibus: ");
    scanf("%hu", &novo_ano_fabricacao);
    getchar();

    fprintf(stdout, "Digite a nova capacidade de passageiros do ônibus: ");
    scanf("%hu", &nova_capacidade_passageiros);
    getchar();

    fprintf(stdout, "Digite o novo ID da linha associada ao ônibus: ");
    scanf("%u", &nova_id_linha);
    getchar();

    fprintf(stdout, "Digite o novo ID do motorista associado ao ônibus: ");
    scanf("%u", &nova_id_motorista);
    getchar();

    Onibus onibus_editado = EditarOnibus(id, nova_placa, novo_modelo, novo_ano_fabricacao, nova_capacidade_passageiros, nova_id_linha, nova_id_motorista);
    if (onibus_editado.id != 0) {
        printf("Ônibus com ID %u editado para placa '%s' e modelo '%s'.\n", onibus_editado.id, onibus_editado.placa, onibus_editado.modelo);
    } else {
        fprintf(stderr, "Erro ao editar ônibus. Ônibus com ID %u não encontrado.\n", id);
    }
}

void delete_onibus(void) {
    unsigned int id;
    fprintf(stdout, "Digite o ID do ônibus que deseja remover: ");
    scanf("%u", &id);
    getchar();

    if (RemoverOnibus(id)) {
        printf("Ônibus com ID %u removido.\n", id);
    } else {
        fprintf(stderr, "Erro ao remover ônibus. Ônibus com ID %u não encontrado.\n", id);
    }
}