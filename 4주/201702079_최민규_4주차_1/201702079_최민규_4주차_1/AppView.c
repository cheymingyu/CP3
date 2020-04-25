#define _CRT_SECURE_NO_WARNINGS

#include "AppView.h"

Boolean AppView_in_solvingIsRequested() {
	char answer;
	printf("? �������� Ǯ���� 'y', Ǯ�̸� �����Ϸ��� �ٸ� �ƹ� Ű�� ġ�ÿ�: ");

	char inputLine[255];
	scanf("%s", inputLine);
	answer = inputLine[0];
	return (answer == 'y');
}

void AppView_in_quadEquation(float* p_c0, float* p_c1, float* p_c2) {
	printf("? 2 ������ ����� �Է��Ͻÿ�: ");
	scanf("%f", p_c2);

	printf("? 1 ������ ����� �Է��Ͻÿ�: ");
	scanf("%f", p_c1);

	printf("? ������� ����� �Է��Ͻÿ�: ");
	scanf("%f", p_c0);
}

void AppView_out_msg_startSolvingQuadEquation(void) {
	printf("<<< ���������� Ǯ�̸� �����մϴ� >>>\n\n");
}

void AppView_out_msg_endSolvingQuadEquation(void) {
	printf("\n<<< ���������� Ǯ�̸� �����մϴ� >>>");
}

void AppView_out_msg_secondOrderTermCoefficientIsZero(void) {
	printf("[����] �������� ����� 0 �̾, ������������ �ƴմϴ�.\n\n");
}

void AppView_out_msg_determinantIsNegative(float aDeterminant) {
	printf("> �Ǻ����� ��: %f\n", aDeterminant);
	printf("[����] �Ǻ����� ���� �����̾ �ذ� �������� �ʽ��ϴ�.\n\n");
}

void AppView_out_quadEquation(float c0, float c1, float c2) {
	printf("> �־��� ������: ");

	Boolean aNonZeroTermDoesExist = FALSE;
	if (!FloatIsZero(c2)) {
		aNonZeroTermDoesExist = TRUE;
		printf("(%f)x*x", c2);
	}
	if (!FloatIsZero(c1)) {
		if (aNonZeroTermDoesExist) {
			printf(" + ");
		}
		aNonZeroTermDoesExist = TRUE;
		printf("(%f)x", c1);
	}
	if (!FloatIsZero(c0)) {
		if (aNonZeroTermDoesExist) {
			printf(" + ");
		}
		aNonZeroTermDoesExist = TRUE;
		printf("(%f)", c0);
	}

	if (!aNonZeroTermDoesExist) {
		printf("0");
	}
	printf(" = 0\n");
}

void AppView_out_solution(float root1, float root2) {
	printf("> �������� �ش� ������ �����ϴ�.\n");
	printf("x1 = %f\n", root1);
	printf("x2 = %f\n\n", root2);
}

void	AppView_out_determinant(float aDeterminant) {
	printf("> �Ǻ����� ��: %f\n", aDeterminant);
}