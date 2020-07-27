#include "Dictionary.h"
#include "BinaryNode.h"

struct _Dictionary
{
	BinaryNode* _root;
	int			_size;
};

void Dictionary_deleteBinaryNodes(Dictionary* _this, BinaryNode* _aNode);
Object* Dictionary_searchTreeRecursively(Dictionary* _this, Key* _aKey, BinaryNode* aNode);
Boolean Dictionary_addToTree(Dictionary* _this, Key* aKey, Object* anObject, BinaryNode* parent);
Object* Dictionary_removeFromTreeRecursively(Dictionary* _this, Key* aKey, BinaryNode* parent);
BinaryNode* Dictionary_removeRightmostNodeOfLeftSubtree(Dictionary* _this, BinaryNode* rootOfSubtree);
void Dictionary_inorderRecursively(Dictionary* _this, Traverse* aTraverse, BinaryNode* aRoot, int depth);

Dictionary* Dictionary_new(void) {
	Dictionary* _this = NewObject(Dictionary);
	_this->_root = NULL;
	_this->_size = 0;
	return _this;
}

void Dictionary_delete(Dictionary* _this) {
	Dictionary_deleteBinaryNodes(_this, _this->_root);	// recursively
	free(_this);
}

void Dictionary_deleteBinaryNodes(Dictionary* _this, BinaryNode* aNode) {
	if (aNode != NULL) {
		Dictionary_deleteBinaryNodes(_this, BinaryNode_left(aNode));
		Dictionary_deleteBinaryNodes(_this, BinaryNode_right(aNode));
		BinaryNode_delete(aNode);
	}
}

Boolean Dictionary_isEmpty(Dictionary* _this) {
	return (_this->_root == NULL);
}

Boolean Dictionary_isFull(Dictionary* _this) {
	return FALSE;
}

int		Dictionary_size(Dictionary* _this) {
	return _this->_size;
}

Boolean Dictionary_keyDoesExist(Dictionary* _this, Key* aKey) {
	return (Dictionary_searchTreeRecursively(_this, aKey, _this->_root) != NULL);
}

Object* Dictionary_objectForKey(Dictionary* _this, Key* aKey) {
	return (Dictionary_searchTreeRecursively(_this, aKey, _this->_root));
}

Object* Dictionary_searchTreeRecursively(Dictionary* _this, Key* aKey, BinaryNode* aNode) {
	// 비공개 함수 : 주어진 aKey가 존재하는지 여부를, 트리를 재귀적으로 탐색하여 알아낸다.
	// aKey가 존재하면 해당 Object 객체를 얻는다. 존재하지 않으면 NULL을 얻는다.

	if (aNode == NULL) {
		return NULL;
	}
	else {
		// 비교 함수 "Key_compareTo()"는 class Key에 구현되어야 한다.
		if (Key_compareTo(aKey, BinaryNode_key(aNode)) == 0) {
			return BinaryNode_object(aNode);
		}
		else if (Key_compareTo(aKey, BinaryNode_key(aNode)) < 0) {
			return Dictionary_searchTreeRecursively(_this, aKey, BinaryNode_left(aNode));
		}
		else {
			return Dictionary_searchTreeRecursively(_this, aKey, BinaryNode_right(aNode));
		}
	}
}

Boolean Dictionary_addKeyAndObject(Dictionary* _this, Key* aKey, Object* anObject) {
	if (_this->_root == NULL) {
		_this->_root = BinaryNode_newWith(aKey, anObject, NULL, NULL);
		_this->_size = 1;
		return TRUE;
	}
	else {
		return Dictionary_addToTree(_this, aKey, anObject, _this->_root);
	}
}

Boolean Dictionary_addToTree(Dictionary* _this, Key* aKey, Object* anObject, BinaryNode* parent) {
	// At this point, parent is not NULL
	if (Key_compareTo(aKey, BinaryNode_key(parent)) < 0) {
		if (BinaryNode_left(parent) == NULL) {
			BinaryNode_setLeft(parent, BinaryNode_newWith(aKey, anObject, NULL, NULL));
			_this->_size++;
			return TRUE;
		}
		else {
			return Dictionary_addToTree(_this, aKey, anObject, BinaryNode_left(parent));
		}
	}
	else if (Key_compareTo(aKey, BinaryNode_key(parent)) > 0) {
		if (BinaryNode_right(parent) == NULL) {
			BinaryNode_setRight(parent, BinaryNode_newWith(aKey, anObject, NULL, NULL));
			_this->_size++;
			return TRUE;
		}
		else {
			return Dictionary_addToTree(_this, aKey, anObject, BinaryNode_right(parent));
		}
	}
	else {	// (Key_compareTo(aKey, BinaryNode_key(parent)) == 0)
		// aKey가 트리에 이미 존재한다.
		return FALSE;
	}
}

Object* Dictionary_removeObjectForKey(Dictionary* _this, Key* aKey) {
	if (Dictionary_isEmpty(_this)) {
		return NULL;
	}
	else {
		if (Key_compareTo(aKey, BinaryNode_key(_this->_root)) != 0) {
			return Dictionary_removeFromTreeRecursively(_this, aKey, _this->_root);
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
					Dictionary_removeRightmostNodeOfLeftSubtree(_this, _this->_root);
				BinaryNode_setLeft(rightmost, BinaryNode_left(removedNode));
				BinaryNode_setRight(rightmost, BinaryNode_right(removedNode));
				_this->_root = rightmost;
			}
			Object* removedObject = BinaryNode_object(removedNode);
			BinaryNode_delete(removedNode);
			_this->_size--;
			return removedObject;
		}
	}
}

Object* Dictionary_removeFromTreeRecursively(Dictionary* _this, Key* aKey, BinaryNode* parent) {
	// 이 시점에 parent는 NULL이 아니며, parent의 key값은 aKey와 일치하지 않는다.

	if (Key_compareTo(aKey, BinaryNode_key(parent)) < 0) {
		// 삭제할 노드는 왼쪽 트리에서 찾아야 한다.
		BinaryNode* leftChild = BinaryNode_left(parent);
		if (leftChild == NULL) {	// 주어진 aKey를 갖는 원소가 존재하지 않는다.
			return NULL;
		}
		if (Key_compareTo(aKey, BinaryNode_key(leftChild)) == 0) {
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

				BinaryNode* rightmost = Dictionary_removeRightmostNodeOfLeftSubtree(_this, removedNode);
				BinaryNode_setLeft(rightmost, BinaryNode_left(removedNode));
				BinaryNode_setRight(rightmost, BinaryNode_right(removedNode));
				BinaryNode_setLeft(parent, rightmost);	// rightmost로 삭제되는 leftChild를 대체시킨다.
			}
			Object* removedObject = BinaryNode_object(removedNode);
			BinaryNode_delete(removedNode);
			_this->_size++;
			return removedObject;
		}
		else {
			return Dictionary_removeFromTreeRecursively(_this, aKey, leftChild);
		}
	}
	else {
		// 삭제할 노드는 오른쪽 트리에서 찾아야 한다.
		BinaryNode* rightChild = BinaryNode_right(parent);
		if (rightChild == NULL) {	// 주어진 aKey를 갖는 원소가 존재하지 않는다.
			return NULL;
		}
		if (Key_compareTo(aKey, BinaryNode_key(rightChild)) == 0) {
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

				BinaryNode* rightmost = Dictionary_removeRightmostNodeOfLeftSubtree(_this, removedNode);
				BinaryNode_setLeft(rightmost, BinaryNode_left(removedNode));
				BinaryNode_setRight(rightmost, BinaryNode_right(removedNode));
				BinaryNode_setRight(parent, rightmost);	// rightmost로 삭제되는 rightChild를 대체시킨다.
			}
			Object* removedObject = BinaryNode_object(removedNode);
			BinaryNode_delete(removedNode);
			_this->_size++;
			return removedObject;
		}
		else {
			return Dictionary_removeFromTreeRecursively(_this, aKey, rightChild);
		}
	}
}

BinaryNode* Dictionary_removeRightmostNodeOfLeftSubtree(Dictionary* _this, BinaryNode* rootOfSubtree) {
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

Boolean Dictionary_repalceObjectForKey(Dictionary* _this, Key* aKey, Object* anObject) {
	if (Dictionary_keyDoesExist(_this, aKey)) {
		return FALSE;
	}

	if (Dictionary_isEmpty(_this)) {
		return FALSE;
	}

	if (Key_compareTo(aKey, BinaryNode_key(_this->_root)) == 0) {
		BinaryNode_setObject(_this->_root, anObject);
		return TRUE;
	}
	else {
		BinaryNode* nodeToReplace = _this->_root;
		do {
			if (Key_compareTo(aKey, BinaryNode_key(nodeToReplace)) > 0) {
				nodeToReplace = BinaryNode_right(nodeToReplace);
			}
			else if (Key_compareTo(aKey, BinaryNode_key(nodeToReplace)) < 0) {
				nodeToReplace = BinaryNode_left(nodeToReplace);
			}
		} while (Key_compareTo(aKey, BinaryNode_key(nodeToReplace)) == 0);
		BinaryNode_setObject(nodeToReplace, anObject);
		return TRUE;
	}
}

void	Dictionary_scanInSortedOrder(Dictionary* _this, Traverse* aTraverse) {
	Dictionary_inorderRecursively(_this, aTraverse, _this->_root, 1);
}

void Dictionary_inorderRecursively(Dictionary* _this, Traverse* aTraverse, BinaryNode* aRoot, int depth) {
	if (aRoot != NULL) {
		Dictionary_inorderRecursively(_this, aTraverse, BinaryNode_left(aRoot), depth + 1);
		Traverse_visit(aTraverse, BinaryNode_key(aRoot), BinaryNode_object(aRoot), depth);
		Dictionary_inorderRecursively(_this, aTraverse, BinaryNode_right(aRoot), depth + 1);
	}
}
