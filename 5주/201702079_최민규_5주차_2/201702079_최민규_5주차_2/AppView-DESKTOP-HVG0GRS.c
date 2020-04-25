#define _CRT_SECURE_NO_WARNINGS
#include "AppView.h"
#include <stdio.h>

void AppView_out(char* aMessage) {
	printf(aMessage);
}

void	Appview_out_executionTime(int anOrder, long anExecutionTime) {
	printf("차수: %2d, 시간: %ld (마이크로 초)\n", anOrder, anExecutionTime);
}