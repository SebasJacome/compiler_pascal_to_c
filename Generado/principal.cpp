#include <iostream>
#include <string>

using namespace std;

int a, b, c, d;

int Add(int a, int b) {
    return a + b;
}

int Mult(int c, int a) {
    return c * a;
}

void multadd() {
    c = Add(a, b);
    d = Mult(c, a);
}

int main() {
    a = 5;
    b = 3;
    multadd();
    
    while ((a > b)) {
        b = b + 1;
    }
    
    cout << c << "\n";
    
    cout << d << "\n";
    
}
