#include "radixsort.h"

//protótipos
int pega_Valor_Max(int array[], int n);
void contador(int array[], int tamanho, int divisor);

// Essa função retornará o maior elemento do Array
int pega_Valor_Max(int array[], int n) {
  int max = array[0];   //max irá receber o vetor da posição zero
  for (int i = 1; i < n; i++)
    if (array[i] > max){    //Aqui o programa irá verificar
                            //se o vetor passado possui um
                            //valor maior q max
        max = array[i];     //assim a variavel max irá receber
                            //o valor mais alto ate o programa
                            // rodar todo o vetor
      }
  return max;
}

// Usando counting sort para classificar os elementos com base
// em lugares significativos
void contador(int array[], int tamanho, int divisor) {
  int resultado[tamanho + 1]; //Declarando a varivel resultado com o tamanho + 1
  int max = (array[0] / divisor) % 10;//Declarando a variavel max com
                                        //o array na primeira posição divido pelo
                                        // o divisor
                                      // que possui a finalidade de transitar entre
                                      // as casas

  for (int i = 1; i < tamanho; i++){
    if (((array[i] / divisor) % 10) > max)
      max = array[i];
  }// um laço de repetição para contar a frenquencias dos digitos
  // e para descobrir o valor max

  int count[max + 1];

  for (int i = 0; i < max; ++i){
    count[i] = 0;
    }// laço de repetição para zerar as casas
    // do vetor e guardar o valor max

  // Calculando a quantidade de elementos
  for (int i = 0; i < tamanho; i++){
    count[(array[i] / divisor) % 10]++;
  }

  // Calculando a soma acumulativa
  for (int i = 1; i < 10; i++){
    count[i] += count[i - 1];
  }

  // Coloca os elementos em ordem no vetor resultado,
  // para passar para o array
  // ou seja, salvando os valores ordenados em
  //array para depois ordena o array
  for (int i = tamanho - 1; i >= 0; i--) {
    resultado[count[(array[i] / divisor) % 10] - 1] = array[i];
    count[(array[i] / divisor) % 10]--;
  }
    // laço de repetição que copia o array ordenado
  for (int i = 0; i < tamanho; i++){
    array[i] = resultado[i];
  }
}

// Função principal para implementação do Radix
void rs(int array[], int tamanho) {
  // Pegando o elemento maximo
  int max = pega_Valor_Max(array, tamanho);

  // Aplicando o contador para classificar elementos com base no valor
  // posicional ou seja verificando sua casa "unidade,dezena,centena...".
  for (int lugar = 1; max / lugar > 0; lugar *= 10){
    contador(array, tamanho, lugar);
    }
}

