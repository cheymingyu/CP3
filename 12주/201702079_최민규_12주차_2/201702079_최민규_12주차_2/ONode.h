#pragma once
#include "Common.h"

typedef struct _ONode ONode;

ONode*	ONode_new();
void	ONode_delete(ONode* _this);

void ONode_setElement(ONode* _this, ElementForOStack newElementForOStack);
ElementForOStack ONode_element(ONode* _this);

void ONode_setNext(ONode* _this, ONode* newNext);
ONode* ONode_next(ONode* _this);