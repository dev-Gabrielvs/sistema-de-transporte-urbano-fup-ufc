#ifndef HORARIO_LINHA_H
#define HORARIO_LINHA_H

typedef struct Horario_Linha {
    unsigned int id;
    unsigned short hora;
    unsigned short minuto;
    struct Horario_Linha *proximo;
} Horario_Linha;

Horario_Linha *ListarHorariosDaLinha(unsigned int linha_id);
Horario_Linha AdicionarHorarioALinha(unsigned int linha_id, unsigned short hora, unsigned short minuto);
short RemoverHorarioDaLinha(unsigned int linha_id, unsigned int horario_id);

#endif