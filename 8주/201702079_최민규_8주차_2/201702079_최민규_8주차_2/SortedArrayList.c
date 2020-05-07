#include "SortedArrayList.h"

struct _SortedArrayList
{
	int			_capacity;
	int			_size;
	Element*	_elements;
};

int		SortedArrayList_maxPositionRecursively(SortedArrayList* _this, int left, int right);
int		SortedArrayList_minPositionRecursively(SortedArrayList* _this, int left, int right);
int		SortedArrayList_positionUsingBinarySearch(SortedArrayList* _this, Element anElement);
void	SortedArrayList_addAt(SortedArrayList* _this, Element anElement, int aPosition);
Element SortedArrayList_removeAt(SortedArrayList* _this, int aPosition);

SortedArrayList* SortedArrayList_new(int givenCapacity) {
	SortedArrayList* _this;
	_this = NewObject(SortedArrayList);
	_this->_capacity = givenCapacity;
	_this->_elements = NewVector(Element, _this->_capacity);
	_this->_size = 0;
	return _this;
}

void SortedArrayList_delete(SortedArrayList* _this) {
	free(_this);
}

Boolean SortedArrayList_isEmpty(SortedArrayList* _this) {
	if (_this->_size == 0) {
		return TRUE;
	}
	else
		return FALSE;
}

Boolean SortedArrayList_isFull(SortedArrayList* _this) {
	if (_this->_size == _this->_capacity) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

Boolean SortedArrayList_add(SortedArrayList* _this, Element anElement) {
	if (SortedArrayList_isFull(_this)) {
		return FALSE;
	}
	else {
		// 제 1단계: 삽입할 위치를 결정한다
		int positionForAdd =
			SortedArrayList_positionUsingBinarySearch(_this, anElement);
		// 제 2단계: 찾아진 삽입 위치에 주어진 원소를 삽입한다.
		SortedArrayList_addAt(_this, anElement, positionForAdd);
		return TRUE;
	}
}

Element SortedArrayList_removeMax(SortedArrayList* _this) {
	int maxPosition;
	Element max;
	maxPosition = _this->_size - 1;
	max = _this->_elements[maxPosition];
	SortedArrayList_removeAt(_this, maxPosition);
	return max;
}

Element SortedArrayList_min(SortedArrayList* _this) {
	int min;
	min = 0;
	return _this->_elements[min];
}

int SortedArrayList_positionUsingBinarySearch(
	SortedArrayList* _this, Element anElement) {
	int left = 0;
	int right = _this->_size - 1;
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (anElement == _this->_elements[mid]) {
			return mid;
		}
		else if (anElement < _this->_elements[mid]) {
			right = mid - 1;
		}
		else if (anElement > _this->_elements[mid]) {
			left = mid + 1;
		}
	}
	return left;
}

void SortedArrayList_addAt(
	SortedArrayList* _this, Element anElement, int aPosition) {
	for (int i = (_this->_size - 1); i > aPosition; i--) {
		_this->_elements[i + 1] = _this->_elements[i];
	}
	_this->_elements[aPosition] = anElement;
	(_this->_size)++;
}

Element SortedArrayList_removeAt(SortedArrayList* _this, int aPosition) {
	Element removedElement = _this->_elements[aPosition];
	for (int i = (aPosition + 1); i < (_this->_size); i++) {
		_this->_elements[i - 1] = _this->_elements[i];
	}
	_this->_size--;
	return removedElement;
}