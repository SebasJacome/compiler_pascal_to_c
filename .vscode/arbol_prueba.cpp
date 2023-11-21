#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HIJOS_NODO 2

typedef struct Nodo Nodo;

struct Nodo{
    int valor;
    Nodo* padre;
    Nodo* hijo[2];
};

Nodo *nuevoNodo(int valor){
    size_t tamNodo = sizeof(Nodo);
    struct Nodo* nodo = (Nodo*)malloc(tamNodo);
    nodo->valor = valor;
    nodo->hijo[0] = NULL;
    nodo->hijo[1] = NULL;
    return nodo;
}


void insertarNodo(struct Nodo *nodo, int valor) {
    for(size_t i = 0; i < MAX_HIJOS_NODO; i++){
        if(nodo->hijo[i] == NULL){
            nodo->hijo[i] = nuevoNodo(valor);
            return;
        }
    }
    insertarNodo(nodo->hijo[0], valor);
}

void imprimirArbol(Nodo* nodo) {
    Nodo* temp;
    if(nodo){
        temp = nodo;
        printf("Nodo: %d\n", temp->valor);
        for(size_t i = 0; i < MAX_HIJOS_NODO; i++){
                imprimirArbol(temp->hijo[i]);
        }
    }
    
}

int main(){

    Nodo* raiz = nuevoNodo(1);
    insertarNodo(raiz, 2);
    insertarNodo(raiz, 3);
    insertarNodo(raiz, 4);
    insertarNodo(raiz, 5);
    insertarNodo(raiz, 6);
    insertarNodo(raiz, 7);
    insertarNodo(raiz, 8);
    insertarNodo(raiz, 9);
    insertarNodo(raiz, 10);
    insertarNodo(raiz, 11);
    insertarNodo(raiz, 12);
    insertarNodo(raiz, 13);
    imprimirArbol(raiz);

    return 0;
}

