/* 
Dado um vetor V, retornar:
1 = se for crescente
-1 = se for decrescente
0 = se não tiver ordem
9 = se for único número
*/

#include <stdio.h>
#include <stdbool.h>

int ordem(int v[], int n){
    bool aumentou = false;
    bool diminuiu = false;
    int i; 

    for(i = 0; i < n; i++){
        if(v[i] < v[i+1]) aumentou = true;
        if(v[i] > v[i+1]) diminuiu = true;
        if(aumentou && diminuiu) return (0); //sem ordem
    }

    if(aumentou)return (1);
    if(diminuiu)return (-1);
    return(9); //constante
}

int main(){

    int v[]= {0, 1, 2, 3, 4};
    int n = 5;

    int resposta = ordem(v, n);

    printf("%d", resposta);

    return 0;
}