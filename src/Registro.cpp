#include "Registro.hpp"

void Registro::setRegistro(int chave, char ** cadeia, double * numerosReais){
    this->chave = chave;
    this->cadeia = cadeia;
    this->numerosReais = numerosReais;
}
