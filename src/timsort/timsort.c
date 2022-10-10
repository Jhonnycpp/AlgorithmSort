#include "timsort.h"

void insertionSort(int arr[], int l, int r);
void timmerge(int arr[], int temp[], int l, int m, int r);
int min(int arg1, int arg2);
void printIntArray(int arr[], unsigned int size);

// =============== Funcoes auxiliares ===============(Nao retirar e deixar como subtitulo)
//Abaixo esta uma funcao auxiliar que pode ordenar um array por ordenacao por insercao.
//Nome: insertionSort
// Input(s):
//(1)'arr' e um ponteiro para um endereco inteiro.
//Este e o inicio de algum 'bloco de memoria contiguo' que vamos classificar.
//(2) 'l' e 'r' sao inteiros, que sao o primeiro indice e o ultimo indice de 'arr' respectivamente.
//Output: Nenhum valor e retornado, mas 'arr' deve ser modificado para armazenar uma matriz ordenada de numeros.

void insertionSort(int arr[], int l, int r) { // funcao e declarada com o vetor, o valor de i do for na funcao timsort e o retorno de arg1 ou arg2 da funcao min
    if (arr == NULL || l>=r) return; // se o vetor for nulo ou l(i do for da funcao timsort) for maior ou igual a r(resultado da funcao min) entao returna nada

    int key;
    int i, j; // variaveis locais criadas para o for da funcao
    for (i=l+1; i<=r; i++) { // repeticao comparando a sentenca de i sendo menor ou igual a r 
        key = arr[i]; // enquanto verdadeiro variavel key recebe valor do indice do vetor onde o indice e igual a i da funcao
        j = i-1; // variavel j recebe o valor de i - 1 ficando assim com o indice anterior ao de i
        while (j>=l && arr[j]>key) { //enquanto o j for maior e igual a l e o valor do vetor no indice j for maior que key 
            arr[j+1] = arr[j]; // indice j+1 no vetor recebe valor do indice j do vetor
            j--; //j e decrementado
        }
        arr[j+1] = key; // apos terminar o while o vetor no indice j+1 recebe o valor de key 
    }

}

//==============funcao de mesclagem.=============(Fazer como subtitulo)
//Nome: timmerge
//Input(s):
//(1)'arr' e um ponteiro para um endereco inteiro.
//Este e o inicio 'bloco de memoria contiguo' que vamos classificar.
//(2) 'temp' e um ponteiro para um endereco inteiro.

//Isso ajuda a armazenar temporariamente o subarray classificado.
//(3) 'l', 'm' e 'r' sao inteiros, que sao o primeiro indice, o meio e o ultimo indice de 'array' respectivamente.
//Output: Nenhum valor e retornado, mas 'array' deve ser modificado para armazenar um array ordenado de numeros.
void timmerge(int arr[], int temp[], int l, int m, int r){// funcao e declarada com vetor principal, vetor temporario, l que e o valor de for da funcao timsort, m tambem da funcao timsort e r da funcao timsort
    if (arr == NULL || temp == NULL) return; // comparativo onde vetor caso nulo ou vetor temporario caso nulo retorna nada
    if (l > m || m+1 > r) return; // se l for maior que m ou m+1 for maior que r returna nada

    int i = l; // i recebe l
    int j = m + 1; // j recebe m mais 1
    int start = l; // start recebe l // variaveis locais criadas para while

    while (i <= m && j <= r){ //enquanto i for menor ou igual a m  e j for menor ou igual a r
	if (arr[i] < arr[j]){ // se indice i do vetor for menor a indice j do vetor entao
	    temp[start++] = arr[i++];// indice start incrementado do vetor temporario receber valor do indice i incrementado do vetor principal
	} else if (arr[i] == arr[j]){ // se nao for verdadeiro e indice i do vetor for igual a indice j do vetor
	    temp[start++] = arr[i++]; // indice start incrementado do vetor temporario receber valor do indice i incrementado do vetor principal

	    temp[start++] = arr[j++]; //indice start incrementado do vetor temporario receber valor do indice j incrementado do vetor principal
	}
	else{ // se nenhuma das comparacoes for verdadeira
	    temp[start++] = arr[j++];//indice start incrementado do vetor temporario receber valor do indice j incrementado do vetor principal
	}

    }

    while (i <= m){ // enquanto i for menor ou igual a m
	    temp[start++] = arr[i++]; // indice start incrementado do vetor temporario receber valor do indice i incrementado do vetor principal 
    }


    while (j <= r){ //enquanto j menor ou igual a r
	    temp[start++] = arr[j++]; // indice start incrementado do vetor temporario receber valor do indice j incrementado do vetor principal
    }

    for (i = l; i <= r; i++){ // repeticao ocorre enquanto i for menor ou  igual a r
	    arr[i] = temp[i]; // indice i do vetor principal receber valor do indice i do vetor temporario
    }
}

//===============funcao min=============(subtitulo)
//Nome: min
//Input(s):
//(1) 'arg1' and 'arg2' sao dois inteiros para comparar.
//Output:o menor inteiro.

//Resumo: funcao que divide em subvetores.

int min(int arg1, int arg2){ // funcao que foi chamada para o comparativo de dois valores arg1(entra o valor de i+RUN-1) e arg2 (Valor de size-1)
    if (arg1 <= arg2){ // comparativo entre arg1 sendo menor ou igual a arg2
        return arg1; // se verdadeiro retorna o valor arg1
    } else {
        return arg2;// se falso retorna valor de arg2
    }
}

//==============funcao de classificacao.=========(subtitulo)
//Name: timSort
//Input(s):
//(1) 'arr' e um ponteiro para um endereco inteiro
//Este e o inicio de 'bloco de memoria contiguo' que iremos sort.
//(2)'size' nos diz o tamanho do array de dados que estamos classificando.
// Output: Nenhum valor e retornado, mas 'arr' deve ser modificado para armazenar uma matriz ordenada de numeros.
//Comece a mesclar a partir do tamanho RUN. Ele sera mesclado no tamanho 2*RUN, depois 4*RUN, e assim por diante.
//'l', 'm' e 'r' sao os indices esquerdo, medio e direito de dois subarranjos contiguos.
//'n' e o tamanho de um subarray.
// Resumo : Mesclagem em varios tempo de respostas

void timSort(int arr[], int size){ //funcao e declarada com o vetor e o tamanho do vetor em variavel sem sinal
    if (arr == NULL || size <= 1) return; //comparacao para ver se o vetor e nulo ou o tamanho dele e menor que 1, se sim retorna nada
    for (int i=0; i < size; i+=RUN){ //caso nao inicia o for para iniciar uma repeticao baseado no tamanho de run 
        insertionSort(arr, i, min(i+RUN-1, size-1)); // a repeticao serve para chamar nova funcao chamada insertionsort que fara a ordenacao dos vetores, ela e declarada com o vetor, o valor de i sendo essa uma variavel auxiliar e uma funcao chamada min
    }

    int* temp = (int*)malloc(sizeof(int)*size);// e criado um vetor temporario e alocado em memoria 


    int l, m, r, n; // criacao de variaveis locais para utilizacao em for
    for (n=RUN; n < size; n*=2){// repeticao acontece durante n for menor que size(tamanho do vetor), n recebe n vezes 2
        for (l=0; l < size; l+=2*n){ //repeticao acontece durante l for menor que size e l recebe a soma de l mais duas vezes o valor de n
            m = l+n-1; // m recebe valor de l mais n menos 1
            r = min(l+2*n-1, size-1); // recebe valor da funcao min correspondente ao arg1 sendo l+2*n-1 e arg2 size-1, o resultado que a funcao der esse e o valor inserido em r
            if (m<r){ // comparativo do valor obtido de m sendo menor que o resultado de r
                timmerge(arr, temp, l, m, r);// caso verdadeiro chama a funcao merge
            }
        }
    }
    free(temp); // libera valor allocado de temp
}
