#ifndef _Pessoa_t_H
#define _Pessoa_t_H
#include "../libraries-TADs/libfila.h"
#include "../libraries-TADs/liblista.h"

struct pessoa {
        int ticket;
        int vacinado;
        int mascara;
        double money;
};
typedef struct pessoa pessoa_t;

pessoa_t* cria_fila_pessoas();
void aleatoriza_fila(pessoa_t* p);
void libera_pessoas(pessoa_t* p);
fila_t* fila_atendimento();
void destroi_fila_at(fila_t* f);
void imprime_fila_pessoas(pessoa_t* p);

#endif