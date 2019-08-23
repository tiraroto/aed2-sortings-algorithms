import random

# Cria um vetor de números aleatórios
def numerosAleatorios(min, max):
    vet = list(range(min,max)) # Cria Vetor
    random.shuffle(vet) # Embaralha Vetor
    return vet

aux = []
def merge(vet):
    tamanho = len(vet)
    meio = round(tamanho/2)
    print(tamanho, meio)
    fim1 = False
    fim2 = False
    p1 = 0
    p2 = meio

    for i in range(tamanho):
        if (fim1 == False and fim2 == False):
            if vet[p1] < vet[p2]:
                aux.append(vet[p1])
                p1 += 1 
            else:
                aux.append(vet[p2])
                p2 += 1 
            if p1 > meio:
                fim1 = True
            if p2 > tamanho-1:
                fim2 = True
        else:
            if (fim1 == False):
                aux.append(vet[p1])
                p1 += 1 
            else:
                aux.append(vet[p2])
                p2 += 1 

    print(vet, aux)

    for i in range(0, tamanho-1):
        print(i)
        vet[i] = aux[i]


def mergeSort(vet):
    meio = round(len(vet)/2)
    if len(vet) > 1:
        mergeSort(vet[0:meio])
        mergeSort(vet[meio+1:])
        merge(vet)

    
vetor = numerosAleatorios(0, 10)
print("# Desordenado")
print(vetor)
mergeSort(vetor)
print("# Ordenado")
print(vetor)