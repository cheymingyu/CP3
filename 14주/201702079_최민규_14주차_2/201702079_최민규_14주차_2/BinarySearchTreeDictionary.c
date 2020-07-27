#include "BinarySearchTreeDictionary.h"
#include "BinaryNode.h"

struct _BinarySearchTreeDictionary
{
	BinaryNode* _root;
	int			_size;
};

Boolean BinarySearchTreeDictionary_addToTree(BinarySearchTreeDictionary* _this, Key* aKey, Object* anObject, BinaryNode* parent);
Boolean BinarySearchTreeDictionary_searchTreeRecursively(BinarySearchTreeDictionary* _this, Key* aKey, BinaryNode* aNode);
Object* BinarySearchTreeDictionary_removeFromTreeRecursively(BinarySearchTreeDictionary* _this, Key* aKey, BinaryNode* parent);
BinaryNode* BinarySearchTreeDictionary_removeRightmostNodeOfLeftSubtree(BinarySearchTreeDictionary* _this, BinaryNode* rootOfSubtree);

BinarySearchTreeDictionary* BinarySearchTreeDictionary_new(int maxSize) {
	BinarySearchTreeDictionary* _this = NewObject(BinarySearchTreeDictionary);
	_this->_root = NULL;
	_this->_size = 0;
	return _this;
}

void BinarySearchTreeDictionary_delete(BinarySearchTreeDictionary* _this) {
	free(_this);
}

Boolean BinarySearchTreeDictionary_isEmpty(BinarySearchTreeDictionary* _this) {
	return (_this->_size == 0);
}

Boolean BinarySearchTreeDictionary_isFull(BinarySearchTreeDictionary* _this) {
	return FALSE;
}

Boolean	BinarySearchTreeDictionary_addKeyAndObject(BinarySearchTreeDictionary* _this, Key* aKey, Object* anObject) {
	if (_this->_root == NULL) {
		Element* elementToAdd = Element_newWith(aKey, anObject);
		_this->_root = BinaryNode_newWith(elementToAdd, NULL, NULL);
		_this->_size = 1;
		return TRUE;
	}
	else {
		return BinarySearchTreeDictionary_addToTree(_this, aKey, anObject, _this->_root);
	}
}

Boolean BinarySearchTreeDictionary_addToTree(BinarySearchTreeDictionary* _this, Key* aKey, Object* anObject, BinaryNode* parent) {
	// At this point, parent is not NULL
	Element* elementToAdd = Element_newWith(aKey, anObject);
	if (Key_compareTo(aKey, Element_key(BinaryNode_Element(parent))) < 0) {
		if (BinaryNode_left(parent) == NULL) {
			BinaryNode_setLeft(parent, BinaryNode_newWith(elementToAdd, NULL, NULL));
			_this->_size++;
			return TRUE;
		}
		else {
			return BinarySearchTreeDictionary_addToTree(_this, aKey, anObject, BinaryNode_left(parent));
		}
	}
	else if (Key_compareTo(aKey, Element_key(BinaryNode_Element(parent))) > 0) {
		if (BinaryNode_right(parent) == NULL) {
			BinaryNode_setRight(parent, BinaryNode_newWith(elementToAdd, NULL, NULL));
			_this->_size++;
			return TRUE;
		}
		else {
			return BinarySearchTreeDictionary_addToTree(_this, aKey, anObject, BinaryNode_right(parent));
		}
	}
	else {	
		return FALSE;
	}
}

Boolean BinarySearchTreeDictionary_keyDoesExist(BinarySearchTreeDictionary* _this, Key* aKey) {
	return (BinarySearchTreeDictionary_searchTreeRecursively(_this, aKey, _this->_root));
}

Boolean BinarySearchTreeDictionary_searchTreeRecursively(BinarySearchTreeDictionary* _this, Key* aKey, BinaryNode* aNode) {
	if (aNode == NULL) {
		return FALSE;
	}
	else {
		// 비교 함수 "Key_compareTo()"는 class Key에 구현되어야 한다.
		if (Key_compareTo(aKey, Element_key(BinaryNode_Element(aNode))) == 0) {
			return TRUE;
		}
		else if (Key_compareTo(aKey, Element_key(BinaryNode_Element(aNode))) < 0) {
			return BinarySearchTreeDictionary_searchTreeRecursively(_this, aKey, BinaryNode_left(aNode));
		}
		else {
			return BinarySearchTreeDictionary_searchTreeRecursively(_this, aKey, BinaryNode_right(aNode));
		}
	}
	return FALSE;
}

Element* BinarySearchTreeDictionary_removeObjectForKey(BinarySearchTreeDictionary* _this, Key* aKey) {
	if (BinarySearchTreeDictionary_isEmpty(_this)) {
		return NULL;
	}
	else {
		if (Key_compareTo(aKey, Element_key(BinaryNode_Element(_this->_root))) != 0) {
			Object* removedObject= BinarySearchTreeDictionary_removeFromTreeRecursively(_this, aKey, _this->_root);
			Element* removedElement = Element_newWith(aKey, removedObject);
			return removedElement;
		}
		else {
			// _root가 삭제할 Object를 가지고 있다.
			BinaryNode* removedNode = _this->_root;
			if (BinaryNode_left(_this->_root) == NULL) {
				_this->_root = BinaryNode_right(_this->_root);
			}
			else if (BinaryNode_right(_this->_root) == NULL) {
				_this->_root = BinaryNode_left(_this->_root);
			}
			else {
				// 삭제할 Object를 갖고 있는 root는 양쪽 자식 노드를 모두 가지고 있다.
				// 왼쪽 트리의 최우측 노드를 찾아서 삭제하여 얻는다.
				// 삭제하여 얻은 최우측 노드가 새로운 루트이다.
				BinaryNode* rightmost =
					BinarySearchTreeDictionary_removeRightmostNodeOfLeftSubtree(_this, _this->_root);
				BinaryNode_setLeft(rightmost, BinaryNode_left(removedNode));
				BinaryNode_setRight(rightmost, BinaryNode_right(removedNode));
				_this->_root = rightmost;
			}
			Object* removedObject = Element_object(BinaryNode_Element(removedNode));
			BinaryNode_delete(removedNode);
			_this->_size--;
			Element* removedElement = Element_newWith(aKey, removedObject);
			return removedElement;
		}
	}
}

Object* BinarySearchTreeDictionary_removeFromTreeRecursively(BinarySearchTreeDictionary* _this, Key* aKey, BinaryNode* parent) {
	// 이 시점에 parent는 NULL이 아니며, parent의 key값은 aKey와 일치하지 않는다.

	if (Key_compareTo(aKey, Element_key(BinaryNode_Element(parent))) < 0) {
		// 삭제할 노드는 왼쪽 트리에서 찾아야 한다.
		BinaryNode* leftChild = BinaryNode_left(parent);
		if (leftChild == NULL) {	// 주어진 aKey를 갖는 원소가 존재하지 않는다.
			return NULL;
		}
		if (Key_compareTo(aKey, Element_key(BinaryNode_Element(leftChild))) == 0) {
			// leftChild가 삭제할 노드이다.

			BinaryNode * removedNode = leftChild;
			if (BinaryNode_left(removedNode) == NULL) {
				BinaryNode_setLeft(parent, BinaryNode_right(removedNode));
			}
			else if (BinaryNode_right(removedNode) == NULL) {
				BinaryNode_setLeft(parent, BinaryNode_left(removedNode));
			}
			else {
				// 삭제해야 하는 leftChild는 양쪽 자식노드를 모두 가지고 있다.
				// leftChild의 왼쪽 부트리에서 최 우측 노드를 찾아서 새로운 leftChild로 한다.

				BinaryNode* rightmost = BinarySearchTreeDictionary_removeRightmostNodeOfLeftSubtree(_this, removedNode);
				BinaryNode_setLeft(rightmost, BinaryNode_left(removedNode));
				BinaryNode_setRight(rightmost, BinaryNode_right(removedNode));
				BinaryNode_setLeft(parent, rightmost);	// rightmost로 삭제되는 leftChild를 대체시킨다.
			}
			Object* removedObject = Element_object(BinaryNode_Element(removedNode));
			BinaryNode_delete(removedNode);
			_this->_size++;
			return removedObject;
		}
		else {
			return BinarySearchTreeDictionary_removeFromTreeRecursively(_this, aKey, leftChild);
		}
	}
	else {
		// 삭제할 노드는 오른쪽 트리에서 찾아야 한다.
		BinaryNode* rightChild = BinaryNode_right(parent);
		if (rightChild == NULL) {	// 주어진 aKey를 갖는 원소가 존재하지 않는다.
			return NULL;
		}
		if (Key_compareTo(aKey, Element_key(BinaryNode_Element(rightChild))) == 0) {
			// rightChild가 삭제할 노드이다.
			BinaryNode * removedNode = rightChild;
			if (BinaryNode_left(removedNode) == NULL) {
				BinaryNode_setRight(parent, BinaryNode_right(removedNode));
			}
			else if (BinaryNode_right(removedNode) == NULL) {
				BinaryNode_setRight(parent, BinaryNode_left(removedNode));
			}
			else {
				// 삭제해야 하는 rightChild는 양쪽 자식노드를 모두 가지고 있다.
				// rightChild의 왼쪽 부트리에서 최 우측 노드를 찾아서 새로운 rightChild로 한다.

				BinaryNode* rightmost = BinarySearchTreeDictionary_removeRightmostNodeOfLeftSubtree(_this, removedNode);
				BinaryNode_setLeft(rightmost, BinaryNode_left(removedNode));
				BinaryNode_setRight(rightmost, BinaryNode_right(removedNode));
				BinaryNode_setRight(parent, rightmost);	// rightmost로 삭제되는 rightChild를 대체시킨다.
			}
			Object* removedObject = Element_object(BinaryNode_Element(removedNode));
			BinaryNode_delete(removedNode);
			_this->_size++;
			return removedObject;
		}
		else {
			return BinarySearchTreeDictionary_removeFromTreeRecursively(_this, aKey, rightChild);
		}
	}
}

BinaryNode* BinarySearchTreeDictionary_removeRightmostNodeOfLeftSubtree(BinarySearchTreeDictionary* _this, BinaryNode* rootOfSubtree) {
	// 여기서 rootOfSubtree는 삭제된 노드 (즉, call 하는 곳의 removedNode)이다.
	// 이 시점에 rootOfSubtree는 양쪽 자식 노드를 모두 가지고 있다.
	// 우리는 rootOfSubtree의 left subtree에서 rightmost를 찾아 삭제하여 얻어야 한다.

	BinaryNode* leftOfRoot = BinaryNode_left(rootOfSubtree);
	BinaryNode* rightmost = leftOfRoot;		// rightmost의 초기화
	if (BinaryNode_right(leftOfRoot) == NULL) {
		// rightmost를 찾으려는 subtree의 right subtree가 존재하지 않는다.
		// 따라서 이 subtree의 root가 rightmost이다.

		BinaryNode_setLeft(rootOfSubtree, BinaryNode_left(leftOfRoot));
	}
	else {
		// rightmost를 찾으려는 subtree의 right subtree가 empty가 아니다.

		BinaryNode* parentOfRightmost = NULL;
		do {
			// rightmost를 찾아서 오른쪽 아래로 내려간다.

			parentOfRightmost = rightmost;
			rightmost = BinaryNode_right(rightmost);
		} while (BinaryNode_right(rightmost) != NULL);
		BinaryNode_setRight(parentOfRightmost, BinaryNode_left(rightmost));
	}
	// 최우측 BinaryNode를 return한다.

	BinaryNode_setLeft(rightmost, NULL);
	// 필요 없는 값인 left를 NULL로 만든다. right는 이미 NULL이다.

	return rightmost;
}