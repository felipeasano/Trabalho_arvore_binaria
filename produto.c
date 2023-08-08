#ifndef PRODUTO_C
#define PRODUTO_C

#include<stdio.h>
#include<string.h>
#include<stdlib.h.>

#include "produto.h"
#include "arquivo.h"
#include "queue.h"

// funcao que printa os dados do produto referente ao no de entrada
// pre-condicao: nenhuma
// pos-condicao: nenhuma
// Entrada: Entra com o no a ser impresso
// Retorno: Nenhum
void printa_no(NO no){
    printf("Reg: %d\n", no.reg);
    printf("Esquerda: %d\n", no.esq);
    printf("Direita: %d\n", no.dir);
    printf("Cod: %d\n", no.prod.cod);
    printf("Nome: %s\n", no.prod.nome);
    printf("Marca: %s\n", no.prod.marca);
    printf("Categoria: %s\n", no.prod.categoria);
    printf("Estoque: %d\n", no.prod.estoque);
    printf("Preco: R$ %s\n\n", no.prod.preco);
}

// funcao que liga o no a arvore binaria, mantendo suas propriedades
// pre-condicao: arquivo deve estar aberto e deve existir um no
// pos-condicao: arvore do arquivo eh atualizada
// Entrada: estrutura de arq binario, NO a ser ligado na arvore e seu registro
// Retorno: retorna a estrutura de arq binario atualizado
ARQ_BIN linka_no_arvore(ARQ_BIN b, NO novo, int reg_atual){

    if(b.c.raiz == -1){
        b.c.raiz = 0;
        return b;
    }
    NO no;
    carrega_no(&b, &no, reg_atual);
    if(novo.prod.cod == no.prod.cod){
        return b;
    }
    if(novo.prod.cod < no.prod.cod){
        if(no.esq == -1){
            no.esq = novo.reg;
            grava_no(&b, &no);
        }else{
            return linka_no_arvore(b, novo, no.esq);
        }
    }else{
        if(no.dir == -1){
            no.dir = novo.reg;
            grava_no(&b, &no);
        }else{
            return linka_no_arvore(b, novo, no.dir);
        }
    }
    return b;
}

// realiza o cadastro de um novo produto pelo usuario
// pre-condicao: arquivo aberto
// pos-condicao: arvore do arquivo eh atualizada
// Entrada: estrutura de arquivo binario
// Retorno: arquivo atualizado
ARQ_BIN cadastra_prod(ARQ_BIN b){
    NO no;
    no.dir = -1;
    no.esq = -1;

    if(b.c.livre >= 0){
        no.reg = b.c.livre;
        NO livre;
        carrega_no(&b, &livre, b.c.livre);
        b.c.livre = livre.dir;
    }else{
        if(b.c.raiz == -1){
            b.c.raiz = 0;
        }
        no.reg = b.c.topo;
        b.c.topo++;
    }

    grava_cabecalho(&b);

    printf("Entre com o codigo do produto: ");
    scanf("%d%*c", &no.prod.cod);

    printf("Entre com o nome do produto: ");
    fgets(no.prod.nome, sizeof(no.prod.nome), stdin);
    if (no.prod.nome[strlen(no.prod.nome) - 1] == '\n') {
        no.prod.nome[strlen(no.prod.nome) - 1] = '\0';
    }

    printf("Entre com a marca do produto: ");
    fgets(no.prod.marca, sizeof(no.prod.marca), stdin);
    if (no.prod.marca[strlen(no.prod.marca) - 1] == '\n') {
        no.prod.marca[strlen(no.prod.marca) - 1] = '\0';
    }

    printf("Entre com a categori do produto: ");
    fgets(no.prod.categoria, sizeof(no.prod.categoria), stdin);
    if (no.prod.categoria[strlen(no.prod.categoria) - 1] == '\n') {
        no.prod.categoria[strlen(no.prod.categoria) - 1] = '\0';
    }

    printf("Entre com o estoque do produto: ");
    scanf("%d", &no.prod.estoque);

    printf("Entre com o preco do produto: ");
    scanf("%s[^\n]", no.prod.preco);    

    grava_cabecalho(&b);
    grava_no(&b, &no);

    
    b = linka_no_arvore(b, no, 0);
    carrega_cabecalho(&b);
    printf("Produto Cadastrado com Sucesso!\n");

    system("pause");

    return b;
}

// funcao auxiliar a "consulta_prod()"
// pre-condicao: arquivo aberto
// pos-condicao: nenhum
// Entrada: estrutura de arq binario, cod a ser buscado e registro do no analizado
// Retorno: retorna o NO buscado
NO consulta_prod_rec(ARQ_BIN b, int cod, int reg){

    NO no;
    carrega_no(&b, &no, reg);

    carrega_cabecalho(&b);

    if(no.prod.cod == cod){
        return no;
    }else{
        if(no.prod.cod < cod){
            if(no.dir == -1){
                printf("Cod nao existe!\n");
                no.reg = -1;
                return no;
            }else{
                return consulta_prod_rec(b, cod, no.dir);
            }
        }else{
            if(no.esq == -1){
                printf("Cod nao existe!\n");
                no.reg = -1;
                return no;
            }else{
                return consulta_prod_rec(b, cod, no.esq);
            }
        }
    }
    return no;
}

// funcao que realiza a busca do no na arvore dentro do arquivo .bin
// pre-condicao: arquivo aberto
// pos-condicao: nenhum
// Entrada: estrutura de arquivo .bin
// Retorno: Nenhum
void consulta_prod(ARQ_BIN b){

    system("cls");
    int cod;
    NO no;
    if(b.c.raiz == -1){
        printf("Nenhum produto cadastrado ainda...\n");
        system("pause");
        return;
    }

    printf("Entre com o cod do produto a ser consultado: ");
    scanf("%d", &cod);
    no = consulta_prod_rec(b, cod, b.c.raiz);

    if(no.reg != -1){
        printa_no(no);
    }
    system("pause");
}

// atualiza os dados de um no dentro da arvore no arquivo .bin
// pre-condicao: arquivo aberto
// pos-condicao: arquivo atualizado
// Entrada: estrutura para arquivo .bin, opcao para atualizacao 0->preco, 1->estoque
// Retorno: estrutura de arquivo .bin
ARQ_BIN atualiza_dado(ARQ_BIN b, int opcao){

    system("cls");
    int cod;
    NO no;
    if(b.c.raiz == -1){
        printf("Nenhum produto cadastrado ainda...\n");
        system("pause");
        return b;
    }

    printf("Entre com o cod do produto a ser atualizado: ");
    scanf("%d", &cod);
    no = consulta_prod_rec(b, cod, b.c.raiz);

    // atualiza preco
    if(opcao == 0){
        printf("Preco atual: R$ %s\n", no.prod.preco);
        printf("Entre com o novo preco: ");
        scanf("%s", no.prod.preco);
    // atualiza estoque
    }else{
        printf("Estoque atual: %d\n", no.prod.estoque);
        printf("Entre com o novo estoque: ");
        scanf("%d", &no.prod.estoque);
    }

    grava_no(&b, &no);

    if(no.reg != -1){
        printa_no(no);
    }
    system("pause");
    return b;
}

// imprime os dados dos NOs da arovre em ordem crescente
// pre-condicao: arquivo aberto
// pos-condicao: nenhum
// Entrada: estrutura para arquivo .bin, indicador do NO na arvore dentro do arquivo
// Retorno: nenhum
void printa_arvore_in_ordem(ARQ_BIN b, int reg){

    if(b.c.raiz == -1){
        printf("Lista vazia!\n");
        //system("pause");
        return;
    }

    NO no;

    carrega_no(&b, &no, reg);
    
    if(no.esq != -1){
        printa_arvore_in_ordem(b, no.esq);
    }
    printa_no(no);
    if(no.dir != -1){
        printa_arvore_in_ordem(b, no.dir);
    }
    //system("pause");
}

// imprime a avore binaria por niveis
// pre-condicao: arquivo aberto
// pos-condicao: nenhum
// Entrada: estrutura para arquivo .bin
// Retorno: nenhum
void printa_arvore_por_nivel(ARQ_BIN b){

    system("cls");
    printf("Arvore Binaria por Niveis:\n\n");

    if(b.c.raiz == -1){
        printf("Arvore Vazia!\n");
        return;
    }
    FILA fila;
    FILA* f = inicializa_fila();
    NO no, no_aux;

    carrega_no(&b, &no, b.c.raiz);

    enqueue(f, no.prod.cod);
    enqueue(f, -1);
    //printa_no(no);

    while(!vazia(f)){
            
        printf("[%d] ", f->inicio->cod);
        dequeue(f);

        if(no.esq != -1){
            carrega_no(&b, &no_aux, no.esq);
            enqueue(f, no_aux.prod.cod);
        }
        if(no.dir != -1){
            carrega_no(&b, &no_aux, no.dir);
            enqueue(f, no_aux.prod.cod);
        }
        if(f->inicio->cod == -1){
            printf("\n");
            dequeue(f);
            enqueue(f, -1);
        }
        if(f->inicio->cod == -1 && f->inicio->prox == NULL) {
            printf("\n\n");
            break;
        }
        no = consulta_prod_rec(b, f->inicio->cod, b.c.raiz);
    }
}

// realiza o cadastro de um produto a partir da leitura de um arquivo .txt
// pre-condicao: arquivo aberto
// pos-condicao: arquivo atualizado
// Entrada: estrutura para arquivo .bin, produto a ser gravado
// Retorno: estrutura de arquivo .bin
ARQ_BIN insere_prod_por_txt(ARQ_BIN b, PRODUTO p){

    NO no;
    no.prod = p;
    no.dir = -1;
    no.esq = -1;

    if(b.c.livre >= 0){
        no.reg = b.c.livre;
        NO livre;
        carrega_no(&b, &livre, b.c.livre);
        b.c.livre = livre.dir;
    }else{
        no.reg = b.c.topo;
        b.c.topo++;
    }
    grava_cabecalho(&b);
    grava_no(&b, &no);

    b = linka_no_arvore(b, no, 0);

    grava_cabecalho(&b);

    return b;
}

// atualiza o estoque de um no a partir de uma leitura de um arquivo .txt
// pre-condicao: arquivo aberto
// pos-condicao: arquivo atualizado
// Entrada: estrutura para arquivo .bin, produto a ser atualizado
// Retorno: estrutura de arquivo .bin
ARQ_BIN atualiza_estoque_txt(ARQ_BIN b, PRODUTO p){

    NO no = consulta_prod_rec(b, p.cod, b.c.raiz);
    no.prod.estoque = p.estoque;

    grava_no(&b, &no);

    return b;
}

// atualiza o preco de um no a partir de uma leitura de um arquivo .txt
// pre-condicao: arquivo aberto
// pos-condicao: arquivo atualizado
// Entrada: estrutura para arquivo .bin, produto a ser atualizado
// Retorno: estrutura de arquivo .bin
ARQ_BIN atualiza_preco_txt(ARQ_BIN b, PRODUTO p){

    NO no = consulta_prod_rec(b, p.cod, b.c.raiz);
    //no.prod.preco= p.preco;
    strcpy(no.prod.preco, p.preco);

    grava_no(&b, &no);

    return b;
}

// grava um NO no arquivo .bin
// pre-condicao: arquivo aberto
// pos-condicao: arquivo atualizado
// Entrada: estrutura para arquivo .bin, NO a ser inserido no arquivo
// Retorno: nenhum
void grava_no(ARQ_BIN *b, NO *no){

    fseek(b->arq_bin, sizeof(CABECALHO) + (sizeof(NO) * no->reg), SEEK_SET);
    fwrite(no, sizeof(NO), 1, b->arq_bin);
}

// le um NO do arquivo .bin
// pre-condicao: arquivo aberto
// pos-condicao: nenhum
// Entrada: estrutura para arquivo .bin, NO a ser lido do arquivo, numero do registro
// Retorno: nenhum
void carrega_no(ARQ_BIN *b, NO *no, int reg){

    fseek(b->arq_bin, sizeof(CABECALHO) + (sizeof(NO) * reg), SEEK_SET);
    fread(no, sizeof(NO), 1, b->arq_bin);
}

// grava o cabecalho no arquivo .bin
// pre-condicao: arquivo aberto
// pos-condicao: arquivo atualizado
// Entrada: estrutura para arquivo .bin
// Retorno: nenhum
void grava_cabecalho(ARQ_BIN *b){
    fseek(b->arq_bin, 0, SEEK_SET);
    fwrite(&b->c, sizeof(CABECALHO), 1, b->arq_bin);
}

// carrega o cabecalho do arquivo .bin
// pre-condicao: arquivo aberto
// pos-condicao: cabecalho atualizado
// Entrada: estrutura para arquivo .bin
// Retorno: nenhum
void carrega_cabecalho(ARQ_BIN *b){
    fseek(b->arq_bin, 0, SEEK_SET);
    fread(&b->c, sizeof(CABECALHO), 1, b->arq_bin);
}

// libera no da arvore e insere na lista de livres
// pre-condicao: arquivo aberto
// pos-condicao: arquivo atualizado
// Entrada: estrutura para arquivo .bin, NO a ser liberado
// Retorno: nenhum
void liberar_no(ARQ_BIN *b, NO* no){
    no->dir = b->c.livre;
    b->c.livre = no->reg;
    grava_no(b, no);
    grava_cabecalho(b);
}

// busca o maior NO
// pre-condicao: arquivo aberto
// pos-condicao: arquivo atualizado
// Entrada: estrutura para arquivo .bin, reg da arvore a ser feito a busca, NO a receber o maior NO
// Retorno: estrutura de arquivo .bin
int maior_dos_menores(ARQ_BIN *b, int reg, NO* maior){

    NO no;
    carrega_no(b, &no, reg);
    if(no.dir == -1){
        *maior = no;
        liberar_no(b, &no);
        return no.esq;
    }
    no.dir = maior_dos_menores(b, no.dir, maior);
    grava_no(b, &no);
    return no.reg;
}

// funcao auxiliar a "remover()"
// pre-condicao: arquivo aberto
// pos-condicao: arquivo atualizado
// Entrada: estrutura para arquivo .bin, cod do NO a ser removido, registrador indicando no acessado
// Retorno: o registro do no da arvore a receber a remocao
int remover_sub(ARQ_BIN *b, int cod, int reg){

    NO no;
    NO removido;
    carrega_no(b, &no, reg);

    if(no.prod.cod == cod){
        printf("Cod %d removido com sucesso\n", cod);
        if(no.dir == -1 && no.esq == -1){
            liberar_no(b, &no);
            return -1;
        }
        int aux;
        if(no.dir == -1){
            aux = no.esq;
            liberar_no(b, &no);
            return aux;
        }
        if(no.esq == -1){
            aux = no.dir;
            liberar_no(b, &no);
            return aux;
        }
        no.esq = maior_dos_menores(b, no.esq, &removido);
        no.prod = removido.prod;
        grava_no(b, &no);
        return reg;
    }

    if(cod < no.prod.cod){
        if(no.dir == -1 && no.esq == -1){
            printf("Codigo inexistente!\n");
        }
        else no.esq = remover_sub(b, cod, no.esq);
    }else{
        if(no.dir == -1 && no.esq == -1){
            printf("Codigo inexistente!\n");
        }
        no.dir = remover_sub(b, cod, no.dir);
    }

    grava_no(b, &no);
    return no.reg;
}

// realiza a remocao de um no na arvore binario no arquivo
// pre-condicao: arquivo aberto
// pos-condicao: arquivo atualizado
// Entrada: estrutura para arquivo .bin, cod do NO a ser removido
// Retorno: nenhum
void remover(ARQ_BIN *b, int cod){

    b->c.raiz = remover_sub(b, cod, b->c.raiz);
    grava_cabecalho(b);
}

// funcao auxiliar a "printa_lista_livres()"
// pre-condicao: arquivo aberto
// pos-condicao: nenhum
// Entrada: estrutura para arquivo .bin, NO a ser acessado, registro desse NO
// Retorno: nenhum
void printa_lista_livres_rec(ARQ_BIN b, NO no, int reg){

    carrega_no(&b, &no, reg);
    printf("%d -> ", no.reg);

    if(no.dir != -1){
        printa_lista_livres_rec(b, no, no.dir);
    }
    return;
}

// imprime uma a lista de NOs livres
// pre-condicao: arquivo aberto
// pos-condicao: nenhum
// Entrada: estrutura para arquivo .bin
// Retorno: nenhum
void printa_lista_livres(ARQ_BIN b){

    NO no;
    carrega_no(&b, &no, b.c.livre);
    printf("%d -> ", no.reg);

    if(no.dir != -1){
        printa_lista_livres_rec(b, no, no.dir);
    }
    printf("\n\n");
    return ;
}

// funcao apena para varrer o arquivo verificando seus ponteiros, registros e cods
void inspeciona_arvore(ARQ_BIN* b) {
  printf("{%d, %d, %d}", b->c.raiz, b->c.topo, b->c.livre);
  for (int i=0; i<b->c.topo; i++) {
    NO no;
    carrega_no(b, &no, i);
    printf(" [%d: %d, %d; %d]", i, no.esq, no.dir, no.prod.cod);
  }
  printf("\n");
}

#endif