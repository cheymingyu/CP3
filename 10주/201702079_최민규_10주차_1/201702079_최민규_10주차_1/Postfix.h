#pragma once
#include "Common.h"

typedef struct _Postfix Postfix;

Postfix*	Postfix_new(int givenMaxNumberOfTokens);
void		Postfix_delete(Postfix* _this);

void	Postfix_setExpression(Postfix* _this, char* anExpression);
Boolean	Postfix_evaluate(Postfix* _this);
int		Postfix_evaluatedValue(Postfix* _this);