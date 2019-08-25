import random
import math
import time

def mergeSort(vet, inv):
    if len(vet) <= 1:
        return vet
    meio = math.ceil(len(vet)/2)
    a = mergeSort(vet[:meio], inv)
    b = mergeSort(vet[meio:], inv)

    vet = merge(a, b, inv)
    return vet

def merge(a, b, inv):
    vet = []
    indexA = 0
    indexB = 0
    while indexA < len(a) and indexB < len(b):
        if not inv:
            if a[indexA] < b[indexB]:
                vet.append(a[indexA])
                indexA += 1
            elif a[indexA] > b[indexB]:
                vet.append(b[indexB])
                indexB += 1
            else:
                vet.append(a[indexA])
                vet.append(b[indexB])
                indexA += 1
                indexB += 1
        else:
            if a[indexA] > b[indexB]:
                vet.append(a[indexA])
                indexA += 1
            elif a[indexA] < b[indexB]:
                vet.append(b[indexB])
                indexB += 1
            else:
                vet.append(a[indexA])
                vet.append(b[indexB])
                indexA += 1
                indexB += 1


    while indexA < len(a):
        vet.append(a[indexA])
        indexA += 1
    while indexB < len(b):
        vet.append(b[indexB])
        indexB += 1
    return vet

# Testes de entrada
testes = []
tempos = []
tamanho = 100
nOp= 5
meio = math.ceil(tamanho/2)

# Vetor desordenado
vet = []
for i in range(tamanho):
    vet.append(random.randint(0,tamanho))
print("Entrada 1 - Desordenado: \n", vet)
# Cria 5 copias do vetor deordenado
for i in range(nOp):
    testes.append(vet)

#Vetor Crescente
testes[1] = mergeSort(testes[1], False)
print("\nEntrada 2 - Ordem Crescente: \n", testes[1])

#Vetor Decrescente
testes[2] = mergeSort(testes[2], True)
print("\nEntrada 3 - Ordem Decrescente: \n", testes[2])

#Vetor Crescente/Decrescente
metade1 = mergeSort(testes[3][:meio], False)
metade2 = mergeSort(testes[3][meio:], True)
testes[3] = metade1 + metade2
print("\nEntrada 4 - Ordem Crescente/Decrescente: \n", testes[3])

#Vetor Decrescente/Crescente
metade1 = mergeSort(testes[4][:meio], True)
metade2 = mergeSort(testes[4][meio:], False)
testes[4] = metade1 + metade2
print("\nEntrada 5 - Ordem Decrescente/Crescente: \n", testes[4], "\n")

# Medição de tempo para cada entrada
for i in range(nOp):
    inicio = time.time()
    mergeSort(testes[i], False)
    fim = time.time()
    tempos.append(fim - inicio)

print("Tempos de execução(segundos):")
for i in range(len(tempos)):
    print("Entrada", i+1, ":", tempos[i])