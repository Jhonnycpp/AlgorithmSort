#include "mymenu.h"

void addMenu(Menu_t * menu, char * text, int id, onSelected block, void * data) {
  if (menu == NULL) return;

  ItemMenu_t * item = calloc(1, sizeof(ItemMenu_t));
  item->text = text;
  item->id = id;
  item->block = block;
  item->data = data;

  if (menu->start == NULL) {
    menu->start = item;
  } else {
    ItemMenu_t * current = menu->start;
    while (current != NULL) {
      if (current->next == NULL) {
        current->next = item;
        break;
      }
      current = current->next;
    }
  }
  menu->size++;
}

Menu_t* newMenu(char * title) {
  Menu_t * menu = (Menu_t *) calloc(1, sizeof(Menu_t));
  menu->title = title;
  return menu;
}

void freeMenu(Menu_t * menu) {
  if (menu == NULL) return;

  ItemMenu_t * current = menu->start;
  while (current != NULL) {
    menu->start = current->next;
    free(current);
    current = menu->start;
  }
  free(menu);
}

void bindingMenu(Menu_t * menu) {
  if (menu == NULL || menu->start == NULL) return;

  int code = 0, isExit = FALSE;
  printf("\nQual opção? ");
  scanf("%d", &code);

  ItemMenu_t * current = menu->start;
  while (current != NULL) {
    if (code == current->id) isExit = current->block(current->data);
    current = current->next;
  }

  if (!isExit) {
    showMenu(menu);
    bindingMenu(menu);
  }
}

void showMenu(Menu_t * menu) {
  if (menu == NULL || menu->start == NULL) return;

  CLEAR;
  printf("\n%s\n", menu->title);
  ItemMenu_t * current = menu->start;
  while (current != NULL) {
    printf("%d - %s\n", current->id, current->text);
    current = current->next;
  }
}