#include "AppController.h"

int main(void) {
	AppController* appController;
	appController = AppController_new();	// appController ��ü ����
	AppController_run(appController);		// app ����
	AppController_delete(appController);	// appController ��ü ����

	return 0;
}