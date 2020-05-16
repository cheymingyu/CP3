#pragma once
#include "Common.h"

Boolean AppView_in_postfixExpression(char* _expression);
void	AppView_out_startingMessage();
void	AppView_out_errorInExpression();
void	AppView_out_evaluatedValue(int evaluatedValue);
void	AppView_out_endingMessage();
void	AppView_out_newLine();

void AppView_out_bottomOfStack();
void AppView_out_element(char anElement);
void AppView_out_topOfStack();