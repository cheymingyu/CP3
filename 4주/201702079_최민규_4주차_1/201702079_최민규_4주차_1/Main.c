#include "QuadEquationProblem.h"
#include "AppView.h"

int main() {
	QuadEquationProblem qeProblem;
	QuadEquation equation;
	Solution solution;

	AppView_out_msg_startSolvingQuadEquation();		// 시작 메세지를 출력한다.
	while (AppView_in_solvingIsRequested()) {		// 이차방정식 풀이여부를 물어본다.
		AppView_in_quadEquation(&equation._c0, &equation._c1, &equation._c2);		// 이차방정식의 계수들을 물어본다.
		QuadEquationProblem_setEquation(&qeProblem, equation);						// 계수들을 저장한다.
		AppView_out_quadEquation(equation._c0, equation._c1, equation._c2);			// 이차방정식을 출력한다.
		if (QuadEquationProblem_secondOrderTermCoefficientIsZero(&qeProblem)) {		// 이차항의 계수가 0인지 확인한다.
			AppView_out_msg_secondOrderTermCoefficientIsZero();
		}
		else {
			float determinant = QuadEquationProblem_determinant(&qeProblem);
			if (QuadEquationProblem_determinantIsNegative(&qeProblem)) {			// 판별식의 값이 음수인지 확인한다.
				AppView_out_msg_determinantIsNegative(determinant);
			}
			else {
				solution = QuadEquationProblem_solve(&qeProblem);					// 이차방정식을 푼다.
				AppView_out_determinant(determinant);								// 판별식 값을 출력한다.
				AppView_out_solution(solution._root1, solution._root2);				// 해를 출력한다.
			}
		}
	}
	AppView_out_msg_endSolvingQuadEquation();
	return 0;
}