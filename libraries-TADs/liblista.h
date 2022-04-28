/*
 * TAD pilha
 * Autores:
 *    André Ricardo Abed Gregio
 *    Marcos Alexandre Castilho
 *    Luis Carlos Erpen de Bona
 *    Luiz Carlos Pessoa Albini
 *
 * Versao 1.0.0 de 04/04/2022
*/

#ifndef _LIBlista_t_H
#define _LIBlista_t_H

struct nodo_l {
    int elemento;       /* lista de numeros inteiros */
    struct nodo_l* prox;  /* ponteiro para o proximo   */
};
typedef struct nodo_l nodo_l_t;

struct lista {
    nodo_l_t* ini;      /* ponteiro para o inicio da lista */
    int tamanho;        /* numero de elementos na lista    */
};
typedef struct lista lista_t;

lista_t* lista_cria ();
lista_t* lista_destroi (lista_t* l);
int lista_vazia (lista_t* l);
int lista_tamanho (lista_t* l);
int lista_insere_inicio (lista_t* l, int elemento);
int lista_insere_fim (lista_t* l, int elemento);
int lista_insere_ordenado (lista_t* l, int elemento);
int lista_retira_inicio (lista_t* l, int* elemento);
int lista_retira_fim (lista_t* l, int* elemento);
int lista_retira_elemento (lista_t *l, int *elemento);
int lista_pertence (lista_t* l, int elemento);
void lista_imprime (lista_t* l);

#endif