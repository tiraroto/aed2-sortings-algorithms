import random
import math
import time

"""
    Ordena um vetor usando Merge Sort.
    :param vet: Vetor a ser ordenado.
    :param inv: Booleano para indicar ordenação decrescente.
    :return: Retorna o vetor ordenado.
"""
def mergeSort(vet, inv):
    if len(vet) <= 1:
        return vet
    meio = math.ceil(len(vet)/2)
    a = mergeSort(vet[:meio], inv)
    b = mergeSort(vet[meio:], inv)

    vet = merge(a, b, inv)
    return vet

"""
    Mescla dois vetores.
    :param a: Primeiro vetor.
    :param b: Segundo vetor
    :param inv: Booleano para indicar ordenação decrescente.
    :return: Retorna o vetor ordenado.
"""
def merge(a, b, inv):
    vet = []
    indexA = 0 # Inicio da primeira metade
    indexB = 0 # Inicio da segunda metade
    while indexA < len(a) and indexB < len(b):
        if not inv: #Ordena em ordem crescente
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
        else: #Ordena em ordem decrescente
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
"""
    Contabiliza o tempo de execução para as seguintes entradas:
    Vetor de inteiros:
    - Desordenado.
    - Ordenado crescente.
    - Ordenado decrescente.
    - Ordenado metade crescente, metade decrescente.
    - Ordenado metade decrescente, metade crescente.
"""
testes = [] # Vetor que guarda os casos de teste
tempos = [] # Vetor que guarda os tempos de execução para cada caso de teste
tamanho = 100000 # Tamanho dos casos de teste
nOp= 5 # número de casos de teste
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