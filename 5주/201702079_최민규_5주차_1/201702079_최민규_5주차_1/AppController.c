#include "AppController.h"
#include "Common.h"
#include "AppView.h"
#include "MagicSquare.h"
#include <stdio.h>

struct _AppController {
	int _a;
};

AppController* AppController_new(void) {
	// AppController 객체를 생성한다.
	AppController* _this;
	_this = NewObject(AppController);
	return _this;
}

void AppController_run(AppController* _this) {
	AppView_out("<<< 마방진 풀이를 시작합니다 >>>");

	MagicSquare* magicSquare = MagicSquare_new();	// magicSquare 객체를 생성한다.
	int inputOrder = AppView_in_order();
	while (inputOrder != END_OF_RUN) {
		MagicSquare_setOrder(magicSquare, inputOrder);
			// magicSquare에게 차수를 알려준다
		if (MagicSquare_orderIsValid(magicSquare)) {
			MagicSquare_solve(magicSquare);
			AppController_showBoard(_this, magicSquare);
		}
		inputOrder = AppView_in_order();
	}
	MagicSquare_delete(magicSquare);	// magicSqaure 객체를 소멸시킨다.
	AppView_out("\n<<< 마방진 풀이를 종료합니다 >>>\n");
}

void AppController_delete(AppController* _this) {
	
	free(_this);
}

void AppController_showBoard(AppController* _this, MagicSquare* aMagicSquare) {
	char messageBuffer[255];
	int order = MagicSquare_order(aMagicSquare);
	sprintf_s(messageBuffer, sizeof(messageBuffer), "Magic Square Board: Order %2d\n", order);
	AppView_out(messageBuffer);
	AppView_out("    ");
	for (int col = 0; col < order; col++) {
		sprintf_s(messageBuffer, sizeof(messageBuffer), "[%3d]", col);
		AppView_out(messageBuffer);
	}
	AppView_out("\n");
	for (int row = 0; row < order; row++) {
		sprintf_s(messageBuffer, sizeof(messageBuffer), "[%2d]", row);
		AppView_out(messageBuffer);
		for (int col = 0; col < order; col++) {
			sprintf_s(messageBuffer, sizeof(messageBuffer), "%5d", MagicSquare_cell(aMagicSquare, row, col));
			AppView_out(messageBuffer);
		}
		AppView_out("\n");
	}
}