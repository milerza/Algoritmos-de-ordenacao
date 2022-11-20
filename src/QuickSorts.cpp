#include "QuickSorts.hpp"


void QuickSorts::Particao(Registro * vetor, int esquerda, int direita, int *i, int *j){
    *i = esquerda;
    *j = direita;

    int pivo = vetor[(*i + *j) / 2].getChave();
    Registro aux;

    while (*i <= *j)
    {
        while (vetor[*i].getChave() < pivo)
            (*i)++;
        while (vetor[*j].getChave() > pivo)
            (*j)--;
        if (*i <= *j)
        {
            aux = vetor[*i];
            vetor[*i] = vetor[*j];
            vetor[*j] = aux;
            (*i++);
            (*j--);
        }
    }
}

void QuickSorts::quickSortRecursivo(Registro *vetor, int esquerda, int direita)
{
    int i , j;

    this->Particao(vetor, esquerda, direita, &i, &j);

    if (j > esquerda)
        quickSortRecursivo(vetor, esquerda, j);
    if (i < direita)
        quickSortRecursivo(vetor, i, direita);
}

void QuickSorts::quickSortMediana(Registro *vetor, int esquerda, int direita, int k)
{
}

void QuickSorts::quickSortSelecao(Registro *vetor, int esquerda, int direita)
{
}

void QuickSorts::quickSortNaoRecursivo(Registro *vetor, int n)
{
    PilhaEncadeada pilha;
    Registro item;
    // campos esq e dir
    int esq, dir, i, j;

    FPVazia(&pilha);

    esq = 0;
    dir = n-1;
    item.dir = dir;
    item.esq = esq;

    pilha.Empilha(item);

    do{
        if (dir > esq) {
            Particao(vetor, esq, dir, &i, &j);
            if ((j-esq)>(dir-i)) {
            item.dir = j;
            item.esq = esq;
            Empilha(item, &pilha);
            esq = i;
            }
            else {
            item.esq = i;
            item.dir = dir;
            Empilha(item, &pilha);
            dir = j;
            }
            }
        else {
            Desempilha(&pilha,&item);
            dir = item.dir;
            esq = item.esq;
        }
    } while (!Vazia(pilha));
}

 
