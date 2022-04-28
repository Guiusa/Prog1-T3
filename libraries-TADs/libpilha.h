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

#ifndef _LIBpilha_t_H
#define _LIBpilha_t_H

typedef struct {
    int* elems;   
    int nelem;   
    int topo;     
} pilha_t;
pilha_t* pilha_cria (int nelem);
pilha_t* pilha_destroi (pilha_t* pilha);
int push (pilha_t* pilha, int elem);
int pop (pilha_t* pilha);
int pilha_topo (pilha_t* pilha);  
int pilha_vazia (pilha_t* pilha);
int pilha_tamanho (pilha_t* pilha);





/* 
 * Imprime a pilha, da base ate o topo, este por ultimo, sem espaco no final.
 * Quando a pilha estiver vazia, nao imprime nada, nem um \n.
 * Esta funcao eh somente para facilitar teus testes.
 * Normalmente ela nao existe nas implementacoes de um TAD pilha.
*/
void pilha_imprime (pilha_t* pilha);

#endif