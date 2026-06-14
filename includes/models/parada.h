#ifndef PARADA_H
#define PARADA_H

typedef struct {
    unsigned int id;
    char nome[50];
    float distancia_km;
    Parada *proxima;
} Parada;

#endif