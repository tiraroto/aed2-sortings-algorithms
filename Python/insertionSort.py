import random

def insertionSort(vet):
    """
    Ordena o vetor atravez do metodo de Insertion Sort

    :param vet: Vetor a ser ordenado
    :return: Retorna o vetor ordenado
    """

    #   Se o tamanho do vetor for menor ou igual a 1, ele ja esta ordenado ou é nulo
    if len(vet) <= 1: return vet

    #   Percorre o vetor a partir da segundo elemento para ordena-lo
    for i in range(1, len(vet)):
        posAtual = i     #   Posicao do elemento atual do vetor
        posAnterior = i - 1    #   Posicao do elemento a esquerda do elemento atual

        #   Enquanto existir elemento a esquerda do atual e o elemento atual for menor que o da esquerda
        #   Move o elemento atual para esquerda
        while posAnterior >= 0 and vet[posAtual] < vet[posAnterior]:
            vet[posAtual] += vet[posAnterior]                       #   A = (a + b)
            vet[posAnterior] = vet[posAtual] - vet[posAnterior]     #   B = (a + b) - b = a
            vet[posAtual] = vet[posAtual] - vet[posAnterior]        #   A = (a + b) - B = b

            #   decrementa a posicao atual para acompanhar a mudanca de valores
            posAtual -= 1
            #   decrementa a posicao do valor a esquerda tambem para acompanhar a mudaca
            #   e fazer uma nova comparacao
            posAnterior -= 1

    #   retorna o vetor ordenado
    return vet

vet = []
for i in range(random.randint(15, 20)):
    vet.append(random.randint(0,30))
print(insertionSort(vet))

vet = []
for i in range(random.randint(0, 5)):
    vet.append(random.randint(0,30))
print(insertionSort(vet))