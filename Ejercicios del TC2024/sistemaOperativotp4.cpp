#include <bits/stdc++.h>

def es_primo(numero):
    if numero < 2:
        return False
    for i in range(2, int(numero**0.5) + 1):
        if numero % i == 0:
            return False
    return True

def primeros_primos(n):
    primos = []
    numero = 2
    while len(primos) < n:
        if es_primo(numero):
            primos.append(numero)
        numero += 1
    return primos

# Obtener los primeros 100 números primos
primos = primeros_primos(100)

# Imprimir los números primos
print(primos)

//Productor(Fabrica):
    while(1) {
        wait(espacioDisponible);    // espera a que haya espacio en el almacén
        wait(mutex);                // Entra en la sección crítica
        
        // Producir una silla
        almacenarSilla(almacen);
        print("Silla fabricada y almacenada");

        signal(mutex);              // Salir de la sección crítica
        signal(sillasDisponibles);  // Señala que hay una nueva silla disponible
    }
    
//Consumidor(Pintor de sillas):
    while(true) {
        wait(sillasDisponibles);    // Espera a que haya una silla disponible
        wait(mutex);                // Entra en la sección crítica
        
        // Consumir una silla (pintar)
        retirarSilla(almacen);
        print("Silla retirada y pintada");

        signal(mutex);              // Salir de la sección crítica
        signal(espacioDisponible);  // Señala que hay un espacio libre en el almacén
	}