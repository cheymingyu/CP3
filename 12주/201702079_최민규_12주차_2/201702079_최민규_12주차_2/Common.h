#pragma once
#include <stdlib.h>
#include <stdio.h>

#define DEFAULT_MAX_NUMBER_OF_TOKENS 200

#define NewObject(TYPE) (TYPE*)malloc(sizeof(TYPE))
#define NewVector(TYPE,SIZE) (TYPE*)malloc(sizeof(TYPE)*SIZE)
#define isDigit(CHAR) (('0' <= CHAR) && (CHAR <= '9'))

typedef enum { FALSE, TRUE } Boolean;
typedef int Element;

typedef char	ElementForOStack;
typedef int		ElementForVStack;

typedef enum {
	PostfixError_None,
	PostfixError_ExpressionTooLong,
	PostfixError_OperandsTooMany,
	PostfixError_OperandsTooFew,
	PostfixError_UnknownOperator,
	PostfixError_DivideByZero
}
PostfixError;