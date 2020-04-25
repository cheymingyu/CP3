#include <math.h>
#include "QuadEquationProblem.h"

void QuadEquationProblem_setEquation(QuadEquationProblem* _this, QuadEquation anEquation) {
	QuadEquationProblem qeProblem = *_this;
	_this ->_equation._c2 = anEquation._c2;
	_this->_equation._c1 = anEquation._c1;
	_this->_equation._c0 = anEquation._c0;
}

Boolean QuadEquationProblem_secondOrderTermCoefficientIsZero(QuadEquationProblem* _this) {
	return FloatIsZero(_this -> _equation._c2);
}

Boolean QuadEquationProblem_determinantIsNegative(QuadEquationProblem* _this) {
	float determinant = QuadEquationProblem_determinant(_this);
	return !(determinant > -EPSILON);
}

float	QuadEquationProblem_determinant(QuadEquationProblem* _this) {
	float determinant = _this ->_equation._c1 * _this->_equation._c1 - 4 * _this->_equation._c2 * _this->_equation._c0;

	return determinant;
}

Solution QuadEquationProblem_solve(QuadEquationProblem* _this) {
	Solution solution;
	float sqrtOfDeterminant;

	sqrtOfDeterminant = sqrtf(QuadEquationProblem_determinant(_this));
	solution._root1 = (-_this->_equation._c1 + sqrtOfDeterminant) / (2 * _this->_equation._c2);
	solution._root2 = (-_this->_equation._c1 - sqrtOfDeterminant) / (2 * _this->_equation._c2);

	if (FloatIsZero(solution._root1)) {
		solution._root1 = 0.0;
	}
	if (FloatIsZero(solution._root2)) {
		solution._root2;
	}
	return solution;
}