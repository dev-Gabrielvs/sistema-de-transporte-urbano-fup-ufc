#include "application_base.h"

Linha* ListarLinhas(void)
{
    return linhas;
}

short RemoverLinha(unsigned int id)
{
    for (unsigned int i = 0; i < num_linhas; i++)
    {
        if (linhas[i].id == id)
        {
            for (unsigned int j = i; j < num_linhas - 1; j++)
            {
                linhas[j] = linhas[j + 1];
            }
            num_linhas--;

            return 1;
        }
    }
    return 0;
}

Linha BuscarLinhaPorNome (const char *nome)
{
    for (unsigned int i = 0; i < num_linhas; i++)
    {
        if (strcmp(linhas[i].nome, nome) == 0)
        {
            return linhas[i];
        }
    }
    return (Linha){0, "", 0, NULL, NULL};
}

LinhasPorEmpresa BuscarLinhasPorEmpresa(const char *nome_empresa){
    unsigned int id_empresa = 0;
    for (unsigned int i = 0; i < num_empresas; i++)
    {
        if (strcmp(empresas[i].nome, nome_empresa) == 0){
            id_empresa = empresas[i].id;
            break;
        }
    }

    unsigned int num_linhas_empresa = 0;

    for (unsigned int i = 0; i < num_linhas; i++)
    {
        if (linhas[i].id_empresa == id_empresa)
        {
            num_linhas_empresa++;
        }
    }

    Linha *linhas_empresa = malloc(num_linhas_empresa * sizeof(Linha));
    if (!linhas_empresa)
    {
        return (LinhasPorEmpresa){ NULL, 0 };
    }

    unsigned int index = 0;
    for (unsigned int i = 0; i < num_linhas; i++)
    {
        if (linhas[i].id_empresa == id_empresa)
        {
            linhas_empresa[index++] = linhas[i];
        }
    }

    return (LinhasPorEmpresa){ linhas_empresa, num_linhas_empresa };
}
