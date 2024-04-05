// Listas dinâmicas duplamente encadeadas com nó cabeça e circularidade

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

# define MAX 50

typedef struct estrutura {
 int chave;
 int info;
 struct estrutura *prox;
 struct estrutura *ant;
} NO;
typedef struct {
 NO* cabeca;
} LISTA;

// Inicialização (encadeamento duplo, circular e com nó cabeça)
void inicializarLista(LISTA* l) {
 l->cabeca = (NO*) malloc(sizeof(NO));
 l->cabeca->prox = l->cabeca;
 l->cabeca->ant = l->cabeca;
}

// Último elemento da lista (encadeamento duplo, circular e com nó cabeça)
NO* ultimoElemLista(LISTA l) {
 NO* p = l.cabeca->ant;
 if(p == l.cabeca) return(NULL);
 else return(p);
}

// Inserção ordenada sem duplicações
bool inserirElemListaOrd(int ch , LISTA* l) {
 NO* novo;
 NO* ant;
 novo = buscaSeqOrd(ch, *l, &ant);
 if(novo) return(false);
 novo = (NO*) malloc(sizeof(NO));
 novo->chave = ch;
 novo->prox = ant->prox;
 novo->ant = ant;
 novo->prox->ant = novo;
 ant->prox = novo;
 return(true);
}

int main(){

    return 0;
}
