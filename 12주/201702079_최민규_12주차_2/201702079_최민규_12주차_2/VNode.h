#pragma once
#include "Common.h"

typedef struct _VNode VNode;

VNode*	VNode_new();
void	VNode_delete(VNode* _this);

void VNode_setElement(VNode* _this, ElementForVStack newElementForVStack);
ElementForVStack VNode_element(VNode* _this);

void VNode_setNext(VNode* _this, VNode* newNext);
VNode* VNode_next(VNode* _this);