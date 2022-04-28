#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "libraries-TADs/libfila.h"
#include "libraries-TADs/liblista.h"
#include "libraries-TADs/libpilha.h"
#include "libraries-Restaurant/pessoa.h"
#include "libraries-Restaurant/contabilidade.h"

int fiscal(fila_t* atendimento, pessoa_t* p, pilha_t* masks, pilha_t* food, lista_t* n_atendidos, dados_t* d){
    int dequeued;
    dequeue(atendimento, &dequeued); /*pessoa do início*/

    /*caso tenha acabado a comida*/
    if(pilha_vazia(food)){
        lista_insere_ordenado(n_atendidos, p[dequeued].ticket);
        lista_insere_ordenado(d->nAtend_ref, p[dequeued].ticket);
        return 0;
    }
    /*caso não esteja vacinado*/
    else if(!p[dequeued].vacinado){
        lista_insere_ordenado(n_atendidos, p[dequeued].ticket);
        lista_insere_ordenado(d->nAtend_vac, p[dequeued].ticket);
        return 0;
    }
    else{
        /*caso não esteja de máscara*/
        if(!p[dequeued].mascara){
            /*caso tenha acabado as máscaras ou não haja dinheiro pra comprar uma*/
            if(pilha_vazia(masks) || p[dequeued].money < 3.8){
                lista_insere_ordenado(n_atendidos, p[dequeued].ticket);
                lista_insere_ordenado(d->nAtend_mask, p[dequeued].ticket);
                return 0;
            }
            /*comprou a máscara e foi pro fim da fila*/
            else{
                p[dequeued].money -= 2.5;
                p[dequeued].mascara = 1;
                d->totalD += 2.5;
                d->maskD += 2.5;
                pop(masks);
                queue(atendimento, dequeued);
                return 0;
            }
        }
        /*caso em que tudo deu certo, pagou o dinheiro e ganhou o prato*/
        p[dequeued].money -= 1.3;
        d->totalD += 1.3;
        d->refD += 1.3;
        pop(food);
    }
    return 1;
}

int main(){
    srand(time(0));

    /*Gerando a fila com pessoas aleatorizadas*/
    pessoa_t* populacao = cria_fila_pessoas();
    aleatoriza_fila(populacao);

    /*Gerando as pilhas de máscara e refeição*/
    pilha_t* masks = cria_pilha_masks();
    pilha_t* food = cria_pilha_refs();
    
    /*inicializando a fila de atendimento e atribuindo a ordem, criando a lista de não atendidos*/
    fila_t* atendimento = fila_atendimento();
    lista_t* n_atendidos = l_n_atendidos();

    /*inicializando a estrutura de contabilidade*/
    dados_t* dados_fim = cria_dados();

    /*-------------------------------------------------------------------------------------------*/

    /*passando todas as pessoas pelo fiscal, depois imprimindo os resultados*/
    while(!fila_vazia(atendimento))
        fiscal(atendimento, populacao, masks, food, n_atendidos, dados_fim);
    imprime_dados(dados_fim);
    montar_graf(dados_fim);
    /*-------------------------------------------------------------------------------------------*/

    /*destruindo as estruturas usadas*/
    destroi_dados(dados_fim);
    destroi_n_atendidos(n_atendidos);
    destroi_fila_at(atendimento);
    libera_pessoas(populacao);
    pilha_destroi(masks);
    pilha_destroi(food);
    return 0;
}