#include "Queue.h"
#include "Node.h"

#define VALUE_FOR_EMPTY '\0'

struct _Queue
{
	int		_size;
	Node*	_front;
	Node*	_rear;
};

void Queue_deleteLinkedChain(Queue* _this);

Queue*	Queue_new(void) {
	Queue* _this;
	_this = NewObject(Queue);
	_this->_size = 0;
	_this->_front = NULL;
	_this->_rear = NULL;
	return _this;
}

void	Queue_delete(Queue* _this) {
	Queue_deleteLinkedChain(_this);
	free(_this);
}

Boolean Queue_isEmpty(Queue* _this) {
	return _this->_size == 0;
}

Boolean Queue_isFull(Queue* _this) {
	return FALSE;
}

int		Queue_size(Queue*_this) {
	return _this->_size;
}

Element Queue_elementAt(Queue* _this, int anOrder) {
	if (anOrder == 0) {
		return Node_element(_this->_front);
	}
	else {
		Node* currentNode = _this->_front;
		for (int i = 0; i < anOrder; i++) {
			currentNode = Node_next(currentNode);
		}
		return Node_element(currentNode);
	}
}

Boolean Queue_add(Queue* _this, Element anElement) {
	if (Queue_isFull(_this)) {
		return FALSE;
	}
	else {
		Node* nodeForAdd = Node_new();
		Node_setElement(nodeForAdd, anElement);
		Node_setNext(nodeForAdd, NULL);
		if (Queue_isEmpty(_this)) {
			_this->_front = nodeForAdd;
		}
		else {
			Node_setNext(_this->_rear, nodeForAdd);
		}
		_this->_rear = nodeForAdd;
		_this->_size++;
		return TRUE;
	}
}

Element Queue_remove(Queue* _this) {
	if (Queue_isEmpty(_this)) {
		return VALUE_FOR_EMPTY;
	}
	else {
		Node* removedNode = _this->_front;
		if (_this->_size == 1) {
			_this->_front = NULL;
			_this->_rear = NULL;
		}
		else {
			_this->_front = Node_next(_this->_front);
		}
		Element removedElement = Node_element(removedNode);
		Node_delete(removedNode);
		_this->_size--;
		return removedElement;
	}
}

void Queue_deleteLinkedChain(Queue* _this) {
	Node* currentNode = _this->_front;
	Node* nodeToBeDeleted = NULL;
	while (currentNode != NULL) {
		nodeToBeDeleted = currentNode;
		currentNode = Node_next(currentNode);
		Node_delete(nodeToBeDeleted);
	}
}