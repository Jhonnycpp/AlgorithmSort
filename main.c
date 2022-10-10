#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

#include "mymenu.h"
#include "order.h"

#include "mergesort.h"
#include "shellsort.h"
#include "timsort.h"
#include "quicksort.h"
#include "heapsort.h"
#include "countingsort.h"
#include "radixsort.h"
#include "bubblesort.h"
#include "selectionsort.h"
#include "insertionsort.h"

#define MENU_MSG " - Quantos números deseja gerar para a ordenação?"

typedef struct AlgorithmMenu {
  measureBlock * block;
  char * name;
} AlgorithmMenu_t;

int finish(void * data);
int createAlgorithmMenu(void * data);

int main() {
  Menu_t * menu = newMenu("Escolha qual algoritmo de ordenação deseja executar?");

  AlgorithmMenu_t mergesortMenu = { .block = &ms, .name = "Mergesort" };
  AlgorithmMenu_t shellsortMenu = { .block = &shellsort, .name = "Shellsort" };
  AlgorithmMenu_t timsortMenu = { .block = &timSort, .name = "Timsort" };
  AlgorithmMenu_t quicksortMenu = { .block = &quicksort, .name = "Quicksort" };
  AlgorithmMenu_t heapsortMenu = { .block = &hs, .name = "Heapsort" };
  AlgorithmMenu_t countingsortMenu = { .block = &countingsort, .name = "Countingsort" };
  AlgorithmMenu_t radixsortMenu = { .block = &rs, .name = "Radixsort" };
  AlgorithmMenu_t bubblesortMenu = { .block = &bubblesort, .name = "Bubblesort" };
  AlgorithmMenu_t selectionsortMenu = { .block = &selectionsort, .name = "Selectionsort" };
  AlgorithmMenu_t insertionsortMenu = { .block = &insertionsort, .name = "Insertionsort" };

  addMenu(menu, "Mergesort", 0, &createAlgorithmMenu, (void *) &mergesortMenu);
  addMenu(menu, "Shellsort", 1, &createAlgorithmMenu, (void *) &shellsortMenu);
  addMenu(menu, "Timsort", 2, &createAlgorithmMenu, (void *) &timsortMenu);
  addMenu(menu, "Quicksort", 3, &createAlgorithmMenu, (void *) &quicksortMenu);
  addMenu(menu, "Heapsort", 4, &createAlgorithmMenu, (void *) &heapsortMenu);
  addMenu(menu, "Countingsort", 5, &createAlgorithmMenu, (void *) &countingsortMenu);
  addMenu(menu, "Radixsort", 6, &createAlgorithmMenu, (void *) &radixsortMenu);
  addMenu(menu, "Bubblesort", 7, &createAlgorithmMenu, (void *) &bubblesortMenu);
  addMenu(menu, "Selectionsort", 8, &createAlgorithmMenu, (void *) &selectionsortMenu);
  addMenu(menu, "Insertionsort", 9, &createAlgorithmMenu, (void *) &insertionsortMenu);
  addMenu(menu, "End", 10, &finish, NULL);

  showMenu(menu);
  bindingMenu(menu);

  freeMenu(menu);

  return 0;
}

int finish(void * data) {
  return TRUE;
}

int createAlgorithmMenu(void * data) {
  AlgorithmMenu_t * algorithmMenu = (AlgorithmMenu_t *) data;

  int titleLenght = strlen(algorithmMenu->name) + strlen(MENU_MSG) + 2;
  char menuTitle[titleLenght];
  memset(menuTitle, 0, titleLenght);
  strcat(menuTitle, algorithmMenu->name);
  strcat(menuTitle, MENU_MSG);

  Menu_t * menu = newMenu(menuTitle);

  MeasureAlgorithm_t alg1 = { .block = algorithmMenu->block, .size = 1000 };
  MeasureAlgorithm_t alg5 = { .block = algorithmMenu->block, .size = 5000 };
  MeasureAlgorithm_t alg10 = { .block = algorithmMenu->block, .size = 10000 };
  MeasureAlgorithm_t alg20 = { .block = algorithmMenu->block, .size = 20000 };
  MeasureAlgorithm_t alg50 = { .block = algorithmMenu->block, .size = 50000 };
  MeasureAlgorithm_t alg100 = { .block = algorithmMenu->block, .size = 100000 };

  addMenu(menu, "1.000", 0, &measureAlgorithm, (void *) &alg1);
  addMenu(menu, "5.000", 1, &measureAlgorithm, (void *) &alg5);
  addMenu(menu, "10.000", 2, &measureAlgorithm, (void *) &alg10);
  addMenu(menu, "20.000", 3, &measureAlgorithm, (void *) &alg20);
  addMenu(menu, "50.000", 4, &measureAlgorithm, (void *) &alg50);
  addMenu(menu, "100.000", 5, &measureAlgorithm, (void *) &alg100);
  addMenu(menu, "End", 10, &finish, NULL);

  showMenu(menu);
  bindingMenu(menu);

  freeMenu(menu);

  return FALSE;
}