#ifndef _QUICK_SORTS_
#define _QUICK_SORTS_

#include "Registro.hpp"

class QuickSorts{

    public:
        void quickSortRecursivo(Registro * vetor, int esquerda, int direita);
        void quickSortMediana(Registro * vetor, int esquerda, int direita, int k);
        void quickSortSelecao(Registro * vetor, int esquerda, int direita);
        void quickSortNaoRecursivo(Registro * vetor, int esquerda, int direita);
        void quickSortNaoRecursivoInteligente(Registro * vetor, int esquerda, int direita);

    private:
        void Particao(int esquerda, int direita, int *i, int *j); 

};

#endif