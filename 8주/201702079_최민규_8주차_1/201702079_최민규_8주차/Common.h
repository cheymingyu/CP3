#pragma once
#include <stdlib.h>
#include <stdio.h>

#define NewObject(TYPE) (TYPE*)malloc(sizeof(TYPE))
#define NewVector(TYPE,SIZE) (TYPE*)malloc(sizeof(TYPE)*SIZE)

#define SWAP(TYPE, X, Y) {TYPE temp = X; X=Y; Y = temp;}

typedef enum { FALSE, TRUE } Boolean;