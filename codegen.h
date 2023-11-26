#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <string>
#include <vector>
#include "arbol_sintactico.h"

ofstream archivo;
string nombre_funcion = "";

bool codegen(Nodo* raiz);

void contenido_del_programa(Nodo* nodo);
void declaraciones(Nodo* nodo);
void subprograma_declaraciones(Nodo* nodo);
void instruccion_compuesta(Nodo* nodo);
void instrucciones(Nodo* nodo);
void declaraciones_variables(Nodo* nodo);
void declaraciones_constantes(Nodo* nodo);
void subprograma_encabezado(Nodo* nodo);
void parametros_lista(Nodo* nodo);
void variable_asignacion(Nodo* nodo);
void procedure_instruccion(Nodo* nodo);
void if_instruccion(Nodo* nodo);
void repeticion_instruccion(Nodo* nodo);
void lectura_instruccion(Nodo* nodo);
void escritura_instruccion(Nodo* nodo);
void lista_expresiones(Nodo* nodo);
void expresion(Nodo* nodo);
void variable(Nodo* nodo);
void relop_expresion(Nodo* nodo);
void relop_expresion_simple(Nodo* nodo);
void identar(string ruta);

using namespace std;

void generar(Nodo* raiz, bool warnings) {
    if (warnings) {
        printf("\n");
        printf("*********************************************************************\n");
        printf("*                          - ADVERTENCIA -                          *\n");
        printf("*                                                                   *\n");
        printf("*  El compilador ha encontrado advertencias en el codigo de pascal. *\n");
        printf("*      Si continua, puede que el codigo se genere con errores.      *\n");
        printf("*                 Esta seguro que desea continuar?                  *\n");
        printf("*                                                                   *\n");
        printf("*********************************************************************\n");
        printf("\n");

        printf("(y/n): ");
        char opcion;
        scanf("%c", &opcion);

        if (opcion == 'y' || opcion == 'Y') {
            printf("Generando codigo con warnings . . .\n");
            if (codegen(raiz)) printf("Codigo generado exitosamente. Cerrando compilador.");
            else printf("Error inesperado al generar el codigo. Cerrando compilador");
        }
        else {
            printf("Operacion abortada. Cerrando compilador.\n");
            exit(0);
        }
    } else {
        printf("\nGenerando codigo . . .\n");
        if (codegen(raiz)) printf("Codigo generado exitosamente. Cerrando compilador.\n");
        else printf("Error inesperado al generar el codigo. Cerrando compilador.\n");
    }
}

bool codegen(Nodo* raiz) {
    string nombre_archivo = raiz->hijos[0]->valorCadena + ".cpp";
    string ruta = "Generado/" + nombre_archivo;
    archivo.open(ruta);

    if (!archivo.is_open()) {
        printf("No se pudo abrir el archivo\n");
        return false;
    }

    archivo << "#include <iostream>\n";
    archivo << "#include <string>\n\n";

    archivo << "using namespace std;\n\n";

    contenido_del_programa(raiz->hijos[2]);

    archivo.close();

    identar(ruta);

    return true;
}

void contenido_del_programa(Nodo* nodo) {
    if (nodo->hijos[0]->tipo == "DECLARACIONES_VARIABLES" || nodo->hijos[0]->tipo == "DECLARACIONES_CONSTANTES") {
        declaraciones(nodo->hijos[0]);
    }

    for (Nodo* hijo : nodo->hijos) {
        if (hijo->tipo == "SUBPROGRAMA_DECLARACION") {
            subprograma_declaraciones(hijo);
        }
    }

    archivo << "int main() {\n";
    nombre_funcion = "main";
    bool hay_instrucciones = false;

    for (Nodo* hijo : nodo->hijos) {
        if (hijo->tipo == "INSTRUCCION_COMPUESTA") {
            instruccion_compuesta(hijo);
            hay_instrucciones = true;
        }
    }
    if (!hay_instrucciones) {
        archivo << "return 0;\n";
    }
    archivo << "}\n";
}

void declaraciones(Nodo* nodo) {
    if (nodo->tipo == "DECLARACIONES_VARIABLES") {
        declaraciones_variables(nodo);
    } else if (nodo->tipo == "DECLARACIONES_CONSTANTES") {
        declaraciones_constantes(nodo);
    }
}

void declaraciones_variables(Nodo* padre) {
    string variables = "";
    for (int i = 0; i < padre->hijos.size(); i++) {
        Nodo* nodo = padre->hijos[i];
        if (nodo->hijos[0]->valorCadena != "array") {
            variables += nodo->hijos[0]->valorCadena + " ";
            variables += nodo->valorCadena;
        }
        else {
            variables += nodo->hijos[0]->hijos[2]->valorCadena + " ";
            int tamano = stoi(nodo->hijos[0]->hijos[1]->valorCadena) - stoi(nodo->hijos[0]->hijos[0]->valorCadena);
            variables += nodo->valorCadena + "[" + to_string(tamano) + "]";
        }
        while(nodo->hermano != nullptr) {
            nodo = nodo->hermano;
            variables += ", " + nodo->valorCadena;
            
        }
        variables += ";\n";
    }
    archivo << variables;
    archivo << "\n";
}

void declaraciones_constantes(Nodo* nodo) {
    string constantes = "";
    for (Nodo* hijo : nodo->hijos) {
        constantes += "const ";
        if (hijo->hijos[0]->tipo == "CONSTANTE_ENTERA") {
            constantes += "int ";
            constantes += hijo->valorCadena + " = ";
            constantes += hijo->hijos[0]->hijos[0]->valorCadena;
            if (hijo->hijos[0]->hijos[1] != nullptr) constantes += hijo->hijos[0]->hijos[1]->valorCadena;
            constantes += ";\n";
        }
        else {
            if (hijo->hijos[0]->tipo == "CONSTANTE_REAL")
                constantes += "float ";
            else if (hijo->hijos[0]->tipo == "CADENA_CONST")
                constantes += "string ";
            constantes += hijo->valorCadena + " = ";
            constantes += hijo->hijos[0]->valorCadena + ";\n";
        }
        
        
    }
    archivo << constantes << "\n";
}

void subprograma_declaraciones(Nodo* nodo) {
    while(nodo != nullptr) {
        nombre_funcion = "";
        subprograma_encabezado(nodo->hijos[0]);
        if (nodo->hijos[1]->tipo == "DECLARACIONES_VARIABLES" || nodo->hijos[1]->tipo == "DECLARACIONES_CONSTANTES") {
            declaraciones(nodo->hijos[1]);
            instruccion_compuesta(nodo->hijos[2]);
        }
        else if (nodo->hijos[1]->tipo == "INSTRUCCION_COMPUESTA") {
            instruccion_compuesta(nodo->hijos[1]);
        }
        archivo << "}\n\n";
        nodo = nodo->hermano;
        nombre_funcion = "";
    }
}

void subprograma_encabezado(Nodo* nodo) {
    string encabezado = "";
    if (nodo->valorCadena == "procedure") {
        encabezado += "void ";
    }
    else  {
        for (Nodo* hijo : nodo->hijos) {
            if (hijo->tipo == "ESTANDAR_TIPO") 
                encabezado += nodo->hijos[2]->valorCadena + " ";
        }
    }
    encabezado += nodo->hijos[0]->valorCadena + "(";
    nombre_funcion = nodo->hijos[0]->valorCadena;
    archivo << encabezado;
    for (Nodo* hijo : nodo->hijos) {
            if (hijo->tipo == "PARAMETROS_LISTA") 
                parametros_lista(hijo);
        }
    archivo << ") {\n";
}

void parametros_lista(Nodo* nodo) {
    string parametros = "";
    for (Nodo* hijo : nodo->hijos) {
        parametros += hijo->hijos[0]->valorCadena + " ";
        parametros += hijo->valorCadena + ", ";
    }
    parametros.pop_back();
    parametros.pop_back();
    archivo << parametros;
}

void instruccion_compuesta(Nodo* nodo) {
    instrucciones(nodo->hijos[0]);
}

void instrucciones(Nodo* nodo) {
    while (nodo != nullptr) {
        if (nodo->hijos[0]->tipo == "VARIABLE_ASIGNACION") {
            variable_asignacion(nodo->hijos[0]);
        }
        else if (nodo->hijos[0]->tipo == "PROCEDURE_INSTRUCCION") {
            procedure_instruccion(nodo->hijos[0]);
        }
        else if (nodo->hijos[0]->tipo == "INSTRUCCION_COMPUESTA") {
            instruccion_compuesta(nodo->hijos[0]);
        }
        else if (nodo->hijos[0]->tipo == "IF_INSTRUCCION") {
            if_instruccion(nodo->hijos[0]);
        }
        else if (nodo->hijos[0]->tipo == "REPETICION_INSTRUCCION") {
            repeticion_instruccion(nodo->hijos[0]);
        }
        else if (nodo->hijos[0]->tipo == "LECTURA_INSTRUCCION") {
            lectura_instruccion(nodo->hijos[0]);
        }
        else if (nodo->hijos[0]->tipo == "ESCRITURA_INSTRUCCION") {
            escritura_instruccion(nodo->hijos[0]);
        }
        archivo << "\n";
        nodo = nodo->hermano;
    }
}

void variable_asignacion(Nodo* nodo) {
    if (nodo->hijos[0]->valorCadena != nombre_funcion) {
        variable(nodo);
        archivo << " = ";
    }
    else {
        archivo << "return ";
    }
    expresion(nodo->hijos[1]);
    archivo << ";";
}

void variable(Nodo* nodo) {
    if (nodo->hijos[0]->tipo == "ID")
        archivo << nodo->hijos[0]->valorCadena;
    else {
        archivo << nodo->hijos[0]->hijos[0]->valorCadena << "[";
        expresion(nodo->hijos[0]->hijos[1]);
        archivo << " - 1]";
    }
}

void procedure_instruccion(Nodo* nodo) {
    archivo << nodo->hijos[0]->valorCadena + "(";
    if (nodo->hijos.size() > 1) {
        lista_expresiones(nodo->hijos[1]);
    }
    archivo << ");\n";
}

void if_instruccion(Nodo* nodo) {
    if(nodo->hijos.size() > 2){
        archivo << "if (";
        relop_expresion(nodo->hijos[0]);
        archivo << ") {\n";
        instrucciones(nodo->hijos[1]);
        archivo << "} else " << "{\n";
        instrucciones(nodo->hijos[2]); 
        archivo << "}\n"; 
    }
    else{
        archivo << "if (";
        relop_expresion(nodo->hijos[0]);
        archivo << ") {\n";
        instrucciones(nodo->hijos[1]);
        archivo << "}\n";
    }
}

void relop_expresion(Nodo* nodo){
    if (nodo->tipo == "RELOP_EXPRESION_SIMPLE") {
        relop_expresion_simple(nodo);
    }
    else {
        if (nodo->valorCadena == "||") {
            relop_expresion(nodo->hijos[0]);
            archivo << " || ";
            relop_expresion(nodo->hijos[1]);
        }
        else if (nodo->valorCadena == "&&") {
            relop_expresion(nodo->hijos[0]);
            archivo << " && ";
            relop_expresion(nodo->hijos[1]);
        }
        else if (nodo->valorCadena == "!") {
            archivo << "!";
            relop_expresion(nodo->hijos[0]);
        }
        else if (nodo->valorCadena == "()") {
            archivo << "(";
            relop_expresion(nodo->hijos[0]);
            archivo << ")";
        } else {
            relop_expresion_simple(nodo->hijos[0]);
        }
    }
}

void relop_expresion_simple(Nodo* nodo) {
    expresion(nodo->hijos[0]);
    archivo << " " << nodo->hijos[1]->valorCadena << " ";
    expresion(nodo->hijos[2]);
    
}

void repeticion_instruccion(Nodo* nodo) {
    if (nodo->valorCadena == "while") {
        archivo << "while (";
        relop_expresion(nodo->hijos[0]);
        archivo << ") {\n";
        instrucciones(nodo->hijos[1]);
        archivo << "}\n";
    }
    else {
        archivo << "for (";
        if (nodo->hijos[0]->tipo == "VARIABLE_ASIGNACION") {
            variable_asignacion(nodo->hijos[0]);
            archivo << " ";
            if (nodo->valorCadena == "for++") {
                variable(nodo->hijos[0]);
                archivo << " <= ";
            }
            else {
                variable(nodo->hijos[0]);
                archivo << " >= ";
            }
        }
        else {
            variable(nodo);
            if (nodo->valorCadena == "for++") {
                variable(nodo);
                archivo << " < ";
            }
            else {
                variable(nodo);
                archivo << " > ";
            }
        }
        expresion(nodo->hijos[1]);
        archivo << "; ";
        if (nodo->valorCadena == "for++") {
            if (nodo->hijos[0]->tipo == "VARIABLE_ASIGNACION") {
                variable(nodo->hijos[0]);
                archivo << "++) {\n";
            }
            else {
                variable(nodo);
                archivo << "++) {\n";
            }
        }
        else {
            if (nodo->hijos[0]->tipo == "VARIABLE_ASIGNACION") {
                variable(nodo->hijos[0]);
                archivo << "--) {\n";
            }
            else {
                variable(nodo);
                archivo << "--) {\n";
            }
        }
        instrucciones(nodo->hijos[2]);
        archivo << "}\n";
    }
}

void lectura_instruccion(Nodo* nodo) {
    if (nodo->valorCadena == "read") {
        archivo << "cin >> " + nodo->hijos[0]->valorCadena + ";\n";
    }
    else {
        archivo << "getline(cin, " + nodo->hijos[0]->valorCadena + ");\n";
    }
}

void escritura_instruccion(Nodo* nodo) {
    archivo << "cout << " << nodo->hijos[0]->valorCadena;
    if (nodo->hijos.size() > 1) {
        if (nodo->hijos[1]->tipo == "EXPRESION") {
            archivo << " << ";
            expresion(nodo->hijos[1]);
        }
        else {
            archivo << " << " << nodo->hijos[1]->valorCadena;
        }
    }
    if (nodo->valorCadena == "writeln") {
        archivo << " << \"\\n\"";
    }
    archivo << ";\n";
}

void lista_expresiones(Nodo* nodo) {	
    expresion(nodo);
    while (nodo->hermano != nullptr) {
        nodo = nodo->hermano;
        archivo << ", ";
        expresion(nodo);
    }
}

void expresion(Nodo* nodo) {
    if (nodo->valorCadena == "identificador") {
        archivo << nodo->hijos[0]->valorCadena; 
        
        if (nodo->hijos.size() > 1) {
            archivo << " " << nodo->hijos[1]->valorCadena << " ";
            expresion(nodo->hermano);
        }
    }
    else if (nodo->valorCadena == "arreglo") {
        archivo << nodo->hijos[0]->valorCadena + "[";
        expresion(nodo->hijos[1]);
        archivo << " - 1]";
    }
    else if (nodo->valorCadena == "llamado funciones") {
        archivo << nodo->hijos[0]->valorCadena + "(";
        lista_expresiones(nodo->hijos[1]);
        archivo << ")";
    }
    else if (nodo->valorCadena == "constante entera") {
        if (nodo->hijos[0]->hijos.size() > 1) {
            archivo << nodo->hijos[0]->hijos[0]->valorCadena;
            archivo << nodo->hijos[0]->hijos[1]->valorCadena;
        } else {
            archivo << nodo->hijos[0]->hijos[0]->valorCadena;
        }
    }
    else if (nodo->valorCadena == "constante real") {
        archivo << nodo->hijos[0]->valorCadena;
    }
    else if (nodo->valorCadena == "signo") {
        archivo << nodo->hijos[0]->valorCadena;
        expresion(nodo->hijos[1]);
    }
    else if (nodo->valorCadena == "parentesis") {
        archivo << "(";
        expresion(nodo->hijos[0]);
        archivo << ")";
    }
}

void identar(string ruta) {
    string linea;
    string temp = "Generado/identado.cpp";
    ifstream archivo_lectura(ruta);
    ofstream archivo_escritura(temp);
    int identacion = 0;
    while (getline(archivo_lectura, linea)) {
        if (linea.find("}") != string::npos) {
            identacion--;
        }
        for (int i = 0; i < identacion; i++) {
            archivo_escritura << "    ";
        }
        archivo_escritura << linea << "\n";
        if (linea.find("{") != string::npos) {
            identacion++;
        }
    }
    archivo_lectura.close();
    archivo_escritura.close();
    remove(ruta.c_str());
    rename(temp.c_str(), ruta.c_str());
}