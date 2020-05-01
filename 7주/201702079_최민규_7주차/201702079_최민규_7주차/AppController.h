#pragma once
#include "Common.h"

typedef struct _AppController AppController;

AppController* AppController_new();

void AppController_delete(AppController* _this);
void AppController_run(AppController* _this);

Boolean AppController_inputIsValid(AppController* _this, char* aStudentID, int aScore);
Boolean	AppController_inputAndStoreStudents(AppController* _this);
void	AppController_showStatistics(AppController* _this);
void	AppController_showStudentsSortedByScore(AppController* _this);
