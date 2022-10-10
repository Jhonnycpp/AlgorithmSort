#include "heapsort.h"

void criaHeap (int *vet, int i, int f);

void hs(int *vet, int n)
{
	int i, aux;

	for (i = (n - 1) / 2; i >= 0; i--) //cria heap a partir dos dados
    {                                  //metade do vetor até a primeira posição e analisar para criar heap
		criaHeap(vet, i, n - 1);
	}

	for (i = n-1; i >= 1; i--) //reconstruir heap
    {
		aux = vet[0];       //pega o maior elemento da heap e coloca na sua posição correspondente no array (quando no topo, tirando ele da heap)
		vet[0] = vet[i];
		vet[i] = aux;
		criaHeap(vet, 0, i - 1);
	}
}

void criaHeap (int *vet, int i, int f)
{
    int aux = vet[i]; //auxiliar primeira posição da partição
    int j = i * 2 + 1; //primeiro filho dele

    while (j <= f){ //enquanto filho menor do que o final do vetor
        if (j < f){
            if(vet[j] < vet [j+1]){ //pai tem 2 filhos? quem é o maior?
                j = j +1;
            }
        }
        if (aux < vet[j]){  //filho maior que o pai?
            vet[i] = vet[j]; //filho se torna o pai!
            i = j;           //repetir o processo
            j = 2 * i + 1;
        }else{
            j = f + 1;
        }
    }
    vet[i] = aux; //antigo pai ocupa lugar o último filho analisado
}
