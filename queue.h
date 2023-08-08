#ifndef QUEUE_H
#define QUEUE_H

// estrutura de de para Fila
typedef struct no_fila{
    int cod;
    struct no_fila *prox;
}NO_FILA;

// estrutura para Fila
typedef struct fila{
    NO_FILA* inicio;
    NO_FILA* fim;
}FILA;

// verifica se a fila esta vazia
// pre-condicao: nenhuma
// pos-condicao: nenhuma
// Entrada: ponteiro para fila
// Retorno: retorna 1 caso a fila esteja vazia, 0 caso contrario
int vazia(FILA* f);

// cria uma fila vazia
// pre-condicao: nenhuma
// pos-condicao: fila criada
// Entrada: nenhum
// Retorno: ponteiro para uma fila vazia
FILA* inicializa_fila();

// insere um elemento no final da fila
// pre-condicao: nenhuma
// pos-condicao: elemento eh inserido no final da fila
// Entrada: ponteiro para fila, cod do elemento a ser inserido
// Retorno: nenhum
void enqueue(FILA* f, int cod);

// remove o primeiro elemento da fila
// pre-condicao: nenhum
// pos-condicao: primeiro elemento da fila eh removido
// Entrada: ponteiro para fila
// Retorno: nenhum
void dequeue(FILA* f);

// funcao auxiliar a "printa_fila()"
// pre-condicao: nenhuma
// pos-condicao: nenhum
// Entrada: ponteiro para primeiro no da fila
// Retorno: nenhum
void printa_fila_aux(NO_FILA* no);

// imprime os elementos da fila
// pre-condicao: nenhum
// pos-condicao: nenhum
// Entrada: ponteiro para fila
// Retorno: nenhum
void printa_fila(FILA* f);

#endif