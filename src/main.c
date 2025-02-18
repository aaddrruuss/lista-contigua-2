#include <stdio.h>
#include <stdlib.h>
#include "imprimirLista.h"
#include "ListaContigua.h"

int main(){
    ListaContigua lista1;

    printf("\n1.\n");
    constructor(&lista1);
    imprimirLista(lista1);

    printf("\n2.\n");
    int i;
    for(i=0;i<11;i++){
        insertarElemento(&lista1, lista1.n, i);
        imprimirLista(lista1);
    }

    printf("\n3.\n");
    int temp = 100;
    for(i=0;i<5;i++){
        insertarElemento(&lista1, 0, temp);
        imprimirLista(lista1);
        temp += 1;
    }
    
    printf("\n4.\n");
    insertarElemento(&lista1, 3, 200);
    imprimirLista(lista1);

    printf("\n5.\n");
    temp = 5;
    for(i = lista1.n; i>(lista1.n) - temp; i--){
        eliminar(&lista1, i);
        imprimirLista(lista1);
        temp -= 1;
    }

    printf("\n6.\n");
    temp = 5;
    while(temp != 0){
        eliminar(&lista1, 0);
        imprimirLista(lista1);
        temp -= 1;
    }

    printf("\n7.\n");
    int posicion100 = buscar(lista1, 100);
    printf("El 100 esta en la pocision: [%d]", posicion100);

    printf("\n8.\n");
    int posicion2 = buscar(lista1, 2);
    printf("El elemento 2 esta en la posicion: [%d]", posicion2);
    
    printf("\n9.\n");
    int posicion5 = buscar(lista1, 5);
    printf("El elemento 5 esta en el posicion: [%d]", posicion5);

    printf("\n10.\n");
    int posicion20 = buscar(lista1, 20);
    printf("El elemento 5 esta en el posicion: [%d]", posicion20);

    printf("\n11.\n");
    ListaContigua lista2;
    constructor(&lista2);
    i = 500;
    while(i < 506){
        insertarElementoFinal(&lista2, i);
        i += 1;
    }
    imprimirLista(lista2);

    printf("\n12.\n");
    concatenar(&lista1, &lista2);
    imprimirLista(lista1);
}