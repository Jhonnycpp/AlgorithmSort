#include "countingsort.h"

void countingsort(int * vet, int size) {
    int maior = vet[0], indice, j, quantidade;
    for(int i = 0; i < size; i++){
        if(vet[i] > maior){
            maior = vet[i];
        }
    }

    int vet_counting_sort[maior+1];

    for(int i = 0; i < maior + 1;i++){
        vet_counting_sort[i]=0;
    }

    for(int i = 0; i < size;i++){
        indice = vet[i];
        vet_counting_sort[indice]++;
    }
}
