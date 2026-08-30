tap = input()
i = 0

while(len(tap) != 0):
    if(tap[i] != tap[i+1] and tap[i] != tap[i+2] and tap[i+1] != tap[i+2]):
        tap = tap[0:i] + tap[i+3:len(tap)]
        i = 0
    else:
        i+=1

    if(i == len(tap)-1):
        break


print("S" if (len(tap)==0) else "N")