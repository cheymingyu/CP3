#include "AppController.h"
#include "AppView.h"
#include "Postfix.h"
#include "Common.h"

#define MAX_NUMBER_OF_TOKENS 200

struct _AppController
{
	char		_expression[MAX_NUMBER_OF_TOKENS];
	Postfix*	_postfix;
};

AppController* AppController_new() {
	AppController* _this;
	_this = NewObject(AppController);
	_this->_postfix = Postfix_new(MAX_NUMBER_OF_TOKENS);
	return _this;
}

void AppController_delete(AppController* _this) {
	free(_this->_postfix);
	free(_this);
}

void AppController_run(AppController* _this) {
	Boolean expressionIsAvailable, noErrorIsInEvaluation;

	AppView_out_startingMessage();
	_this->_postfix = Postfix_new(MAX_NUMBER_OF_TOKENS);
	expressionIsAvailable = AppView_in_postfixExpression(_this->_expression);
	while (expressionIsAvailable) {
		Postfix_setExpression(_this->_postfix, _this->_expression);
		noErrorIsInEvaluation = Postfix_evaluate(_this->_postfix);
		if (!noErrorIsInEvaluation) {
			AppView_out_errorInExpression();
		}
		else {
			AppView_out_evaluatedValue(Postfix_evaluatedValue(_this->_postfix));
		}
		expressionIsAvailable = AppView_in_postfixExpression(_this->_expression);
	}
	AppView_out_endingMessage();
}