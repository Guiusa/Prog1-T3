#include <stdio.h>
#include <stdlib.h>
#include "contabilidade.h"

dados_t* cria_dados(){
    dados_t* d = malloc(sizeof(dados_t));
    if(d==NULL)
        return NULL;

    /*inicializando todas as 4 listas*/    
    d->nAtend_total = lista_cria();    
    d->nAtend_mask = lista_cria();
    d->nAtend_vac = lista_cria();
    d->nAtend_ref = lista_cria();

    /*inicializando as variáveis de dinheiro*/
    d->refD = 0.0;
    d->maskD = 0.0;
    d->totalD = 0.0;

    return d;
}

int destroi_dados(dados_t* d){
    /* Libera as listas da struct dinheiro e libera a estruct depois*/
    lista_destroi(d->nAtend_total);
    lista_destroi(d->nAtend_mask);
    lista_destroi(d->nAtend_vac);
    lista_destroi(d->nAtend_ref);

    free(d);

    return 1;
}

pilha_t* cria_pilha_masks(){
    int i;

    /*numero de mascara aleatorio*/
    int nMask = rand()%100; 

    pilha_t* masks = pilha_cria(nMask);
    /*adicionando os pratos de trás pra frente (politica LIFO)*/
    for(i=nMask; i>0; i--)
        push(masks, i);
    
    return masks;
}

pilha_t* cria_pilha_refs(){
    int i;

    /*numero de refeições aleatorio*/
    int nRef = (rand()%500) + 500; 

    pilha_t* refs = pilha_cria(nRef);
    /*adicionando os pratos de trás pra frente (politica LIFO)*/
    for(i=nRef; i>0; i--)
        push(refs, i);

    return refs;
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
void imprime_caracteres(char k, int b){
    /*Essa função imprime 'CCCCCCCC     ' caso b seja 1 e '             ' caso seja diferente de 1*/
    int i;

    if(b){
        for(i=0; i<8; i++)
            printf("%c", k);
        printf("     ");
    }
    
    else{
        for(i=0; i<13; i++)
            printf(" ");
    }

    return;
}

void montar_graf(dados_t* d){
    /* ø é um caracter inválido no terminal, o que acaba gerando a impressão de um caracter visualmente mais interessante
    para o uso de preencher um gráfico*/
    char k = *"ø";
    
    /*Salvando o tamanho de cada lista em variáveis pra poder calcular as porcentagens com mais elegância*/
    double total = lista_tamanho(d->nAtend_total);
    double mask = (lista_tamanho(d->nAtend_mask)/total)*100;
    double vac = (lista_tamanho(d->nAtend_vac)/total)*100;
    double ref = (lista_tamanho(d->nAtend_ref)/total)*100;
    
    /*Esses dois operadores ternários acham o maior valor entre mask, vac e ref. Isso será importante nos cálculos*/
    double maior = (mask > vac) ? mask : vac;
    maior = (ref > maior) ? ref : maior;

    printf("\n\nGráfico de porcentagem entre os motivos:\n\n");
    while(maior>0){
        /*Esse laço itera do maior elemento até 0, sempre imprimindo "barras de nível" caso o valor atual esteja no escopo
        da porcentagem total de cada uma das listas*/
        imprime_caracteres(k, (maior<=mask));
        imprime_caracteres(k, (maior<=vac));
        imprime_caracteres(k, (maior<=ref));

        /*itera de 4 em 4 para que o gráfico não seja muito grande*/        
        maior-=4;
        printf("\n");
    }
    /*esse print imprime a legenda do gráfico*/
    printf("masc:%2.1f%%   vac:%2.1f%%    ref:%2.1f%%\n\n", mask, vac, ref);
}
#include "contabilidade.h"