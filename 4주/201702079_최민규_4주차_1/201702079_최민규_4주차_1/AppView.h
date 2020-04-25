#pragma once
#include <stdio.h>
#include "Common.h"

Boolean AppView_in_solvingIsRequested(void);
void	AppView_in_quadEquation(float* p_c0, float* p_c1, float* p_c2);

void	AppView_out_msg_startSolvingQuadEquation(void);
void	AppView_out_msg_endSolvingQuadEquation(void);
void	AppView_out_msg_secondOrderTermCoefficientIsZero(void);
void	AppView_out_msg_determinantIsNegative(float aDeterminant);
void	AppView_out_quadEquation(float c0, float c1, float c2);
void	AppView_out_solution(float root1, float root2);
void	AppView_out_determinant(float aDeterminant);