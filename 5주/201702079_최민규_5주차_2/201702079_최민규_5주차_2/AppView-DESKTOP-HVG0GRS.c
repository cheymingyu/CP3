#define _CRT_SECURE_NO_WARNINGS
#include "AppView.h"
#include <stdio.h>

void AppView_out(char* aMessage) {
	printf(aMessage);
}

void	Appview_out_executionTime(int anOrder, long anExecutionTime) {
	printf("����: %2d, �ð�: %ld (����ũ�� ��)\n", anOrder, anExecutionTime);
}