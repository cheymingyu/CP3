#pragma once
#include "Common.h"
typedef struct _Stack Stack;

Stack*	Stack_new(int givenCapacity);
void	Stack_delete(Stack* _this);

Boolean Stack_isEmpty(Stack* _this);
Boolean Stack_isFull(Stack* _this);
int		Stack_size(Stack* _this);
Boolean Stack_push(Stack* _this, Element anElement);
Element Stack_pop(Stack* _this);

Element Stack_topElement(Stack* _this);
Element Stack_elementAt(Stack* _this, int anOrder);
void	Stack_reset(Stack* _this);