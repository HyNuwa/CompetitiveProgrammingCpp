def EsMenorMitad(hora):
    acumulador = hora[0]*3600+hora[1]*60+hora[2]
    if(acumulador==9000):
        return "="
    elif(acumulador<9000):
        return "-"
    else:
        return "+"

horas = map(int ,input().split())
print(EsMenorMitad(horas))