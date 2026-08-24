nombre = input()
salida = nombre[0]
for i in range(1,len(nombre)): 
    if (nombre[-i]== " "):
        salida = salida + nombre[-i+1]
        break

print(salida)
