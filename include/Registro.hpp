#ifndef _REGISTRO_
#define _REGISTRO_

class Registro{
    private:
        int chave;
        char cadeia[15][200];
        double numerosReais[10];
    
    public:
        int getChave(){ return chave;}
        Registro(int chave, char cadeia[][], int numerosReais[]);
};

#endif
