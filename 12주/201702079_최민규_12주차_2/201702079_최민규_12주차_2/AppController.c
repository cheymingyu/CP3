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
	nextInfixExpressionIsAvailable = AppView_in_infixExpression(_this->_expression);	// Infix표현을 입력받는다.
	while (nextInfixExpressionIsAvailable) {
		AppView_out_infixToPostfixMessage();
		Infix_setExpression(_this->_infix, _this->_expression);		// Infix객체에 infix표현을 저장한다.
		infixToPostfixIsValid = Infix_toPostfix(_this->_infix);		// infix 를 postfix 로 변경한다.
		if (!infixToPostfixIsValid) {						
			AppView_out_infixToPostfixErrorMessage();
		}
		else {	// Infix표현이 올바르고 postfix로 변환을 마쳤다.
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