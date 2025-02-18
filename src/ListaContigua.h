#ifndef LISTA_CONTIGUA_H
#define LISTA_CONTIGUA_H

typedef struct {
    int *array;
    int capacidad;
    int n;
}ListaContigua;

void constructor(ListaContigua *lista);

void destructor(ListaContigua *lista);

int isLlena(ListaContigua lista);

int elementoPosicion(ListaContigua lista, int posicion);

void modificarElemento(ListaContigua *lista, int posicion, int nuevoValor);

void ampliarCapacidad(ListaContigua *lista, int nuevaCapacidad);

void insertarElementoFinal(ListaContigua *lista, int elemento);

void insertarElemento(ListaContigua *lista, int posicion, int elemento);

void eliminarUltimoElemento(ListaContigua *lista);

void eliminar(ListaContigua *lista, int posicion);

void concatenar(ListaContigua *lista1, ListaContigua *lista2);

int buscar(ListaContigua lista, int elemento);

#endif // LISTA_CONTIGUA_H