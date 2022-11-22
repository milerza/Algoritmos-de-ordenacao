#ifndef _SORTS_
#define _SORTS_

#include "Registro.hpp"

class Sorts{
    public:
        void merge(Registro * vetor, int const esquerda, int const meio, int const direita);
        void mergeSort(Registro * vetor, int const inicio, int const fim);
};


#endif