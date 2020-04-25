#include "Common.h"

// 출력 함수
void AppView_out_msg_startSolvingLinearEquation(void);
void AppView_out_msg_endSolvingLinearEquation(void);
void AppView_out_linearEquation(float c0, float c1);
void AppView_out_root(float root);
void AppView_out_msg_firstOrderTermCoefficientIsZero(void);

// 입력 함수
Boolean AppView_in_solvingIsRequested(void);
void AppView_in_linearEquation(float* p_c0, float* p_c1); // * : 포인터 변수 / 메모리 주소를 포인터 변수에 저장

