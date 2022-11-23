#ifndef _SORTS_
#define _SORTS_

#include "Registro.hpp"

class Sorts{
    public:
        int comparacoes;
        void mergeSort(Registro * vetor, int const inicio, int const fim);
        void heapSort(Registro * vetor, int N);
    private:
        void merge(Registro * vetor, int const esquerda, int const meio, int const direita);
        void heapify(Registro * vetor, int N, int i);
};


#endif