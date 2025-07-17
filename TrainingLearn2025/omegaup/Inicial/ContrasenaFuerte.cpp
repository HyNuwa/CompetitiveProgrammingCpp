#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool esContraseñaFuerte(const string& contraseña) {
    int n = contraseña.length();
    
    // Verificar longitud mínima de 12 caracteres
    if (n < 12) {
        return false;
    }
    
    // Contadores para diferentes tipos de caracteres
    bool tieneVocal = false;
    bool tieneNumero = false;
    
    // Verificar presencia de vocal y número
    for (char c : contraseña) {
        // Verificar vocales (mayúsculas y minúsculas)
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            tieneVocal = true;
        }
        
        // Verificar números
        if (isdigit(c)) {
            tieneNumero = true;
        }
    }
    
    // Si no tiene vocal o número, no es fuerte
    if (!tieneVocal || !tieneNumero) {
        return false;
    }
    
    // Verificar que no tenga dos o más caracteres consecutivos iguales
    for (int i = 0; i < n - 1; i++) {
        if (contraseña[i] == contraseña[i + 1]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int N;
    cin >> N;
    
        string contraseña;
        cin >> contraseña;
        
        if (esContraseñaFuerte(contraseña)) {
            cout << "FUERTE" << endl;
        } else {
            cout << "DEBIL" << endl;
        }
    
    
    return 0;
}