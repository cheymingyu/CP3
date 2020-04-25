#define _CRT_SECURE_NO_WARNINGS
#include "AppView.h"
#include <stdio.h>
#include <conio.h>

void AppView_out(char* aMessage) {
	printf(aMessage);
}

void	AppView_out_averageScore(float anAverageScore) {
	printf("��������� %f�Դϴ�.\n", anAverageScore);
}

void	AppView_out_numberOfStudentsAboveAverage(int aNumber) {
	printf("��� �̻��� �л��� ��� %d�� �Դϴ�.\n", aNumber);
}

void	AppView_out_maxScore(int aMaxScore) {
	printf("�ְ����� %d�� �Դϴ�.\n", aMaxScore);
}

void	AppView_out_minScore(int aMinScore) {
	printf("�������� %d�� �Դϴ�.\n", aMinScore);
}

void	AppView_out_gradeCountFor(char aGrade, int aCount) {
	printf("%c ������ %d�� �Դϴ�.\n", aGrade, aCount);
}

void	AppView_out_studentInfo(int aScore, char aGrade) {
	printf("����: %d ����: %c\n", aScore, aGrade);
}

Boolean	AppView_in_doesContinueToInputNextStudent() {
	printf("\n? ������ �Է��Ϸ��� 'Y'��, �Է��� �����Ϸ��� �ٸ� �ƹ� Ű�� ġ�ÿ�: \n");
	char answer = getcharDirectlyFromKeyboard();

	return (answer == 'Y' || answer == 'y');
}

int		AppView_in_score() {
	int score;

	printf("- ������ �Է��Ͻÿ�: ");
	scanf("%d", &score);
	return score;
}

char getcharDirectlyFromKeyboard(void) {
	char charFromKeyboard;
	charFromKeyboard = _getch();
	return charFromKeyboard;
}