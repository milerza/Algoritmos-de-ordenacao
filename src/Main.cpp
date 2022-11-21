#include "QuickSorts.hpp"
#include <iostream>

/* int GerarChaveAleatoria(int N){

} */

void ImprimirVetor(Registro * registro, int n){
    for(int i = 0; i < n; i++)
        std::cout << registro[i].getChave() << std::endl;
}

int main(int argc, char* argv[]) {
    QuickSorts quicksorts;
    double * numerosReais = new double[10];
    int m = 15;
    int n = 200;

    char** texto = new char*[m];
    char *linha = new char[m*n];

    for(int i=0; i< m; ++i) {
        texto[i] = linha + i * n;
    }

    for(int i = 0; i<m ; i++){
        for(int j = 0; j<n; j++)
        texto[i][j] = 'a';
    }

    Registro * listaRegistros =  new  Registro[10] ;

    for(int i = 0; i<10 ; i++){
        listaRegistros[i].setRegistro(10 - i, texto, numerosReais);
    }

    ImprimirVetor(listaRegistros, 10);

    quicksorts.quickSortNaoRecursivo(listaRegistros, 10);

    std::cout << " ordena" << std::endl;

    ImprimirVetor(listaRegistros, 10);

    return 0;
}