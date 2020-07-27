#include "AppController.h"
#include "Dictionary.h"
#include "AppView.h"
#define Esc 27

struct _AppController
{
	Dictionary* _dictionary;
	Traverse*	_traverse;
};

void AppController_replace(AppController* _this, Key* aKey, Object* anObject);
void AppController_add(AppController* _this, Key* aKey, Object* anObject);
void AppController_remove(AppController* _this);
void AppController_showSize(AppController* _this);
void AppController_doesExist(AppController* _this);
void AppController_ignore(AppController* _this);

AppController*	AppController_new() {
	AppController* _this = NewObject(AppController);
	_this->_dictionary = Dictionary_new();
	_this->_traverse = Traverse_new();
	return _this;
}

void AppController_delete(AppController* _this) {
	Dictionary_delete(_this->_dictionary);
	Traverse_delete(_this->_traverse);
	free(_this);
}

void AppController_run(AppController* _this) {
	AppView_out_startProgram();

	char	inputChar = AppView_in_nextInputChar();
	while (inputChar != Esc) {

		if (isAlpha(inputChar)) {
			char	keyValue = inputChar;
			int		objectValue = (int)keyValue;
			Key*	newKey = Key_newWith(keyValue);
			Object* newObject = Object_newWith(objectValue);
			if (Dictionary_keyDoesExist(_this->_dictionary, newKey)) {
				AppController_replace(_this, newKey, newObject);
			}
			else {
				AppController_add(_this, newKey, newObject);
			}
		}
		else if (inputChar == '-') {
			AppController_remove(_this);
		}
		else if (inputChar == '#') {
			AppController_showSize(_this);
		}
		else if (inputChar == '/') {
			AppController_showInternalShapeOfBinaryTree(_this, _this->_traverse);
		}
		else if (inputChar == '?') {
			AppController_doesExist(_this);
		}
		else {
			AppController_ignore(_this);
		}
		inputChar = AppView_in_nextInputChar();
	}
	AppView_out_endProgram();
}

void AppController_add(AppController* _this, Key* aKey, Object* anObject) {
	if (Dictionary_isFull(_this->_dictionary)) {

	}
	else {
		Dictionary_addKeyAndObject(_this->_dictionary, aKey, anObject);
		char	aChar = Key_value(aKey);
		int		aNum = Object_value(anObject);
		AppView_out_addedKeyAndObjectInDictionary(aChar, aNum);
	}
}

void AppController_replace(AppController* _this, Key* aKey, Object* anObject) {
	Dictionary_addKeyAndObject(_this->_dictionary, aKey, anObject);
	char	aChar = Key_value(aKey);
	int		aNum = Object_value(anObject);
	AppView_out_replaceObject(aChar, aNum);
}


void AppController_remove(AppController* _this) {
	if (Dictionary_isEmpty(_this->_dictionary)) {
		AppView_out_noElementInDictionary();
	}
	else {
		char removeKeyValue = AppView_in_removeKeyAndObject();
		Key* removeKey = Key_newWith(removeKeyValue);
		if (Dictionary_keyDoesExist(_this->_dictionary, removeKey)) {
			Object* anObject = Dictionary_removeObjectForKey(_this->_dictionary, removeKey);
			char	aChar = Key_value(removeKey);
			int		aNum = Object_value(anObject);
			AppView_out_remove(aChar, aNum);
		}
		else {
			AppView_out_keyDoesNotExistInDictionary();
		}
	}
}

void AppController_showSize(AppController* _this) {
	AppView_out_dictionarySize(Dictionary_size(_this->_dictionary));
}

void AppController_showInternalShapeOfBinaryTree(AppController* _this, Traverse* aTraverse) {
	AppView_out_showBinaryTree();
	Dictionary_scanInSortedOrder(_this->_dictionary, aTraverse);
}

void AppController_doesExist(AppController* _this) {
	char searchKeyValue = AppView_in_searchKeyAndObject();
	Key* newKey = Key_newWith(searchKeyValue);
	if (Dictionary_keyDoesExist(_this->_dictionary, newKey)) {
		int aNum = Object_value(Dictionary_objectForKey(_this->_dictionary, newKey));
		AppView_out_keyExistInDictionary(searchKeyValue, aNum);
	}
	else {
		AppView_out_keyDoesNotExistInDictionary();
	}
}

void AppController_ignore(AppController* _this) {
	AppView_out_ignoredChar();
}
