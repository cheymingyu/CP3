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

char AppView_in_removeKeyAndObject() {
	printf("삭제할 객체의 Key값을 입력하시오: ");
	char charDirectlyFromKeyboard = getCharDirectlyFromKeyboard();
	AppView_out_newLine();

	return charDirectlyFromKeyboard;
}

char AppView_in_searchKeyAndObject() {
	printf("검색할 객체의 Key값을 입력하시오: ");
	char charDirectlyFromKeyboard = getCharDirectlyFromKeyboard();
	AppView_out_newLine();

	return charDirectlyFromKeyboard;
}

void AppView_out_addedKeyAndObjectInDictionary(char aChar, int aNum) {
	printf("[Add] 삽입된 키-객체 쌍은 <\'%c\', %d> 입니다.\n", aChar, aNum);
}

void AppView_out_replaceObject(char aChar, int aNum) {
	printf("[Replace] key  <\'%c\'>의 object를 <%d>로 대체합니다.\n", aChar, aNum);
}

void AppView_out_remove(char aChar, int aNum) {
	printf("[삭제] <\'%c\', %d> 이 성공적으로 삭제되었습니다.\n", aChar, aNum);
}

void AppView_out_noElementInDictionary() {
	printf("[Empty] 사전에 삭제할 원소가 없습니다.\n");
}

void AppView_out_dictionarySize(int dictionarySize) {
	printf("[Size] 사전에는 현재 %d 개의 키-객체 쌍이 있습니다.\n", dictionarySize);
}

void AppView_out_keyExistInDictionary(char aChar, int aNum) {
	printf("[검색] <\'%c\', %d> 쌍이 사전에 존재합니다.\n", aChar, aNum);
}

void AppView_out_keyDoesNotExistInDictionary() {
	printf("[검색] 주어진 키가 사전에 존재하지 않습니다.\n");
}

void AppView_out_ignoredChar() {
	printf("[Ignore] 의미 없는 문자가 입력되었습니다.\n");
}

void AppView_out_showBinaryTree() {
	printf("[Tree]\n");

}

void AppView_out_blank() {
	printf("   ");
}

void AppView_out_showDictionaryElement(char aChar) {
	printf("%3c\n", aChar);
}

void AppView_out_newLine() {
	printf("\n");
}

void AppView_out_removedElementByEndInput(char anElement) {
	printf("[삭제] 삭제된 원소는 \'%c\' 입니다.\n", anElement);
}

void AppView_out_startProgram() {
	printf("<<< 사전 활용 프로그램을 시작합니다 >>>");
	AppView_out_newLine();
}

void AppView_out_endProgram() {
	AppView_out_newLine();
	printf("<<< 사전 활용 프로그램을 종료합니다 >>>\n");
}