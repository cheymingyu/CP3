#include "AppController.h"
#include "AppView.h"
#include "Common.h"
#include "Messages.h"
#include "UnsortedLinkedList.h"
#include "Timer.h"
#include <time.h>

#define MIN_TEST_SIZE		1000
#define	NUMBER_OF_TESTS		5
#define INTERVAL_SIZE		1000

struct _AppController
{
	int* _testData;
};

void AppController_gernerateTestDataByRandomNumbers(AppController* _this);
double AppController_timeForUnsortedLinkedList_add(AppController* _this, UnsortedLinkedList* aList, int aTestSize);
double AppController_timeforUnsortedLinkedList_min(AppController* _this, UnsortedLinkedList* aList, int aTestSize);
double AppController_timeForUnsortedLinkedList_removeMax(AppController* _this, UnsortedLinkedList* aList, int aTestSize);
void AppController_showResults(AppController* _this, int aTestSize, double aTimeForAdd, double aTimeForMin, double aTimeForRemoveMax);

AppController* AppController_new(void) {
	AppController* _this = NewObject(AppController);
	return _this;
}

void AppController_delete(AppController* _this) {
	free(_this);
}

void AppController_run(AppController* _this) {
	AppView_out(MSG_StartPerformanceMeasuring);

	int numberOfTests = NUMBER_OF_TESTS;
	int intervalSize = INTERVAL_SIZE;
	int maxTestSize = MIN_TEST_SIZE + INTERVAL_SIZE*(NUMBER_OF_TESTS - 1);

	_this->_testData = NewVector(int, maxTestSize);

	AppController_gernerateTestDataByRandomNumbers(_this);

	AppView_out(MSG_TitleForUnsortedLinkedList);

	int testSize = MIN_TEST_SIZE;
	for (int i = 0; i < numberOfTests; i++) {
		UnsortedLinkedList* listForTest = UnsortedLinkedList_new(maxTestSize);
		double timeForAdd = AppController_timeForUnsortedLinkedList_add(_this, listForTest, testSize);
		double timeForMin = AppController_timeforUnsortedLinkedList_min(_this, listForTest, testSize);
		double timeForRemoveMax = AppController_timeForUnsortedLinkedList_removeMax(_this, listForTest, testSize);
		AppController_showResults(_this, testSize, timeForAdd, timeForMin, timeForRemoveMax);
		UnsortedLinkedList_delete(listForTest);
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

double AppController_timeforUnsortedLinkedList_min(AppController* _this, UnsortedLinkedList* aList, int aTestSize) {
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

void AppController_showResults(AppController* _this, int aTestSize, double aTimeForAdd, double aTimeForMin, double aTimeForRemoveMax) {
	char results[255];
	sprintf_s(results, sizeof(results),
		"크기: %5d, 삽입: %6ld, 최소값 얻기: %8ld, 최대값삭제: %8ld\n",
		aTestSize, (long)aTimeForAdd, (long)aTimeForMin, (long)aTimeForRemoveMax);
	AppView_out(results);
}
