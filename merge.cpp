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

/*
* Algoritmo que recebe duas partes de um único vetor e junta-as noutro vetor auxiliar de forma ordenada.
* @param v  O vetor dividido que será fundido.
* @param inicio  Posição inicial do vetor
* @param meio  Posição mediana do vetor, que divide o vetor em dois.
* @param fim  Posição final do vetor.
* @param modo  Modo de ordenação do vetor. (0-Crescente / 1-Decrescente).
*/
void merge(int* v, int inicio, int meio, int fim, int modo) {
    int *aux; // Vetor auxiliar 
    int p1, p2; // Posição de verificação dos vetores. (index)
    int tamanho; // Tamanho do vetor
    bool fim1 = false, fim2 = false; // Indica o fim dos vetores.

    tamanho = fim - inicio + 1;
    aux = new int[tamanho];
    p1 = inicio;
    p2 = meio + 1;

    if (aux != NULL){
        for (int i = 0; i < tamanho; i++){
            if (modo == 0){ // Ordena em ordem crescente
                if (!fim1 && !fim2){
                    if (v[p1] < v[p2]){
                        aux[i] = v[p1++];
                    } else {
                        aux[i] = v[p2++];
                    }
                    if (p1 > meio) {
                        fim1 = true;
                    }
                    if (p2 > fim) {
                        fim2 = true;
                    }
                } else {
                    if (!fim1){
                        aux[i] = v[p1++];
                    } else {
                        aux[i] = v[p2++];
                    }
                }
            } else { // Ordena em ordem decrescente
                if (!fim1 && !fim2){
                    if (v[p1] > v[p2]){
                        aux[i] = v[p1++];
                    } else {
                        aux[i] = v[p2++];
                    }
                    if (p1 > meio) {
                        fim1 = true;
                    }
                    if (p2 > fim) {
                        fim2 = true;
                    }
                } else {
                    if (!fim1){
                        aux[i] = v[p1++];
                    } else {
                        aux[i] = v[p2++];
                    }
                }
            }
            
        }

        // Copia os valores do vetor auxiliar para o vetor passado como parâmetro.
        for (int i = 0; i < tamanho; i++){
            v[i+inicio] = aux[i];
        } 

    }

    delete(aux);

}

/* Merge Sort
* Aplica o algoritmo Merge-Sort em vetor dado.
* @param vet  Vetor de inteiros a ser ordenado.
* @param inicio  posição de início da ordenação.
* @param fim  posição final da ordenação.
* @param modo  Ordenação. (0-Crescente/1-Decrescente)
*/
void mergeSort(int* vet, int inicio, int fim, int modo) {
    if (inicio < fim){
        int meio = floor((fim + inicio)/2); // Calcula a metade do vetor.
        mergeSort(vet, inicio, meio, modo); // Aplica algoritmo recursivamente na primeira metade do vetor, de acordo com o modo.
        mergeSort(vet, meio+1, fim, modo); // Aplica algoritmo recursivamente na segunda metade do vetor, de acordo com o modo.
        merge(vet, inicio, meio, fim, modo); // Junta as duas metádes do vetor, de acordo com o modo.
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

    // Alocação dos vetores auxiliares
    int** vetores = new int*[op];
    for (int i = 0; i < op; i++){
        vetores[i] = new int[n];
    }

    // Vetor desordenado
    vetores[0] = numerosAleatorios(n, 0, n);

    / Copia o primeiro vetor para os demais
    for (int i = 1; i < op; i++){
        for (int j = 0; j < n; j++){
            vetores[i][j] = vetores[0][j];
        }
    }
    
    // Vetor Decrescente
    mergeSort(vetores[1], 0, n, 1);

    // Vetor Crescente
    mergeSort(vetores[2], 0, n, 0);

    // Vetor Crescente/Decrescente
    mergeSort(vetores[3], 0, n/2, 0); // Ordena a primeira metade do vetor em ordem crescente
    mergeSort(vetores[3], (n/2)+1, n, 1); // Ordena a segunda metade do vetor em ordem decrescente

    // Vetor Decrescente/Crescente
    mergeSort(vetores[4], 0, n/2, 1); // Ordena a primeira metade do vetor em ordem decrescente
    mergeSort(vetores[4], (n/2)+1, n, 0); // Ordena a segunda metade do vetor em ordem crescente

    for (int i = 0; i < op; i++){
        clock_t tick_inicio, tick_fim; 
        
        tick_inicio = clock(); // Salva o momento antes da execução do algoritmo.
        mergeSort(vetores[i], 0, n, 0);
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
int main (){

    avaliar();

    return 0;
}