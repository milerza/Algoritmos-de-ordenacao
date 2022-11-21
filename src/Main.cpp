#include "QuickSorts.hpp"

#include <iostream>
#include <string>
#include <fstream>

int GerarChaveAleatoria(int N){
    // configurando a semente
    srand(N);

    // gerando um numero aleatorio
    int random = rand();

    return random;
} 

void LerArquivo(std::string arquivoEntrada){

}

void EscreverArquivo(std::string arquivoSaida, int n, Registro *vetor){
    std::ofstream inFile;

    inFile.open(arquivoSaida.c_str());
    
    inFile << "Vetor tamanho "<< n << std::endl;
    for(int i = 0; i< n - 1; i++){
        inFile << vetor[i].getChave() ;
    }
        inFile << vetor[n - 1].getChave() << std::endl;

    inFile.close();
}

void ImprimirVetor(Registro * registro, int n){
    for(int i = 0; i < n; i++)
        std::cout << registro[i].getChave() << std::endl;
}

int main(int argc, char* argv[]) {
    QuickSorts quicksorts;
    char versao;
    int semente, kMediana, mSelecao, chave;
    std::string caminhoEntrada;
    std::string caminhoSaida;
    
    int m = 15; int n = 200;

    //------ Alocando texto
    char** texto = new char*[m]; 
    char *linha = new char[m*n];

    for(int i = 0 ; i< m; ++i) {
        texto[i] = linha + i * n;
    }
    
    //------ Alocando o vetor de numeros
    float * numerosReais = new float[10]; 

    //------ Lendo valores passados 

    for (int i = 0; i < argc; i++){
        if (std::string(argv[i]) == "-v"){ //versao quicksort
            versao = *argv[i + 1];
            //std::cout << versao <<std::endl;
        }
        else if (std::string(argv[i]) == "-s"){//semente do rand
            semente = *argv[i + 1] - '0';
            //std::cout << versao <<std::endl;
        }
        else if (std::string(argv[i]) == "-i"){ //arquivo de input
            caminhoEntrada = std::string(argv[i + 1]);
            //std::cout << versao <<std::endl;
        }
        else if (std::string(argv[i]) == "-o"){ //arquivo de saida
            caminhoSaida = std::string(argv[i + 1]);
            //std::cout << versao <<std::endl;
        }
        else if (std::string(argv[i]) == "-k"){ //elementos do quicksort mediana
            kMediana = *argv[i + 1] - '0';
            //std::cout << versao <<std::endl;
        }
        else if (std::string(argv[i]) == "-m"){ //elementos do select sort mediana
            mSelecao = *argv[i + 1] - '0';
            //std::cout << versao <<std::endl;
        }
    } 


    
    
    

    

    for(int i = 0; i<m ; i++){
        for(int j = 0; j<n; j++)
        texto[i][j] = 'a';
    }

    Registro * listaRegistros =  new  Registro[10] ;

    for(int i = 0; i<10 ; i++){
        chave = GerarChaveAleatoria(10);
        listaRegistros[i].setRegistro(chave, texto, numerosReais);
    }

    ImprimirVetor(listaRegistros, 10);

    quicksorts.quickSortNaoRecursivo(listaRegistros, 10);

    std::cout << " ordena" << std::endl;

    ImprimirVetor(listaRegistros, 10);

    return 0;
}