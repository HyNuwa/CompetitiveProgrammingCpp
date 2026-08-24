#include<iostream>
#include<vector>

/* 
#include<algorithm>
sort(v.begin(), v.end(), [](const auto &a, const auto &b) {
    return a > b;
    });

Tú no llamas a la función lambda; std::sort la llama cientos de veces por dentro mientras ordena.
Imagina que std::sort es un organizador de una fila:
  1. sort toma dos elementos cualquiera de tu vector (por ejemplo, el de la posición 0 y el de la posición 4).
  2. Como sort no sabe cuál es tu criterio, te los muestra llamando a tu lambda:
  ¿TuLambda(elemento_A, elemento_B)?
  3. Tu lambda evalúa la condición y le contesta a sort:
      • Si contestas true: sort acomoda a elemento_A a la izquierda de elemento_B.
      • Si contestas false: sort acomoda a elemento_B a la izquierda.

    
    ! Búsqueda binaria

template <typename T>
int busquedaBinaria(vector<T> v, T x) {
    int inicio = 0;
    int fin = v.size() - 1;

    while (inicio <= fin) {
        int medio = (inicio + fin) / 2;

        if (v[medio] == x)
            return medio;

        if (v[medio] < x)
            inicio = medio + 1;
        else
            fin = medio - 1;
    }

    return -1;
}
 */

using namespace std;

long longfactorialI(int n){
    long long res = 1;
    for(int i = 2; i <= n; i++)
        res *= i;
    
    return res;
}

// Viable hasta n <= 60
long long combinatoria(int n, int k) {
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;
    if (k > n - k) k = n - k; // Simetría de la combinatoria
    
    long long res = 1;
    for (int i = 1; i <= k; ++i) {
        res = res * (n - k + i) / i;
    }
    return res;
}

//>>>>>> PARA VECTOREEEEEEEEEEEEEEEEEEEEEEES

template <typename T>
void showVector(vector<T>& v, string nombre = ""){
    cout << endl;
    cout << "Vector" << nombre << ": ";
    for(T elem: v) cout << elem << " ";
    cout << endl;
}

template<typename T>
void enterVector1(vector<T>& v, int n){
    for(int i = 0; i < n; i++){
        cin >>  v[i];
        
        if(cin.peek() == '\n') break;
    }
}

template<typename T>
void enterVector2(vector<T>& v){
    T elem;
    while(true){
        cin >>  elem;
        v.push_back(elem);
        if(cin.peek() == '\n') break;
    }
}

// + CARACTERES
#include<cctype>

bool isVocal(char a){
    char b = tolower(a);
    return b == 'a' || b == 'e' || b == 'i' || b == 'o' || b == 'u';
}

template <class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main (){
    
    return 0;
}