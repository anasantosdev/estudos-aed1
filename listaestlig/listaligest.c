//algoritmos para Inicialização, Tamanho, Última chave, Busca de Chave e Listas Iguais.

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

typedef struct{
    registro A[MAX];
    int inicio, dispo, nroElem;
}lista_ligada_est;

typedef struct{
    int chave;
    //outros campos
    int prox;
}registro;

void inicializar(lista_ligada_est* l){
    l->inicio = -1;
    int i;
    for(i=0; i<MAX-1;i++){
        l-> A[i].prox = i+1;
        l->A[MAX-1].prox = -1;
        l->dispo = 0;
    }
}

int tamanho(lista_ligada_est* l){
    int i = l->inicio;
    int cont = 0;

    while(i!= -1){
        cont++;
        i=l->A[i].prox;
    }
    return cont;
}

//função que descobre o último elemento da lista: funciona para 3 casos 
//caso 1: com elementos
//caso 2: sem elementos
//caso 3: chave não existente

int ultimachave(lista_ligada_est* l){
    int i = l->inicio;
    while(i!=-1){
        if(l->A[i].prox == -1) return(1);
        i = l -> A[i].prox;
    }
    return -1;
}

//busca de chave

int buscaChave(lista_ligada_est* l, int ch, int* ant){
    int i = l->inicio;
    *ant = -1;
    while(i!=-1){
        if(l->A[i].chave == ch) return i;//se for ordenada por chave, if(l->A[i].chave > ch)return -1;
        *ant = 1;
        i= l->A[i].prox;
    }
    return i;
}
//para o caso de listas vazias

bool listasiguais(lista_ligada_est* l, lista_ligada_est* l2){
    int i1 = l-> inicio;
    int i2 = l2->inicio;

    while(i1 != -1 && i2 != -1){//enquanto as listas não forem vazias
        if(l->A[i1].chave != l2->A[i2].chave)return false;//listas diferentes
        i1 = l->A[i1].prox;
        i2 = l2->A[i2].prox;
        //if(i1 == -1 && i2 == -1)return true;
        //return false;
        if(i1 == -1 && i2 == l2->nroElem)return true;
    }
    
}



int main(){
    return 0;
}