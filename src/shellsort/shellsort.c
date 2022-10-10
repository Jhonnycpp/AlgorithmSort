// Funcao de ordenacao de algoritmos: ShellSort.
// Sao passados 2 parametros para a funcao: o endereco
// da vetor e seu tamanho definido na constante;
void shellsort(int *V, int N){

    // Declaracao de variáveis.
    // i, j: Servem para referenciar as posicoes/indices do vetor.
    // aux: variavel auxiliar que ira guardar o elemento das comparacoes
    // h: o coeficiente que irá determinar a distancia do salto entre os
    // vetores para melhor performar a ordenacao.
    int i, j, h, aux;

    // Antes de efetuar leituras no vetor, o programa primeiro precisa
    // identificar qual o melhor salto que pode ser feito entre os
    // elementos para entao serem ordenados mais rapidamente. Para isso,
    // o programa atribui um novo valor para h até que este valor seja
    // menor que o numero de elementos do vetor dividido poor tres
    h = 1;
    while(h < N/3){
        h = 3 * h + 1;
    }


    // Apos definir o h, o programa ira comecar a comparar os elementos
    // em h posicoes até que o vetor chege ao fim. Porem, ainda irao
    // existir elementos que nao foram comparados entre si, isso implica
    // na reducao do valor de h para que posicoes que nao foram comparadas
    // passem a ser, e isso se repete ate que o h seja reduzido para o valor
    // 1. Neste ponto, o programa ira funcionar com o sistema de ordenacao
    // do insertion sort, que compara elementos de 1 posicao de distancia.
    // Assim que a ultima passada no vetor for efetuada comparando elementos
    // de 1 posicao de distancia, o h sera reduzido a um valor menor que 1 no
    // final do laço, mas neste ponto, o vetor ja estara ordenado, e e por isso
    // que criamos um laco que so executa a ordenacao enquanto h for maior que 0.
    while(h > 0){

        // Aqui comecamos a comparacao ate que o vetor termine.
        // i vai receber o valor de h, e o valor auxiliar sera
        // aquele na posicao i do vetor, exemplo:

        //  v = {110, 104, 123, 91, 2, 44, 901, 84, 10, 78};
        //  i = 4;
        //      aux = 2
        //      j = 4
        for(i = h; i < N; i++){
            aux = V[i];
            j = i;

            // Em seguida, entramo no laco para verificar se o elemento
            // da posicao j e maior que o elemento na posicao h:

            // 4 >= 4 && 2 < 110? TRUE

            // Em caso positivo, o elemento de indice j recebe o valor
            // da posicao j-h, enquanto o j é decrementado em h unidades:

            // v[4] = v[0]
            // j = 4-4 = 0

            // Dessa forma, os elementos vao sempre ser comparados assim:

            // v[4] com v[0]
            // v[5] com v[1]
            // v[6] com v[2]
            // v[7] com v[3]
            // v[8] com v[4]
            // v[9] com v[5]


            while(j >= h && aux < V[j - h]){
                V[j] = V[j - h];
                j = j - h;

            }

            // O valor auxiliar so e recuperado e reordenado da variavel aux
            // no final das comparacoes do laco while anterior. Isto e importante
            // pois, eventualmente, o valor de h sera igual a 1, e mais de uma
            // comparacao pode ser feita no laco while anterior, e mais elementos
            // devem ser ordenados para que assim a insercao do valor na variavel
            // auxiliar ocorra de forma ordenada.
            V[j] = aux;


        }

        // Depois que todas as comparacoes sao feitas com o intervalo de h posicoes,
        // o valor e reajustado da melhor forma atraves da formula abaixo, e mais uma
        // vez os valores sao comparados entre o novo valor de h posicoes de distancia
        // no vetor ate que o resultado dessa formula para h seja menor que 0, onde a
        // ordenacao e encerrada.

        // h = (4-1)/3
        // h = 1
        h = (h-1)/3;

    }

}