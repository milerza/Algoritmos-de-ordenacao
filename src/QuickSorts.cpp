#include "QuickSorts.hpp"

#include <cstdlib>



void QuickSorts::quickSortRecursivo(Registro *vetor, int esquerda, int direita){
    int i , j;

    this->Particao(vetor, esquerda, direita, &i, &j);

    if (j > esquerda)
        quickSortRecursivo(vetor, esquerda, j);
    if (i < direita)
        quickSortRecursivo(vetor, i, direita);
}

void QuickSorts::quickSortMediana(Registro *vetor, int esquerda, int direita, int k)
{
    int i , j;
    Registro aux;


    i = esquerda;
    j = direita;

    int pivo = this->escolherPivor(vetor, k, esquerda, direita);
    
    while (i <= j)
    {
        while (vetor[i].getChave() < pivo)
            i++;
        while (vetor[j].getChave() > pivo)
            j--;
        if (i <= j)
        {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            (i++);
            (j--);
        }
    }

    if (j > esquerda)
        quickSortRecursivo(vetor, esquerda, j);
    if (i < direita)
        quickSortRecursivo(vetor, i, direita);
}

void QuickSorts::quickSortSelecao(Registro *vetor, int esquerda, int direita, int m){
    int i , j;

    this->ParticaoSelecao(vetor, esquerda, direita, &i, &j, m);

    if (j > esquerda)
        quickSortRecursivo(vetor, esquerda, j);
    if (i < direita)
        quickSortRecursivo(vetor, i, direita);
}

void QuickSorts::quickSortNaoRecursivo(Registro *vetor, int n)
{
    PilhaEncadeada * pilha;
    TipoItem item;
    // campos esq e dir
    int esq, dir, i, j;

    pilha = new PilhaEncadeada();

    esq = 0;
    dir = n-1;
    item.direita = dir;
    item.esquerda = esq;

    pilha->Empilha(item);

    do{
        if (dir > esq) {
            Particao(vetor, esq, dir, &i, &j);
            if ((j-esq)>(dir-i)) {
                item.direita = j;
                item.esquerda = esq;
                pilha->Empilha(item);
                esq = i;
            }
            else {
                item.direita = i;
                item.esquerda = dir;
                pilha->Empilha(item);
                dir = j;
            }
        }
        else {
            pilha->Desempilha();
            dir = item.direita;
            esq = item.esquerda;
        }
    } while (!pilha->Vazia());
}

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

int QuickSorts::escolherPivor(Registro *vetor, int k, int esquerda, int direita){
    Registro * aux = new Registro[k];
    int posicao;

    if(k == 0)
        throw "Valor de k invalido";

    //procurando valores aleatórios no intervalo definido por direita e esquerda
    for(int i = 0; i < k; i++){ 
        //calculando o valor aleatorio entre o valor esquerda e o valor direita passados como paramentros
        posicao =  esquerda + (rand() % (direita - esquerda + 1));
        aux[i] = vetor[posicao];
    }

    //ordena o vetor aux
    quickSortRecursivo(aux, 0, k);

    if(k%2 == 0){ 
        return aux[k/2].getChave(); //mediana caso o vetor aux tenha tamanho par
    } 
    else{
        return aux[(k+1)/2].getChave(); //mediana caso o vetor aux tenha tamanho impar
    }
}


void QuickSorts::Selecao(Registro * vetor,  int n){
    int i, j, min;
    Registro aux;

    for (i = 0; i < n - 1; i++){
        min = i;

        for (j = i + 1 ; j < n; j++){
            if (vetor[j].getChave() < vetor[min].getChave())
                min = j;
        }

        aux = vetor[i];
        vetor[i] = vetor[min];
        vetor[min] = aux;
    }
}

void QuickSorts::ParticaoSelecao(Registro * vetor, int esquerda, int direita, int *i, int *j, int m){
    *i = esquerda;
    *j = direita;

    int pivo = vetor[(*i + *j) / 2].getChave();

    while ((*j - *i) <= m)
    {
        while (vetor[*i].getChave() < pivo)
            (*i)++;
        while (vetor[*j].getChave() > pivo)
            (*j)--;
        if ( (*j - *i) <= m)
        {
            Selecao(vetor, (*j - *i));
        }
    }
}