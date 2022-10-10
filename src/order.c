#include "order.h"
#define CALC_DELTA(start, finish) 1000.0 * (finish - start) / CLOCKS_PER_SEC

void measure(measureBlock * block, int size);
void badTime(measureBlock * block, int size);
void goodTime(measureBlock * block, int size);
int * createRandomVectorNumbers(int size, int base);

int measureAlgorithm(void * data) {
  srand(time(NULL));
  MeasureAlgorithm_t * algorithm_data = (MeasureAlgorithm_t *) data;

  measure(algorithm_data->block, algorithm_data->size);
  goodTime(algorithm_data->block, algorithm_data->size);
  badTime(algorithm_data->block, algorithm_data->size);

  pauseTerminal();

  return FALSE;
}

void goodTime(measureBlock * block, int size) {
  int * numbers = NULL;
  clock_t start, finish;
  double delta = 0;

  numbers = calloc(size, sizeof(int));

  for (int i = 0; i < size; i++) numbers[i] = i;

  start = clock();
  block(numbers, size);
  finish = clock();
  delta = CALC_DELTA(start, finish);
  free(numbers);
  printf("Tempo no melhor caso de execução é de: %f milisegundos\n", delta);
}

void badTime(measureBlock * block, int size) {
  int * numbers = NULL;
  clock_t start, finish;
  double delta = 0;
  numbers = calloc(size, sizeof(int));

  for (int i = 0; i < size; i++) numbers[i] = size - i;

  start = clock();
  block(numbers, size);
  finish = clock();
  delta = CALC_DELTA(start, finish);
  free(numbers);
  printf("Tempo no pior caso de execução é de: %f milisegundos\n", delta);
}

void measure(measureBlock * block, int size) {
  double avg[10];

  for (int i = 0; i < 10; i++) {
    int * numbers = createRandomVectorNumbers(size, 1000);

    clock_t start, finish;

    start = clock();
    block(numbers, size);
    finish = clock();
    double delta = CALC_DELTA(start, finish);
    avg[i] = delta;
    free(numbers);
  }

  double acc = 0;
  for (int i = 0; i < 10; i++) acc += avg[i];

  printf("Tempo médio de execução dos comandos é de: %f milisegundos\n", acc / 10);
}

int * createRandomVectorNumbers(int size, int base) {
  int * numbers = calloc(size, sizeof(int));
  for (int i = 0; i < size; i++) numbers[i] = rand() % base;
  return numbers;
}