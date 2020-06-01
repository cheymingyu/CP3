#include "Stack.h"
#include "Node.h"

struct _Stack
{
	int		_size;
	Node*	_top;
};

void Stack_deleteLinkedChain(Stack* _this);
void Stack_deleteLinkedChainRecursively(Node* firstNode);

Stack*	Stack_new() {
	Stack*_this;
	_this = NewObject(Stack);
	_this->_top = NULL;
	_this->_size = 0;
	return _this;
}

void	Stack_delete(Stack* _this) {
	Stack_deleteLinkedChain(_this);
	free(_this);
}

Boolean Stack_isEmpty(Stack* _this) {
	return (_this->_size == 0);
}

Boolean Stack_isFull(Stack* _this) {
	return (_this->_size >= 5);
}

int	Stack_size(Stack* _this) {
	return _this->_size;
}

Boolean Stack_push(Stack* _this, Element anElement) {
	if (Stack_isFull(_this)) {
		return FALSE;
	}
	Node* nodeForPush = Node_new();
	Node_setElement(nodeForPush, anElement);
	Node_setNext(nodeForPush, _this->_top);
	_this->_top = nodeForPush;
	_this->_size++;
	return TRUE;
}

void	Stack_reset(Stack* _this) {
	_this->_top = NULL;
	_this->_size = 0;
}

Element Stack_pop(Stack* _this) {
	if (Stack_isEmpty(_this)) {
		return 0;
	}
	Node* poppedNode = _this->_top;
	Element poppedElement = Node_element(poppedNode);
	_this->_top = Node_next(poppedNode);
	Node_delete(poppedNode);
	_this->_size--;
	return poppedElement;
}

Element Stack_peek(Stack* _this) {
	if (Stack_isEmpty(_this)) {
		return 0;
	}
	else{
		Element topElement = Node_element(_this->_top);
		return topElement;
	}
}

Element Stack_elementAt(Stack* _this, int order) {
	int numberOfIteration = _this->_size - order - 1;

	Node* currentNode = _this->_top;
	for (int i = 0; i < numberOfIteration; i++) {
		currentNode = Node_next(currentNode);
	}
	return Node_element(currentNode);
}

void Stack_deleteLinkedChain(Stack* _this) {
	Node* currentNode = _this->_top;
	Node* nodeToBeDeleted = NULL;
	while (currentNode != NULL) {
		nodeToBeDeleted = currentNode;
		currentNode = Node_next(currentNode);
		Node_delete(nodeToBeDeleted);
	}
}

void Stack_deleteLinkedChainRecursively(Node* firstNode) {
	if (firstNode != NULL) {
		Stack_deleteLinkedChainRecursively(Node_next(firstNode));
		Node_delete(firstNode);
	}
}