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

void	AppView_out_msg_invalidStudentID(char* aStudentID, int maxLength) {
	printf("[����] �й� %s �� ���̰� �ʹ� ��ϴ�. �ִ� %d �Դϴ�.\n", aStudentID, maxLength);
}

void	AppView_out_studentInfo(char* aStudentID, int aScore, char aGrade) {
	printf("�й�: %s, ����: %d, ����: %c\n", aStudentID, aScore, aGrade);
}

void	AppView_out_titleForSortedStudentList() {
	printf("�л����� ������ ����Դϴ�.\n");
}

Boolean	AppView_in_doesContinueToInputNextStudent() {
	printf("\n? ������ �Է��Ϸ��� 'Y'��, �Է��� �����Ϸ��� �ٸ� �ƹ� Ű�� ġ�ÿ�: \n");
	char answer = getcharDirectlyFromKeyboard();

	return (answer == 'Y' || answer == 'y');
}

char getcharDirectlyFromKeyboard(void) {
	char charFromKeyboard;
	charFromKeyboard = _getch();
	return charFromKeyboard;
}

int	AppView_in_score() {
	int score;

	printf("- ������ �Է��Ͻÿ�: ");
	scanf("%d", &score);
	return score;
}

void	Appview_in_studentID(char* aStudentID) {
	printf("- �й��� �Է��Ͻÿ�: ");
	scanf("%s", aStudentID);
}