#pragma once
#include "Common.h"
typedef struct _VStack VStack;

VStack*	VStack_new();
void	VStack_delete(VStack* _this);

Boolean VStack_isEmpty(VStack* _this);
Boolean VStack_isFull(VStack* _this);
int		VStack_size(VStack* _this);
Boolean VStack_push(VStack* _this, ElementForVStack anElementForVStack);
void	VStack_reset(VStack* _this);

ElementForVStack VStack_pop(VStack* _this);
ElementForVStack VStack_peek(VStack* _this);
ElementForVStack VStack_elementAt(VStack* _this, int order);