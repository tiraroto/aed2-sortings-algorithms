import random
def mergeSort(vet, inv):
    if len(vet) <= 1:
        return vet
    meio = int(len(vet)/2)
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




vet = []
for i in range(100):
    vet.append(random.randint(0,100))
print("Vetor desordenado:")
print(vet)
print("Vetor ordenado:")
print(mergeSort(vet, True))
