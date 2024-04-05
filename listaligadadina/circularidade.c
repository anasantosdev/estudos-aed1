#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

# define MAX 50

typedef struct estrutura {
 int chave;
 int info;
 struct estrutura *prox;
} NO;

typedef struct {
NO* inicio;
NO* cabeca;
} LISTA;

// Inicialização da lista circular e com nó cabeça
void inicializarLista(LISTA *l) {
 l->cabeca = (NO*) malloc(sizeof(NO));
 l->cabeca->prox = l->cabeca;
}

// Exibição da lista circular e com nó cabeça
void exibirLista(LISTA l) {
 NO* p = l.cabeca->prox;
 while (p!=l.cabeca) {
 printf("%d ",p->chave); // deve ser int
 p = p->prox;
 }
}

// 1º. elemento da lista
NO* primeiroElemLista(LISTA l) {
 if(l.cabeca->prox == l.cabeca) return(NULL);
 else return(l.cabeca->prox);
}

// Último elemento da lista
NO* ultimoElemLista(LISTA l) {
 NO* p = l.cabeca->prox;
 if(p == l.cabeca) return(NULL);
 while(p->prox!=l.cabeca)
 p = p->prox;
 return(p);
}

// N-ésimo elemento da lista
NO* enesimoElemLista(LISTA l, int n) {
 NO* p = l.cabeca->prox;
If(p==l.cabeca);
return(NULL);
 int i = 1;
 while( (p->prox != l.cabeca) && (i < n) ) {
 p = p->prox;
 i++;
 }
 if(i != n) return(NULL);
 else return(p);
}

// Quantos elementos existem?
int tamanhoLista(LISTA l) {
 NO* p = l.cabeca->prox;
 int tam = 0;
 while (p != l.cabeca) {
tam++;
p = p->prox;
}
 return(tam);
}

// Posição da chave de busca na lista ordenada
NO* buscaSeqOrd(int ch, LISTA l, NO* *ant) {
 NO* p = l.cabeca->prox;
 *ant = l.cabeca;
 l.cabeca->chave = ch; // usa cabeça como sentinela
 while(p->chave < ch) {
 *ant = p;
 p = p->prox;
 }
 if((p != l.cabeca) && (p->chave == ch) ) return(p);
 else return(NULL);
}

// Inserção ordenada sem duplicidade
bool inserirElemListaOrd(int ch , LISTA* l) {
NO* novo;
 NO* ant;
novo = buscaSeqOrd(ch, *l, &ant);
if(novo) return(false);
novo = (NO*) malloc(sizeof(NO));
 novo->chave = ch;
 novo->prox = ant->prox;
 ant->prox = novo;
 return(true);
}

// Destruição da lista circular e com nó cabeça
void destruirLista (LISTA* l) {
NO* atual;
 NO* prox;
atual = l->cabeca->prox;
while (atual != l->cabeca ) {
 prox = atual->prox;
 free(atual);
 atual = prox;
 }
 l->cabeca->prox = l->cabeca;
}



int main(){

    return 0;
}
