#pragma once
#include "Common.h"
#include "Key.h"
#include "Object.h"

typedef struct _Element Element;

Element* Element_new();
Element* Element_newWith(Key* aKey, Object* anObject);
void Element_delete(Element* _this);

void Element_setKey(Element* _this, Key* newKey);
Key* Element_key(Element* _this);

void Element_setObject(Element* _this, Object* newObject);
Object* Element_object(Element* _this);