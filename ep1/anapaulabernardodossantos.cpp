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