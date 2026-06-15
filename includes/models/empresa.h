#ifndef EMPRESA_H
#define EMPRESA_H

typedef struct {
    unsigned int id;
    char nome[50];
} Empresa;

Empresa* ListarEmpresas(void);
Empresa BuscarEmpresaPorNome(const char *nome);
Empresa AdicionarEmpresa(const char *nome);
Empresa EditarEmpresa(unsigned int id, const char *novo_nome);
short RemoverEmpresa(unsigned int id);

#endif