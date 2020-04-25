#pragma once
#include "Common.h"

typedef struct _AppController AppController;

AppController* AppController_new();

void AppController_delete(AppController* _this);
void AppController_run(AppController* _this);

Boolean	AppControlller_inputAndStoreStudents(AppController* _this);
void	AppController_showStatistics(AppController* _this);
void	AppController_AppController_showStudentsSortedByScore(AppController* _this);