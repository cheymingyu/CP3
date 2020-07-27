#pragma once
#include <stdlib.h>

#define NewObject(TYPE) (TYPE*)malloc(sizeof(TYPE))
#define NewVector(TYPE,SIZE) (TYPE*)malloc(sizeof(TYPE)*SIZE)
#define isDigit(CHAR) (('0' <= CHAR) && (CHAR <= '9'))
#define isAlpha(CHAR) (('a' <= CHAR) && (CHAR <= 'z') || ('A' <= CHAR) && (CHAR <= 'Z'))

typedef enum { FALSE, TRUE } Boolean;
typedef char Element;