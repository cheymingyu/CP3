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
	printf("\n> 문자를 입력하시오: ");
	char charDirectlyFromKeyboard = getCharDirectlyFromKeyboard();
	AppView_out_newLine();

	return charDirectlyFromKeyboard;
}

void AppView_out_queueIsFull(char anElementForPush) {
	printf("[Full] 큐가 꽉 차서 원소 \'%c\' 는 삽입이 불가능합니다.\n", anElementForPush);
}

void AppView_out_addedElementInQueue(char anElement) {
	printf("[Add] 삽입된 원소는 \'%c\' 입니다.\n", anElement);
}

void AppView_out_noElementInQueue() {
	printf("[Empty] 큐에 삭제할 원소가 없습니다.\n");
}

void AppView_out_removedElementFromQueue(char anElement) {
	printf("[Remove1] 삭제된 원소는 \'%c\' 입니다.\n", anElement);
}

void AppView_out_removedElementFromQueueByRemoveN(char anElement) {
	printf("[RemoveN] 삭제된 원소는 \'%c\' 입니다.\n", anElement);
}


void AppView_out_queueIsEmptyAgainstRemove() {
	printf("[Empty] 큐에 더 이상 삭제할 원소가 없습니다.\n");
}

void AppView_out_frontElement(char anElement) {
	printf("[Front] Front 원소는 \'%c\' 입니다.\n", anElement);
}

void AppView_out_noFrontElement() {
	printf("[Empty] 현재 큐는 비어 있습니다.\n");
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
	printf("[Size] 큐에는 현재 %d 개의 원소가 있습니다.\n", stackSize);
}

void AppView_out_ignoredChar() {
	printf("[Ignore] 의미 없는 문자가 입력되었습니다.\n");
}

void AppView_out_removedElementByEndInput(char anElement) {
	printf("[Esc] 삭제된 원소는 \'%c\' 입니다.\n", anElement);
}

void AppView_out_numberOFInputChars(int numberOfChars) {
	printf("......입력된 문자는 모두 %d 개 입니다.\n", numberOfChars);
}

void AppView_out_numberOfNormallyProcessedChars(int numberOfChars) {
	printf("......정상 처리된 문자는 %d 개 입니다.\n", numberOfChars);
}

void AppView_out_numberOfIgnoredChars(int numberOfChars) {
	printf("......무시된 문자는 %d 개 입니다.\n", numberOfChars);
}

void AppView_out_numberOfAddedChars(int numberOfChars) {
	printf("......삽입된 문자는 %d 개 입니다.\n", numberOfChars);
}

void AppView_out_startProgram() {
	printf("<<< Queue 활용 프로그램을 시작합니다 >>>");
	AppView_out_newLine();
}

void AppView_out_endProgram() {
	AppView_out_newLine();
	printf("<<< Queue 활용 프로그램을 종료합니다 >>>\n");
}