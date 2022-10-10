#ifndef MENU_H_   /* Include guard */
#define MENU_H_

#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

typedef int (onSelected)(void *);

typedef struct ItemMenu {
  int id;
  char * text;
  onSelected * block;
  void * data;
  struct ItemMenu * next;
} ItemMenu_t;

typedef struct Menu {
  ItemMenu_t * start;
  int size;
  char * title;
} Menu_t;

Menu_t * newMenu(char * title);
void addMenu(Menu_t * menu, char * text, int id, onSelected block, void * data);
void showMenu(Menu_t * menu);
void freeMenu(Menu_t * menu);
void bindingMenu(Menu_t * menu);

#endif // MENU_H_