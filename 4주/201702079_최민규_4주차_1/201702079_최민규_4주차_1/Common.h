#pragma once
#include <math.h>

#define MAXFLOAT 1.0E+100
#define EPSILON 1.0E-6
#define FloatIsZero(NUMBER) (fabsf(NUMBER) < EPSILON)

typedef enum { FALSE, TRUE } Boolean;

typedef struct {
	float _c0;
	float _c1;
	float _c2;
} QuadEquation;

typedef struct {
	float _root1;
	float _root2;
} Solution;

typedef struct {
	QuadEquation _equation;
} QuadEquationProblem;