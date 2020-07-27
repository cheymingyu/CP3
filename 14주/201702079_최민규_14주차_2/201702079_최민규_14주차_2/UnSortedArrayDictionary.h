#pragma once
#include "Common.h"
#include "Key.h"
#include "Object.h"
#include "Element.h"

typedef struct _UnSortedArrayDictionary UnSortedArrayDictionary;

UnSortedArrayDictionary* UnSortedArrayDictionary_new(int maxSize);
void UnSortedArrayDictionary_delete(UnSortedArrayDictionary* _this);

Boolean UnSortedArrayDictionary_isEmpty(UnSortedArrayDictionary* _this);
Boolean UnSortedArrayDictionary_isFull(UnSortedArrayDictionary* _this);

Boolean	UnSortedArrayDictionary_addKeyAndObject(UnSortedArrayDictionary* _this, Key* aKey, Object* anObject);
Boolean UnSortedArrayDictionary_keyDoesExist(UnSortedArrayDictionary* _this, Key* aKey);
Element* UnSortedArrayDictionary_removeObjectForKey(UnSortedArrayDictionary* _this, Key* aKey);