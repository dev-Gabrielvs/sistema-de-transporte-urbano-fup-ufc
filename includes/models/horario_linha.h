#ifndef HORARIO_LINHA_H
#define HORARIO_LINHA_H

typedef struct Horario_Linha {
    unsigned int id;
    unsigned short hora;
    unsigned short minuto;
    struct Horario_Linha *proximo;
} Horario_Linha;

#endif