#include "SortedArrayDictionary.h"

struct _SortedArrayDictionary
{
	int			_capacity;
	int			_size;
	Element**	_elements;
};

int SortedArrayDictionary_positionUsingBinarySearch(SortedArrayDictionary* _this, Key* aKey);
void SortedArrayDictionary_addAt(SortedArrayDictionary* _this, Element* anElement, int aPosition);
void SortedArrayDictionary_removeGapAt(SortedArrayDictionary* _this, int searchedPosition);

SortedArrayDictionary* SortedArrayDictionary_new(int maxSize) {
	SortedArrayDictionary* _this;
	_this = NewObject(SortedArrayDictionary);
	_this->_capacity = maxSize;
	_this->_elements = NewVector(Element*, _this->_capacity);
	_this->_size = 0;
	return _this;
}

void SortedArrayDictionary_delete(SortedArrayDictionary* _this) {
	free(_this->_elements);
	free(_this);
}

Boolean SortedArrayDictionary_isEmpty(SortedArrayDictionary* _this) {
	return (_this->_size == 0);
}

Boolean SortedArrayDictionary_isFull(SortedArrayDictionary* _this) {
	return (_this->_size == _this->_capacity);
}

Boolean	SortedArrayDictionary_addKeyAndObject(SortedArrayDictionary* _this, Key* aKey, Object* anObject) {
	if (SortedArrayDictionary_isFull(_this)) {
		return FALSE;
	}
	else {
		Element* elementForAdd = Element_newWith(aKey, anObject);
		int positionForAdd =
			SortedArrayDictionary_positionUsingBinarySearch(_this, aKey);
		SortedArrayDictionary_addAt(_this, elementForAdd, positionForAdd);
		return TRUE;
	}
}

int SortedArrayDictionary_positionUsingBinarySearch(SortedArrayDictionary* _this, Key* aKey) {
	int left = 0;
	int right = _this->_size - 1;
	int mid;
	Element* midElement = Element_new();
	while (left <= right) {
		mid = (left + right) / 2;
		midElement = _this->_elements[mid];
		if (midElement != NULL) {
			if (Key_compareTo(aKey, Element_key(midElement)) == 0) {
				return mid;
			}
			else if (Key_compareTo(aKey, Element_key(midElement)) < 0) {
				right = mid - 1;
			}
			else if (Key_compareTo(aKey, Element_key(midElement)) > 0) {
				left = mid + 1;
			}
		}
	}
	return left;
}

void SortedArrayDictionary_addAt(SortedArrayDictionary* _this, Element* anElement, int aPosition) {
	for (int i = _this->_size - 1; i >= aPosition; i--) {
		_this->_elements[i + 1] = _this->_elements[i];
	}
	_this->_elements[aPosition] = anElement;
	_this->_size++;
}

Boolean SortedArrayDictionary_keyDoesExist(SortedArrayDictionary* _this, Key* aKey) {
	if (SortedArrayDictionary_isEmpty(_this)) {
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

Element* SortedArrayDictionary_removeObjectForKey(SortedArrayDictionary* _this, Key* aKey) {
	Element* elementForRemove = Element_new();
	Element_setKey(elementForRemove, aKey);
	int positionToRemove = 0;
	while (!SortedArrayDictionary_isEmpty(_this) && (positionToRemove < _this->_size)) {
		if (Key_compareTo(aKey, Element_key(_this->_elements[positionToRemove])) == 0) {
			elementForRemove = _this->_elements[positionToRemove];
			SortedArrayDictionary_removeGapAt(_this, positionToRemove);
			return elementForRemove;
		}
		positionToRemove++;
	}
	return NULL;
}

void SortedArrayDictionary_removeGapAt(SortedArrayDictionary* _this, int searchedPosition) {
	for (int i = searchedPosition; i < _this->_size - 2; i++) {
		_this->_elements[i] = _this->_elements[i + 1];
	}
	_this->_size--;
}