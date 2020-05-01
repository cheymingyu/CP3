#pragma once
#include "Common.h"

void	AppView_out(char* aMessage);
void	AppView_out_averageScore(float anAverageScore);
void	AppView_out_numberOfStudentsAboveAverage(int aNumber);
void	AppView_out_maxScore(int aMaxScore);
void	AppView_out_minScore(int aMinScore);
void	AppView_out_gradeCountFor(char aGrade, int aCount);
void	AppView_out_msg_invalidStudentID(char* aStudentID, int maxLength);

void	AppView_out_studentInfo(char* aStudentID, int aScore, char aGrade);
void	AppView_out_titleForSortedStudentList();

Boolean	AppView_in_doesContinueToInputNextStudent();
int		AppView_in_score();
void	Appview_in_studentID(char* aStudentID);

char getcharDirectlyFromKeyboard(void);