#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>

typedef struct Nodo Nodo;

struct Nodo{
    std::string tipo;
    std::string valorCadena;
    Nodo* hermano;
    std::vector<Nodo*> hijos;
};

Nodo* crearNodo(std::string tipo){
    size_t tamNodo = sizeof(Nodo);
    Nodo* nodo = new Nodo;
    nodo->tipo = tipo;
    nodo->valorCadena = "";
    nodo->hermano = nullptr;
    return nodo;
}

void agregarHijo(Nodo* nodo, Nodo* hijo){
    if(nodo != nullptr){
        nodo->hijos.push_back(hijo);
    }
}

void insertarNodoHijos(Nodo* nodo, Nodo* nodo1 = nullptr, Nodo* nodo2 = nullptr, Nodo* nodo3 = nullptr){
    if (nodo1) agregarHijo(nodo, nodo1);
    if (nodo2) agregarHijo(nodo, nodo2);
    if (nodo3) agregarHijo(nodo, nodo3);
}

void agregarHermano(Nodo* nodo, Nodo* hermano){
    if(nodo != nullptr){
        nodo->hermano = hermano;
    }
}

void limpiarArbol(Nodo* raiz){
    if(raiz != nullptr){
        for(auto hijo: raiz->hijos){
            limpiarArbol(hijo);
        }
        Nodo* hermano = raiz->hermano;
        if(hermano != nullptr){
            raiz->hermano = nullptr;
            limpiarArbol(hermano);
        }
    }
    delete raiz;
}

std::string espacios = "";
bool hermano = false;

void imprimirArbol(Nodo* nodo) {
    if(nodo == nullptr){
        return;
    }

    if(hermano) std::cout << espacios << "H: " << nodo->valorCadena << " " << nodo->tipo << "\n";
    else std::cout << espacios << nodo->valorCadena << " " << nodo->tipo << "\n";

    
    for(const auto&hijo : nodo->hijos){
        espacios += " | ";
        hermano = false;
        imprimirArbol(hijo);
        espacios = espacios.substr(0, espacios.size() - 3);
    }

    if(nodo->hermano != nullptr){
        hermano = true;
        imprimirArbol(nodo->hermano);
        hermano = false;
    }
}

void imprimirArbolFinal(Nodo* nodo) {
    printf("Arbol Sintactico:\n");
    printf("--------------------\n");
    imprimirArbol(nodo);
    printf("--------------------\n");
}