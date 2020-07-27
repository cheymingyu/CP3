#include "Element.h"

struct _Element
{
	Key*	_key;
	Object* _object;
};

Element* Element_new() {
	Element* _this = NewObject(Element);
	_this->_key = NULL;
	_this->_object = NULL;
	return _this;
}

Element* Element_newWith(Key* aKey, Object* anObject) {
	Element* _this = NewObject(Element);
	_this->_key = aKey;
	_this->_object = anObject;
	return _this;
}

void Element_delete(Element* _this) {
	free(_this);
}

void Element_setKey(Element* _this, Key* newKey) {
	_this->_key = newKey;
}

Key* Element_key(Element* _this) {
	return _this->_key;
}

void Element_setObject(Element* _this, Object* newObject) {
	_this->_object = newObject;
}

Object* Element_object(Element* _this) {
	return _this->_object;
}