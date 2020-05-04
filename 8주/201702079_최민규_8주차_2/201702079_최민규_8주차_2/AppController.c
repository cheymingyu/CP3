#include "AppController.h"
#include "Common.h"
#include "AppView.h"
#include "Messages.h"
#include "UnsortedArrayList.h"
#include "SortedArrayList.h"
#include "Timer.h"
#include "ParameterSet.h"
#include <time.h>

#define MIN_TEST_SIZE		1000
#define	NUMBER_OF_TESTS		5
#define INTERVAL_SIZE		1000

struct  _AppController
{
	ParameterSet*	 _parameterSet;
	int*			 _testData;
};

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
	int intervalsize = ParameterSet_intervalSize(_this->_parameterSet);
	int maxTestSize = ParameterSet_maxTestSize(_this->_parameterSet);

	AppView_out(MSG_TitleForUnsortedArrayList);
	int testSize = ParameterSet_minTestSize(_this->_parameterSet);
	for (int i = 0; i < numberOfTests; i++) {
		UnsortedArrayList* listForTest = UnsortedArrayList_new(maxTestSize);
		double timeForAdd = AppController_timeForUnsortedArrayList_add(_this, listForTest, testSize);
		double timeForMin = AppController_timeForUnsortedArrayList_min(_this, listForTest, testSize);
		double timeForRemoveMax = AppController_timeForUnsortedArrayList_removeMax(_this, listForTest, testSize);
		AppController_showResults(_this, testSize, timeForAdd, timeForMin, timeForRemoveMax);
		UnsortedArrayList_delete(listForTest);
		testSize += intervalsize;
	}

	AppView_out("\n");
	AppView_out(MSG_TitleForSortedArrayList);
	testSize = ParameterSet_minTestSize(_this->_parameterSet);
	for (int i = 0; i < numberOfTests; i++) {
		SortedArrayList* listForTest = SortedArrayList_new(maxTestSize);
		double timeForAdd = AppController_timeForSortedArrayList_add(_this, listForTest, testSize);
		double timeForMin = AppController_timeForSortedArrayList_min(_this, listForTest, testSize);
		double timeForRemoveMax = AppController_timeForSortedArrayList_removeMax(_this, listForTest, testSize);
		AppController_showResults(_this, testSize, timeForAdd, timeForMin, timeForRemoveMax);
		SortedArrayList_delete(listForTest);
		testSize += intervalsize;
	}
	AppView_out(MSG_EndPerfommanceMeasuring);
}

void AppController_gernerateTestDataByRandomNumbers(AppController* _this) {
	int maxTestSize = MIN_TEST_SIZE + INTERVAL_SIZE*(NUMBER_OF_TESTS - 1);
	srand((unsigned)time(NULL));
	for (int i = 0; i < maxTestSize; i++) {
		_this->_testData[i] = rand();
	}
}

double AppController_timeForUnsortedArrayList_add
(AppController* _this, UnsortedArrayList* aList, int aTestSize) {
	Timer* timer = Timer_new();

	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!UnsortedArrayList_isFull(aList)) {
			UnsortedArrayList_add(aList, _this->_testData[i]);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

double AppController_timeForUnsortedArrayList_removeMax
(AppController* _this, UnsortedArrayList* aList, int aTestSize) {
	Element max;
	double	duration = 0;

	Timer* timer = Timer_new();

	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!UnsortedArrayList_isEmpty(aList)) {
			max = UnsortedArrayList_removeMax(aList);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

double AppController_timeForUnsortedArrayList_min(
	AppController* _this, UnsortedArrayList* aList, int aTestSize) {
	Element min;
	double	duration = 0;

	Timer* timer = Timer_new();

	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!UnsortedArrayList_isEmpty(aList)) {
			min = UnsortedArrayList_min(aList);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);

	return duration;
}

double AppController_timeForSortedArrayList_add
(AppController* _this, SortedArrayList* aList, int aTestSize) {
	Timer* timer = Timer_new();

	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!SortedArrayList_isFull(aList)) {
			SortedArrayList_add(aList, _this->_testData[i]);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

double AppController_timeForSortedArrayList_removeMax
(AppController* _this, SortedArrayList* aList, int aTestSize) {
	Element max;
	double	duration = 0;

	Timer* timer = Timer_new();

	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!SortedArrayList_isEmpty(aList)) {
			max = SortedArrayList_removeMax(aList);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

double AppController_timeForSortedArrayList_min(
	AppController* _this, SortedArrayList* aList, int aTestSize) {
	Element min;
	double	duration = 0;

	Timer* timer = Timer_new();

	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!SortedArrayList_isEmpty(aList)) {
			min = SortedArrayList_min(aList);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);

	return duration;
}

void AppController_showResults
(AppController* _this,
	int aTestSize,
	double aTimeForAdd,
	double aTimeForMin,
	double aTimeForRemoveMax)
{
	char results[255];
	sprintf_s(results, sizeof(results),
		"크기: %4d, 삽입: %6ld, 최소값얻기: %7ld, 최대값삭제: %7ld\n",
		aTestSize, (long)aTimeForAdd, (long)aTimeForMin, (long)aTimeForRemoveMax);
	AppView_out(results);
}