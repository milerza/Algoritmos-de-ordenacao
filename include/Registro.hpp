 #ifndef _REGISTRO_
#define _REGISTRO_

class Registro{
    private:
        int chave;
        char ** cadeia;
        float *numerosReais;
    
    public:
        int getChave(){ return chave;}
        void setChave(int chave){ this->chave = chave;}
        void setRegistro(int chave, char ** cadeia, float * numerosReais);
};

#endif
