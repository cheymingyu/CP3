#include "BinaryNode.h"

struct _BinaryNode
{
	Element* _element;
	BinaryNode* _left;
	BinaryNode* _right;
};

BinaryNode* BinaryNode_new(void) {
	BinaryNode* _this = NewObject(BinaryNode);
	_this->_element = NULL;
	_this->_left = NULL;
	_this->_right = NULL;
	return _this;
}

BinaryNode* BinaryNode_newWith(Element* anElement , BinaryNode* aLeft, BinaryNode* aRight) {
	BinaryNode* _this = NewObject(BinaryNode);
	_this->_element = anElement;
	_this->_left = aLeft;
	_this->_right = aRight;
	return _this;
}

void BinaryNode_delete(BinaryNode* _this) {
	free(_this);
}

void BinaryNode_setElement(BinaryNode* _this, Element* anElement) {
	_this->_element = anElement;
}

Element* BinaryNode_Element(BinaryNode* _this) {
	return _this->_element;
}

void BinaryNode_setLeft(BinaryNode* _this, BinaryNode* aLeft) {
	_this->_left = aLeft;
}

BinaryNode* BinaryNode_left(BinaryNode* _this) {
	return _this->_left;
}

void BinaryNode_setRight(BinaryNode* _this, BinaryNode* aRight) {
	_this->_right = aRight;
}

BinaryNode* BinaryNode_right(BinaryNode* _this) {
	return _this->_right;
}