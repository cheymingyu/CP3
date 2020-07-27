#include "SortedLinkedDictionary.h"
#include "Node.h"

struct _SortedLinkedDictionary
{
	int		_size;
	Node*	_head;
};

void SortedLinkedDictionary_deleteLinkedChain(SortedLinkedDictionary* _this);

SortedLinkedDictionary* SortedLinkedDictionary_new(int maxSize) {
	SortedLinkedDictionary* _this = NewObject(SortedLinkedDictionary);
	_this->_size = 0;
	_this->_head = NULL;
	return _this;
}

void SortedLinkedDictionary_delete(SortedLinkedDictionary* _this) {
	SortedLinkedDictionary_deleteLinkedChain(_this);
	free(_this);
}

Boolean SortedLinkedDictionary_isEmpty(SortedLinkedDictionary* _this) {
	return (_this->_size == 0);
}

Boolean SortedLinkedDictionary_isFull(SortedLinkedDictionary* _this) {
	return FALSE;
}

Boolean SortedLinkedDictionary_addKeyAndObject(SortedLinkedDictionary* _this, Key* aKey, Object* anObject) {
	if (SortedLinkedDictionary_isFull(_this)) {
		return FALSE;
	}
	else {
		Node* nodeForAdd = Node_new();
		Element* elementForAdd = Element_newWith(aKey, anObject);
		Node_setElement(nodeForAdd, elementForAdd);
		Node_setNext(nodeForAdd, NULL);
		if (SortedLinkedDictionary_isEmpty(_this)) {
			_this->_head = nodeForAdd;
		}
		else {
			Node* previousNode = NULL;
			Node* currentNode = _this->_head;
			while (currentNode != NULL && Key_compareTo(Element_key(Node_element(currentNode)), aKey) < 0) {
				previousNode = currentNode;
				currentNode = Node_next(currentNode);
			}
			if (previousNode == NULL) {
				Node_setNext(nodeForAdd, _this->_head);
				_this->_head = nodeForAdd;
			}
			else {
				Node_setNext(nodeForAdd, currentNode);
				Node_setNext(previousNode, nodeForAdd);
			}
		}
		_this->_size++;
		return TRUE;
	}
}

Boolean SortedLinkedDictionary_keyDoesExist(SortedLinkedDictionary* _this, Key* aKey) {
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

Element* SortedLinkedDictionary_removeObjectForKey(SortedLinkedDictionary* _this, Key* aKey) {
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

void SortedLinkedDictionary_deleteLinkedChain(SortedLinkedDictionary* _this) {
	Node* currentNode = _this->_head;
	Node* nodeToBeDeleted = NULL;
	while (currentNode != NULL) {
		nodeToBeDeleted = currentNode;
		currentNode = Node_next(currentNode);
		Node_delete(nodeToBeDeleted);
	}
}