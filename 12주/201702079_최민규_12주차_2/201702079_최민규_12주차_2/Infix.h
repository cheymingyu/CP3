#pragma once
#include "Common.h"
typedef struct _Infix Infix;

Infix* Infix_new();
void Infix_delete(Infix* _this);
void Infix_setExpression(Infix* _this, char* newExpression);

Boolean Infix_toPostfix(Infix* _this);
char* Infix_postfix(Infix* _this);