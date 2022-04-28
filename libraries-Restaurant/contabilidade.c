#include <stdio.h>
#include <stdlib.h>
#include "contabilidade.h"

dados_t* cria_dados(){
    dados_t* d = malloc(sizeof(dados_t));
    if(d==NULL)
        return NULL;
    d->nAtend_mask = lista_cria();
    d->nAtend_vac = lista_cria();
    d->nAtend_ref = lista_cria();
    d->refD = 0;
    d->maskD = 0;
    d->totalD = 0;
    return d;
}

pilha_t* cria_pilha_masks(){
    int i;
    int nMask = rand()%100; /*numero de mascara aleatorio*/
    pilha_t* masks = pilha_cria(nMask);
    /*adicionando os pratos de trás pra frente (politica LIFO)*/
    for(i=nMask; i>0; i--)
        push(masks, i);
    
    return masks;
}

pilha_t* cria_pilha_refs(){
    int i;
    int nRef = (rand()%500) + 500; /*numero de refeições aleatorio*/
    pilha_t* refs = pilha_cria(nRef);
    /*adicionando os pratos de trás pra frente (politica LIFO)*/
    for(i=nRef; i>0; i--)
        push(refs, i);

    return refs;
}

int destroi_dados(dados_t* d){
    lista_destroi(d->nAtend_mask);
    lista_destroi(d->nAtend_vac);
    free(d);

    return 1;
}

void imprime_dados(dados_t* d){
    printf("O total de dinheiro hoje arrecadado é de R$%.2f\n", d->totalD);
    printf("Do total de R$%.2f, %.2f%% foi com a venda de máscaras, totalizando R$%.2f ou %.0f máscaras\n", d->totalD, (d->maskD/d->totalD)*100, d->maskD, d->maskD/2.5);
    printf("Do total de R$%.2f, %.2f%% foi com a venda de refeições, totalizando R$%.2f ou %.0f refeições\n", d->totalD, (d->refD/d->totalD)*100, d->refD, d->refD/1.3);
    printf("\n");
    printf("A quantia de pessoas que não pode comer por falta de vacinação é de %d pessoas\n", lista_tamanho(d->nAtend_vac));
    printf("Essas são as %d pessoas:\n", lista_tamanho(d->nAtend_vac));
    lista_imprime(d->nAtend_vac);
    printf("\n");
    printf("A quantia de pessoas que não pode comprar máscaras e, portanto, não comeu é de %d pessoas\n", lista_tamanho(d->nAtend_mask));
    printf("Essas são as %d pessoas:\n", lista_tamanho(d->nAtend_mask));
    lista_imprime(d->nAtend_mask);
    printf("\n");
    printf("A quantia de pessoas que não pode comer por falta de pratos é de %d pessoas\n", lista_tamanho(d->nAtend_ref));
    printf("Essas são as %d pessoas:\n", lista_tamanho(d->nAtend_ref));
    lista_imprime(d->nAtend_ref);
    printf("\n");
    printf("O total de pessoas que não comeram por quaisquer motivos foi de %d pessoas\n", lista_tamanho(d->nAtend_vac)+lista_tamanho(d->nAtend_mask)+lista_tamanho(d->nAtend_ref));
}

void montar_graf(dados_t* d){
    double total = lista_tamanho(d->nAtend_ref)+lista_tamanho(d->nAtend_vac)+lista_tamanho(d->nAtend_mask);
    double mask = (lista_tamanho(d->nAtend_mask)/total)*100;
    double vac = (lista_tamanho(d->nAtend_vac)/total)*100;
    double ref = (lista_tamanho(d->nAtend_ref)/total)*100;
    
    double maior = (mask > vac) ? mask : vac;
    maior = (ref > maior) ? ref : maior;
    printf("\n\nGráfico de porcentagem entre os motivos:\n\n");
    while(maior>0){
        if(maior<=mask){
            printf("########     ");
        }
        else{
            printf("             ");
        }
        
        if(maior<=vac){
            printf("########     ");
        }
        else{
            printf("             ");
        }
        
        if(maior<=ref){
            printf("########     ");
        }
        else{
            printf("             ");
        }
        maior-=4;
        printf("\n");
    }
    printf("masc:%2.1f%%   vac:%2.1f%%    ref:%2.1f%%\n\n", mask, vac, ref);
}
#include "contabilidade.h"