#include <stdio.h>
#include <stdlib.h>
#include "imprimirLista.h"
#include "ListaContigua.h"

int main(){
    ListaContigua lista;
    printf("Nueva lista creada: \n");
    constructor(&lista);
    imprimirLista(lista);
    printf("Rellenando ListaContigua:\n");
    for(int i = 0 ; i < 12 ; i++){
        insertarElemento(&lista, i);
        imprimirLista(lista);
    }
    //Formas de imprimir elemento de una posicion concreta:
    // Metodo 1:
    printf("Elemento 0: %d\n", elementoPosicion(lista, 0));
    printf("Elemento 11: %d\n", elementoPosicion(lista, 11));

    // Metodo 2: (creando una nueva funcion que unicamente imprime el elemento de una posicion dada como parametro)
    imprimirElementoLista(lista, 0);
    imprimirElementoLista(lista, 11);
    
    printf("Cambio elemento 4 por 50. Nueva ListaContigua:\n");
    modificarElemento(&lista, 4, 50);
    imprimirLista(lista);

    for(int i = 0; i < 4; i++){
        printf("Borramos el ultimo elemento. Nueva ListaContigua:\n");
        eliminarUltimoElemento(&lista);
        imprimirLista(lista);
    }
    
    for(int i = 100; i < 104; i++){
        printf("Insertamos %d al final. Nueva ListaContigua:\n", i);
        insertarElemento(&lista, i);
        imprimirLista(lista);
    }
    return 0;
}