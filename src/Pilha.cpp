#include "Pilha.hpp"

TipoCelula::TipoCelula(){
    item.setChave(-1);
    prox = nullptr;
}

PilhaEncadeada::PilhaEncadeada() : Pilha(){
    topo = nullptr;
}

PilhaEncadeada::~PilhaEncadeada(){
    Limpa();
}

void PilhaEncadeada::Empilha(TipoItem item){
    TipoCelula *nova;

    nova = new TipoCelula();
    nova->item = item;
    nova->prox = topo;
    topo = nova;
    tamanho++;
};

TipoItem PilhaEncadeada::Desempilha(){
    Registro aux;
    TipoCelula *p;

    if(tamanho == 0)
        throw "A pilha está vazia!";

    aux = topo->item;
    p = topo;
    topo = topo->prox;

    delete p;
    tamanho--;
    return aux;
};

void PilhaEncadeada::Limpa(){
    while(!Vazia())
        Desempilha();
}