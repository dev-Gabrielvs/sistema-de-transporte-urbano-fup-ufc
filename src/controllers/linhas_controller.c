#include "application_base.h"

void index_linhas(void){
    Linha *linhas_listadas = ListarLinhas();

    for (unsigned int i = 0; i < num_linhas; i++) {
        printf("ID: %u, Nome: %s\n", linhas_listadas[i].id, linhas_listadas[i].nome);
    }
}

void show_linha_by_name(void){
    char nome[50];
    fprintf(stdout, "Digite o nome da linha que deseja buscar: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    Linha linha_buscada = BuscarLinhaPorNome(nome);
    if (linha_buscada.id != 0) {
        printf("ID: %u, Nome: %s\n", linha_buscada.id, linha_buscada.nome);
    } else {
        fprintf(stderr, "Linha não encontrada.\n");
    }
}

void show_linhas_by_company(void){
    char nome[50];
    fprintf(stdout, "Digite o nome da empresa para listar suas linhas: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    LinhasPorEmpresa linhas_empresa = BuscarLinhasPorEmpresa(nome);
    if (linhas_empresa.num_linhas_empresa > 0) {
        printf("Linhas da empresa '%s':\n", nome);
        for (unsigned int i = 0; i < linhas_empresa.num_linhas_empresa; i++) {
            printf("ID: %u, Nome: %s\n", linhas_empresa.linhas_empresa[i].id, linhas_empresa.linhas_empresa[i].nome);
        }
        free(linhas_empresa.linhas_empresa);
    } else {
        fprintf(stderr, "Nenhuma linha encontrada para a empresa '%s'.\n", nome);
    }
}

void create_linha(void){
    char nome[50];
    unsigned int id_empresa;
    fprintf(stdout, "Digite o nome da nova linha: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    fprintf(stdout, "Digite o ID da empresa para associar a linha: ");
    scanf("%u", &id_empresa);
    getchar();

    Linha nova_linha = AdicionarLinha(nome, id_empresa);
    if (nova_linha.id != 0) {
        printf("Linha '%s' adicionada com ID %u.\n", nova_linha.nome, nova_linha.id);
    } else {
        fprintf(stderr, "Erro ao adicionar linha.\n");
    }
}

void update_linha(void){
    char nome[50];
    unsigned int id;
    fprintf(stdout, "Digite o ID da linha que deseja editar: ");
    scanf("%u", &id);
    getchar();

    fprintf(stdout, "Digite o novo nome da linha: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    Linha linha_editada = EditarLinha(id, nome);
    if (linha_editada.id != 0) {
        printf("Linha com ID %u editada para '%s'.\n", linha_editada.id, linha_editada.nome);
    } else {
        fprintf(stderr, "Erro ao editar linha. Linha com ID %u não encontrada.\n", id);
    }
}

void delete_linha(void){
    unsigned int id;
    fprintf(stdout, "Digite o ID da linha que deseja remover: ");
    scanf("%u", &id);
    getchar();

    if (RemoverLinha(id)) {
        printf("Linha com ID %u removida.\n", id);
    } else {
        fprintf(stderr, "Erro ao remover linha. Linha com ID %u não encontrada.\n", id);
    }
}