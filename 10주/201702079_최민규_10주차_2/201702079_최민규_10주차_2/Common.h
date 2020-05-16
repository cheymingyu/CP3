#pragma once
#include <stdlib.h>
#include <stdio.h>

#define NewObject(TYPE) (TYPE*)malloc(sizeof(TYPE))
#define NewVector(TYPE,SIZE) (TYPE*)malloc(sizeof(TYPE)*SIZE)
#define isDigit(CHAR) (('0' <= CHAR) && (CHAR <= '9'))
#define isAlpha(CHAR) (('a' <= CHAR) && (CHAR <= 'z') || ('A' <= CHAR) && (CHAR <= 'Z'))

typedef enum { FALSE, TRUE } Boolean;
typedef int Element;
typedef enum {
	PostfixError_None,
	PostfixError_ExpressionTooLong,
	PostfixError_OperandsTooMany,
	PostfixError_OperandsTooFew,
	PostfixError_UnknownOperator,
	PostfixError_DivideByZero
} PostfixError;