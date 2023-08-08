#ifndef PRODUTO_H
#define PRODUTO_H

#include "arquivo.h"

// estrutura para produto
typedef struct prod{
    int cod;
    char nome[50];
    char marca[30];
    char categoria[50];
    int estoque;
    char preco[10];
}PRODUTO;

// estrutura para no da arvore
typedef struct no{
    int reg;
    int dir;
    int esq;
    PRODUTO prod;
}NO;

// funcao que printa os dados do produto referente ao no de entrada
// pre-condicao: nenhuma
// pos-condicao: nenhuma
// Entrada: Entra com o no a ser impresso
// Retorno: Nenhum
void printa_no(NO no);

// funcao que liga o no a arvore binaria, mantendo suas propriedades
// pre-condicao: arquivo deve estar aberto e deve existir um no
// pos-condicao: arvore do arquivo eh atualizada
// Entrada: estrutura de arq binario, NO a ser ligado na arvore e seu registro
// Retorno: retorna a estrutura de arq binario atualizado
ARQ_BIN linka_no_arvore(ARQ_BIN b, NO novo, int reg_atual);

// realiza o cadastro de um novo produto pelo usuario
// pre-condicao: arquivo aberto
// pos-condicao: arvore do arquivo eh atualizada
// Entrada: estrutura de arquivo binario
// Retorno: arquivo atualizado
ARQ_BIN cadastra_prod(ARQ_BIN b);

// funcao auxiliar a "consulta_prod()"
// pre-condicao: arquivo aberto
// pos-condicao: nenhum
// Entrada: estrutura de arq binario, cod a ser buscado e registro do no analizado
// Retorno: retorna o NO buscado
NO consulta_prod_rec(ARQ_BIN b, int cod, int reg);

// funcao que realiza a busca do no na arvore dentro do arquivo .bin
// pre-condicao: arquivo aberto
// pos-condicao: nenhum
// Entrada: estrutura de arquivo .bin
// Retorno: Nenhum
void consulta_prod(ARQ_BIN b);

// atualiza os dados de um no dentro da arvore no arquivo .bin
// pre-condicao: arquivo aberto
// pos-condicao: arquivo atualizado
// Entrada: estrutura para arquivo .bin, opcao para atualizacao 0->preco, 1->estoque
// Retorno: estrutura de arquivo .bin
ARQ_BIN atualiza_dado(ARQ_BIN b, int opcao);

// imprime os dados dos NOs da arovre em ordem crescente
// pre-condicao: arquivo aberto
// pos-condicao: nenhum
// Entrada: estrutura para arquivo .bin, indicador do NO na arvore dentro do arquivo
// Retorno: nenhum
void printa_arvore_in_ordem(ARQ_BIN b, int reg);

// imprime a avore binaria por niveis
// pre-condicao: arquivo aberto
// pos-condicao: nenhum
// Entrada: estrutura para arquivo .bin
// Retorno: nenhum
void printa_arvore_por_nivel(ARQ_BIN b);

// realiza o cadastro de um produto a partir da leitura de um arquivo .txt
// pre-condicao: arquivo aberto
// pos-condicao: arquivo atualizado
// Entrada: estrutura para arquivo .bin, produto a ser gravado
// Retorno: estrutura de arquivo .bin
ARQ_BIN insere_prod_por_txt(ARQ_BIN b, PRODUTO p);

// atualiza o estoque de um no a partir de uma leitura de um arquivo .txt
// pre-condicao: arquivo aberto
// pos-condicao: arquivo atualizado
// Entrada: estrutura para arquivo .bin, produto a ser atualizado
// Retorno: estrutura de arquivo .bin
ARQ_BIN atualiza_estoque_txt(ARQ_BIN b, PRODUTO p);

// atualiza o preco de um no a partir de uma leitura de um arquivo .txt
// pre-condicao: arquivo aberto
// pos-condicao: arquivo atualizado
// Entrada: estrutura para arquivo .bin, produto a ser atualizado
// Retorno: estrutura de arquivo .bin
ARQ_BIN atualiza_preco_txt(ARQ_BIN b, PRODUTO p);

// grava um NO no arquivo .bin
// pre-condicao: arquivo aberto
// pos-condicao: arquivo atualizado
// Entrada: estrutura para arquivo .bin, NO a ser inserido no arquivo
// Retorno: nenhum
void grava_no(ARQ_BIN *b, NO *no);

// le um NO do arquivo .bin
// pre-condicao: arquivo aberto
// pos-condicao: nenhum
// Entrada: estrutura para arquivo .bin, NO a ser lido do arquivo, numero do registro
// Retorno: nenhum
void carrega_no(ARQ_BIN *b, NO *no, int reg);

// grava o cabecalho no arquivo .bin
// pre-condicao: arquivo aberto
// pos-condicao: arquivo atualizado
// Entrada: estrutura para arquivo .bin
// Retorno: nenhum
void grava_cabecalho(ARQ_BIN *b);

// carrega o cabecalho do arquivo .bin
// pre-condicao: arquivo aberto
// pos-condicao: cabecalho atualizado
// Entrada: estrutura para arquivo .bin
// Retorno: nenhum
void carrega_cabecalho(ARQ_BIN *b);

// libera no da arvore e insere na lista de livres
// pre-condicao: arquivo aberto
// pos-condicao: arquivo atualizado
// Entrada: estrutura para arquivo .bin, NO a ser liberado
// Retorno: nenhum
void liberar_no(ARQ_BIN *b, NO* no);

// busca o maior NO
// pre-condicao: arquivo aberto
// pos-condicao: arquivo atualizado
// Entrada: estrutura para arquivo .bin, reg da arvore a ser feito a busca, NO a receber o maior NO
// Retorno: estrutura de arquivo .bin
int maior_dos_menores(ARQ_BIN *b, int reg, NO* maior);

// funcao auxiliar a "remover()"
// pre-condicao: arquivo aberto
// pos-condicao: arquivo atualizado
// Entrada: estrutura para arquivo .bin, cod do NO a ser removido, registrador indicando no acessado
// Retorno: o registro do no da arvore a receber a remocao
int remover_sub(ARQ_BIN *b, int cod, int reg);

// realiza a remocao de um no na arvore binario no arquivo
// pre-condicao: arquivo aberto
// pos-condicao: arquivo atualizado
// Entrada: estrutura para arquivo .bin, cod do NO a ser removido
// Retorno: nenhum
void remover(ARQ_BIN *b, int cod);

// funcao auxiliar a "printa_lista_livres()"
// pre-condicao: arquivo aberto
// pos-condicao: nenhum
// Entrada: estrutura para arquivo .bin, NO a ser acessado, registro desse NO
// Retorno: nenhum
void printa_lista_livres_rec(ARQ_BIN b, NO no, int reg);

// imprime uma a lista de NOs livres
// pre-condicao: arquivo aberto
// pos-condicao: nenhum
// Entrada: estrutura para arquivo .bin
// Retorno: nenhum
void printa_lista_livres(ARQ_BIN b);

// funcao apena para varrer o arquivo verificando seus ponteiros, registros e cods
void inspeciona_arvore(ARQ_BIN* b);

#endif