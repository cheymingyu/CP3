#include <stdio.h>
#include "Common.h"
#include "AppView.h"
#include "MagicSquare.h"

void Main_showBoard(MagicSquare* aMagicSquare) {
	char messageBuffer[255];

	sprintf_s(messageBuffer, sizeof(messageBuffer), "> Magic Square Board: Order %2d\n", aMagicSquare->_order);
	AppView_out(messageBuffer);
	AppView_out("    ");

	for (int col = 0; col < aMagicSquare->_order; col++) {
		sprintf_s(messageBuffer, sizeof(messageBuffer), "[%2d]", col);
		AppView_out(messageBuffer);
	}
	AppView_out("\n");
	for (int row = 0; row < aMagicSquare->_order; row++) {
		sprintf_s(messageBuffer, sizeof(messageBuffer), "[%2d]", row);
		AppView_out(messageBuffer);
		for (int col = 0; col < aMagicSquare->_order; col++) {
			sprintf_s(messageBuffer, sizeof(messageBuffer), "%4d", aMagicSquare ->_board[row][col]);
			AppView_out(messageBuffer);
		}
		AppView_out("\n");
	}
}

int main(void) {
	MagicSquare magicSquare;
	int			inputOrder;

	AppView_out("<<< ������  Ǯ�̸� �����մϴ� >>>\n");
	inputOrder = AppView_in_order();	// ������ �Է� �޴´�.
	while (inputOrder != END_OF_RUN) {	// ������ -1�̸� ���α׷� ����
		MagicSquare_setOrder(&magicSquare, inputOrder);
		if (MagicSquare_orderIsValid(&magicSquare)) {
			MagicSquare_solve(&magicSquare);
			Main_showBoard(&magicSquare);
		}
		inputOrder = AppView_in_order();
	}
	AppView_out("\n<<< ������ Ǯ�̸� �����մϴ� >>>\n");
	return 0;
}