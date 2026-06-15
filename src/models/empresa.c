#include "application_base.h"

Empresa* ListarEmpresas(void)
{
    return empresas;
}

Empresa AdicionarEmpresa(const char *nome)
{
    if (num_empresas >= capacidade_empresas)
    {
        capacidade_empresas *= 2;
        Empresa *temp_aloc = realloc(empresas, sizeof(Empresa) * capacidade_empresas);

        if (temp_aloc == NULL)
        {
            fprintf(stderr, "Erro ao realocar memória para empresas.\n");
            return (Empresa){0, ""};
        }

        empresas = temp_aloc;
    }

    Empresa nova_empresa;
    nova_empresa.id = proximo_id_empresa;
    strcpy(nova_empresa.nome, nome);
    empresas[num_empresas] = nova_empresa;

    num_empresas++;
    proximo_id_empresa++;
    return nova_empresa;
}

Empresa EditarEmpresa(unsigned int id, const char *novo_nome)
{
    for (unsigned int i = 0; i < num_empresas; i++)
    {
        if (empresas[i].id == id)
        {
            strcpy(empresas[i].nome, novo_nome);
            return empresas[i];
        }
    }
    return (Empresa){0, ""};
}

short RemoverEmpresa(unsigned int id)
{
    for (unsigned int i = 0; i < num_empresas; i++)
    {
        if (empresas[i].id == id)
        {
            for (unsigned int j = i; j < num_empresas - 1; j++)
            {
                empresas[j] = empresas[j + 1];
            }
            num_empresas--;

            return 1;
        }
    }
    return 0;
}

Empresa BuscarEmpresaPorNome(const char *nome)
{
    for (unsigned int i = 0; i < num_empresas; i++)
    {
        if (strcmp(empresas[i].nome, nome) == 0)
        {
            return empresas[i];
        }
    }

    return (Empresa){0, ""};
}