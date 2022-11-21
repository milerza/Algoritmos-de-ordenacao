#include "Registro.hpp"

void Registro::setRegistro(int chave, char ** cadeia, float * numerosReais){
    this->chave = chave;
    this->cadeia = cadeia;
    this->numerosReais = numerosReais;
}
