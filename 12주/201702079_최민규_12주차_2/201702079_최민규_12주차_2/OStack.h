#pragma once
#include "Common.h"

typedef struct _OStack OStack;

OStack*	OStack_new();
void	OStack_delete(OStack* _this);

Boolean OStack_isEmpty(OStack* _this);
Boolean OStack_isFull(OStack* _this);
int		OStack_size(OStack* _this);
Boolean OStack_push(OStack* _this, ElementForOStack anElementForOStack);
void	OStack_reset(OStack* _this);

ElementForOStack OStack_pop(OStack* _this);
ElementForOStack OStack_peek(OStack* _this);
ElementForOStack OStack_elementAt(OStack* _this, int order);