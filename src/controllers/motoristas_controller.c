#include "application_base.h"

void index_motoristas(void){
    Motorista *motoristas_listados = ListarMotoristas();

    for (unsigned int i = 0; i < num_motoristas; i++) {
        printf("ID: %u, Nome: %s, Idade: %hu, Sexo: %c, ID Empresa: %u\n", motoristas_listados[i].id, motoristas_listados[i].nome, motoristas_listados[i].idade, motoristas_listados[i].sexo, motoristas_listados[i].id_empresa);
    }
}

void show_motorista_by_name(void){
    char nome[50];
    fprintf(stdout, "Digite o nome do motorista que deseja buscar: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    Motorista motorista_buscado = BuscarMotoristaPorNome(nome);
    if (motorista_buscado.id != 0) {
        printf("ID: %u, Nome: %s, Idade: %hu, Sexo: %c, ID Empresa: %u\n", motorista_buscado.id, motorista_buscado.nome, motorista_buscado.idade, motorista_buscado.sexo, motorista_buscado.id_empresa);
    } else {
        fprintf(stderr, "Motorista não encontrado.\n");
    }
}

void show_motoristas_by_company(void){
    char nome[50];
    fprintf(stdout, "Digite o nome da empresa para listar seus motoristas: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    MotoristasPorEmpresa motoristas_empresa = BuscarMotoristasPorEmpresa(nome);
    if (motoristas_empresa.motoristas_empresa) {
        for (unsigned int i = 0; i < motoristas_empresa.num_motoristas_empresa; i++) {
            fprintf(stdout, "ID: %u, Nome: %s, Idade: %hu, Sexo: %c, ID Empresa: %u\n", motoristas_empresa.motoristas_empresa[i].id, motoristas_empresa.motoristas_empresa[i].nome, motoristas_empresa.motoristas_empresa[i].idade, motoristas_empresa.motoristas_empresa[i].sexo, motoristas_empresa.motoristas_empresa[i].id_empresa);
        }
        free(motoristas_empresa.motoristas_empresa);
    } else {
        fprintf(stderr, "Nenhum motorista encontrado para a empresa especificada.\n");
    }
}

void create_motorista(void){
    char nome[50];
    unsigned short idade;
    char sexo;
    unsigned int id_empresa;

    fprintf(stdout, "Digite o nome do novo motorista: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    fprintf(stdout, "Digite a idade do novo motorista: ");
    scanf("%hu", &idade);
    getchar();

    fprintf(stdout, "Digite o sexo do novo motorista (M/F): ");
    scanf("%c", &sexo);
    getchar();

    fprintf(stdout, "Digite o ID da empresa do novo motorista: ");
    scanf("%u", &id_empresa);
    getchar();

    Motorista novo_motorista = AdicionarMotorista(nome, idade, sexo, id_empresa);
    if (novo_motorista.id != 0) {
        printf("Motorista '%s' adicionado com ID %u.\n", novo_motorista.nome, novo_motorista.id);
    } else {
        fprintf(stderr, "Erro ao adicionar motorista.\n");
    }
}

void update_motorista(void){
    char nome[50];
    unsigned short idade;
    char sexo;
    unsigned int id_empresa;
    unsigned int id;

    fprintf(stdout, "Digite o ID do motorista que deseja editar: ");
    scanf("%u", &id);
    getchar();

    fprintf(stdout, "Digite o novo nome do motorista: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    fprintf(stdout, "Digite a nova idade do motorista: ");
    scanf("%hu", &idade);
    getchar();

    fprintf(stdout, "Digite o novo sexo do motorista (M/F): ");
    scanf("%c", &sexo);
    getchar();

    fprintf(stdout, "Digite o novo ID da empresa do motorista: ");
    scanf("%u", &id_empresa);
    getchar();

    Motorista motorista_editado = EditarMotorista(id, nome, idade, sexo, id_empresa);
    if (motorista_editado.id != 0) {
        printf("Motorista com ID %u editado para '%s'.\n", motorista_editado.id, motorista_editado.nome);
    } else {
        fprintf(stderr, "Erro ao editar motorista. Motorista com ID %u não encontrado.\n", id);
    }
}

void delete_motorista(void){
    unsigned int id;
    fprintf(stdout, "Digite o ID do motorista que deseja remover: ");
    scanf("%u", &id);
    getchar();

    if (RemoverMotorista(id)) {
        printf("Motorista com ID %u removido.\n", id);
    } else {
        fprintf(stderr, "Erro ao remover motorista. Motorista com ID %u não encontrado.\n", id);
    }
}