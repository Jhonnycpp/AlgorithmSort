#include "bubblesort.h"

void bubblesort(int * v, int n) {
    int i, continua, aux, fim = n;
    do {
        continua = 0;
        for(i = 0; i < fim - 1; i++) {
            if(v[i] > v[i + 1]) {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                continua = i;
            }
        }
        fim--;
    } while(continua != 0);
}