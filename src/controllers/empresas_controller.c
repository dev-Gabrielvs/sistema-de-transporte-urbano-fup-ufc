#include "application_base.h"

void index_empresas(void){
    Empresa *empresas_listadas = ListarEmpresas();

    for (unsigned int i = 0; i < num_empresas; i++) {
        printf("ID: %u, Nome: %s\n", empresas_listadas[i].id, empresas_listadas[i].nome);
    }
}

void show_empresa(void){
    char nome[50];
    fprintf(stdout, "Digite o nome da empresa que deseja buscar: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    Empresa empresa_buscada = BuscarEmpresaPorNome(nome);
    if (empresa_buscada.id != 0) {
        printf("ID: %u, Nome: %s\n", empresa_buscada.id, empresa_buscada.nome);
    } else {
        fprintf(stderr, "Empresa não encontrada.\n");
    }
}

void create_empresa(void){
    char nome[50];
    fprintf(stdout, "Digite o nome da nova empresa: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    Empresa nova_empresa = AdicionarEmpresa(nome);
    if (nova_empresa.id != 0) {
        printf("Empresa '%s' adicionada com ID %u.\n", nova_empresa.nome, nova_empresa.id);
    } else {
        fprintf(stderr, "Erro ao adicionar empresa.\n");
    }
}

void update_empresa(void){
    char nome[50];
    unsigned int id;
    fprintf(stdout, "Digite o ID da empresa que deseja editar: ");
    scanf("%u", &id);
    getchar();

    fprintf(stdout, "Digite o novo nome da empresa: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    Empresa empresa_editada = EditarEmpresa(id, nome);
    if (empresa_editada.id != 0) {
        printf("Empresa com ID %u editada para '%s'.\n", empresa_editada.id, empresa_editada.nome);
    } else {
        fprintf(stderr, "Erro ao editar empresa. Empresa com ID %u não encontrada.\n", id);
    }
}

void delete_empresa(void){
    unsigned int id;
    fprintf(stdout, "Digite o ID da empresa que deseja remover: ");
    scanf("%u", &id);
    getchar();

    if (RemoverEmpresa(id)) {
        printf("Empresa com ID %u removida.\n", id);
    } else {
        fprintf(stderr, "Erro ao remover empresa. Empresa com ID %u não encontrada.\n", id);
    }
}