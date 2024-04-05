//LISTAS DINÂMICAS COM NÓ SENTINELA

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
NO* sentinela;
} LISTA;

// Inicialização (lista com sentinela)
void inicializarLista(LISTA* l) {
 l->sentinela = (NO*) malloc(sizeof(NO));
 l->inicio = l->sentinela;
}

// Exibição (lista com sentinela)
void exibirLista(LISTA l) {
 NO* p = l.inicio;
 while (p != l.sentinela) {
 printf("%d ",p->chave); // chave deve ser int
 p = p->prox;
 }
}

// Primeiro elemento da lista com sentinela
NO* primeiroElemLista(LISTA l) {
if(l.inicio == l.sentinela)
return(NULL);
 else
return(l.inicio);
}

// Último elemento da lista com sentinela
NO* ultimoElemLista(LISTA l) {
 NO* p = l.inicio;
 if(p == l.sentinela) return(NULL);
 while(p->prox != l.sentinela)
 p = p->prox;
 return(p);
}

// N-ésimo elemento da lista com sentinela
NO* enesimoElemLista(LISTA l, int n) {
 NO* p = l.inicio;
 int i = 1;
 if(p == l.sentinela) return(NULL);
 while((p->prox != l.sentinela) && (i < n)) {
 p = p->prox;
 i++;
 }
 if(i != n) return(NULL);
 else return(p);
}

// Quantos elementos existem na lista com sentinela
int tamanhoLista(LISTA l) {
 NO* p = l.inicio;
 int tam = 0;
 while (p != l.sentinela) {
tam++;
p = p->prox;
}
return(tam);
}

// Busca da chave em lista ordenada e com sentinela
NO* buscaSeqOrd(int ch, LISTA l, NO* *ant) {
 NO* p = l.inicio;
 *ant = NULL;
 l.sentinela->chave = ch;
 while(p->chave < ch) {
 *ant = p;
 p = p->prox;
 }
 if((p != l.sentinela) && (p->chave == ch)) return(p);
 else return(NULL);
}

// Inserção em lista ordenada sem repetição com sentinela
bool inserirElemListaOrd(int ch , LISTA* l) {
 NO* novo;
NO* ant;
 novo = buscaSeqOrd(ch, *l, &ant);
 if(novo) return(false);
 novo = (NO*) malloc(sizeof(NO));
 novo->chave = ch;
 if(l->inicio == l->sentinela) {
 l->inicio = novo;
novo->prox = l->sentinela;
 }
 else {
 if(ant==NULL) {
 novo->prox = l->inicio;
 l->inicio = novo;
 }
 else {
 novo->prox = ant->prox;
 ant->prox = novo;
 }
 }
 return(true);
}

// Anexar um novo elemento à lista com sentinela
void anexarElemLista(int ch, LISTA* l) {
 NO* novo;
 NO* ant;
 ant = ultimoElemLista(*l);
 novo = (NO *) malloc(sizeof(NO));
 novo->chave = ch;
 novo->prox = l->sentinela;
 if(ant == NULL) l->inicio = novo;
 else ant->prox = novo;
}

// Destruição da lista com sentinela
void destruirLista (LISTA* l) {
 NO* atual;
 NO* prox;
 atual = l->inicio;
 while (atual != l->sentinela ) {
 prox = atual->prox;
 free(atual);
 atual = prox;
 }
 l->inicio = l->sentinela;
}

int main(){

    return 0;
}
