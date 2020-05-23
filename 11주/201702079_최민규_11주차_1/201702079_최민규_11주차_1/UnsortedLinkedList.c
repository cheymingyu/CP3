#include "UnsortedLinkedList.h"
#include "Node.h"

struct _UnsortedLinkedList
{
	int		_size;
	Node*	_head;
};

UnsortedLinkedList* UnsortedLinkedList_new() {
	UnsortedLinkedList* _this = NewObject(UnsortedLinkedList);
	_this->_size = 0;
	_this->_head = NULL;
	return _this;
}

void UnsortedLinkedList_delete(UnsortedLinkedList* _this) {
	free(_this);
}

Boolean UnsortedLinkedList_isEmpty(UnsortedLinkedList* _this) {
	return (_this->_size == 0);
}

Boolean UnsortedLinkedList_isFull(UnsortedLinkedList* _this) {
	return FALSE;	// We assume always FALSE
}

Boolean UnsortedLinkedList_add(UnsortedLinkedList* _this, Element anElement) {
	if (UnsortedLinkedList_isFull(_this)) {
		return FALSE;
	}
	else {
		Node* nodeForAdd = Node_new();
		Node_setElement(nodeForAdd, anElement);
		Node_setNext(nodeForAdd, _this->_head);
		_this->_head = nodeForAdd;
		_this->_size++;
		return TRUE;
	}
}

Element UnsortedLinkedList_min(UnsortedLinkedList* _this) {
	if (UnsortedLinkedList_isEmpty(_this)) {
		return ELEMENT_DOES_NOT_EXIST;
	}
	else {
		int min = Node_element(_this->_head);
		Node* currentNode = Node_next(_this->_head);
		while (currentNode != NULL) {
			if (Node_element(currentNode) < min) {
				min = Node_element(currentNode);
			}
			currentNode = Node_next(currentNode);
		}
		return min;
	}
}

Element UnsortedLinkedList_removeMax(UnsortedLinkedList* _this) {
	if (UnsortedLinkedList_isEmpty(_this)) {
		return ELEMENT_DOES_NOT_EXIST;
	}
	else {
		int max = Node_element(_this->_head);
		Node* currentNode = _this->_head;
		Node* nextNode = Node_next(_this->_head);
		Node* previousNodeOfMax = NULL;
		while (nextNode != NULL) {	// [중요] max를 갖는노드의 앞 노드를 찾는다.
			if (Node_element(nextNode) > max) {
				max = Node_element(nextNode);
				previousNodeOfMax = currentNode;
			}
			currentNode = nextNode;
			nextNode = Node_next(nextNode);
		}
		Node* removedNode = nextNode;
		if (previousNodeOfMax == NULL) {	// 맨 앞 노드가 max를 갖고 있다.
			// 연결 체인의 맨 앞 노드 삭제
			removedNode = _this->_head;
			_this->_head = Node_next(_this->_head);
		}
		else {	// max를 갖고 있는 노드는 previousNodeOfMax의 다음 노드이다.
			// 연결 체인의 중간 노드 삭제
			removedNode = Node_next(previousNodeOfMax);
			Node_setNext(previousNodeOfMax, Node_next(removedNode));
		}
		_this->_size--;
		Node_delete(removedNode);
		return max;
	}
}
