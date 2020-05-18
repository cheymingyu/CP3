#define  _CRT_SECURE_NO_WARNINGS

#include "AppView.h"
#include <stdio.h>

Boolean AppView_in_postfixExpression(char* _expression) {
	printf("> Postfix 수식을 입력하시오: ");
	scanf("%s", _expression);
	if (_expression[0] == '$') {
		return FALSE;
	}
	else {
		return TRUE;
	}
}

void	AppView_out_startingMessage() {
	printf("<<< Postfix 수식 계산을 시작합니다 >>>\n");
	AppView_out_newLine();
}

void	AppView_out_errorInExpression() {
	printf("> 수식에 오류가 있습니다.\n");
	AppView_out_newLine();
}

void	AppView_out_evaluatedValue(int evaluatedValue) {
	printf("계산값 : %d\n", evaluatedValue);
	AppView_out_newLine();
}

void	AppView_out_endingMessage() {
	printf("\n<<< Postfix 수식 계산을 종료합니다 >>>\n");
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

void AppView_out_topOfStack() {
	printf("<Top> ");
}