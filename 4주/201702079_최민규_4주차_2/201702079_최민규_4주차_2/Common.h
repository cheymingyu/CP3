#pragma once

#define MAX_ORDER 99
#define END_OF_RUN -1

typedef enum { FALSE, TRUE } Boolean;

typedef struct {
	int _order;
	int _board[MAX_ORDER][MAX_ORDER];
} MagicSquare;