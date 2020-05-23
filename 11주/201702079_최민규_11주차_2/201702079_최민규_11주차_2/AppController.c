#include "AppController.h"
#include "AppView.h"
#include "Common.h"
#include "Messages.h"
#include "UnsortedLinkedList.h"
#include "SortedLinkedList.h"
#include "Timer.h"
#include "ParameterSet.h"
#include <time.h>

#define MIN_TEST_SIZE		10000
#define	NUMBER_OF_TESTS		5
#define INTERVAL_SIZE		10000

struct _AppController
{
	ParameterSet* _parameterSet;
	int* _testData;
};

void AppController_initPerformanceMeasurement(AppController* _this);
void AppController_gernerateTestDataByRandomNumbers(AppController* _this);
double AppController_timeForUnsortedLinkedList_add(AppController* _this, UnsortedLinkedList* aList, int aTestSize);
double AppController_timeForUnsortedLinkedList_min(AppController* _this, UnsortedLinkedList* aList, int aTestSize);
double AppController_timeForUnsortedLinkedList_removeMax(AppController* _this, UnsortedLinkedList* aList, int aTestSize);

double AppController_timeForSortedLinkedList_add(AppController* _this, SortedLinkedList* aList, int aTestSize);
double AppController_timeForSortedLinkedList_min(AppController* _this, SortedLinkedList* aList, int aTestSize);
double AppController_timeForSortedLinkedList_removeMax(AppController* _this, SortedLinkedList* aList, int aTestSize);
void AppController_showResults(AppController* _this, int aTestSize, double aTimeForAdd, double aTimeForMin, double aTimeForRemoveMax);

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

	AppView_out(MSG_TitleForUnsortedLinkedList);

	int testSize = ParameterSet_minTestSize(_this->_parameterSet);
	for (int i = 0; i < numberOfTests; i++) {
		UnsortedLinkedList* listForTest = UnsortedLinkedList_new(maxTestSize);
		double timeForAdd = AppController_timeForUnsortedLinkedList_add(_this, listForTest, testSize);
		double timeForMin = AppController_timeForUnsortedLinkedList_min(_this, listForTest, testSize);
		double timeForRemoveMax = AppController_timeForUnsortedLinkedList_removeMax(_this, listForTest, testSize);
		AppController_showResults(_this, testSize, timeForAdd, timeForMin, timeForRemoveMax);
		UnsortedLinkedList_delete(listForTest);
		testSize += intervalSize;
	}

	AppView_out("\n");
	AppView_out(MSG_TitleForSortedLinkedList);
	testSize = ParameterSet_minTestSize(_this->_parameterSet);
	for (int i = 0; i < numberOfTests; i++) {
		SortedLinkedList* listForTest = SortedLinkedList_new(maxTestSize);
		double timeForAdd = AppController_timeForSortedLinkedList_add(_this, listForTest, testSize);
		double timeForMin = AppController_timeForSortedLinkedList_min(_this, listForTest, testSize);
		double timeForRemoveMax = AppController_timeForSortedLinkedList_removeMax(_this, listForTest, testSize);
		AppController_showResults(_this, testSize, timeForAdd, timeForMin, timeForRemoveMax);
		SortedLinkedList_delete(listForTest);
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
double AppController_timeForUnsortedLinkedList_add(AppController* _this, UnsortedLinkedList* aList, int aTestSize) {
	Timer* timer = Timer_new();

	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!UnsortedLinkedList_isFull(aList)) {
			UnsortedLinkedList_add(aList, _this->_testData[i]);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

double AppController_timeForUnsortedLinkedList_min(AppController* _this, UnsortedLinkedList* aList, int aTestSize) {
	Element min;
	double	duration = 0;

	Timer* timer = Timer_new();

	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!UnsortedLinkedList_isEmpty(aList)) {
			min = UnsortedLinkedList_min(aList);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);

	return duration;
}

double AppController_timeForUnsortedLinkedList_removeMax(AppController* _this, UnsortedLinkedList* aList, int aTestSize) {
	Element max;
	double	duration = 0;

	Timer* timer = Timer_new();

	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!UnsortedLinkedList_isEmpty(aList)) {
			max = UnsortedLinkedList_removeMax(aList);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

double AppController_timeForSortedLinkedList_add(AppController* _this, SortedLinkedList* aList, int aTestSize) {
	Timer* timer = Timer_new();

	double duration = 0;
	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!SortedLinkedList_isFull(aList)) {
			SortedLinkedList_add(aList, _this->_testData[i]);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

double AppController_timeForSortedLinkedList_min(AppController* _this, SortedLinkedList* aList, int aTestSize) {
	Element min;
	double	duration = 0;

	Timer* timer = Timer_new();

	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!SortedLinkedList_isEmpty(aList)) {
			min = SortedLinkedList_min(aList);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);

	return duration;
}

double AppController_timeForSortedLinkedList_removeMax(AppController* _this, SortedLinkedList* aList, int aTestSize) {
	Element max;
	double	duration = 0;

	Timer* timer = Timer_new();

	for (int i = 0; i < aTestSize; i++) {
		Timer_start(timer);
		if (!SortedLinkedList_isEmpty(aList)) {
			max = SortedLinkedList_removeMax(aList);
		}
		Timer_stop(timer);
		duration += Timer_duration(timer);
	}
	Timer_delete(timer);
	return duration;
}

void AppController_showResults(AppController* _this, int aTestSize, double aTimeForAdd, double aTimeForMin, double aTimeForRemoveMax) {
	char results[255];
	sprintf_s(results, sizeof(results),
		"크기: %5d, 삽입: %8ld, 최소값 얻기: %9ld, 최대값삭제: %9ld\n",
		aTestSize, (long)aTimeForAdd, (long)aTimeForMin, (long)aTimeForRemoveMax);
	AppView_out(results);
}
