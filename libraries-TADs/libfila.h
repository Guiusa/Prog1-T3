/*
 * TAD fila
 * Autores:
 *    André Ricardo Abed Gregio
 *    Marcos Alexandre Castilho
 *    Luis Carlos Erpen de Bona
 *    Luiz Carlos Pessoa Albini
 *
 * Versao 1.0.0 de 04/04/2022
*/

#ifndef _LIBfila_t_H
#define _LIBfila_t_H
struct nodo_f {
    int chave;    
    struct nodo_f *prox; 
};
typedef struct nodo_f nodo_f_t;
struct fila {
    nodo_f_t* ini;
    nodo_f_t* fim; 
    int tamanho;     
};
typedef struct fila fila_t;
fila_t* fila_cria ();
fila_t* fila_destroi (fila_t* f);
int fila_vazia (fila_t* f);
int fila_tamanho (fila_t* f);
int queue (fila_t* f, int elemento);
int dequeue (fila_t* f, int* elemento);

/*
 * Imprime a fila, do inicio ate o fim, este por ultimo, sem espaco no final.
 * Quando a fila estiver vazia, nao imprime nada, nem um \n.
 * Esta funcao eh somente para facilitar teus testes.
 * Normalmente ela nao existe nas implementacoes de um TAD fila.
*/
void fila_imprime (fila_t* f);

#endif