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
		// �� �Լ� "Key_compareTo()"�� class Key�� �����Ǿ�� �Ѵ�.
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
	// �� ������ parent�� NULL�� �ƴϸ�, parent�� key���� aKey�� ��ġ���� �ʴ´�.

	if (Key_compareTo(aKey, Element_key(BinaryNode_Element(parent))) < 0) {
		// ������ ���� ���� Ʈ������ ã�ƾ� �Ѵ�.
		BinaryNode* leftChild = BinaryNode_left(parent);
		if (leftChild == NULL) {	// �־��� aKey�� ���� ���Ұ� �������� �ʴ´�.
			return NULL;
		}
		if (Key_compareTo(aKey, Element_key(BinaryNode_Element(leftChild))) == 0) {
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

				BinaryNode* rightmost = BinarySearchTreeDictionary_removeRightmostNodeOfLeftSubtree(_this, removedNode);
				BinaryNode_setLeft(rightmost, BinaryNode_left(removedNode));
				BinaryNode_setRight(rightmost, BinaryNode_right(removedNode));
				BinaryNode_setLeft(parent, rightmost);	// rightmost�� �����Ǵ� leftChild�� ��ü��Ų��.
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
		// ������ ���� ������ Ʈ������ ã�ƾ� �Ѵ�.
		BinaryNode* rightChild = BinaryNode_right(parent);
		if (rightChild == NULL) {	// �־��� aKey�� ���� ���Ұ� �������� �ʴ´�.
			return NULL;
		}
		if (Key_compareTo(aKey, Element_key(BinaryNode_Element(rightChild))) == 0) {
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

				BinaryNode* rightmost = BinarySearchTreeDictionary_removeRightmostNodeOfLeftSubtree(_this, removedNode);
				BinaryNode_setLeft(rightmost, BinaryNode_left(removedNode));
				BinaryNode_setRight(rightmost, BinaryNode_right(removedNode));
				BinaryNode_setRight(parent, rightmost);	// rightmost�� �����Ǵ� rightChild�� ��ü��Ų��.
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