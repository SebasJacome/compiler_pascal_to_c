#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

#define MAX_HIJOS_NODO 3

enum tipoNodo {
    SIN_TIPO, PROGRAMA, CONTENIDO_PROGRAMA, IDENTIFICADOR_LISTA, DECLARACIONES, DECLARACIONES_VARIABLES, 
    DECLARACIONES_CONSTANTES, TIPO, SUBPROGRAMA_DECLARACIONES, SUBPROGRAMA_DECLARACION, SUBPROGRAMA_ENCABEZADO, ARGUMENTOS, 
    PARAMETROS, PARAMETROS_LISTA, INSTRUCCION_COMPUESTA, INSTRUCCIONES_OPCIONALES, INSTRUCCIONES_LISTA, INSTRUCCIONES, 
    REPETICION_INSTRUCCION, LECTURA_INSTRUCCION, ESCRITURA_INSTRUCCION, IF_INSTRUCCION, INSTRUCCION_ELSE, VARIABLE_ASIGNACION, 
    FOR_ASIGNACION, VARIABLE, PROCEDURE_INSTRUCCION, RELOP_EXPRESION, RELOP_AND, RELOP_NOT, 
    RELOP_PAREN, RELOP_EXPRESION_SIMPLE, EXPRESION_LISTA, EXPRESION, TERMINO, LLAMADO_FUNCION, 
    FACTOR, CONSTANTE_ENTERA, CONSTANTE_REAL, ID, RELOP, ADDOP, 
    MULOP, ESTANDAR_TIPO, FOR_COMPORTAMIENTO, SIGNO
};

std::string tipoTexto(tipoNodo tipo);

typedef struct Nodo Nodo;

struct Nodo{   
    tipoNodo tipo;
    Nodo* padre;
    Nodo* hermano;
    Nodo* hijo[MAX_HIJOS_NODO];
    union
    {
        int valorEntero;
        double valorReal;
        char* valorCadena;
    } atributos;
};

Nodo* crearNodo() {
    Nodo* temp = (struct Nodo*)malloc(sizeof(Nodo*));
    temp->tipo = SIN_TIPO;
    temp->atributos.valorCadena = NULL;
    temp->padre = NULL;
    temp->hermano = NULL;
    temp->hijo[0] = NULL;
    temp->hijo[1] = NULL;
    temp->hijo[2] = NULL;
    
    return temp;
}

Nodo* iniciarNodo(Nodo* temp) {
    temp->tipo = SIN_TIPO;
    temp->atributos.valorCadena = NULL;
    temp->padre = NULL;
    temp->hermano = NULL;
    temp->hijo[0] = NULL;
    temp->hijo[1] = NULL;
    temp->hijo[2] = NULL;
    
    return temp;
}

void insertarNodoHijos(Nodo* nodo, Nodo* nodoHijo1, Nodo* nodoHijo2, Nodo* nodoHijo3) {
    if (nodoHijo1) nodo->hijo[0] = nodoHijo1;
    if (nodoHijo2) nodo->hijo[1] = nodoHijo2;
    if (nodoHijo3) nodo->hijo[2] = nodoHijo3;   
}

void insertarNodoHermano(Nodo* nodo, Nodo* nodoHermano) {
    nodo->hermano = nodoHermano;
}

int contador = 0;

void imprimirArbol(Nodo* nodo){
    printf("Nodo: %d\n", contador++);
    Nodo* temp;
    if(nodo){
        temp = nodo;
        printf("Nodo de tipo: %s\n", tipoTexto(temp->tipo).c_str());
        for(size_t i = 0; i < MAX_HIJOS_NODO; i++){
                if(temp->hijo[i] != NULL){ 
                    imprimirArbol(temp->hijo[i]);
                }
        }
    }
    
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
        case DECLARACIONES:
            return "DECLARACIONES";
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
        case INSTRUCCION_COMPUESTA:
            return "INSTRUCCION_COMPUESTA";
        case INSTRUCCIONES_OPCIONALES:
            return "INSTRUCCIONES_OPCIONALES";
        case INSTRUCCIONES_LISTA:
            return "INSTRUCCIONES_LISTA";
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
        case INSTRUCCION_ELSE:
            return "INSTRUCCION_ELSE";
        case VARIABLE_ASIGNACION:
            return "VARIABLE_ASIGNACION";
        case FOR_ASIGNACION:
            return "FOR_ASIGNACION";
        case VARIABLE:
            return "VARIABLE";
        case PROCEDURE_INSTRUCCION:
            return "PROCEDURE_INSTRUCCION";
        case RELOP_EXPRESION:
            return "RELOP_EXPRESION";
        case RELOP_AND:
            return "RELOP_AND";
        case RELOP_NOT:
            return "RELOP_NOT";
        case RELOP_PAREN:
            return "RELOP_PAREN";
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
        default:
            return "ERROR";
    }
}