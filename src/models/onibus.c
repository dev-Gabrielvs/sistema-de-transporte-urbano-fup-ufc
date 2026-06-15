#include "application_base.h"

Onibus* ListarOnibus(void)
{
    return onibus;
}

Onibus AdicionarOnibus(const char *placa, const char *modelo, unsigned short ano_fabricacao, unsigned short capacidade_passageiros, unsigned int id_linha, unsigned int id_motorista)
{
    if (num_onibus >= capacidade_onibus)
    {
        capacidade_onibus *= 2;
        Onibus *temp_aloc = realloc(onibus, sizeof(Onibus) * capacidade_onibus);

        if (temp_aloc == NULL)
        {
            fprintf(stderr, "Erro ao realocar memória para ônibus.\n");
            return (Onibus){0, "", "", 0, 0, 0, 0};
        }

        onibus = temp_aloc;
    }

    Onibus novo_onibus;
    novo_onibus.id = proximo_id_onibus;
    strcpy(novo_onibus.placa, placa);
    strcpy(novo_onibus.modelo, modelo);
    novo_onibus.ano_fabricacao = ano_fabricacao;
    novo_onibus.capacidade_passageiros = capacidade_passageiros;
    novo_onibus.id_linha = id_linha;
    novo_onibus.id_motorista = id_motorista;

    onibus[num_onibus] = novo_onibus;

    num_onibus++;
    proximo_id_onibus++;
    return novo_onibus;
}

Onibus EditarOnibus(unsigned int id, const char *nova_placa, const char *novo_modelo, unsigned short novo_ano_fabricacao, unsigned short nova_capacidade_passageiros, unsigned int nova_id_linha, unsigned int nova_id_motorista)
{
    for (unsigned int i = 0; i < num_onibus; i++)
    {
        if (onibus[i].id == id)
        {
            strcpy(onibus[i].placa, nova_placa);
            strcpy(onibus[i].modelo, novo_modelo);
            onibus[i].ano_fabricacao = novo_ano_fabricacao;
            onibus[i].capacidade_passageiros = nova_capacidade_passageiros;
            onibus[i].id_linha = nova_id_linha;
            onibus[i].id_motorista = nova_id_motorista;
            return onibus[i];
        }
    }
    return (Onibus){0, "", "", 0, 0, 0, 0};
}

short RemoverOnibus(unsigned int id)
{
    for (unsigned int i = 0; i < num_onibus; i++)
    {
        if (onibus[i].id == id)
        {
            for (unsigned int j = i; j < num_onibus - 1; j++)
            {
                onibus[j] = onibus[j + 1];
            }
            num_onibus--;

            return 1;
        }
    }
    return 0;
}

Onibus BuscarOnibusPorPlaca(const char *placa)
{
    for (unsigned int i = 0; i < num_onibus; i++)
    {
        if (strcmp(onibus[i].placa, placa) == 0)
        {
            return onibus[i];
        }
    }
    return (Onibus){0, "", "", 0, 0, 0, 0};
}

Onibus BuscarOnibusPorMotorista(const char *nome_motorista)
{
    unsigned int id_motorista = 0;
    for (unsigned int i = 0; i < num_motoristas; i++)
    {
        if (strcmp(motoristas[i].nome, nome_motorista) == 0)
        {
            id_motorista = motoristas[i].id;
            break;
        }
    }

    if (id_motorista == 0)
    {
        return (Onibus){0, "", "", 0, 0, 0, 0};
    }

    for (unsigned int i = 0; i < num_onibus; i++)
    {
        if (onibus[i].id_motorista == id_motorista)
        {
            return onibus[i];
        }
    }
    
    return (Onibus){0, "", "", 0, 0, 0, 0};
}