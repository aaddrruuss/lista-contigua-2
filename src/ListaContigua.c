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
    insertarElemento(lista, lista->n, elemento);
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
    eliminar(lista, lista->n);
}

void eliminar(ListaContigua *lista, int posicion){
    if (posicion < 0 || posicion > lista->n){
        printf("Posicion no valida");
        return;
    }
    int i;
    for(i = posicion; i < lista->n; i++){
        lista->array[i] = lista->array[i+1];
    }
    lista->n -= 1;
    if((lista->capacidad - lista->n) >= 2*INCREMENTO){
        ampliarCapacidad(lista, -INCREMENTO);
        return;
    }
}

void concatenar(ListaContigua *lista1, ListaContigua *lista2){
    ampliarCapacidad(lista1, lista2->capacidad);
    int temp = lista1->n;
    lista1->n += lista2->n;
    int temp2 = 0;
    for(int i = temp; i<lista1->n; i++){
        lista1->array[i] = lista2->array[temp2];
        temp2 += 1;
    }
}

int buscar(ListaContigua lista, int elemento){
    int i;
    for(i = 0; i < lista.n; i++){
        if(lista.array[i] == elemento){
            return i;
        }
    }
    return -1;
}