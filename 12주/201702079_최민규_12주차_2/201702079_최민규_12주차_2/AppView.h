#pragma once
#include "Common.h"
#include "Postfix.h"

Boolean AppView_in_infixExpression(char* _expression);
void	AppView_out_startingMessage();
void	AppView_out_infixToPostfixMessage();
void	AppView_out_postfixEvaluationErrorMessage(PostfixError aPostfixError);
void	AppView_out_infixToPostfixErrorMessage();
void	Appview_out_startEvaluatePostfix();
void	AppView_out_evaluatedValue(int evaluatedValue);
void	AppView_out_postfixExpression(char* _expression);
void	AppView_out_endingMessage();
void	AppView_out_newLine();

void AppView_out_bottomOfStack();
void AppView_out_element(int anElement);
void AppView_out_OElement(int anOElement);
void AppView_out_topOfStack();