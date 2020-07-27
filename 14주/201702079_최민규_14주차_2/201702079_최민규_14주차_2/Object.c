#include "Object.h"

struct _Object
{
	ObjectValue _value;
};

Object* Object_new(void) {
	Object* _this = NewObject(Object);
	_this->_value = 0;
	return _this;
}

Object* Object_newWith(ObjectValue givenValue) {
	Object* _this = NewObject(Object);
	_this->_value = givenValue;
	return _this;
}

void	Object_delete(Object* _this) {
	free(_this);
}

void Object_setValue(Object* _this, ObjectValue newValue) {
	_this->_value = newValue;
}

ObjectValue Object_value(Object* _this) {
	return _this->_value;
}