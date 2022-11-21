/*#include "Sorts.hpp"


int *Sorts::merge(int *valuesL, int *valuesR, int nl, int nr) {
    int *result = (int *)

    malloc((nl+nr) * sizeof(int));

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < nl && j < nr) {
        if (valuesL[i] < valuesR[j]) {
            result[k] = valuesL[i];
            i++;
        } 
        else {
            result[k] = valuesR[j];
            j++;
        }
        k++;
    }
    if (k < nl + nr) {
        for(; i < nl; i++) {
            result[k] = valuesL[i];
            k++;
        }
        for(; j < nr; j++) {
            result[k] = valuesR[j];
            k++;
        }
    }
    return result;
} 
   
void Sorts::mergeSort(Registro * registro, int esquerda, int direita) 
{ 
    if (esquerda < direita) { 
        //Dividindo o vetor
        int meio = esquerda + (direita - esquerda) / 2; 

        mergeSort(registro, esquerda, meio); 
        mergeSort(registro, meio + 1, direita); 

        //combinando
        merge(registro, esquerda, meio, direita); 
    } 
} 

*/