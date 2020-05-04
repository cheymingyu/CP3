#include "ParameterSet.h"
#include "Common.h"

struct _ParameterSet {
	int _minTestSize;
	int _intervalSize;
	int _numberOfTests;
};

ParameterSet* ParameterSet_new(void) {		// ������
	ParameterSet* _this = NewObject(ParameterSet);
	_this->_minTestSize = 0;
	_this->_intervalSize = 0;
	_this->_numberOfTests = 0;
	return _this;

}
ParameterSet* ParameterSet_newWith(			// �ʱ�ȭ ���� �־����� ������
	int givenMinTestSize, int givenIntervalSize, int givenNumberOfTests) {
	ParameterSet* _this = NewObject(ParameterSet);
	_this->_minTestSize = givenMinTestSize;
	_this->_intervalSize = givenIntervalSize;
	_this->_numberOfTests = givenNumberOfTests;
	return _this;
}

void ParameterSet_delete(ParameterSet* _this) {		// �Ҹ���
	free(_this);
}

// Getters & Setters
void	ParameterSet_setMinTestSize(ParameterSet* _this, int newMinTestSize) {
	_this->_minTestSize = newMinTestSize;
}

int		ParameterSet_minTestSize(ParameterSet* _this) {
	return _this->_minTestSize;
}

void	ParameterSet_setIntervalSize(ParameterSet* _this, int newIntervalSize) {
	_this->_intervalSize = newIntervalSize;
}

int		ParameterSet_intervalSize(ParameterSet* _this) {
	return _this->_intervalSize;
}

void	ParameterSet_setNumberOfTests(ParameterSet* _this, int newNumberOfTests) {
	_this->_numberOfTests = newNumberOfTests;
}

int		ParameterSet_numberOfTests(ParameterSet* _this) {
	return _this->_numberOfTests;
}

int		ParameterSet_maxTestSize(ParameterSet* _this) {
	return (_this->_minTestSize + (_this->_intervalSize * (_this->_numberOfTests - 1)));
}