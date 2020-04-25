#pragma once
#include "Common.h"

Boolean MagicSquare_orderIsValid(MagicSquare* _this);
void	MagicSquare_solve(MagicSquare* _this);
void	MagicSquare_setOrder(MagicSquare* _this, int newOrder);
int		MagicSquare_order(MagicSquare* _this);