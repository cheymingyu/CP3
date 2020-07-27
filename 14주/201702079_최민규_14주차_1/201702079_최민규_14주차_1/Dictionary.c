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
	// ����� �Լ� : �־��� aKey�� �����ϴ��� ���θ�, Ʈ���� ��������� Ž���Ͽ� �˾Ƴ���.
	// aKey�� �����ϸ� �ش� Object ��ü�� ��´�. �������� ������ NULL�� ��´�.

	if (aNode == NULL) {
		return NULL;
	}
	else {
		// �� �Լ� "Key_compareTo()"�� class Key�� �����Ǿ�� �Ѵ�.
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
		// aKey�� Ʈ���� �̹� �����Ѵ�.
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
			// _root�� ������ Object�� ������ �ִ�.
			BinaryNode* removedNode = _this->_root;
			if (BinaryNode_left(_this->_root) == NULL) {
				_this->_root = BinaryNode_right(_this->_root);
			}
			else if (BinaryNode_right(_this->_root) == NULL) {
				_this->_root = BinaryNode_left(_this->_root);
			}
			else {
				// ������ Object�� ���� �ִ� root�� ���� �ڽ� ��带 ��� ������ �ִ�.
				// ���� Ʈ���� �ֿ��� ��带 ã�Ƽ� �����Ͽ� ��´�.
				// �����Ͽ� ���� �ֿ��� ��尡 ���ο� ��Ʈ�̴�.
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
	// �� ������ parent�� NULL�� �ƴϸ�, parent�� key���� aKey�� ��ġ���� �ʴ´�.

	if (Key_compareTo(aKey, BinaryNode_key(parent)) < 0) {
		// ������ ���� ���� Ʈ������ ã�ƾ� �Ѵ�.
		BinaryNode* leftChild = BinaryNode_left(parent);
		if (leftChild == NULL) {	// �־��� aKey�� ���� ���Ұ� �������� �ʴ´�.
			return NULL;
		}
		if (Key_compareTo(aKey, BinaryNode_key(leftChild)) == 0) {
			// leftChild�� ������ ����̴�.

			BinaryNode * removedNode = leftChild;
			if (BinaryNode_left(removedNode) == NULL) {
				BinaryNode_setLeft(parent, BinaryNode_right(removedNode));
			}
			else if (BinaryNode_right(removedNode) == NULL) {
				BinaryNode_setLeft(parent, BinaryNode_left(removedNode));
			}
			else {
				// �����ؾ� �ϴ� leftChild�� ���� �ڽĳ�带 ��� ������ �ִ�.
				// leftChild�� ���� ��Ʈ������ �� ���� ��带 ã�Ƽ� ���ο� leftChild�� �Ѵ�.

				BinaryNode* rightmost = Dictionary_removeRightmostNodeOfLeftSubtree(_this, removedNode);
				BinaryNode_setLeft(rightmost, BinaryNode_left(removedNode));
				BinaryNode_setRight(rightmost, BinaryNode_right(removedNode));
				BinaryNode_setLeft(parent, rightmost);	// rightmost�� �����Ǵ� leftChild�� ��ü��Ų��.
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
		// ������ ���� ������ Ʈ������ ã�ƾ� �Ѵ�.
		BinaryNode* rightChild = BinaryNode_right(parent);
		if (rightChild == NULL) {	// �־��� aKey�� ���� ���Ұ� �������� �ʴ´�.
			return NULL;
		}
		if (Key_compareTo(aKey, BinaryNode_key(rightChild)) == 0) {
			// rightChild�� ������ ����̴�.
			BinaryNode * removedNode = rightChild;
			if (BinaryNode_left(removedNode) == NULL) {
				BinaryNode_setRight(parent, BinaryNode_right(removedNode));
			}
			else if (BinaryNode_right(removedNode) == NULL) {
				BinaryNode_setRight(parent, BinaryNode_left(removedNode));
			}
			else {
				// �����ؾ� �ϴ� rightChild�� ���� �ڽĳ�带 ��� ������ �ִ�.
				// rightChild�� ���� ��Ʈ������ �� ���� ��带 ã�Ƽ� ���ο� rightChild�� �Ѵ�.

				BinaryNode* rightmost = Dictionary_removeRightmostNodeOfLeftSubtree(_this, removedNode);
				BinaryNode_setLeft(rightmost, BinaryNode_left(removedNode));
				BinaryNode_setRight(rightmost, BinaryNode_right(removedNode));
				BinaryNode_setRight(parent, rightmost);	// rightmost�� �����Ǵ� rightChild�� ��ü��Ų��.
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
	// ���⼭ rootOfSubtree�� ������ ��� (��, call �ϴ� ���� removedNode)�̴�.
	// �� ������ rootOfSubtree�� ���� �ڽ� ��带 ��� ������ �ִ�.
	// �츮�� rootOfSubtree�� left subtree���� rightmost�� ã�� �����Ͽ� ���� �Ѵ�.

	BinaryNode* leftOfRoot = BinaryNode_left(rootOfSubtree);
	BinaryNode* rightmost = leftOfRoot;		// rightmost�� �ʱ�ȭ
	if (BinaryNode_right(leftOfRoot) == NULL) {
		// rightmost�� ã������ subtree�� right subtree�� �������� �ʴ´�.
		// ���� �� subtree�� root�� rightmost�̴�.

		BinaryNode_setLeft(rootOfSubtree, BinaryNode_left(leftOfRoot));
	}
	else {
		// rightmost�� ã������ subtree�� right subtree�� empty�� �ƴϴ�.

		BinaryNode* parentOfRightmost = NULL;
		do {
			// rightmost�� ã�Ƽ� ������ �Ʒ��� ��������.

			parentOfRightmost = rightmost;
			rightmost = BinaryNode_right(rightmost);
		} while (BinaryNode_right(rightmost) != NULL);
		BinaryNode_setRight(parentOfRightmost, BinaryNode_left(rightmost));
	}
	// �ֿ��� BinaryNode�� return�Ѵ�.

	BinaryNode_setLeft(rightmost, NULL);
		// �ʿ� ���� ���� left�� NULL�� �����. right�� �̹� NULL�̴�.

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
