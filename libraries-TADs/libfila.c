#include "libfila.h"
#include <stdlib.h>
#include <stdio.h>

fila_t* fila_cria(){
    /*inicializando a fila e apontando os ponteiros ini e fim pra nulo*/
    fila_t* fila = malloc(sizeof(fila_t));
    if(fila==NULL)
        return NULL;
    
    fila->tamanho = 0;
    fila->ini = NULL;
    fila->fim = NULL;

    return fila;
}

fila_t* fila_destroi (fila_t* f){
    nodo_f_t* p;

    /*Liberando espaço em caso de fila vazia*/
    if(fila_vazia(f)){ 
        free(f);
        return NULL;
    }
    
    p = f->ini->prox;
    while(p!=NULL){
        free(f->ini);
        f->ini = p;
        p = p->prox;
    }
    /*liberando o último nodo e o espaço da fila em si*/
    free(f->ini);
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
    nodo_f_t* aux;
    /*tratando caso de fila já vazia*/
    if(fila_vazia(f))
        return 0;
    
    /*retirando, alocando no parâmetro elemento e devolvendo espaço do nodo*/
    if(fila_tamanho(f) == 1){
        *elemento = f->ini->chave;
        free(f->fim);
        f->tamanho--;
        return 1;
    }

    aux = f->ini;
    *elemento = f->ini->chave;
    f->ini = f->ini->prox;
    f->tamanho--;
    free(aux);
    return 1;
}

void fila_imprime (fila_t* f){
    nodo_f_t* p;
    if(fila_vazia(f))
        return;
    
    p = f->ini;
    while(p != NULL){
        printf("%d ", p->chave);
        p = p->prox;
    }
    printf("\n");

    /*liberando espaço p*/
    free(p);
    return;
}