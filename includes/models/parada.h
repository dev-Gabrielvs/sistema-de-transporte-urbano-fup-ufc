#ifndef PARADA_H
#define PARADA_H

typedef struct Parada {
    unsigned int id;
    char nome[50];
    float distancia_km;
    struct Parada *proxima;
} Parada;

#endif