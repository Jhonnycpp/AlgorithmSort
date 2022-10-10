#ifndef UTILS_H_   /* Include guard */
#define UTILS_H_

#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

#ifdef _WIN32
#define CLEAR system("cls")
#elif defined _WIN64
#define CLEAR system("cls")
#elif defined __unix__
#define CLEAR system("clear")
#elif defined __APPLE__
#define CLEAR system("clear")
#endif

void pauseTerminal();

#endif // UTILS_H_