#include "Queue.h"

#define VALUE_FOR_EMPTY '\0'

struct _Queue
{
	int		_maxLength;
	int		_front;
	int		_rear;
	Element* _elements;
};

int Queue_nextRear(Queue* _this);
int Queue_nextFront(Queue* _this);

Queue*	Queue_new(int givenCapacity) {
	Queue* _this;
	_this = NewObject(Queue);
	_this->_maxLength = givenCapacity + 1;
	_this->_elements = NewVector(Element, _this->_maxLength);
	_this->_front = 0;
	_this->_rear = 0;

	return _this;
}

void	Queue_delete(Queue* _this) {
	free(_this->_elements);
	free(_this);
}

Boolean Queue_isEmpty(Queue* _this) {
	return (_this->_front == _this->_rear);
}

Boolean Queue_isFull(Queue* _this) {
	int nextRear = Queue_nextRear(_this);
	return (nextRear == _this->_front);
}

int		Queue_size(Queue*_this) {
	if (_this->_front <= _this->_rear) {
		return (_this->_rear - _this->_front);
	}
	else {
		return (_this->_rear + _this->_maxLength - _this->_front);
	}
}

Element Queue_elementAt(Queue* _this, int anOrder) {
	if (anOrder == 0) {
		return _this->_elements[Queue_nextFront(_this)];
	}
	else {
		int currentLoc = _this->_front + 1;
		for (int i = 0; i < anOrder; i++) {
			currentLoc = (currentLoc + 1) % _this->_maxLength;
		}
		return _this->_elements[currentLoc];
	}
}

Boolean Queue_add(Queue* _this, Element anElement) {
	if (Queue_isFull(_this)) {
		return FALSE;
	}
	else {
		_this->_rear = Queue_nextRear(_this);
		_this->_elements[_this->_rear] = anElement;
		return TRUE;
	}
}

Element Queue_remove(Queue* _this) {
	Element removedElement;
	if (Queue_isEmpty(_this)) {
		return VALUE_FOR_EMPTY;
	}
	else {
		_this->_front = Queue_nextFront(_this);
		removedElement = _this->_elements[_this->_front];
		return removedElement;
	}
}

int Queue_nextRear(Queue* _this) {
	return (_this->_rear + 1) % _this->_maxLength;
}

int Queue_nextFront(Queue* _this) {
	return (_this->_front + 1) % _this->_maxLength;
}