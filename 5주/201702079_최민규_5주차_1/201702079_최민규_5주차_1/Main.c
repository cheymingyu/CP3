#include "AppController.h"

int main(void) {
	AppController* appController;
	appController = AppController_new();	// appController 按眉 积己
	AppController_run(appController);		// app 角青
	AppController_delete(appController);	// appController 按眉 昏力

	return 0;
}