#include "liblista.h"
#include <stdlib.h>
#include <stdio.h>

lista_t* lista_cria (){
    /*alocando espaço e retornando nulo pra caso de erro*/
    lista_t* l = malloc(sizeof(lista_t));
    
    if(l==NULL)
        return NULL;

    l->ini = NULL;
    l->tamanho = 0;
    return l;
}

lista_t* lista_destroi (lista_t* l){
    nodo_l_t* aux1;
    nodo_l_t* aux2;
    
    /*Liberando espaço em caso de lista vazia*/
    aux1 = l->ini;
    if(aux1 == NULL){ 
        free(l);
        return NULL;
    }
    /*nodo2 e nodo1 vão iterando e liberando espaço pra cada nodo da lista*/
    aux2 = l->ini->prox;
    while(aux2!=NULL){
        free(aux1);
        aux1 = aux2;
        aux2 = aux2->prox;
    }

    /*liberar espaço para nodo1 e lista*/
    free(aux1);
    free(l);

    return NULL;
}

int lista_vazia (lista_t* l){
    if(l->tamanho == 0)
        return 1;
    return 0;
}

int lista_tamanho (lista_t* l){
    return l->tamanho;
}

int lista_insere_inicio (lista_t* l, int elemento){
    /*criando o nodo e retornando em caso de erro*/
    nodo_l_t* nodo = malloc(sizeof(nodo_l_t));
    if(nodo==NULL)
        return 0;

    /*configurando o nodo para inseri-lo no inicio*/    
    nodo->prox = l->ini;
    nodo->elemento = elemento;
    l->ini = nodo;
    l->tamanho++;
    return 1;
}

int lista_insere_fim (lista_t* l, int elemento){
    /*criando nodo em retornando em caso de erro*/
    nodo_l_t* nodo = malloc(sizeof(nodo_l_t));
    nodo_l_t* nodoAux;

    if(nodo==NULL)
        return 0;

    nodo->prox = NULL;
    nodo->elemento = elemento;
    /*se a lista estiver vazia, insere no inicio*/
    if(lista_vazia(l)){
        l->ini = nodo;
        l->tamanho++;
        return 1;
    }

    /*procurando o fim da lista com nodoAux, inserindo quandio achar*/
    nodoAux = l->ini;
    while(nodoAux->prox!=NULL){
        nodoAux = nodoAux->prox;
    } 
    nodoAux->prox = nodo;
    l->tamanho++;
    return 1;
}

int lista_insere_ordenado (lista_t* l, int elemento){
    /*criando nodo em retornando em caso de erro*/
    nodo_l_t* nodo = malloc(sizeof(nodo_l_t));
    nodo_l_t* nodoAux;

    if(nodo==NULL)
        return 0;
    
    nodo->elemento = elemento;
    nodo->prox = NULL;
    
    /*em caso de lista vazia, insere no início*/
    if(lista_vazia(l)){
        lista_insere_inicio(l, elemento);
        free(nodo);
        return 1;
    }

    nodoAux = l->ini;
    /*tratando o caso do primeiro elemento já ser maior que o elemento*/
    if(nodoAux->elemento >= elemento){
        lista_insere_inicio(l, elemento);
        free(nodo);
        return 1;
    }

    while(nodoAux->prox!=NULL){ 
        /*se achar o fim da lista, insere*/
        if(nodoAux->prox->elemento > elemento){
            break;
        }
        nodoAux = nodoAux->prox;
    }
    if(nodoAux->prox==NULL){
        free(nodo);
        lista_insere_fim(l, elemento);
        return 1;
    }
    /*insere o nodo na posição*/
    nodo->prox = nodoAux->prox;
    nodoAux->prox = nodo;
    l->tamanho++;
    return 1;
}

int lista_retira_inicio (lista_t* l, int* elemento){
    nodo_l_t* aux;
    /*Se a lista estiver vazia, retorna sem tirar elemento*/
    if(lista_vazia(l)) 
        return 0;
    
    /*retira o inicio da fila e retorna o valor na variável elemento*/
    aux = l->ini;
    *elemento = l->ini->elemento;
    l->ini = l->ini->prox;
    l->tamanho--;
    free(aux);
    return 1;
}

int lista_retira_fim (lista_t* l, int* elemento){
    nodo_l_t* aux;
    nodo_l_t* liberarAux;
    /*Se a lista estiver vazia, retorna sem tirar elemento*/
    if(lista_vazia(l))
        return 0;

    /*Se a lista tiver tamanho 1, chama a funcao retira inicio*/
    if(lista_tamanho(l) == 1){
        *elemento = l->ini->elemento;
        lista_retira_inicio(l, elemento);
        return 1;
    }
    else{
        /*cria nodo pra iterar de nodo em nodo*/
        aux = l->ini;
        while(aux->prox->prox != NULL){
            aux = aux->prox;
        }
        /*retira e retorna*/
        liberarAux = aux->prox; 
        *elemento = aux->prox->elemento;
        aux->prox = NULL;
        free(liberarAux);
        l->tamanho--;
    }
    return 1;
}

int lista_retira_elemento (lista_t *l, int *elemento){
    nodo_l_t* aux;
    nodo_l_t* liberarAux;

    /*Se a lista estiver vazia, retorna sem tirar elemento*/
    if(lista_vazia(l))
        return 0;

    /*trata o caso de a lista ter 1 elemento*/
    if(lista_tamanho(l) == 1){
        if(l->ini->elemento == *elemento){
            /*Se o primeiro elemento for igual ao recebido, chama a funcao retira inicio*/
            free(l->ini);
            l->ini = NULL;
            l->tamanho--;
            return 1;
        }
        else
            return 0;
    }
    /*a partir de vários elementos*/
    else{ 
        /*No caso do primeiro elemento ser o certo*/
        if(l->ini->elemento == *elemento){
            liberarAux = l->ini;
            l->ini = l->ini->prox;
            l->tamanho--;
            free(liberarAux);
            return 1;
        }

        /*cria nodo pra iteração, ele semrpe olha dois nodos a frente para achar o fim*/
        aux = l->ini;
        while(aux->prox->prox != NULL){
            if(aux->prox->elemento == *elemento){
                liberarAux = aux->prox;
                aux->prox = aux->prox->prox;
                l->tamanho--;
                free(liberarAux);
                return 1;
            }
            aux = aux->prox;
        }
        if(aux->prox->elemento == *elemento){
                liberarAux = aux->prox; 
                aux->prox = NULL;
                l->tamanho--;
                free(liberarAux);
                return 1;
        }
    }
    return 0;
}

int lista_pertence (lista_t* l, int elemento){
    nodo_l_t* aux;
    
    /*Essa função funciona igual ao lista_retira_elemento, apenas não retira*/
    if(lista_vazia(l))
        return 0;

    aux = l->ini;

    while(aux->prox != NULL){
        if(aux->elemento == elemento)
            return 1;
        aux = aux->prox;
    }
    
    if(aux->elemento == elemento)
        return 1;
    return 0;
}

void lista_imprime (lista_t* l){
    nodo_l_t* n;
    if(lista_vazia(l))
            return;
    
    n = l->ini;
    while(n->prox != NULL){
        printf("%d ", n->elemento);
        n = n->prox;
    }
    printf("%d\n", n->elemento);
    return; 
}