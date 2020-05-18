#define  _CRT_SECURE_NO_WARNINGS

#include "AppView.h"
#include <stdio.h>

Boolean AppView_in_postfixExpression(char* _expression) {
	printf("> Postfix ������ �Է��Ͻÿ�: ");
	scanf("%s", _expression);
	if (_expression[0] == '$') {
		return FALSE;
	}
	else {
		return TRUE;
	}
}

void	AppView_out_startingMessage() {
	printf("<<< Postfix ���� ����� �����մϴ� >>>\n");
	AppView_out_newLine();
}

void	AppView_out_errorInExpression() {
	printf("> ���Ŀ� ������ �ֽ��ϴ�.\n");
	AppView_out_newLine();
}

void	AppView_out_evaluatedValue(int evaluatedValue) {
	printf("��갪 : %d\n", evaluatedValue);
	AppView_out_newLine();
}

void	AppView_out_endingMessage() {
	printf("\n<<< Postfix ���� ����� �����մϴ� >>>\n");
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