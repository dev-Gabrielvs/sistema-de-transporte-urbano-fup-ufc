#include "application_base.h"

Linha* ListarLinhas(void)
{
    return linhas;
}

Linha AdicionarLinha(const char *nome, unsigned int id_empresa){
    if (num_linhas >= capacidade_linhas)
    {
        capacidade_linhas *= 2;
        Linha *temp_aloc = realloc(linhas, sizeof(Linha) * capacidade_linhas);

        if (temp_aloc == NULL)
        {
            fprintf(stderr, "Erro ao realocar memória para linhas.\n");
            return (Linha){0, "", 0, NULL, NULL};
        }

        linhas = temp_aloc;
    }

    Linha nova_linha;
    nova_linha.id = proximo_id_linha;
    strcpy(nova_linha.nome, nome);
    nova_linha.id_empresa = id_empresa;
    nova_linha.paradas = NULL;
    nova_linha.horarios = NULL;
    linhas[num_linhas] = nova_linha;

    num_linhas++;
    proximo_id_linha++;
    return nova_linha;
}

Linha EditarLinha(unsigned int id, const char *novo_nome)
{
    for (unsigned int i = 0; i < num_linhas; i++)
    {
        if (linhas[i].id == id)
        {
            strcpy(linhas[i].nome, novo_nome);
            return linhas[i];
        }
    }
    return (Linha){0, "", 0, NULL, NULL};
}

short RemoverLinha(unsigned int id)
{
    for (unsigned int i = 0; i < num_linhas; i++)
    {
        if (linhas[i].id == id)
        {
            while (linhas[i].paradas != NULL)
            {
                Parada *temp_parada = linhas[i].paradas;
                linhas[i].paradas = linhas[i].paradas->proxima;
                free(temp_parada);
            }

            while (linhas[i].horarios != NULL)
            {
                Horario_Linha *temp_horario = linhas[i].horarios;
                linhas[i].horarios = linhas[i].horarios->proximo;
                free(temp_horario);
            }

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
