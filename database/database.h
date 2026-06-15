#ifndef DATABASE_H
#define DATABASE_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "empresa.h"

extern Empresa *empresas;
extern unsigned int num_empresas;
extern size_t capacidade_empresas;
extern unsigned int proximo_id_empresa;

#include "motorista.h"

extern Motorista *motoristas;
extern unsigned int num_motoristas;
extern size_t capacidade_motoristas;
extern unsigned int proximo_id_motorista;

short db_init(void);
void db_clear(void);

#endif