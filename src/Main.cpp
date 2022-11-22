#include "QuickSorts.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

extern "C"{
    #include <msgassert.h>
    #include <memlog.h>
    #include <sys/time.h>
    #include <sys/resource.h>
}

void Imprimir(Registro * registro, int n){
    std::cout << "Vetor de tamanho:" << n << std::endl;

    for(int i = 0; i < n-1; i++)
        std::cout << registro[i].getChave() << " ";

    std::cout << registro[n-1].getChave() << std::endl;
}

void ChamarQuickSort(int * valores, int quantidadeValores, int versao, int semente, int kMediana = 3, int mSelecao = 3){
    QuickSorts quicksorts;
    int chave;
    std::string caminhoSaida;

    // Alocando o vetor de numeros
    float * numerosReais = new float[10]; 


    // Alocando texto
    int m = 15; int n = 200;
    char** texto = new char*[m]; 
    char *linha = new char[m*n];
    
    for(int i = 0 ; i< m; ++i) {
        texto[i] = linha + i * n;
    }

    //Atribuindo Texto para registro
    for(int i = 0; i<m ; i++){
        for(int j = 0; j<n; j++)
        texto[i][j] = 'a';
    }

    //Verificando validade da semente
    avisoAssert(semente > 0, "Semente menor ou igual a zero");
    
    if(semente > 0)
        srand(semente); //atribuindo semente

    // ---------------------------------------------------------------------------------------
    // declarações para medir o tempo
    struct rusage usage;
    struct timeval start_user, end_user, start_system, end_system;

    // ---------------------------------------------------------------------------------------

    for(int i = 0; i< quantidadeValores; i++){

        Registro * listaRegistros = new Registro[valores[i]];

        for(int x = 0; x < valores[i] ; x++){

            chave = rand();
            chave = chave%valores[i];  // gerando um numero aleatorio
            listaRegistros[x].setRegistro(chave, texto, numerosReais); //atribuindo registro
        }
        
        // start reading u_time
        getrusage(RUSAGE_SELF, &usage);
        start_user = usage.ru_utime;
        start_system = usage.ru_stime;
        
        leMemLog((long int)((listaRegistros[valores[i]].getChave())), sizeof(long int), 0);

        if(versao == 1){
            quicksorts.quickSortRecursivo(listaRegistros, 0, valores[i] - 1);
        } 
        else if(versao == 2){
            quicksorts.quickSortMediana(listaRegistros, 0, valores[i] - 1, kMediana);
        }
        else if(versao == 3){
            quicksorts.quickSortSelecao(listaRegistros, 0, valores[i] - 1, kMediana);
        }
        else if(versao == 4){
            quicksorts.quickSortNaoRecursivo(listaRegistros, valores[i]);
        }
        else if(versao == 5){
            quicksorts.quickSortNaoRecursivo(listaRegistros, valores[i]);
        } else{
        avisoAssert(versao >= 1 || versao<= 5, "Versão QuickSort não especificada!");
        }

        Imprimir(listaRegistros, valores[i]);
        delete(listaRegistros);

        // ---------------------------------------------------------------------------------------
    // end reading u_time
    getrusage(RUSAGE_SELF, &usage);
    end_user = usage.ru_utime;
    end_system = usage.ru_stime;

    // tv_sec: seconds; tv_usec: microseconds
    // ru_utime: total amount of time spent executing in usermode,
    // expressed in a timeval structure (seconds plus microseconds)
    float utime = (end_user.tv_sec - start_user.tv_sec) + 1e-6 * (end_user.tv_usec - start_user.tv_usec);
    float stime = (end_system.tv_sec - start_system.tv_sec) + 1e-6 * (end_system.tv_usec - start_system.tv_usec);
    
    std::cout << std::fixed << "tempo total: " << utime + stime << std::endl;

    }
    
}

int *LerArquivo(std::string arquivoEntrada, int * N){
    
    std::ifstream inFile;

    int * valores;
    
    inFile.open(arquivoEntrada.c_str());
    
    //------ Verificando validade se o arquivo existe
    avisoAssert(!inFile.fail(), "Arquivo inexistente!");

    inFile >> *N;
    valores = new int[*N];

    for(int i = 0; i< *N; i++){
        inFile >> valores[i];
    }

    inFile.close();

    return valores;
}

void EscreverArquivo(std::string arquivoSaida, int n, Registro *vetor){
    std::ofstream inFile;

    inFile.open(arquivoSaida.c_str());
    
    inFile << "Vetor tamanho: "<< n << std::endl;
    for(int i = 0; i< n - 1; i++){
        inFile << vetor[i].getChave() ;
    }
        inFile << vetor[n - 1].getChave() << std::endl;

    inFile.close();
}

int main(int argc, char* argv[]) {

    // configuração do memlog
    std::string logdir = "run.log";
    std::ofstream logfile(logdir);
    logfile.close();

    char *logdir_name = new char[logdir.length() + 1];
    std::strcpy(logdir_name, logdir.c_str());

    iniciaMemLog(logdir_name);
    ativaMemLog();

    
    int versao = 0;
    int semente, kMediana, mSelecao, tamanhoValores;
    int * valores;
    std::string caminhoEntrada;
    std::string caminhoSaida;
    

    //------ Lendo valores passados 

    for (int i = 0; i < argc; i++){
        if (std::string(argv[i]) == "-v"){ //versao quicksort
            versao = std::stoi(std::string(argv[i + 1]));
        }
        else if (std::string(argv[i]) == "-s"){//semente do rand
            semente = std::stoi(std::string(argv[i + 1]));
        }
        else if (std::string(argv[i]) == "-i"){ //arquivo de input
            caminhoEntrada = std::string(argv[i + 1]);
        }
        else if (std::string(argv[i]) == "-o"){ //arquivo de saida
            caminhoSaida = std::string(argv[i + 1]);
        }
        else if (std::string(argv[i]) == "-k"){ //elementos do quicksort mediana
            kMediana = std::stoi(std::string(argv[i + 1]));
        }
        else if (std::string(argv[i]) == "-m"){ //elementos do select sort mediana
            mSelecao = std::stoi(std::string(argv[i + 1]));
        }
    }

    //------ Verificando versao quick sort
    avisoAssert(versao != 0, "Versão QuickSort não especificada!");

    valores = LerArquivo(caminhoEntrada, &tamanhoValores);

    ChamarQuickSort(valores, tamanhoValores, versao, semente, kMediana, mSelecao);

    return 0;
}