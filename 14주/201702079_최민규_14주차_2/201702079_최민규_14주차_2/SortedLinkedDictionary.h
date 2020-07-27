#pragma once
#include "Common.h"
#include "Key.h"
#include "Object.h"
#include "Element.h"


typedef struct _SortedLinkedDictionary SortedLinkedDictionary;

SortedLinkedDictionary* SortedLinkedDictionary_new();
void SortedLinkedDictionary_delete(SortedLinkedDictionary* _this);

Boolean SortedLinkedDictionary_isEmpty(SortedLinkedDictionary* _this);
Boolean SortedLinkedDictionary_isFull(SortedLinkedDictionary* _this);

Boolean	SortedLinkedDictionary_addKeyAndObject(SortedLinkedDictionary* _this, Key* aKey, Object* anObject);
Boolean SortedLinkedDictionary_keyDoesExist(SortedLinkedDictionary* _this, Key* aKey);
Element* SortedLinkedDictionary_removeObjectForKey(SortedLinkedDictionary* _this, Key* aKey);