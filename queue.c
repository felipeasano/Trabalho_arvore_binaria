#ifndef QUEUE_C
#define QUEUE_C

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

// verifica se a fila esta vazia
// pre-condicao: nenhuma
// pos-condicao: nenhuma
// Entrada: ponteiro para fila
// Retorno: retorna 1 caso a fila esteja vazia, 0 caso contrario
int vazia(FILA* f){
    return (f->inicio == NULL);
}

// cria uma fila vazia
// pre-condicao: nenhuma
// pos-condicao: fila criada
// Entrada: nenhum
// Retorno: ponteiro para uma fila vazia
FILA* inicializa_fila(){
    FILA* f = (FILA*) malloc(sizeof(FILA));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

// insere um elemento no final da fila
// pre-condicao: nenhuma
// pos-condicao: elemento eh inserido no final da fila
// Entrada: ponteiro para fila, cod do elemento a ser inserido
// Retorno: nenhum
void enqueue(FILA* f, int cod){
    NO_FILA* novo = (NO_FILA*) malloc(sizeof(NO_FILA)); 
    novo->cod = cod;
    novo->prox = NULL;
    if(vazia(f)){
        f->inicio = novo;
        f->fim = novo;
    }else{
        f->fim->prox = novo;
        f->fim = novo;
    }
}

// remove o primeiro elemento da fila
// pre-condicao: nenhum
// pos-condicao: primeiro elemento da fila eh removido
// Entrada: ponteiro para fila
// Retorno: nenhum
void dequeue(FILA* f){
    NO_FILA* aux = f->inicio;
    f->inicio = f->inicio->prox;
    free(aux);
}

// funcao auxiliar a "printa_fila()"
// pre-condicao: nenhuma
// pos-condicao: nenhum
// Entrada: ponteiro para primeiro no da fila
// Retorno: nenhum
void printa_fila_aux(NO_FILA* no){
    if(no != NULL){
        printf("[%d] ", no->cod);
        printa_fila_aux(no->prox);
    }
}

// imprime os elementos da fila
// pre-condicao: nenhum
// pos-condicao: nenhum
// Entrada: ponteiro para fila
// Retorno: nenhum
void printa_fila(FILA* f){
    printa_fila_aux(f->inicio);
}

#endif