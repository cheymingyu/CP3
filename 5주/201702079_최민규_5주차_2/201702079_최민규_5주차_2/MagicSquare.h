#pragma once
#include "Common.h"

MagicSquare*	MagicSquare_new();
void			MagicSquare_delete(MagicSquare* _this);
void			MagicSquare_setOrder(MagicSquare* _this, int anOrder);
int				MagicSquare_order(MagicSquare* _this);
Boolean			MagicSquare_orderIsValid(MagicSquare* _this);
void			MagicSquare_solve(MagicSquare* _this);
int				MagicSquare_cell(MagicSquare* _this, int aRow, int aCol);