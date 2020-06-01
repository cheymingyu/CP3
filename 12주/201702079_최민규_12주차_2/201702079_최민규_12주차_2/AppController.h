#pragma once
#pragma once

typedef struct _AppController AppController;

AppController*	AppController_new();
void			AppController_delete(AppController* _this);

void AppController_run(AppController* _this);