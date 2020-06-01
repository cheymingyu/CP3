#pragma once
#include "Common.h"

typedef struct _Node Node;

Node*	Node_new();
void	Node_delete(Node* _this);

void Node_setElement(Node* _this, Element newElement);
Element Node_element(Node* _this);

void Node_setNext(Node* _this, Node* newNext);
Node* Node_next(Node* _this);