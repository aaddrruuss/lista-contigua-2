#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ListaContigua.h"

#define INCREMENTO 2

void constructor(ListaContigua *lista){
    lista->n = 0;
    lista->array = NULL;
    lista->capacidad = 0;
}

void destructor(ListaContigua *lista){
    free(lista->array);
    lista->array = NULL;
    lista->capacidad = 0,
    lista->n = 0;    
}

int isLlena(ListaContigua lista){
    return lista.capacidad == lista.n;
}

int elementoPosicion(ListaContigua lista, int posicion){
    if(posicion < 0 || posicion >= lista.n){
        printf("Valor de la posicion no valido\n");
        return -1;
    }
    return lista.array[posicion];
}

void modificarElemento(ListaContigua *lista, int posicion, int nuevoValor){
    if(posicion>=0 && posicion<(lista->n)){
        lista->array[posicion] = nuevoValor;
        return;
    }
    printf("Posicion no valida");
}

void ampliarCapacidad(ListaContigua *lista, int nuevaCapacidad){
    if (lista->capacidad + nuevaCapacidad < 0){
        return;
    }
    lista->capacidad += nuevaCapacidad;
    lista->array = (int*)realloc(lista->array, lista->capacidad * sizeof(int));
    if (!lista->array){
        printf("Error al reservar memoria");
        exit(1);
    }
}

void insertarElementoFinal(ListaContigua *lista, int elemento){
    if(lista->n != lista->capacidad){
        lista->array[lista->n] = elemento;
        lista->n++;
        return;
    }
    ampliarCapacidad(lista, INCREMENTO);
    lista->array[lista->n] = elemento;
    lista->n++;
}

void insertarElemento(ListaContigua *lista, int posicion, int elemento){
    if (posicion < 0 || posicion > lista->n){
        printf("Posicion no valida");
        return;
    }
    
    if (lista->n == lista->capacidad){
        ampliarCapacidad(lista, INCREMENTO);
    }

    lista->n += 1;
    for (int i = lista->n; i > posicion; i--){
        lista->array[i] = lista->array[i-1];
    }
    lista->array[posicion] = elemento;
}

void eliminarUltimoElemento(ListaContigua *lista){
    if(lista->n == 0){
        printf("La lista esta vacia");
        return;
    }

    lista->n--;

    if((lista->capacidad - lista->n) >= 2*INCREMENTO){
        ampliarCapacidad(lista, -INCREMENTO);
        return;
    }
}