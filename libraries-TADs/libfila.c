#include "libfila.h"
#include <stdlib.h>
#include <stdio.h>

fila_t* fila_cria(){
    fila_t* fila = malloc(sizeof(fila_t));
    fila->tamanho = 0;
    if(fila==NULL)
        return NULL;
    
    return fila;
}

fila_t* fila_destroi (fila_t* f){
    nodo_f_t* nodo1 = f->ini;
    if(nodo1 == NULL){ /*Liberando espaço em caso de fila vazia*/
        free(f);
        return NULL;
    }
    
    nodo_f_t* nodo2 = f->ini->prox; /*liberando espaço nodo a nodo*/
    while(nodo2!=NULL){
        free(nodo1);
        nodo1 = nodo2;
        nodo2 = nodo2->prox;
    }
    /*liberando o último nodo e o espaço da fila em si*/
    free(nodo1);
    free(f);
    return NULL;
}

int fila_vazia (fila_t* f){
    if(f->tamanho==0)
        return 1;
    return 0;
}

int fila_tamanho (fila_t* f){
    return f->tamanho;
}

int queue (fila_t* f, int elemento){
    /*Cria nodo pra inserir e retorna 0 em caso de erro*/
    nodo_f_t* nodo = malloc(sizeof(nodo_f_t));
    if(nodo==NULL)
        return 0;

    nodo->chave = elemento;
    nodo->prox = NULL;
    /*tratar caso de fila vazia*/
    if(fila_vazia(f))
        f->ini = nodo;
    /*inserção*/
    if(!fila_vazia(f))
        f->fim->prox = nodo;
    f->fim = nodo;
    f->tamanho++;
    return 1;
}

int dequeue (fila_t* f, int* elemento){
    /*tratando caso de fila já vazia*/
    if(fila_vazia(f))
        return 0;
    /*retirando, alocando no parâmetro elemento e devolvendo espaço do nodo*/
    *elemento = f->ini->chave;
    f->ini = f->ini->prox;
    f->tamanho--;
    return 1;
}

void fila_imprime (fila_t* f){
    if(fila_vazia(f))
        return;
    nodo_f_t* p = f->ini;
    while(p->prox != NULL){
        printf("%d ", p->chave);
        p = p->prox;
    }
    /*liberando espaço p*/
    free(p);
    printf("%d\n", p->chave);
    return;
}