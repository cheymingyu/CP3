#include "Key.h"

struct _Key
{
	KeyValue _value;
};

Key* Key_new(void) {
	Key* _this = NewObject(Key);
	_this->_value = 0;
	return _this;
}

Key* Key_newWith(KeyValue givenValue) {
	Key* _this = NewObject(Key);
	_this->_value = givenValue;
	return _this;
}

void Key_delete(Key* _this) {
	free(_this);
}

void Key_setValue(Key* _this, KeyValue newValue) {
	_this->_value = newValue;
}

KeyValue Key_value(Key* _this) {
	return _this->_value;
}

int Key_compareTo(Key* _this, Key* otherKey) {
	if (_this->_value > Key_value(otherKey)) {
		return 1;
	}
	else if (_this->_value == Key_value(otherKey)) {
		return 0;
	}
	else {
		return -1;
	}
}