#include "AppView.h"
#include <stdio.h>

void AppView_out_msg_startSolvingLinearEquation(void) {
	printf("<<< ���������� Ǯ�̸� �����մϴ� >>>\n\n");
}

void AppView_out_msg_endSolvingLinearEquation(void) {
	printf("<<< ���������� Ǯ�̸� �����մϴ� >>>\n");
}

void AppView_out_linearEquation(float c0, float c1) {
	printf("> �־��� ������ : (%.1f)x + (%.1f) = 0\n", c1, c0);
}

void AppView_out_root(float root) {
	printf("> �������� �ش� ������ �����ϴ� : \n");
	printf("x = %.1f\n\n", root);
}

void AppView_out_msg_firstOrderTermCoefficientIsZero(void) {
	printf("[����] 1������ ����� 0 �̾, �������� Ǯ �� �����ϴ�.\n\n");
}

Boolean AppView_in_solvingIsRequested(void) {
	char answer;
	printf("? �������� Ǯ���� 'y', Ǯ�̸� �����Ϸ��� �ٸ� �ƹ� Ű�� ġ�ÿ� : ");

	char inputLine[255];
	scanf_s("%s", inputLine, 255);
	answer = inputLine[0];
	return (answer == 'y');
}

void AppView_in_linearEquation(float* p_c0, float* p_c1) {
	printf("? 1������ ����� �Է��Ͻÿ� : ");
	scanf_s("%f", p_c1);
	printf("? ������� ����� �Է��Ͻÿ� : ");
	scanf_s("%f", p_c0);
}

