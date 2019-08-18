#include <iostream>
#include <cstdlib>

using namespace std;

//Gera um número aleatório
int numeroAleatorio(int min, int max){

    static int initFlag = 0; // Flag de inicialização para chamada única do método srand().
    int num; //número aleatório a ser gerado.

    if (initFlag == 0){
        srand(time(NULL));
        initFlag = 1;
    }

    num = rand() % (max - min + 1) + min; //gera um número aleatório
    
    return num;
}

