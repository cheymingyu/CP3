#pragma once
#define  _CRT_SECURE_NO_WARNINGS

#include "AppView.h"
#include "MessasgeKOR_PostfixError.h"
#include <stdio.h>

Boolean AppView_in_infixExpression(char* _expression) {
	printf("? Infix 수식을 입력하시오: ");
	scanf("%s", _expression);
	if (_expression[0] == '@') {
		return FALSE;
	}
	else {
		return TRUE;
	}
}

void	AppView_out_startingMessage() {
	printf("<<< Infix 수식 계산을 시작합니다 >>>\n");
	AppView_out_newLine();
}

void	AppView_out_infixToPostfixMessage() {
	printf("> Infix를 Postfix로 변환합니다: \n");
}

void	AppView_out_postfixEvaluationErrorMessage(PostfixError aPostfixError) {
	if (aPostfixError == PostfixError_ExpressionTooLong) {
		printf(ErrorMsg_ExpressionTooLong);
	}
	else if (aPostfixError == PostfixError_OperandsTooMany) {
		printf(ErrorMsg_OperandsTooMany);
	}
	else if (aPostfixError == PostfixError_OperandsTooFew) {
		printf(ErrorMsg_OperandsTooFew);
	}
	else if (aPostfixError == PostfixError_UnknownOperator) {
		printf(ErrorMsg_UnknownOperator);
	}
	else if (aPostfixError == PostfixError_DivideByZero) {
		printf(ErrorMsg_DivideByZero);
	}
}

void	AppView_out_infixToPostfixErrorMessage() {
	printf("Infix 수식이 올바르지 않습니다.\n\n");
}

void	Appview_out_startEvaluatePostfix() {
	printf("> Postfix 수식을 계산합니다: \n");
}

void	AppView_out_evaluatedValue(int evaluatedValue) {
	printf(">> 계산값 : %d\n", evaluatedValue);
	AppView_out_newLine();
}

void	AppView_out_postfixExpression(char* _expression) {
	printf(">> 변환된 Postfix : %s\n", _expression);
	AppView_out_newLine();
}

void	AppView_out_endingMessage() {
	printf("\n<<< Infix 수식 계산을 종료합니다 >>>\n");
}

void	AppView_out_newLine() {
	printf("\n");
}

void AppView_out_bottomOfStack() {
	printf(" <Bottom> ");
}

void AppView_out_element(int anElement) {
	printf("%d ", anElement);
}

void AppView_out_OElement(int anOElement) {
	printf("%c ", anOElement);
}

void AppView_out_topOfStack() {
	printf("<Top> ");
}