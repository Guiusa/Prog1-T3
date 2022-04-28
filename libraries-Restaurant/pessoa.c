#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"

pessoa_t* cria_fila_pessoas(){
    pessoa_t* p = malloc(1000*sizeof(pessoa_t));
    if(p==NULL)
        return NULL;
    return p;
}

void aleatoriza_fila(pessoa_t* p){
    int i;
    for(i=0; i<1000; i++){
        int probVacina = rand()%100;
        int probMascara = rand()%100;
        int probDinheiro = rand()%100;
        
        p[i].ticket = i+1;
        p[i].vacinado = probVacina<95 ?  1 : 0;
        p[i].mascara = probMascara<80 ?  1 : 0;
        p[i].money = probDinheiro<60 ?  1.3 : 3.8;
    }
    return;
}

void libera_pessoas(pessoa_t* p){
    free(p);
    return;
}

fila_t* fila_atendimento(){
    fila_t* f = fila_cria();
    int i;
    for(i=0; i<1000; i++){
        queue(f, i+1);
    }

    return f;
}

void destroi_fila_at(fila_t* f){
    fila_destroi(f);
    return;
}

lista_t* l_n_atendidos(){
    lista_t* l = lista_cria();
    return l;
}

void destroi_n_atendidos(lista_t* l){
    lista_destroi(l);
    return;
}

void imprime_fila_pessoas(pessoa_t* p){
    int i;
    for(i=0; i<1000; i++)
        printf("%d %d %d %f\n", p[i].ticket, p[i].vacinado, p[i].mascara, p[i].money);
    return;
}