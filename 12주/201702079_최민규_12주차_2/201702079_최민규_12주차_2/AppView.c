#pragma once
#define  _CRT_SECURE_NO_WARNINGS

#include "AppView.h"
#include "MessasgeKOR_PostfixError.h"
#include <stdio.h>

Boolean AppView_in_infixExpression(char* _expression) {
	printf("? Infix ������ �Է��Ͻÿ�: ");
	scanf("%s", _expression);
	if (_expression[0] == '@') {
		return FALSE;
	}
	else {
		return TRUE;
	}
}

void	AppView_out_startingMessage() {
	printf("<<< Infix ���� ����� �����մϴ� >>>\n");
	AppView_out_newLine();
}

void	AppView_out_infixToPostfixMessage() {
	printf("> Infix�� Postfix�� ��ȯ�մϴ�: \n");
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
	printf("Infix ������ �ùٸ��� �ʽ��ϴ�.\n\n");
}

void	Appview_out_startEvaluatePostfix() {
	printf("> Postfix ������ ����մϴ�: \n");
}

void	AppView_out_evaluatedValue(int evaluatedValue) {
	printf(">> ��갪 : %d\n", evaluatedValue);
	AppView_out_newLine();
}

void	AppView_out_postfixExpression(char* _expression) {
	printf(">> ��ȯ�� Postfix : %s\n", _expression);
	AppView_out_newLine();
}

void	AppView_out_endingMessage() {
	printf("\n<<< Infix ���� ����� �����մϴ� >>>\n");
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