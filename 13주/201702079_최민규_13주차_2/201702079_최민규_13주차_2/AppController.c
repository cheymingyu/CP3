#include "AppController.h"
#include "AppView.h"
#include "Queue.h"
#include "Common.h"
#define Esc 27

struct _AppController
{
	Queue*	_queue;
	int		_inputChars;	// 입력된 문자의 개수
	int		_ignoredChars;	// 무시된 문자의 개수
	int		_addedChars;	// 삽입된 문자의 개수
};

void AppController_add(AppController* _this, char aChar);
void AppController_removeN(AppController* _this, char aDigit);
void AppController_remove1(AppController* _this);
void AppController_showSize(AppController* _this);
void AppController_showAllFromFront(AppController* _this);
void AppController_showFront(AppController* _this);
void AppController_ignore(AppController* _this);
void AppController_esc(AppController* _this);

void AppController_initCharCounts(AppController* _this);
void AppController_countInput(AppController* _this);
void AppController_countIgnored(AppController* _this);
void AppController_countAdded(AppController* _this);

int AppController_numberOfInputChars(AppController* _this);
int AppController_numberOfIgnoredChars(AppController* _this);
int AppController_numberOfNormallyProcessedChars(AppController* _this);
int AppController_numberOfAddedChars(AppController* _this);

void AppController_showStatistics(AppController* _this);

AppController*	AppController_new() {
	AppController* _this;
	_this = NewObject(AppController);
	_this->_queue = Queue_new(DEFAULT_MAX_LENGTH);
	_this->_inputChars = 0;
	_this->_ignoredChars = 0;
	_this->_addedChars = 0;

	return _this;
}

void AppController_delete(AppController* _this) {
	Queue_delete(_this->_queue);
	free(_this);
}

void AppController_run(AppController* _this) {
	AppView_out_startProgram();
	AppController_initCharCounts(_this);

	char inputChar = AppView_in_nextInputChar();
	if (inputChar != Esc) {
		AppController_countInput(_this);
	}
	while (inputChar != Esc) {
		if (isAlpha(inputChar)) {
			AppController_add(_this, inputChar);
		}
		else if (isDigit(inputChar)) {
			AppController_removeN(_this, inputChar);
		}
		else if (inputChar == '-') {
			AppController_remove1(_this);
		}
		else if (inputChar == '#') {
			AppController_showSize(_this);
		}
		else if (inputChar == '/') {
			AppController_showAllFromFront(_this);
		}
		else if (inputChar == '^') {
			AppController_showFront(_this);
		}
		else {
			AppController_ignore(_this);
		}
		inputChar = AppView_in_nextInputChar();
		if (inputChar != Esc) {
			AppController_countInput(_this);
		}
	}
	AppController_esc(_this);
	AppController_showStatistics(_this);
	AppView_out_endProgram();
}

void AppController_add(AppController* _this, char aChar) {
	if (Queue_isFull(_this->_queue)) {
		AppView_out_queueIsFull(aChar);
	}
	else {
		Queue_add(_this->_queue, aChar);
		AppController_countAdded(_this);
		AppView_out_addedElementInQueue(aChar);
	}
}

void AppController_removeN(AppController* _this, char aDigit) {
	int numberOfCharsRemoved = aDigit - '0';

	for (int i = 0; i < numberOfCharsRemoved; i++) {
		if (Queue_isEmpty(_this->_queue)) {
			AppView_out_queueIsEmptyAgainstRemove();
			return;
		}
		char removedChar = Queue_remove(_this->_queue);
		AppView_out_removedElementFromQueueByRemoveN(removedChar);
	}
}

void AppController_remove1(AppController* _this) {
	char removedChar;
	if (Queue_isEmpty(_this->_queue)) {
		AppView_out_noElementInQueue();
	}
	else {
		removedChar = Queue_remove(_this->_queue);
		AppView_out_removedElementFromQueue(removedChar);
	}
}

void AppController_showSize(AppController* _this) {
	AppView_out_queueSize(Queue_size(_this->_queue));
}

void AppController_showAllFromFront(AppController* _this) {
	AppView_out_labelFront();
	for (int i = 0; i < Queue_size(_this->_queue); i++) {
		AppView_out_elementInQueue(Queue_elementAt(_this->_queue, i));
	}
	AppView_out_labelRear();
}

void AppController_showFront(AppController* _this) {
	AppView_out_frontElement(Queue_elementAt(_this->_queue, 0));
}

void AppController_ignore(AppController* _this) {
	AppView_out_ignoredChar();
	AppController_countIgnored(_this);
}

void AppController_esc(AppController* _this) {
	while (Queue_size(_this->_queue) > 0) {
		char poppedChar = Queue_remove(_this->_queue);
		AppView_out_removedElementByEndInput(poppedChar);
	}
}

void AppController_initCharCounts(AppController* _this) {
	_this->_inputChars = 0;
	_this->_ignoredChars = 0;
	_this->_addedChars = 0;
}

void AppController_countInput(AppController* _this) {
	_this->_inputChars++;
}

void AppController_countIgnored(AppController* _this) {
	_this->_ignoredChars++;
}

void AppController_countAdded(AppController* _this) {
	_this->_addedChars++;
}

int AppController_numberOfInputChars(AppController* _this) {
	return (_this->_inputChars);
}

int AppController_numberOfIgnoredChars(AppController* _this) {
	return (_this->_ignoredChars);
}

int AppController_numberOfNormallyProcessedChars(AppController* _this) {
	return (_this->_inputChars - _this->_ignoredChars);
}

int AppController_numberOfAddedChars(AppController* _this) {
	return (_this->_addedChars);
}

void AppController_showStatistics(AppController* _this) {
	AppView_out_newLine();

	AppView_out_numberOFInputChars(AppController_numberOfInputChars(_this));
	AppView_out_numberOfNormallyProcessedChars(AppController_numberOfNormallyProcessedChars(_this));
	AppView_out_numberOfIgnoredChars(AppController_numberOfIgnoredChars(_this));
	AppView_out_numberOfAddedChars(AppController_numberOfAddedChars(_this));
}