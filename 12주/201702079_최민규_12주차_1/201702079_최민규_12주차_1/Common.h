#pragma once
#include <stdlib.h>
#include <stdio.h>

#define MAX_NUMBER_OF_TOKENS 200

#define NewObject(TYPE) (TYPE*)malloc(sizeof(TYPE))
#define NewVector(TYPE,SIZE) (TYPE*)malloc(sizeof(TYPE)*SIZE)

typedef enum { FALSE, TRUE } Boolean;
typedef int Element;

typedef enum {
	PostfixError_None,
	PostfixError_ExpressionTooLong,
	PostfixError_OperandsTooMany,
	PostfixError_OperandsTooFew,
	PostfixError_UnknownOperator,
	PostfixError_DivideByZero
}
PostfixError;