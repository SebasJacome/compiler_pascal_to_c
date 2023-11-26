#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>

#define MAX_HIJOS_NODO 3

enum tipoNodo {
    SIN_TIPO, PROGRAMA, CONTENIDO_PROGRAMA, DECLARACIONES_VARIABLES, INSTRUCCION_COMPUESTA, DECLARACIONES_CONSTANTES,
    SUBPROGRAMA_DECLARACION, SUBPROGRAMA_ENCABEZADO, PARAMETROS_LISTA, NUMERO, INSTRUCCIONES,
    REPETICION_INSTRUCCION, LECTURA_INSTRUCCION, ESCRITURA_INSTRUCCION, IF_INSTRUCCION, VARIABLE_ASIGNACION, 
    VARIABLE, PROCEDURE_INSTRUCCION, CADENA_CONST, RELOP_EXPRESION_SIMPLE, LLAMADO_FUNCION, EXPRESION, 
    CONSTANTE_ENTERA, CONSTANTE_REAL, ID, RELOP, ADDOP, MULOP, ESTANDAR_TIPO, SIGNO, RELOP_EXPRESION
};

std::string tipoTexto(tipoNodo tipo);

typedef struct Nodo Nodo;

struct Nodo{
    std::string tipo;
    std::string valorCadena;
    Nodo* hermano;
    std::vector<Nodo*> hijos;
};

Nodo* crearNodo(tipoNodo tipo){
    size_t tamNodo = sizeof(Nodo);
    Nodo* nodo = new Nodo;
    nodo->tipo = tipoTexto(tipo);
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

std::string tipoTexto(tipoNodo tipo) {
    switch(tipo) {
        case SIN_TIPO:
            return "SIN_TIPO";
        case PROGRAMA:
            return "PROGRAMA";
        case CONTENIDO_PROGRAMA:
            return "CONTENIDO_PROGRAMA";
        case DECLARACIONES_VARIABLES:
            return "DECLARACIONES_VARIABLES";
        case INSTRUCCION_COMPUESTA:
            return "INSTRUCCION_COMPUESTA";
        case DECLARACIONES_CONSTANTES:
            return "DECLARACIONES_CONSTANTES";
        case SUBPROGRAMA_DECLARACION:
            return "SUBPROGRAMA_DECLARACION";
        case SUBPROGRAMA_ENCABEZADO:
            return "SUBPROGRAMA_ENCABEZADO";
        case PARAMETROS_LISTA:
            return "PARAMETROS_LISTA";
        case INSTRUCCIONES:
            return "INSTRUCCIONES";
        case REPETICION_INSTRUCCION:
            return "REPETICION_INSTRUCCION";
        case LECTURA_INSTRUCCION:
            return "LECTURA_INSTRUCCION";
        case ESCRITURA_INSTRUCCION:
            return "ESCRITURA_INSTRUCCION";
        case IF_INSTRUCCION:
            return "IF_INSTRUCCION";
        case VARIABLE_ASIGNACION:
            return "VARIABLE_ASIGNACION";
        case VARIABLE:
            return "VARIABLE";
        case PROCEDURE_INSTRUCCION:
            return "PROCEDURE_INSTRUCCION";
        case RELOP_EXPRESION_SIMPLE:
            return "RELOP_EXPRESION_SIMPLE";
        case LLAMADO_FUNCION:
            return "LLAMADO_FUNCION";
        case EXPRESION:
            return "EXPRESION";
        case CONSTANTE_ENTERA:
            return "CONSTANTE_ENTERA";
        case CONSTANTE_REAL:
            return "CONSTANTE_REAL";
        case ID:
            return "ID";
        case RELOP:
            return "RELOP";
        case ADDOP:
            return "ADDOP";
        case MULOP:
            return "MULOP";
        case ESTANDAR_TIPO:
            return "ESTANDAR_TIPO";
        case SIGNO:
            return "SIGNO";
        case NUMERO:
            return "NUMERO";
        case CADENA_CONST:
            return "CADENA_CONST";
        case RELOP_EXPRESION:
            return "RELOP_EXPRESION";
        default:
            return "ERROR: TIPO: " + std::to_string(tipo);
    }
}