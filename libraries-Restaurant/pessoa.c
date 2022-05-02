#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"

pessoa_t* cria_fila_pessoas(){
    /*aloca 1000 espaços do tipo pessoa e disponibiliza como vetor*/
    pessoa_t* p = malloc(1000*sizeof(pessoa_t));
    if(p==NULL)
        return NULL;
    return p;
}

void aleatoriza_fila(pessoa_t* p){
    /*variável de contador e variáveis de probabilidade*/
    int i;
    int probVacina;
    int probMascara;
    int probDinheiro;

    for(i=0; i<1000; i++){
        /*gera alguma probabilidade aleatória entre 0 e 100*/
        probVacina = rand()%100;
        probMascara = rand()%100;
        probDinheiro = rand()%100;
        
        /*o ticket sempre recebe o contador+1, os ternários servem para distribuir os valores de
        acordo com as porcentagens: 95% para estar vacinado, 80% para estar de máscara e o
        dinheiro segue a especificação do enunciado*/

        p[i].ticket = i+1;
        p[i].vacinado = probVacina<95 ?  1 : 0;
        p[i].mascara = probMascara<80 ?  1 : 0;
        p[i].money = probDinheiro<60 ?  1.3 : 3.8;
    }
    return;
}

void libera_pessoas(pessoa_t* p){
    /*simplesmente libera os 1000 espaços para pessoas*/
    free(p);
    return;
}

fila_t* fila_atendimento(){
    /*essa função cria a fila de atendimento, onde a primeira pessoa tem o ticket 1 e a última o ticket 1000*/
    fila_t* f = fila_cria();
    int i;
    for(i=0; i<1000; i++){
        queue(f, i);
    }

    return f;
}

void destroi_fila_at(fila_t* f){
    /*destroi a fila de atendimento depois de usada*/
    fila_destroi(f);
    return;
}

void imprime_fila_pessoas(pessoa_t* p){
    /*essa função só foi usada para testar se a distribuição de probabilidades estava funcionando, ela não é aplicada
    na versão final do trabalho*/
    
    int i;
    for(i=0; i<1000; i++)
        printf("%d %d %d %f\n", p[i].ticket, p[i].vacinado, p[i].mascara, p[i].money);
    return;
}