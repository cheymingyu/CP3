#include "UnSortedArrayDictionary.h"

struct _UnSortedArrayDictionary
{
	int			_capacity;
	int			_size;
	Element**	_elements;
};

void UnSortedArrayDictionary_removeGapAt(UnSortedArrayDictionary* _this, int searchedPosition);


UnSortedArrayDictionary* UnSortedArrayDictionary_new(int maxSize) {
	UnSortedArrayDictionary* _this;
	_this = NewObject(UnSortedArrayDictionary);
	_this->_capacity = maxSize;
	_this->_elements = NewVector(Element*, _this->_capacity);
	_this->_size = 0;
	return _this;
}

void UnSortedArrayDictionary_delete(UnSortedArrayDictionary* _this) {
	free(_this->_elements);
	free(_this);
}

Boolean UnSortedArrayDictionary_isEmpty(UnSortedArrayDictionary* _this) {
	return (_this->_size == 0);
}

Boolean UnSortedArrayDictionary_isFull(UnSortedArrayDictionary* _this) {
	return (_this->_size == _this->_capacity);
}

Boolean	UnSortedArrayDictionary_addKeyAndObject(UnSortedArrayDictionary* _this, Key* aKey, Object* anObject) {
	if (UnSortedArrayDictionary_isFull(_this)) {
		return FALSE;
	}
	else {
		Element* elementForAdd = Element_newWith(aKey, anObject);
		_this->_elements[_this->_size] = elementForAdd;
		_this->_size++;
		return TRUE;
	}
}

Boolean UnSortedArrayDictionary_keyDoesExist(UnSortedArrayDictionary* _this, Key* aKey) {
	if (UnSortedArrayDictionary_isEmpty(_this)) {
		return FALSE;
	}
	else {
		Element* elementForSearch = Element_new();
		Element_setKey(elementForSearch, aKey);
		int positionToSearch = 0;
		while (positionToSearch < _this->_size) {
			if (Key_compareTo(aKey, Element_key(_this->_elements[positionToSearch])) == 0) {
				return TRUE;
			}
			positionToSearch++;
		}
		return FALSE;
	}
}

Element* UnSortedArrayDictionary_removeObjectForKey(UnSortedArrayDictionary* _this, Key* aKey) {
	Element* elementForRemove = Element_new();
	Element_setKey(elementForRemove, aKey);
	int positionToRemove = 0;
	while (!UnSortedArrayDictionary_isEmpty(_this) && (positionToRemove < _this->_size)) {
		if (Key_compareTo(aKey, Element_key(_this->_elements[positionToRemove])) == 0) {
			elementForRemove = _this->_elements[positionToRemove];
			UnSortedArrayDictionary_removeGapAt(_this, positionToRemove);
			return elementForRemove;
		}
		positionToRemove++;
	}
	return NULL;
}

void UnSortedArrayDictionary_removeGapAt(UnSortedArrayDictionary* _this, int searchedPosition) {
	for (int i = searchedPosition; i < _this->_size - 2; i++) {
		_this->_elements[i] = _this->_elements[i + 1];
	}
	_this->_size--;
}