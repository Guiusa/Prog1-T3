#ifndef _Contabilidade_t_H
#define _Contabilidade_t_H
#include "../libraries-TADs/liblista.h"
#include "../libraries-TADs/libpilha.h"

struct dados {
    double totalD;
    double refD;
    double maskD;
    lista_t* nAtend_vac;
    lista_t* nAtend_mask;
    lista_t* nAtend_ref;
};
typedef struct dados dados_t;

dados_t* cria_dados();
int destroi_dados(dados_t* d);
void imprime_dados(dados_t* d);
void montar_graf(dados_t* d);
pilha_t* cria_pilha_masks();
pilha_t* cria_pilha_refs();

#endif