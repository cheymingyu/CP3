#include "OStack.h"
#include "ONode.h"

struct _OStack
{
	int		_size;
	ONode*	_top;
};

void OStack_deleteLinkedChain(OStack* _this);
void OStack_deleteLinkedChainRecursively(ONode* firstNode);

OStack*	OStack_new() {
	OStack*_this;
	_this = NewObject(OStack);
	_this->_top = NULL;
	_this->_size = 0;
	return _this;
}

void	OStack_delete(OStack* _this) {
	OStack_deleteLinkedChain(_this);
	free(_this);
}

Boolean OStack_isEmpty(OStack* _this) {
	return (_this->_size == 0);
}

Boolean OStack_isFull(OStack* _this) {
	return FALSE;
}

int	OStack_size(OStack* _this) {
	return _this->_size;
}

Boolean OStack_push(OStack* _this, ElementForOStack anElementForOstack) {
	if (OStack_isFull(_this)) {
		return FALSE;
	}
	ONode* nodeForPush = ONode_new();
	ONode_setElement(nodeForPush, anElementForOstack);
	ONode_setNext(nodeForPush, _this->_top);
	_this->_top = nodeForPush;
	_this->_size++;
	return TRUE;
}

void	OStack_reset(OStack* _this) {
	_this->_top = NULL;
	_this->_size = 0;
}

ElementForOStack OStack_pop(OStack* _this) {
	if (OStack_isEmpty(_this)) {
		return -1;
	}
	ONode* poppedNode = _this->_top;
	ElementForOStack poppedElement = ONode_element(poppedNode);
	_this->_top = ONode_next(poppedNode);
	ONode_delete(poppedNode);
	_this->_size--;
	return poppedElement;
}

ElementForOStack OStack_peek(OStack* _this) {
	if (OStack_isEmpty(_this)) {
		return -1;
	}
	else {
		Element topElement = ONode_element(_this->_top);
		return topElement;
	}
}

ElementForOStack OStack_elementAt(OStack* _this, int order) {
	int numberOfIteration = _this->_size - order - 1;

	ONode* currentNode = _this->_top;
	for (int i = 0; i < numberOfIteration; i++) {
		currentNode = ONode_next(currentNode);
	}
	return ONode_element(currentNode);
}

void OStack_deleteLinkedChain(OStack* _this) {
	ONode* currentNode = _this->_top;
	ONode* nodeToBeDeleted = NULL;
	while (currentNode != NULL) {
		nodeToBeDeleted = currentNode;
		currentNode = ONode_next(currentNode);
		ONode_delete(nodeToBeDeleted);
	}
}

void OStack_deleteLinkedChainRecursively(ONode* firstNode) {
	if (firstNode != NULL) {
		OStack_deleteLinkedChainRecursively(ONode_next(firstNode));
		ONode_delete(firstNode);
	}
}