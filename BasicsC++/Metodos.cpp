#include <iostream>
#include <random>
#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(1); cin.tie(0); cout.tie(0);
    
    //SWAP() (INTERCAMBIA VALORES DE UN ARRAY)
    //INTERNAMENTE HACEA ASI:
    /* int temp = arr[j];
    arr[j] = arr[j + 1];
    arr[j + 1] = temp; */

    //uniform_int_distribution<int> dist(1, n); // Genera un número aleatorio entre 1 y n(elegida por usuario o depende del contexto)
    //int aleatorio = dist(rng); // Genera un número aleatorio entre 1 y n
    //Forma compacta de hacerlo:
    //int aleatorio = uniform_int_distribution<int>(1, n)(rng); // Genera un número aleatorio entre 1 y n
    //double aleatorio = uniform_real_distribution<double>(1, n)(rng); // Genera un número aleatorio entre 1 y n (con decimales)


    //cout<<fixed<<setprecision(10); // Para mostrar números con precisión de 10 decimales 

    //VECTORES
    std::vector<int> numeros = {10, 20, 30};
    int primerElemento = numeros[0]; // primerElemento = 10
    int segundoElemento = numeros[1]; // segundoElemento = 20
    // numeros[3] = 40; // ¡Error si el vector solo tiene 3 elementos!

    // Lectura de N elementos en un vector
    int N;
    std::cin >> N;

    std::vector<int> numeros;
    numeros.reserve(N); // Opcional: reservar espacio para evitar reasignaciones

    for (int i = 0; i < N; ++i) {
        int x;
        std::cin >> x;
        numeros.push_back(x);
    }

    // Ordenar el vector
    std::sort(numeros.begin(), numeros.end());

    // Imprimir los elementos (sin el último)
    for (size_t i = 0; i < numeros.size() - 1; ++i) {
        std::cout << numeros[i] << " ";
    }
    // Imprimir el último elemento y un salto de línea
    if (!numeros.empty()) {
        std::cout << numeros.back() << std::endl;
    }

    // Buscar un elemento
    int valorABuscar = 20;
    bool encontrado = false;
    for (int num : numeros) {
        if (num == valorABuscar) {
            encontrado = true;
            break;
        }
    }
    if (encontrado) {
        std::cout << valorABuscar << " fue encontrado." << std::endl;
    } else {
        std::cout << valorABuscar << " NO fue encontrado." << std::endl;
    }
    // Buscar un elemento usando std::find
    auto it = std::find(numeros.begin(), numeros.end(), valorABuscar); //Complejidad O(N) - HORRRIBLE
    return 0;

    std::vector<int> numeros = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    // ¡Importante! El vector debe estar ordenado para binary_search
    // std::sort(numeros.begin(), numeros.end()); // Si no está ordenado

    //Assign() Asigna nuevos valores al vector, reemplazando su contenido.
    vector<int> v;
    v.assign(5, 10);  
    // v = {10, 10, 10, 10, 10}

    vector<int> w{1,2,3,4,5};
    v.assign(w.begin()+1, w.begin()+4);  
    // v = {2,3,4}

    //At Devuelve (con chequeo de rangos) una referencia al elemento en la posición dada. Lanza out_of_range si el índice no existe.
    vector<string> v{"uno","dos","tres"};
    try {
        cout << v.at(1) << "\n";  // “dos”
        cout << v.at(10) << "\n"; // excepción
    } catch (const out_of_range &e) {
        cerr << "Error: " << e.what() << "\n";
    }

    //Front y Back Devuelve una referencia al primer y último elemento del vector, respectivamente. No lanza excepciones si el vector está vacío.
    // Si el vector está vacío, el comportamiento es indefinido.
    vector<int> v{5,10,15};
    cout << v.front() << "\n"; // 5
    cout << v.back()  << "\n"; // 15

    v.front() = 100;
    v.back()  = 200;
    // v = {100, 10, 200}

    //Push_back() Añade un elemento al final del vector. No lanza excepciones si el vector está lleno, pero puede causar una reasignación de memoria.
    // Si el vector está lleno, se redimensiona automáticamente.
    // Pop_back() Elimina el último elemento del vector. No lanza excepciones si el vector está vacío, pero el comportamiento es indefinido.
    // Si el vector está vacío, el comportamiento es indefinido.
    vector<int> v;
    v.push_back(1);
    v.push_back(2);  // v = {1,2}
    v.pop_back();    // v = {1}

    //Insert() Inserta un elemento o un rango de elementos en una posición específica del vector. Puede causar una reasignación de memoria si el vector está lleno.
    vector<int> v{1,4,5};
    v.insert(v.begin()+1, 2);               
    // v = {1,2,4,5}

    v.insert(v.end(), {6,7,8});             
    // v = {1,2,4,5,6,7,8}

    //erase() Elimina un elemento o un rango de elementos del vector. No lanza excepciones si el vector está vacío, pero el comportamiento es indefinido.
    vector<int> v{1,2,3,4,5};
    v.erase(v.begin()+2);         // borra el 3 → {1,2,4,5}
    v.erase(v.begin(), v.begin()+2); 
    // borra 1 y 2 → {4,5}

    //clear() Elimina todos los elementos del vector. No lanza excepciones si el vector está vacío, pero el comportamiento es indefinido.
    vector<int> v{1,2,3};
    v.clear();  
    // v vacío

    //empty() Comprueba si está vacío (size() == 0). No lanza excepciones.
    vector<int> v;
    if (v.empty()) cout << "vacío\n";

    //size() Devuelve el número de elementos. No lanza excepciones.
    //capacity() → cuántos puede almacenar sin realocar.
    //max_size() → número máximo teórico de elementos (limitado por el sistema).
    vector<int> v;
    cout << v.size()     << "\n"; // 0
    cout << v.capacity() << "\n"; // (depende de implementación)
    cout << v.max_size() << "\n"; // muy grande

    v.reserve(100);
    cout << v.capacity() << "\n"; // al menos 100

    //Swap() - Intercambia el contenido de dos vectores en O(1).
    vector<int> a{1,2,3}, b{4,5};
    a.swap(b);
    // ahora a={4,5} y b={1,2,3}


    //lower_bound() y upper_bound() - Devuelven iteradores 
    //al primer elemento que no es menor que (lower_bound) o al primer elemento que es mayor que (upper_bound) un valor dado. Requieren que el vector esté ordenado.
    //con contenedores asocioados como set, map, multiset, multimap, etc., se pueden usar directamente sin necesidad de ordenar.
    //equal_range() - Devuelve un par de iteradores que representan el rango de elementos
    //O(n log n) para ordenar, O(log n) para buscar con lower_bound, upper_bound o equal_range.
    vector<int> v = {1, 2, 2, 3, 5, 5, 5, 8};
    int x = 5;

    // lower_bound: primer >= 5
    auto lo = lower_bound(v.begin(), v.end(), x);
    // upper_bound: primer > 5
    auto hi = upper_bound(v.begin(), v.end(), x);

    cout << "lower_bound apunta al valor " << *lo
         << " en posición " << (lo - v.begin()) << "\n";
    cout << "upper_bound apunta al valor " << *hi
         << " en posición " << (hi - v.begin()) << "\n";

    // equal_range:
    auto range = equal_range(v.begin(), v.end(), x);
    cout << "equal_range abarca posiciones ["
         << (range.first  - v.begin()) << ", "
         << (range.second - v.begin()) << ")\n";
}