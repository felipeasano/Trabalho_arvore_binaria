#ifndef ARQ_TXT_H
#define ARQ_TXT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "produto.h"
#include "arquivo.h"
#include "queue.h"

// realiza a leitura do arquivo em lote .txt
// pre-condicao: arquivo .bin aberto
// pos-consicao: arquivo .bin eh atualizado com as informacoes do arquivo .txt em lote
// Entrada: Estrutura para arquivo .bin
// Retorno: Estrutura para arquivo .bin
ARQ_BIN leitura_arq_txt(ARQ_BIN b);

#endif