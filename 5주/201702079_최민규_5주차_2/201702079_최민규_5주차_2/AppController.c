#include "AppController.h"
#include "Common.h"
#include "AppView.h"
#include "MagicSquare.h"
#include "Timer.h"
#include <stdio.h>

struct _AppController {

};

AppController* AppController_new(void) {
	// AppController ��ü�� �����Ѵ�.
	AppController* _this;
	_this = NewObject(AppController);
	return _this;
}

void AppController_run(AppController* _this) {
	MagicSquare*	magicSquare;
	int				order, count;
	Timer*			timer;
	long			executionTime;

	timer = Timer_new();
	AppView_out("<<< ������ Ǯ���� ���� ������ �����մϴ� >>>\n");
	AppView_out("�ϳ��� ������ ���� 100ȸ �ݺ� ������ �ð��� �����մϴ�.\n");

	for (order = 9; order <= MAX_ORDER; order += 10) {
		Timer_start(timer);
		for (count = 0; count < 100; count++) {
			magicSquare = MagicSquare_new();
			MagicSquare_setOrder(magicSquare, order);
			MagicSquare_solve(magicSquare);
			MagicSquare_delete(magicSquare);
		}
		Timer_stop(timer);
		executionTime = Timer_duration(timer);
		Appview_out_executionTime(order, executionTime);
	}
	Timer_delete(timer);
	AppView_out("<<< ���� ������ ��Ĩ�ϴ� >>>\n");
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
		sprintf_s(messageBuffer, sizeof(messageBuffer), "[%2d]", col);
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