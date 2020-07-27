#pragma once
#include "Common.h"
#include "Element.h"

typedef struct _BinaryNode BinaryNode;

BinaryNode* BinaryNode_new(void);
BinaryNode* BinaryNode_newWith(Element* anElement, BinaryNode* aLeft, BinaryNode* aRight);
void		BinaryNode_delete(BinaryNode* _this);

void BinaryNode_setElement(BinaryNode* _this, Element* anElement);
Element* BinaryNode_Element(BinaryNode* _this);
void BinaryNode_setLeft(BinaryNode* _this, BinaryNode* aLeft);
BinaryNode* BinaryNode_left(BinaryNode* _this);
void BinaryNode_setRight(BinaryNode* _this, BinaryNode* aRight);
BinaryNode* BinaryNode_right(BinaryNode* _this);