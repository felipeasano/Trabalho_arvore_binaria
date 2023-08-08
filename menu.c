#ifndef MENU_C
#define MENU_C

#include <stdio.h>

#include "menu.h"

// imprime o menu do programa
// pre-condicao: nenhuma
// pos-condicao: nenhuma
// Entrada: nenhum
// Retorno: Nenhum
void printa_menu(){

    printf("\tBEM VINDO A AED VENDAS ONLINE\n");
    printf("____________________________________________\n\n");


    printf("[1] - Cadastrar Produto\n");
    printf("[2] - Remover Produto\n");
    printf("[3] - Atualizar Preco\n");
    printf("[4] - Atualizar Estoque\n");
    printf("[5] - Consultar Produto\n");
    printf("[6] - Imprimir Lista de Produtos\n");
    printf("[7] - Imprimir Arvore Binaria\n");
    printf("[8] - Imprimir Lista de Livres\n");
    printf("[9] - Carregar Arquivo\n");
    printf("[0] - Fim do programa!\n\n");

    printf("Entre com uma das opcoes acima: ");
}

#endif