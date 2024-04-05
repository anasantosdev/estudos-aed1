//Dado um elemento i garantidamente existente, (i é um indice), 
//mova este elemento para a frente da lista

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

bool excluir(lista_ligada_est* l, int ch, int ant){
    int ant;
    int atual = busca(l, ch, &ant);
    if(atual == -1) return false; //não existe
    if(ant > -1){// tem anterior
        l -> A[ant].prox = l->A[atual].prox;
    } else l -> inicio = l ->A[atual].prox;

    devolver(l, atual); 
    return true;
}

int obterEnd(lista_ligada_est* l){
    if(l->dispo == -1) return -1;
    int resposta = l->dispo;
    l->dispo = l->A[l->dispo].prox;
    return resposta;
}

bool moverFrente(lista_ligada_est* l, int i){
    int ant;
    int ch = l ->A[i].chave;
     bool ok = excluir(l, ch, &ant);
     if(!ok)return false; // teste para ver se i é necessário
    int novo = obterEndereco(l);
    l->A[novo].chave = ch;
    l->A[novo].prox = l ->inicio;

    return true;
    // se quisermos mover um elemento que já está na 1a posição
    //if(inicio == i){
        //comandos
    //}
}

int main(){

    return 0;
}