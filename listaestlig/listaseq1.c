//Lista sequencial -----> ordem lógica == ordem física

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int chave; // distingue os alunos
    //demais campos
}registro;

typedef struct{
    registro A[MAX];
    int nroElem;
}lista_seq;

void inicializar (lista_seq* l){
    l -> nroElem = 0;
}

bool anexar (lista_seq* l, int ch){
    if(l ->nroElem == MAX) return false; //caso de lista cheia

    l -> A[l->nroElem].chave = ch;
    l -> nroElem ++;
    return true; 
}

void exibir(lista_seq* l){
    int i;
    for(i=0; i < l -> nroElem ;i++){
        printf("%d", l -> A[i].chave);
    }
}

int buscaSeq(lista_seq* l, int ch){
    int i;

    for(i=0; i<l->nroElem; i++){
        if(l->A[i].chave == ch) return i;
    }
}

bool excluir (lista_seq* l, int ch){
    int atual = buscaSeq(l, ch);
    if(atual == -1) return false;
    //else if(atual == 1){
        //l->nroElem = atual;
        //l->A[l->nroElem].chave = 0;
    int i;
    for(i= atual; i< l->nroElem - 1; i++){
        l -> A[i] = l -> A[i+1];
    }
    l->nroElem --;
    return true;
}

int main(){
    lista_seq l;
    inicializar(&l);
    anexar(&l, 2);
    //exibir(&l);
    //int resposta = buscaSeq(&l, 2);
    //printf("%d", resposta);
    excluir(&l, 2);
    exibir(&l);

}