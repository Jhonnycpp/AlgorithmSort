#ifndef ORDER_H_   /* Include guard */
#define ORDER_H_

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

#include "utils.h"

typedef void (measureBlock)(int *, int);

typedef struct MeasureAlgorithm {
    measureBlock * block;
    int size;
} MeasureAlgorithm_t;

int measureAlgorithm(void * data);

#endif // ORDER_H_