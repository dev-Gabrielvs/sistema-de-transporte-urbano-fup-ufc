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

#endif