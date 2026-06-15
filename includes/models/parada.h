#ifndef PARADA_H
#define PARADA_H

typedef struct Parada {
    unsigned int id;
    char nome[50];
    float distancia_km;
    struct Parada *proxima;
} Parada;

Parada* ListarParadasDaLinha(unsigned int linha_id);
Parada AdicionarParadaALinha(unsigned int linha_id, const char* nome_parada, float distancia_km);
Parada EditarParadaDaLinha(unsigned int linha_id, unsigned int parada_id, const char* novo_nome);
short RemoverParadaDaLinha(unsigned int linha_id, unsigned int parada_id);

#endif