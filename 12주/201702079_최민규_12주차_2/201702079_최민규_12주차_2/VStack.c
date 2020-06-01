#include "VStack.h"
#include "VNode.h"

struct _VStack
{
	int		_size;
	VNode*	_top;
};

void VStack_deleteLinkedChain(VStack* _this);
void VStack_deleteLinkedChainRecursively(VNode* firstNode);

VStack*	VStack_new() {
	VStack*_this;
	_this = NewObject(VStack);
	_this->_top = NULL;
	_this->_size = 0;
	return _this;
}

void	VStack_delete(VStack* _this) {
	VStack_deleteLinkedChain(_this);
	free(_this);
}

Boolean VStack_isEmpty(VStack* _this) {
	return (_this->_size == 0);
}

Boolean VStack_isFull(VStack* _this) {
	return FALSE;
}

int	VStack_size(VStack* _this) {
	return _this->_size;
}

Boolean VStack_push(VStack* _this, ElementForVStack anElementForVstack) {
	if (VStack_isFull(_this)) {
		return FALSE;
	}
	VNode* nodeForPush = VNode_new();
	VNode_setElement(nodeForPush, anElementForVstack);
	VNode_setNext(nodeForPush, _this->_top);
	_this->_top = nodeForPush;
	_this->_size++;
	return TRUE;
}

void	VStack_reset(VStack* _this) {
	_this->_top = NULL;
	_this->_size = 0;
}

ElementForVStack VStack_pop(VStack* _this) {
	if (VStack_isEmpty(_this)) {
		return -1;
	}
	VNode* poppedNode = _this->_top;
	ElementForVStack poppedElement = VNode_element(poppedNode);
	_this->_top = VNode_next(poppedNode);
	VNode_delete(poppedNode);
	_this->_size--;
	return poppedElement;
}

ElementForVStack VStack_peek(VStack* _this) {
	if (VStack_isEmpty(_this)) {
		return -1;
	}
	else {
		Element topElement = VNode_element(_this->_top);
		return topElement;
	}
}

ElementForVStack VStack_elementAt(VStack* _this, int order) {
	int numberOfIteration = _this->_size - order - 1;

	VNode* currentNode = _this->_top;
	for (int i = 0; i < numberOfIteration; i++) {
		currentNode = VNode_next(currentNode);
	}
	return VNode_element(currentNode);
}

void VStack_deleteLinkedChain(VStack* _this) {
	VNode* currentNode = _this->_top;
	VNode* nodeToBeDeleted = NULL;
	while (currentNode != NULL) {
		nodeToBeDeleted = currentNode;
		currentNode = VNode_next(currentNode);
		VNode_delete(nodeToBeDeleted);
	}
}

void VStack_deleteLinkedChainRecursively(VNode* firstNode) {
	if (firstNode != NULL) {
		VStack_deleteLinkedChainRecursively(VNode_next(firstNode));
		VNode_delete(firstNode);
	}
}