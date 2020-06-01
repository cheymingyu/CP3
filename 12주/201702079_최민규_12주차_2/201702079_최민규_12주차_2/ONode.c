#include "ONode.h"

struct _ONode
{
	ElementForOStack	_elementforOStack;
	ONode*				_next;
};

ONode*	ONode_new() {
	ONode* _this = NewObject(ONode);
	return _this;
}

void	ONode_delete(ONode* _this) {
	free(_this);
}

void ONode_setElement(ONode* _this, ElementForOStack newElementForOStack) {
	_this->_elementforOStack = newElementForOStack;
}

ElementForOStack ONode_element(ONode* _this) {
	return _this->_elementforOStack;
}

void ONode_setNext(ONode* _this, ONode* newNext) {
	_this->_next = newNext;
}

ONode* ONode_next(ONode* _this) {
	return _this->_next;
}