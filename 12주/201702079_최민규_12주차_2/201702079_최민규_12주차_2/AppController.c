#include "AppController.h"
#include "AppView.h"
#include "Infix.h"
#include "Postfix.h"
#include "Common.h"

struct _AppController
{
	char		_expression[DEFAULT_MAX_NUMBER_OF_TOKENS];
	Infix*		_infix;
	Postfix*	_postfix;
};

AppController* AppController_new() {
	AppController* _this;
	_this = NewObject(AppController);
	return _this;
}

void AppController_delete(AppController* _this) {
	free(_this);
}

void AppController_run(AppController* _this) {
	Boolean			nextInfixExpressionIsAvailable, infixToPostfixIsValid;
	PostfixError	evaluationError;

	AppView_out_startingMessage();
	_this->_infix = Infix_new();
	_this->_postfix = Postfix_new(DEFAULT_MAX_NUMBER_OF_TOKENS);
	nextInfixExpressionIsAvailable = AppView_in_infixExpression(_this->_expression);	// Infixǥ���� �Է¹޴´�.
	while (nextInfixExpressionIsAvailable) {
		AppView_out_infixToPostfixMessage();
		Infix_setExpression(_this->_infix, _this->_expression);		// Infix��ü�� infixǥ���� �����Ѵ�.
		infixToPostfixIsValid = Infix_toPostfix(_this->_infix);		// infix �� postfix �� �����Ѵ�.
		if (!infixToPostfixIsValid) {						
			AppView_out_infixToPostfixErrorMessage();
		}
		else {	// Infixǥ���� �ùٸ��� postfix�� ��ȯ�� ���ƴ�.
			char* postfixExpression = Infix_postfix(_this->_infix);
			Postfix_setExpression(_this->_postfix, postfixExpression);
			AppView_out_postfixExpression(postfixExpression);
			Appview_out_startEvaluatePostfix();
			evaluationError = Postfix_evaluate(_this->_postfix);
			if (evaluationError == PostfixError_None) {
				AppView_out_evaluatedValue(Postfix_evaluatedValue(_this->_postfix));
			}
			else {
				AppView_out_postfixEvaluationErrorMessage(evaluationError);
			}
		}
		nextInfixExpressionIsAvailable = AppView_in_infixExpression(_this->_expression);
	}
	Infix_delete(_this->_infix);
	AppView_out_endingMessage();
}