#pragma once
#include "Common.h"

typedef struct _SortedArrayList SortedArrayList;

SortedArrayList* SortedArrayList_new(int givenCapacity);
void SortedArrayList_delete(SortedArrayList* _this);

Boolean SortedArrayList_isEmpty(SortedArrayList* _this);
Boolean SortedArrayList_isFull(SortedArrayList* _this);

Boolean SortedArrayList_add(SortedArrayList* _this, Element anElement);
Element SortedArrayList_removeMax(SortedArrayList* _this);
Element SortedArrayList_min(SortedArrayList* _this);

