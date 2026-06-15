#include "application_base.h"

Motorista* ListarMotoristas(void)
{
    return motoristas;
}

Motorista AdicionarMotorista(const char *nome, unsigned short idade, char sexo, unsigned int id_empresa)
{
    if (num_motoristas >= capacidade_motoristas)
    {
        capacidade_motoristas *= 2;
        Motorista *temp_aloc = realloc(motoristas, sizeof(Motorista) * capacidade_motoristas);

        if (temp_aloc == NULL)
        {
            fprintf(stderr, "Erro ao realocar memória para motoristas.\n");
            return (Motorista){0, "", 0, ' ', 0};
        }

        motoristas = temp_aloc;
    }

    Motorista novo_motorista;
    novo_motorista.id = proximo_id_motorista;
    strcpy(novo_motorista.nome, nome);
    novo_motorista.idade = idade;
    novo_motorista.sexo = sexo;
    novo_motorista.id_empresa = id_empresa;
    motoristas[num_motoristas] = novo_motorista;

    num_motoristas++;
    proximo_id_motorista++;
    return novo_motorista;
}

Motorista EditarMotorista(unsigned int id, const char *novo_nome, unsigned short nova_idade, char novo_sexo, unsigned int novo_id_empresa)
{
    for (unsigned int i = 0; i < num_motoristas; i++)
    {
        if (motoristas[i].id == id)
        {
            strcpy(motoristas[i].nome, novo_nome);
            motoristas[i].idade = nova_idade;
            motoristas[i].sexo = novo_sexo;
            motoristas[i].id_empresa = novo_id_empresa;
            return motoristas[i];
        }
    }
    return (Motorista){0, "", 0, ' ', 0};
}

short RemoverMotorista(unsigned int id)
{
    for (unsigned int i = 0; i < num_motoristas; i++)
    {
        if (motoristas[i].id == id)
        {
            for (unsigned int j = i; j < num_motoristas - 1; j++)
            {
                motoristas[j] = motoristas[j + 1];
            }
            num_motoristas--;
            return 1;
        }
    }
    return 0;
}

Motorista BuscarMotoristaPorNome(const char *nome)
{
    for (unsigned int i = 0; i < num_motoristas; i++)
    {
        if (strcmp(motoristas[i].nome, nome) == 0)
        {
            return motoristas[i];
        }
    }
    return (Motorista){0, "", 0, ' ', 0};
}

MotoristasPorEmpresa BuscarMotoristasPorEmpresa(const char *nome_empresa)
{
    unsigned int id_empresa = 0;
    for (unsigned int i = 0; i < num_empresas; i++)
    {
        if (strcmp(empresas[i].nome, nome_empresa) == 0){
            id_empresa = empresas[i].id;
            break;
        }
    }

    unsigned int num_motoristas_empresa = 0;

    for (unsigned int i = 0; i < num_motoristas; i++)
    {
        if (motoristas[i].id_empresa == id_empresa)
        {
            num_motoristas_empresa++;
        }
    }

    Motorista *motoristas_empresa = malloc(num_motoristas_empresa * sizeof(Motorista));
    if (!motoristas_empresa)
    {
        return (MotoristasPorEmpresa){ NULL, 0 };
    }

    unsigned int j = 0;
    for (unsigned int i = 0; i < num_motoristas; i++)
    {
        if (motoristas[i].id_empresa == id_empresa)
        {
            motoristas_empresa[j++] = motoristas[i];
        }
    }

    return (MotoristasPorEmpresa){ motoristas_empresa, num_motoristas_empresa };
}