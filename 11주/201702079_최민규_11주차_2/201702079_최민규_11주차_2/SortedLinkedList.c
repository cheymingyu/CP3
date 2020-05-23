#include "SortedLinkedList.h"
#include "Node.h"

struct _SortedLinkedList
{
	int		_size;
	Node*	_head;
};

SortedLinkedList* SortedLinkedList_new() {
	SortedLinkedList* _this = NewObject(SortedLinkedList);
	_this->_size = 0;
	_this->_head = NULL;
	return _this;
}

void SortedLinkedList_delete(SortedLinkedList* _this) {
	free(_this);
}

Boolean SortedLinkedList_isEmpty(SortedLinkedList* _this) {
	return (_this->_size == 0);
}

Boolean SortedLinkedList_isFull(SortedLinkedList* _this) {
	return FALSE;	// We assume always FALSE
}

Boolean SortedLinkedList_add(SortedLinkedList* _this, Element anElement) {
	if (SortedLinkedList_isFull(_this)) {
		return FALSE;
	}
	else {
		Node* nodeForAdd = Node_new();
		Node_setElement(nodeForAdd, anElement);
		Node_setNext(nodeForAdd, NULL);
		if (SortedLinkedList_isEmpty(_this)) {	// 이 검사는 하지 않아도, 다음 else 부분 코드로 정상적인 처리 가능.
			_this->_head = nodeForAdd;
		}
		else {
			Node* previousNode = NULL;
			Node* currentNode = _this->_head;
			while (currentNode != NULL && Node_element(currentNode) < anElement) {	// 삽입 위치를 찾는다.
				previousNode = currentNode;
				currentNode = Node_next(currentNode);
			}
			if (previousNode == NULL) {	// 연결 체인의 맨 앞에 삽입
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

Element SortedLinkedList_min(SortedLinkedList* _this) {
	if (SortedLinkedList_isEmpty(_this)) {
		return ELEMENT_DOES_NOT_EXIST;
	}
	else {	// 맨 앞 노드가 min을 갖고 있다.
		int min = Node_element(_this->_head);
		return min;
	}
}

Element SortedLinkedList_removeMax(SortedLinkedList* _this) {
	if (SortedLinkedList_isEmpty(_this)) {
		return ELEMENT_DOES_NOT_EXIST;
	}
	else {
		Node* maxNode = NULL;
		if (_this->_size == 1) {	// 연결 체인에 노드가 단 하나만 존재한다.
			// 단 하나의 노드는 연결 체인의 head 노드이며, 이것을 삭제한다.
			maxNode = _this->_head;
			_this->_head = NULL;
		}
		else {	// 연결 체인에 2개 이상의 노드가 있다.
			Node* previousNode = _this->_head;
			Node* currentNode = Node_next(_this->_head);
			Node* nextNode = Node_next(currentNode);
			while (nextNode != NULL) {	// [중요] max는 맨 끝 노드에 있다.
				previousNode = currentNode;
				currentNode = nextNode;
				nextNode = Node_next(nextNode);
			}
			maxNode = currentNode;	// 연결 체인의 끝 노드
			Node_setNext(previousNode, NULL);	// 끝 노드를 연결체인에서 삭제한다.

		}
		int max = Node_element(maxNode);
		_this->_size--;
		return max;
	}
}
