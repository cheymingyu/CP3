#include "Common.h"

// ��� �Լ�
void AppView_out_msg_startSolvingLinearEquation(void);
void AppView_out_msg_endSolvingLinearEquation(void);
void AppView_out_linearEquation(float c0, float c1);
void AppView_out_root(float root);
void AppView_out_msg_firstOrderTermCoefficientIsZero(void);

// �Է� �Լ�
Boolean AppView_in_solvingIsRequested(void);
void AppView_in_linearEquation(float* p_c0, float* p_c1); // * : ������ ���� / �޸� �ּҸ� ������ ������ ����

