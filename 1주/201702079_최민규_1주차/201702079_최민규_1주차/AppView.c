#include "AppView.h"
#include <stdio.h>

void AppView_out_msg_startSolvingLinearEquation(void) {
	printf("<<< 일차방정식 풀이를 시작합니다 >>>\n\n");
}

void AppView_out_msg_endSolvingLinearEquation(void) {
	printf("<<< 일차방정식 풀이를 종료합니다 >>>\n");
}

void AppView_out_linearEquation(float c0, float c1) {
	printf("> 주어진 방정식 : (%.1f)x + (%.1f) = 0\n", c1, c0);
}

void AppView_out_root(float root) {
	printf("> 방정식의 해는 다음과 같습니다 : \n");
	printf("x = %.1f\n\n", root);
}

void AppView_out_msg_firstOrderTermCoefficientIsZero(void) {
	printf("[오류] 1차항의 계수가 0 이어서, 방정식을 풀 수 없습니다.\n\n");
}

Boolean AppView_in_solvingIsRequested(void) {
	char answer;
	printf("? 방정식을 풀려면 'y', 풀이를 종료하려면 다른 아무 키나 치시오 : ");

	char inputLine[255];
	scanf_s("%s", inputLine, 255);
	answer = inputLine[0];
	return (answer == 'y');
}

void AppView_in_linearEquation(float* p_c0, float* p_c1) {
	printf("? 1차항의 계수를 입력하시오 : ");
	scanf_s("%f", p_c1);
	printf("? 상수항의 계수를 입력하시오 : ");
	scanf_s("%f", p_c0);
}

