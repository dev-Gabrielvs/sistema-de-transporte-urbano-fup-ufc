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

short db_init(void);
void db_clear(void);

#endif