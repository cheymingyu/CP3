#define _CRT_SECURE_NO_WARNINGS
#include "AppView.h"
#include <stdio.h>

void AppView_out(char* aMessage) {
	printf(aMessage);
}

int AppView_in_order(void) {
	int order;
	printf("\n? ������ ������ �Է��Ͻÿ�: ");
	scanf("%d", &order);
	return order;
}