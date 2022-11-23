#include "QuickSorts.hpp"

#include <cstdlib>
#include <string>
#include <iostream>


extern "C"{
    #include <msgassert.h>
    #include <memlog.h>
    #include <sys/time.h>
    #include <sys/resource.h>
}


void QuickSorts::Particao(Registro * vetor, int esquerda, int direita, int *i, int *j){
    *i = esquerda;
    *j = direita;
    

    int pivo = vetor[(*i + *j) / 2].getChave();

    leMemLog((long int)(&vetor), sizeof(long int), 0);

    Registro aux;

    while (*i <= *j)
    {
        while (vetor[*i].getChave() < pivo){
            leMemLog((long int)(&(vetor[*i])), sizeof(long int), 0);

            (*i)++;
            comparacoes++;
        }
        comparacoes++;
 
        while (vetor[*j].getChave() > pivo){
            leMemLog((long int)(&(vetor[*j])), sizeof(long int), 0);
            (*j)--;
            comparacoes++;
        }
        comparacoes++;

        if (*i <= *j){
            escreveMemLog((long int)(&vetor[*i]), sizeof(long int), 1);
            aux = vetor[*i];
            vetor[*i] = vetor[*j];
            vetor[*j] = aux;
            (*i)++;
            (*j)--;
        }
    }
}

void QuickSorts::quickSortRecursivo(Registro *vetor, int esquerda, int direita){
    int i , j;

    this->Particao(vetor, esquerda, direita, &i, &j);

    if (j > esquerda){
        leMemLog((long int)(&(vetor[j])), sizeof(long int), 0);
        quickSortRecursivo(vetor, esquerda, j);
    }
    if (i < direita){
        leMemLog((long int)(&(vetor[i])), sizeof(long int), 0);
        quickSortRecursivo(vetor, i, direita);
    }
}

void QuickSorts::quickSortMediana(Registro *vetor, int esquerda, int direita, int k){
    int i , j;
    int pivo;
    Registro aux;

    i = esquerda;
    j = direita;

    pivo = vetor[(i + j) / 2].getChave(); //caso não consiga achar o pivor mediana, usa esse

    try {
        pivo = this->escolherPivor(vetor, k, esquerda, direita);
    }
    catch(std::string ex) {
        std::cout << "valor de k inválido" << '\n';
    } 

    while (i <= j)
    {
        while (vetor[i].getChave() < pivo){
            leMemLog((long int)(&(vetor[i])), sizeof(long int), 0);
            i++;
            comparacoes++;
        }
        comparacoes++;

        while (vetor[j].getChave() > pivo){
            leMemLog((long int)(&(vetor[j])), sizeof(long int), 0);
            j--;
            comparacoes++;
        }
        comparacoes++;
        if (i <= j)
        {
            escreveMemLog((long int)(&vetor[i]), sizeof(long int), 1);
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            (i++);
            (j--);
        }
    }

    if (j > esquerda)
        quickSortMediana(vetor, esquerda, j, k);
    if (i < direita)
        quickSortMediana(vetor, i, direita, k);
}

void QuickSorts::quickSortSelecao(Registro *vetor, int esquerda, int direita, int m){
    int i , j;

    this->Particao(vetor, esquerda, direita, &i, &j);

    escreveMemLog((long int)(&vetor), sizeof(long int), 0);
    if(direita - esquerda + 1 <= m){
        Selecao(vetor, j - i);
    }
    else{
        if (j > esquerda)
        quickSortSelecao(vetor, esquerda, j, m);
    if (i < direita )
        quickSortSelecao(vetor, i, direita, m);
    } 
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
        dir = pilha->topo->item.direita;
        esq = pilha->topo->item.esquerda;
        
        if (dir > esq) {
            Particao(vetor, esq, dir, &i, &j);
            leMemLog((long int)(&pilha), sizeof(long int), 0);
            pilha->Desempilha();

            escreveMemLog((long int)(&pilha), sizeof(long int), 0);
            item.direita = j;
            item.esquerda = esq;
            pilha->Empilha(item);

            escreveMemLog((long int)(&pilha), sizeof(long int), 0);
            item.esquerda = i;
            item.direita = dir;
            pilha->Empilha(item);
        }
        else {
            pilha->Desempilha();
        }
    } while (!pilha->Vazia());

    pilha->Limpa();
}

void QuickSorts::quickSortNaoRecursivoInteligente(Registro *vetor, int n){
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
        dir = pilha->topo->item.direita;
        esq = pilha->topo->item.esquerda;

        if (dir > esq) {

            Particao(vetor, esq, dir, &i, &j);
            leMemLog((long int)(&pilha), sizeof(long int), 0);
            pilha->Desempilha();

            if ((j-esq)>(dir-i)) {
                escreveMemLog((long int)(&pilha), sizeof(long int), 0);
                item.direita = j;
                item.esquerda = esq;
                pilha->Empilha(item);

                escreveMemLog((long int)(&pilha), sizeof(long int), 0);
                item.esquerda = i;
                item.direita = dir;
                pilha->Empilha(item);
            }
            else {
                escreveMemLog((long int)(&pilha), sizeof(long int), 0);
                item.esquerda = i;
                item.direita = dir;
                pilha->Empilha(item);

                escreveMemLog((long int)(&pilha), sizeof(long int), 0);
                item.direita = j;
                item.esquerda = esq;
                pilha->Empilha(item);
            }
        }
        else {
            pilha->Desempilha();
        }
    } while (!pilha->Vazia());

    pilha->Limpa();
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
    this->Selecao(aux, k);

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
            comparacoes++;
            if (vetor[j].getChave() < vetor[min].getChave())
                min = j;
        }

        escreveMemLog((long int)(&vetor[i]), sizeof(long int), 1);
        aux = vetor[i];
        vetor[i] = vetor[min];
        vetor[min] = aux;
    }
}
