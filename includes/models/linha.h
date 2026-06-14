#ifndef LINHA_H
#define LINHA_H

#include "parada.h"
#include "horario_linha.h"

typedef struct {
    unsigned int id;
    char nome[50];
    unsigned int id_empresa;
    Parada *paradas;
    Horario_Linha *horarios;
} Linha;

#endif