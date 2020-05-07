#pragma once
#include "UnsortedArrayList.h"
#include "SortedArrayList.h"

typedef struct _AppController AppController;

AppController* AppController_new(void);
void AppController_delete(AppController* _this);
void AppController_initPerformanceMeasurement(AppController* _this);
void AppController_run(AppController* _this);
void AppController_gernerateTestDataByRandomNumbers(AppController* _this);

double AppController_timeForUnsortedArrayList_add(AppController* _this, UnsortedArrayList* aList, int aTestSize);
double AppController_timeForUnsortedArrayList_removeMax(AppController* _this, UnsortedArrayList* aList, int aTestSize);
double AppController_timeForUnsortedArrayList_min(AppController* _this, UnsortedArrayList* aList, int aTestSize);