#ifndef ARQUIVO_H
#define ARQUIVO_H

// estrutura de cabecalho para o arquivo .bin
typedef struct cabecalho{
    int raiz;
    int topo;
    int livre;
}CABECALHO;

// estrutura para arquivo .bin contendo ponteiro para arquivo e cabecalho
typedef struct arquivo_bin{
    FILE* arq_bin;
    CABECALHO c;
}ARQ_BIN;

// abre arquivo .bin
// pre-condicao: nenhuma
// pos-condicao: nenhuma
// Entrada: Entra com nome do arquivo e a estrutura para arquivo .bin
// Retorno: devolve a estrutura com o arquivo aberto e o cabecalho lido, ou settado
ARQ_BIN abre_arq_bin(char nome_arquivo[], ARQ_BIN b);

#endif