#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>

#define MAX_HIJOS_NODO 3

enum tipoNodo {
    SIN_TIPO, PROGRAMA, CONTENIDO_PROGRAMA, IDENTIFICADOR_LISTA, DECLARACIONES_VARIABLES, 
    DECLARACIONES_CONSTANTES, TIPO, SUBPROGRAMA_DECLARACIONES, SUBPROGRAMA_DECLARACION, SUBPROGRAMA_ENCABEZADO, ARGUMENTOS, 
    PARAMETROS, PARAMETROS_LISTA, INSTRUCCIONES_LISTA, NUMERO,
    REPETICION_INSTRUCCION, LECTURA_INSTRUCCION, ESCRITURA_INSTRUCCION, IF_INSTRUCCION, VARIABLE_ASIGNACION, 
    VARIABLE, PROCEDURE_INSTRUCCION, RELOP_EXPRESION, RELOP_AND, CADENA_CONST,
    RELOP_EXPRESION_SIMPLE, EXPRESION_LISTA, EXPRESION, TERMINO, LLAMADO_FUNCION, 
    FACTOR, CONSTANTE_ENTERA, CONSTANTE_REAL, ID, RELOP, ADDOP, 
    MULOP, ESTANDAR_TIPO, FOR_COMPORTAMIENTO, SIGNO
};

std::string tipoTexto(tipoNodo tipo);

typedef struct Nodo Nodo;

struct Nodo {
    tipoNodo tipo;
    // Nodo* hermano;
    std::vector<Nodo*> hijos;
    std::string valorCadena;

    Nodo(tipoNodo t) : tipo(t), hijos(MAX_HIJOS_NODO, nullptr) {}

    ~Nodo() {
        for (auto hijo : hijos) {
            delete hijo;
        }
    }
};

Nodo* crearNodo(tipoNodo tipo) {
    return new Nodo(tipo);
}

void insertarNodoHijos(Nodo* nodo, Nodo* nodoHijo1 = NULL, Nodo* nodoHijo2 = NULL, Nodo* nodoHijo3 = NULL) {
    if (nodoHijo1) nodo->hijos[0] = nodoHijo1;
    if (nodoHijo2) nodo->hijos[1] = nodoHijo2;
    if (nodoHijo3) nodo->hijos[2] = nodoHijo3;   
}

void eliminarArbol(Nodo* nodo) {
    delete nodo;
}

int contador = 0;
std::string espacios = "";

void imprimirArbol(Nodo* nodo){
    Nodo* temp;
    if(nodo){
        temp = nodo;
        printf("%s%s, ",espacios.c_str(), tipoTexto(temp->tipo).c_str());
        if (temp->valorCadena != "") {
            printf("Valor: %s", temp->valorCadena.c_str());
        }
        printf("\n");
        for(size_t i = 0; i < MAX_HIJOS_NODO; i++){
            if(temp->hijos[i] != NULL){ 
                espacios += " | ";
                imprimirArbol(temp->hijos[i]);
            }
        }
    }
    espacios = espacios.substr(0, espacios.length() - 3);
}



std::string tipoTexto(tipoNodo tipo) {
    switch(tipo) {
        case SIN_TIPO:
            return "SIN_TIPO";
        case PROGRAMA:
            return "PROGRAMA";
        case CONTENIDO_PROGRAMA:
            return "CONTENIDO_PROGRAMA";
        case IDENTIFICADOR_LISTA:
            return "IDENTIFICADOR_LISTA";
        case DECLARACIONES_VARIABLES:
            return "DECLARACIONES_VARIABLES";
        case DECLARACIONES_CONSTANTES:
            return "DECLARACIONES_CONSTANTES";
        case TIPO:
            return "TIPO";
        case SUBPROGRAMA_DECLARACIONES:
            return "SUBPROGRAMA_DECLARACIONES";
        case SUBPROGRAMA_DECLARACION:
            return "SUBPROGRAMA_DECLARACION";
        case SUBPROGRAMA_ENCABEZADO:
            return "SUBPROGRAMA_ENCABEZADO";
        case ARGUMENTOS:
            return "ARGUMENTOS";
        case PARAMETROS:
            return "PARAMETROS";
        case PARAMETROS_LISTA:
            return "PARAMETROS_LISTA";
        case INSTRUCCIONES_LISTA:
            return "INSTRUCCIONES_LISTA";
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
        case RELOP_EXPRESION:
            return "RELOP_EXPRESION";
        case RELOP_AND:
            return "RELOP_AND";
        case RELOP_EXPRESION_SIMPLE:
            return "RELOP_EXPRESION_SIMPLE";
        case EXPRESION_LISTA:
            return "EXPRESION_LISTA";
        case EXPRESION:
            return "EXPRESION";
        case TERMINO:
            return "TERMINO";
        case LLAMADO_FUNCION:
            return "LLAMADO_FUNCION";
        case FACTOR:
            return "FACTOR";
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
        case FOR_COMPORTAMIENTO:
            return "FOR_COMPORTAMIENTO";
        case SIGNO:
            return "SIGNO";
        case NUMERO:
            return "NUMERO";
        default:
            return "ERROR: TIPO: " + std::to_string(tipo);
    }
}