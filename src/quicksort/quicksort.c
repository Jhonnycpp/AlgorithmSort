/*
Sullivan Santos Castilho        GU3020363
Luiza Maria Barros de Oliveira  GU3022315
Isabela de Souza Santana        GU3020584
Carlos ALberto Siqueira Silva   GU3022293
*/

#include "quicksort.h"

void quick_sort(int * vetor, int inicio, int fim);

void quicksort(int * vetor, int size) {
    quick_sort(vetor, 0, size);
}

void quick_sort(int * vetor, int inicio, int fim) {
    int pivo, esq, dir, meio, aux;

    //Limites da esquerda e direita da região analisada
    esq = inicio;
    dir = fim;

    //Ajustando auxiliares do centro
    meio =  (int) ((esq + dir) / 2); // a variável meio é a que divide a lista em 2
    pivo = vetor[meio]; //valor que está no meio da lista


    while(dir > esq){ // Espera-se que o limite da direita seja maior que o da esquerda para ser analisado enquanto o codigo abaixo é executado

        while(vetor[esq] < pivo){ //se este valor for menor que o pivo está tudo certo fazendo uma análise comparativa
            esq = esq + 1;
        }

        while(vetor[dir] > pivo){  //se este valor for maior que o pivo está tudo certo fazendo uma análise comparativa
            dir = dir - 1;
        }

        if(esq <= dir){ // se o limite da esquerda e da direita se cruzam

            //Realiza uma troca se os valores estiverem na posição contrária
            aux = vetor[esq];
            vetor[esq] = vetor[dir]; // vetor da esquerda recebe o da direita
            vetor[dir] = aux; // vetor da direita recebe o auxiliar

            //Faz os limites laterais caminharem para o centro
            esq = esq + 1;
            dir = dir - 1;

        }

    }
    // Análise de posições e não de valores
    //Recursão para continuar ordenando (chamando o método criado)
    if(inicio < dir){
        quick_sort(vetor, inicio, dir);
    }

     //Recursão para continuar ordenando
    if(esq < fim){
         quick_sort(vetor, esq, fim);
    }

}