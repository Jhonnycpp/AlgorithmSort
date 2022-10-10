#include "utils.h"

void pauseTerminal() {
  fflush(stdin);
  printf("\nPressione enter para continuar...\n");
  getchar();
}