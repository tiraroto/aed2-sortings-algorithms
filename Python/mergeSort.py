import random
def mergeSort(vet):
    if len(vet) <= 1:
        return vet
    meio = int(len(vet)/2)
    a = mergeSort(vet[:meio])
    b = mergeSort(vet[meio:])

    vet = merge(a, b)
    return vet

def merge(a, b):
    vet = []
    indexA = 0
    indexB = 0
    while indexA < len(a) and indexB < len(b):
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

    while indexA < len(a):
        vet.append(a[indexA])
        indexA += 1
    while indexB < len(b):
        vet.append(b[indexB])
        indexB += 1
    return vet




vet = []
for i in range(random.randint(15, 20)):
    vet.append(random.randint(0,30))
print(mergeSort(vet))

vet = []
for i in range(random.randint(0, 5)):
    vet.append(random.randint(0,30))
print(mergeSort(vet))
