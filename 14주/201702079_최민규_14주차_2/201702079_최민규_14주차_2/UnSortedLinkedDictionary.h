#pragma once
#include "Common.h"
#include "Key.h"
#include "Object.h"
#include "Element.h"


typedef struct _UnSortedLinkedDictionary UnSortedLinkedDictionary;

UnSortedLinkedDictionary* UnSortedLinkedDictionary_new();
void UnSortedLinkedDictionary_delete(UnSortedLinkedDictionary* _this);

Boolean UnSortedLinkedDictionary_isEmpty(UnSortedLinkedDictionary* _this);
Boolean UnSortedLinkedDictionary_isFull(UnSortedLinkedDictionary* _this);

Boolean	UnSortedLinkedDictionary_addKeyAndObject(UnSortedLinkedDictionary* _this, Key* aKey, Object* anObject);
Boolean UnSortedLinkedDictionary_keyDoesExist(UnSortedLinkedDictionary* _this, Key* aKey);
Element* UnSortedLinkedDictionary_removeObjectForKey(UnSortedLinkedDictionary* _this, Key* aKey);