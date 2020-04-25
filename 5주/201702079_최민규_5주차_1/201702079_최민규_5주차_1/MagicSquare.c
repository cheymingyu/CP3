#include "MagicSquare.h"
#include "AppView.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int _row;
	int _col;
} CellLocation;

#define EMPTY_CELL -1

MagicSquare*	MagicSquare_new() {
	MagicSquare* _this;
	_this = NewObject(MagicSquare);
	return _this;
}

void MagicSquare_delete(MagicSquare* _this) {
	free(_this);
}

void MagicSquare_setOrder(MagicSquare* _this, int anOrder) {
	_this->_order = anOrder;
}

int	MagicSquare_order(MagicSquare* _this) {
	return _this->_order;
}

Boolean	MagicSquare_orderIsValid(MagicSquare* _this) {
	if (_this->_order < 3) {
		AppView_out("[오류] 차수가 너무 작습니다. 3보다 크거나 같아야 합니다\n");
		return FALSE;
	}
	else if (_this->_order > MAX_ORDER) {
		char messageBuffer[255];
		sprintf_s(messageBuffer, sizeof(messageBuffer), "[오류] 차수가 너무 큽니다. %d 보다 작아야 합니다.\n", MAX_ORDER);
		AppView_out(messageBuffer);
		return FALSE;
	}
	else if ((_this->_order % 2) == 0) {
		AppView_out("[오류] 차수가 짝수입니다. 홀수이어야 합니다.\n");
		return FALSE;
	}
	else {
		return TRUE;
	}
}

void MagicSquare_solve(MagicSquare* _this) {
	CellLocation currentLoc;
	CellLocation nextLoc;
	int row, col;

	for (row = 0; row < _this->_order; row++) {
		for (col = 0; col < _this->_order; col++) {
			_this->_board[row][col] = EMPTY_CELL;
		}
	}
	currentLoc._row = 0;
	currentLoc._col = _this->_order / 2;
	nextLoc._row = 0;
	nextLoc._col = 0;
	int cellValue = 1;
	_this->_board[currentLoc._row][currentLoc._col] = cellValue;

	int lastCellValue = _this->_order * _this->_order;
	cellValue = 2;
	for (cellValue = 2; cellValue <= lastCellValue; cellValue++) {
		nextLoc._row = currentLoc._row - 1;
		if (nextLoc._row < 0) {
			nextLoc._row = _this->_order - 1;
		}
		nextLoc._col = currentLoc._col + 1;
		if (nextLoc._col >= _this->_order) {
			nextLoc._col = 0;
		}

		if (_this->_board[nextLoc._row][nextLoc._col] != EMPTY_CELL) {
			nextLoc._row = currentLoc._row + 1;
			nextLoc._col = currentLoc._col;
		}
		currentLoc = nextLoc;
		_this->_board[currentLoc._row][currentLoc._col] = cellValue;
	}
}

int	MagicSquare_cell(MagicSquare* _this, int aRow, int aCol) {
	if ((0 <= aRow && aRow < _this->_order) && 0 <= aCol && aCol < _this->_order) {
		return _this->_board[aRow][aCol];
	}
	else {
		return -1;
	}
}