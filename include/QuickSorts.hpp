#ifndef _QUICK_SORTS_
#define _QUICK_SORTS_

#include "Registro.hpp"
#include "Pilha.hpp"

class QuickSorts{
    public:
        int comparacoes;

    public:
        void quickSortRecursivo(Registro * vetor, int esquerda, int direita);
        void quickSortMediana(Registro * vetor, int esquerda, int direita, int k);
        void quickSortSelecao(Registro * vetor, int esquerda, int direita, int m);
        void quickSortNaoRecursivo(Registro * vetor, int n);
        void quickSortNaoRecursivoInteligente(Registro * vetor, int n);

    private:
        void Particao(Registro * vetor, int esquerda, int direita, int *i, int *j); 
        int escolherPivor(Registro *vetor, int k, int esquerda, int direita);
        void Selecao(Registro * vetor,  int n);
};

#endif