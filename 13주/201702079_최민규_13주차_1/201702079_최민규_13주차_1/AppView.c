#include "AppView.h"
#include <stdio.h>
#include <conio.h>

char getCharDirectlyFromKeyboard();

char getCharDirectlyFromKeyboard() {
	char charFromKeyboard;
	charFromKeyboard = _getch();
	return charFromKeyboard;
}

char AppView_in_nextInputChar() {
	printf("\n> ���ڸ� �Է��Ͻÿ�: ");
	char charDirectlyFromKeyboard = getCharDirectlyFromKeyboard();
	AppView_out_newLine();

	return charDirectlyFromKeyboard;
}

void AppView_out_queueIsFull(char anElementForPush) {
	printf("[Full] ť�� �� ���� ���� \'%c\' �� ������ �Ұ����մϴ�.\n", anElementForPush);
}

void AppView_out_addedElementInQueue(char anElement) {
	printf("[Add] ���Ե� ���Ҵ� \'%c\' �Դϴ�.\n", anElement);
}

void AppView_out_noElementInQueue() {
	printf("[Empty] ť�� ������ ���Ұ� �����ϴ�.\n");
}

void AppView_out_removedElementFromQueue(char anElement) {
	printf("[Remove1] ������ ���Ҵ� \'%c\' �Դϴ�.\n", anElement);
}

void AppView_out_removedElementFromQueueByRemoveN(char anElement) {
	printf("[RemoveN] ������ ���Ҵ� \'%c\' �Դϴ�.\n", anElement);
}


void AppView_out_queueIsEmptyAgainstRemove() {
	printf("[Empty] ť�� �� �̻� ������ ���Ұ� �����ϴ�.\n");
}

void AppView_out_frontElement(char anElement) {
	printf("[Front] Front ���Ҵ� \'%c\' �Դϴ�.\n", anElement);
}

void AppView_out_noFrontElement() {
	printf("[Empty] ���� ť�� ��� �ֽ��ϴ�.\n");
}

void AppView_out_labelRear() {
	printf(" <Rear>\n");
}

void AppView_out_elementInQueue(char anElement) {
	printf("%c ", anElement);
}

void AppView_out_labelFront() {
	printf("[Queue] <Front> ");
}

void AppView_out_newLine() {
	printf("\n");
}

void AppView_out_queueSize(int stackSize) {
	printf("[Size] ť���� ���� %d ���� ���Ұ� �ֽ��ϴ�.\n", stackSize);
}

void AppView_out_ignoredChar() {
	printf("[Ignore] �ǹ� ���� ���ڰ� �ԷµǾ����ϴ�.\n");
}

void AppView_out_removedElementByEndInput(char anElement) {
	printf("[Esc] ������ ���Ҵ� \'%c\' �Դϴ�.\n", anElement);
}

void AppView_out_numberOFInputChars(int numberOfChars) {
	printf("......�Էµ� ���ڴ� ��� %d �� �Դϴ�.\n", numberOfChars);
}

void AppView_out_numberOfNormallyProcessedChars(int numberOfChars) {
	printf("......���� ó���� ���ڴ� %d �� �Դϴ�.\n", numberOfChars);
}

void AppView_out_numberOfIgnoredChars(int numberOfChars) {
	printf("......���õ� ���ڴ� %d �� �Դϴ�.\n", numberOfChars);
}

void AppView_out_numberOfAddedChars(int numberOfChars) {
	printf("......���Ե� ���ڴ� %d �� �Դϴ�.\n", numberOfChars);
}

void AppView_out_startProgram() {
	printf("<<< Queue Ȱ�� ���α׷��� �����մϴ� >>>");
	AppView_out_newLine();
}

void AppView_out_endProgram() {
	AppView_out_newLine();
	printf("<<< Queue Ȱ�� ���α׷��� �����մϴ� >>>\n");
}