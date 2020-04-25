#include "AppView.h"

float LinearEquation_solve(float c0, float c1) {
	if (FloatValueIsZero(c1)) {
		float det = c1 * c0;
		if (det >= 0.0) {
			return -MAXFLOAT;
		}
		else {
			return +MAXFLOAT;
		}
	}
	else {
		return (-c0) / c1;
	}
}

int main(void) {
	Boolean solvingIsRequested;
	float c0, c1;
	float root;

	AppView_out_msg_startSolvingLinearEquation();
	solvingIsRequested = AppView_in_solvingIsRequested();
	while (solvingIsRequested) {
		AppView_in_linearEquation(&c0, &c1); // (c0, c1)의 메모리 주소를 포인터 변수에 저장
		AppView_out_linearEquation(c0, c1);
		if (FloatValueIsZero(c1)) {
			AppView_out_msg_firstOrderTermCoefficientIsZero();
		}
		else {
			root = LinearEquation_solve(c0, c1);
			AppView_out_root(root);
		}

		solvingIsRequested = AppView_in_solvingIsRequested();
	}
	AppView_out_msg_endSolvingLinearEquation();
	return 0;
}