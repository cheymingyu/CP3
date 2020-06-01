#define  _CRT_SECURE_NO_WARNINGS

#include "Infix.h"
#include "OStack.h"
#include "AppView.h"
#include <stdlib.h>
#include <string.h>

struct _Infix
{
	char*	_infixExpression;	// AppController에서 보내준다.
	char	_postfixExpression[DEFAULT_MAX_NUMBER_OF_TOKENS];
		// postfix로 변환된 결과는 이곳에 저장된다.
	OStack* _operatorStack;
};

int		Infix_inComingPrecedence(char aToken);
int		Infix_inStackPrecedence(char aToken);
void	Infix_showTokenAndOStack(Infix* _this, char currentToken);

Infix* Infix_new() {
	Infix* _this;
	_this = NewObject(Infix);
	_this->_infixExpression = NewVector(char, DEFAULT_MAX_NUMBER_OF_TOKENS);
	_this->_operatorStack = OStack_new();
	return _this;
}

void Infix_delete(Infix* _this) {
	free(_this->_infixExpression);
	free(_this);
}

void Infix_setExpression(Infix* _this, char* newExpression) {
	strcpy(_this->_infixExpression, newExpression);
}

Boolean Infix_toPostfix(Infix* _this) {
	int i = 0;
	int p = 0;
	char currentToken = '\0';
	char poppedToken = '\0';
	int infixSize = strlen(_this->_infixExpression);
	_this->_operatorStack = OStack_new();
	while (i < infixSize) {
		currentToken = _this->_infixExpression[i++];
		if (isDigit(currentToken)) {	// operand
			_this->_postfixExpression[p++] = currentToken;
			Infix_showTokenAndOStack(_this, currentToken);
		}
		else {		// operator
			if (currentToken == ')') {
				if (OStack_isEmpty(_this->_operatorStack)) {
					return FALSE;	// 수식 오류
				}
				else {
					poppedToken = OStack_pop(_this->_operatorStack);
					while (poppedToken != '(') {
						_this->_postfixExpression[p++] = poppedToken;
						if (OStack_isEmpty(_this->_operatorStack)) {
							return FALSE;	// 수식 오류
						}
						else {
							poppedToken = OStack_pop(_this->_operatorStack);
						}
					}
				}
				Infix_showTokenAndOStack(_this, currentToken);
			}
			else {
				int inComingPrecedence = Infix_inComingPrecedence(currentToken);
				while (!OStack_isEmpty(_this->_operatorStack) &&
					Infix_inStackPrecedence(OStack_peek(_this->_operatorStack)) >= inComingPrecedence) {
					poppedToken = OStack_pop(_this->_operatorStack);
					_this->_postfixExpression[p++] = poppedToken;
				}
				OStack_push(_this->_operatorStack, currentToken);
				Infix_showTokenAndOStack(_this, currentToken);
			}
		}
	}
	while (!OStack_isEmpty(_this->_operatorStack)) {
		poppedToken = OStack_pop(_this->_operatorStack);
		_this->_postfixExpression[p++] = poppedToken;
	}
	_this->_postfixExpression[p] = '\0';
	return TRUE;
}

char* Infix_postfix(Infix* _this) {
	return _this->_postfixExpression;
}

int Infix_inComingPrecedence(char aToken) {
	// 각 연산자의 입력 토큰 상태의 우선 순위를 돌려준다
	if (aToken == '(') {
		return 20;
	}
	else if (aToken == ')') {
		return 19;
	}
	else if (aToken == '^') {
		return 17;
	}
	else if (aToken == '*') {
		return 13;
	}
	else if (aToken == '/') {
		return 13;
	}
	else if (aToken == '%') {
		return 13;
	}
	else if (aToken == '+') {
		return 12;
	}
	else if (aToken == '-') {
		return 12;
	}
	else if (aToken == '$') {
		return 0;
	}
	else {
		return -1;
	}
}

int Infix_inStackPrecedence(char aToken) {
	if (aToken == '^') {
		return 16;
	}
	else if (aToken == '*') {
		return 13;
	}
	else if (aToken == '/') {
		return 13;
	}
	else if (aToken == '%') {
		return 13;
	}
	else if (aToken == '+') {
		return 12;
	}
	else if (aToken == '-') {
		return 12;
	}
	else if (aToken == '$') {
		return 0;
	}
	else {
		return -1;
	}
}

void Infix_showTokenAndOStack(Infix* _this, char currentToken) {
	char stackElement;
	printf("%c : OStack ", currentToken);
	AppView_out_bottomOfStack();
	for (int i = 0; i < OStack_size(_this->_operatorStack); i++) {
		stackElement = OStack_elementAt(_this->_operatorStack, i);
		AppView_out_OElement(stackElement);
	}
	AppView_out_topOfStack();
	AppView_out_newLine();
}