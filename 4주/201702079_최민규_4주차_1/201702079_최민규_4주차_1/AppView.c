#define _CRT_SECURE_NO_WARNINGS

#include "AppView.h"

Boolean AppView_in_solvingIsRequested() {
	char answer;
	printf("? 방정식을 풀려면 'y', 풀이를 종료하려면 다른 아무 키나 치시오: ");

	char inputLine[255];
	scanf("%s", inputLine);
	answer = inputLine[0];
	return (answer == 'y');
}

void AppView_in_quadEquation(float* p_c0, float* p_c1, float* p_c2) {
	printf("? 2 차항의 계수를 입력하시오: ");
	scanf("%f", p_c2);

	printf("? 1 차항의 계수를 입력하시오: ");
	scanf("%f", p_c1);

	printf("? 상수항의 계수를 입력하시오: ");
	scanf("%f", p_c0);
}

void AppView_out_msg_startSolvingQuadEquation(void) {
	printf("<<< 이차방정식 풀이를 시작합니다 >>>\n\n");
}

void AppView_out_msg_endSolvingQuadEquation(void) {
	printf("\n<<< 이차방정식 풀이를 종료합니다 >>>");
}

void AppView_out_msg_secondOrderTermCoefficientIsZero(void) {
	printf("[오류] 이차항의 계수가 0 이어서, 이차방정식이 아닙니다.\n\n");
}

void AppView_out_msg_determinantIsNegative(float aDeterminant) {
	printf("> 판별식의 값: %f\n", aDeterminant);
	printf("[오류] 판별식의 값이 음수이어서 해가 존재하지 않습니다.\n\n");
}

void AppView_out_quadEquation(float c0, float c1, float c2) {
	printf("> 주어진 방정식: ");

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
	printf("> 방정식의 해는 다음과 같습니다.\n");
	printf("x1 = %f\n", root1);
	printf("x2 = %f\n\n", root2);
}

void	AppView_out_determinant(float aDeterminant) {
	printf("> 판별식의 값: %f\n", aDeterminant);
}