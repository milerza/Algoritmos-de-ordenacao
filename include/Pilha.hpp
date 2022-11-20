#ifndef _PILHA_
#define _PILHA_

#include "Registro.hpp"

class Pilha
{
    public:
        Pilha(){tamanho = 0;};
        int GetTamanho() {return tamanho;};
        bool Vazia() {return tamanho == 0;};
        virtual void Empilha(Registro item) = 0;
        virtual Registro Desempilha() = 0;
        virtual void Limpa() = 0;
    protected:
        int tamanho;
};

class PilhaEncadeada : public Pilha
{
    public:
        PilhaEncadeada();
        virtual ~PilhaEncadeada();
        void Empilha(Registro item);
        Registro Desempilha();
        void Limpa();
    private:
        
};

class TipoCelula
{
    public:
        TipoCelula();
    private:
        Registro item;
        TipoCelula *prox;
        friend class PilhaEncadeada;
};

#endif;