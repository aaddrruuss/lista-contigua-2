#include <stdio.h>
#include "imprimirLista.h"

void imprimirLista(ListaContigua lista){
    printf("n = %d | Max = %d | ListaContigua: ", lista.n, lista.capacidad);
    if(lista.n!=0){
        for(int i=0;i<lista.n;i++){
            printf("%d ", lista.array[i]);
        }
    }else{
        printf("NULL");
    }
    printf("\n");
}

void imprimirElementoLista(ListaContigua lista, int elemento){
    printf("Elemento %d = %d\n", elemento, lista.array[elemento]);
}