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

typedef struct {
    Linha *linhas_empresa;
    unsigned int num_linhas_empresa;
} LinhasPorEmpresa;

Linha* ListarLinhas(void);
Linha BuscarLinhaPorNome(const char *nome);
LinhasPorEmpresa BuscarLinhasPorEmpresa(const char *nome_empresa);
short RemoverLinha(unsigned int id);

#endif