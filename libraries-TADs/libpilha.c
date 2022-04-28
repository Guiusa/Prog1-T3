 #include "libpilha.h"
#include <stdlib.h>
#include <stdio.h>

pilha_t* pilha_cria(int nelem){
    /*alocando a pilha e returnando nulo em caso de erro*/
    pilha_t *pile=malloc(sizeof(pilha_t));
    if(pile==NULL)
        return NULL;
    
    /*atribuindo os valores iniciais pra pilha, alocando o vetor*/
    pile->topo = 0;
    pile->nelem = nelem;
    pile->elems = malloc(nelem * sizeof(int));
    
    return pile;
}

pilha_t* pilha_destroi(pilha_t* pilha){
    /*devolve o espaço do vetor e depois da própria estruct pilha*/
    free(pilha->elems);
    free(pilha);
    return NULL;
}

int push(pilha_t* pilha, int elem){
    /*tratando caso de pilha cheia*/
    if(pilha->topo == pilha->nelem)
        return -1;

    pilha->elems[pilha->topo] = elem;
    pilha->topo++;
    return pilha->topo; 
}

int pop(pilha_t* pilha){
    /*tratando caso de pilha vazia*/
    if(pilha_vazia(pilha))
        return 0;

    pilha->topo--;
    return pilha->elems[pilha->topo];
}
int pilha_topo(pilha_t* pilha){
    if(pilha_vazia(pilha))
        return 0;
    return pilha->elems[pilha->topo-1];
}

int pilha_vazia(pilha_t* pilha){
    if(pilha->topo == 0)
        return 1;
    return 0;
}

int pilha_tamanho(pilha_t* pilha){
    return pilha->topo;
}

void pilha_imprime (pilha_t* pilha){
    if(pilha_vazia(pilha))
        return;
    int i;
    for(i=0; i<pilha->topo; i++){
        printf("%d", pilha->elems[i]);
        if(i<pilha->topo-1)
            printf(" ");
    }
    printf("\n");
}
