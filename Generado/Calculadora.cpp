#include <iostream>
#include <string>

using namespace std;

int opcion;
float num1, num2, resultado;

float Suma(float a, float b) {
    return a + b;
}

float Rest(float a, float b) {
    return a - b;
}

float Mult(float a, float b) {
    return a * b;
}

float Divi(float a, float b) {
    return a / b;
}

float Pote(float a, float b) {
    float acum;
    int i;
    
    acum = 1;
    for (i = 1; i <= b; i++) {
        acum = acum * a;
    }
    
    return acum;
}

void leerRespuesta() {
    cout << "Elija su opcion deseada: ";
    
    cin >> opcion;
    
}

void menu() {
    cout << "\n(1): Sumar" << "\n";
    
    cout << "(2): Restar" << "\n";
    
    cout << "(3): Multiplicar" << "\n";
    
    cout << "(4): Dividir" << "\n";
    
    cout << "(5): Potencia" << "\n";
    
    cout << "(6): Salir" << "\n";
    
}

void leerNumeros() {
    cout << "Escriba el primer numero: ";
    
    cin >> num1;
    
    cout << "Escriba el segundo numero: ";
    
    cin >> num2;
    
}

void realizaOperacion() {
    leerNumeros();
    
    if (opcion == 1) {
        resultado = Suma(num1, num2);
    }
    
    if (opcion == 2) {
        resultado = Rest(num1, num2);
    }
    
    if (opcion == 3) {
        resultado = Mult(num1, num2);
    }
    
    if (opcion == 4) {
        resultado = Divi(num1, num2);
    }
    
    if (opcion == 5) {
        resultado = Pote(num1, num2);
    }
    
}

int main() {
    opcion = 1;
    while (opcion < 6 && opcion > 0) {
        menu();
        
        leerRespuesta();
        
        if (opcion < 6 && opcion > 0) {
            realizaOperacion();
            
            cout << "Resultado: " << resultado << "\n";
            
            
        } else {
            cout << "Saliendo del programa" << "\n";
            
        }
        
        
    }
    
}
