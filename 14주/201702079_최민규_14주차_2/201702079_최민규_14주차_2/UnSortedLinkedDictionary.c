#include "UnSortedLinkedDictionary.h"
#include "Node.h"

struct _UnSortedLinkedDictionary
{
	int		_size;
	Node*	_head;
};

void UnSortedLinkedDictionary_deleteLinkedChain(UnSortedLinkedDictionary* _this);

UnSortedLinkedDictionary* UnSortedLinkedDictionary_new() {
	UnSortedLinkedDictionary* _this = NewObject(UnSortedLinkedDictionary);
	_this->_size = 0;
	_this->_head = NULL;
	return _this;
}
void UnSortedLinkedDictionary_delete(UnSortedLinkedDictionary* _this) {
	UnSortedLinkedDictionary_deleteLinkedChain(_this);
	free(_this);
}

Boolean UnSortedLinkedDictionary_isEmpty(UnSortedLinkedDictionary* _this) {
	return (_this->_size == 0);
}

Boolean UnSortedLinkedDictionary_isFull(UnSortedLinkedDictionary* _this) {
	return FALSE;
}

Boolean	UnSortedLinkedDictionary_addKeyAndObject(UnSortedLinkedDictionary* _this, Key* aKey, Object* anObject) {
	if (UnSortedLinkedDictionary_isFull(_this)) {
		return FALSE;
	}
	else {
		Element* elementForAdd = Element_newWith(aKey, anObject);
		Node* nodeForAdd = Node_new();
		Node_setElement(nodeForAdd, elementForAdd);
		Node_setNext(nodeForAdd, _this->_head);
		_this->_head = nodeForAdd;
		_this->_size++;
		return TRUE;
	}
}

Boolean UnSortedLinkedDictionary_keyDoesExist(UnSortedLinkedDictionary* _this, Key* aKey) {
	Node* currentNode = _this->_head;
	Element* currentElement = Node_element(currentNode);
	Key* currentKey = Element_key(currentElement);
	for (int i = 0; i < _this->_size; i++) {
		if (Key_compareTo(currentKey, aKey) == 0) {
			return TRUE;
		}
		currentNode = Node_next(currentNode);
		currentElement = Node_element(currentNode);
		currentKey = Element_key(currentElement);
	}
	return FALSE;
}

Element* UnSortedLinkedDictionary_removeObjectForKey(UnSortedLinkedDictionary* _this, Key* aKey) {
	Node* currentNode = _this->_head;
	Node* nextNode = Node_next(currentNode);
	Node* previousNodeOfRemove = NULL;
	Element* removeElement = NULL;
	if (nextNode != NULL) {
		Element* nextElement = Node_element(nextNode);
		Key* nextKey = Element_key(nextElement);
	}
	if (nextNode != NULL) {
		Element* nextElement = Node_element(nextNode);
		Key* nextKey = Element_key(nextElement);
		while (nextNode != NULL) {
			if (Key_compareTo(nextKey, aKey) == 0) {
				removeElement = Node_element(nextNode);
				previousNodeOfRemove = currentNode;
			}
			currentNode = nextNode;
			nextNode = Node_next(nextNode);
			if (nextNode != NULL) {
				nextElement = Node_element(nextNode);
				nextKey = Element_key(nextElement);
			}
		}
	}
	
	Node* removedNode = nextNode;
	if (previousNodeOfRemove == NULL) {
		removedNode = _this->_head;
		_this->_head = Node_next(_this->_head);
	}
	else {
		removedNode = Node_next(previousNodeOfRemove);
		Node_setNext(previousNodeOfRemove, Node_next(removedNode));
	}
	_this->_size--;
	Node_delete(removedNode);
	return removeElement;
}

void UnSortedLinkedDictionary_deleteLinkedChain(UnSortedLinkedDictionary* _this) {
	Node* currentNode = _this->_head;
	Node* nodeToBeDeleted = NULL;
	while (currentNode != NULL) {
		nodeToBeDeleted = currentNode;
		currentNode = Node_next(currentNode);
		Node_delete(nodeToBeDeleted);
	}
}