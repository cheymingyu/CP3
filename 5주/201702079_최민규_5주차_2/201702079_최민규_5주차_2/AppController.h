#pragma once
#include "Common.h"

typedef struct _AppController AppController;

AppController* AppController_new();

void AppController_delete(AppController* _this);
void AppController_run(AppController* _this);
void AppController_showBoard(AppController* _this, MagicSquare* aMagicSquare);
