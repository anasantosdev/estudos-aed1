//função para inserir elemento no final da lista (anexar)
// 1º achar o fim da lista 
// 2º encontrar posição livre

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
// funções auxiliares
int obterEnd(lista_ligada_est* l){
    if(l->dispo == -1) return -1;
    int resposta = l->dispo;
    l->dispo = l->A[l->dispo].prox;
    return resposta;
}

bool anexar(lista_ligada_est* l, int ch){
    int novo = obterEnd(&l); //(1º) indice de uma posição livre no vetor (endereço)
    if(novo == -1)return false; //n tem
    l ->A[novo].chave = ch;
    int i = l->inicio;
    int fim = -1;
    while(i!= -1){
        fim = i; // ponto anterior
        i = l->A[i].prox;
    }
    if(fim > -1){
        l->A[fim].prox = novo;
    } else l->inicio = novo;

}

