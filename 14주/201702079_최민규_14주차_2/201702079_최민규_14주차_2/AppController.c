#include "AppController.h"
#include "Common.h"
#include "BinarySearchTreeDictionary.h"
#include "UnSortedArrayDictionary.h"
#include "SortedArrayDictionary.h"
#include "UnSortedLinkedDictionary.h"
#include "SortedLinkedDictionary.h"
#include "Element.h"
#include "ParameterSet.h"
#include "Messages.h"
#include "Timer.h"
#include "AppView.h"
#include <time.h>

#define MIN_TEST_SIZE		1000
#define	NUMBER_OF_TESTS		5
#define INTERVAL_SIZE		1000

struct _AppController
{
	ParameterSet* _parameterSet;
	int* _testData;
};

void AppController_initPerformanceMeasurement(AppController* _this);
void AppController_gernerateTestDataByRandomNumbers(AppController* _this);

double AppController_timeForUnSortedArrayDictionary_add(AppController*_this, UnSortedArrayDictionary* aDictionary, int aTestSize);
double AppController_timeForUnSortedArrayDictionary_search(AppController*_this, UnSortedArrayDictionary* aDictionary, int aTestSize);
double AppController_timeForUnSortedArrayDictionary_remove(AppController*_this, UnSortedArrayDictionary* aDictionary, int aTestSize);

double AppController_timeForSortedArrayDictionary_add(AppController*_this, SortedArrayDictionary* aDictionary, int aTestSize);
double AppController_timeForSortedArrayDictionary_search(AppController*_this, SortedArrayDictionary* aDictionary, int aTestSize);
double AppController_timeForSortedArrayDictionary_remove(AppController*_this, SortedArrayDictionary* aDictionary, int aTestSize);


double AppController_timeForUnSortedLinkedDictionary_add(AppController*_this, UnSortedLinkedDictionary* aDictionary, int aTestSize);
double AppController_timeForUnSortedLinkedDictionary_search(AppController*_this, UnSortedLinkedDictionary* aDictionary, int aTestSize);
double AppController_timeForUnSortedLinkedDictionary_remove(AppController*_this, UnSortedLinkedDictionary* aDictionary, int aTestSize);

double AppController_timeForSortedLinkedDictionary_add(AppController*_this, SortedLinkedDictionary* aDictionary, int aTestSize);
double AppController_timeForSortedLinkedDictionary_search(AppController*_this, SortedLinkedDictionary* aDictionary, int aTestSize);
double AppController_timeForSortedLinkedDictionary_remove(AppController*_this, SortedLinkedDictionary* aDictionary, int aTestSize);

double AppController_timeForBinarySearchTreeDictionary_add(AppController*_this, BinarySearchTreeDictionary* aDictionary, int aTestSize);
double AppController_timeForBinarySearchTreeDictionary_search(AppController*_this, BinarySearchTreeDictionary* aDictionary, int aTestSize);
double AppController_timeForBinarySearchTreeDictionary_remove(AppController*_this, BinarySearchTreeDictionary* aDictionary, int aTestSize);

void AppController_showResults(AppController* _this, int aTestSize, double aTimeForAdd, double aTimeForSearch, double aTimeForRemove);


AppController* AppController_new(void) {
	AppController* _this = NewObject(AppController);
	_this->_parameterSet = ParameterSet_new();
	return _this;
}

void AppController_delete(AppController* _this) {
	free(_this);
}

void AppController_initPerformanceMeasurement(AppController* _this) {
	ParameterSet_setMinTestSize(_this->_parameterSet, MIN_TEST_SIZE);
	ParameterSet_setIntervalSize(_this->_parameterSet, INTERVAL_SIZE);
	ParameterSet_setNumberOfTests(_this->_parameterSet, NUMBER_OF_TESTS);

	_this->_testData = NewVector(int, ParameterSet_maxTestSize(_this->_parameterSet));
	AppController_gernerateTestDataByRandomNumbers(_this);
}

void AppController_run(AppController* _this) {
	AppView_out(MSG_StartPerformanceMeasuring);
	AppController_initPerformanceMeasurement(_this);

	int numberOfTests = ParameterSet_numberOfTests(_this->_parameterSet);
	int intervalSize = ParameterSet_intervalSize(_this->_parameterSet);
	int maxTestSize = ParameterSet_maxTestSize(_this->_parameterSet);

	AppView_out(MSG_TitleForUnSortedArrayDictionary);

	int testSize = ParameterSet_minTestSize(_this->_parameterSet);
	for (int i = 0; i < numberOfTests; i++) {
		UnSortedArrayDictionary* dictionaryForTest = UnSortedArrayDictionary_new(maxTestSize);
		double timeForAdd = AppController_timeForUnSortedArrayDictionary_add(_this, dictionaryForTest, testSize);
		double timeForSearch = AppController_timeForUnSortedArrayDictionary_search(_this, dictionaryForTest, testSize);
		double timeForRemove = AppController_timeForUnSortedArrayDictionary_remove(_this, dictionaryForTest, testSize);
		AppController_showResults(_this, testSize, timeForAdd, timeForSearch, timeForRemove);
		UnSortedArrayDictionary_delete(dictionaryForTest);
		testSize += intervalSize;
	}
	AppView_out("\n");
	AppView_out(MSG_TitleForSortedArrayDictionary);
	
	testSize = ParameterSet_minTestSize(_this->_parameterSet);
	for (int i = 0; i < numberOfTests; i++) {
		SortedArrayDictionary* dictionaryForTest = SortedArrayDictionary_new(maxTestSize);
		double timeForAdd = AppController_timeForSortedArrayDictionary_add(_this, dictionaryForTest, testSize);
		double timeForSearch = AppController_timeForSortedArrayDictionary_search(_this, dictionaryForTest, testSize);
		double timeForRemove = AppController_timeForSortedArrayDictionary_remove(_this, dictionaryForTest, testSize);
		AppController_showResults(_this, testSize, timeForAdd, timeForSearch, timeForRemove);
		SortedArrayDictionary_delete(dictionaryForTest);
		testSize += intervalSize;
	}

	AppView_out("\n");
	AppView_out(MSG_TitleForUnSortedLinkedDictionary);

	testSize = ParameterSet_minTestSize(_this->_parameterSet);
	for (int i = 0; i < numberOfTests; i++) {
		UnSortedLinkedDictionary* dictionaryForTest = UnSortedLinkedDictionary_new();
		double timeForAdd = AppController_timeForUnSortedLinkedDictionary_add(_this, dictionaryForTest, testSize);
		double timeForSearch = AppController_timeForUnSortedLinkedDictionary_search(_this, dictionaryForTest, testSize);
		double timeForRemove = AppController_timeForUnSortedLinkedDictionary_remove(_this, dictionaryForTest, testSize);
		AppController_showResults(_this, testSize, timeForAdd, timeForSearch, timeForRemove);
		UnSortedLinkedDictionary_delete(dictionaryForTest);
		testSize += intervalSize;
	}

	AppView_out("\n");
	AppView_out(MSG_TitleForSortedLinkedDictionary);

	testSize = ParameterSet_minTestSize(_this->_parameterSet);
	for (int i = 0; i < numberOfTests; i++) {
		SortedLinkedDictionary* dictionaryForTest = SortedLinkedDictionary_new();
		double timeForAdd = AppController_timeForSortedLinkedDictionary_add(_this, dictionaryForTest, testSize);
		double timeForSearch = AppController_timeForSortedLinkedDictionary_search(_this, dictionaryForTest, testSize);
		double timeForRemove = AppController_timeForSortedLinkedDictionary_remove(_this, dictionaryForTest, testSize);
		AppController_showResults(_this, testSize, timeForAdd, timeForSearch, timeForRemove);
		SortedLinkedDictionary_delete(dictionaryForTest);
		testSize += intervalSize;
	}

	AppView_out("\n");
	AppView_out(MSG_TitleForBinarySearchTreeDictionary);

	testSize = ParameterSet_minTestSize(_this->_parameterSet);
	for (int i = 0; i < numberOfTests; i++) {
		BinarySearchTreeDictionary* dictionaryForTest = BinarySearchTreeDictionary_new(maxTestSize);
		double timeForAdd = AppController_timeForBinarySearchTreeDictionary_add(_this, dictionaryForTest, testSize);
		double timeForSearch = AppController_timeForBinarySearchTreeDictionary_search(_this, dictionaryForTest, testSize);
		double timeForRemove = AppController_timeForBinarySearchTreeDictionary_remove(_this, dictionaryForTest, testSize);
		AppController_showResults(_this, testSize, timeForAdd, timeForSearch, timeForRemove);
		BinarySearchTreeDictionary_delete(dictionaryForTest);
		testSize += intervalSize;
	}
	free(_this->_testData);
	AppView_out(MSG_EndPerfommanceMeasuring);
}

void AppController_gernerateTestDataByRandomNumbers(AppController* _this) {
	int maxTestSize = MIN_TEST_SIZE + INTERVAL_SIZE*(NUMBER_OF_TESTS - 1);
	srand((unsigned)time(NULL));
	for (int i = 0; i < maxTestSize; i++) {
		_this->_testData[i] = rand();
	}
}

double AppController_timeForUnSortedArrayDictionary_add(AppController*_this, UnSortedArrayDictionary* aDictionary, int aTestSize) {
	Timer* timer = Timer_new();

	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!UnSortedArrayDictionary_isFull(aDictionary)) {
			Key* aKey = Key_newWith(_this->_testData[i]);
			Object* anObject = Object_newWith(_this->_testData[i]);
			UnSortedArrayDictionary_addKeyAndObject(aDictionary, aKey, anObject);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

double AppController_timeForUnSortedArrayDictionary_search(AppController*_this, UnSortedArrayDictionary* aDictionary, int aTestSize) {
	Timer* timer = Timer_new();

	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!UnSortedArrayDictionary_isEmpty(aDictionary)) {
			Key* aKey = Key_newWith(_this->_testData[i]);
			UnSortedArrayDictionary_keyDoesExist(aDictionary, aKey);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

double AppController_timeForUnSortedArrayDictionary_remove(AppController*_this, UnSortedArrayDictionary* aDictionary, int aTestSize) {
	Element* removedElement = NULL;
	double	duration = 0;

	Timer* timer = Timer_new();

	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!UnSortedArrayDictionary_isEmpty(aDictionary)) {
			Key* aKey = Key_newWith(_this->_testData[i]);
			removedElement = UnSortedArrayDictionary_removeObjectForKey(aDictionary, aKey);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

double AppController_timeForSortedArrayDictionary_add(AppController*_this, SortedArrayDictionary* aDictionary, int aTestSize) {
	Timer* timer = Timer_new();

	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!SortedArrayDictionary_isFull(aDictionary)) {
			Key* aKey = Key_newWith(_this->_testData[i]);
			Object* anObject = Object_newWith(_this->_testData[i]);
			SortedArrayDictionary_addKeyAndObject(aDictionary, aKey, anObject);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

double AppController_timeForSortedArrayDictionary_search(AppController*_this, SortedArrayDictionary* aDictionary, int aTestSize) {
	Timer* timer = Timer_new();

	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!SortedArrayDictionary_isEmpty(aDictionary)) {
			Key* aKey = Key_newWith(_this->_testData[i]);
			SortedArrayDictionary_keyDoesExist(aDictionary, aKey);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

double AppController_timeForSortedArrayDictionary_remove(AppController*_this, SortedArrayDictionary* aDictionary, int aTestSize) {
	Element* removedElement = NULL;
	double	duration = 0;

	Timer* timer = Timer_new();

	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!SortedArrayDictionary_isEmpty(aDictionary)) {
			Key* aKey = Key_newWith(_this->_testData[i]);
			removedElement = SortedArrayDictionary_removeObjectForKey(aDictionary, aKey);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

double AppController_timeForUnSortedLinkedDictionary_add(AppController*_this, UnSortedLinkedDictionary* aDictionary, int aTestSize) {
	Timer* timer = Timer_new();

	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!UnSortedLinkedDictionary_isFull(aDictionary)) {
			Key* aKey = Key_newWith(_this->_testData[i]);
			Object* anObject = Object_newWith(_this->_testData[i]);
			UnSortedLinkedDictionary_addKeyAndObject(aDictionary, aKey, anObject);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

double AppController_timeForUnSortedLinkedDictionary_search(AppController*_this, UnSortedLinkedDictionary* aDictionary, int aTestSize) {
	Timer* timer = Timer_new();

	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!UnSortedLinkedDictionary_isEmpty(aDictionary)) {
			Key* aKey = Key_newWith(_this->_testData[i]);
			UnSortedLinkedDictionary_keyDoesExist(aDictionary, aKey);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

double AppController_timeForUnSortedLinkedDictionary_remove(AppController*_this, UnSortedLinkedDictionary* aDictionary, int aTestSize) {
	Element* removedElement = NULL;
	double	duration = 0;

	Timer* timer = Timer_new();

	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!UnSortedLinkedDictionary_isEmpty(aDictionary)) {
			Key* aKey = Key_newWith(_this->_testData[i]);
			removedElement = UnSortedLinkedDictionary_removeObjectForKey(aDictionary, aKey);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

double AppController_timeForSortedLinkedDictionary_add(AppController*_this, SortedLinkedDictionary* aDictionary, int aTestSize) {
	Timer* timer = Timer_new();

	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!SortedLinkedDictionary_isFull(aDictionary)) {
			Key* aKey = Key_newWith(_this->_testData[i]);
			Object* anObject = Object_newWith(_this->_testData[i]);
			SortedLinkedDictionary_addKeyAndObject(aDictionary, aKey, anObject);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

double AppController_timeForSortedLinkedDictionary_search(AppController*_this, SortedLinkedDictionary* aDictionary, int aTestSize) {
	Timer* timer = Timer_new();

	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!SortedLinkedDictionary_isEmpty(aDictionary)) {
			Key* aKey = Key_newWith(_this->_testData[i]);
			SortedLinkedDictionary_keyDoesExist(aDictionary, aKey);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

double AppController_timeForSortedLinkedDictionary_remove(AppController*_this, SortedLinkedDictionary* aDictionary, int aTestSize) {
	Element* removedElement = NULL;
	double	duration = 0;

	Timer* timer = Timer_new();

	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!SortedLinkedDictionary_isEmpty(aDictionary)) {
			Key* aKey = Key_newWith(_this->_testData[i]);
			removedElement = SortedLinkedDictionary_removeObjectForKey(aDictionary, aKey);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

double AppController_timeForBinarySearchTreeDictionary_add(AppController*_this, BinarySearchTreeDictionary* aDictionary, int aTestSize) {
	Timer* timer = Timer_new();

	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!BinarySearchTreeDictionary_isFull(aDictionary)) {
			Key* aKey = Key_newWith(_this->_testData[i]);
			Object* anObject = Object_newWith(_this->_testData[i]);
			BinarySearchTreeDictionary_addKeyAndObject(aDictionary, aKey, anObject);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

double AppController_timeForBinarySearchTreeDictionary_search(AppController*_this, BinarySearchTreeDictionary* aDictionary, int aTestSize) {
	Timer* timer = Timer_new();

	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!BinarySearchTreeDictionary_isEmpty(aDictionary)) {
			Key* aKey = Key_newWith(_this->_testData[i]);
			BinarySearchTreeDictionary_keyDoesExist(aDictionary, aKey);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

double AppController_timeForBinarySearchTreeDictionary_remove(AppController*_this, BinarySearchTreeDictionary* aDictionary, int aTestSize) {
	Element* removedElement = NULL;
	double	duration = 0;

	Timer* timer = Timer_new();

	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!BinarySearchTreeDictionary_isEmpty(aDictionary)) {
			Key* aKey = Key_newWith(_this->_testData[i]);
			removedElement = BinarySearchTreeDictionary_removeObjectForKey(aDictionary, aKey);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}


void AppController_showResults(AppController* _this, int aTestSize, double aTimeForAdd, double aTimeForSearch, double aTimeForRemove) {
	char results[255];
	sprintf_s(results, sizeof(results),
		"크기: %5d, 삽입: %8ld, 검색: %9ld, 삭제: %9ld\n",
		aTestSize, (long)aTimeForAdd, (long)aTimeForSearch, (long)aTimeForRemove);
	AppView_out(results);
}
