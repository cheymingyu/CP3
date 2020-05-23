#pragma once
#include "Common.h"

typedef struct _SortedLinkedList SortedLinkedList;

SortedLinkedList* SortedLinkedList_new();
void SortedLinkedList_delete(SortedLinkedList* _this);

Boolean SortedLinkedList_isEmpty(SortedLinkedList* _this);
Boolean SortedLinkedList_isFull(SortedLinkedList* _this);
Boolean SortedLinkedList_add(SortedLinkedList* _this, Element anElement);
Element SortedLinkedList_min(SortedLinkedList* _this);
Element SortedLinkedList_removeMax(SortedLinkedList* _this);