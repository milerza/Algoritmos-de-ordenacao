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

void Sorts::heapify(Registro * vetor, int N, int i){
    
    int maior = i; //raiz
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;
 
    // se a folha da esquerda é maior que que maior
    if (esquerda < N && vetor[esquerda].getChave() > vetor[maior].getChave())
 
        maior = esquerda;
 
    // se a folha da esquerda é maior que que maior
    if (direita < N && vetor[direita].getChave() > vetor[maior].getChave())
 
        maior = direita;
 
    // troca e continua a função se a raiz não é maior
    if (maior != i) {
        Registro aux = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = aux;
 
        // executa recursivamento o metodo na subarvore
        heapify(vetor, N, maior);
    }
}

void Sorts::heapSort(Registro * vetor, int N){
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(vetor, N, i);
 
    // Heap sort
    for (int i = N - 1; i >= 0; i--) {
        Registro aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;

        heapify(vetor, i, 0);
    }
}