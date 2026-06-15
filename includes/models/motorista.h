#ifndef MOTORISTA_H
#define MOTORISTA_H

typedef struct {
    unsigned int id;
    char nome[50];
    unsigned short idade;
    char sexo;
    unsigned int id_empresa;
} Motorista;

typedef struct {
    Motorista *motoristas_empresa;
    unsigned int num_motoristas_empresa;
} MotoristasPorEmpresa;

Motorista* ListarMotoristas(void);
Motorista BuscarMotoristaPorNome(const char *nome);
MotoristasPorEmpresa BuscarMotoristasPorEmpresa(const char *nome_empresa);
Motorista AdicionarMotorista(const char *nome, unsigned short idade, char sexo, unsigned int id_empresa);
Motorista EditarMotorista(unsigned int id, const char *novo_nome, unsigned short nova_idade, char novo_sexo, unsigned int novo_id_empresa);
short RemoverMotorista(unsigned int id);

#endif 