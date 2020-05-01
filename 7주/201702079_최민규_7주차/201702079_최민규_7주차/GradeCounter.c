#include "GradeCounter.h"

struct _GradeCounter {
	int		_numberOfA;
	int		_numberOfB;
	int		_numberOfC;
	int		_numberOfD;
	int		_numberOfF;
};

GradeCounter* GradeCounter_new(void) {
	GradeCounter* _this = NewObject(GradeCounter);

	_this->_numberOfA = 0;
	_this->_numberOfB = 0;
	_this->_numberOfC = 0;
	_this->_numberOfD = 0;
	_this->_numberOfF = 0;

	return _this;
}

void GradeCounter_delete(GradeCounter* _this) {
	free(_this);
}

void GradeCounter_count(GradeCounter* _this, char aGrade) {
	switch (aGrade) {
	case 'A':
		_this->_numberOfA++;
		break;
	case 'B':
		_this->_numberOfB++;
		break;
	case 'C':
		_this->_numberOfC++;
		break;
	case 'D':
		_this->_numberOfD++;
		break;
	default:
		_this->_numberOfF++;
		break;
	}
}

int GradeCounter_numberOfA(GradeCounter* _this) {
	return _this->_numberOfA;
}

int GradeCounter_numberOfB(GradeCounter* _this) {
	return _this->_numberOfB;
}

int GradeCounter_numberOfC(GradeCounter* _this) {
	return _this->_numberOfC;
}

int GradeCounter_numberOfD(GradeCounter* _this) {
	return _this->_numberOfD;
}

int GradeCounter_numberOfF(GradeCounter* _this) {
	return _this->_numberOfF;
}
