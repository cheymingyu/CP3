#pragma once
#include "Key.h"
#include "Object.h"

typedef struct _BinaryNode BinaryNode;

BinaryNode* BinaryNode_new(void);
BinaryNode* BinaryNode_newWith(Key* aKey, Object* anObject, BinaryNode* aLeft, BinaryNode* aRight);
void		BinaryNode_delete(BinaryNode* _this);

void BinaryNode_setKey(BinaryNode* _this, Key* aKey);
Key* BinaryNode_key(BinaryNode* _this);
void BinaryNode_setObject(BinaryNode* _this, Object* anObject);
Object* BinaryNode_object(BinaryNode* _this);
void BinaryNode_setLeft(BinaryNode* _this, BinaryNode* aLeft);
BinaryNode* BinaryNode_left(BinaryNode* _this);
void BinaryNode_setRight(BinaryNode* _this, BinaryNode* aRight);
BinaryNode* BinaryNode_right(BinaryNode* _this);