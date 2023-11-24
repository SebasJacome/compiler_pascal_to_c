#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <string>
#include <vector>
#include "arbol_sintactico.h"

bool codegen(Nodo* raiz);

using namespace std;

void generar(Nodo* raiz, bool warnings) {
    if (warnings) {
        printf("*********************************************************************\n");
        printf("*                          - ADVERTENCIA -                          *\n");
        printf("*                                                                   *\n");
        printf("*  El compilador ha encontrado advertencias en el codigo de pascal. *\n");
        printf("*      Si continua, puede que el codigo se genere con errores.      *\n");
        printf("*                 Esta seguro que desea continuar?                  *\n");
        printf("*                                                                   *\n");
        printf("*********************************************************************\n");

        printf("(y/n): ");
        char opcion;
        scanf("%c", &opcion);

        if (opcion == 'y' || opcion == 'Y') {
            printf("Generando codigo con warnings . . .\n");
            if (codegen(raiz)) printf("Codigo generado exitosamente. Cerrando compilador.");
            else printf("Error inesperado al generar el codigo. Cerrando compilador");
        }
        else {
            printf("Operacion abortada. Cerrando compilador");
            exit(0);
        }
    } else {
        printf("Generando codigo . . .\n");
        if (codegen(raiz)) printf("Codigo generado exitosamente. Cerrando compilador.");
        else printf("Error inesperado al generar el codigo. Cerrando compilador");
    }
}

bool codegen(Nodo* raiz) {
    ofstream archivo;

    string nombre_archivo = raiz->hijos[0]->valorCadena + ".c";
    archivo.open(nombre_archivo.c_str());

    if (!archivo.is_open()) {
        printf("No se pudo abrir el archivo\n");
        return false;
    }

    archivo << "#include <stdio.h>\n";
    archivo << "#include <stdlib.h>\n";
    archivo << "int main() {\n";
    archivo << "\tprintf(\"Hello World!\");\n";
    archivo << "\treturn 0;\n";
    archivo << "}\n";

    archivo.close();

    return true;
}
