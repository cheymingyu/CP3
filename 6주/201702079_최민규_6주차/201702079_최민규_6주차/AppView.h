#pragma once
#include "Common.h"

void	AppView_out(char* aMessage);
void	AppView_out_averageScore(float anAverageScore);
void	AppView_out_numberOfStudentsAboveAverage(int aNumber);
void	AppView_out_maxScore(int aMaxScore);
void	AppView_out_minScore(int aMinScore);
void	AppView_out_gradeCountFor(char aGrade, int aCount);

void	AppView_out_studentInfo(int aScore);

Boolean	AppView_in_doesContinueToInputNextStudent();
int		AppView_in_score();