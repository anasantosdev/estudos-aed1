// algoritmos de Exclusão e Inserção da Lista ligada Estática

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

bool excluir(lista_ligada_est* l, int ch){
    int ant;
    int atual = busca(l, ch, &ant);
    if(atual == -1) return false; //não existe
    if(ant > -1){// tem anterior
        l -> A[ant].prox = l->A[atual].prox;
    } else l -> inicio = l ->A[atual].prox;

    devolver(l, atual); 
    return true;
}

void devolver(lista_ligada_est* l, int atual){
    l ->A[atual].prox = l ->dispo;
    l->dispo = atual;
    return;
}

int obterEnd(lista_ligada_est* l){
    if(l->dispo == -1) return -1;
    int resposta = l->dispo;
    l->dispo = l->A[l->dispo].prox;
    return resposta;
}

bool inserir(lista_ligada_est* l, int ch){
    int ant;
    int atual = buscaChave (l, ch, &ant);
    if(atual!= 1) return false; //ja existe
    int novo = obterEnd(l);//retorna um end ou -1
    if(novo == -1)return false;//vetor cheio
    l->A[novo].chave = ch;
    if(l->inicio == -1){//lista vazia
        l -> inicio = novo;
        l->A[novo].prox = -1;
        return true;
    }//caso 2 generico: no meio
    if(ant > -1){
        l->A[novo].prox = l->A[ant].prox;
        l->A[ant].prox = novo;
        return true;
    }else{//outros casos: com repetição e desordenado
        l->A[novo].prox = l->inicio;
        l->inicio = novo;
    }
    return true;
}


int main(){

    return 0;
}