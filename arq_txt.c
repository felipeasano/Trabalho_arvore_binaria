#ifndef ARQ_TXT_C
#define ARQ_TXT_C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "produto.h"
#include "arquivo.h"
#include "queue.h"
#include "arq_txt.h"

// realiza a leitura do arquivo em lote .txt
// pre-condicao: arquivo .bin aberto
// pos-consicao: arquivo .bin eh atualizado com as informacoes do arquivo .txt em lote
// Entrada: Estrutura para arquivo .bin
// Retorno: Estrutura para arquivo .bin
ARQ_BIN leitura_arq_txt(ARQ_BIN b){

    system("cls");
    printf("Entre com o nome do arquivo: ");

    PRODUTO produto;

    char nome_arquivo[50], linha[100];
    scanf("%s", nome_arquivo);

    FILE* f = fopen(nome_arquivo, "r");

    if(f == NULL){
        printf("Arquivo nao encontrado!\n");
        system("pause");
        return b;
    }
    char *op;
    char *cod;
    while(fgets(linha, 100, f)){
        op = strtok(linha, ";");
        //printf("%s\n", op);

        if(!strcmp(op, "I")){

            cod = strtok(NULL, ";");
            produto.cod = atoi(cod);

            cod = strtok(NULL, ";");
            strcpy(produto.nome, cod);

            cod = strtok(NULL, ";");
            strcpy(produto.marca, cod);

            cod = strtok(NULL, ";");
            strcpy(produto.categoria, cod);

            cod = strtok(NULL, ";");
            produto.estoque = atoi(cod);

            cod = strtok(NULL, "\n");
            strcpy(produto.preco, cod);
            //produto.preco = atoi(cod);

            //cod = strtok(NULL, "\n");
            //produto.preco_dec = atoi(cod);

            //produto.preco += produto.preco_dec/100;

            b = insere_prod_por_txt(b, produto);
            //printf("\n");
        }else{
            if(!strcmp(op, "A")){
                cod = strtok(NULL, ";");
                produto.cod = atoi(cod);

                cod = strtok(NULL, ";");
                produto.estoque = atoi(cod);
                if(cod != NULL){
                    b = atualiza_estoque_txt(b, produto);
                }
                cod = strtok(NULL, "\n");
                //printf("aq!\n");
                if(cod != NULL){
                    strcpy(produto.preco, cod);
                    b = atualiza_preco_txt(b, produto);
                }
                //sscanf();
            }else{
                cod = strtok(NULL, "\n");
                produto.cod = atoi(cod);
                remover(&b, produto.cod);
            }
        }
    }
    printf("Arquivo Carregado com Sucesso\n");
    fclose(f);
    system("pause");
    return b;
}

#endif
