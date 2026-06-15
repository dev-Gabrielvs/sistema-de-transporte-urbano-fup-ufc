#include "application_base.h"

void main_cli(void);
void manage_companies_cli(void);
void manage_lines_cli(void);
void manage_drivers_cli(void);
void manage_buses_cli(void);
void taxes_cli(void);

void manage_companies(void);
void manage_lines(void);
void manage_drivers(void);
void manage_buses(void);
void taxes(void);

int main(void) {
    if (!db_init()) {
        fprintf(stderr, "Erro ao inicializar o banco de dados.\n");
        return 1;
    }

    short choice;

    do {
        main_cli();
        scanf("%hd", &choice);
        getchar();

        switch (choice) {
            case 0:
                fprintf(stderr, "Encerrando o programa. Até mais!\n");
                break;
            case 1:
                manage_companies();
                break;
            case 2:
                manage_lines();
                break;
            case 3:
                manage_drivers();
                break;
            case 4:
                manage_buses();
                break;
            case 5:
                taxes();
                break;
            default:
                fprintf(stderr, "Opção inválida. Tente alguma conhecida.\n");
                break;
        }
    } while (choice != 0);

    db_clear();
    return 0;
}

static void aguardar_tecla(void) {
    fprintf(stderr, "\nPressione Enter para continuar...");
    getchar();
}

void main_cli(void) {
    fprintf(stderr, "\033[2J\033[H");
    fprintf(stderr, "Bem vindo ao Sistema de Transporte Urbano, FUP!\n");
    fprintf(stderr, "Digite 1 para acessar o menu de gerenciamento de Empresas;\n");
    fprintf(stderr, "Digite 2 para acessar o menu de gerenciamento de Linhas;\n");
    fprintf(stderr, "Digite 3 para acessar o menu de gerenciamento de Motoristas;\n");
    fprintf(stderr, "Digite 4 para acessar o menu de gerenciamento de Onibus;\n");
    fprintf(stderr, "Digite 5 para calcular taxas;\n");
    fprintf(stderr, "Digite 0 para encerrar o programa.\n");
    fprintf(stderr, "Escolha: ");
}

void manage_companies_cli(void) {
    fprintf(stderr, "\033[2J\033[H");
    fprintf(stderr, "Menu de Gerenciamento de Empresas:\n");
    fprintf(stderr, "Digite 1 para Listar Empresas;\n");
    fprintf(stderr, "Digite 2 para Buscar Empresa por Nome;\n");
    fprintf(stderr, "Digite 3 para Adicionar Nova Empresa;\n");
    fprintf(stderr, "Digite 4 para Editar Empresa Existente;\n");
    fprintf(stderr, "Digite 5 para Remover Empresa;\n");
    fprintf(stderr, "Digite 0 para Voltar ao Menu Principal.\n");
    fprintf(stderr, "Escolha: ");
}

void manage_lines_cli(void) {
    fprintf(stderr, "\033[2J\033[H");
    fprintf(stderr, "Menu de Gerenciamento de Linhas:\n");
    fprintf(stderr, "Digite 1 para Listar Linhas;\n");
    fprintf(stderr, "Digite 2 para Listar as paradas de uma linha;\n");
    fprintf(stderr, "Digite 3 para Listar os horários de uma linha;\n");
    fprintf(stderr, "Digite 4 para Buscar Linha por Nome;\n");
    fprintf(stderr, "Digite 5 para Buscar linhas por empresa;\n");
    fprintf(stderr, "Digite 6 para Adicionar Nova Linha;\n");
    fprintf(stderr, "Digite 7 para Adicionar uma parada a uma linha;\n");
    fprintf(stderr, "Digite 8 para Adicionar um horário a uma linha;\n");
    fprintf(stderr, "Digite 9 para Editar Linha Existente;\n");
    fprintf(stderr, "Digite 10 para Editar uma parada de uma linha;\n");
    fprintf(stderr, "Digite 11 para Remover Linha;\n");
    fprintf(stderr, "Digite 12 para Remover uma parada de uma linha;\n");
    fprintf(stderr, "Digite 13 para Remover um horário de uma linha;\n");
    fprintf(stderr, "Digite 0 para Voltar ao Menu Principal.\n");
    fprintf(stderr, "Escolha: ");
}

void manage_drivers_cli(void) {
    fprintf(stderr, "\033[2J\033[H");
    fprintf(stderr, "Menu de Gerenciamento de Motoristas:\n");
    fprintf(stderr, "Digite 1 para Listar Motoristas;\n");
    fprintf(stderr, "Digite 2 para Buscar Motorista por Nome;\n");
    fprintf(stderr, "Digite 3 para Buscar Motoristas por Empresa;\n");
    fprintf(stderr, "Digite 4 para Adicionar Novo Motorista;\n");
    fprintf(stderr, "Digite 5 para Editar Motorista Existente;\n");
    fprintf(stderr, "Digite 6 para Remover Motorista;\n");
    fprintf(stderr, "Digite 0 para Voltar ao Menu Principal.\n");
    fprintf(stderr, "Escolha: ");
}

void manage_buses_cli(void) {
    fprintf(stderr, "\033[2J\033[H");
    fprintf(stderr, "Menu de Gerenciamento de Ônibus:\n");
    fprintf(stderr, "Digite 1 para Listar Ônibus;\n");
    fprintf(stderr, "Digite 2 para Buscar Ônibus por Placa;\n");
    fprintf(stderr, "Digite 3 para Buscar Ônibus por Motorista;\n");
    fprintf(stderr, "Digite 4 para Adicionar Novo Ônibus;\n");
    fprintf(stderr, "Digite 5 para Editar Ônibus Existente;\n");
    fprintf(stderr, "Digite 6 para Remover Ônibus;\n");
    fprintf(stderr, "Digite 0 para Voltar ao Menu Principal.\n");
    fprintf(stderr, "Escolha: ");
}

void taxes_cli(void) {
    fprintf(stderr, "\033[2J\033[H");
    fprintf(stderr, "Menu de Cálculo de Tarifas:\n");
    fprintf(stderr, "Digite 1 para calcular a tarifa de um trecho;\n");
    fprintf(stderr, "Digite 2 para calcular a tarifa do percurso completo;\n");
    fprintf(stderr, "Digite 0 para Voltar ao Menu Principal.\n");
    fprintf(stderr, "Escolha: ");
}

void manage_companies(void) {
    short choice;

    do {
        manage_companies_cli();
        scanf("%hd", &choice);
        getchar();

        switch (choice) {
            case 0:
                break;
            case 1:
                fprintf(stderr, "\033[2J\033[H");
                index_empresas();
                aguardar_tecla();
                break;
            case 2:
                fprintf(stderr, "\033[2J\033[H");
                show_empresa();
                aguardar_tecla();
                break;
            case 3:
                fprintf(stderr, "\033[2J\033[H");
                create_empresa();
                aguardar_tecla();
                break;
            case 4:
                fprintf(stderr, "\033[2J\033[H");
                update_empresa();
                aguardar_tecla();
                break;
            case 5:
                fprintf(stderr, "\033[2J\033[H");
                delete_empresa();
                aguardar_tecla();
                break;
            default:
                fprintf(stderr, "Opção inválida. Tente alguma conhecida.\n");
                break;
        }
    } while (choice != 0);
}

void manage_lines(void) {
    short choice;

    do {
        manage_lines_cli();
        scanf("%hd", &choice);
        getchar();

        switch (choice) {
            case 0:
                break;
            case 1:
                fprintf(stderr, "\033[2J\033[H");
                index_linhas();
                aguardar_tecla();
                break;
            case 2:
                fprintf(stderr, "\033[2J\033[H");
                show_paradas_by_linha_id();
                aguardar_tecla();
                break;
            case 3:
                fprintf(stderr, "\033[2J\033[H");
                show_horarios_by_linha_id();
                aguardar_tecla();
                break;
            case 4:
                fprintf(stderr, "\033[2J\033[H");
                show_linha_by_name();
                aguardar_tecla();
                break;
            case 5:
                fprintf(stderr, "\033[2J\033[H");
                show_linhas_by_company();
                aguardar_tecla();
                break;
            case 6:
                fprintf(stderr, "\033[2J\033[H");
                create_linha();
                aguardar_tecla();
                break;
            case 7:
                fprintf(stderr, "\033[2J\033[H");
                create_parada_for_linha();
                aguardar_tecla();
                break;
            case 8:
                fprintf(stderr, "\033[2J\033[H");
                create_horario_for_linha();
                aguardar_tecla();
                break;
            case 9:
                fprintf(stderr, "\033[2J\033[H");
                update_linha();
                aguardar_tecla();
                break;
            case 10:
                fprintf(stderr, "\033[2J\033[H");
                update_parada_from_linha();
                aguardar_tecla();
                break;
            case 11:
                fprintf(stderr, "\033[2J\033[H");
                delete_linha();
                aguardar_tecla();
                break;
            case 12:
                fprintf(stderr, "\033[2J\033[H");
                delete_parada_from_linha();
                aguardar_tecla();
                break;
            case 13:
                fprintf(stderr, "\033[2J\033[H");
                delete_horario_from_linha();
                aguardar_tecla();
                break;
            default:
                fprintf(stderr, "Opção inválida. Tente alguma conhecida.\n");
                break;
        }
    } while (choice != 0);
}

void manage_drivers(void) {
    short choice;

    do {
        manage_drivers_cli();
        scanf("%hd", &choice);
        getchar();

        switch (choice) {
            case 0:
                break;
            case 1:
                fprintf(stderr, "\033[2J\033[H");
                index_motoristas();
                aguardar_tecla();
                break;
            case 2:
                fprintf(stderr, "\033[2J\033[H");
                show_motorista_by_name();
                aguardar_tecla();
                break;
            case 3:
                fprintf(stderr, "\033[2J\033[H");
                show_motoristas_by_company();
                aguardar_tecla();
                break;
            case 4:
                fprintf(stderr, "\033[2J\033[H");
                create_motorista();
                aguardar_tecla();
                break;
            case 5:
                fprintf(stderr, "\033[2J\033[H");
                update_motorista();
                aguardar_tecla();
                break;
            case 6:
                fprintf(stderr, "\033[2J\033[H");
                delete_motorista();
                aguardar_tecla();
                break;
            default:
                fprintf(stderr, "Opção inválida. Tente alguma conhecida.\n");
                break;
        }
    } while (choice != 0);
}

void manage_buses(void) {
    short choice;

    do {
        manage_buses_cli();
        scanf("%hd", &choice);
        getchar();

        switch (choice) {
            case 0:
                break;
            case 1:
                fprintf(stderr, "\033[2J\033[H");
                index_onibus();
                aguardar_tecla();
                break;
            case 2:
                fprintf(stderr, "\033[2J\033[H");
                show_onibus_by_licence_plate();
                aguardar_tecla();
                break;
            case 3:
                fprintf(stderr, "\033[2J\033[H");
                show_onibus_by_driver();
                aguardar_tecla();
                break;
            case 4:
                fprintf(stderr, "\033[2J\033[H");
                create_onibus();
                aguardar_tecla();
                break;
            case 5:
                fprintf(stderr, "\033[2J\033[H");
                update_onibus();
                aguardar_tecla();
                break;
            case 6:
                fprintf(stderr, "\033[2J\033[H");
                delete_onibus();
                aguardar_tecla();
                break;
            default:
                fprintf(stderr, "Opção inválida. Tente alguma conhecida.\n");
                break;
        }
    } while (choice != 0);
}

void taxes(void) {
    short choice;

    do {
        taxes_cli();
        scanf("%hd", &choice);
        getchar();

        switch (choice) {
            case 0:
                break;
            case 1:
                fprintf(stderr, "\033[2J\033[H");
                get_route_tax();
                aguardar_tecla();
                break;
            case 2:
                fprintf(stderr, "\033[2J\033[H");
                get_all_route_tax();
                aguardar_tecla();
                break;
            default:
                fprintf(stderr, "Opção inválida. Tente alguma conhecida.\n");
                break;
        }
    } while (choice != 0);
}
