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

char AppView_in_removeKeyAndObject() {
	printf("������ ��ü�� Key���� �Է��Ͻÿ�: ");
	char charDirectlyFromKeyboard = getCharDirectlyFromKeyboard();
	AppView_out_newLine();

	return charDirectlyFromKeyboard;
}

char AppView_in_searchKeyAndObject() {
	printf("�˻��� ��ü�� Key���� �Է��Ͻÿ�: ");
	char charDirectlyFromKeyboard = getCharDirectlyFromKeyboard();
	AppView_out_newLine();

	return charDirectlyFromKeyboard;
}

void AppView_out_addedKeyAndObjectInDictionary(char aChar, int aNum) {
	printf("[Add] ���Ե� Ű-��ü ���� <\'%c\', %d> �Դϴ�.\n", aChar, aNum);
}

void AppView_out_replaceObject(char aChar, int aNum) {
	printf("[Replace] key  <\'%c\'>�� object�� <%d>�� ��ü�մϴ�.\n", aChar, aNum);
}

void AppView_out_remove(char aChar, int aNum) {
	printf("[����] <\'%c\', %d> �� ���������� �����Ǿ����ϴ�.\n", aChar, aNum);
}

void AppView_out_noElementInDictionary() {
	printf("[Empty] ������ ������ ���Ұ� �����ϴ�.\n");
}

void AppView_out_dictionarySize(int dictionarySize) {
	printf("[Size] �������� ���� %d ���� Ű-��ü ���� �ֽ��ϴ�.\n", dictionarySize);
}

void AppView_out_keyExistInDictionary(char aChar, int aNum) {
	printf("[�˻�] <\'%c\', %d> ���� ������ �����մϴ�.\n", aChar, aNum);
}

void AppView_out_keyDoesNotExistInDictionary() {
	printf("[�˻�] �־��� Ű�� ������ �������� �ʽ��ϴ�.\n");
}

void AppView_out_ignoredChar() {
	printf("[Ignore] �ǹ� ���� ���ڰ� �ԷµǾ����ϴ�.\n");
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
	printf("[����] ������ ���Ҵ� \'%c\' �Դϴ�.\n", anElement);
}

void AppView_out_startProgram() {
	printf("<<< ���� Ȱ�� ���α׷��� �����մϴ� >>>");
	AppView_out_newLine();
}

void AppView_out_endProgram() {
	AppView_out_newLine();
	printf("<<< ���� Ȱ�� ���α׷��� �����մϴ� >>>\n");
}