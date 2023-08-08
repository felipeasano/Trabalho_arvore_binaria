#ifndef ARQUIVO_C
#define ARQUIVO_C

#include<stdlib.h>
#include<stdio.h>

#include "arquivo.h"

// abre arquivo .bin
// pre-condicao: nenhuma
// pos-condicao: nenhuma
// Entrada: Entra com nome do arquivo e a estrutura para arquivo .bin
// Retorno: devolve a estrutura com o arquivo aberto e o cabecalho lido, ou settado
ARQ_BIN abre_arq_bin(char nome_arquivo[], ARQ_BIN b){
    b.arq_bin = fopen(nome_arquivo, "r+b");
    if(b.arq_bin == NULL){
        //printf("Novo banco aberto!\n");
        b.arq_bin = fopen(nome_arquivo, "w+b");
        b.c.livre = -1;
        b.c.raiz = -1;
        b.c.topo = 0;
        fwrite(&b.c, sizeof(b.c), 1, b.arq_bin);
    }else{
        //printf("Banco aberto!\n");
        fseek(b.arq_bin, 0, SEEK_SET);
        fread(&b.c, sizeof(b.c), 1, b.arq_bin);
    }
    return b;
}

#endif