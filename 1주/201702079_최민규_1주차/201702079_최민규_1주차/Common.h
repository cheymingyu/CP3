#include <math.h>

#define EPSILON 1.0E-6
#define FloatValueIsZero(NUMBER) fabsf(NUMBER) < EPSILON

typedef enum { FALSE, TRUE } Boolean;

#define MAXFLOAT 3.4E+38F