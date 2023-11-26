#include <iostream>
#include <string>

using namespace std;

int n[10];
int i, j;

int main() {
    for (i = 1; i <= 10; i++) {
        n[i - 1] = i + 100;
    }
    
    for (j = 1; j <= 10; j++) {
        cout << "Element[" << j;
        
        cout << "] = " << n[j - 1] << "\n";
        
        
    }
    
}
