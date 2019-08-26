#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>

using namespace std;

/* Gera um número aleatório
* @param min  Valor mínimo que o número pode ter.
* @param max  Valor máximo que o número pode ter.
*/
int numeroAleatorio(int min, int max){

    static int initFlag = 0; // Flag de inicialização para chamada única do método srand().
    int num; // Número aleatório a ser gerado.

    if (initFlag == 0){
        srand(time(NULL)); // Define a seed de acordo com o relógio da máquina.
        initFlag = 1;
    }

    num = rand() % (max - min + 1) + min; // Gera um número aleatório
    
    return num;
}

/* Embaralha Vetor
* Escolhe uma posição aleatoria do vetor e troca com a de iteração.
* @param vet  Vetor a ser embaralhado.
* @param tam  Tamanho do vetor.
* @param min  posição de início do embaralhamento.
*/
void embaralhaVetor(int* vet, int tam, int min){
    for (int i = 0; i < tam; i++){
        int rnd = numeroAleatorio(min, tam);

        int aux = vet[i];
        vet[i] = vet[rnd];
        vet[rnd] = aux;
    }
}

/*
* Gera números aleatórios distintos e adiciona-os no vetor.
* @param qtNum  Quantidade de números a serem gerados.
* @param min  Valor mínimo que um número poderá ter.
* @param max  Valor máximo que um número poderá ter.
*/
int* numerosAleatorios(int qtNum, int min, int max){
    int* vet = new int[qtNum]; //vetor que será retornado.

    // Cria um vetor ordenado
    for (int i = 0; i < qtNum; i++){
        vet[i+min] = i;
    }

    // Embaralha o vetor
    embaralhaVetor(vet, qtNum, min);

    return vet;

}

/* [DEBUG] Impressão de valores inteiros de um vetor (pode ser apagada)
* @param vet  Vetor a ser impresso.
* @param tam  Tamanho do vetor.
*/
template <class T>
void imprimeVetor(T* vet, int tam){
    cout << vet[0];
    for (int i = 1; i < tam; i++){
        cout << ", " << vet[i];
    }
    cout << endl;
}

void insertionSort(int* vet, int st, int len, int order) {
    for (int j = st+1; j < len; j++) {
        int key = vet[j];
        int i = j - 1;

        switch(order) {
            case 0:
                while (i >= 0 && vet[i] < key) {
                    vet[i+1] = vet[i];
                    i--;
                }
                break;
            default:
                while (i >= 0 && vet[i] > key) {
                    vet[i+1] = vet[i];
                    i--;
                }
                break;
        }

        vet[i+1] = key;
    }
}

/* Avaliação 
* Avalia o tempo de execução do algoritmo Merg-Sort com 100.000 números ordenados de formas distintas
* e imprime o tempo de duração de cada operação.
* As formas de ordenação são: desordenado, crescente, decrescente, metade crescente e metade decrescente, 
* metade decrescente e metade crescente.
*/
void avaliar() {
    unsigned int n = 100000;
    int op = 5; // Numero de operações
    double* tempo = new double[op]; // Vetor que armazena os tempos de execução

    // Alocação dos vetores de entrada
    int** vetores = new int*[op];
    for (int i = 0; i < op; i++){
        vetores[i] = new int[n];
    }

    /* Configuração das Entradas */

    // Vetor desordenado
    vetores[0] = numerosAleatorios(n, 0, n);

    // Copia o primeiro vetor para os demais
    for (int i = 1; i < op; i++){
        for (int j = 0; j < n; j++){
            vetores[i][j] = vetores[0][j];
        }
    }
    
    // Vetor Decrescente
    insertionSort(vetores[1], 0, n, 1);

    // Vetor Crescente
    insertionSort(vetores[2], 0, n, 0);

    // Vetor Crescente/Decrescente
    insertionSort(vetores[3], 0, n/2, 0); // Ordena a primeira metade do vetor em ordem crescente
    insertionSort(vetores[3], (n/2)+1, n, 1); // Ordena a segunda metade do vetor em ordem decrescente

    // Vetor Decrescente/Crescente
    insertionSort(vetores[4], 0, n/2, 1); // Ordena a primeira metade do vetor em ordem decrescente
    insertionSort(vetores[4], (n/2)+1, n, 0); // Ordena a segunda metade do vetor em ordem crescente

    // Medição do tempo de execução do Merge Sort nos vetores de entrada
    for (int i = 0; i < op; i++){
        clock_t tick_inicio, tick_fim; 
        
        tick_inicio = clock(); // Salva o momento antes da execução do algoritmo.
        insertionSort(vetores[i], 0, n, 0);
        tick_fim = clock(); // Salva o momento após a execução do algoritmo.
        tempo[i] = (tick_fim - tick_inicio) * 1000.0 / CLOCKS_PER_SEC; // Calcula o tempo 

    }   

    // Impressão dos tempos de execução
    for (int i = 0; i < op; i++){
        cout << "Tempo gasto (";
        switch(i){
            case 0:
                cout << "Desordenado";
                break;
            case 1:
                cout << "Decrescente";
                break;
            case 2:
                cout << "Crescente";
                break;
            case 3:
                cout << "Crescente/Decrescente";
                break;
            case 4:
                cout << "Decrescente/Crescente";
                break;
        }
        printf("): %g ms.\n", tempo[i]);

    }

    // Desalocação de recursos
    for (int i = 0; i < op; i++){
        delete(vetores[i]);
    }
    delete(vetores);
    delete(tempo);

}

// Main
int main () {
    avaliar();
    return 0;
}