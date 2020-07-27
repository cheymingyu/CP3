#pragma once
#include "Common.h"
#include "Key.h"
#include "Object.h"
#include "Element.h"


typedef struct _BinarySearchTreeDictionary BinarySearchTreeDictionary;

BinarySearchTreeDictionary* BinarySearchTreeDictionary_new(int maxSize);
void BinarySearchTreeDictionary_delete(BinarySearchTreeDictionary* _this);

Boolean BinarySearchTreeDictionary_isEmpty(BinarySearchTreeDictionary* _this);
Boolean BinarySearchTreeDictionary_isFull(BinarySearchTreeDictionary* _this);

Boolean	BinarySearchTreeDictionary_addKeyAndObject(BinarySearchTreeDictionary* _this, Key* aKey, Object* anObject);
Boolean BinarySearchTreeDictionary_keyDoesExist(BinarySearchTreeDictionary* _this, Key* aKey);
Element* BinarySearchTreeDictionary_removeObjectForKey(BinarySearchTreeDictionary* _this, Key* aKey);