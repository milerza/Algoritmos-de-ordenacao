#include "Sorts.hpp"


void Sorts::merge(Registro * vetor, int const esquerda, int const meio, int const direita){
    int const subVetorUm = meio - esquerda + 1;
    int const subVetorDois = direita - meio;

    int idSubVetorUm, idSubVetorDois, idJuntadoVetor; //inicia variaveis
 
    //criando vetores auxiliar
    Registro *esquerdaVetor = new Registro[subVetorUm];
    Registro *direitaVetor = new Registro[subVetorDois];
 
    // Dividindo vetores
    for (int i = 0; i < subVetorUm; i++)
        esquerdaVetor[i] = vetor[esquerda + i];

    for (int j = 0; j < subVetorDois; j++)
        direitaVetor[j] = vetor[meio + 1 + j];
    
    //atribuindo indexes dos vetores
    idSubVetorUm = 0; 
    idSubVetorDois = 0; 
    idJuntadoVetor = esquerda;  
    
    // ordena e junta novamente os vetores
    while (idSubVetorUm < subVetorUm && idSubVetorDois < subVetorDois) {
        if (esquerdaVetor[idSubVetorUm].getChave() <= direitaVetor[idSubVetorDois].getChave()) {
            vetor[idJuntadoVetor] = esquerdaVetor[idSubVetorUm];
            idSubVetorUm++;
        }
        else {
            vetor[idJuntadoVetor] = direitaVetor[idSubVetorDois];
            idSubVetorDois++;
        }
        idJuntadoVetor++;
    }

    // Copia os elementos que sobraram da esquerda
    while (idSubVetorUm < subVetorUm) {
        vetor[idJuntadoVetor] = esquerdaVetor[idSubVetorUm];
        idSubVetorUm++;
        idJuntadoVetor++;
    }

    // Copia os elementos que sobraram da direita
    while (idSubVetorDois < subVetorDois) {
        vetor[idJuntadoVetor] = direitaVetor[idSubVetorDois];
        idSubVetorDois++;
        idJuntadoVetor++;
    }

    delete[] esquerdaVetor;
    delete[] direitaVetor;
}

void Sorts::mergeSort(Registro * vetor, int const inicio, int const fim){
    if (inicio >= fim)
        return; //condicao de parada
 
    int meio = inicio + (fim - inicio) / 2;
    //divide
    mergeSort(vetor, inicio, meio);
    mergeSort(vetor, meio + 1, fim);

    //junta
    merge(vetor, inicio, meio, fim);
}