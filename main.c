#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "produto.h"
#include "queue.h"
#include "arquivo.h"
#include "arq_txt.h"

int main(){

    int op = 10;
    ARQ_BIN b = abre_arq_bin("arquivo", b);
    //printf("%d %d %d\n", b.c.livre, b.c.raiz, b.c.topo);
    
    while(op != 0){
        system("cls");
        printf("livre: %d raiz: %d topo: %d\n", b.c.livre, b.c.raiz, b.c.topo);
        printa_menu();
        scanf("%d", &op);
        while(op > 10){
            printf("Entrada invalida!\n");
            scanf("%d", &op);
        }
        int cod;
        NO no;
        switch(op){
            case 1:
                system("cls");
                b = cadastra_prod(b);
                break;
            case 2:
                system("cls");
                if(b.c.raiz == -1){
                    printf("Arvore vazia!\n");
                    system("pause");
                    break;
                }
                printf("Entre com o cod a ser removido: ");
                scanf("%d", &cod);
                remover(&b, cod);
                system("pause");
                break;
            case 3:
                // atualiza preco
                b = atualiza_dado(b, 0);
                break;
            case 4:
                // atualiza estoque
                b = atualiza_dado(b, 1);
                break;
            case 5:
                consulta_prod(b);
                break;
            case 6:
                system("cls");
                printa_arvore_in_ordem(b, b.c.raiz);
                system("pause");
                break;
            case 7:
                system("cls");
                printa_arvore_por_nivel(b);
                system("pause");
                break;
            case 8:
                system("cls");
                if(b.c.livre == -1){
                    printf("Lista de livres vazia!\n");
                    system("pause");
                    break;
                }
                printa_lista_livres(b);
                system("pause");
                break;
            case 9:
                b = leitura_arq_txt(b);
                break;
            /*case 10:
                inspeciona_arvore(&b);
                system("pause");
            */
        }
    }
    fclose(b.arq_bin);
    system("cls");
    printf("Fim do Programa!\n");

    return 0;
}
