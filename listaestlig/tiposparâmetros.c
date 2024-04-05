#include <stdio.h>
#include <stdlib.h>

//passagem de parâmetros

void imprimir(int x){//por valor
    printf("%d", x);
    x++;
}

void incrementar(int* x){//por referência
    *x = *x + 1;
}

int main(){
    int x = 0;
    imprimir(x);
    incrementar(&x);
    printf("%d", x);

    return 0;
}