#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// ######### ESCREVA O NROUSP AQUI
char* nroUSP() {
    return("14785580, 14677190");
}

// ######### ESCREVA SEU NOME AQUI
char* nome() {
    return("Ana Paula Bernardo dos Santos, Sara Leticia Santos Silva");
}

// elemento da lista
typedef struct estr {
    int chave;
    int info;
    struct estr* prox;
} NO;

typedef struct{
  NO* inicio;
}LISTA;

//Função para criar a lista e inserir 1 chave 
NO* crialista(int ch){
  NO* p = (NO*)malloc(sizeof(NO));
  if(p == NULL){
    printf("erro de alocação de memória");
    return 0;
  }
  p->chave = ch;
  p->prox = NULL;
  return p;
}

void inserirCh(NO* *inicio, int ch){
  NO* p = crialista(ch);
  if(*inicio == NULL){
    *inicio = p;
  }else {
    NO* atual = *inicio;
    while(atual->prox != NULL){
      atual = atual->prox;
    }
    atual->prox = p;
  }
}

void imprimeLista(NO* inicio){
  NO* atual = inicio;
  int i=0;
if(inicio==NULL) printf("Lista vazia");
  while(atual != NULL){
    i++;
    if(i>=10)break;
    printf("%d ", atual->chave);
    atual = atual->prox;
  }
  printf("\n");
}

void removerParteDaLista( NO* p2, NO* *ant2){
   NO* aux;

  if(p2 != NULL){
     while (p2 != NULL){
      aux = p2;
       if (p2->prox == NULL) { break;}
      p2 = p2->prox;
      free(aux);
    } 

    free(p2);
  }
  if(*ant2 != NULL)
  (*ant2)->prox = NULL;

  if(*ant2 == NULL) p2 = NULL;
}

void removerCompartilhados(NO* *p1, NO* *p2) {
  NO* auxp1 = *p1;
  NO* auxp2 = *p2;
  NO* auxREPETIDOS;
  NO* ant1 = NULL;
  NO* ant2 = NULL;

int saida=0;

  while (auxp1 && auxp2){
    while (auxp1){   
      if (auxp1 == auxp2){
        
        if(ant1==NULL && ant2== NULL){ 
           removerParteDaLista(*p1, &ant1); 
           *p1 = NULL;
           *p2 = NULL;
         }
        
        else if(ant2==NULL){ 
           removerParteDaLista(*p2, &ant2);
            *p2 = NULL;
            auxp2= NULL;
            ant1->prox = *p1; 
            saida++;
            break;
        }
          
            
           else {
            ant1->prox = NULL;
           
            auxREPETIDOS = auxp2;
            removerParteDaLista(auxREPETIDOS, &ant2);
            }//função auxiliar
        break;
       }
      
      ant1 = auxp1;
      auxp1 = auxp1->prox;
     }
    
    if(saida==1) 
      break;
   if ((auxp1 == auxp2) && (ant1!= NULL)){
     ant1->prox = *p1; 
     ant2->prox = *p2;
     break;
   }

   ant2 = auxp2;
   auxp2 = auxp2->prox;
   auxp1 = (*p1);
 }
  
  if(saida==0) {
    ant1->prox = *p1; 
    ant2->prox = *p2;
  }
}

// por favor nao inclua nenhum codigo a ser entregue abaixo deste ponto

//----------------------------------------------------------------
// use main() apenas para fazer chamadas de teste ao seu programa
//----------------------------------------------------------------
int main() {

  NO* p1 = NULL;
  NO* p2 = NULL;  
  NO* p3 = NULL;//lista compartilhada por NO* p1 e NO* p2

  //a função criar lista não foi usada e não podemos usar implementação estática ou vamos ter trabalho invalidadp

  inserirCh(&p1, 1);
  inserirCh(&p1, 2);
  inserirCh(&p1, 3);

   inserirCh(&p2, 4);
   inserirCh(&p2, 5);
   inserirCh(&p2, 6);

  inserirCh(&p3, 7);
  inserirCh(&p3, 8);
  inserirCh(&p3, 9);

   NO* atual = p1;
  while(atual->prox != NULL){
    atual = atual->prox;
  }
  atual->prox = p3;

 /* atual = p2;
  while(atual->prox != NULL){
    atual = atual->prox;
  }
  atual->prox = p3;*/
  
  
/*
  printf("Lista 1: ");
    imprimeLista(p1);

    printf("Lista 2: ");
    imprimeLista(p2);

    printf("Lista 3: ");
    imprimeLista(p3);
*/
  // aqui vc pode incluir codigo para inserir elementos
  // de teste nas listas p1 e p2

  // o EP sera testado com chamadas deste tipo
  removerCompartilhados(&p1, &p3);

  printf("Lista 1: ");
    imprimeLista(p1);

    printf("Lista 2: ");
    imprimeLista(p3);

  NO* aux = p1;
  NO* p1Inicial= p1;

  
  if(p1 != NULL){
     while (aux != NULL){
      aux = p1;
       if (p1->prox == NULL) { break;}
      p1 = p1->prox;
      free(aux);
      aux=NULL;
    } 

    free(p1);
  }

}