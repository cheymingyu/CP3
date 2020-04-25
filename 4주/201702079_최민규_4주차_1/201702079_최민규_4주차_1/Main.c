#include "QuadEquationProblem.h"
#include "AppView.h"

int main() {
	QuadEquationProblem qeProblem;
	QuadEquation equation;
	Solution solution;

	AppView_out_msg_startSolvingQuadEquation();		// ���� �޼����� ����Ѵ�.
	while (AppView_in_solvingIsRequested()) {		// ���������� Ǯ�̿��θ� �����.
		AppView_in_quadEquation(&equation._c0, &equation._c1, &equation._c2);		// ������������ ������� �����.
		QuadEquationProblem_setEquation(&qeProblem, equation);						// ������� �����Ѵ�.
		AppView_out_quadEquation(equation._c0, equation._c1, equation._c2);			// ������������ ����Ѵ�.
		if (QuadEquationProblem_secondOrderTermCoefficientIsZero(&qeProblem)) {		// �������� ����� 0���� Ȯ���Ѵ�.
			AppView_out_msg_secondOrderTermCoefficientIsZero();
		}
		else {
			float determinant = QuadEquationProblem_determinant(&qeProblem);
			if (QuadEquationProblem_determinantIsNegative(&qeProblem)) {			// �Ǻ����� ���� �������� Ȯ���Ѵ�.
				AppView_out_msg_determinantIsNegative(determinant);
			}
			else {
				solution = QuadEquationProblem_solve(&qeProblem);					// ������������ Ǭ��.
				AppView_out_determinant(determinant);								// �Ǻ��� ���� ����Ѵ�.
				AppView_out_solution(solution._root1, solution._root2);				// �ظ� ����Ѵ�.
			}
		}
	}
	AppView_out_msg_endSolvingQuadEquation();
	return 0;
}