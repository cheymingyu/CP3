#include "AppController.h"

int main(void) {
	AppController* appController = AppController_new();
	AppController_run(appController);
	AppController_delete(appController);

	return 0;
}