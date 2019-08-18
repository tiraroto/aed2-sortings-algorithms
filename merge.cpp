#include <iostream>
#include <cstdlib>

using namespace std;

//Gera um número aleatório
int numeroAleatorio(int min, int max){

    static int initFlag = 0; // Flag de inicialização para chamada única do método srand().
    int num; //número aleatório a ser gerado.

    if (initFlag == 0){
        srand(time(NULL)); //define a seed de acordo com o relógio da máquina.
        initFlag = 1;
    }

    num = rand() % (max - min + 1) + min; //gera um número aleatório
    
    return num;
}

/*
* Gera números aleatórios distintos e adiciona-os no vetor.
* @param qtNum é a quantidade de números a serem gerados.
* @param min é o valor mínimo que um número poderá ter.
* @param max é o valor máximo que um número poderá ter.
*/
int* numerosAleatorios(int qtNum, int min, int max){
    int* vet = new int[qtNum]; //vetor que será retornado.
    
    for (int i = 0; i < qtNum; i++){
        int num = numeroAleatorio(min, max);

        //Checar se numero ja existe no vetor.
        for (int j = 0; j <= i; j++){
            if (vet[j] == num) {
                i--;
                break; // para o loop caso encontre o número no vetor.
            }

            //Adicionar numero no vetor.
            if (j == i){
                vet[i] = num;
            }
        }
    }

    return vet;

}

int main (){



    return 0;
}