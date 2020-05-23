#pragma once
#include <stdlib.h>
#include <stdio.h>

#define NewObject(TYPE) (TYPE*)malloc(sizeof(TYPE))
#define NewVector(TYPE,SIZE) (TYPE*)malloc(sizeof(TYPE)*SIZE)
#define ELEMENT_DOES_NOT_EXIST -1;

typedef enum { FALSE, TRUE } Boolean;
typedef int Element;