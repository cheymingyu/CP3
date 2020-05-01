#define _CRT_SECURE_NO_WARNINGS
#include "AppView.h"
#include <stdio.h>
#include <conio.h>

void AppView_out(char* aMessage) {
	printf(aMessage);
}

void	AppView_out_averageScore(float anAverageScore) {
	printf("평균점수는 %f입니다.\n", anAverageScore);
}

void	AppView_out_numberOfStudentsAboveAverage(int aNumber) {
	printf("평균 이상인 학생은 모두 %d명 입니다.\n", aNumber);
}

void	AppView_out_maxScore(int aMaxScore) {
	printf("최고점은 %d점 입니다.\n", aMaxScore);
}

void	AppView_out_minScore(int aMinScore) {
	printf("최저점은 %d점 입니다.\n", aMinScore);
}

void	AppView_out_gradeCountFor(char aGrade, int aCount) {
	printf("%c 학점은 %d명 입니다.\n", aGrade, aCount);
}

void	AppView_out_msg_invalidStudentID(char* aStudentID, int maxLength) {
	printf("[오류] 학번 %s 의 길이가 너무 깁니다. 최대 %d 입니다.\n", aStudentID, maxLength);
}

void	AppView_out_studentInfo(char* aStudentID, int aScore, char aGrade) {
	printf("학번: %s, 점수: %d, 학점: %c\n", aStudentID, aScore, aGrade);
}

void	AppView_out_titleForSortedStudentList() {
	printf("학생들의 성적순 목록입니다.\n");
}

Boolean	AppView_in_doesContinueToInputNextStudent() {
	printf("\n? 성적을 입력하려면 'Y'를, 입력을 종료하려면 다른 아무 키나 치시오: \n");
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

	printf("- 점수를 입력하시오: ");
	scanf("%d", &score);
	return score;
}

void	Appview_in_studentID(char* aStudentID) {
	printf("- 학번을 입력하시오: ");
	scanf("%s", aStudentID);
}