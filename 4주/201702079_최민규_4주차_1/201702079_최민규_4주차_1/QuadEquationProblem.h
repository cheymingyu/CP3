#pragma once
#include "Common.h"

void		QuadEquationProblem_setEquation(QuadEquationProblem* _this, QuadEquation anEquation);

Boolean		QuadEquationProblem_secondOrderTermCoefficientIsZero(QuadEquationProblem* _this);
Boolean		QuadEquationProblem_determinantIsNegative(QuadEquationProblem* _this);

float		QuadEquationProblem_determinant(QuadEquationProblem* _this);
Solution	QuadEquationProblem_solve(QuadEquationProblem* _this);