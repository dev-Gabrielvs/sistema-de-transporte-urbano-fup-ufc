#ifndef ONIBUS_H
#define ONIBUS_H

typedef struct {
    unsigned int id;
    char placa[10];
    char modelo[20];
    unsigned short ano_fabricacao;
    unsigned short capacidade_passageiros;
    unsigned int id_linha;
    unsigned int id_motorista;
} Onibus;

Onibus* ListarOnibus(void);
Onibus AdicionarOnibus(const char *placa, const char *modelo, unsigned short ano_fabricacao, unsigned short capacidade_passageiros, unsigned int id_linha, unsigned int id_motorista);
Onibus EditarOnibus(unsigned int id, const char *nova_placa, const char *novo_modelo, unsigned short novo_ano_fabricacao, unsigned short nova_capacidade_passageiros, unsigned int nova_id_linha, unsigned int nova_id_motorista);
short RemoverOnibus(unsigned int id);
Onibus BuscarOnibusPorPlaca(const char *placa);
Onibus BuscarOnibusPorMotorista(const char *nome_motorista);

#endif