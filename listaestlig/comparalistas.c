// Algoritmos para comparar duas listas de tipos diferentes (lista ligada estática e lista sequencial)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct{
    registro A[MAX];
    int inicio, dispo, nroElem;
}lista_lig_est;

typedef struct{
    int chave;
    //outros campos
    int prox;
}registro;

typedef struct{
    registro A[MAX];
    int nroElem;
}lista_seq;

void inicializar (lista_seq* l1){
    l1 -> nroElem = 0;
}

void inicializar(lista_lig_est* l2){
    l2->inicio = -1;
    int i;
    for(i=0; i<MAX-1;i++){
        l2-> A[i].prox = i+1;
        l2->A[MAX-1].prox = -1;
        l2->dispo = 0;
    }
}

bool listasiguais(lista_seq* l1, lista_lig_est* l2){
    int i1 = 0, i2 = l2 -> inicio; //sequencial e ligada;
    while (i2!= -1 && i1 < l1->nroElem){//condição garante a verdade do IF
    if(l1->A[i1].chave != l2->A[i2].chave)return false;
    i1++;
    i2 = l2 -> A[i2].prox;
    }//testar o fim do laço while
    if(i1<l1->nroElem || i2 != -1)return false; //tam diferentes
    return true; //do contrário, tamanhos iguais
}

int main(){

    return 0;
}