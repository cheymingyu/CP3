#define _CRT_SECURE_NO_WARNINGS
#include "AppView.h"
#include <stdio.h>

void AppView_out(char* aMessage) {
	printf(aMessage);
}

int AppView_in_order(void) {
	int order;
	printf("\n? 마방진 차수를 입력하시오: ");
	scanf("%d", &order);
	return order;
}

void	Appview_out_executionTime(int anOrder, long anExecutionTime) {
	printf("차수: %2d, 시간: %ld (마이크로 초)\n", anOrder, anExecutionTime);
}