#pragma once
#include "Common.h"
#include "Key.h"
#include "Object.h"
#include "Element.h"


typedef struct _SortedArrayDictionary SortedArrayDictionary;

SortedArrayDictionary* SortedArrayDictionary_new(int maxSize);
void SortedArrayDictionary_delete(SortedArrayDictionary* _this);

Boolean SortedArrayDictionary_isEmpty(SortedArrayDictionary* _this);
Boolean SortedArrayDictionary_isFull(SortedArrayDictionary* _this);

Boolean	SortedArrayDictionary_addKeyAndObject(SortedArrayDictionary* _this, Key* aKey, Object* anObject);
Boolean SortedArrayDictionary_keyDoesExist(SortedArrayDictionary* _this, Key* aKey);
Element* SortedArrayDictionary_removeObjectForKey(SortedArrayDictionary* _this, Key* aKey);